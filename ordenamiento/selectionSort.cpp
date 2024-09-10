#include <fstream>
#include <vector>
#include <chrono>
#include <iostream>
#include <sstream>

using namespace std;

/* 
funcion: selectionSort
parametros: arr (vector de enteros que será ordenado).
resumen: Implementa el algoritmo de ordenamiento por selección (Selection Sort). 
         Para cada posición del vector, encuentra el elemento más pequeño en el resto 
         del vector y lo intercambia con el elemento en la posición actual.
*/
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
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
            selectionSort(caso_copy);
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