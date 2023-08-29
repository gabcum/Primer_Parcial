#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ADIVINANZAS 5

int main() {
    char preguntas[NUM_ADIVINANZAS][100] = {
        "Blanco por dentro, verde por fuera. Si quieres que te lo diga, espera.",
        "Tengo agujas y no se tejer, tengo numero y no se leer",
        "Blanco es, no es ave, y tiene cresta sin ser casco.",
        "Oro parece, plata no es, abre la cortina y veras lo que es.",
        "Aunque nunca habla, siempre responde. Siempre va y viene, nunca se esconde."
    };

    char respuestas[NUM_ADIVINANZAS][50] = {
        "pera", "reloj", "copo", "platano", "eco"
    };

    int aciertos = 0;

    printf("Bienvenido al juego de adivinanzas!\n");
    for (int i = 0; i < NUM_ADIVINANZAS; i++) {
        printf("\n%s\nTu respuesta: ", preguntas[i]);

        char respuestaUsuario[100];  // Longitud máxima desconocida
        fgets(respuestaUsuario, sizeof(respuestaUsuario), stdin);
        respuestaUsuario[strcspn(respuestaUsuario, "\n")] = '\0';

        if (strcasecmp(respuestaUsuario, respuestas[i]) == 0) {
            printf("Correcto!\n");
            aciertos++;
        } else {
            printf("Incorrecto. La respuesta correcta es: %s\n", respuestas[i]);
        }
    }

    printf("\nHas acertado %d adivinanzas.\n", aciertos);

    // Solicitar y guardar el nombre y la puntuación en un archivo
    char nombre[50];  // Longitud máxima desconocida
    printf("Por favor, ingresa tu nombre: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    FILE *archivoPuntuaciones = fopen("puntuaciones.txt", "a");
    if (archivoPuntuaciones == NULL) {
        printf("Error al abrir el archivo de puntuaciones.\n");
        return 1;
    }

    fprintf(archivoPuntuaciones, "Nombre: %s, Aciertos: %d\n", nombre, aciertos);
    fclose(archivoPuntuaciones);

    printf("Tu puntuacion ha sido guardada en el archivo 'puntuaciones.txt'.\n");

    return 0;
}

