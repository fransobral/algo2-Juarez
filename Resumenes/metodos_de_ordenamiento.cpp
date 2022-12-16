//BUBBLESORT: Intercambia el de la izq por el de la derecha si es mayor. Hay q correrlo varias veces para que ordene todo.
for (i=1; i<TAM; i++){
    for j=0 ; j<TAM - 1; j++){
        if (lista[j] > lista[j+1]){
            temp = lista[j];
            lista[j] = lista[j+1];
            lista[j+1] = temp;}}}

//POR SELECCION: Busca el elemento mas chico en la lista y lo pone en la primera posicion intercambiando la posicion con el q estaba antes primero.

int Menor(lista,TAM,i){
    for (i,i>TAM,i++){
        menor = lista[i];
        pos_menor = i;
        if (lista[i] < menor){
            pos_menor = i;
        }
    }
    return pos_menor;
}

for (i=0; i<TAM - 1; i++){
    pos_men = Menor(lista, TAM, i);
    temp = lista[i];
    lista[i] = lista [pos_men];
    lista [pos_men] = temp;
    }

//POR INSERCCION: Vamos insertando el numero menor donde corresponda, moviendo todos los mayores uno para la derecha
for (i=1; i<TAM; i++){
    temp = lista[i];
    j = i - 1;
    while ( (lista[j] > temp) && (j >= 0) ){
        lista[j+1] = lista[j];
        j--;}
    lista[j+1] = temp;}

