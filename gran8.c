#include <stdio.h>
#include <stdlib.h>
void guardarResultado(char *nombre, int numero, char *resultado) {
    FILE *archivo = fopen("salida.txt", "a");  // Abrir el archivo en modo de agregar

    if (archivo != NULL) {
        fprintf(archivo, "Nombre: %s - Número aleatorio: %d - Resultado: %s\n", nombre, numero, resultado);
        fclose(archivo);
    } else {
        printf("Error al guardar el resultado.\n");
    }
}
int main() {
    

    char nombre[50];
    printf("Ingrese su nombre: ");
    scanf("%s", nombre);

    char jugar_nuevo;

    do {
        int numero_aleatorio = rand() % 11 + 2;
        printf("Numero aleatorio: %d\n", numero_aleatorio);

        if (numero_aleatorio == 8) {
            printf("Ganaste!\n");
            guardarResultado(nombre, numero_aleatorio, "Ganaste");
        } else if (numero_aleatorio == 7) {
            printf("Perdiste!\n");
            guardarResultado(nombre, numero_aleatorio, "Perdiste");
        } else {
            printf("Sigue intentando.\n");
            guardarResultado(nombre, numero_aleatorio, "Intento fallido");
        }

        printf("Quieres volver a jugar? (s/n): ");
        scanf(" %c", &jugar_nuevo);
        
    } while (jugar_nuevo == 's' || jugar_nuevo == 'S');

    printf("Gracias por jugar, %s. Hasta luego!\n", nombre);

    return 0;
}

