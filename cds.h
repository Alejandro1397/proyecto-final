#define MAX 200

#ifndef cds_h
#define cds_h

struct cds
{
	int canciones;
	char nombre[200];
	char genero [200];
	char album[120];
	float ventas;
};

typedef struct cds CD;
int indiceAlArreglo=0;// esta variable global se usara para almacenar el indice del ultimo cd ingresado al arreglo
CD listaCd[MAX];// declaracion de un arreglo de cds de 200 elementos

/**  Funcion insertarCD
 *
 * Descripcion:
 *   Funcion para insertar al arreglo un nuevo cd,
 * Entrada:
 *     la funcion  recibe un cd "al" de entrada.
 * LÛgica interna:
 *     Verifica que el indice este en el rango adecuado, entre 0 y MAX.
 *     de cumplirse ingresa el alumno al arreglo e incrementa el indice general
 * Valor de retorno:
 *     No regresa nada.
 */
void insertarCd(CD cd){
	if (indiceAlArreglo >= 0 && indiceAlArreglo < MAX) { // verificamos que inidice este en los rangos correctos
        listaCD[indiceAlArreglo]=cd;
        indiceAlArreglo++;
    }else{
        printf("El indice apunta fuera del arreglo, favor de revisar la logica");
    }
}

/** Funcion nuevoAlumno
 * DescripciÛn:
 *   Funcion para capturar los datos desde teclado de un nuevo alumno,
 * Entrada:
 *     la funciÛn no recibe ningun parametro de entrada.
 * LÛgica interna:
 *     Crea una variable temporal del tipo alumno y se obtienen los datos desde el teclado.
 *     TambÌen se agrega el alumno al arreglo
 * Valor de retorno:
 *     Regreza la variable temporal con los datos llenos.
 */
 CD nuevoCd(){
    CD tmp;
    printf("Introduce el nombre del Artista:");
    scanf("%d",&tmp.nombre);
    printf("Introduce el genero:");
    scanf(" %c",&tmp.genero);   // El espacio antes del %c es para que ignore espacios en blanco
    printf("Introduce el nombre del album:");
    //fflush(stdin);// limpia el buffer de teclado
    //gets(tmp.nombre);
    scanf("%*c%[^\n]",tmp.album);
    printf("Introduce n�mero de canciones:");
    //fflush(stdin);// limpia el buffer de teclado
    //gets(tmp.carrera);
    scanf("%d",tmp.canciones);
    printf("Introduce numero de ventas:");
    scanf("%f",&tmp.ventas);
    /*
     * Aqui agregamos al alumno al arreglo e incrementamos el indice para que apunte al siguiente elementos
     */
    insertarCd(tmp);
    return tmp;
}

/** funcion imprimeCd
 * DescripciÛn:
 *   Funcion para imprimir en pantalla los datos de un solo alumno,
 * Entrada:
 *     la funciÛn  recibe la variable alumno a ser impresa.
 * LÛgica interna:
 *     SÛlo imprime cada uno de los campos
 * Valor de retorno:
 *     No regresa nada
 */
void imprimeCd(CD cd){
    printf("**************************\n");
    printf("Nombre del artista:%s\n",al.nombre);
    printf("Genero:%c\n",al.genero);
    printf("Nombre del album:%s\n",al.genero);
    printf("Numero de canciones:%d\n",al.canciones);
    printf("Ventas:%.2f\n",al.ventas);
    printf("**************************\n");
}

/** funcion imprimirLista
 * DescripciÛn:
 *   Funcion para imprimir en pantalla TODOS los datos del arreglo.
 * Entrada:
 *     la funciÛn NO recibe parametros de entrada.
 * LÛgica interna:
 *     en un for recorre el arreglo hasta el indiceAlArreglo que es el que almacena el tope actual
 * Valor de retorno:
 *     No regresa nada
 */
void imprimirLista(){
    int j=0;
    for (j = 0; j < indiceAlArreglo; j++) {
        imprimeCd(listaCd[j]);
    }
}

/** funcion buscarPorNombre
 * DescripciÛn:
 *   funcion que busca un alumno a partir de una cadena de texto en el campo nombre
 * Entrada:
 *     Un array de tipo char con la cadena a buscar.
 * LÛgica interna:
 *     en un for recorre el arreglo hasta que la cadena recibida sea igual al campo nombre y de coincidir lo imprime en pantalla
 * Valor de retorno:
 *     No regresa nada
 */
void buscarPorNombreArtista(char *nombre){
    int j=0;
    for (j = 0; j < indiceAlArreglo; j++) {
        if(strcmp(listaCd[j].nombre,nombre) == 0){
            imprimeCd(listaCd[j]);
        }
    }
}

void buscarPorVentas(float v){
    int j=0;
    for (j = 0; j < indiceAlArreglo; j++) {
        if(v == listaCd[j].ventas){
            imprimeCd(listaCd[j]);
        }
    }
}

void calcularPromedioCanciones(){
    int j=0;
    int tmp=0;
    for (j = 0; j < indiceAlArreglo; j++) {
        tmp= tmp + listaCd[j].canciones;
    }
    printf("\nEl promedio de las canciones de los albunes en la BD es: %d!",tmp/indiceAlArreglo);
}

int menu(){
    int opcion=0;
    printf("\n----------- Menu para la aplicacion de BD para alumnos ---------\n");
    printf("(1) Crear lista.\n");
    printf("(2) Guardar a archivo.\n");
    printf("(3) Leer desde archivo.\n");
    printf("(4) Mostrar lista.\n");
    printf("(5) Agregar Cd. \n");
    printf("(6) Obtener promedio de canciones.\n");
    printf("(7) Buscar Cd por artista. \n");
    printf("(8) Buscar Cd por ventas. \n");
    printf("(9) NA \n");
    printf("(10) NA \n");
    printf("(0) SALIR\n");
    printf("\n\nElige una opcion:");
    scanf("%d",&opcion);

    return opcion;
}

/**
Manejo de archivos
*/

/*
 Funcion para grabar un ARREGLO DE REGISTROS
 en el archivo Evaluaciones.dat
 */
void grabarRegistros(CD r[], int tam){
    FILE *ptrF;

    if((ptrF=fopen("Cds.dat","w"))==NULL){
        printf("el archivo no se puede abrir\n");
    }else{
        fwrite(r,sizeof(CD),tam,ptrF);
    }

    fclose(ptrF);
}

/*
 Funcion para LEER  REGISTROs
 en el archivo Evaluaciones.dat
 */
void leerRegistros(int tam){

    FILE *ptrF;

    if((ptrF=fopen("Cds.dat","rb"))==NULL){
        printf("el archivo no se puede abrir\n");
    }
    else{
        //for /*(int i=0;i<tam;i++)*/
        fread(listaCd,sizeof(CD),tam,ptrF);
    }

    fclose(ptrF);
}

 
 
 
