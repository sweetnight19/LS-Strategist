#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct{
	char dia[2];
	char mes[2];
	char any[4];
}Aniversari;

typedef struct{
	int  dorsal;
	char nom[26];
	Aniversari aniversari;
	char compost[2];
	int numParadas;
	int numVoltaParada[10];
}Pilot;

typedef struct{
	Pilot pilot[20];
	int numPilot;
	int numCarrera;
	int ID;
	char pluja;
	int numVoltes;
}Carrera;

int estrategiaDeNeumaticos(int *paradas,char compost[2]){
}

int codigoDeRadio(char radio[4],int *dorsal,int *numCarrera){
}

int comunicarseConElPiloto(Carrera carrera,char radio[4],int numCarrera,int ok2){
}

void simularCarrera(int ok1,int ok2,int ok3,Carrera carrera){
}

int menu(){
	int opcio;

	printf("Por favor, escoge una opción del menu:\n\n");
	printf("    1. Estraegia de neumáticos\n");
	printf("    2. Obtención del código de radio\n");
	printf("    3. Comunicarse con el piloto\n");
	printf("    4. Simular carrera\n");
	printf("    5. Salir\n\n");
	printf("Opción seleccionada: ");
	scanf("%d",&opcio);
	return opcio;
}

void main(){
	int opcio,paradas,ok1=0,ok2=0,ok3=0,dorsal,numCarrera;
	Carrera carrera;
	char compost[2],radio[4];

	printf("Bienvenido a LS Strategist!\n\n");
	do{
		opcio=menu();
		while(opcio<1||opcio>5){
			printf("ERROR: Los valores admitidos se encuentran entre el 1 y el 5\n");
			printf("Por favor, vuelva a introducir la opcion seleccionada: ");
			scanf("%d",&opcio);
		}
		switch(opcio){
			case 1:
				ok1=estrategiaDeNeumaticos(&paradas,compost);
				break;
			case 2:
				ok2=codigoDeRadio(radio,&dorsal,&numCarrera);
				break;
			case 3:
				ok3=comunicarseConElPiloto(carrera,radio,numCarrera,ok2);
				break;
			case 4:
				simularCarrera(ok1,ok2,ok3,carrera);
				break;
		} 
	}while(opcio!=5);
	printf("\nGracias por usar el programa!\n");
	printf("Suerte en la siguiente carrera\n");
}
