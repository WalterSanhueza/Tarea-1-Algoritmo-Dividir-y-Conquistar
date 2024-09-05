#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
  
    // Choose the pivot
    int pivot = arr[high];
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print a vector
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
    while (getline(archivo, linea) && i < 9) {
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

        chrono::duration<double> total_time(0);
        for (int j = 0; j < 10; j++) {
            vector<int> caso_copy = casos[i]; // Copia del vector para cada iteración
            auto start = std::chrono::system_clock::now();
            quickSort(caso_copy, 0, caso_copy.size() - 1);
            auto end = std::chrono::system_clock::now();
            total_time += end - start;
        }
        chrono::duration<double> avg_time = total_time / 10;
        cout << "(Tiempo promedio: " << avg_time.count() << "s)" << endl;
        cout << "Sorted: ";
        printVector(casos[i]);
        cout << endl;
        cout <<""<< endl;
    }

    return 0;
}