#include <stdio.h>
#include <stdlib.h>
#include "cds.h"

int main(int argc, const char * argv[]) {
    int opcion=0;
    int cantidad=0;
    int j=0;
    char nombre[120];
    int canciones;
    printf("Programa de Cd�s de musica!\n");

    do {
        opcion=menu();

        //Aqui va la logica principal
        switch (opcion) {
            case 1:
                 printf("Crear una nueva lista de Cd�s\n");
                 printf("øCuantos Cd�s quieres capturar?:");
                 scanf("%d",&cantidad);
                 for(j=0;j<cantidad;j++){
                   printf("Capturando datos del Cd %d\n",j+1);
                   nuevoCd();
                 }
                break;
            case 2:
                printf("Guardar lista al archivo\n");
                grabarRegistros(listaCd,indiceAlArreglo);
                break;
            case 3:
                printf("Leer la lista desde el archivo\n");
                 indiceAlArreglo=registrosEnArchivo();
                printf("Se encontraron %d registros\n",indiceAlArreglo);
        		//Lectura del arreglo en memoria
                leerRegistros(indiceAlArreglo);
                break;
            case 4:
                printf("Mostrar todos los datos de la lista\n");
                imprimirLista();
                break;
            case 5:
                printf("Agregar un nuevo Cd a la lista\n");
                nuevoCd();
                break;
            case 6:
                printf("Calcular el promedio de canciones\n");
                calcularPromedioCanciones();
                break;
            case 7:
                printf("Buscar Cd por artista\n");
                printf("Introduce el artista a buscar:");
                scanf("%*c%[^\n]",nombre);
                buscarPorNombreArtista(nombre);
                break;
            case 8:
                printf("Buscar cd por numero de canciones\n");
                printf("Introduce el numero de canciones a buscar:");
                scanf("%d",&canciones);
                buscarPorCanciones(canciones);
                break;
            case 9:
                printf("Uso futuro\n");
                break;
            case 10:
                printf("Uso futuro\n");
                break;
            default:
                printf("Opcion no válida\n");
                break;
        }


    } while (opcion != 0);
    return 0;
}

