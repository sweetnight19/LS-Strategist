#include <stdio.h>
#include <math.h>
#include <string.h>

#define ABECEDARIO 26
#define MAX 100000
#define NOMBRE 25

int i = 0, x = 0, y = 0, z = 0;
int opcio,id,ipv,cx,boxes, dorsal, carrera, idigit_1, idigit_2, generado = 0, numVueltas, numPilotos, numCarrera = 0, dia, mes, año, numDorsal, numParadas, error = 0;
char pluja, lletra, c_radio[3], c_radio2[6], digit_1, digit_2;
char informacion[MAX], piloto[MAX], nombrePiloto[NOMBRE], tipo_compuesto;

typedef struct {
	int dia;
	int mes;
	int any;
}Aniversari;

typedef struct {
	Aniversari aniversari;
	int numDorsal;
	char nom[25];
	int	numParadas;
	char compost;
	int voltaParada[MAX];
}Pilot;

Pilot pilot[20];

void main(){
	printf("Bienvenido a LS Strategist!\n\n");
	do{
		printf("\nPor favor, escoge una opción del menu:\n\n");
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

				printf("\nCual es el número de la carrera en el calendario? ");
				scanf("%d", &carrera);

				while (carrera < 1 || carrera > 21) //num carrera incorrecto
				{
					printf("\nERROR: Has introducido un valor inválido.\n");
					printf("\nCual es el número de la carrera en el calendario? ");
					scanf("%d", &carrera);
				}

				idigit_1 = dorsal / carrera;
                digit_1 = idigit_1 + '0';
				idigit_2 = dorsal / ABECEDARIO;
                digit_2 = idigit_2 + '0';
				lletra = dorsal % ABECEDARIO + 'A' - 1; // Guardar la letra del abecedario correspondiente, se resta 1 para que no se pase una posición

                c_radio[0] = lletra;
                c_radio[1] = digit_1;
                c_radio[2] = digit_2;
				c_radio[3] = '\0';

				printf("\nCODIGO GENERADO: %s\n", c_radio);

                generado = 1;
				break;
			case 3:
                if(generado == 0) {
                    printf("\nERROR: Aun no se ha generado ningun codigo de cifrado para la radio.\n");
                }else{
                    printf("\nIntroduzca el codigo de radio: ");
                    scanf("%s", c_radio2);
                    
					if(strcmp(c_radio, c_radio2) == 0){
						printf("Codigo correcto.\n");
					}else{
						while (strcmp(c_radio, c_radio2) != 0) {
							printf("\nERROR: Este codigo de radio no existe.\n");
							printf("\nIntroduzca el codigo de radio: ");
							scanf("%s", c_radio2);
						}
					}

					printf("\nComunicandose con el piloto #%d en la carrera #%d...\n", dorsal, carrera);

					do {
							printf("\nIntroduzca la información: ");
						scanf("%s", informacion);

						if(strcmp(informacion, "exit") != 0) {
							while(informacion[i] != '\0') {
								i = getParam(i, informacion, numCarrera, '|');
								i = getParam(i, informacion, id, '|');
								i = getParam(i, informacion, pluja, '|');
								i = getParam(i, informacion, numVueltas, '|');
								i = getParam(i, informacion, numPilotos, '|');
								i = getParam(i, informacion, piloto, '|');
							}

							//se rellena la infomación de todos los pilotos que se han introducido en "informacion" que han sido guardados en "piloto"

							while(piloto[z] != '\0') { 
								z = getParam(z, piloto, pilot[y].numDorsal, '-');
								z = getParam(z, piloto, pilot[y].nom, '-');
								z = getParam(z, piloto, pilot[y].aniversari.dia, '/');
								z = getParam(z, piloto, pilot[y].aniversari.mes, '/');
								z = getParam(z, piloto, pilot[y].aniversari.any, '-');
								z = getParam(z, piloto, pilot[y].compost, '-');
								z = getParam(z, piloto, pilot[y].numParadas, '-');
								z = getParam(z, piloto, pilot[y].voltaParada[MAX], '/');
								y++;
							}

							x = y;
							y = 0;

							//control de errores

							//Comprobación  de los datos de la carrera

							//Joan: Propongo idear una función externa para optimizar el código y que no sea tan grande para reducir las redundancias de codigo

							if(numCarrera != carrera) {
								printf("\nERROR: El numero de la carrera es incorrecto!\n");
								error = 1;
							}else{
								if(numVueltas < 1 || numVueltas > 10) {
									printf("\nERROR: Numero de vueltas incorrecto!\n");
									error = 1;
								}else{
									if(numPilotos != y) {
										printf("\nERROR: Numero de pilotos incorrecto!\n");
										error = 1;
									}else{

										//Comprobación de los datos de los pilotos
										if(dorsal != pilot[y].numDorsal) {
											printf("\nERROR: El dorsal del piloto no son el mismo.\n");
											error = 1;
										}else{
											while(y != x || error == 1) {
												if(strlen(pilot[y].nom) > 25) {
													printf("\nERROR: El nombre es demasiado largo.\n");
													error = 1;
												}else{

													//Joan: preguntar cuales son los años que deberíamos comprobar (rollo jdesde el año 0 hasta el año 9999 o hacerlo con años "normales"; vigilar que no sean demasiado jóvenes o viejos)

													if(pilot[y].aniversari.mes < 1 || pilot[y].aniversari.mes > 12) {
														printf("\nERROR: La fecha de nacimiento del piloto %s es incorrecta!\n", pilot[y].nom);
														error = 1;
													}else{
														if(pilot[y].aniversari.mes == 2) {
															if(pilot[y].aniversari.dia < 1 || pilot[y].aniversari.dia > 28){
																printf("\nERROR: La fecha de nacimiento del piloto %s es incorrecta!\n", pilot[y].nom);
																error = 1;
															}
														}else{
															if(pilot[y].aniversari.dia < 1 || pilot[y].aniversari.dia > 30) {
																printf("\nERROR: La fecha de nacimiento del piloto %s es incorrecta!\n", pilot[y].nom);
																error = 1;
															}else{
																if(pilot[y].numParadas < 1 || pilot[y].numParadas > 10) {
																	printf("\nERROR: El número de paradas es incorrecto.\n");
																	error = 1;
																}else{
																	if(strlen(pilot[y].voltaParada) != numParadas) {
																		printf("\nERROR: El número de paradas y las paradas realizadas no coinciden!\n");
																		error = 1;
																	}
																}
															}
														}
													}

												y++;
												} //Joan: tengo dudas sobre si este '}' deberia ir aqui o antes del y++
											}
										}
									}
								}
							}

						printf("\nInformaciónn validada y enviada correctamente!\n");
						}else{
							printf("\nCancelando envio...\n");
						}
					} while(error != 1);
                }
				break;
			case 4:
				break;

		}
	} while(opcio!=5);
	printf("\nGracias por usar el programa!\n");
	printf("Suerte en la siguiente carrera.\n");
}

int getParam(int i, char info[MAX], char param[MAX], char delimitador)
{
	int j = 0;

	while (info[i] != delimitador)
	{
		param[j] = info[i];
		i++;
		j++;
	}
	i++;
	param[j] = '\0';
	return i;
}