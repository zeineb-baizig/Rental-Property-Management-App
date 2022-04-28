#include <stdio.h>
#include <stdlib.h>
#include "saisieloc.h"
#include <string.h>
#include <time.h>
#include <ctype.h>


// control entier
int verif_int(int x)
{
    char chaine[20];
    int i=0;
    itoa(x,chaine,10);
    while(chaine[i]!='\0')
    {
        if (!((chaine[i]<'9')&&(chaine[i]>'0')))
        {
            return 0;
        }
        else
        {
            i++;
        }
    }
    return 1;
}

      // comparer deux dates
  int compare(date d1, date d2)
    { if (d1.annee>d2.annee)
        {

         return 1 ;}
      else if
            (d1.annee<d2.annee)
           {

            return -1;}
      else
        {if (d1.mois>d2.mois)
            {
               return 1;}
        else if (d1.mois<d2.mois)
           {return -1;}
        else
        {
            if (d1.jour>d2.jour )
                {return 1;}
            else if  (d1.jour<d2.jour)
                {return -1;}
            else
                {return 0;}
        }


    }
    }

// verification de la date
   int bissextile(int annee)

     {  if ((annee%4)==0)
           return 1;
        if ((annee%100)==0)
            return 0;
        if((annee%400)==0)
            return 1;
        return 0;
      }
   int cntrl_date(int jour , int mois, int annee)
      {   if ((jour>31)||(jour<1))
                return 0;
          if ((mois>12)||(mois<1))
                 return 0;
          switch(mois)
            {
            case 1:
                {
                    if (jour<=31)
                       {

                        return 1 ;
                         }
                } break;
            case 2:
                {
                    if ((bissextile(annee))&&(jour<=29))
                       return 1;
                    else if ((bissextile(annee)==0)&&(jour<=28))
                        return 1;

                }break;
            case 3:
                {
                    if (jour<=31)
                        return 1;
                    else
                        return 0;

                }break;
            case 4:
                {
                     if (jour<=30)
                        return 1;
                     else
                        return 0;

                }break;
            case 5:
                {
                     if(jour<=31)
                        return 1;
                     else
                        return 0;
                } break;
            case 6:
                 {
                     if(jour<=30)
                        return 1;
                     else
                        return 0;
                } break;
            case 7:
                 {
                     if(jour<=31)
                        return 1;
                     else
                        return 0;
                } break;
            case 8 :
                 {
                     if(jour<=31)
                        return 1;
                     else
                        return 0;
                } break;
            case 9:
                 {
                     if(jour<=30)
                        return 1;
                     else
                        return 0;
                } break;
            case 10:
                 {
                     if(jour<=31)
                        return 1;
                     else
                        return 0;
                } break;
            case 11:
                 {
                     if(jour<=30)
                        return 1;
                     else
                        return 0;
                } break;
            case 12:
                 {
                     if(jour<=31)
                        return 1;
                     else
                        return 0;
                } break;



            }
      }






  //verfication d'une chaine
int verif (char ch[])
{
    int i, test=1;
    for (i=0;i<(strlen(ch));i++)
        {  if (!(((ch[i]>='a')&&(ch[i]<='z'))||((ch[i]>='A')&&(ch[i]<='Z'))))
            {
             test=0;
             break;
            }
        }
    return test;

   }

//Saisie de location
  location saisir_loc()
  {
       location loc ;
     time_t x =time(NULL);
     struct tm* date_sys=localtime(&x);



       do
         {

            printf("\n");
            printf(" ** Donner le nom du locataire **                          \n");
            scanf("%s",loc.nom);
         }while(verif(loc.nom)==0);

        do
          {
              printf("\n-----------------------------------------------------  \n");
              printf(" ** Donner le prenom du locataire **                     \n");
              scanf("%s",loc.prenom);
           } while (verif(loc.prenom)==0);
       do
        {
            printf("\n-------------------------------------------------------  \n");
            printf(" ** Donner l'identifiant  du location **\n");
          scanf("%d",&loc.identifiant);
        }while(verif_int(loc.identifiant)==0);
       do
       {
        printf("\n-----------------------------------------------------------  \n");
        printf (" ** Donner la date de debut de location **                    \n" );
        scanf("%i %i %i",&loc.debut_loc.jour,&loc.debut_loc.mois,&loc.debut_loc.annee);

       }while((loc.debut_loc.annee<(date_sys->tm_year+1900))||(loc.debut_loc.mois<(date_sys->tm_mon+1))||(loc.debut_loc.jour<(date_sys->tm_mday)));
       do
          {
            printf("\n-------------------------------------------------------  \n");
            printf (" ** Donner la date de fin  de location **\n" );
            scanf("%i %i %i", &loc.fin_loc.jour ,&loc.fin_loc.mois, &loc.fin_loc.annee );
          }while((compare(loc.fin_loc,loc.debut_loc)==0) || (compare(loc.fin_loc,loc.debut_loc)==-1));
       do
        {   printf("\n-------------------------------------------------------  \n");
            printf(" ** Donner l'identifiant de l'appartement **\n ");
            scanf("%i", &loc.appart_loue.id);}
       while (verif_int(loc.appart_loue.id)==0);
       do
        {   printf("\n-------------------------------------------------------  \n");
            printf(" ** Donner la surface **\n");
            scanf("%f",&loc.appart_loue.surface);
        }while (loc.appart_loue.surface<0);
       printf("\n------------------------------------------------------------  \n");
       printf(" ** Saisir une description **\n ");
       scanf("%s",loc.appart_loue.description);

       return loc;
  }
 // affichage d'une location
void afficher_loc(location loc1)
    {
        printf("\n");
        printf("  .                                                                                      \n");
        printf("  .        * Identifiant de la location : %d                                             \n",loc1.identifiant);
        printf("  .                                                                                      \n");
        printf("  .        * Locataire : %s | %s                                                         \n",loc1.nom,loc1.prenom);
        printf("  .                                                                                      \n");
        printf("  .        * Date de début de location :  %d / %d / %d                                   \n",loc1.debut_loc.jour,loc1.debut_loc.mois,loc1.debut_loc.annee);
        printf("  .                                                                                      \n");
        printf("  .        * Date de fin de location :    %d / %d / %d                                   \n",loc1.fin_loc.jour,loc1.fin_loc.mois,loc1.fin_loc.annee);
        printf("  .                                                                                      \n");
        printf("  .        * Identifiant de l'appartement :  %d                                          \n",loc1.appart_loue.id);
        printf("  .                                                                                      \n");
        printf("  .        * Surface de l'appartement : %f                                               \n",loc1.appart_loue.surface);
        printf("  .                                                                                      \n");
        printf("  .        * Description de l'appartement : %s                                           \n",loc1.appart_loue.description);
        printf("  .                                                                                      \n");
        printf("\n");

    }
    // rechrcher toutes les locations d'un appartement donné
void   rechercher_loc(appartement B, location fiche [],int N)
         { int i , vrai=0 ;
         Color(15,5);
          printf("\n");
          printf(".......................................................................\n");
          printf(". Veuillez donner l'identifiant  de l'appartement que vous recherchez .\n");
          printf(".......................................................................\n");
          printf("\n");
          scanf("%i",&B.id);


          for (i=0;i<N;i++)
           {
               if (B.id==fiche[i].appart_loue.id)
                 {

                    afficher_loc(fiche[i]);
                    vrai=1; }


           }
          if (vrai==0)
          {
              printf("\n");
              printf(" ********* L'appartement n'existe pas ********* \n");
              printf("\n");
          }
}
//la mise a jour
void up_date (location fiche[],int N)
          {
            int choix,i,id_loc,test=1;
            time_t x =time(NULL);
            struct tm* date_sys=localtime(&x);
            printf("\n");
            printf("...........................Modifier....................................\n");
            printf(".                                                                     .\n");
            printf(".    Donner l'identifiant de location que vous souhaitez modifier.    .\n");
            printf(".......................................................................\n");
            printf("\n");
            scanf("%d",&id_loc);
            for (i=0;i<N;i++)
             {
                 if (fiche[i].identifiant!=id_loc)
                    test=0;
                 else   if (fiche[i].identifiant==id_loc)
                    {test=1;break;}
             }
            if (test==0)
            {printf(" ********* La location n'existe pas *********  \n");}
            printf("\n");
            printf("...............................................................................\n");
            printf(".        -1-  Taper 1 si vous voulez changer le nom                           .\n");
            printf(".        -2-  Taper 2 si vous voulez changer le prenom                        .\n");
            printf(".        -3-  Taper 3 si vous voulez changer l'identifiant de la location     .\n");
            printf(".        -4-  Taper 4 si vous voulez changer la date de debut de location     .\n");
            printf(".        -5-  Taper 5 si vous voulez changer la date de fin du location       .\n");
            printf(".        -6-  Taper 6 si vous voulez changer  id de l'appartement             .\n");
            printf(".        -7-  Taper 7 si vous voulez changer  la surface  de l'appartement    .\n");
            printf(".        -8-  Taper 8 si vous voulez changer  description  de l'appartement   .\n");
            printf("...............................................................................\n");
            printf("\n");
            scanf("%i", &choix);
            switch (choix)
              { case 1 :
                  do
                  {
                    printf("\n");
                    printf(" ___Donner le nouveau nom___ \n ");
                    printf("\n");
                    scanf("%s",fiche[i].nom);
                  }while(verif(fiche[i].nom)==0);
                   break;
                case 2 :
                   do
                   {
                       printf("\n");
                       printf(" ___Donner le nouveau prénom___ \n ");
                       printf("\n");
                       scanf("%s",fiche[i].prenom);
                   }while(verif(fiche[i].prenom)==0);
                     break ;
                case 3 :
                     do
                     {
                         printf("\n");
                         printf(" ___Donner le nouveau identifiant de la location___ \n ");
                         printf("\n");
                         scanf("%d",&fiche[i].identifiant);
                     }while(verif_int(fiche[i].identifiant)==0);
                         break ;
                case 4 :
                    do
                    {
                        printf("\n");
                        printf(" ___Donner la nouvelle date de debut___ \n ");
                        printf("\n");
                        scanf("%i %i %i",&fiche[i].debut_loc.jour ,&fiche[i].debut_loc.mois, &fiche[i].debut_loc.annee);
                    }while ((fiche[i].debut_loc.annee<(date_sys->tm_year+1900))||(fiche[i].debut_loc.mois<(date_sys->tm_mon+1))||(fiche[i].debut_loc.jour<date_sys->tm_mday));
                    break ;
                case 5 :
                    do
                    {
                        printf("\n");
                        printf(" ___Donner la nouvelle date de fin___ \n ");
                        printf("\n");
                        scanf("%i %i %i ", &fiche[i].fin_loc.jour,&fiche[i].fin_loc.mois,&fiche[i].fin_loc.annee );
                    }while((compare(fiche[i].fin_loc,fiche[i].debut_loc)==0)||(compare(fiche[i].fin_loc,fiche[i].debut_loc)==-1));
                    break ;
                case 6 :
                    do
                    {
                        printf("\n");
                        printf(" ___Donner le nouveau identifiant de l'appartement___ \n ");
                        printf("\n");
                        scanf("%i",&fiche[i].appart_loue.id);
                    }while(verif_int(fiche[i].appart_loue.id)==0);
                    break ;
                case 7 :
                    do
                    {
                        printf("\n");
                        printf(" ___Donner la nouvelle surface___ \n");
                        printf("\n");
                        scanf("%f",&fiche[i].appart_loue.surface);
                    }while (fiche[i].appart_loue.surface<0);
                     break ;
                case 8 :

                    printf("\n");
                    printf(" ___Donner la nouvelle description___ \n");
                    printf("\n");
                    scanf("%s",fiche[i].appart_loue.description);
                     break ;
                default :
                    printf("\n");
                    printf(" ********* Veuillez saisir un choix correcte! *********\n ");
                    printf("\n");

              }
               printf("\n");
               printf("\n");
               printf(" ******* La location apres modification est *******");
               printf("\n");
               printf("\n");
               afficher_loc(fiche[i]);





           }




           // la suppression
            int supprimer_loc(location fiche [],int N, int id_loc )
            {
               int i=0,x=0 ;
               for (i=0 ;i<N;i++)

                  { if (fiche[i].identifiant==id_loc)
                      {
                          fiche[i]=fiche[i+1];
                          x++;
                      }
                  }

               if (x==0)
               {
                   printf("la location n'existe pas ");
               }
               else
               {
                  N=N-1;

               }
               return N;
               }







