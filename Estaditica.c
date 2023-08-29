#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_NOTAS 5

// Función para calcular la mediana
float calcularMediana(float notas[]) {
    // Ordenar las notas de menor a mayor
    for (int i = 0; i < NUM_NOTAS - 1; i++) {
        for (int j = 0; j < NUM_NOTAS - i - 1; j++) {
            if (notas[j] > notas[j + 1]) {
                float temp = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = temp;
            }
        }
    }

    
    if (NUM_NOTAS % 2 == 0) {
        return (notas[NUM_NOTAS / 2 - 1] + notas[NUM_NOTAS / 2]) / 2.0;
    } else {
        return notas[NUM_NOTAS / 2];
    }
}


int main() {
    float notas[NUM_NOTAS];
    float suma = 0.0, media, mediana, moda, rango, desviacionEstandar, varianza;

    // Solicitar las notas al usuario
    printf("Ingresa las 5 notas (de 0 a 100):\n");
    for (int i = 0; i < NUM_NOTAS; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
        suma += notas[i];
    }

    // Calcular media
    media = suma / NUM_NOTAS;

    // Calcular mediana
    mediana = calcularMediana(notas);


    // Calcular rango
    float max = notas[0], min = notas[0];
    for (int i = 1; i < NUM_NOTAS; i++) {
        if (notas[i] > max) {
            max = notas[i];
        }
        if (notas[i] < min) {
            min = notas[i];
        }
    }
    rango = max - min;

    // Calcular desviación estándar y varianza
    float sumaDiferenciasCuadradas = 0.0;
    for (int i = 0; i < NUM_NOTAS; i++) {
        sumaDiferenciasCuadradas += pow(notas[i] - media, 2);
    }
    varianza = sumaDiferenciasCuadradas / NUM_NOTAS;
    desviacionEstandar = sqrt(varianza);

    // Mostrar los resultados
    printf("\nResultados:\n");
    printf("Media: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Rango: %.2f\n", rango);
    printf("Desviacion Estandar: %.2f\n", desviacionEstandar);
    printf("Varianza: %.2f\n", varianza);

    // Guardar los resultados en un archivo de texto
    FILE *archivo = fopen("salida.txt", "w");
    if (archivo != NULL) {
        fprintf(archivo, "Media: %.2f\n", media);
        fprintf(archivo, "Mediana: %.2f\n", mediana);
        fprintf(archivo, "Rango: %.2f\n", rango);
        fprintf(archivo, "Desviación Estándar: %.2f\n", desviacionEstandar);
        fprintf(archivo, "Varianza: %.2f\n", varianza);
        fclose(archivo);
        printf("Los resultados se han guardado en 'resultados.txt'.\n");
    } else {
        printf("No se pudo crear el archivo de resultados.\n");
    }

    return 0;
}
