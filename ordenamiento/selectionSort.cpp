#include <fstream>
#include <vector>
#include <chrono>
#include <iostream>
#include <sstream>

using namespace std;

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

int main() {
    ifstream file("test_cases.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    int caseNum = 1;
    while (getline(file, line)) {
        istringstream iss(line);
        string caseLabel;
        iss >> caseLabel;
        vector<int> arr;
        int num;
        while (iss >> num) {
            arr.push_back(num);
        }

        chrono::duration<double> total_time(0);
        for (int j = 0; j < 10; j++) {
            vector<int> arr_copy = arr; // Copia del vector para cada iteración
            auto start = chrono::system_clock::now();
            selectionSort(arr_copy);
            auto end = chrono::system_clock::now();
            total_time += end - start;
        }
        chrono::duration<double> avg_time = total_time / 10;

        cout << "Case " << caseNum << ": ";
        for(int i=0;i<10;i++){
            cout << arr[i]<<" ";
        }
        cout<<"........";
        for(int i=arr.size()-11;i<arr.size();i++){
            cout << arr[i]<<" ";
        }
        cout<<endl;
        cout<< " (Tiempo promedio: " << avg_time.count() << "s)" << endl;
        cout<<endl;
        caseNum++;
    }

    file.close();
    return 0;
}