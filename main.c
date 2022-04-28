#include <stdio.h>
#include <stdlib.h>
#include "saisieloc.h"
#include <windows.h>

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


int main()
{   location fiche[100];
    appartement A  ;
    int  choix,c,i,supp, id_loc;

    int N=0;
    FILE  *F;
    F= fopen("fiche.txt","rt");
    if (F==NULL)
    {
        Color(0,2);
        printf("\n");
        printf("\n");
        printf("                      ***  Le fichier n'existe pas  ***\n");
        printf("\n");
        printf("********************************************************************************\n");
        printf("\n");
    }
    else
    {
        while (!feof(F))
           {

            fscanf(F,"%s %s %d %d %d %d %d %d %d %d %f %s\n",fiche[N].nom,fiche[N].prenom,&fiche[N].identifiant,&fiche[N].debut_loc.jour,&fiche[N].debut_loc.mois,
                   &fiche[N].debut_loc.annee,&fiche[N].fin_loc.jour,&fiche[N].fin_loc.mois,&fiche[N].fin_loc.annee,&fiche[N].appart_loue.id,&fiche[N].appart_loue.surface,
                   fiche[N].appart_loue.description);
            N++; }
    }
    fclose(F);

    while (1)
    {
    printf("\n");
    Color(15,8);
    printf("                      _________Gerer les locations immobilieres_________             \n");
    printf("\n");
    printf("\n");
    printf("        .....................................Menu....................................\n");
    printf("        .                                                                           .\n");
    printf("        .       -1- Taper 1: Saisir une location                                    .\n");
    printf("        .                                                                           .\n");
    printf("        .       -2- Taper 2: Afficher la fiche de location                          .\n");
    printf("        .                                                                           .\n");
    printf("        .       -3- Taper 3: Rechercher un appartement dans la fiche de location    .\n");
    printf("        .                                                                           .\n");
    printf("        .       -4- Taper 4: Supprimer une location  de la fiche                    .\n");
    printf("        .                                                                           .\n");
    printf("        .       -5- Taper 5: Modifier une location                                  .\n");
    printf("        .                                                                           .\n");
    printf("        .       -6- Taper 0: Pour quitter                                           .\n");
    printf("        .                                                                           .\n");
    printf("        .............................................................................\n");
    printf("\n");
    scanf("%i",&c);
    switch(c)
        {
        case 1:
            do
            {fiche[N]=saisir_loc();
            N++;
            Color(0,14);
            printf("\n");
            printf("............................................................\n");
            printf(". Voulez-vous continuer la saisie? Taper 1 si oui, 0 sinon .\n");
            printf("............................................................\n");
            printf("\n");
            scanf("%i",&choix);
            }while ((N<100)&&(choix==1));
            break;
        case 2:
            for (i=0;i<N;i++)
            {
                Color(0,4);
                afficher_loc(fiche[i]);
            }
            break;
        case 3 :
            {

            rechercher_loc( A , fiche , N);

             }break ;
        case 4:
            {
               printf("\n");
               Color(0,12);
               printf(".................................................\n");
               printf(". Donner l'identifiant  de location a supprimer .\n");
               printf(".................................................\n");
               printf("\n");
               scanf("%d",&id_loc);
               supp=supprimer_loc(fiche,N,id_loc);
               printf("\n");
               Color(0,14);
               printf("...................................................\n");
               printf(". Le nombre de locations apres suppression est %d .\n",supp);
               printf("...................................................\n");
               printf("\n");
            } break;
        case 5 :
           {
             up_date (fiche, N ) ;
           }break;
        case 0:
            { F=fopen("fiche.txt","wt");
            for (i=0; i<N;i++)
            {

             fprintf(F,"%s %s %d %d %d %d %d %d %d %f %s\n",fiche[i].nom,fiche[i].prenom,fiche[i].debut_loc.jour,fiche[i].debut_loc.mois,
                     fiche[i].debut_loc.annee,fiche[i].fin_loc.jour,fiche[i].fin_loc.mois,fiche[i].fin_loc.annee,fiche[i].appart_loue.id,fiche[i].appart_loue.surface,
                     fiche[i].appart_loue.description);
             }
             fclose(F);
             exit(0) ;
            }

} }
return 0;

}
