#include <bits/stdc++.h>
using namespace std;

#define ROW_1 4
#define COL_1 4

#define ROW_2 4
#define COL_2 4


/* 
funcion: print_matrix
parametros: display (cadena de texto que describe la matriz), matrix (matriz a imprimir).
resumen: Imprime en consola una matriz con el formato adecuado, mostrando el título especificado por el parámetro "display".
*/
void print_matrix(string display, vector<vector<int>> matrix) {
    cout << endl << display << " =>" << endl;
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            cout << setw(10) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}



/* 
funcion: add_matrix
parametros: matrix_A (primera matriz), matrix_B (segunda matriz), split_index (tamaño de la submatriz a sumar), multiplier (multiplicador opcional para los valores de matrix_B).
resumen: Suma dos submatrices de tamaño "split_index" provenientes de matrix_A y matrix_B, aplicando un multiplicador a matrix_B. 
         Devuelve la matriz resultante de la operación.
*/
vector<vector<int>> add_matrix(vector<vector<int>> matrix_A,
           vector<vector<int>> matrix_B, int split_index,
           int multiplier = 1) {
    for (auto i = 0; i < split_index; i++)
        for (auto j = 0; j < split_index; j++)
            matrix_A[i][j] = matrix_A[i][j] + (multiplier * matrix_B[i][j]);
    return matrix_A;
}



/* 
funcion: multiply_matrix
parametros: matrix_A (primera matriz), matrix_B (segunda matriz).
resumen: Realiza la multiplicación de matrices utilizando el algoritmo de Strassen, 
         dividiendo las matrices en submatrices y combinando resultados. Devuelve la matriz producto.
*/
vector<vector<int>> multiply_matrix(vector<vector<int>> matrix_A,
                vector<vector<int>> matrix_B) {
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    int row_2 = matrix_B.size();

    if (col_1 != row_2) {
        cout << "\nError: The number of columns in Matrix A must be equal to the number of rows in Matrix B\n";
        return {};
    }

    vector<int> result_matrix_row(col_2, 0);
    vector<vector<int>> result_matrix(row_1, result_matrix_row);

    if (col_1 == 1)
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    else {
        int split_index = col_1 / 2;

        vector<int> row_vector(split_index, 0);

        vector<vector<int>> a00(split_index, row_vector);
        vector<vector<int>> a01(split_index, row_vector);
        vector<vector<int>> a10(split_index, row_vector);
        vector<vector<int>> a11(split_index, row_vector);
        vector<vector<int>> b00(split_index, row_vector);
        vector<vector<int>> b01(split_index, row_vector);
        vector<vector<int>> b10(split_index, row_vector);
        vector<vector<int>> b11(split_index, row_vector);

        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++) {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + split_index];
                a10[i][j] = matrix_A[split_index + i][j];
                a11[i][j] = matrix_A[i + split_index][j + split_index];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + split_index];
                b10[i][j] = matrix_B[split_index + i][j];
                b11[i][j] = matrix_B[i + split_index][j + split_index];
            }

        vector<vector<int>> p(multiply_matrix(a00, add_matrix(b01, b11, split_index, -1)));
        vector<vector<int>> q(multiply_matrix(add_matrix(a00, a01, split_index), b11));
        vector<vector<int>> r(multiply_matrix(add_matrix(a10, a11, split_index), b00));
        vector<vector<int>> s(multiply_matrix(a11, add_matrix(b10, b00, split_index, -1)));
        vector<vector<int>> t(multiply_matrix(add_matrix(a00, a11, split_index), add_matrix(b00, b11, split_index)));
        vector<vector<int>> u(multiply_matrix(add_matrix(a01, a11, split_index, -1), add_matrix(b10, b11, split_index)));
        vector<vector<int>> v(multiply_matrix(add_matrix(a00, a10, split_index, -1), add_matrix(b00, b01, split_index)));

        vector<vector<int>> result_matrix_00(add_matrix(add_matrix(add_matrix(t, s, split_index), u, split_index), q, split_index, -1));
        vector<vector<int>> result_matrix_01(add_matrix(p, q, split_index));
        vector<vector<int>> result_matrix_10(add_matrix(r, s, split_index));
        vector<vector<int>> result_matrix_11(add_matrix(add_matrix(add_matrix(t, p, split_index), r, split_index, -1), v, split_index, -1));

        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++) {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + split_index] = result_matrix_01[i][j];
                result_matrix[split_index + i][j] = result_matrix_10[i][j];
                result_matrix[i + split_index][j + split_index] = result_matrix_11[i][j];
            }
    }
    return result_matrix;
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
            result = multiply_matrix(mat1, mat2);
            auto end = chrono::high_resolution_clock::now();
            total_time += end - start;
        }

        chrono::duration<double> avg_time = total_time / 5;
        cout << "Tiempo promedio " << i + 1 << ": " << avg_time.count() << " seconds" << endl;

        //print_matrix("Matriz resultante", result);
    }

    return 0;
}
