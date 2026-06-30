#ifndef LISTADBL_H
#define LISTADBL_H
#include <stddef.h>

/* Nodo de la lista doblemente enlazada */
typedef struct NodoDbl {
    int data;
    struct NodoDbl *ant;
    struct NodoDbl *sig;
} NodoDbl;

/* Lista doblemente enlazada */
typedef struct {
    NodoDbl *cabeza;
    NodoDbl *cola;
    size_t   size;
} ListaDbl;

/* Inicializa la lista vacía. */
void ld_init(ListaDbl *l);

/* Inserta un nuevo nodo al inicio. */
void ld_insertar_inicio(ListaDbl *l, int valor);

/* Inserta un nuevo nodo al final. */
void ld_insertar_final(ListaDbl *l, int valor);

/* Inserta un nuevo nodo en la posición i (0 = inicio). */
void ld_insertar_pos(ListaDbl *l, size_t i, int valor);

/* Elimina la primera ocurrencia del nodo cuyo data coincida con valor. */
void ld_eliminar(ListaDbl *l, int valor);

/* Busca un valor. Retorna 1 si lo encuentra, 0 si no. */
int ld_buscar(ListaDbl *l, int valor);

/* Imprime la lista de adelante hacia atrás. */
void ld_print_adelante(ListaDbl *l);

/* Imprime la lista de atrás hacia adelante. */
void ld_print_atras(ListaDbl *l);

/* Libera toda la memoria y resetea la estructura. */
void ld_free(ListaDbl *l);

#endif
