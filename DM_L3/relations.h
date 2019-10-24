#ifndef DM_L3_RELATIONS_H
#define DM_L3_RELATIONS_H

#include <iostream>

using namespace std;

// для перевірки на рефлексивність
int reflex(int **arr, int P) {
    for (int i = 0; i < P; ++i) {
        if (arr[i][i] == 1)
            continue;
        else {
            cout << "Ne Refleksyvne" << endl;
            return 0;
        }
    }
    cout << "Refleksyvne" << endl;
    return 0;
}

// для перевірки на антирефлексивність
int anti_reflex(int **arr, int P) {
    for (int i = 0; i < P; ++i) {
        if (arr[i][i] == 0)
            continue;
        else {
            cout << "Ne AntiRefleksyvne" << endl;
            return 0;
        }
    }
    cout << "AntiRefleksyvne" << endl;
    return 0;
}

// для перевірки на симетричність
int symmetry(int **arr, int P) {
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < P; ++j) {
            if (arr[i][j] == 1) {
                if (arr[i][j] == arr[j][i])
                    continue;
                else {
                    cout << "Ne Symetrychne" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Symetrychne" << endl;
    return 0;
}

// для перевірки на антисиметричність
int anti_symmetry(int **arr, int P) {
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < P; ++j) {
            if (i == j){
                continue;
            }
            if (arr[i][j] == 1) {
                if (arr[j][i] == 0)
                    continue;
                else {
                    cout << "Ne AntiSymetrychne" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "AntiSymetrychne" << endl;
    return 0;
}

// перевірка на транзитивність
int transitivity(int **arr, int **a, int P){
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < P; ++j) {
            if (arr[i][j] == 1) {
                /*if (i == j)
                    continue;*/
                for (int k = 0; k < P; ++k) {
                    if (arr[j][k]==1 && arr[i][k]==1){
                        if (i == k && i == j){
                            continue;
                        }else {
                            a[i][j] = 0;
                            a[j][k] = 0;
                            a[i][k] = 0;
                        }
                    }
                }
            }
        }
    }
    int cntr = 0;
    for (int l = 0; l < P; ++l) {
        for (int i = 0; i < P; ++i) {
            if (a[l][i]==1)
                cntr++;
        }
    }
    if (cntr == 0)
        cout << "Tranzytyvne" << endl;
    else
        cout << "Ne Tranzytyvne"<<endl;
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < P; ++j) {
            cout << a[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}

//перевірка на антитранзитивність
int anti_transitivity(int **arr, int **a, int P){
    int cntr = 0;
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < P; ++j) {
            if (arr[i][j] == 1) {
                /*if (i == j)
                    continue;*/
                for (int k = 0; k < P; ++k) {
                    if (arr[j][k]==1 && arr[i][k]==0){
                        if (i == k && i == j){
                            continue;
                        }else {
                            a[i][j] = 0;
                            a[j][k] = 0;
                            a[i][k] = 0;
                        }
                    }
                }
            }
        }
    }
    for (int l = 0; l < P; ++l) {
        for (int i = 0; i < P; ++i) {
            if (a[l][i]==1)
                cntr++;
        }
    }
    if (cntr == 0)
        cout << "AntiTranzytyvne";
    else
        cout << "Ne AntiTranzytyvne"<<endl;
    /*for (int i = 0; i < P; ++i) {
        for (int j = 0; j < P; ++j) {
            cout << a[i][j] << "   ";
        }
        cout << endl;
    }*/
    return 0;
}

#endif