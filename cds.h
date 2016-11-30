#define MAX 200

#ifndef cds_h
#define cds_h

struct cds
{
	int canciones;
	char nombre[200];
	char genero [200];
	char album[120];
	char disquera[100];
	float ventas;
};

typedef struct cds CD;
int indiceAlArreglo=0;// esta variable global se usara para almacenar el indice del ultimo cd ingresado al arreglo
CD listaCd[MAX];// declaracion de un arreglo de cds de 200 elementos


void insertarCd(CD cd){
	if (indiceAlArreglo >= 0 && indiceAlArreglo < MAX) { // verificamos que inidice este en los rangos correctos
        listaCd[indiceAlArreglo]=cd;
        indiceAlArreglo++;
    }else{
        printf("El indice apunta fuera del arreglo, favor de revisar la logica");
    }
}

 CD nuevoCd(){
    CD tmp;
    printf("Introduce el album:");
    scanf("%c",&tmp.album);
    printf("Introduce numero de canciones:");
    scanf(" %d",&tmp.canciones);   // El espacio antes del %c es para que ignore espacios en blanco
    printf("Introduce el nombre del artista:");
    //fflush(stdin);// limpia el buffer de teclado
    //gets(tmp.nombre);
    scanf("%*c%[^\n]",tmp.nombre);
    printf("Introduce Disquera:");
    //fflush(stdin);// limpia el buffer de teclado
    //gets(tmp.carrera);
    scanf("%*c%[^\n]",tmp.disquera);
    printf("Introduce numero de premios:");
    //fflush(stdin);// limpia el buffer de teclado
    //gets(tmp.nCuenta);
    scanf("%*c%[^\n]",tmp.ventas);
    printf("Introduce numero de ventas:");
    scanf("%f",&tmp.ventas);
    /*
     * Aqui agregamos al alumno al arreglo e incrementamos el Ìndice para que apunte al siguiente elementos
     */
    insertarCd(tmp);
    return tmp;
}

void imprimeCd(CD cd){
    printf("**************************\n");
    printf("Nombre del artista:%s\n",cd.nombre);
    printf("Genero:%c\n",cd.genero);
    printf("Nombre del album:%s\n",cd.genero);
    printf("Numero de canciones:%d\n",cd.canciones);
    printf("Ventas:%.2f\n",cd.ventas);
    printf("**************************\n");
}

void imprimirLista(){
    int j=0;
    for (j = 0; j < indiceAlArreglo; j++) {
        imprimeCd(listaCd[j]);
    }
}


void buscarPorNombreArtista(char *nombre){
    int j=0;
    for (j = 0; j < indiceAlArreglo; j++) {
        if(strcmp(listaCd[j].nombre,nombre) == 0){
            imprimeCd(listaCd[j]);
        }
    }
}

void buscarPorCanciones(int c){
    int j=0;
    for (j = 0; j < indiceAlArreglo; j++) {
        if(c == listaCd[j].canciones){
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
    printf("(8) Buscar Cd por canciones. \n");
    printf("(9) NA \n");
    printf("(10) NA \n");
    printf("(0) SALIR\n");
    printf("\n\nElige una opcion:");
    scanf("%d",&opcion);

    return opcion;
}

void grabarRegistros(CD r[], int tam){
    FILE *ptrF;

    if((ptrF=fopen("Cds.dat","w"))==NULL){
        printf("el archivo no se puede abrir\n");
    }else{
        fwrite(r,sizeof(CD),tam,ptrF);
    }

    fclose(ptrF);
}

int registrosEnArchivo()
{
	FILE *ptrF;
	int cont=0;
	CD tmp;
	if((ptrF=fopen("Cds.dat","rb"))== NULL)
	{
		printf("Error al abrir el archivo\n");
	}else{
		while(!feof(ptrF)){
			if(fread(&tmp,sizeof(CD),1,ptrF))
			cont++;
		}
	}
	fclose(ptrF);
	return cont;	
}


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

#endif /* alumnos_h */

 
 
 
