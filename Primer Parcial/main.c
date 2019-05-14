#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

#define TAMMARCA 5
#define TAMCOLOR 5
#define TAMLAVADO 4
#define TAMAUTO  40
#define TAMTRABAJO 40
#define TAMCLIENTE 40

// ---------------  ESTRUCTURAS --------//
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int id;
    char descripcion[20];
} eMarca;

typedef struct
{
    int id;
    char descripcion[20];
} eColor;

typedef struct
{
    int id;
    int idCliente;
    char patente[7];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
} eAuto;

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
} eServicio;

typedef struct
{
    int id;
    char patente[7];
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;
} eCliente;


// ---------------  PROTOTITPOS --------//

int menu();
int menuModificarAuto();
int mostrarColores(eColor colores[], int tamColores);
int mostrarMarcas(eMarca marcas[], int tamMarca);
int mostrarServicios(eServicio lavado[], int tamServ);
int mostrarAutos(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);
int buscarPatente(eAuto autos[], int tam, char patente[]);
void mostrarAuto(eAuto autos, eMarca marcas, eColor colores);
void altaAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, int id, int flag);
int buscarMarca(eMarca marcas[], int tamMarca, int idMarca);
int buscarColor(eColor colores[], int tamColor, int idColor);
int isEmpty(eAuto autos[], int tamAuto);
void initAutos(eAuto autos[], int tamAuto);
void modificarModelo(eAuto autos[], int tamAuto);
void modificarColor(eAuto autos[], int tamAuto, eColor colores[], int tamColor);
void bajaAuto(eAuto autos[], int tamAuto, eMarca marcas[], eColor colores[]);
int isEmptyTrabajo(eTrabajo trabajos[], int tamTrabajo);
void altaTrabajo(eAuto autos[], int tamAuto, eTrabajo trabajos[], int tamTrabajo ,eServicio lavado[], int tamServ, int id);
void mostratTrabajo(eTrabajo trabajo, eAuto autos, eServicio lavados);
int mostrarTrabajos( eTrabajo trabajos[], int tamTrabajos, eAuto autos[], int tamAuto, eServicio lavado[], int tamServ);
void ordenarAutos(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);
void mostrarNegro(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

// ---------------  MAIN --------//
int main()
{
    char seguir = 's';
    char confirma;
    int id=1;
    int idTrabajo=1;
    int flag=1;

    eMarca marcas[TAMMARCA] =
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"},
    };


    eCliente clientes[TAMCLIENTE] =
    {
        {1, "Pablo", 'm'},
        {2, "Lucas", 'm'},
        {3, "Ricardo", 'm'},
        {4, "Ana", 'f'},
        {5, "Sofia", 'f'},
        {6, "Laura", 'f'},

    };

    eColor colores[TAMCOLOR] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"},
    };
    eServicio lavado[TAMLAVADO]=
    {
        {20000, "Lavado", 250},
        {20001, "Pulido", 300},
        {20002, "Encerado", 400},
        {20003, "Completo", 600}
    };


   eAuto autos[TAMAUTO]= {
       {1, "AAA201", 1000, 5001, 1995, 1},
       {2, "DFR234", 1003, 5000, 2002, 1},
       {3, "GFT564", 1002, 5003, 2007, 1},
       {4, "ACD321", 1002, 5003, 1995, 1},
       {5, "HTD656", 1004, 5002, 2008, 1},
       {6, "QSZ435", 1003, 5001, 1994, 1},
       {7, "LGX201", 1001, 5000, 2012, 1},
       {8, "SUZ324", 1001, 5002, 1991, 1},
       {9, "HCU762", 1000, 5003, 2008, 1},
       {10, "DYC735", 1003, 5001, 2002, 1},
       {11, "JJK879", 1003, 5001, 2010, 1},
       {12, "FED322", 1004, 5002, 2006, 1},
       {13, "GHV332", 1001, 5003, 2007, 1},
       {14, "BDE221", 1000, 5004, 1996, 1},
       {15, "OPD332", 1000, 5001, 2014, 1},
       {16, "PPD121", 1002, 5001, 2015, 1},
       {17, "IIT230", 1001, 5000, 2009, 1},
       {18, "KOD220", 1004, 5002, 2011, 1},
       {19, "QSZ305", 1004, 5002, 1993, 1},
       {20, "SSD128", 1002, 5003, 1992, 1},
       {21, "SSD240", 1003, 5004, 1992, 1},
       {22, "EDF213", 1001, 5000, 2001, 1},
   };

   eTrabajo trabajos[TAMTRABAJO] = {

       {1, "AAA201", 20000, {12,3,2019}, 1},
       {2, "DFR234", 20000, {2,4,2019}, 1},
       {3, "GFT564", 20001, {7,1,2019}, 1},
       {4, "ACD321", 20002, {9,11,2019}, 1},
       {5, "HTD656", 20003, {12,12,2019}, 1},
       {6, "QSZ435", 20001, {21,7,2019}, 1},
       {7, "LGX201", 20001, {29,8,2019}, 1},
       {8, "SUZ324", 20004, {31,5,2019}, 1},
       {9, "HCU762", 20004, {2,2,2019}, 1},
       {10, "DYC735", 20000, {18,2,2019}, 1},
       {11, "JJK879", 20001, {17,3,2019}, 1},
       {12, "AAA201", 20000, {17,4,2019}, 1},
       {13, "DFR234", 20000, {2,6,2019}, 1},
       {14, "GFT564", 20001, {7,3,2019}, 1},
       {15, "ACD321", 20002, {21,7,2019}, 1},
       {16, "HTD656", 20003, {11,9,2019}, 1},
       {17, "QSZ435", 20001, {3,7,2019}, 1},
       {18, "LGX201", 20001, {21,8,2019}, 1},
       {19, "SUZ324", 20004, {28,5,2019}, 1},
       {20, "HCU762", 20004, {2,8,2019}, 1},
       {21, "DYC735", 20000, {8,2,2019}, 1},
       {22, "JJK879", 20001, {17,3,2019}, 1},
       {23, "KOD220", 20003, {17,4,2019}, 1},
       {24, "QSZ305", 20000, {21,3,2019}, 1},
       {25, "SSD128", 20002, {16,4,2019}, 1},
       {26, "SSD240", 20000, {17,4,2019}, 1},
       {27, "EDF213", 20001, {23,3,2019}, 1},
       {28, "AAA201", 20000, {12,2,2019}, 1},
       {29, "DFR234", 20000, {2,3,2019}, 1},
       {30, "GFT564", 20001, {7,2,2019}, 1},
       {31, "ACD321", 20002, {9,12,2019}, 1},
       {32, "HTD656", 20003, {12,9,2019}, 1},
       {33, "QSZ435", 20001, {21,5,2019}, 1},
       {34, "HTD656", 20002, {12,2,2019}, 1},
       {35, "QSZ435", 20000, {21,1,2019}, 1},
   };

   do
    {
        switch(menu())
        {

        case 1:
               //ALTA AUTO
            altaAuto(autos, TAMAUTO, marcas, TAMMARCA, colores, TAMCOLOR, id, flag);
            id++;
            flag=1;

            system("pause");
            break;

        case 2:
            if(flag == 0){
                printf("\nDEBE REALIZAR EL ALTA DE UN AUTO PRIMERO\n");
            }
            else{
                 switch(menuModificarAuto()){
                    case 1:
                            //MODIFICAR COLOR
                            modificarColor(autos, TAMAUTO, colores, TAMCOLOR);
                      break;
                    case 2:
                            //MODIFICAR MODELO
                            modificarModelo(autos, TAMAUTO);
                      break;
                    default:
                        printf("OPCION INVALIDA");
                        system("break");
                }
            }

            system("pause");
            break;

        case 3:
                //BAJA AUTO
            if(flag == 0){
                printf("\nDEBE REALIZAR EL ALTA DE UN AUTO PRIMERO\n");
            }
            else{
                 bajaAuto(autos, TAMAUTO, marcas, colores);
            }

            system("pause");
            break;

        case 4:
                //LISTAR AUTOS
            if(flag == 0){
                printf("\nDEBE REALIZAR EL ALTA DE UN AUTO PRIMERO\n");
            }
            else{
                 mostrarAutos(autos, TAMAUTO, marcas, TAMMARCA, colores, TAMCOLOR);
            }
            system("pause");
            break;

        case 5:
                //LISTAR MARCAS
            mostrarMarcas(marcas, TAMMARCA);
            system("pause");
            break;

        case 6:
                //LISTAR COLORES
            mostrarColores(colores, TAMCOLOR);
            system("pause");
            break;
        case 7:
                //LISTAR SERVICIOS
            mostrarServicios(lavado, TAMLAVADO);
            system("pause");
            break;

        case 8:
                // ALTA TRABAJO
            if(flag == 0){
                printf("\nDEBE REALIZAR EL ALTA DE UN AUTO PRIMERO\n");
            }
            else{
                altaTrabajo(autos, TAMAUTO, trabajos, TAMTRABAJO, lavado, TAMLAVADO,  idTrabajo);
                idTrabajo++;
            }

            system("pause");
            break;

        case 9:
                // LISTAR TRABAJOS
             if(flag == 0){
                printf("\nDEBE REALIZAR EL ALTA DE UN AUTO PRIMERO\n");
            }
            else{
                 mostrarTrabajos(trabajos, TAMTRABAJO, autos, TAMAUTO, lavado, TAMLAVADO);
            }

            system("pause");
            break;
        case 10:
            mostrarNegro(autos, TAMAUTO, marcas, TAMMARCA, colores, TAMCOLOR);
            system("pause");
            break;

        case 11:
                // SALIE
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n OPCION INVALIDA\n\n");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}


int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM  ***\n\n");
    printf("1- Alta Auto\n");
    printf("2- Modificar Auto\n");
    printf("3- Baja Auto \n");
    printf("4- Listar Autos \n");
    printf("5- Listar Marcas\n");
    printf("6- Listar Colores\n");
    printf("7- Listar Servicios\n");
    printf("8- Alta Trabajo\n");
    printf("9- Listar Trabajos \n");
    printf("10- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuModificarAuto()
{
    int opcion;

    system("cls");
    printf("  *** Eliga que desea modificar  ***\n\n");
    printf("1- Color\n");
    printf("2- Modelo\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int buscarPatente(eAuto autos[], int tam, char patente[])
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(strcmp(autos[i].patente, patente) == 0 && autos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarMarca(eMarca marcas[], int tamMarca, int idMarca)
{
    int indice = -1;

    for(int i=0; i < tamMarca; i++)
    {
        if(marcas[i].id == idMarca)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarColor(eColor colores[], int tamColor, int idColor)
{
    int indice = -1;

    for(int i=0; i < tamColor; i++)
    {
        if(colores[i].id == idColor)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void altaAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, int id, int flag)
{
    char patente[7];
    int existe;
    int hayLugar;

         hayLugar = isEmpty(autos, tamAuto);

        if(hayLugar == -1){
            printf("No hay lugar");
        }else{

        printf("Ingrese patente: ");
        scanf("%s", patente);
        strupr(patente);

        existe = buscarPatente(autos, tamAuto, patente);

        if( existe != -1)
        {
            printf("YA EXISTE LA PATENTE EN EL SISTEMA\n");
        }
        else
        {
            mostrarMarcas(marcas, tamMarca);
            printf("Ingrese numero de marca: ");
            scanf("%d", &autos[hayLugar].idMarca);

            existe = buscarMarca(marcas, tamMarca, autos[hayLugar].idMarca);

            while(existe == -1){
                    printf("\nReingrese marca correcta: ");
                    scanf("%d", &autos[hayLugar].idMarca);

                    existe = buscarMarca(marcas, tamMarca, autos[hayLugar].idMarca);
            }

            mostrarColores(colores, tamColor);
            printf("\nIngrese numero de color: ");
            scanf("%d", &autos[hayLugar].idColor);

            existe = buscarColor(colores, tamColor, autos[hayLugar].idColor);

            while(existe == -1){
                    printf("\nNo Existe el color ingresado. Reingrese una vez mas: ");
                    scanf("%d", &autos[hayLugar].idColor);

                    existe = buscarColor(colores, tamColor, autos[hayLugar].idColor);
            }

            printf("\nIngrese Modelo del auto: ");
            scanf("%d", &autos[hayLugar].modelo);

            while(autos[hayLugar].modelo < 1886){
                printf("\n\nReingrese un Modelo que exista: ");
                scanf("%d", &autos[hayLugar].modelo);
            }

            autos[hayLugar].id = id;
            autos[hayLugar].isEmpty = 1;
            strcpy(autos[hayLugar].patente, patente);

             printf("\nALTA DE AUTO EXITOSA!!!\n\n");
        }
        }
}

void altaTrabajo(eAuto autos[], int tamAuto, eTrabajo trabajos[], int tamTrabajo ,eServicio lavado[], int tamServ, int id)
{
    char patente[7];
    int existe;
    int hayLugar;
    int dia;
    int mes;
    int anio;

        hayLugar = isEmptyTrabajo(trabajos, tamTrabajo);

        if(hayLugar == -1){
            printf("\nNo hay lugar");
        }else{
            printf("\nIngrese patente: ");
            scanf("%s", patente);
            strupr(patente);

            existe = buscarPatente(autos, tamAuto, patente);

            if( existe == -1)
            {
            printf("\nNO EXISTE AUTO CON LA PATENTE INGRESADA\n");
            }
            else{
                mostrarServicios(lavado, tamServ);
                printf("\nIngrese numero de servicio: ");
                scanf("%d", &trabajos[hayLugar].idServicio);
                while(trabajos[hayLugar].idServicio < 20000 || trabajos[hayLugar].idServicio > 20004){
                    printf("\nReingrese numero de servicio: ");
                    scanf("%d", &trabajos[hayLugar].idServicio);
                }

                printf("\nIngrese fecha de ingreso dd/mm/aaaa: ");
                scanf("%d/%d/%d", &dia, &mes, &anio);
                while(dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio != 2019){
                    printf("\nReingrese fecha de ingreso dd/mm/aaaa: ");
                    scanf("%d/%d/%d", &dia, &mes, &anio);
                }

                trabajos[hayLugar].fecha.dia = dia;
                trabajos[hayLugar].fecha.mes = mes;
                trabajos[hayLugar].fecha.anio = anio;
                trabajos[hayLugar].id = id;
                strcpy(trabajos[hayLugar].patente, patente);
                trabajos[hayLugar].isEmpty = 1;


                printf("\n ALTA DE TRABAJO EXITOSA!!!\n\n");
            }
        }
}
void modificarColor(eAuto autos[], int tamAuto, eColor colores[], int tamColor)
{
    char patente[7];
    char confirm;
    int nuevoColor;
    int existe;

    printf("\nIngrese Patente: ");
    scanf("%s", patente);

     existe = buscarPatente(autos, tamAuto, patente);

    if( existe == -1)
    {
        printf("\nLA PATENTE NO ESTA REGISTRADA EN EL SISTEMA\n");
    }
    else
    {

        printf("\nQuiere cambiar el Color? s/n:  ");
        fflush(stdin);
        confirm = tolower(getche());

        if(confirm == 's')
        {
            mostrarColores(colores, tamColor);
            printf("\n\nIngrese nuevo Color: ");
            scanf("%d", &nuevoColor);

            while(nuevoColor > 5004 || nuevoColor < 5000){
                printf("\nReingrese Color: ");
                scanf("%d", &nuevoColor);
            }

            autos[existe].idColor = nuevoColor;
            printf("\nSE MODIFICO COLOR CON EXITO");
        }
        else
        {
            printf("\n\nNO SE AH MODIFICADO EL COLOR\n\n");
        }
    }
}

void modificarModelo(eAuto autos[], int tamAuto)
{
    char patente[7];
    char confirm;
    int nuevoModelo;
    int existe;

    printf("\nIngrese Patente: ");
    scanf("%s", patente);

     existe = buscarPatente(autos, tamAuto, patente);

    if( existe == -1)
    {
        printf("\nLA PATENTE NO ESTA REGISTRADA EN EL SISTEMA\n");
    }
    else
    {

        printf("\nQuiere cambiar el Modelo? s/n:  ");
        fflush(stdin);
        confirm = tolower(getche());

        if(confirm == 's')
        {
            printf("\n\nIngrese nuevo Modelo: ");
            scanf("%d", &nuevoModelo);

            while(nuevoModelo < 1886){
                printf("\n\nReingrese un Modelo que exista: ");
                scanf("%d", &nuevoModelo);
            }

            autos[existe].modelo = nuevoModelo;

            printf("\nSE MODIFICO EL MODELO EXITOSAMENTE.\n");
        }
        else
        {
            printf("\n\nNO SE MODIFICO EL MODELO\n\n");
        }
    }
}

void mostrarAuto(eAuto autos, eMarca marcas, eColor colores, eCliente clientes){

    printf("%9s     %5d     %7s    %6s    %2d  %d  %s   %c\n", marcas.descripcion, autos.modelo, colores.descripcion, autos.patente, autos.id clientes.id, clientes.nombre, clientes.sexo);
}

int mostrarAutos(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor){
    int contador = 0;

    system("cls");

     printf("   MARCA      MODELO     COLOR    PATENTE     ID        ID CLIENTE    NOMBRE     SEXO\n");
     printf("  -------    --------   -------  ---------   ----       ----------   --------   -------\n");

    for(int i=0; i < tamAuto; i++)
    {
        for(int j=0; j < tamMarca; j++){
               if(autos[i].idMarca == marcas[j].id && autos[i].isEmpty == 1){
                    for(int k=0; k<tamColor; k++){
                        if(autos[i].idColor == colores[k].id){
                                mostrarAuto(autos[i], marcas[j], colores[k]);
                            contador++;
                        }
                    }
                }
        }
    }
    printf("\n");

    if( contador == 0)
    {
        printf("\nNO HAY AUTOS QUE MOSTRAR\n");
    }
    return 0;
}


int mostrarMarcas(eMarca marcas[], int tamMarca){
    int contador = 0;

    printf("\n      Marcas      \n");
    printf("     --------      \n");

    for(int i=0; i < tamMarca; i++)
    {
        printf("%d- %s\n", marcas[i].id, marcas[i].descripcion);
            contador++;
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNO HAY MARCAS QUE MOSTRAR\n");
    }
    return 0;
}


int mostrarColores(eColor colores[], int tamColores){
    int contador = 0;

    printf("\n\n      Colores      \n");
    printf("     ---------      \n");

    for(int i=0; i < tamColores; i++)
    {
        printf("%4d- %s\n", colores[i].id, colores[i].descripcion);
            contador++;
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNO HAY COLORES QUE MOSTRAR\n");
    }
    return 0;
}



int mostrarServicios(eServicio lavado[], int tamServ){
    int contador = 0;

    printf("\n     Servicio        Precio \n");
    printf("     ----------      ---------\n");

    for(int i=0; i < tamServ; i++)
    {
        printf("%d- %8s        $ %d\n", lavado[i].id, lavado[i].descripcion, lavado[i].precio);
            contador++;
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNO HAY SERVICIOS QUE MOSTRAR\n");
    }
    return 0;
}

void mostratTrabajo(eTrabajo trabajo, eAuto autos, eServicio lavado)
{
    if(trabajo.isEmpty == 1 && autos.isEmpty == 1){
        printf("%5d     %5s     %8s    $%5d        %d/%d/%d\n", trabajo.id, trabajo.patente, lavado.descripcion, lavado.precio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
    }

}


int mostrarTrabajos( eTrabajo trabajos[], int tamTrabajos, eAuto autos[], int tamAuto, eServicio lavado[], int tamServ)
{
    int contador = 0;

    system("cls");

     printf("   ID      PATENTE     TRABAJO    PRECIO         FECHA\n");
     printf("  ----    ---------   ---------  ---------     ----------\n");

    for(int i=0; i < tamAuto; i++)
    {
        for(int j=0; j < tamTrabajos; j++){
               if(strcmp(trabajos[j].patente, autos[i].patente) == 0){
                    for(int k=0; k < tamServ; k++){
                        if(trabajos[j].idServicio == lavado[k].id){
                            mostratTrabajo(trabajos[j], autos[i], lavado[k]);
                            contador++;
                        }
                    }
                }
        }
    }
    printf("\n");

    if( contador == 0)
    {
        printf("\nNO HAY TRABAJOS QUE MOSTRAR\n");
    }
    return 0;
}

int isEmpty(eAuto autos[], int tamAuto)
{
    int indice = -1;

    for(int i=0; i<tamAuto; i++){
        if(autos[i].isEmpty == 0){
            indice = i;
            break;
        }
    }
    return indice;
}

int isEmptyTrabajo(eTrabajo trabajos[], int tamTrabajo)
{
    int indice = -1;

    for(int i=0; i<tamTrabajo; i++){
        if(trabajos[i].isEmpty == 0){
            indice = i;
            break;
        }
    }
    return indice;
}

void initAutos(eAuto autos[], int tamAuto){
    for(int i=0; i<tamAuto; i++){
        autos[i].isEmpty = 0;
    }
}

void bajaAuto(eAuto autos[], int tamAuto, eMarca marca[], eColor color[])
{
    char patente[7];
    char confirm;
    int esta;

    printf("\nIngrese patente: ");
    scanf("%s", patente);

    esta = buscarPatente(autos, tamAuto, patente);

    if( esta == -1)
    {
        printf("\nLA PATENTE NO ESTA REGISTRADA EN EL SISTEMA\n");
    }
    else
    {
        mostrarAuto(autos[esta], marca[esta], color[esta]);

        printf("\nConfirma la eliminacion? s/n");
        fflush(stdin);
        confirm = tolower(getche());

        if(confirm == 's')
        {
            autos[esta].isEmpty = 0;
            printf("\nSE ELIMINO CORRECTAMENTE\n");
        }
        else
        {
            printf("\nLA ELIMINACION HA SIDO CANCELADA\n");
        }
    }
}


void mostrarNegro(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int contador = 0;
    int existe;
    int id;

            mostrarColores(colores, tamColor);
            printf("\nIngrese numero de color: ");
            scanf("%d", &id);

            existe = buscarColor(colores, tamColor, id);

            while(existe == -1){
                    printf("\nNo Existe el color ingresado. Reingrese una vez mas: ");
                    scanf("%d", &id);

                    existe = buscarColor(colores, tamColor, id);
            }

            printf("   MARCA      MODELO     COLOR    PATENTE     ID\n");
            printf("  -------    --------   -------  ---------   ----\n");


            for(int i=0; i < tamAuto; i++){
                    if(autos[i].idColor == id && autos[i].isEmpty == 1){
                            for(int j=0; j<tamMarca; j++){
                                if(autos[i].idMarca == marcas[j].id){
                                    for(int k=0; k<tamColor; k++){
                                        if(autos[i].idColor == colores[k].id){
                                             mostrarAuto(autos[i], marcas[j], colores[k]);
                                          //   printf("%s   %d    %s     %s    %d\n", marcas[j].descripcion, autos[i].modelo, colores[k].descripcion, autos[i].patente, autos[i].id);
                                        }
                                    }
                                }
                            }




                    }
            }
    if(contador == 0){
        printf("No hay autos de color negro.");
    }
}


