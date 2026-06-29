#include <stdio.h>
#include <ctype.h>

//prototipos de las funciones a utilizar
void jugada(int jugador, char jugada[]);
int calculo(char jugada[]);

int main() {
    //bloc de pedir y llenar jugadas utilizando la funcion jugada
    char player1[100];
    jugada(1, player1);
    char player2[100];
    jugada(2, player2);
    
    //bloc llenar calculo de puntos con la funcion calculo
    int total1 = calculo(player1);
    int total2 = calculo(player2);
    //bloc para imprimir ganador del juego
    if(total1 > total2){
        printf("Player 1 wins!");
    }else if(total2 > total1){
        printf("Player 2 wins!");
    }else{
        printf("Tie!");
    }

    return 0;
}
//funcion que pide, pasa a lowercase y guarda la jugada del jugador
void jugada(int jugador, char jugada[]){
    printf("player %i: ", jugador);
    scanf("%s", jugada);
    for(int i = 0; jugada[i] != '\0'; i++){
        jugada[i] = tolower(jugada[i]);
    }
}
//funcion que toma la jugada y calcula la puntuacion
int calculo(char jugada[]){
    //array de puntos donde puntos[i] representa los puntos de la
    //iesima letra del abecedario
    int puntos[26] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
    
    int total = 0;
    
    for(int i = 0; jugada[i] != '\0'; i++){
        total = total + puntos[jugada[i]-97];
    }
}
