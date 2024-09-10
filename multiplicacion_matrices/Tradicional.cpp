#include <fstream>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
/*funcion: verMatriz(vector<vector>)
parametros: vector de vectores
resumen: funcion que itera dentro de una matriz
formada por vectores de vectores e imprime sus valores 
por consola.
Se tiene la funcion comentada, pues molesta a la hora de 
tomar los tiempos de cada algoritmo.
*/
void verMatriz(vector<vector<int>>& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> mulMat(vector<vector<int>>& mat1, vector<vector<int>>& mat2, int R1, int C1, int R2, int C2) {
    vector<vector<int>> rslt(R1, vector<int>(C2));

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt[i][j] = 0;

            for (int k = 0; k < R2; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return rslt;
}

int main() {
    ifstream file("test_cases.txt");

    for (int i = 0; i < 10; i++) {
        int size;
        file >> size;

        vector<vector<int>> mat1(size, vector<int>(size));
        vector<vector<int>> mat2(size, vector<int>(size));

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

        chrono::duration<double> duration;
        vector<vector<int>> result;
        chrono::duration<double> total_time(0);
        for (int j = 0; j < 5; j++) {
            auto start = chrono::high_resolution_clock::now();
            result = mulMat(mat1, mat2, size, size, size, size);
            auto end = chrono::high_resolution_clock::now();
            duration = end - start;
            total_time += duration;
        }

        chrono::duration<double> avg_time = total_time / 5;
        cout << "Tiempo promedio " << i + 1 << ": " << avg_time.count() << " seconds" << endl;

        //cout << "Matriz resultante: " << endl;
        //verMatriz(result);
        cout << endl;
    }

    return 0;
}
