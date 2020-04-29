#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define tama 100

typedef struct {
	int TareaID; //Numerado en ciclo iterativo
	char *Descripcion; //
	int Duracion; // entre 10 – 100
}Tarea; 

void cargar(Tarea *Pendientes, int n);
void realizadas(Tarea *Pendientes, Tarea *Realizadas, int n);
void mostrarRealizadas(Tarea *Realizadas,int n);
void mostar(Tarea R);

int main()
{	int n;
	
	srand(time(NULL));

	puts("Cantidad de tareas a cargar");
	scanf("%i",&n);
	fflush(stdin);
	Tarea *TareasPendientes=(Tarea*)malloc(sizeof(Tarea)* n); 
	Tarea *TareasRealizadas=(Tarea*)malloc(sizeof(Tarea)* n); 

	cargar(TareasPendientes,n);
	realizadas(TareasPendientes, TareasRealizadas, n);
	mostrarRealizadas(TareasRealizadas, n);
	getchar();
	return 0;
}

void cargar(Tarea *Pendientes, int n){


	for (int i = 0; i < n; i++)
	{
		Pendientes[i].TareaID=i+1;
		printf("TareaID:%i\n",i+1);
		puts("Ingrese Descripcion de tarea:");
		fflush(stdin);
		char desc[tama];
		gets(desc);	
		
		Pendientes[i].Descripcion=(char *)malloc(strlen(desc) * sizeof(char) );
		strcpy(Pendientes[i].Descripcion,desc);
		Pendientes[i].Duracion= rand () % 91 + 10;

	}
}

void realizadas(Tarea *Pendientes, Tarea *Realizadas, int n){

	int key=10;
	int j ;

	for (j = 0 ; j < n; j++){

		printf("Valor de n %i \n",n );
		printf("Valor de j %i \n",j );
		printf("TareaID: %i \n",Pendientes->TareaID);
		printf("Duracion: %i \n",Pendientes->Duracion);
		printf("Descripcion: %s \n",Pendientes->Descripcion);
		
		while(key!=0 && key!=1){

			puts("Se realizo dicha tarea?(si = 1/ no = 0)");
			fflush(stdin);
			scanf("%i",&key);
		}
		
		if (key==0)
		{
			Pendientes->TareaID = 0; 			
		}	
		

		key=10;
		*Realizadas = *Pendientes;
		Realizadas++; Pendientes++; 
	}

printf("TAMA de Realizadas %i\n",sizeof(Realizadas) );
}

void mostrarRealizadas(Tarea *Realizadas,int n){
	
	puts("Tareas realizadas:\n");

	for (int i = 0; i < n; i++)
	{
		if (Realizadas[i].TareaID != 0)
			{				
				printf("TareaID: %i\n",Realizadas[i].TareaID);
				printf("Duracion: %i\n",Realizadas[i].Duracion);
				printf("Descripcion: %s\n",Realizadas[i].Descripcion);
			}	
	}

}

