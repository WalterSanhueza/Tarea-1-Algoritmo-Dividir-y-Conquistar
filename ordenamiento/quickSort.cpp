#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/* 
funcion: partition
parametros: arr (vector a ordenar), low (índice inicial), high (índice final).
resumen: Realiza la partición del vector arr tomando el último elemento como pivote. Reorganiza el vector de tal manera 
         que todos los elementos menores que el pivote se colocan a su izquierda y los mayores a su derecha. Retorna el índice del pivote.
*/
int partition(vector<int>& arr, int low, int high) {
  
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

/* 
funcion: quickSort
parametros: arr (vector a ordenar), low (índice inicial), high (índice final).
resumen: Implementa el algoritmo de ordenamiento QuickSort. Llama recursivamente a la función partition para dividir 
         el vector en dos partes: los elementos menores que el pivote y los mayores. Ordena ambas mitades de forma recursiva.
*/
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* 
funcion: printVector
parametros: arr (vector a imprimir).
resumen: Imprime los primeros 10 elementos y los últimos 10 elementos del vector arr, mostrando "..." en el medio 
         si el vector tiene más de 20 elementos.
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
            quickSort(caso_copy, 0, caso_copy.size() - 1);
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