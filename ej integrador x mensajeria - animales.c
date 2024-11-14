/*Un refugio de animales la ciudad de Avellaneda está llevando a cabo un programa de adopción de mascotas para alentar a los residentes a apoyar
y cuidar a los animales que fueron rescatados. Después de seis meses de lanzar el programa, el refugio decidió hacer un seguimiento de las casi
600 personas que anotadas para adoptar animales sí adoptaron (se considera que se puede adoptar sólo un tipo de animal por persona, pero pueden ser
varios animales de ese tipo).

La carga finaliza con un adoptante igual a cero.
Para cada adoptante encuestado que sí adoptó, se ingresan los siguientes datos (validar con Función):
•    Código de adoptante (entero, mayor a cero).
•    Código del animal adoptado (entero, de 101 a 110)
•    Cantidad de animales adoptados (entero, mayor a cero).
•    Valoración de la experiencia de adoptar (caracter, 'M' malo, 'R': regular,     'B': Bueno, 'E':excelente).
.   Deseo de participar en otras experiencias de adopción de mascotas (entero, 1: Si desea, 2: No desea)


Informar:
a.    Listar la cantidad de animales adoptados, informando código y cantidad (Función).
b.    Porcentaje de cada experiencia de adoptar una mascota respecto del total de     adoptantes.
c.    Cuál fue el código del animal menos adoptado, entre los que sí fueron adoptados.   Puede haber más de uno, mostrarlos a todos. (Función).
d.    Indicar cuál es el promedio de animales adoptados por persona (de las personas que sí adoptaron).
e.  Informar los códigos de los adoptantes que desean volver a adoptar mascotas y la cantidad de adoptantes que no quieren repetir la experiencia.*/
#include <stdio.h>

int LimiteInferior(int);
int LeerYValidar(int,int);
char OpcionesLetras(char,char,char,char);
int BuscarMinimo(int ce, int vector[])

int main()
{   int cod_animal,cod_adoptante,Cant_animalesAdopt,DeseaParticipar;
    char valoracion;

    printf("\nIngrese codigo del animal adoptado:");
    cod_animal=LeerYValidar(101,110);
    printf("\nIngrese codigo del adoptante:");
    cod_adoptante=LimiteInferior(0);
    printf("\nIngrese cantidad de animales adoptadas [MAYOR A 0]:")
    Cant_animalesAdopt=LimiteInferior(0);
    printf("\nIngrese valoracion de la experiencia ['M' Mala, 'R' Regular, 'B' Buena, 'E' Excelente]");
    valoracion=OpcionesLetras('M','R','B','E');
    printf("\n¿Desea volver a participar de la experiencia? [1:SI, 2:NO]:");
    DeseaParticipar=LeerYValidar(1,2);


    printf("%d",cod_animal);
    printf("%d",cod_adoptante);
               return 0;
}

int LimiteInferior(int lim_inf)
{   int num;

    do
    {
        scanf("%d",&num);
    }while(num<lim_inf);

    return num;
}

int LeerYValidar(int lim_inf, int lim_sup)
{
    int num;
    do
    {
        scanf("%d",&num);
    }
    while((num<lim_inf)||(num>lim_sup));

    return num;
}

char OpcionesLetras(char letra1,char letra2,char letra3,char letra4)
{   char dato;

    do
    {
        scanf("%c",&dato);
        fflush(stdin);
    }while(!((dato==letra1)||(dato==letra2)||(dato==letra3)||(dato==letra4)))

    return dato;
}

int BuscarMinimo(int ce, int vector[])
{
    int i, int min=vector[0];

    for(i=0;i<ce;i++)
    {
        if(vector[i]<min)
            min=vector[i];
    }

    return min;
}

