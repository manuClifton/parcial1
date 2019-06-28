#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

#define TAMMARCA 5
#define TAMCOLOR 5
#define TAMSERVICIO 4
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
    char descripcion[25];
    int precio;
} eServicio;

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
    char nombre[20];
    char sexo;
    int isEmpty;
} eCliente;

typedef struct
{
    int id;
    char patente[7];
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;




// ---------------  PROTOTITPOS --------//

int menu();
int menuModificarAuto();
int mostrarColores(eColor colores[], int tamColores);
int mostrarMarcas(eMarca marcas[], int tamMarca);
int mostrarServicios(eServicio servicios[], int tamServ);
int mostrarAutos(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamCliente);
int buscarPatente(eAuto autos[], int tam, char patente[]);
int buscarPatenteTrabajo(eTrabajo trabajos[], int tamTrabajo, char patente[]);
int buscarServicio(eServicio servicios[], int tamServ, char servicio[]);
void mostrarAuto(eAuto autos, eMarca marcas, eColor colores, eCliente clientes);
void altaAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamCliente, int idAuto, int idCliente, int flag);
int buscarMarca(eMarca marcas[], int tamMarca, int idMarca);
int buscarColor(eColor colores[], int tamColor, int idColor);
int isEmpty(eAuto autos[], int tamAuto);
void initAutos(eAuto autos[], int tamAuto);
void modificarModelo(eAuto autos[], int tamAuto);
void modificarColor(eAuto autos[], int tamAuto, eColor colores[], int tamColor);
void bajaAuto(eAuto autos[], int tamAuto, eMarca marcas[], eColor colores[], eCliente clientes[]);
int isEmptyTrabajo(eTrabajo trabajos[], int tamTrabajo);
void altaTrabajo(eAuto autos[], int tamAuto, eTrabajo trabajos[], int tamTrabajo ,eServicio servicios[], int tamServ, int id);
void mostrarTrabajo(eTrabajo trabajo, eAuto autos, eServicio servicios, eCliente cliente);
int mostrarTrabajos( eTrabajo trabajos[], int tamTrabajos, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eCliente clientes[], int tamCliente);
void mostrarXservicios(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServ, eAuto autos[], int tamAuto, eCliente clientes[], int tamCliente, eMarca marcas[], int tamMarca);
void mostrarXfecha(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServ, eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente);
void ordenarAutos(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);
void mostrarXcolor(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamCliente);
void initClientes(eCliente clientes[], int tamCliente);
int isEmptyCliente(eCliente clientes[], int tamCliente);
int mostrarClientes(eCliente clientes[], int tamCliente);
void mostrarXmarca(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamCliente);
void mostrarXtrabajo(eTrabajo trabajos[], int tamTrabajo, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eCliente clientes[], int tamCliente);
void mostrarSinTrabajo(eAuto autos[], int tamAuto, eTrabajo trabajos[], int tamTrabajo, eMarca marca[], int tamMarca, eColor color[], int tamColor, eCliente cliente[], int tamCliente);
void importeTrabajos(eTrabajo trabajos[], int tamTrabajo, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ);
void importeServicios(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServ);
void importeXfecha(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServ);
void servicioMasPedido(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServ);



// ---------------  MAIN --------//
int main()
{
    char seguir = 's';
    char confirma;
    int idAuto=1;
    int idTrabajo=1;
    int idCliente=1;
    int flag=1;

    eMarca marcas[TAMMARCA] =
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"},
    };

    eColor colores[TAMCOLOR] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };
    eServicio servicios[TAMSERVICIO]=
    {
        {20000, "Lavado", 250},
        {20001, "Pulido", 300},
        {20002, "Encerado", 400},
        {20003, "Completo", 600}
    };


   eAuto autos[TAMAUTO]=
   {
       {1,  1, "AAA201", 1000, 5001, 1995, 1},
       {2,  2, "DFR234", 1003, 5000, 2002, 1},
       {3,  3, "GFT564", 1002, 5003, 2007, 1},
       {4,  4, "ACD321", 1002, 5003, 1995, 1},
       {5,  5, "HTD656", 1004, 5002, 2008, 1},
       {6,  6, "QSZ435", 1003, 5001, 1994, 1},
       {7,  7, "LGX201", 1001, 5000, 2012, 1},
       {8,  8, "SUZ324", 1001, 5002, 1991, 1},
       {9,  9, "HCU762", 1000, 5003, 2008, 1},
       {10, 10,"DYC735", 1003, 5001, 2002, 1},
       {11, 11,"JJK879", 1003, 5001, 2010, 1},
       {12, 12,"FED322", 1004, 5002, 2006, 1},
       {13, 13,"GHV332", 1001, 5003, 2007, 1},
       {14, 14,"BDE221", 1000, 5004, 1996, 1},
       {15, 15,"OPD332", 1000, 5001, 2014, 1},
       {16, 16,"PPD121", 1002, 5001, 2015, 1},
       {17, 17,"IIT230", 1001, 5000, 2009, 1},
       {18, 18,"KOD220", 1004, 5002, 2011, 1},
       {19, 19,"QSZ305", 1004, 5002, 1993, 1},
       {20, 20,"SSD128", 1002, 5003, 1992, 1},
       {21, 21,"SSD240", 1003, 5004, 1992, 1},
       {22, 22,"EDF213", 1001, 5000, 2001, 1}
   };




    eCliente clientes[TAMCLIENTE] =
    {
        {1,    "Pablo",   'm', 1},
        {2,    "Lucas",   'm', 1},
        {3,    "Ricardo", 'm', 1},
        {4,    "Ana",     'f', 1},
        {5,    "Sofia",   'f', 1},
        {6,    "Laura",   'f', 1},
        {7,    "Pablo",   'm', 1},
        {8,    "Simon",   'm', 1},
        {9,    "Lucas",   'm', 1},
        {10, "Florencia", 'f', 1},
        {11,       "Ana", 'f', 1},
        {12,    "Amanda", 'f', 1},
        {13,     "Pablo", 'm', 1},
        {14,    "Ramiro", 'm', 1},
        {15,   "Claudio", 'm', 1},
        {16,   "Luciano", 'm', 1},
        {17,     "Laura", 'f', 1},
        {18,     "Pablo", 'm', 1},
        {19,       "Ana", 'f', 1},
        {20,     "Sofia", 'f', 1},
        {21,     "Lucas", 'm', 1},
        {22,    "Nestor", 'm', 1}
    };


   eTrabajo trabajos[TAMTRABAJO] = {

       {1,  "AAA201", 20000,  {12,9,2019}, 1},
       {2,  "DFR234", 20000,   {2,4,2019}, 1},
       {3,  "GFT564", 20001,   {7,1,2019}, 1},
       {4,  "ACD321", 20002,  {9,11,2019}, 1},
       {5,  "HTD656", 20003, {12,12,2019}, 1},
       {6,  "QSZ435", 20001,  {21,7,2019}, 1},
       {7,  "LGX201", 20001,  {29,8,2019}, 1},
       {8,  "SUZ324", 20003,  {31,5,2019}, 1},
       {9,  "HCU762", 20003,   {2,2,2019}, 1},
       {10, "DYC735", 20000,  {18,2,2019}, 1},
       {11, "JJK879", 20001,  {17,3,2019}, 1},
       {12, "AAA201", 20000,  {17,4,2019}, 1},
       {13, "DFR234", 20000,   {2,6,2019}, 1},
       {14, "GFT564", 20001,   {7,3,2019}, 1},
       {15, "ACD321", 20002,  {21,7,2019}, 1},
       {16, "HTD656", 20003,  {11,9,2019}, 1},
       {17, "QSZ435", 20001,   {3,7,2019}, 1},
       {18, "LGX201", 20001,  {21,8,2019}, 1},
       {19, "SUZ324", 20002,  {21,8,2019}, 1},
       {20, "HCU762", 20001,   {2,8,2019}, 1},
       {21, "DYC735", 20000,   {8,2,2019}, 1},
       {22, "JJK879", 20001,  {17,3,2019}, 1},
       {23, "KOD220", 20003,  {17,4,2019}, 1},
       {24, "QSZ305", 20000,  {21,3,2019}, 1},
       {25, "SSD128", 20002,  {16,4,2019}, 1},
       {26, "SSD240", 20000,  {17,4,2019}, 1},
       {27, "EDF213", 20001,  {23,3,2019}, 1},
       {28, "AAA201", 20000,  {12,2,2019}, 1},
       {29, "DFR234", 20000,   {2,3,2019}, 1},
       {30, "GFT564", 20001,   {7,2,2019}, 1},
       {31, "ACD321", 20002,  {9,12,2019}, 1},
       {32, "HTD656", 20003,  {12,9,2019}, 1},
       {33, "QSZ435", 20001,  {21,5,2019}, 1},
       {34, "HTD656", 20002,  {12,2,2019}, 1},
       {35, "QSZ435", 20000,  {21,1,2019}, 1}
   };

   do
    {
        switch(menu())
        {

        case 1:
               //ALTA AUTO
            altaAuto(autos, TAMAUTO, marcas, TAMMARCA, colores, TAMCOLOR, clientes, TAMCLIENTE, idAuto, idCliente, flag);
            idAuto++;
            idCliente++;
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
                 bajaAuto(autos, TAMAUTO, marcas, colores, clientes);
            }

            system("pause");
            break;

        case 4:
                //LISTAR AUTOS
            if(flag == 0){
                printf("\nDEBE REALIZAR EL ALTA DE UN AUTO PRIMERO\n");
            }
            else{
                 mostrarAutos(autos, TAMAUTO, marcas, TAMMARCA, colores, TAMCOLOR, clientes, TAMCLIENTE);
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
            mostrarServicios(servicios, TAMSERVICIO);
            system("pause");
            break;

        case 8:
                // ALTA TRABAJO
            if(flag == 0){
                printf("\nDEBE REALIZAR EL ALTA DE UN AUTO PRIMERO\n");
            }
            else{
                altaTrabajo(autos, TAMAUTO, trabajos, TAMTRABAJO, servicios, TAMSERVICIO,  idTrabajo);
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
                 mostrarTrabajos(trabajos, TAMTRABAJO, autos, TAMAUTO, servicios, TAMSERVICIO, clientes, TAMCLIENTE);
            }

            system("pause");
            break;
        case 10:
            mostrarXcolor(autos, TAMAUTO, marcas, TAMMARCA, colores, TAMCOLOR, clientes, TAMCLIENTE);
            system("pause");
            break;
         case 11:
            mostrarXmarca(autos, TAMAUTO, marcas, TAMMARCA, colores, TAMCOLOR, clientes, TAMCLIENTE);
            system("pause");
            break;
        case 12:
            mostrarXtrabajo(trabajos, TAMTRABAJO, autos, TAMAUTO, servicios, TAMSERVICIO, clientes, TAMCLIENTE);
            system("pause");
            break;
        case 13:
            mostrarSinTrabajo(autos, TAMAUTO, trabajos, TAMTRABAJO, marcas, TAMMARCA, colores, TAMCOLOR, clientes, TAMCLIENTE);
            system("pause");
            break;
        case 14:
           importeTrabajos(trabajos, TAMTRABAJO, autos, TAMAUTO,servicios, TAMSERVICIO);
            system("pause");
            break;
        case 15:
           importeServicios(trabajos, TAMTRABAJO, servicios, TAMSERVICIO);
            system("pause");
            break;
        case 16:
           importeXfecha(trabajos, TAMTRABAJO, servicios, TAMSERVICIO);
            system("pause");
            break;
        case 17:
           servicioMasPedido(trabajos, TAMTRABAJO, servicios, TAMSERVICIO);
            system("pause");
            break;
        case 18:
           mostrarXservicios(trabajos, TAMTRABAJO, servicios, TAMSERVICIO,autos, TAMAUTO, clientes, TAMCLIENTE, marcas, TAMMARCA);
            system("pause");
            break;
        case 19:
           mostrarXfecha(trabajos, TAMTRABAJO, servicios, TAMSERVICIO,autos, TAMAUTO, marcas, TAMMARCA,clientes,TAMCLIENTE);
            system("pause");
            break;

        case 20:
                // SALIER
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
    printf("  *** ABM kmlml ***\n\n");
    printf("1- Alta Auto\n");
    printf("2- Modificar Auto\n");
    printf("3- Baja Auto \n");
    printf("4- Listar Autos \n");
    printf("5- Listar Marcas\n");
    printf("6- Listar Colores\n");
    printf("7- Listar Servicios\n");
    printf("8- Alta Trabajo\n");
    printf("9- Listar Trabajos \n");
    printf("10- Listar por colores \n");
    printf("11- Listar por marcas \n");
    printf("12- Listar por trabajos\n");
    printf("13- Listar Autos sin trabajos\n");
    printf("14- Importe total de trabajos a un auto\n");
    printf("15- Facturacion total por servicio seleccionado\n");
    printf("16- Facturacion total por fehca seleccionada\n");
    printf("17- Servicio mas pedidos\n");
    printf("18- Mostrar autos por trabajos realizados\n");
    printf("19- Mostrar autos que recibieron trabajos en la fecha indicada\n\n");

    printf("20- Salir\n\n");
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

int buscarPatenteTrabajo(eTrabajo trabajos[], int tamTrabajo, char patente[])
{
    int indice = -1;

    for(int i=0; i < tamTrabajo; i++)
    {
        if(strcmp(trabajos[i].patente, patente) == 0 && trabajos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarServicio(eServicio servicios[], int tamServ, char servicio[])
{
    int indice = -1;

    for(int i=0; i < tamServ; i++)
    {
        if(strcmp(servicios[i].descripcion, servicio) == 0)
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



void altaAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamCliente, int idAuto, int idCliente, int flag)
{
    char patente[7];
    int existe;
    int hayLugar;
    int hayLugarCliente;

         hayLugar = isEmpty(autos, tamAuto);
         hayLugarCliente = isEmptyCliente(clientes, tamCliente);

        if(hayLugar == -1 && hayLugarCliente == -1){
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

            printf("\nIngrese Nombre: ");
            scanf("%s", clientes[hayLugarCliente].nombre);

            printf("\nIngrese Sexo: ");
            scanf("%c", &clientes[hayLugarCliente].sexo);

            clientes[hayLugarCliente].id = idCliente;
            clientes[hayLugarCliente].isEmpty = 1;

            autos[hayLugar].idCliente = idCliente;
            autos[hayLugar].id = idAuto;
            autos[hayLugar].isEmpty = 1;
            strcpy(autos[hayLugar].patente, patente);

             printf("\nALTA DE AUTO EXITOSA!!!\n\n");
        }
        }
}

void altaTrabajo(eAuto autos[], int tamAuto, eTrabajo trabajos[], int tamTrabajo ,eServicio servicios[], int tamServ, int id)
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
                mostrarServicios(servicios, tamServ);
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
    strupr(patente);

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

    if( autos.isEmpty == 1 && clientes.isEmpty == 1){
        printf("%5d     %8s     %8s    %5d      %7s    %12s      %5c\n", autos.id, marcas.descripcion, colores.descripcion, autos.modelo, autos.patente, clientes.nombre, clientes.sexo);
    }
 }

int mostrarAutos(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamCliente){
    int contador = 0;

    system("cls");

     printf(" ID      MARCA         COLOR      MODELO      PATENTE          NOMBRE        SEXO    \n");
     printf("----    -------       -------    --------    ---------        --------      ------   \n");

    for(int i=0; i < tamAuto; i++){
        for(int j=0; j < tamCliente; j++){
               if(autos[i].idCliente == clientes[j].id && autos[i].isEmpty == 1){
                    for(int k=0; k<tamMarca; k++){
                        for(int l=0; l<tamColor; l++ ){
                            if(autos[i].idMarca == marcas[k].id && autos[i].idColor == colores[l].id){
                                        mostrarAuto(autos[i], marcas[k], colores[l], clientes[j]);
                                      // printf("BAUS HIJO DE PUTA\n");
                                        contador++;
                            }
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



int mostrarServicios(eServicio servicios[], int tamServ){
    int contador = 0;

    printf("\n    SERVICIO        PRECIO \n");
    printf("     ----------      ---------\n");

    for(int i=0; i < tamServ; i++)
    {
        printf("%d- %8s        $ %d\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
            contador++;
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNO HAY SERVICIOS QUE MOSTRAR\n");
    }
    return 0;
}

void mostrarTrabajo(eTrabajo trabajo, eAuto autos, eServicio servicios, eCliente cliente)
{
    if(trabajo.isEmpty == 1 && autos.isEmpty == 1 && cliente.isEmpty == 1){
        printf("%5d     %5s     %7s     %8s    $%5d        %0d/%0d/%0d\n", trabajo.id, trabajo.patente, cliente.nombre, servicios.descripcion, servicios.precio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
    }

}


int mostrarTrabajos( eTrabajo trabajos[], int tamTrabajos, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eCliente clientes[], int tamCliente)
{
    int contador = 0;

    system("cls");

     printf("   ID      PATENTE     NOMBRE     TRABAJO    PRECIO       FECHA\n");
     printf("  ----    ---------   ---------  ---------  ----------  -------\n");

    for(int i=0; i < tamAuto; i++)
    {
        for(int j=0; j < tamTrabajos; j++){
               if(strcmp(trabajos[j].patente, autos[i].patente) == 0){
                    for(int k=0; k < tamServ; k++){
                        if(trabajos[j].idServicio == servicios[k].id){
                                for(int l=0; l<tamCliente; l++){
                                    if(autos[i].idCliente == clientes[l].id){
                                        mostrarTrabajo(trabajos[j], autos[i], servicios[k], clientes[l]);
                                        contador++;
                                    }
                                }

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

int mostrarClientes(eCliente clientes[], int tamCliente){
    int contador = 0;

    printf("\n    NOMBRE     SEXO       ID\n");
    printf("     --------   -------    -----    \n");

    for(int i=0; i < tamCliente; i++)
    {
        printf("  %7s     %2s      %2d\n", clientes[i].nombre, clientes[i].nombre, clientes[i].id);
            contador++;
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNO HAY CLIENTES QUE MOSTRAR\n");
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

int isEmptyCliente(eCliente clientes[], int tamCliente){
    int indice = -1;

        for(int i=0; i<tamCliente; i++){
            if(clientes[i].isEmpty == 0){
                indice = i;
                break;
            }
        }
    return indice;
}

void initClientes(eCliente clientes[], int tamCliente){
    for(int i=0; i<tamCliente; i++){
      clientes[i].isEmpty = 0;
    }
}

void initAutos(eAuto autos[], int tamAuto){
    for(int i=0; i<tamAuto; i++){
        autos[i].isEmpty = 0;
    }
}

void bajaAuto(eAuto autos[], int tamAuto, eMarca marca[], eColor color[], eCliente cliente[])
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
        mostrarAuto(autos[esta], marca[esta], color[esta], cliente[esta]);

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


void mostrarXcolor(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamCliente)
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

            printf(" ID      MARCA         COLOR      MODELO      PATENTE          NOMBRE        SEXO    \n");
            printf("----    -------       -------    --------    ---------        --------      ------   \n");

            for(int i=0; i < tamAuto; i++){
                    if(autos[i].idColor == id && autos[i].isEmpty == 1){
                            for(int j=0; j<tamMarca; j++){
                                if(autos[i].idMarca == marcas[j].id){
                                    for(int k=0; k<tamColor; k++){
                                        if(autos[i].idColor == colores[k].id){
                                                for(int l=0; l<tamCliente; l++){
                                                    if(autos[i].idCliente == clientes[l].id){
                                                        mostrarAuto(autos[i], marcas[j], colores[k], clientes[l]);
                                                        contador++;
                                                    }
                                                }
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


void mostrarXmarca(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, eCliente clientes[], int tamCliente)
{
    int contador = 0;
    int existe;
    int id;

            mostrarMarcas(marcas, tamMarca);
            printf("\nIngrese numero de marca: ");
            scanf("%d", &id);

            existe = buscarMarca(marcas, tamMarca, id);

            while(existe == -1){
                    printf("\nNo Existe la marca ingresada. Reingrese una vez mas: ");
                    scanf("%d", &id);

                     existe = buscarMarca(marcas, tamMarca, id);
            }

            printf(" ID      MARCA         COLOR      MODELO      PATENTE          NOMBRE        SEXO    \n");
            printf("----    -------       -------    --------    ---------        --------      ------   \n");

            for(int i=0; i < tamAuto; i++){
                    if(autos[i].idMarca == id && autos[i].isEmpty == 1){
                            for(int j=0; j<tamMarca; j++){
                                if(autos[i].idMarca == marcas[j].id){
                                    for(int k=0; k<tamColor; k++){
                                        if(autos[i].idColor == colores[k].id){
                                                for(int l=0; l<tamCliente; l++){
                                                    if(autos[i].idCliente == clientes[l].id){
                                                        mostrarAuto(autos[i], marcas[j], colores[k], clientes[l]);
                                                        contador++;
                                                    }
                                                }
                                        }
                                    }
                                }
                            }
                    }
            }
    if(contador == 0){
        printf("No hay autos de esa Marca.");
    }
}


void mostrarXtrabajo(eTrabajo trabajos[], int tamTrabajo, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eCliente clientes[], int tamCliente)
{
    char patente[7];
    int existe;
    int contador=0;

        printf("Ingrese patente: ");
        scanf("%s", patente);
        strupr(patente);

        existe = buscarPatente(autos, tamAuto, patente);

        while(existe == -1){
                printf("\nNo Existe la patente ingresada. Reingrese una vez mas: ");
                scanf("%s", patente);
                strupr(patente);

                existe = buscarPatente(autos, tamAuto, patente);
            }

        printf("   ID      PATENTE     NOMBRE     TRABAJO    PRECIO       FECHA\n");
        printf("  ----    ---------   ---------  ---------  ----------  -------\n");

           for(int i=0; i < tamTrabajo; i++){
                    for(int j=0; j<tamAuto; j++){
                            if(strcmp(trabajos[i].patente, patente) == 0 && strcmp(autos[j].patente, patente) == 0 && autos[j].isEmpty == 1 && trabajos[i].isEmpty == 1){
                                    for(int k=0; k < tamServ; k++){
                                        for(int l=0; l<tamCliente; l++){
                                            if(trabajos[i].idServicio == servicios[k].id && autos[j].idCliente == clientes[l].id){
                                        mostrarTrabajo(trabajos[i], autos[j], servicios[k], clientes[l]);
                                        contador++;
                                            }
                                        }
                                    }
                            }
                    }
            }

    if(contador == 0){
        printf("No hay Trabajos para ese Auto.");
    }
}


void mostrarSinTrabajo(eAuto autos[], int tamAuto, eTrabajo trabajos[], int tamTrabajo, eMarca marca[], int tamMarca, eColor color[], int tamColor, eCliente cliente[], int tamCliente){
    int contador=0;
    int esta;

            printf(" ID      MARCA         COLOR      MODELO      PATENTE          NOMBRE        SEXO    \n");
            printf("----    -------       -------    --------    ---------        --------      ------   \n");

        for(int i=0; i<tamAuto; i++){
                    esta = buscarPatenteTrabajo(trabajos, tamTrabajo, autos[i].patente);
                     if(esta == -1){
                            for(int k=0; k <tamMarca; k++){
                                    if(marca[k].id == autos[i].idMarca){
                                        for(int l=0; l<tamColor; l++){
                                            if(color[l].id == autos[i].idColor){
                                                for(int m=0; m<tamCliente; m++){
                                                    if(cliente[m].id == autos[i].idCliente){
                                                        mostrarAuto(autos[i], marca[k], color[l], cliente[m]);
                                                        contador++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                            }
                     }

        }
    if(contador == 0){
        printf("No hay Autos que no tengan trabajos realizados.");
    }
}


void importeTrabajos(eTrabajo trabajos[], int tamTrabajo, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ){
    char patente[7];
    int existe;
    int contador=0;
    int acumulador=0;

        printf("Ingrese patente: ");
        scanf("%s", patente);
        strupr(patente);

        existe = buscarPatente(autos, tamAuto, patente);

        while(existe == -1){
                printf("\nNo Existe la patente ingresada. Reingrese una vez mas: ");
                scanf("%s", patente);
                strupr(patente);

                existe = buscarPatente(autos, tamAuto, patente);
            }

                for(int i=0; i<tamTrabajo; i++){
                        if(strcmp(trabajos[i].patente, patente) == 0 ){
                                    for(int j=0; j<tamServ; j++){
                                        if(trabajos[i].idServicio == servicios[j].id){

                                        acumulador = acumulador + (servicios[j].precio);
                                        contador++;
                                        }
                                    }
                        }
                }
        if(contador != 0){
        printf("\nEl Auto debe abonar: %d\n\n", acumulador);
        }

      if(contador == 0){
        printf("\nNo hay Trabajos para ese Auto.\n");
      }
}

void importeServicios(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServ){
    char servicio[10];
    int existe;
    int contador=0;
    int acumulador=0;

    printf("Ingrese Servicio: ");
        scanf("%s", servicio);
        strlwr(servicio);
        servicio[0]=toupper(servicio[0]);

        existe = buscarServicio(servicios, tamServ, servicio);

        while(existe == -1){
                printf("\nNo Existe el servicio ingresado. Reingrese una vez mas: ");
                scanf("%s", servicio);
                strlwr(servicio);
                servicio[0]=toupper(servicio[0]);

                existe = buscarServicio(servicios, tamServ, servicio);
            }

        for(int i=0; i<tamServ; i++){
            if( strcmp(servicios[i].descripcion, servicio) == 0 ){
                for(int j=0; j<tamTrabajo; j++){
                    if(trabajos[j].idServicio == servicios[i].id){

                        acumulador = acumulador + (servicios[i].precio);
                        contador++;

                    }
                }
            }
        }
        if(contador != 0){
            printf("\nLa facturqacion total de %s es: %d\n\n", servicio ,acumulador);
        }
        if(contador == 0){
            printf("\nNo se realizo ese servicio.\n");
        }
}

void servicioMasPedido(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServ){

    char servicio[10];
    int max;
    int contador1 = 0;
    int contador2 = 0;
    int contador3 = 0;
    int contador4 = 0;
    int acumulador1 = 0;
    int acumulador2 = 0;
    int acumulador3 = 0;
    int acumulador4 = 0;


        for(int j=0; j<tamServ; j++){
            if(servicios[j].precio == 250){
                for(int k=0; k<tamTrabajo; k++){
                    if(trabajos[k].idServicio == servicios[k].id){
                        acumulador1 = acumulador1 + (servicios[j].precio);
                        contador1++;
                        max=contador1;
                        strcpy(servicio, servicios[j].descripcion);
                    }
                }
            }
        }
        for(int l=0; l<tamServ; l++){
            if(servicios[l].precio == 300){
                for(int m=0; m<tamTrabajo; m++){
                    if(trabajos[m].idServicio == servicios[l].id){
                        acumulador2 = acumulador2 + (servicios[l].precio);
                        contador2++;
                        if(max < contador2){
                            max = contador2;
                            strcpy(servicio, servicios[l].descripcion);

                        }
                    }
                }
            }
        }
        for(int n=0; n<tamServ; n++){
            if(servicios[n].precio == 400){
                for(int r=0; r<tamTrabajo; r++){
                    if(trabajos[r].idServicio == servicios[n].id){
                        acumulador3 = acumulador3 + (servicios[n].precio);
                        contador3++;
                        if(max < contador3){
                            max = contador3;
                            strcpy(servicio, servicios[n].descripcion);
                        }
                    }
                }
            }
        }
        for(int s=0; s<tamServ; s++){
            if(servicios[s].precio == 600){
                for(int t=0; t<tamTrabajo; t++){
                    if(trabajos[t].idServicio == servicios[s].id){
                        acumulador4 = acumulador4 + (servicios[s].precio);
                        contador4++;
                         if(max < contador4){
                            max = contador4;
                            strcpy(servicio, servicios[s].descripcion);
                        }
                    }
                }
            }
        }

        for(int i=0; i<tamServ; i++){
            if(servicios[i].precio == 250){
                for(int j=0; j<tamTrabajo; j++){
                    if(trabajos[j].idServicio == servicios[i].id){
                            if(strcmp(servicio, "Lavado") == 0){
                                contador1++;
                            }
                    }
                }
            }
                max = contador1;
                strcpy(servicio, servicios[i].descripcion);// ACAAAAA!!!!
            if(servicios[i].precio == 300){
                for(int k=0; <tamTrabajo; k++){
                    if(trabajos[k].idServicio == servicios[i].id){
                            if(strcmp(servicio, "Pulido") == 0){
                                contador2++;
                                if(max < contador2){
                                    max = contador2;
                                }
                            }
                    }
                }
            }
             if(servicios[i].precio == 400){
                for(int l=0; <tamTrabajo; l++){
                    if(trabajos[l].idServicio == servicios[i].id){
                            if(strcmp(servicio, "Encerado") == 0){
                                contador3++;
                            }
                    }
                }
            }
            if(servicios[i].precio == 400){
                for(int m=0; <tamTrabajo; m++){
                    if(trabajos[m].idServicio == servicios[i].id){
                            if(strcmp(servicio, "Completo") == 0){
                                contador4++;
                            }
                    }
                }
            }
        }

        if(contador1 != 0 || contador2 != 0 || contador3 != 0 || contador4 != 0){
            printf("\nEl servicio mas pedido es: %s\n\n", servicio);
        }
        if(contador1 == 0 && contador2 == 0 && contador3 == 0 && contador4 == 0){
            printf("\nNo se registraron servicios.\n");
        }
}


void importeXfecha(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServ){
    int day;
    int month;
    int year;
    int contador=0;
    int acumulador=0;

        printf("\nIngrese fecha de trabajo dd/mm/aaaa: ");
        scanf("%d/%d/%d", &day, &month, &year);
                while(day < 1 || day > 31 || month < 1 || month > 12 || year > 2019 || year < 1980){
                    printf("\nERROR. Reingrese fecha dd/mm/aaaa: ");
                    scanf("%d/%d/%d", &day, &month, &year);
                };

        for(int i=0; i<tamTrabajo; i++){
            if( trabajos[i].fecha.dia == day && trabajos[i].fecha.mes == month  && trabajos[i].fecha.anio == year ){
                for(int j=0; j<tamServ; j++){
                    if(trabajos[i].idServicio == servicios[j].id){

                        acumulador = acumulador + (servicios[j].precio);
                        contador++;

                    }
                }
            }
        }
        if(contador != 0){
            printf("\nLa facturqacion total en el dia %d/%d/%d es:  $ %d\n\n", day, month, year ,acumulador);
        }
        if(contador == 0){
            printf("\nNo se realizo ningun trabajo en esa fecha.\n");
        }
}


void mostrarXservicios(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServ, eAuto autos[], int tamAuto, eCliente clientes[], int tamCliente, eMarca marcas[], int tamMarca){
    char servicio[10];
    int existe;


    printf("Ingrese Servicio: ");
        scanf("%s", servicio);
        strlwr(servicio);
        servicio[0]=toupper(servicio[0]);

        existe = buscarServicio(servicios, tamServ, servicio);

        while(existe == -1){
                printf("\nNo Existe el servicio ingresado. Reingrese una vez mas: ");
                scanf("%s", servicio);
                strlwr(servicio);
                servicio[0]=toupper(servicio[0]);

                existe = buscarServicio(servicios, tamServ, servicio);
            }

                printf("   AUTO           CLIENTE            FECHA\n");
                printf("  ------         ---------          -------\n");
        for(int i=0; i<tamServ; i++){
            if( strcmp(servicios[i].descripcion, servicio) == 0 ){
                for(int j=0; j<tamTrabajo; j++){
                    if(trabajos[j].idServicio == servicios[i].id){
                        for(int k=0; k<tamAuto; k++){
                            if( strcmp(autos[k].patente, trabajos[j].patente) == 0 ){
                                for(int l=0; l<tamCliente; l++){
                                    if(clientes[l].id == autos[k].idCliente){
                                        for(int m=0; m<tamMarca; m++){
                                            if(marcas[m].id == autos[k].idMarca){

                                                printf("%10s      %10s     %7d/%d/%d\n", marcas[m].descripcion, clientes[l].nombre, trabajos[j].fecha.dia, trabajos[j].fecha.mes, trabajos[j].fecha.anio);
                                            }
                                        }
                                        //mostrarTrabajo(trabajos[j],autos[k],servicios[i], clientes[l]);

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
}


void mostrarXfecha(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServ, eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eCliente clientes[], int tamCliente){
    int day;
    int month;
    int year;


        printf("\nIngrese fecha de trabajo dd/mm/aaaa: ");
        scanf("%d/%d/%d", &day, &month, &year);
                while(day < 1 || day > 31 || month < 1 || month > 12 || year > 2019 || year < 1980){
                    printf("\nERROR. Reingrese fecha dd/mm/aaaa: ");
                    scanf("%d/%d/%d", &day, &month, &year);
                };


            printf("   AUTO      MODELO      CLIENTE       SERVICIO         FECHA\n");
            printf("  ------    --------    ----------    ----------        ----------\n");

        for(int i=0; i<tamTrabajo; i++){
            if( trabajos[i].fecha.dia == day && trabajos[i].fecha.mes == month  && trabajos[i].fecha.anio == year ){
                for(int j=0; j<tamServ; j++){
                    if(trabajos[i].idServicio == servicios[j].id){
                        for(int k=0; k<tamAuto; k++){
                            if( strcmp(autos[k].patente, trabajos[i].patente) == 0 ){
                                for(int m=0; m<tamMarca; m++){
                                    if(autos[k].idMarca == marcas[m].id){
                                            for(int n=0; n<tamCliente; n++){
                                                if(clientes[n].id == autos[k].idCliente){
                                                    printf("%9s     %5d     %7s        %5s       %4d/%d/%d\n", marcas[m].descripcion, autos[k].modelo, clientes[n].nombre, servicios[j].descripcion, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
                                                }
                                            }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
}




