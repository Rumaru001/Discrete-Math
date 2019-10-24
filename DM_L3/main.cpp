#include <iostream>
#include "func.h"
#include "relations.h"

using namespace std;

int main() {
    int A_B_pot;
    cout << "Enter the number of arrays elements A and B" << endl;
    cin >> A_B_pot;
    if (cin.fail()) {
        cout << "ERROR";
    }
    int *A = new int[A_B_pot];
    int *B = new int[A_B_pot];
    //ввід масивів
    cout << "Enter elements of the array A" << endl;
    enter(A, A_B_pot);
    cout << "Enter elements of the array B" << endl;
    enter(B, A_B_pot);
    //сортування масивів
    //sort(A, A_B_pot);
    //sort(B, A_B_pot);
    /*for (int i = 0; i < A_B_pot; ++i) {
        cout << A[i] << "\t";
    }
    cout << endl;*/
    int **AB = new int *[A_B_pot];
    for (int i = 0; i < A_B_pot; i++)
        AB[i] = new int[A_B_pot];
    //створення та виведення матриці відношення
    creat(A, B, AB, A_B_pot);
    output(AB, A_B_pot);
    cout << endl;
    // відношення
    reflex(AB, A_B_pot);
    anti_reflex(AB, A_B_pot);
    symmetry(AB, A_B_pot);
    anti_symmetry(AB, A_B_pot);

    int **C = new int *[A_B_pot];
    for (int i = 0; i < A_B_pot; i++)
        C[i] = new int[A_B_pot];
    for (int j = 0; j < A_B_pot; ++j) {
        for (int i = 0; i < A_B_pot; ++i) {
            C[i][j]=AB[i][j];
        }
    }
    transitivity(AB, C, A_B_pot);

    for (int j = 0; j < A_B_pot; ++j) {
        for (int i = 0; i < A_B_pot; ++i) {
            C[i][j]=AB[i][j];
        }
    }
    anti_transitivity(AB, C, A_B_pot);

    for (int i = 0; i < A_B_pot; i++)
        delete[] AB[i];
    delete[] A;
    delete[] B;
    return 0;
}