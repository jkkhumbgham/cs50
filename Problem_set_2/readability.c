#include <stdio.h>

int main() {
    //bloque de peticion y guardado del texto a analizar
    printf("Text: ");
    char texto[1000];
    fgets(texto, sizeof(texto), stdin);
    //bloque de iniciacion de las variables para calcular L y S
    int palabras = 0;
    int letras = 0; 
    int oraciones = 0;
    //bloque de cuenta de letras, palabras y oraciones
    for(int i = 0; texto[i] != '\n';i++ ){

        if(texto[i] != ' '){
            
            if((texto[i] != '?')&&(texto[i] != '.')&&(texto[i] != '!')){
                
                letras++;
                
            }else{
                
                oraciones++;
                
            }
            
        }else if(letras != 0){
            
            palabras++;
            
        }
        
    }
    //bloque de calculo de L y S para la formula de index
    float L = ((float) letras / palabras ) * 100.0;
    float S = ((float) oraciones / palabras ) * 100.0;
    //formula de index para calcular el grado aproximando al entero mas cercano
    int grade = 0.0588 * L - 0.296 * S - 15.8;
    //bloque de impresion de los resultados
    if(grade < 1){
        printf("Before Grade 1"); 
    }else if(grade > 16){
        printf("Grade 16+");    
    }else{
        printf("Grade %i", grade);
    }
    
    return 0;
}
