#include <fstream>
#include <vector>
#include <random>

using namespace std;

/* 
funcion: generateTestCases
parametros: Ninguno.
resumen: Esta función genera casos de prueba para la multiplicación de matrices. 
         Crea un archivo llamado "test_cases.txt" que contiene varias matrices de tamaños diferentes, 
         en este caso 100x100, 200x200, hasta 800x800. Para cada tamaño, se generan dos matrices (A y B) 
         cuyos elementos son números enteros aleatorios en el rango de 0 a 100. Muestra en la primera linea
         el tamaño de la matriz (que como es cuadrado consiste en 1 numero) y seguido vienen las dos matrices
         separadas por un espacion entre ellas.
*/
void generateTestCases() {
    ofstream file("test_cases.txt");

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100);

    // Lista de tamaños de matrices a generar
    vector<int> sizes = {2,4,8,16,32,64,128,256,512,1024};

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
