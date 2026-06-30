#ifndef LISTAENL_H
#define LISTAENL_H
#include <stddef.h>

/* Nodo de la lista enlazada */
typedef struct Nodo {
    int data;
    struct Nodo *sig;
} Nodo;

/* Lista enlazada simple */
typedef struct {
    Nodo   *cabeza;
    size_t  size;   /* cantidad de nodos */
} ListaEnl;

/* Inicializa la lista vacía. */
void le_init(ListaEnl *l);

/* Inserta un nuevo nodo al inicio de la lista. */
void le_insertar_inicio(ListaEnl *l, int valor);

/* Inserta un nuevo nodo al final de la lista. */
void le_insertar_final(ListaEnl *l, int valor);

/* Inserta un nuevo nodo en la posición i (0 = inicio). */
void le_insertar_pos(ListaEnl *l, size_t i, int valor);

/* Elimina la primera ocurrencia del nodo cuyo data coincida con valor. */
void le_eliminar(ListaEnl *l, int valor);

/* Busca un valor en la lista. Retorna 1 si lo encuentra, 0 si no. */
int le_buscar(ListaEnl *l, int valor);

/* Imprime la lista de adelante hacia atrás. */
void le_print(ListaEnl *l);

/* Libera toda la memoria reservada y resetea la estructura. */
void le_free(ListaEnl *l);

#endif
