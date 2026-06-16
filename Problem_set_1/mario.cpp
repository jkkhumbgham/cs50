#include <iostream>
using namespace std;
int main() {
    //pedir y almacenar la altura al usuario
    cout << "Altura:"<<endl;
    int altura;
    cin >> altura;
    //loops para las filas, mismo tamaño que la altura dada por el usuario
    for(int filas = 1; filas <=altura; filas++){
        //loop que imprime los espacios a la izquierda de los hashes
        for(int spaces=0;spaces<altura-filas;spaces++){
            cout<<" ";
        }
        //loop que imprime los primeros hashes luego de los espacios
        for(int hash1=0;hash1<filas;hash1++){
            cout<<"#";
        }
        cout<<"  ";
        //loop que imprime los hashes luego de el doble espacio para completar la piramide
        for(int hash2=0;hash2<filas;hash2++){
            cout<<"#";
        }
        cout<<endl;
    }

    return 0;
}
