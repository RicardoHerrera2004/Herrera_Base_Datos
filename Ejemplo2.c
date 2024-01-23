#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *arch;

struct Estudiante
{
    char nombre[50];
    float nota_prog1;
    float nota_prog2;
    float nota_prog3;
    float nota_final;
};

void
final(float x1, float x2, float x3, float *f)
{
    x1 = x1 * 0.25;
    x2 = x2 * 0.35;
    x3 = x3 * 0.4;
    *f = x1 + x2 + x3;
    printf("Su promedio final es de  %.2f\n", *f);
}

void agregar(char *nombre, float nota_final)
{
    char direccion[] = "C:\\Users\\Ricky\\Desktop\\Programacion\\Herrera_Base_Datos\\Carpeta\\Alumnos.txt";
    arch = fopen(direccion, "a");
    if (arch == NULL)
    {
        printf("Error al ingresar al archivo\n");
    }
    printf("Creado base de datos\n");
    fprintf(arch, "Estudiantes\n");
    fprintf(arch, "Nombre: %s\n", nombre);
    fprintf(arch, "Pormedio: %.2f\n", nota_final);
    fclose(arch);
}

int main()
{
    int cont;

    struct Estudiante alumno[cont];

    printf("Ingrese la cantidad de estudiantes que va a promediar: ");
    scanf("%d", &cont);
    fflush(stdin);

    for (int i = 0; i < cont; i++)
    {
        printf("Ingreso de nombre de estudiante: ");
        gets(alumno[i].nombre);
        fflush(stdin);

        printf("Ingreso del promedio del progreso 1 del estudiante: ");
        scanf("%f", &alumno[i].nota_prog1);
        fflush(stdin);

        printf("Ingreso del promedio del progreso 2 del estudiante: ");
        scanf("%f", &alumno[i].nota_prog2);
        fflush(stdin);

        printf("Ingreso del promedio del progreso 3 del estudiante: ");
        scanf("%f", &alumno[i].nota_prog3);
        fflush(stdin);

        printf("Alumno %d\n", i + 1);
        printf("Nombre: %s\n", alumno[i].nombre);
        final(alumno[i].nota_prog1, alumno[i].nota_prog2, alumno[i].nota_prog3, &alumno[i].nota_final);
        agregar(alumno[i].nombre, alumno[i].nota_final);
    }

    return 0;
}