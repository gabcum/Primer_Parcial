#include <stdio.h>


int main() {

    char continuar;

    do
    {
        float precioIva, iva, PrecioSinIva;

        printf("Ingrese el precio en quetzales: ");
        scanf("%f", &precioIva);

        iva = precioIva * 0.12;
        PrecioSinIva = precioIva - iva;

        printf("El monto de IVA es: %.2f Quetzales\n", iva);
        printf("El monto sin IVA es: %.2f Quetzales\n", PrecioSinIva);

        FILE *archivo = fopen("resultados.txt", "w");
        if (archivo==NULL)
        {
            printf("Error al abrir el archivo");
            return 1;
        }

        fprintf(archivo, "Monto de IVA: %.2f Quetzales\n", iva);
        fprintf(archivo, "El monto sin IVA es: %.2f Quetzales\n", PrecioSinIva);

        fclose(archivo);
        

        printf("¿Deseas calcular otro precio? (S/N): ");
        scanf(" %c", &continuar);

        
    } while (continuar == 'S' || continuar == 's');
    
    return 0;
}