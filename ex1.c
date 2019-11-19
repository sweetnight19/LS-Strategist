#include <stdio.h>
#include <math.h>

int opcio,id,ipv,cx,boxes;
char pluja;

void main(){
	printf("Bienvenido a LS Strategist!\n\n");
	do{
		printf("Por favor, escoge una opción del menu:\n\n");
		printf("    1. Estrategia de neumáticos.\n");
		printf("    2. Obtención del codigo de radio.\n");
		printf("    3. Comunicarse con el piloto.\n");
		printf("    4. Simular carrera.\n");
		printf("    5. Salir.\n");
		printf("\nOpcion seleccionada: ");
		scanf("%d",&opcio);
		while(opcio<1||opcio>5){
			printf("ERROR: Los valores admitidos se encuentran entre el 1 y el 5.\n");
		printf("Por favor, vuelva a introducir la opcion seleccionada: ");
		scanf("%d",&opcio);
		}
		switch (opcio){
			case 1:
				printf("Asistente de estrategia de neumaticos:\n");
				do{
					printf("\nEsta lloviendo sobre la pista? (S/N): ");
					scanf("\n%c",&pluja);
					if(pluja!='S'&&pluja!='s'&&pluja!='N'&&pluja!='n'){
						printf("ERROR: Por favor, introduzca S/s o N/n\n");
					}
				}while(pluja!='S'&&pluja!='s'&&pluja!='n'&&pluja!='N');
				do{
					printf("\nQue nivel de degradacion provoca la pista sobre el neumatico? (0-4): ");
					scanf("%d",&id);
					if(id<0||id>4){
						printf("ERROR: Por favor, introduzca un valor entre 0 y 4\n");
					}
				}while(id<0||id>4);
				do{
					printf("\nCuanto se quiere priorizar la velocidad del neumatico sobre la durabilidad? (1-5): ");
					scanf("%d",&ipv);
					if(ipv<1||ipv>5){
						printf("ERROR: Por favor, introduzca un valor entre 1 y 5\n");
					}
				}while(ipv<1||ipv>5);
				if(pluja=='n'||pluja=='N'){
					cx=abs(ipv-id);
					if(ipv<3){
						boxes=1;
					}else{
						if(ipv==3){
							boxes=2;
						}else{
							boxes=3;
						}
					}
				if(boxes==1){
					printf("\nEl compuesto adecuado es el C%d y deberan realizarse %d parada a boxes.\n",cx,boxes);
				}else{
					printf("\nEl compuesto adecuado es el C%d y deberan realizarse %d paradas a boxes.\n",cx,boxes);
				}
				}else{
					cx=abs(ipv-id);
					if(ipv<3){
						boxes=1;
					}else{
						if(ipv==3){
							boxes=2;
						}else{
							boxes=3;
						}
					}
					if(cx>=3){
						printf("\nEl compuesto adecuado es el I y deberan realizarse %d paradas a boxes\n",boxes);
					}else{
						printf("\nEl compuesto adecuado es el W y deberan realizarse %d paradas a boxes\n",boxes);
					}
				}
				printf("\n\n");
				break;
			case 2:
				printf("\nCual es el numero de dorsal del piloto con quien se quiere comunicar? ");
				scanf("%d", &dorsal);

				while (dorsal < 1 || dorsal > 99) //dorsal incorrecto
				{
					printf("\nERROR: Has introducido un valor inválido.\n");
					printf("\nCual es el número de dorsal del piloto con quien se quiere comunicar? ");
					scanf("%d", &dorsal);
				}

				printf("\nCual es el número de la carrera en el calendario?");
				scanf("%d", &carrera);

				while (carrera < 1 || carrera > 21) //num carrera incorrecto
				{
					printf("\nERROR: Has introducido un valor inválido.\n");
					printf("\nCual es el número de la carrera en el calendario? ");
					scanf("%d", &carrera);
				}

				digit_1 = dorsal / carrera;
				digit_2 = dorsal / ABECEDARIO;
				lletra = dorsal % ABECEDARIO + 'A' - 1; // Guardar la letra del abecedario correspondiente, se resta 1 para que no se pase una posición

				printf("\nCODIGO GENERADO: %c%d%d\n", lletra, digit_1, digit_2);
				break;
			case 3:
				break;
			case 4:
				break;

		}
	} while(opcio!=5);
	printf("\nGracias por usar el programa!\n");
	printf("Suerte en la siguiente carrera.\n");
}
