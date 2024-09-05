#include <fstream>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

void transponer_matriz(int n, const vector<vector<int>>& B, vector<vector<int>>& BT) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            BT[j][i] = B[i][j];
        }
    }
}

void multiplicacion_matrices_transpuesta(int n, const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    vector<vector<int>> BT(n, vector<int>(n));
    transponer_matriz(n, B, BT);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * BT[j][k];
            }
        }
    }
}

void imprimir_matriz(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    ifstream file("test_cases.txt");

    for (int i = 0; i < 4; i++) {
        int size;
        file >> size;

        vector<vector<int>> mat1(size, vector<int>(size));
        vector<vector<int>> mat2(size, vector<int>(size));
        vector<vector<int>> result(size, vector<int>(size));

        cout << "Case " << i + 1 << ":\n";

        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                file >> mat1[j][k];
            }
        }

        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                file >> mat2[j][k];
            }
        }

        double total_time = 0.0;
        for (int j = 0; j < 10; j++) {
            auto start = chrono::high_resolution_clock::now();
            multiplicacion_matrices_transpuesta(size, mat1, mat2, result);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> duration = end - start;
            total_time += duration.count();
        }

        double avg_time = total_time / 10.0;
        cout << "Tiempo promedio " << i + 1 << ": " << avg_time << " seconds" << endl;
        
        // Imprimir la matriz resultante
        cout << "Matriz resultante: " << endl;
        imprimir_matriz(result);
        cout << endl;
    }

    return 0;
}
