// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    
    cout << "Altura:"<<endl;
    int altura;
    cin >> altura;
    for(int filas = 1; filas <=altura; filas++){
        for(int spaces=0;spaces<altura-filas;spaces++){
            cout<<" ";
        }
        for(int hash1=0;hash1<filas;hash1++){
            cout<<"#";
        }
        cout<<"  ";
        for(int hash2=0;hash2<filas;hash2++){
            cout<<"#";
        }
        cout<<endl;
    }

    return 0;
}
