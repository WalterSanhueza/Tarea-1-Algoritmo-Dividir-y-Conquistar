#include <fstream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void generateTestCases() {
    std::ofstream file("test_cases.txt");

    // Case 1: Vector de números ordenados desde 1 hasta 100
    std::vector<int> arr1(100);
    for (int i = 0; i < 100; i++) {
        arr1[i] = i + 1;
    }
    for (int i : arr1) {
        file << i << " ";
    }
    file << std::endl;

    // Case 2: Vector de números aleatorios entre 1 y 100
    std::vector<int> arr2(100);
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        arr2[i] = rand() % 100 + 1;
    }
    for (int i : arr2) {
        file << i << " ";
    }
    file << std::endl;

    // Case 3: Vector de números invertidos desde 100 hasta 1
    std::vector<int> arr3(100);
    for (int i = 0; i < 100; i++) {
        arr3[i] = 100 - i;
    }
    for (int i : arr3) {
        file << i << " ";
    }
    file << std::endl;


    // Case 4: Vector de números ordenados desde 1 hasta 1000
    std::vector<int> arr4(1000);
    for (int i = 0; i < 1000; i++) {
        arr4[i] = i + 1;
    }
    for (int i : arr4) {
        file << i << " ";
    }
    file << std::endl;

    // Case 5: Vector de números aleatorios entre 1 y 1000
    std::vector<int> arr5(1000);
    srand(time(0));
    for (int i = 0; i < 1000; i++) {
        arr5[i] = rand() % 1000 + 1;
    }
    for (int i : arr5) {
        file << i << " ";
    }
    file << std::endl;

    // Case 6: Vector de números invertidos desde 1000 hasta 1
    std::vector<int> arr6(1000);
    for (int i = 0; i < 1000; i++) {
        arr6[i] = 1000 - i;
    }
    for (int i : arr6) {
        file << i << " ";
    }
    file << std::endl;

    // Case 7: Vector de números ordenados desde 1 hasta 10000
    std::vector<int> arr7(10000);
    for (int i = 0; i < 10000; i++) {
        arr7[i] = i + 1;
    }
    for (int i : arr7) {
        file << i << " ";
    }
    file << std::endl;

    // Case 8: Vector de números aleatorios entre 1 y 10000
    std::vector<int> arr8(10000);
    srand(time(0));
    for (int i = 0; i < 10000; i++) {
        arr8[i] = rand() % 10000 + 1;
    }
    for (int i : arr8) {
        file << i << " ";
    }
    file << std::endl;

    // Case 9: Vector de números invertidos desde 10000 hasta 1
    std::vector<int> arr9(10000);
    for (int i = 0; i < 10000; i++) {
        arr9[i] = 10000 - i;
    }
    for (int i : arr9) {
        file << i << " ";
    }
    file << std::endl;

    file.close();
}

int main() {
    generateTestCases();
    return 0;
}
