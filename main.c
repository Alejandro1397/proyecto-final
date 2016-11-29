#include <stdio.h>
#include <stdlib.h>
#include "cds.h"

int main(int argc, const char * argv[]) {
    int opcion=0;
    int cantidad=0;
    int j=0;
    char nombre[120];
    int edad;
    printf("Programa de Cd´s de musica!\n");

    do {
        opcion=menu();

        //Aqui va la logica principal
        switch (opcion) {
            case 1:
                 printf("Crear una nueva lista de Cd´s\n");
                 printf("Ã¸Cuantos Cd´s quieres capturar?:");
                 scanf("%d",&cantidad);
                 for(j=0;j<cantidad;j++){
                   printf("Capturando datos del Cd %d\n",j+1);
                   nuevoAlumno();
                 }
                break;
            case 2:
                printf("Guardar lista al archivo\n");
                grabarRegistros(listaAlumnos,indiceAlArreglo);
                break;
            case 3:
                printf("Leer la lista desde el archivo\n");
                indiceAlArreglo=registrosEnArchivo();
                leerRegistros(indiceAlArreglo);
                break;
            case 4:
                printf("Mostrar todos los datos de la lista\n");
                imprimirLista();
                break;
            case 5:
                printf("Agregar un nuevo Cd a la lista\n");
                nuevoAlumno();
                break;
            case 6:
                printf("Calcular el promedio del grupo de alumnos\n");
                calcularPromedio();
                break;
            case 7:
                printf("Buscar Cd por artista\n");
                printf("Introduce el artista a buscar:");
                scanf("%*c%[^\n]",nombre);
                buscarPorNombre(nombre);
                break;
            case 8:
                printf("Buscar alumno por edad\n");
                printf("Introduce la edad a buscar:");
                scanf("%d",&edad);
                buscarPorEdad(edad);
                break;
            case 9:
                printf("Uso futuro\n");
                break;
            case 10:
                printf("Uso futuro\n");
                break;
            default:
                printf("Opcion no vÃ¡lida\n");
                break;
        }


    } while (opcion != 0);
    return 0;
}

