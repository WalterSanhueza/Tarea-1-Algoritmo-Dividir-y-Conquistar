#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/* 
funcion: merge
parametros: arr (vector a ordenar), left (índice izquierdo), mid (índice medio), right (índice derecho).
resumen: Combina dos subvectores de arr (del índice left a mid y de mid+1 a right) en uno solo en orden ascendente. 
         Utiliza dos vectores temporales para almacenar los elementos y los copia de vuelta al vector original.
*/
void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* 
funcion: mergeSort
parametros: arr (vector a ordenar), left (índice izquierdo), right (índice derecho).
resumen: Implementa el algoritmo de ordenamiento Merge Sort. Divide recursivamente el vector en dos mitades, 
         y luego combina las mitades ordenadas utilizando la función merge.
*/
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


/* 
funcion: printVector
parametros: arr (vector a imprimir).
resumen: Imprime los primeros 10 elementos y los últimos 10 elementos del vector arr, mostrando "..." en el medio 
         si el vector es mayor de 20 elementos.
*/
void printVector(vector<int>& arr)
{
        for(int i=0;i<10;i++){
            cout << arr[i]<<" ";
        }
        cout<<"........";
        for(int i=arr.size()-11;i<arr.size();i++){
            cout << arr[i]<<" ";
        }
}

int main()
{
    ifstream archivo("test_cases.txt");
    string linea;
    vector<vector<int>> casos;
    int i = 0;
    while (getline(archivo, linea) && i < 25) {
        istringstream iss(linea);
        vector<int> caso;
        int num;
        while (iss >> num) {
            caso.push_back(num);
        }
        casos.push_back(caso);
        i++;
    }
    archivo.close();

    for (int i = 0; i < casos.size(); i++) {
        cout << "Caso " << i + 1 << ": ";
        printVector(casos[i]);

        vector<int> caso_copy;
        chrono::duration<double> total_time(0);
        for (int j = 0; j < 10; j++) {
            caso_copy = casos[i]; 
            auto start = std::chrono::system_clock::now();
            mergeSort(caso_copy, 0, caso_copy.size() - 1);
            auto end = std::chrono::system_clock::now();
            total_time += end - start;
        }
        chrono::duration<double> avg_time = total_time / 10;
        cout << "(Tiempo promedio: " << avg_time.count() << "s)" << endl;
        cout << "Sorted: ";
        printVector(caso_copy);
        cout << endl;
        cout <<""<< endl;
    }

    return 0;
}