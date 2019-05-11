#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define TAMMARCA 5
#define TAMCOLOR 5
#define TAMLAVADO 4
#define TAMAUTO  1

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
    char patente[7];
    int idMarca;
    int idColor;
    int modelo;
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
    eFecha;
} eTrabajo;

// ---------------  PROTOTITPOS --------//

int menu();
int mostrarColores(eColor colores[], int tamColores);
int mostrarMarca(eMarca marcas[], int tamMarca);
int mostrarServicios(eServicio servicios[], int tamServ);
int mostrarAuto(eAuto autos[], int tamAuto);

// ---------------  MAIN --------//
int main()
{
    char seguir = 's';
    char confirma;

    eMarca marcas[] =
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"},
    };

    eColor colores[] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"},
    };
    eServicio lavado[]=
    {
        {20000, "Lavado", 250},
        {20001, "Pulido", 300},
        {20002, "Encerado", 400},
        {20003, "Completo", 600}
    };

    eAuto autos;

   do
    {
        switch(menu())
        {

        case 1:

            system("pause");
            break;

        case 2:

            system("pause");
            break;

        case 3:

            system("pause");
            break;

        case 4:
            mostrarAuto(autos, TAMAUTO);
            system("pause");
            break;

        case 5:
            mostrarMarca(marcas, TAMMARCA);
            system("pause");
            break;

        case 6:
            mostrarColores(colores, TAMCOLOR);
            system("pause");
            break;
        case 7:
            mostrarServicios(lavado, TAMLAVADO);
            system("pause");
            break;

        case 8:

            system("pause");
            break;

        case 9:


            system("pause");
            break;

        case 10:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
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


int buscarPatente(eAuto autos[], int tam, char patente)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(autos[i].patente  == patente)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarMarca(eMarca marcas[], int tamMarca)
{
    int indice = -1;

    for(int i=0; i < tamMarca; i++)
    {
        if(marcas[i].id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarColor(eColor colores[], int tamColor)
{
    int indice = -1;

    for(int i=0; i < tamColor; i++)
    {
        if(colores[i].id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}




void altaAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int indice;
    char patente[7];
    int esta;


        printf("Ingrese patente: ");
        scanf("%d", &patente);

        esta = buscarPatente(autos, tamAuto, patente);

        if( esta != -1)
        {
            printf("Existe un Auto con la patente %s en el sistema\n", patente);
            mostrarAuto(autos[esta]);
        }
        else
        {
            printf("Ingrese marca: ");
            scanf("%d", autos[esta].idMarca);

            esta = buscarMarca(marcas, tamMarca);

            if( esta != -1){
                printf("No Existe la  marca con id %d en el sistema\n", marcas[esta].id);
            }else{
                    printf("Ingrese id color: ");
                    scanf("%d", autos[esta].idColor);

                     esta = buscarColor(colores, tamColor);
                        if(esta != -1){
                             printf("No Existe el color con id %d en el sistema\n", colores[esta].id);
                        }else{

                            printf("Ingrese  id del auto: ");
                            scanf("%d", autos[esta].id);

                            printf("Ingrese Modelo del auto: ");
                            scanf("%d", autos[esta].modelo);

                            printf("Alta del AUTO exitosa!!!\n\n");
                        }


            }
        }
}



int mostrarAuto(eAuto autos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor){
    int contador = 0;

    system("cls");

     printf(" MARCA      MODELO     COLOR    PATENTE\n");
    printf(" ------      ------     -----    -------- \n");

    for(int i=0; i < tamAuto; i++)
    {
        for(int j=0; j < tamMarca; j++)
               if(autos[i].idMarca == marcas[j].id){
                    for(int k=0; k<tamColor; k++){
                        if(autos.[i].idColor == colores[k].id){
                            printf("%s    %d     %s    %s", marcas[j].descripcion, autos[i].modelo, colores[k].descripcion, autos[i].patente);
                            contador++;
                        }
                    }
               }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay Autos que mostrar\n");
    }
    return 0;
}


int mostrarMarca(eMarca marcas[], int tamMarca){
    int contador = 0;

    system("cls");

    printf(" Marcas      \n");
    printf(" ------      \n");

    for(int i=0; i < tamMarca; i++)
    {
        printf("%s\n", marcas[i].descripcion);
            contador++;
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay Marcas que mostrar\n");
    }
    return 0;
}


int mostrarColores(eColor colores[], int tamColores){
    int contador = 0;

    system("cls");

    printf(" Colores      \n");
    printf(" ------      \n");

    for(int i=0; i < tamColores; i++)
    {
        printf("%s\n", colores[i].descripcion);
            contador++;
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay Colores que mostrar\n");
    }
    return 0;
}



int mostrarServicios(eServicio servicios[], int tamServ){
    int contador = 0;

    system("cls");

    printf(" Servicio        Precio \n");
    printf(" ------         --------\n");

    for(int i=0; i < tamServ; i++)
    {
        printf("%8s        $ %d\n", servicios[i].descripcion, servicios[i].precio);
            contador++;
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay Colores que mostrar\n");
    }
    return 0;
}
