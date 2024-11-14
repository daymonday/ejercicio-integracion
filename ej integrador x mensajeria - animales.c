/*Un refugio de animales la ciudad de Avellaneda est� llevando a cabo un programa de adopci�n de mascotas para alentar a los residentes a apoyar
y cuidar a los animales que fueron rescatados. Despu�s de seis meses de lanzar el programa, el refugio decidi� hacer un seguimiento de las casi
600 personas que anotadas para adoptar animales s� adoptaron (se considera que se puede adoptar s�lo un tipo de animal por persona, pero pueden ser
varios animales de ese tipo).

La carga finaliza con un adoptante igual a cero.
Para cada adoptante encuestado que s� adopt�, se ingresan los siguientes datos (validar con Funci�n):
�    C�digo de adoptante (entero, mayor a cero).
�    C�digo del animal adoptado (entero, de 101 a 110)
�    Cantidad de animales adoptados (entero, mayor a cero).
�    Valoraci�n de la experiencia de adoptar (caracter, 'M' malo, 'R': regular,     'B': Bueno, 'E':excelente).
.   Deseo de participar en otras experiencias de adopci�n de mascotas (entero, 1: Si desea, 2: No desea)


Informar:
a.    Listar la cantidad de animales adoptados, informando c�digo y cantidad (Funci�n).
b.    Porcentaje de cada experiencia de adoptar una mascota respecto del total de     adoptantes.
c.    Cu�l fue el c�digo del animal menos adoptado, entre los que s� fueron adoptados.   Puede haber m�s de uno, mostrarlos a todos. (Funci�n).
d.    Indicar cu�l es el promedio de animales adoptados por persona (de las personas que s� adoptaron).
e.  Informar los c�digos de los adoptantes que desean volver a adoptar mascotas y la cantidad de adoptantes que no quieren repetir la experiencia.*/
#include <stdio.h>

int LimiteInferior(int);
int LeerYValidar(int,int);

int main()
{   int cod_animal,cod_adoptante;
    printf("\nIngrese codigo del animal adoptado:");
    cod_animal=LeerYValidar(101,110);
    printf("\nIngrese codigo del adoptante:");
    cod_adoptante=LimiteInferior(0);
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


