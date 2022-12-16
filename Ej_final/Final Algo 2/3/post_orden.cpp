

/* 
POST: imprime los valores almacenados en el orden indicado
*/

void recorrido_pos_orden(Nodo* raiz) 
{
     if(raiz !=NULL)
     {
          recorrido_pos_orden(raiz->izq);
          recorrido_pos_orden(raiz->der);
          cout << nodo->valor << " ";
     }
}