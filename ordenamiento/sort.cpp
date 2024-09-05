#include <algorithm> 
#include <iostream> 
#include <chrono>
#include <fstream>
#include <sstream>
using namespace std;

int main() 
{ 
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
            auto start = std::chrono::system_clock::now();
            sort(arr_copy.begin(), arr_copy.end()); 
            auto end = std::chrono::system_clock::now();
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