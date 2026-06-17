
#include <stdio.h>
#include <math.h>
int main() {
    long int numero;
    long int aux_num;
    int cont = 1;
    int pares = 0;
    int inpares = 0;
    printf("Numero de tarjeta?:");
    scanf("%ld",&numero);
    aux_num = numero;
  //loop para obtener y operar los digitos
    while(numero != 0){
      //obtencion del digito
        int digito = numero % 10;
      //bloque para detectar si es par o inpar y multiplicar acorde
        if(cont % 2 != 0){

            inpares = inpares + digito;
        }else{
          //verificacion de solo sumar de a 1 digito
            if((digito*2)<9){
                pares = pares + digito*2;
            }else{
                pares = pares + (digito*2)%10;
                pares = pares + (digito*2)/10;
            }
        }
        cont++;
        numero = numero / 10;
    }
  //verificacion de validez del numero
    int total = pares + inpares;
    if(total % 10 == 0){
      //uso de reglas para identificar la marc de la tarjeta
        int identificador = aux_num / pow(10, cont-3);
        if((identificador == 34) || (identificador == 37)){
            printf("AMEX\n");
        }else if(identificador/10 == 4){
            printf("VISA\n");
        }else{
            printf("MASTERCARD\n");
        }
    }else{
        printf("INVALID\n");
    }
    

    return 0;
}
