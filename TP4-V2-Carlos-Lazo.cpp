#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define tama 1024

typedef struct {
	int TareaID; //Numerado en ciclo iterativo
	char *Descripcion; //
	int Duracion; // entre 10 – 100
}Tarea; 


void cargar(Tarea **Pendientes, int n);
void realizadas(Tarea **Pendientes, Tarea **Realizadas, int n);
void mostrarRealizadas(Tarea **Realizadas,int n);
Tarea BuscarID(Tarea **Realizadas, int n);
void resultadoID(Tarea BuscaID);
Tarea Buscapalabra(Tarea **Realizadas, int n);
void resultadoPalabra(Tarea BuscaP);


int main()
{	
	int n;
	srand(time(NULL));

	puts("Cantidad de tareas a cargar");
	scanf("%i",&n);
	fflush(stdin);

	Tarea **TareasPendientes=(Tarea**)malloc(sizeof(Tarea)* n); 
	Tarea **TareasRealizadas=(Tarea**)malloc(sizeof(Tarea)* n); 
	Tarea BuscaID;
	Tarea BuscaP;

	cargar(TareasPendientes,n);
	realizadas(TareasPendientes, TareasRealizadas, n);
	mostrarRealizadas(TareasRealizadas, n);

	BuscaID=BuscarID(TareasRealizadas,n);
	resultadoID(BuscaID);

	BuscaP=Buscapalabra(TareasRealizadas,n);
	resultadoPalabra(BuscaP);

	getchar();
	return 0;
}

void cargar(Tarea **Pendientes, int n){


	for (int i = 0; i < n; i++)
	{	
		Pendientes[i]= (Tarea*) malloc(sizeof(Tarea));
		Pendientes[i]->TareaID=i+1;
		printf("TareaID:%i\n",i+1);
		puts("Ingrese Descripcion de tarea:");

		char desc[tama];
		fflush(stdin);
		gets(desc);	
		fflush(stdin);

		Pendientes[i]->Descripcion=(char *) malloc (strlen(desc) * sizeof(char));
		strcpy(Pendientes[i]->Descripcion,desc);
		
		Pendientes[i]->Duracion= (rand () % 91 + 10);

	}
}

void realizadas(Tarea **Pendientes, Tarea **Realizadas, int n){

	int key=10;
	int i=0 ;

	for (int j = 0 ; j < n; j++){

		
		printf("\n\nTareaID: %i \n",Pendientes[j]->TareaID);
		printf("Duracion: %i \n",Pendientes[j]->Duracion);
		printf("Descripcion: %s \n",Pendientes[j]->Descripcion);
		
		while(key!=0 && key!=1){

			puts("Se realizo dicha tarea?(si = 1/ no = 0)");
			fflush(stdin);
			scanf("%i",&key);
			fflush(stdin);
		}
		
		if (key==1)
		{
			Realizadas[j] = (Tarea*) malloc(sizeof(Tarea));
			Realizadas[j] = Pendientes[j];
			Pendientes[j] = NULL;
			 			
		}else{

			Realizadas[j]->Duracion=0;
		}	
		

		key=10;
		 
	}

}

void mostrarRealizadas(Tarea **Realizadas,int n){
	
	puts("\nTareas realizadas:\n");

	for (int i = 0; i < n; i++)
	{
		if (Realizadas[i]->Duracion!=0)
		{
			printf("TareaID: %i\n",Realizadas[i]->TareaID);
			printf("Duracion: %i\n",Realizadas[i]->Duracion);
			printf("Descripcion: %s\n",Realizadas[i]->Descripcion);
		}
				
	}
	
}

Tarea BuscarID(Tarea **Realizadas, int n){
	
	int key;
	puts("Ingrese el ID a Buscar: ");
	fflush(stdin);
	scanf("%i",&key);
	fflush(stdin);

	for (int i = 0; i < n; i++)
	{
			if (Realizadas[i]->TareaID==key)
			{
				return *(Realizadas[i]);
				 
				
			}
	}
	
	Tarea noMatch;
	noMatch.TareaID=-1;
	return noMatch;
}

void resultadoID(Tarea BuscaID){
	
	if (BuscaID.TareaID!=-1)
		{	
			puts("Tarea Encontrada!\n");
			printf("TareaID: %i\n",BuscaID.TareaID);

			printf("Duracion: %i\n",BuscaID.Duracion);
			printf("Descripcion: %s\n",BuscaID.Descripcion);

		}else{
			puts("Tarea NO Encontrada!\n");
		}
}

Tarea Buscapalabra(Tarea **Realizadas, int n){
	char palabra[tama];
	int i =0;

	puts("Ingrese la palabra que desea buscar");
	fflush(stdin);
	gets(palabra);
	fflush(stdin);

	
	while(Realizadas[i]!= NULL){
	

		if(strstr(Realizadas[i]->Descripcion, palabra)){
		        
		            return *(Realizadas[i]);
		    	}
		    	
		
		i++;
	}
		
	Tarea noMatch;
	noMatch.Descripcion = NULL;
	return noMatch;
}


void resultadoPalabra(Tarea BuscaID){
	
	if (BuscaID.Descripcion!=NULL)
		{	
			puts("Palabra encontrada!\n");
			printf("TareaID: %i\n",BuscaID.TareaID);
			printf("Duracion: %i\n",BuscaID.Duracion);
			printf("Descripcion: %s\n",BuscaID.Descripcion);

		}else{
			puts("Palabra no encontrada!\n");
		}
}