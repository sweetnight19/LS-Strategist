/*******************************
 *
 * @Proposito:LS-Strategist
 * @Autores: David Marquet, Joan Casals
 * @Fecha creacion: 14/12/2019
 * @Fecha última modificacion: 05/07/2020
 *
 ******************************/

//Librerias del sistema
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Constantes
#define TEXT 500
#define DIA 2
#define COMPOST 2
#define NOM 51
#define PARADAS 10
#define PILOTOS 20

//Tipos propios
typedef struct {
    char dia[DIA];
    char mes[DIA];
    char any[DIA * 2];
} Aniversari;

typedef struct {
    int dorsal;
    char nom[NOM];
    Aniversari aniversari;
    char compost[COMPOST];
    int numParadas;
    int numVoltaParada[PARADAS];
} Pilot;

typedef struct {
    Pilot pilot[PILOTOS];
    int numPilot;
    int numCarrera;
    int ID;
    char pluja;
    int numVoltes;
} Carrera;

typedef struct {
    int dorsal;
    int paradas;
    int numCarrera;
    char compost[2];
    char radio[5];
} Usuari;

/****************************
 *
 * @Finalidad: Selecionar el mejor compuesto segun condiciones de pista
 * @Parametros: Usuario *usuario = estructura pasada por referencia
 * @Retorno: Retorna un ok de que se ha realizado
 *
 ***************************/
int estrategiaDeNeumaticos(Usuari *usuari) {
    char pluja;
    int id, ipv, cx;

    printf("Asistente de estrategia de neumaticos:\n");
    do {
        printf("\nEsta lloviendo sobre la pista? (S/N): ");
        scanf("\n%c", &pluja);

        //Comprobació d'errors
        if (pluja != 'S' && pluja != 's' && pluja != 'N' && pluja != 'n') {
            printf("ERROR: Por favor, introduzca S/s o N/n\n");
        }
        //

    } while (pluja != 'S' && pluja != 's' && pluja != 'n' && pluja != 'N');
    do {
        printf("\nQue nivel de degradacion provoca la pista sobre el neumatico? (0-4): ");
        scanf("%d", &id);

        //Comprobació d'errors
        if (id < 0 || id > 4) {
            printf("ERROR: Por favor, introduzca un valor entre 0 y 4\n");
        }
        //

    } while (id < 0 || id > 4);
    do {
        printf("\nCuanto se quiere priorizar la velocidad del neumatico sobre la durabilidad? (1-5): ");
        scanf("%d", &ipv);

        //Comprobació d'erros
        if (ipv < 1 || ipv > 5) {
            printf("ERROR: Por favor, introduzca un valor entre 1 y 5\n");
        }
        //

    } while (ipv < 1 || ipv > 5);
    if (pluja == 'n' || pluja == 'N') {
        cx = abs(ipv - id);
        if (ipv < 3) {
            (*usuari).paradas = 1;
        } else {
            if (ipv == 3) {
                (*usuari).paradas = 2;
            } else {
                (*usuari).paradas = 3;
            }
        }
        if ((*usuari).paradas == 1) {
            (*usuari).compost[0] = 'C';
            (*usuari).compost[1] = cx + '0';
            printf("\nEl compuesto adecuado es el C%d y deberan realizarse %d parada a boxes.\n", cx,
                   (*usuari).paradas);
        } else {
            (*usuari).compost[0] = 'C';
            (*usuari).compost[1] = cx + '0';
            printf("\nEl compuesto adecuado es el C%d y deberan realizarse %d paradas a boxes.\n", cx,
                   (*usuari).paradas);
        }
    } else {
        cx = abs(ipv - id);
        if (ipv < 3) {
            (*usuari).paradas = 1;
        } else {
            if (ipv == 3) {
                (*usuari).paradas = 2;
            } else {
                (*usuari).paradas = 3;
            }
        }

        //Eleccio si son compost I o W
        if (cx >= 3) {
            (*usuari).compost[0] = 'I';
            printf("\nEl compuesto adecuado es el I y deberan realizarse %d paradas a boxes\n", (*usuari).paradas);
        } else {
            (*usuari).compost[0] = 'W';
            printf("\nEl compuesto adecuado es el W y deberan realizarse %d paradas a boxes\n", (*usuari).paradas);
        }
        //
    }
    printf("\n\n");
    return 1;
}

/****************************
 *
 * @Finalidad: Generar codigo de radio para el usuario
 * @Parametros: Usuario *usuario = estructura pasada por referencia
 * @Retorno: Retorna un ok de que se ha realizado
 *
 ***************************/

int codigoDeRadio(Usuari *usuari) {

    do {
        printf("Cual es el numero de dorsal del piloto con quien se quiere comunicar? ");
        scanf("%d", &(*usuari).dorsal);

        //Comprobació d'errors
        if ((*usuari).dorsal < 1 || (*usuari).dorsal > 99) {
            printf("\nERROR: Has introducido un valor invalido\n");
        }
        //

    } while ((*usuari).dorsal < 1 || (*usuari).dorsal > 99);
    do {
        printf("\nCual es el numero de la carrera en el calendario? ");
        scanf("%d", &(*usuari).numCarrera);

        //Comprobació d'errors
        if ((*usuari).numCarrera < 1 || (*usuari).numCarrera > 21) {
            printf("ERROR: Has introducido un valor invalido\n");
        }
        //

    } while ((*usuari).numCarrera < 1 || (*usuari).numCarrera > 21);

    (*usuari).radio[0] = (*usuari).dorsal % 26 + 'A' - 1;

    //Cas en que el residu sigui 0
    if ((*usuari).radio[0] == '@') {
        (*usuari).radio[0] = 'Z';
    }
    //

    //Control si es de es 2 o 3 digits el codi de radio
    if ((*usuari).dorsal / (*usuari).numCarrera < 10) {
        (*usuari).radio[1] = (*usuari).dorsal / (*usuari).numCarrera + '0';
        (*usuari).radio[2] = (*usuari).dorsal / 26 + '0';
        (*usuari).radio[3] = '\0';
    } else {
        (*usuari).radio[1] = ((*usuari).dorsal / (*usuari).numCarrera) / 10 + '0';
        (*usuari).radio[2] =
                ((*usuari).dorsal / (*usuari).numCarrera - (((*usuari).dorsal / (*usuari).numCarrera) / 10) * 10) + '0';
        (*usuari).radio[3] = (*usuari).dorsal / 26 + '0';
        (*usuari).radio[4] = '\0';
    }
    //

    printf("\nCODIGO GENERADO: %s\n", (*usuari).radio);
    return 1;
}

/****************************
 *
 * @Finalidad: Introducir informacion del campeonato y los pilotos
 * @Parametros: Carrera carrera = estructura que luego devolverá rellenada
 *              Usuario usario = Necesario para comparar el codigo de radio
 *              int ok2 = Comprobacion de que se ha generado el codigo de radio del piloto
 *              int *ok3 = Pasado por referencia para la verificacion de la siguiente fase
 * @Retorno: Retorna la estructura carrera con la informacion de todo el campeonato
 *
 ***************************/

Carrera comunicarseConElPiloto(Carrera carrera, Usuari usuari, int ok2, int *ok3) {
    int i = 0, pilot = 0, x = 0, any = 0, mes = 0, dia = 0;
    int error_fecha = 0, bisiesto = 0, error = 1; // error es posa a 1 si hi ha un error en la cadena
    int imensaje = 0;
    char radio[5], mensaje[TEXT];

    //Comprobació de si s'ha generat el codi o no
    if (ok2 == 0) {
        printf("ERROR: Aun no se ha generado ningun codigo de cifrado para la radio\n");
    }
        //
    else {
        do {
            printf("Introduzca el codigo de radio: ");
            scanf("\n%s", radio);

            //Comprobació si existeix el codi de radio o no
            if (strcmp(radio, "exit") != 0 && strcmp(radio, usuari.radio) != 0) {
                printf("ERROR: Este codigo de radio no existe\n");
            }
            //

        } while (strcmp(radio, "exit") != 0 && strcmp(radio, usuari.radio) != 0);

        //Si introdueix exit es retorna al menu principal
        if (strcmp(radio, "exit") == 0) {
            *ok3 = 0;
            return carrera;
        }
            //

        else {
            printf("Codigo valido!\n");
            printf("Comunicandose con el piloto #%d en la carrera #%d..\n\n", usuari.dorsal, usuari.numCarrera);
            fgets(mensaje, TEXT, stdin);
            while (error != 0) {
                error = 0;
                do {
                    printf("Introduzca la informacion: ");
                    fgets(mensaje, TEXT, stdin);
                    if (strcmp(mensaje, "exit\n") == 0) {
                        *ok3 = 0;
                        return carrera;
                    }
                } while (strcmp(mensaje, "exit\n") == 0);
                error = 0;
                /*--------------------------------------------------------------------
                            INICIALIZACIÓN DE VARIABLES INT A 0
                --------------------------------------------------------------------*/
                carrera.numCarrera = 0;
                carrera.ID = 0;
                carrera.numVoltes = 0;
                carrera.numPilot = 0;

                while (mensaje[i] != '\0' && error == 0) { //Extracción general del mensaje
                    error = 0;
                    carrera.numCarrera = 0;
                    while (mensaje[i] != '|' && error == 0) {
                        imensaje = mensaje[i] - '0';
                        carrera.numCarrera = carrera.numCarrera * 10 + imensaje;
                        i++;
                    }

                    if (!(carrera.numCarrera >= 1 && carrera.numCarrera <= 21)) {
                        //ok3 = 0;
                        error = 1;
                        printf("\nERROR: Numero de carrera incorrecto!\n");
                        //return carrera;
                    }

                    i++;

                    if (error == 0) {

                        //Fem un atoi per passar-ho a int
                        while (mensaje[i] != '|') {
                            carrera.ID = carrera.ID * 10 + mensaje[i] - '0';
                            i++;
                        }

                        //Comprobació d'error
                        if (carrera.ID < 0 || carrera.ID > 4) {
                            error = 1;
                            printf("\nERRPR: El Indice de Degradacion de la carrera es incorrecto!\n");
                            carrera.ID = 0;
                        }
                    }
                    i++;

                    if (error == 0) {
                        while (mensaje[i] != '|') {
                            carrera.pluja = mensaje[i];
                            i++;
                        }

                        //Comprobrem si el estat de pista es s/S o n/N
                        if (!(carrera.pluja == 's' || carrera.pluja == 'S' || carrera.pluja == 'n' ||
                              carrera.pluja == 'N')) {
                            //ok3 = 0;
                            error = 1;
                            printf("\nERROR: La lluvia no es correcta! (Introducir s/S o n/N)\n");
                            //return carrera;
                        }
                        //
                    }

                    i++;

                    if (error == 0) {
                        //Fem un atoi per tenir-ho a int
                        while (mensaje[i] != '|') {
                            carrera.numVoltes = carrera.numVoltes * 10 + (mensaje[i] - '0');
                            i++;
                        }

                        //Comprobació de si les voltes son correctes
                        if (carrera.numVoltes < 1 || carrera.numVoltes > 10) {
                            //ok3 = 0;
                            error = 1;
                            printf("\nERROR: El numero de vueltas indicada no es correcto!\n");
                            carrera.numVoltes = 0;
                        }
                    }

                    i++;

                    if (error == 0) {

                        //Fem un atoi per tenir-ho a int
                        while (mensaje[i] != '|') {
                            carrera.numPilot = carrera.numPilot * 10 + (mensaje[i] - '0');
                            i++;
                        }
                        //

                        //Revisem si el numero de pilots es correcte
                        if (carrera.numPilot < 2 || carrera.numPilot > 20) {
                            error = 1;
                            printf("\nERROR: El numero de pilotos no es correcto!\n");
                            carrera.numPilot = 0;
                        }
                        //
                    }

                    i++;
                    pilot = 0;
                    do {// Extracción de pilotos
                        while (mensaje[i] != '|' && mensaje[i] != '\0') {
                            carrera.pilot[pilot].dorsal = 0;
                            if (error == 0) {
                                while (mensaje[i] != '-') {
                                    carrera.pilot[pilot].dorsal = carrera.pilot[pilot].dorsal * 10 + (mensaje[i] - '0');
                                    i++;
                                }

                                //Revisem si el dorsal es correcte
                                if (carrera.pilot[pilot].dorsal < 1 || carrera.pilot[pilot].dorsal > 99) {
                                    error = 1;
                                    printf("\nERROR: El dorsal del piloto no es valido!\n");
                                    carrera.pilot[pilot].dorsal = 0;
                                }
                                //
                            }
                            i++;
                            x = 0;

                            if (error == 0) {
                                while (mensaje[i] != '-' && error == 0) {
                                    carrera.pilot[pilot].nom[x] = mensaje[i];
                                    i++;
                                    x++;
                                }
                                carrera.pilot[pilot].nom[x] = '\0';

                                //  Comprobrem si el nom del pilot es major a 25 caracters
                                if (strlen(carrera.pilot[pilot].nom) > 25) {
                                    error = 1;
                                    printf("\nERROR: El nombre del piloto no es correcto!\n");
                                }
                                //
                            }
                            i++;
                            x = 0;

                            //Lectura del dia-mes-any
                            while (mensaje[i] != '/' && error == 0) {
                                carrera.pilot[pilot].aniversari.dia[x] = mensaje[i];
                                i++;
                                x++;
                            }
                            i++;
                            carrera.pilot[pilot].aniversari.dia[x] = '\0';
                            x = 0;

                            while (x != strlen(carrera.pilot[pilot].aniversari.dia)) {
                                dia = dia * 10 + carrera.pilot[pilot].aniversari.dia[x] - '0';
                                x++;
                            }
                            x = 0;

                            while (mensaje[i] != '/' && error == 0) {
                                carrera.pilot[pilot].aniversari.mes[x] = mensaje[i];
                                i++;
                                x++;
                            }
                            i++;
                            carrera.pilot[pilot].aniversari.mes[x] = '\0';
                            x = 0;

                            while (x != strlen(carrera.pilot[pilot].aniversari.mes)) {
                                mes = mes * 10 + carrera.pilot[pilot].aniversari.mes[x] - '0';
                                x++;
                            }
                            x = 0;

                            while (mensaje[i] != '-' && error == 0) {
                                carrera.pilot[pilot].aniversari.any[x] = mensaje[i];
                                i++;
                                x++;
                            }
                            i++;
                            carrera.pilot[pilot].aniversari.any[x] = '\0';
                            x = 0;

                            while (x != strlen(carrera.pilot[pilot].aniversari.any)) {
                                any = any * 10 + carrera.pilot[pilot].aniversari.any[x] - '0';
                                x++;
                            }
                            x = 0;
                            //

                            //Comprobem si es un any bisiesto o no
                            if (mes == 02) {

                                if (any % 4 == 0) {
                                    if (any % 100 == 0.0) {
                                        if (any % 400 == 0.0) {
                                            bisiesto = 1;
                                        } else {
                                            bisiesto = 0;
                                        }
                                    } else {
                                        bisiesto = 1;
                                    }
                                } else {
                                    bisiesto = 0;
                                }

                                if (dia > 28) {

                                    if (bisiesto == 1) {
                                        if (dia == 29) {
                                            error_fecha = 0;
                                        } else {
                                            error_fecha = 1;
                                        }
                                    } else {
                                        error_fecha = 1;
                                    }
                                }
                            } else {
                                if (mes < 1 || mes > 12) {
                                    error_fecha = 1;
                                } else {
                                    if (dia < 1 || dia > 31) {
                                        error_fecha = 1;
                                    } else {
                                        error_fecha = 0;
                                    }
                                }
                            }
                            //

                            if (error == 0) {
                                if (error_fecha == 1) {
                                    error = 1;
                                    printf("\nERROR: Fecha introducida incorrecta!\n");
                                }
                            }

                            //Lectura del compost
                            while (mensaje[i] != '-' && error == 0) {
                                carrera.pilot[pilot].compost[x] = mensaje[i];
                                i++;
                                x++;
                            }
                            i++;
                            carrera.pilot[pilot].compost[x] = '\0';
                            x = 0;
                            carrera.pilot[pilot].numParadas = 0;

                            if (error == 0) {
                                //Fem un atoi mentre llegim el numero de parades
                                while (mensaje[i] != '-' && error == 0) {
                                    carrera.pilot[pilot].numParadas =
                                            carrera.pilot[pilot].numParadas * 10 + (mensaje[i] - '0');
                                    i++;
                                }

                                //Comprobem si esta correcte
                                if (carrera.pilot[pilot].numParadas < 1 || carrera.pilot[pilot].numParadas > 10) {
                                    //*ok3 = 0;
                                    error = 1;
                                    printf("\nERROR: Numero de paradas incorrecto!\n");
                                    //return carrera;
                                }
                            }

                            x = 0;
                            i++;

                            if (error == 0) {

                                //Fem un atoi mentre llegim el numero de parada en volta
                                while (mensaje[i] != '\0' && mensaje[i] != '|' && error == 0) {
                                    carrera.pilot[pilot].numVoltaParada[x] = 0;
                                    carrera.pilot[pilot].numVoltaParada[x] = mensaje[i] - '0';
                                    i++;

                                    if (mensaje[i] == '/') {
                                        i++;
                                        x++;
                                    }
                                }

                                //Comprobem que estigui tot correcte
                                if ((x + 1) != carrera.pilot[pilot].numParadas) {
                                    error = 1;
                                    printf("\nError: numero de paradas no coinciden\n");
                                }
                            }
                        }

                        if (mensaje[i] == '|') {
                            pilot++;
                            i++;
                            dia = 0;
                            mes = 0;
                            any = 0;
                        }
                    } while (mensaje[i] != '\0' && error == 0);

                    if (error ==
                        1) { //Si s'ha detectat un error, es demana tornar a introduir la informacio i es posa la variable "i" a 0 per començar desde l'inici de la cadena per asegurar que no sortim del while
                        printf("Informacion erronea;\nIntroduzca la informacion: ");
                        fgets(mensaje, TEXT, stdin);

                        i = 0;
                        error = 0;
                        if (strcmp(mensaje, "exit\n") == 0) {
                            return carrera;
                        }
                    }
                }
            }
            *ok3 = 1;
            printf("\nInformacion validada y enviada correctamente\n\n");
            return carrera;
        }
    }
}

/****************************
 *
 * @Finalidad: Realizar la carrera
 * @Parametros: int ok1 = Comprobacion de la primera fase realizada
 *              int ok2 = Comprobacion de la segona fase realizada
 *              int ok3 = Comprobacion de la tercera fase realizada
 *              Carrera carrera = Estructura necesaria con la informacion del gran premio
 *              Usuari usuari = Estructura con la informacion del usuario
 * @Retorno: No retorna nada
 *
 ***************************/

void simularCarrera(int ok1, int ok2, int ok3, Carrera carrera, Usuari usuari) {
    int i, j, a, b, c, d, e;
    float resultat[PILOTOS], posibilitats, max;

    //Els valors aleatoris necessaris a posterior serant diferent cada vegada degut a la funcio srand agafant com a unitat, el temps
    srand(time(NULL));

    //Comprobació d'errors
    if (ok1 == 0) {
        printf("ERROR: Aun no has configurado la estrategia de neumaticos\n\n");
    } else {
        if (ok2 == 0) {
            printf("ERROR: Aun no has generado el codigo de radio\n\n");
        } else {
            if (ok3 == 0) {
                printf("ERROR: Aun no has enviado ninguna informacion al piloto\n\n");
            }
                //

            else {
                printf("Simulando carrera..\n\n");
                printf("Resultados:\n\n");
                i = 0;
                d = carrera.numPilot;

                //Comprobem el compost per calcular el valor a de la formula comentada en el enunciat del projecte
                do {
                    if (usuari.compost[0] == 'I' && carrera.pilot[i].compost[0] != usuari.compost[0]) {
                        a = 1;
                    }
                    if (usuari.compost[0] == 'W' && carrera.pilot[i].compost[0] == 'C') {
                        a = 2;
                    }
                    if (usuari.compost[0] == 'W' && carrera.pilot[i].compost[0] == 'I') {
                        a = 1;
                    }
                    if (usuari.compost[0] == 'C' && carrera.pilot[i].compost[0] == 'C') {
                        if (usuari.compost[1] == carrera.pilot[i].compost[1]) {
                            a = 0;
                        } else {
                            a = abs(usuari.compost[1] - carrera.pilot[i].compost[1]);
                        }

                    }
                    b = usuari.paradas - carrera.pilot[i].numParadas;
                    c = i;
                    e = rand() % 8;

                    //apliquem la formula
                    posibilitats = 100 - sqrt(abs(pow(a, 2) + pow(b, 2))) -
                                   abs(cos(((c / d) * 100 * 2 / 3) + (1 / 3 * e)) * 40);
                    resultat[i] = posibilitats;
                    printf("%d. %s (%.2f)\n", i + 1, carrera.pilot[i].nom, posibilitats);
                    i++;
                } while (i < carrera.numPilot);

                i = 0;
                max = 0.0;
                //busquem el pilot amb el resultat mes elevat
                do {
                    if (resultat[i] > max) {
                        max = resultat[i];
                        j = i;
                    }
                    i++;
                } while (i < carrera.numPilot);
                printf("\n\n");
                printf("    |       |\n");
                printf("    |       |\n");
                printf("    |       |\n");
                printf("    |       |\n");
                printf("    |       |\n");
                printf("     |     |\n");
                printf("     |     |\n");
                printf("    |       |\n");
                printf("    |   #1  |\n");
                printf(" ---------------\n\n");
                printf("Enhorabuena %s!\n\n", carrera.pilot[j].nom);

            }
        }
    }
}

/****************************
 *
 * @Finalidad: Printar por pantalla las opciones disponibles
 * @Retorno: Retorna la opcion escogida por el usuario
 *
 ***************************/

int menu() {
    int opcio;

    //Generem el menu principal
    printf("Por favor, escoge una opcion del menu:\n\n");
    printf("\t1. Estraegia de neumaticos\n");
    printf("\t2. Obtencion del codigo de radio\n");
    printf("\t3. Comunicarse con el piloto\n");
    printf("\t4. Simular carrera\n");
    printf("\t5. Salir\n\n");
    printf("Opcion seleccionada: ");
    scanf("%d", &opcio);
    return opcio;
}

//Procedimiento principal
void main() {
    int opcio, ok1 = 0, ok2 = 0, ok3 = 0;
    Carrera carrera;
    Usuari usuari;

    printf("Bienvenido a LS Strategist!\n\n");
    do {
        opcio = menu();

        //Comprobació de la opció que sigui vàlida
        while (opcio < 1 || opcio > 5) {
            printf("ERROR: Los valores admitidos se encuentran entre el 1 y el 5\n");
            printf("Por favor, vuelva a introducir la opcion seleccionada: ");
            scanf("%d", &opcio);
        }

        switch (opcio) {
            case 1:
                //Cridem la fase 1 corresponent a la estrategia de neumatics
                ok1 = estrategiaDeNeumaticos(&usuari);
                break;
            case 2:
                //Cridem la fase 2 corresponent a la generar el codi de radio
                ok2 = codigoDeRadio(&usuari);
                break;
            case 3:
                //Cridem a la fase 3 corresponent a la comunicació amb el pilot
                carrera = comunicarseConElPiloto(carrera, usuari, ok2, &ok3);
                break;
            case 4:
                //Cridem a l'última fase corresponent a la simulació de la carrera
                simularCarrera(ok1, ok2, ok3, carrera, usuari);
                break;
        }
    } while (opcio != 5);
    printf("\nGracias por usar el programa!\n");
    printf("Suerte en la siguiente carrera\n");
}
