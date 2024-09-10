#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
funcion: generateTestCases()
parametros: ninguno
resumen: Funcion que genera los 25 lineas
agrupadas en 5 casos de prueba separados por 
un saltos de linea.Los casos los guarda en un 
archivo de texto llamado test_cases.txt.
*/
void generateTestCases() {
    ofstream file("test_cases.txt");

    srand(time(0)); 

    // Caso ordenado
    int casos=5;
    int rango=10000;
    int tamaño=rango;
    for (int caseNum = 1; caseNum <= casos; caseNum++) {
        int size = caseNum * tamaño;
        vector<int> arr(size);

        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }

        for (int i : arr) {
            file << i << " ";
        }
        file << endl;
    }

    // Caso con un cuarto de los datos desordenados
    for (int caseNum = 1; caseNum <= casos; caseNum++) {
        int size = caseNum * tamaño;
        vector<int> arr(size);

        for (int i = 0; i < size / 4; i++) {
            arr[i] = rand() % rango*caseNum + 1;
        }

        for (int i = size / 4; i < size; i++) {
            arr[i] = i + 1;
        }

        for (int i : arr) {
            file << i << " ";
        }
        file << endl;
    }

    // Caso con la mitad de los datos desordenados
    for (int caseNum = 1; caseNum <= casos; caseNum++) {
        int size = caseNum * tamaño;
        vector<int> arr(size);

        for (int i = 0; i < size / 2; i++) {
            arr[i] = rand() % rango*caseNum + 1;
        }

        for (int i = size / 2; i < size; i++) {
            arr[i] = i + 1;
        }

        for (int i : arr) {
            file << i << " ";
        }
        file << endl;
    }

    // Caso con el 75% de los datos desordenados
    for (int caseNum = 1; caseNum <= casos; caseNum++) {
        int size = caseNum * tamaño;
        vector<int> arr(size);

        for (int i = 0; i < (size * 3) / 4; i++) {
            arr[i] = rand() % rango*caseNum + 1;
        }

        for (int i = (size * 3) / 4; i < size; i++) {
            arr[i] = i + 1;
        }

        for (int i : arr) {
            file << i << " ";
        }
        file << endl;
    }

    // Datos desordenados
    for (int caseNum = 1; caseNum <= casos; caseNum++) {
        int size = caseNum * tamaño;
        vector<int> arr(size);

        for (int i = 0; i < size; i++) {
            arr[i] = rand() % rango*caseNum + 1;
        }

        for (int i : arr) {
            file << i << " ";
        }
        file << endl;
    }

    file.close();
}

int main() {
    generateTestCases();
    return 0;
}




