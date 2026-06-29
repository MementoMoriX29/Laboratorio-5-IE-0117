#include <stdio.h>
#include "dinarr.h"

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

    return 0;
}


