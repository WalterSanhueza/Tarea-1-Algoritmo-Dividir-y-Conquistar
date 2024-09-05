#include <fstream>
#include <vector>
#include <random>

using namespace std;

void generateTestCases() {
    ofstream file("test_cases.txt");

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100);

    // Lista de tamaños de matrices a generar
    vector<int> sizes = {8, 16, 32, 64, 128, 256,512 ,1024};

    for (int size : sizes) {
        file << size<< "\n";
        
        // Generar matriz A
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file << dis(gen) << " ";
            }
            file << "\n";
        }

        file << "\n";

        // Generar matriz B
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file << dis(gen) << " ";
            }
            file << "\n";
        }

        file << "\n";
    }

    file.close();
}

int main() {
    generateTestCases();
    return 0;
}
