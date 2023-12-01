#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define null 0
typedef struct list_horizontale {
        char information;
        struct list_horizontale *suivant;
}list_horizontale;

typedef struct list_vert {
        struct list_horizontale *listH;
        struct list_vert *suivant;
}list_vert;

struct list_horizontale *create_list_horizontale()
{
    struct list_horizontale *P;
    struct list_horizontale *tete;
    struct list_horizontale *prec;
    int  letter;
    int i=0;
    P=(struct list_horizontale*)malloc(sizeof(list_horizontale));
    tete=P;
    prec=P;
    printf("\n Donner la taile de la list horizontale pour creation : \t ");
    scanf("%d",&letter);
    if (letter == 1)
    {
        tete->suivant=null;
    }
    for(i=1;i<=(letter-1);i++)
    {
       P=(struct list_horizontale*)malloc(sizeof(list_horizontale));
       prec->suivant=P;
       prec=P;
       prec->suivant=null;
    }
    printf("\n la creation de list horz is terminer ");
    return tete;

};
struct list_vert *create_list_vert()
{
    struct list_vert *P;
    struct list_vert *tete;
    struct list_vert *prec;
    int  letter;
    int i=0;
    P=(struct list_vert*)malloc(sizeof(list_vert));
    tete=P;
    prec=P;
    printf("\n Donner la taile de la list verticalle  pour creation : \t ");
    scanf("%d",&letter);
    if (letter == 1)
    {
        tete->suivant=null;
    }
    for(i=1;i<=(letter-1);i++)
    {
       P=(struct list_vert*)malloc(sizeof(list_vert));
       prec->suivant=P;
       prec=P;
       prec->suivant=null;
       printf("\n -------------------- i =%d",i);
    }
    printf("\n la creation de list verticale est terminer ");

    return tete;

};
void input_info(struct list_horizontale *tete)
{
    struct list_horizontale *p;
    printf("\n tete = %d",tete);
    p=tete;
    while(p != null)
    {
        printf("\n donnner character : \t ");
        scanf("%s",&p->information);
        p=p->suivant;
    }
    printf("\n ------ les character sont donner------ \n ");
}

void affichage(struct list_horizontale *tete)
{

    printf("\n ");
    struct list_horizontale *p;
    p=tete;

    while (p != null)
    {
        printf("[%c] ",p->information);
        p=p->suivant;
    }
    printf("\n");
}

void affichage_vert(struct list_vert *tete)
{

    printf("\n ");
    struct list_vert *p;
    p=tete;

    while (p != null)
    {
        printf("\n-----");
        printf("[%d]  [%d] \n ",p,p->suivant);
        affichage(p->listH);
        p=p->suivant;
        printf("------\n ");
    }
    printf("\n");
}
int taille_list(struct list_horizontale *tete)
{

    struct list_horizontale *p;
    p=tete;
    int t=0;
    while(p != null)
    {
        t=t+1;
        p=p->suivant;
    }
    return t;
}
bool sous_list(struct list_horizontale *tete_1,struct list_horizontale *tete_2,int taille1,int taille2)
{
    int somme=0;
    struct list_horizontale *p1=tete_1;
    struct list_horizontale *p2=tete_2;
    struct list_horizontale *p3;
    if(taille1==taille2)
    {

        while(p1 !=null)
        {
            if(p1->information == p2->information)
            {
                somme=somme+1;
            }
            p1=p1->suivant;
            p2=p2->suivant;

        }
        if(somme==taille1)
        {
            return true;
        }
        if(somme != taille1)
        {
            return false;
        }
    }
    if(taille1>taille2)
    {
        return false;
    }
    if(taille1<taille2)
    {

        p2=tete_2;
        p1=tete_1;
        while(p2 != null)
        {
            somme=0;

            p3=p2;
            p1=tete_1;
            while((p1 != null) && (p3!=null))
            {
                if(p1->information == p3->information)
                {
                    somme=somme+1;
                }
                p1=p1->suivant;
                p3=p3->suivant;
            }

            if(somme == taille1)
            {
                return true;
            }
            if(somme != taille1)
            {
                p2=p2->suivant;
            }
        }
        return false;

    }
}
struct list_horizontale *suprimer_list(struct list_horizontale *tete,struct list_horizontale *psup)
{
    struct list_horizontale *prec;
    struct list_horizontale *p;
    bool treuve=false;
    prec=tete;
    p=tete;
    if(tete == psup)
    {

        p=tete;
        tete=tete->suivant;
        free(p);
        return tete;
    }
    else
    {
        treuve=false;
        prec=tete;
        p=tete->suivant;
        while((p!=null) && (treuve==false))
        {
            if(p==psup)
            {
                treuve=true;
            }
            else
            {
                prec=p;
                p=p->suivant;
            }
        }
        if((treuve==true) && (p->suivant!=null))
        {
            prec->suivant=p->suivant;
            free(p);
            return tete;
        }
        if((treuve==true && p->suivant==null))
        {
            prec->suivant=null;
            free(p);
            return tete;
        }
        }
}
int main()
{
    FILE *pfile;
    struct list_vert *tete_vert;
    int taille_1;
    int taille_2;
    int taille_vert;
    int i;
    struct list_vert *c;
    struct list_vert *p1;
    struct list_vert *p2;
    bool Baa=false;
    tete_vert=create_list_vert();
    taille_vert=taille_list(tete_vert);
    printf("\n taile vert = %d ",taille_vert);
    c=tete_vert;
   for(i=1;i<=(taille_vert);i++)
   {
       printf("\n ---------------- %d",c);
       c->listH=create_list_horizontale();
       input_info(c->listH);
       affichage(c->listH);
       c=c->suivant;

   }
    affichage_vert(tete_vert);
    p1=tete_vert;
    p2=tete_vert;
    printf("\n");
    while(p1 != null && p2!=null)
    {
        while(p2 != null && p1!=null)
        {
            if(p1==p2)
            {
                p2=p2->suivant;
            }
            else {
                taille_1=taille_list(p1->listH);
                taille_2=taille_list(p2->listH);
                Baa=sous_list(p2->listH,p1->listH,taille_2,taille_1);

                if( Baa == true)
                {
                   tete_vert=suprimer_list(tete_vert,p2);
                   p1=tete_vert;
                   p2=tete_vert;

                }
                if (Baa == false)
                {
                    p2=p2->suivant;
                }
            }

        }
        p1=p1->suivant;
        p2=tete_vert;
    }
    printf("\n The new structure ");
    affichage_vert(tete_vert);
    pfile=fopen("les_information.txt","w");
    struct list_horizontale *ph;
    struct list_vert *pv;
    int posh=0;
    pv=tete_vert;
    int nbchar=0;
    while(pv != null)
    {
        posh=posh+1;
        ph=pv->listH;
        nbchar=taille_list(ph);
        fprintf(pfile,"postions vertical : %d -- noubmre de character : %d ----",posh,nbchar);
        while( ph != null)
        {

            fprintf(pfile,"[%c]-",ph->information);
            ph=ph->suivant;
        }
        fprintf(pfile,"\n");
        pv=pv->suivant;
    }



    return 0;
}
