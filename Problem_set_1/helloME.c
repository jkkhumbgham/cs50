#include <stdio.h>
//ejercicio helloME pide al usuario un nombre y luego imprime un saludo a dicho nombre
int main() {
    char nombre[50];
    printf("Como te llamas?:");
    scanf("%s",&nombre);
    printf("hola, %s",nombre);

    return 0;
}
