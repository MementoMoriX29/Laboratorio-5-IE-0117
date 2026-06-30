#include <stdio.h>
#include "listadbl.h"
#include "dinarr.h"
#include "lista.h"

int main(void) {
    DinaArray arr;

    printf("=== Arreglos Dinamicos ===\n");

    printf("\n-- Creacion (capacidad inicial 2) --\n");
    da_init(&arr, 2);
    da_print(&arr);

    printf("\n-- Agregar elementos (da_push) --\n");
    da_push(&arr, 10);
    da_push(&arr, 20);
    da_push(&arr, 30); /* aqui deberia expandir la capacidad */
    da_push(&arr, 40);
    da_print(&arr);

    printf("\n-- Obtener elemento por indice (da_get) --\n");
    printf("Elemento en indice 2: %d\n", da_get(&arr, 2));

    printf("\n-- Eliminar elemento (da_eliminar, indice 1) --\n");
    da_eliminar(&arr, 1);
    da_print(&arr);

    printf("\n-- Liberar memoria (da_free) --\n");
    da_free(&arr);

    

    /* ── LISTA DOBLEMENTE ENLAZADA ─────────────────────── */
    ListaDbl ld;
    printf("\n=== Lista Doblemente Enlazada ===\n");

    ld_init(&ld);

    printf("\n-- Insertar al inicio --\n");
    ld_insertar_inicio(&ld, 10);
    ld_insertar_inicio(&ld, 20);
    ld_print_adelante(&ld);

    printf("\n-- Insertar al final --\n");
    ld_insertar_final(&ld, 30);
    ld_print_adelante(&ld);

    printf("\n-- Insertar en posicion 1 --\n");
    ld_insertar_pos(&ld, 1, 99);
    ld_print_adelante(&ld);

    printf("\n-- Buscar elemento --\n");
    printf("Buscar 10: %d\n", ld_buscar(&ld, 10));
    printf("Buscar 55: %d\n", ld_buscar(&ld, 55));

    printf("\n-- Eliminar elemento (99) --\n");
    ld_eliminar(&ld, 99);
    ld_print_adelante(&ld);

    printf("\n-- Imprimir hacia atras --\n");
    ld_print_atras(&ld);

    printf("\n-- Liberar memoria --\n");
    ld_free(&ld);

    return 0;
}


