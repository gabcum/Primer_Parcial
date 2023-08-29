#include <stdio.h>

int esPrimo(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num;

    printf("Ingresa un numero: ");
    scanf("%d", &num);

    FILE *archivoResultados = fopen("Salida.txt", "a");
    if (archivoResultados == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    if (esPrimo(num)) {
        printf("%d es un numero primo.\n", num);
        fprintf(archivoResultados, "%d - Primo\n", num);
    } else {
        printf("%d es un numero compuesto.\n", num);
        fprintf(archivoResultados, "%d - Compuesto\n", num);
    }

    fclose(archivoResultados);

    return 0;
}
