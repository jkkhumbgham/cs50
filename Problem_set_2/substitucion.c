#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  //bloque para verificar si el usuario puso los argumentos esperados
    if(argc != 2){
        printf("Usage: ./Substitucion key\n");
        return 1;
    }
    //bloque de asignacion de argumentos, ponemos la key dada por el usuario en nuestra variable
    char *key = argv[1];

  //bloque de peticion del texto a cifrar
    char texto[100];
    printf("PlainText: ");
    fgets(texto, sizeof(texto), stdin);
  //bloque de cifrado del texto, si es tomamos el valor ascii y restamos 97 para encontrar la posicion en la key
    printf("CypherText: ");
    for(int i = 0; texto[i] != '\n'; i++){
        //Si es una mayuscula se pasa a miniscula
        if ((texto[i]>=65)&&(texto[i]<=90))
        {
            texto[i] = tolower(texto[i]);
        }
        //si es una letra minuscula se cifra si no se imprime tal como es, asi no borramos espacios ni signos de puntuacion
        if ((texto[i]-97>=0)&&(texto[i]-97<=26))
        {
            
            printf("%c", key[texto[i]-97]);
        }else{
            printf("%c", texto[i]);
        }
        
    }
    printf("\n");
    return 0;
}
