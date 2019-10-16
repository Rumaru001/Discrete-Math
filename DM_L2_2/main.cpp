#include <iostream>

using namespace std;

int main() {
    int N, M;
    cout << "The number of elements of the array A and B :";
    cin >> N >> M;
    int A[N];
    int B[M];
    cout << "Enter elements of the array A" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << "Enter elements of the array B" << endl;
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    /*for (int j = 0; j < N; ++j) {
        cout << A[j] << " ";
    }
    cout << endl;
    for (int j = 0; j < M; ++j) {
        cout << B[j] << " ";
    }*/
    int n = 0;
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < M; ++i) {
            if (A[k] == B[i])
                ++n;
        }
    }
    int aandb[n], f = 0;
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < M; ++i) {
            if (A[k] == B[i])
                aandb[f++] = A[k];
        }
    }
    cout << "A /\\ B = { ";
    for (int j = 0; j < n; ++j) {
        cout << aandb[j] << " ";
    } cout << "}";
        /*об'єднання*/
    int AB[N+M], k = 0;
    for (int l = 0; l < N; ++l) {
        AB[k++] = A[l];
    }
    for (int l = 0; l < M; ++l) {
        AB[k++] = B[l];
    }
    /*for (int m = 0; m < N + M; ++m) {
        cout << AB[m] << " ";
    } cout << endl;*/
    // сортування масиву
    int temp, size = N + M;
    k = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (AB[j] > AB[j + 1]) {
                temp = AB[j];
                AB[j] = AB[j + 1];
                AB[j + 1] = temp;
            }
        }
    }
    /*for (int i = 0; i < N + M; i++) {
        cout << AB[i] << " ";
    } cout << endl;*/
    // видалення одинакових елементів масиву
    for (int i = 0; i < size; ++i) {
        if (AB[i] == AB[i + 1]) {
            for (int j = i; j < size; ++j) {
                AB[j+1] = AB[j+2];
            }
            ++k;
        }
    }
    cout << endl << "A \\/ B = { ";
    k = int(k/2+1);
    for (int i = 0; i < size-k; i++) {
        cout << AB[i] << " ";
    } cout << "}";

    cout << endl << "|A /\\ B| = " << sizeof(aandb)/4;
    cout << endl << "|A \\/ B| = " << sizeof(AB)/4-k;

    return 0;
}