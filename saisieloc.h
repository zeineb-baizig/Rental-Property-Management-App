#ifndef SAISIELOC_H_INCLUDED
#define SAISIELOC_H_INCLUDED
typedef struct
{ int jour ;
int mois ;
int annee ;


} date ;

 typedef struct
 { int id ;
 float surface ;
 char description [200] ;

 } appartement  ;


typedef struct
{ char nom [20];
  char prenom [20];
  int identifiant ;
  date debut_loc;
  date fin_loc ;
  appartement  appart_loue ;

} location ;


location saisir_loc () ;
void afficher_loc(location loc1);
void  rechercher_loc( appartement A, location fiche [], int N  );
int supprimer_loc(location fiche [],int N, int indice ) ;
void up_date(location fiche [], int N);



#endif // SAISIELOC_H_INCLUDED
