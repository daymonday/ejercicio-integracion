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
b.    Porcentaje de cada experiencia de adoptar una mascota respecto del total de adoptantes.
c.    Cuál fue el código del animal menos adoptado, entre los que sí fueron adoptados.   Puede haber más de uno, mostrarlos a todos. (Función).
d.    Indicar cuál es el promedio de animales adoptados por persona (de las personas que sí adoptaron).
e.  Informar los códigos de los adoptantes que desean volver a adoptar mascotas y la cantidad de adoptantes que no quieren repetir la experiencia.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int LimiteInferior(int);
int LeerYValidar(int,int);
int Rango(int, int, int);
char OpcionesLetras(char,char,char,char);
int BuscarMinimo(int ce, int vector[]);
void MostrarVector(int v[],int ce, int);

int main()
{
    int i=0, cod_animal,cod_adoptante,Cant_animalesAdopt=0,DeseaParticipar,cant_Adoptantes=0;
    int v_codAnimal[10]= {0},v_DeseaParticipar[10]= {0};
    int animalesAdoptTotal=0,cant_NoDeseaParticipar=0,cod_cantMinAdopt=0,Cant_MalaExp=0,Cant_RegExp=0,Cant_BuenaExp=0,Cant_ExcExp=0;
    char valoracion;

    printf("\nIngrese codigo del animal adoptado:");
    cod_animal=Rango(101,110,0);

    while(cod_animal!=0&&cant_Adoptantes<600)
    {
        cant_Adoptantes++;
        printf("\nIngrese codigo del adoptante:");
        cod_adoptante=LimiteInferior(0);

        printf("\nIngrese cantidad de animales adoptadas [MAYOR A 0]:");
        Cant_animalesAdopt=LimiteInferior(0);

        printf("\nIngrese valoracion de la experiencia ['M' Mala, 'R' Regular, 'B' Buena, 'E' Excelente]: ");
        valoracion=OpcionesLetras('M','R','B','E');

        printf("\n¿Desea volver a participar de la experiencia? [1:SI, 2:NO]:");
        DeseaParticipar=LeerYValidar(1,2);

        v_codAnimal[cod_animal-101]=+Cant_animalesAdopt; /*Punto A*/
        animalesAdoptTotal=+Cant_animalesAdopt;

        switch(valoracion) /* Aca si bien podrias hacer un vector para que acumule como contador las exp, el problema es que no podes renombres los indices*/
        {
        case 'M':
            Cant_MalaExp++;
            break;
        case'R':
            Cant_RegExp++;
            break;
        case 'B':
            Cant_BuenaExp++;
            break;
        case'E': Cant_ExcExp++;
                break;
        }



        if(DeseaParticipar==1) /*Punto E*/
        {
            v_DeseaParticipar[i]=cod_adoptante;
        }
        else
        {
            cant_NoDeseaParticipar++;
        }

        i++;

        printf("\nIngrese codigo del animal adoptado:");
        cod_animal=Rango(101,110,0);
    }

    if(cod_animal==0)
    {
        if(cant_Adoptantes>0)
        {
            printf("\n Cantidad de animales adoptados segun codigo:\n"); /*Punto A*/
            MostrarVector(v_codAnimal,10,101);

            printf("\n Porcentaje de cada experiencia de adopcion, en cuanto al total de adoptantes"); /*Punto B*/
            printf("\nMala:%.2f % \tRegular:%.2f % \tBuena:%.2f % \t Excelente:%.2f %\n",((float)Cant_MalaExp/(float)cant_Adoptantes)*100,((float)Cant_MalaExp/(float)cant_Adoptantes)*100,((float)Cant_BuenaExp/(float)cant_Adoptantes)*100,(Cant_ExcExp/cant_Adoptantes)*100);

            cod_cantMinAdopt=BuscarMinimo(10,v_codAnimal); /*Punto C*/

            printf("\nCodigo de los animales con menor cantidad de adopciones:");
           /* MostrarVector();*/
            printf("\n %d ",cod_cantMinAdopt+101);

            printf("\nPromedio de la cantidad de animales adoptados:%.2f",(float)animalesAdoptTotal/(float)cant_Adoptantes); /*Punto D*/

            printf("\n %d Adoptantes no quisieran repetir la experiencia, pero otros si.\n Codigo:\n",cant_NoDeseaParticipar); /* Punto E*/
            MostrarVector(v_DeseaParticipar,(cant_Adoptantes-cant_NoDeseaParticipar),101);
        }
        else
        {
            printf("\nNo se han ingresado datos.");
        }
    }
    system("pause");
    return 0;
}

int LimiteInferior(int lim_inf)
{
    int num;

    do
    {
        scanf("%d",&num);
    }
    while(num<lim_inf);

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

int Rango(int lim_inf, int lim_sup, int fin)
{
    int num;
    do
    {
        scanf("%d",&num);
    }
    while(((num<lim_inf)||(num>lim_sup))&&(num!=fin));

    return num;
}

char OpcionesLetras(char letra1,char letra2,char letra3,char letra4)
{
    char dato;

    do
    {
        scanf("%c",&dato);
        dato=toupper(dato);
        fflush(stdin);
    }
    while(!((dato==letra1)||(dato==letra2)||(dato==letra3)||(dato==letra4)));

    return dato;
}

int BuscarMinimo(int ce, int vector[])
{
    int i, min=vector[0];

    for(i=0; i<ce; i++)
    {
        if(vector[i]<min)
            min=vector[i];
    }

    return min;
}

void MostrarVector(int v[],int ce, int despl)
{
    int i;

    for(i=0; i<ce; i++)
    {
        printf("\n%d\t\t%d\n",i+despl,v[i]);
    }

}
