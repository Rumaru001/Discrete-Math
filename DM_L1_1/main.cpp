#include <iostream>
using namespace std;

int main() {
    int x, y, z, P, Q;
    cout << "Print x, y, z" << endl;
    cin >> x >> y >> z;
    for ( ; ; ) {
        if ((x == 1 || x == 0)&&(y == 1 || y == 0)&&(z == 1 || z == 0)){
            break;
        } else{
            cout << "ERROR!!!" << endl;
            cin >> x >> y >> z;
        }
    }
/*
    cout << "Print y" << endl;
    cin >> y ;
    for ( ; ; ) {
        if (y == 1 || y == 0){
            break;
        } else{
            cout << "ERROR!!! Please, print y" << endl;
            cin >> y ;
        }
    }

    cout << "Print z" << endl;
    cin >> z ;
    for ( ; ; ) {
        if (z == 1 || z == 0){
            break;
        } else{
            cout << "ERROR!!! Please, print z" << endl;
            cin >> z ;
        }
    }
*/
    if (x && y && z == 1){
        P = 1;
    } else{
        P = 0;
    }
    if (x || y || z == 1){
        Q = 1;
    } else{
        Q = 0;
    }
    if (P == 1 && Q == 0){
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "z = " << z << endl;
        cout << "(x /\\ (y /\\ z)) --> (x V y V z)" << endl << "FALSE" << endl;
    } else{
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "z = " << z << endl;
        cout << "(x /\\ (y /\\ z)) --> (x V y V z)" << endl << "TRUE" << endl;
    }
}