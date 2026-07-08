// Disclaimer: este codigo corresponde a los TODO del ejercicio plurality
// para probarlo se necesita el resto del codigo que es propiedad del staff de cs50


//Funcion que suma los votos al candidato dado el nombre
bool vote(string name)
{
  //loop que itera por los candidatos revisando si el nombre es de un candidato
    for(int i = 0; i < candidate_count; i++){
      //si el nombre existe en el array suma un voto y retorna true (el voto es valido)
        if(strcmp(candidates[i].name , name) == 0){
            candidates[i].votes++;
            return true;
        }
    }
  // si no encuentra ningun candidato con el nombre del voto devuelve false (voto invalido)
    return false;
}

// Funcion que ve la cantidad de votos y imprime el ganador
void print_winner(void)
{
  // variable del maximo actual de votos
    int max = 0;
  // loop que recorre el array de candidatos buscando la mayor cantidad de votos
    for(int i = 0; i < candidate_count; i++){
        if(candidates[i].votes > max){
            max = candidates[i].votes;
        }
    }
  // loop que una vez encontrado el maximo busca todos los candidatos con esta cantidad de votos
  // y imprime los ganadores
    printf("Los ganadores son: ");
    for(int i = 0; i < candidate_count; i++){
        if(candidates[i].votes == max){
            printf("%s  ", candidates[i].name);
        }
    }
    printf("\n");
    return;
}
