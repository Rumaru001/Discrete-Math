#ifndef DM_L3_FUNC_H
#define DM_L3_FUNC_H

#include <iostream>
using namespace std;
//функція для вводу масиву
void enter(int *arr, int P){
    for (int i = 0; i < P; ++i) {
        cin >> arr[i];
    }
}

//функція для сортування масиву
void sort(int *arr, int P){
    int tmp;
    for(int j = 0; j < P - 1; j++){
        for(int i = 0; i < P - 1; i++){
            if (arr[i] > arr[i + 1]){
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }
}

//функція для побудови матриці
void creat(int *A, int *B, int **AB, int P){
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < P; ++j) {
            if (A[i]+B[j]>2)
                AB[i][j] = {1};
            else
                AB[i][j] = {0};
        }
    }
}

//функція для виводу матриці
void output(int **AB, int P){
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < P; ++j) {
            cout << AB[i][j] << "   ";
        }
        cout << endl;
    }
}

#endif
