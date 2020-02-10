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

typedef struct {
    int dorsal;
    int paradas;
    int numCarrera;
    char compost[2];
    char radio[5];
}Usuari;

int estrategiaDeNeumaticos(Usuari *usuari){
    char pluja;
    int id,ipv,cx;

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
            (*usuari).paradas=1;
		}else{
		    if(ipv==3){
                (*usuari).paradas=2;
			}else{
                (*usuari).paradas=3;
			}
		}
		if((*usuari).paradas==1){
            (*usuari).compost[0]='C';
            (*usuari).compost[1]=cx+'0';
		    printf("\nEl compuesto adecuado es el C%d y deberan realizarse %d parada a boxes.\n",cx,(*usuari).paradas);
		}else{
            (*usuari).compost[0]='C';
            (*usuari).compost[1]=cx+'0';
			printf("\nEl compuesto adecuado es el C%d y deberan realizarse %d paradas a boxes.\n",cx,(*usuari).paradas);
		}
	}else{
	    cx=abs(ipv-id);
		if(ipv<3){
            (*usuari).paradas=1;
		}else{
			if(ipv==3){
                (*usuari).paradas=2;
			}else{
                (*usuari).paradas=3;
			}
		}
		if(cx>=3){
            (*usuari).compost[0]='I';
			printf("\nEl compuesto adecuado es el I y deberan realizarse %d paradas a boxes\n",(*usuari).paradas);
		}else{
            (*usuari).compost[0]='W';
			printf("\nEl compuesto adecuado es el W y deberan realizarse %d paradas a boxes\n",(*usuari).paradas);
		}
	}
	printf("\n\n");
    return 1;
}

int codigoDeRadio(Usuari *usuari){

    do{
        printf("Cual es el numero de dorsal del piloto con quien se quiere comunicar? ");
        scanf("%d",&(*usuari).dorsal);
        if ((*usuari).dorsal<1||(*usuari).dorsal>99){
            printf("\nERROR: Has introducido un valor invalido\n");
        }
    }while((*usuari).dorsal<1||(*usuari).dorsal>99);
    do{
        printf("\nCual es el numero de la carrera en el calendario? ");
        scanf("%d",&(*usuari).numCarrera);
        if((*usuari).numCarrera<1||(*usuari).numCarrera>21){
            printf("ERROR: Has introducido un valor invalido\n");
        }
    }while((*usuari).numCarrera<1||(*usuari).numCarrera>21);

    (*usuari).radio[0]=(*usuari).dorsal%26+'A'-1;
    if((*usuari).dorsal/(*usuari).numCarrera<10){
        (*usuari).radio[1]=(*usuari).dorsal/(*usuari).numCarrera+'0';
        (*usuari).radio[2]=(*usuari).dorsal/26+'0';
        (*usuari).radio[3]='\0';
    } else{
        (*usuari).radio[1]=((*usuari).dorsal/(*usuari).numCarrera)/10+'0';
        (*usuari).radio[2]=((*usuari).dorsal/(*usuari).numCarrera-(((*usuari).dorsal/(*usuari).numCarrera)/10)*10)+'0';
        (*usuari).radio[3]=(*usuari).dorsal/26+'0';
        (*usuari).radio[42
        ]='\0';
    }
    printf("\nCODIGO GENERADO: %s\n",(*usuari).radio);
    return 1;
}

int comunicarseConElPiloto(Carrera carrera,Usuari usuari,int ok2){
    char radio[5];

    if(ok2==0){
        printf("ERROR: Aun no se ha generado ningun codigo de cifrado para la radio\n");
    }else {
        do {
            printf("Introudzca el codigo de radio: ");
            scanf("\n%s", &radio);
            if (strcmp(radio,"exit")!=0 && strcmp(radio, usuari.radio) != 0) {
                printf("ERROR: Este codigo de radio no existe\n");
            }
         }while(strcmp(radio,"exit")!=0&&strcmp(radio,usuari.radio)!=0);
        if(strcmp(radio,"exit")==0){
            return 0;
        }else{
            printf("Codigo valido!\n");
            printf("Comunicandose con el piloto #%d en la carrera #%d..\n\n",usuari.dorsal,usuari.numCarrera);
            //CODIGO
            printf("Introduzca la informacion: ");
            fgets (mensaje, TEXT, stdin);
            fgets (mensaje, TEXT, stdin);

    /*--------------------------------------------------------------------
                INICIALIZACIÓN DE VARIABLES INT A 0
    --------------------------------------------------------------------*/
            carrera.numCarrera = 0;
            carrera.ID = 0;
            carrera.numVoltes = 0;
            carrera.numPilot = 0;

    /* -----------------------------------------------
                EXTRAER EL MENSAJE
    ------------------------------------------------*/

            do { //Extracción general del mensaje

                /*-----------------------------------------------------------------------------
                                        DEBUG
                            -----------------------------------------------------------------------------*/
                printf("\n\tExtraccion mensaje\n");
                carrera.numCarrera = 0;
                while (mensaje[i] != '|') {
                    imensaje = mensaje[i] - '0';
                    carrera.numCarrera = carrera.numCarrera * 10 + imensaje;
                    i++;
                    printf("\nNumero Carrera: %d", carrera.numCarrera);
                }

                i++;
    //------------------------------------------------------------------------------------------------------------------
                printf("\n\tDespues numero carrera");

                while (mensaje[i] != '|') {
                    carrera.ID = mensaje[i] - '0';
                    i++;
                    
                }

    //------------------------------------------------------------------------------------------------------------------
                printf("\nCarrera ID: %d", carrera.ID);

                i++;
    //------------------------------------------------------------------------------------------------------------------
                printf("\n\tDespues Indice Degradacion\n");
                while (mensaje[i] != '|') {
                    carrera.pluja = mensaje[i];
                    i++;
                    printf("\nLluvia: %c", carrera.pluja);
                }

                i++;
    //------------------------------------------------------------------------------------------------------------------
                printf("\n\tDespues lluvia\n");
                while (mensaje[i] != '|') {
                    carrera.numVoltes = carrera.numVoltes * 10 + (mensaje[i] -'0');
                    i++;
                }
    //------------------------------------------------------------------------------------------------------------------
                printf("\nNumero vueltas Carrera: %d", carrera.numVoltes);

                i++;
    //------------------------------------------------------------------------------------------------------------------
                printf("\n\tDespues numero vueltas\n");
                while (mensaje[i] != '|')
                {
                    carrera.numPilot = carrera.numPilot * 10 + (mensaje[i] - '0');
                    i++;
                }

    //------------------------------------------------------------------------------------------------------------------
                printf("\nNum pilots: %d", carrera.numPilot);

    //------------------------------------------------------------------------------------------------------------------
                printf("\n\tDespues Numero pilotos\n");

                i++;

                do {// Extracción de pilotos
                    while (mensaje[i] != '|' && mensaje[i] != '\0') {
                        
                        carrera.pilot[pilot].dorsal = 0;
                        while (mensaje[i] != '-') {
                            carrera.pilot[pilot].dorsal = carrera.pilot[pilot].dorsal * 10 + (mensaje[i] - '0');
                            i++;
                        }

                        i++;
    //------------------------------------------------------------------------------------------------------------------
                        printf("\nDorsal pilot: %d", carrera.pilot[pilot].dorsal);

                        while (mensaje[i] != '-') {
                            carrera.pilot[pilot].nom[x] = mensaje[i];
                            i++;
                            x++;
                        }

                        i++;
                        carrera.pilot[pilot].nom[x] = '\0';
                        x = 0;

                        /*-----------------------------------------------------------------------------
                                        DEBUG
                            -----------------------------------------------------------------------------*/
                        printf("\n\tNombre piloto: %s\n", carrera.pilot[pilot].nom);

                        while (mensaje[i] != '/') {
                            carrera.pilot[pilot].aniversari.dia[x] = mensaje[i];
                            i++;
                            x++;
                        }

                        i++;
                        carrera.pilot[pilot].aniversari.dia[x] = '\0';
                        x = 0;

                        printf ("\n\tDia aniversario piloto: %s\n", carrera.pilot[pilot].aniversari.dia);

                        while (mensaje[i] != '/') {
                            carrera.pilot[pilot].aniversari.mes[x] = mensaje[i];
                            i++;
                            x++;
                        }

                        i++;
                        carrera.pilot[pilot].aniversari.mes[x] = '\0';
                        x = 0;

                        printf ("\n\tMes aniversario piloto: %s\n", carrera.pilot[pilot].aniversari.mes);

                        while (mensaje[i] != '-') {
                            carrera.pilot[pilot].aniversari.any[x] = mensaje[i];
                            i++;
                            x++;
                        }

                        i++;
                        carrera.pilot[pilot].aniversari.any[x] = '\0';
                        x = 0;

                        printf ("\n\tAño aniversario piloto: %s\n", carrera.pilot[pilot].aniversari.any);

                        /*-----------------------------------------------------------------------------
                                    DEBUG
                        -----------------------------------------------------------------------------*/
                        printf("\n\tAntes comprobación fecha\n");

                        if (carrera.pilot[pilot].aniversari.mes == 02) {
                            if (carrera.pilot[pilot].aniversari.dia > 01 && carrera.pilot[pilot].aniversari.dia < 28) {
                                error = 0;
                            }else{
                                /*-----------------------------------------------------------------------
                                            MIRAR AÑO BISIESTO
                                -----------------------------------------------------------------------*/
                            }
                        }

                        while (mensaje[i] != '-') {
                            carrera.pilot[pilot].compost[x] = mensaje[i];
                            i++;
                            x++;
                        }

                        i++;
                        carrera.pilot[pilot].compost[x] = '\0';
                        x = 0;

    //--------------------------------------------------------------------------------------------------------------
                        printf ("\n\tCompost: %s\n", carrera.pilot[pilot].compost);

                        carrera.pilot[pilot].numParadas = 0;

                        while (mensaje[i] != '-') {
                            carrera.pilot[pilot].numParadas = carrera.pilot[pilot].numParadas * 10 + (mensaje[i] - '0');
                            i++;
                        }

    //--------------------------------------------------------------------------------------------------------------
                        printf ("\n\tNumero de parades: %d", carrera.pilot[pilot].numParadas);
                        if (carrera.pilot[pilot].numParadas < 1 || carrera.pilot[pilot].numParadas > 10) {
                            error = 1;
                        }

                        while (mensaje[i] != '/' && mensaje[i] != '\0' && mensaje[i]!= '|') {
                            carrera.pilot[pilot].numVoltaParada[x] = 0;
                            carrera.pilot[pilot].numVoltaParada[x] = carrera.pilot[pilot].numVoltaParada[x] * 10 + (mensaje[i] - '0');
                            i++;
                            x++;

    //--------------------------------------------------------------------------------------------------------------
                            printf ("\n\tNum Volta Parada %d: %d", x, carrera.pilot[pilot].numVoltaParada);
                        }
                    }

                    if (mensaje[i] == '|') {
                        pilot++;
                        /*-----------------------------------------------------------------------------
                                        DEBUG
                        -----------------------------------------------------------------------------*/
                        printf("\n\tPiloto++");
                    }
                } while (mensaje[i] != '\0');
                
            } while (mensaje[i] != '\0');
            return 1;
        }
    }
}

void simularCarrera(int ok1,int ok2,int ok3,Carrera carrera){

    if(ok1==0){
        printf("ERROR: Aun no has configurado la estrategia de neumaticos\n\n");
    }else{
        if(ok2==0){
            printf("ERROR: Aun no has generado el codigo de radio\n\n");
        }else{
            if(ok3==0){
                printf("ERROR: Aun no has enviado ninguna informacion al piloto\n\n");
            }else{
                printf("Simulando carrera..\n\n");
                printf("Resultados:\n\n");
                //CODIGO
            }
        }
    }
}

int menu(){
	int opcio;

	printf("Por favor, escoge una opcion del menu:\n\n");
	printf("\t1. Estraegia de neumaticos\n");
	printf("\t2. Obtencion del codigo de radio\n");
	printf("\t3. Comunicarse con el piloto\n");
	printf("\t4. Simular carrera\n");
	printf("\t5. Salir\n\n");
	printf("Opcion seleccionada: ");
	scanf("%d",&opcio);
	return opcio;
}

void main(){
	int opcio,ok1=0,ok2=0,ok3=0;
	Carrera carrera;
	Usuari usuari;

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
				ok1=estrategiaDeNeumaticos(&usuari);
				break;
			case 2:
				ok2=codigoDeRadio(&usuari);
				break;
			case 3:
				ok3=comunicarseConElPiloto(carrera,usuari,ok2);
				break;
			case 4:
				simularCarrera(ok1,ok2,ok3,carrera);
				break;
		}
	}while(opcio!=5);
	printf("\nGracias por usar el programa!\n");
	printf("Suerte en la siguiente carrera\n");
}
