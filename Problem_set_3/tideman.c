// Disclaimer: este codigo solo corresponde a los TODO del ejercicio tideman, 
// para correrlo se necesita el resto del codigo propiedad del staff de cs50.
// Adicional se creo una funcion auxiliar extra para revisar la existencia de ciclos
// para su uso adjuntar el siguiente prototipo: bool existing_cycle(int loser, int winner);

// funcion que asigna los votos a sus rangos y devuelve si el voto es valido
bool vote(int rank, string name, int ranks[])
{
  // loop que itera por los candidatos
    for(int candidato = 0; candidato < candidate_count; candidato++){
      // si un candidato es el que fue votado se le asigna el rango, 
      // por ejemplo si es 3ro el 3er espacio de ranks es el id de dicho candidato
        if(strcmp(candidates[candidato], name) == 0){
            ranks[rank] = candidato;
            return true;
        }
    }
  // si no se encuentra el candidato votado se retorna falso y el voto es invalido
    return false;
}

// funcion que convierte los rangos en preferencias, llena la matriz preferences con cuantos prefieren i sobre j
void record_preferences(int ranks[])
{
  // loop que itera en orden la lista de ranks, itera los que son preferidos sobre.
    for(int preferido = 0; preferido < candidate_count; preferido++){
      // loop que itera sobre los ranks inferiores al preferido actual, suma la preferencia de un candidato sobre el iterado actual
        for(int no_preferido = preferido+1; no_preferido < candidate_count; no_preferido++){
            preferences[ranks[preferido]][ranks[no_preferido]]++;
        }
    }
    return;
}

// Crea y suma todas las parejas, dice quien es el preferido y agrega al contador de parejas
void add_pairs(void)
{
    pair_count = 0;
  // loops para iterar en la matriz, decidiendo un ganador y aumentando el contador de parejas
    for(int i = 0; i < candidate_count; i++){
        for(int j = i+1; j < candidate_count; j++){
          // logica de como decidir quien es el ganador de la pareja
            if(preferences[i][j] > preferences[j][i]){
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }else if(preferences[i][j] < preferences[j][i]){
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Funcion para organizar las parejas de mayor cantidad de votos a menor en base al ganador
void sort_pairs(void)
{
    pair temp;
  // loop para iterar sobre las parejas
    for(int i = 0; i < pair_count; i++){
      // lopp para iterar y comparar, evitamos comparar los valores ya organizados
        for(int j = 0; j < pair_count - 1 - i; j++){
            int valor_j = preferences[pairs[j].winner][pairs[j].loser];
            int valor_siguiente = preferences[pairs[j + 1].winner][pairs[j + 1].loser];
          // logica del swap del bubble sort
            if(valor_j < valor_siguiente){
                temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
    return;
}

// Funcion para definir el grafo de victoria de los candidatos si [i][j] es true i le gano a j
void lock_pairs(void)
{
  // loop para recorrer las parejas y si no hay ciclo agregar el camino al grafo
    for(int pareja = 0; pareja < pair_count; pareja++){
        int winner = pairs[pareja].winner;
        int loser = pairs[pareja].loser;
        if(!existing_cycle(loser, winner)){
            locked[winner][loser] = true;
        }
    }
    return;
}

// Funcion que imprime el ganador
void print_winner(void)
{
    // loop que itera sobre los posibles candidatos a ganar
    for(int fuente = 0; fuente < candidate_count; fuente++){
      // definimos si es el source o el ganador como true, luego verificamos si esto es real
        bool source = true;
      // loop para iterar en las conexiones que llegan a el
        for(int vecinos = 0; vecinos < candidate_count; vecinos++){
          // si hay un camino de otro candidato hacia el significa que no es la fuente por lo tanto no es el ganador
            if(locked[vecinos][fuente] == true){
                source = false;
            }
        }
      // si tras verificar todos los candidatos ninguno se conecta con el es el ganador
        if(source){
            printf("el ganador es: %s \n", candidates[fuente]);
            return;
        }
    }
}

// Funcion auxiliar para verificar si crear un camino haria un ciclo
bool existing_cycle(int actual, int buscado){
  // caso base si ya estamos en el nodo buscado retornamos que si se haria un ciclo
    if(actual == buscado){
        return true;
    }
  // loop que itera sobre los candidatos buscando vecinos del nodo actual
    for(int candidato = 0; candidato < candidate_count; candidato++){
      // si el nodo actual tiene vecinos llamamos a la funcion para buscar desde el vecino
        if(locked[actual][candidato] == true){
          // si el vecino tiene un camino al nodo actual devolvemos true
            if(existing_cycle(candidato,buscado)){
              return true;
            }
        }
    }
  // si se verificaron todos los candidatos y no hay mas vecinos o ningun vecino devolvio true retornamos false,
  // indicando que no se hace un ciclo
    return false;
}
