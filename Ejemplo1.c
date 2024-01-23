// Con una estructura ingresar los datos de 5 estudiantes, se matricula a estos 5 estudiantes y si sobrepasa
// estos 5 estudiantes saltar un mensaje de advertencia, utilice archivos y matrices.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *archivo;

struct estudiante
{
    int matricula;
    char nombre[40];
    char direccion[40];
    char materia[40];
    float nota;
} alumnos[5];

void agregar()
{
    char direccion[] = "C:\\Users\\Ricky\\Desktop\\Programacion\\Herrera_Base_Datos\\Carpeta\\Ejemplo.txt";
    int respuesta, i = 1;
    archivo = fopen(direccion, "a");
    if (archivo == NULL)
    {
        printf("Error al ingresar en el archivo\n");
    }
    printf("Creando base de datos\n");
    fprintf(archivo, "ESTUDIANTES MATRICULADOS\n");

    do
    {
        printf("-Ingrese la matricula del estudiante-\n");
        scanf("%d", &alumnos[i].matricula);
        fflush(stdin);
        printf("-Ingrese el nombre del estudiante-\n");
        gets(alumnos[i].nombre);
        fflush(stdin);
        printf("-Ingrese la direcion del estudiante-\n");
        gets(alumnos[i].direccion);
        fflush(stdin);
        printf("-Ingrese la materia del estudiante-\n");
        gets(alumnos[i].materia);
        fflush(stdin);
        printf("-Ingrese la nota del estudiante-\n");
        scanf("%f", &alumnos[i].nota);
        fflush(stdin);

        fprintf(archivo, "MATRICULA: %d\n", alumnos[i].matricula);
        fprintf(archivo, "NOMBRE: %s\n", alumnos[i].nombre);
        fprintf(archivo, "DIRECCION: %s\n", alumnos[i].direccion);
        fprintf(archivo, "CARRERA: %s\n", alumnos[i].materia);
        fprintf(archivo, "NOTA: %.2f\n", alumnos[i].nota);

        printf("¿Desea salir? (1. para salir 2. para continuar)\n");
        scanf("%d", &respuesta);
        getchar();
    } while (respuesta != 1);
    fclose(archivo);
}

void visualizar()
{
    char direccion[] = "C:\\Users\\Ricky\\Desktop\\Programacion\\Herrera_Base_Datos\\Carpeta\\Ejemplo.txt";
    int c;
    archivo = fopen(direccion, "r");
    if (archivo == NULL)
    {
        printf("Error al ingresar en el archivo\n");
    }
    while ((c = fgetc(archivo)) != EOF)
    {
        if (c == '\n')
        {
            printf("\n");
        }
        else
        {
            putchar(c);
        }
    }
    fclose(archivo);
}

int main()
{

    int boton;

    do
    {
        printf("-Bienvenido al menu de ingreso de estudiantes \n");
        printf("1. para añadir estudiante\n");
        printf("2. para ver estudiantes matriculados\n");
        printf("3. para salir \n");
        scanf("%d", &boton);
        switch (boton)
        {
        case 1:
            printf("-Adicion de estudiantes-\n");
            agregar();
            break;
        case 2:
            printf("-Visualizacion de estudiantes-\n");
            visualizar();
            break;
        case 3:
            printf("-Gracias por usar-\n");
            break;
        default:
            printf("Numero invalido, ingrese de nuevo\n");
            break;
        }
    } while (boton != 3);

    return 0;
}