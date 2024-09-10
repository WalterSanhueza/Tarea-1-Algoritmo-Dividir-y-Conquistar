#include <fstream>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

/*funcion: transponer_matriz(int,vector<vector>,vector<vector>)
parametros: int, vector<vector>, vector<vector>
resumen: funcion utilizada en la funcion multiplicacion_matrices_traspuesta.
se encarga de trasponer una de las matrices de la funcion para su posterior 
uso.
*/
void transponer_matriz(int n, const vector<vector<int>>& B, vector<vector<int>>& BT) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            BT[j][i] = B[i][j];
        }
    }
}

/*funcion: multiplicacion_matrices_traspuestas(int, vector<vector>,vector<vector>,vector<vector>)
parametros int, vector<vector>, vector<vector>, vector<vector>
resumen: Realiza de multiplicacion de matrices optimizada, 
para esto ocupa 2 matrices y una tercera para almacenar 
el calculo del producto.
*/
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

/*funcion: verMatriz(vector<vector>)
parametros: vector de vectores
resumen: funcion que itera dentro de una matriz
formada por vectores de vectores e imprime sus valores 
por consola.
Se tiene la funcion comentada, pues molesta a la hora de 
tomar los tiempos de cada algoritmo.
*/
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

    for (int i = 0; i < 10; i++) {
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

        chrono::duration<double> total_time(0);
        for (int j = 0; j < 5; j++) {
            auto start = chrono::high_resolution_clock::now();
            multiplicacion_matrices_transpuesta(size, mat1, mat2, result);
            auto end = chrono::high_resolution_clock::now();
            total_time += end - start;
        }

        chrono::duration<double> avg_time = total_time / 5;
        cout << "Tiempo promedio " << i + 1 << ": " << avg_time.count() << " seconds" << endl;
        

        //cout << "Matriz resultante: " << endl;
        //imprimir_matriz(result);
        cout << endl;
    }

    return 0;
}
