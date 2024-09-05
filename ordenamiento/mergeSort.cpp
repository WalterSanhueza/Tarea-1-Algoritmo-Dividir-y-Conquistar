#include <bits/stdc++.h>
#include <fstream>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
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

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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
            mergeSort(caso_copy, 0, caso_copy.size() - 1);
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