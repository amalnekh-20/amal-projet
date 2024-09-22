#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {    //structure d adresse
	int num ;
	char ville[20];
}Adresse;
typedef struct{   //structure de date de naissance
	int annee ;
	int mois;
	int jour;
}date;
typedef struct etudiant {      //declaration de la structure etudiant
	char Nom[25];
	char Prenom[25];
	int CNE;
	date dt ;
    Adresse  Ad ;
}etd;
 /*fonction de saisie des informations de chaque etudiant dans la liste */
    etd * saisi (int taille){
    	  	etd * LEtd ;
        LEtd = (etd*) malloc(taille  * sizeof(etd));//declaration d un tableau dynamique
        int i ;
        	for(i=0; i<taille; i++){

         printf("\n\n _le %d etudiant______________\n",i+1);
		 printf("\n\tNom:");
		 scanf("%s",&LEtd[i].Nom);
		 printf("\n\tPrenom :");
		 scanf("%s",&LEtd[i].Prenom);
		// gets(LEtd[i].Nom_Prenom);
		 printf("\tCNE(prt.num) :");
		 scanf("%d",&LEtd[i].CNE);
		 printf("\tdate naissance : ");
		do{
		   printf("\n \t\t -> jour :");
		  scanf("\t%d",&LEtd[i].dt.jour);
		  if(LEtd[i].dt.jour<0 || LEtd[i].dt.jour>31){
		  	printf("\tdonnez un nombre raisonable!!!");
		  }
		  }while(LEtd[i].dt.jour<0 || LEtd[i].dt.jour>31);
			do{
		 printf("\n\t\t -> mois:");
		 scanf("\t%d",&LEtd[i].dt.mois);
		 if(LEtd[i].dt.mois<0 || LEtd[i].dt.mois>12){
		  	printf("\tdonnez un nombre raisonable!!!");
		  }
	}while(LEtd[i].dt.mois<0 || LEtd[i].dt.mois>12);
		 printf("\n \t\t -> annee:");
		 scanf("\t%d",&LEtd[i].dt.annee);
		 printf("\n\tAdresse \n\t\t -> num  :");
		 scanf("%d",&LEtd[i].Ad.num);
		 printf("\n\t\t -> Ville :");
		 scanf("%s",&LEtd[i].Ad.ville);
	}
	return LEtd;


}
    /* fonctions d affichage de la liste des etudiants */
     void Afficher( etd *LEtd, int taille){
	int i;

	printf("\n|_______La liste des etudiants est la suivante_______________|\n");
	        for(i=0; i<taille; i++){
	        	printf("\n\n __le %d etudiant_________\n",i+1);
	        	printf("\n\n\tNom \t:%s ",LEtd[i].Nom);
	        	printf("\n\tPrenom \t:%s ",LEtd[i].Prenom);
	         	printf("\n\tCNE :%d",LEtd[i].CNE);
	            printf("\n\tdate de naissance :%d/%d/%d",LEtd[i].dt.jour,LEtd[i].dt.mois,LEtd[i].dt.annee);
	        	printf("\n\tAdresse <num> : %d \n\tAdresse <Ville> : %s",(LEtd+i)->Ad.num, (LEtd+i)->Ad.ville);
	}
}
//Fonction Menu a choix multiple
        int menu(){
	    int c;
          do {  // boucle (do while) pour assurer la recupuration du choix

        printf("\n\n\n-> Choisissez une operation :\n");
		printf("   1 : Voulez-vous afficher la liste des etdudiants?\n");
		printf("   2 : Voulez-vous afficher un etudiant dont vous connaissez le CNE?\n");
		printf("   3 : Voulez-vous supprimer un etudiant par CNE?\n");
		printf("   4 : Voulez-vous afficher un etudiant dont vous connaissez le nom ?\n");
		printf("   5 : Voulez-vous faire l'echange entre deux etudiants ?\n");
		printf("   6 : Voulez-vous trier la liste des etdudiants par cne?\n");
		printf("   7 : Voulez-vous trier la liste des etdudiants par nom?\n");
		printf("   8 : recherche par dichotomie  ?\n");
		printf("   9 : Voulez-vous enregiter votre dans un fichier ?\n");
		printf("   0 : Fin du programme?\n");
		printf("\n\n\tVotre choix => ");
		scanf("%d",&c);


		if (c < 0 || c > 9) {
			printf ("\n le nombre est hors l intervalle \n");
  }
	}while(c< 0 || c > 9);
	return c;
	}
   //fonctions qui affichage les informations d un etudiant par son cne
 void afficheparCNE(etd *LEtd, int cne, int taille ){
    	int i;int a = 0;
    	for(i=0;i<taille;i++){
    		if( LEtd[i].CNE == cne){
    			a = 1 ;
    	printf("\n\n\tNom\t:%s",LEtd[i].Nom);
    	printf("\n\n\tPrenom \t:%s ",LEtd[i].Prenom);
		printf("\n\tCNE\t:%d",LEtd[i].CNE);
		printf("\n\tdate de naissance :%d/%d/%d",LEtd[i].dt.jour,LEtd[i].dt.mois,LEtd[i].dt.annee);
		printf("\n\tAdresse -> num : %d,\tVille : %s",(LEtd+i)->Ad.num, (LEtd+i)->Ad.ville);

		}
	}
	if(a == 0){
		printf("ce etudiant n'existent pas !!!");
	}

}
	//fonctions qui supprimme un etudiant par sont cne
void SupprimerEtdParCNE(etd *LEtd, int cne, int *taille){
	int  i=0,j;

	    while(LEtd[i].CNE!=cne)
	      i++;
        	for(j=i; j<*taille-1; j++){
	         	LEtd[j]=LEtd[j+1];
	}
	             (*taille)--;
    Afficher(LEtd,*taille);
}
//fonctions d echange de deux etudiants
  void echange_Etd(int i, int j, etd* LEtd){

	etd tmp;
	tmp= *(LEtd+i);
	*(LEtd+i)=*(LEtd+j);
	*(LEtd+j)=tmp;


}
//fonction qui affiche les infos d etudiant par son nom
   void Affiche_PN(etd*LEtd,char T[50],int taille){
   	    	int i=0;
	while(strcmp(LEtd[i].Nom,T)!=0) i++;     // strcmp fonction qui faire la comparaison entre deux chaine de caractere
	if(i>taille) printf("\n\n\n\n____L'etudiant %s n existe pas dans la liste");
	else{
		printf("\n\n\tNom\t:%s",LEtd[i].Nom);
    	printf("\n\n\tPrenom \t:%s ",LEtd[i].Prenom);
		printf("\n\tCNE\t:%d",LEtd[i].CNE);
		printf("\n\tdate de naissance :%d/%d/%d",LEtd[i].dt.jour,LEtd[i].dt.mois,LEtd[i].dt.annee);
		printf("\n\tAdresse -> num : %d,\tVille : %s",(LEtd+i)->Ad.num, (LEtd+i)->Ad.ville);
	}
}
//tri par selection
  void Tri (etd *LEtd, int taille) {

    int i, j, min ;
	    for (i = 0 ; i < taille-1 ; i++) {
		     min = i ;
		       for ( j = i+1 ; j < taille ; j++ ){
			      if ( strcmp(LEtd[j].Nom , LEtd[min].Nom) < 0 )
			          min = j ;
		}
		if (min != i)  {  /* faire des �changes*/
			echange_Etd(i, min,  LEtd);
		}
	}
}    // fonctions qui trie le tablau par cne en ordre croissant
 void tri_Par_CNE(etd *LEtd , int taille){
 	int i ,j;
 	for(i=0;i<taille-1;i++){
 		for(j=i+1;j<taille;j++){
 			if(LEtd[j].CNE<LEtd[i].CNE)
 			echange_Etd(i,j,LEtd);
		 }
	 }
 }
 /* Recherche dichotomique dans un tableau tri */
etd * ChercherDich(etd *LEtd, int nbPers) {
	char aChercher[21] ;
	int  mini, maxi, milieu, trouve ;
	int  compare, longueur ;

	printf("\n\n>>>>>>>     RECHERCHE DICHOTOMIQUE     <<<<<<<<<\n");

	printf("\n\n>>>>>>>     Entrez le nom de l'etudiant recherche  >>\t");
	fflush(stdin);
	gets(aChercher); /* get string = lire une chaine */

	longueur = strlen(aChercher) ;

	mini = 0           ;
	maxi = nbPers - 1 ;
	trouve = 0 ; /* on ne trouve pas encore */
	while (!trouve && mini <= maxi) {
		milieu = (mini + maxi) / 2 ;
		compare = strnicmp(aChercher, LEtd[milieu].Nom, longueur);
		if ( compare < 0 )
			maxi = milieu - 1 ;
		else  if (compare > 0)
			mini = milieu + 1 ;
		else trouve = 1 ;
	}
	if (!trouve)
		printf("Desole, on ne trouve pas %s\n", aChercher);

	else {
		return (LEtd+milieu);
	}
}
void enregistrer(etd*LEtd,int taille,char*liste){     // fonction d'enregitrement dans un fichier
    int i;
    FILE*p=NULL;
	p=fopen("liste.doc","w");
     if(p == NULL){
    	printf("ce fichier n'existent pas");
	}
	else{
	   for(i=0;i<taille;i++){
    fprintf(p,"\n\n __le %d etudiant_________\n",i+1);
	fprintf(p,"\n\n\tNom \t:%s ",LEtd[i].Nom);
	fprintf(p,"\n\n\tPrenom \t:%s ",LEtd[i].Prenom);
	fprintf(p,"\n\tCNE :%d",LEtd[i].CNE);
    fprintf(p,"\n\tdate de naissance :%d/%d/%d",LEtd[i].dt.jour,LEtd[i].dt.mois,LEtd[i].dt.annee);
	fprintf(p,"\n\tAdresse <num> : %d \n\tAdresse <Ville> : %s",(LEtd+i)->Ad.num, (LEtd+i)->Ad.ville);

}
fclose(p);
}
}
//main (fonctions principale)

   int main(){
   	int n ;
   	char PN[50],c;
   	char* liste;
   	int i , j ;
   	int x;
	 etd *lt,*pRech;
	 int cne ;


	do{

	printf("Donnez la taille de votre liste  ==> ");
   	scanf("%d",&n);
   	if(n==0){
   		printf("\nVeuillez donner unne taille raisonable!!!!\n\n");
	}

    }while(n==0);


    lt = saisi (n);// lt est un pointeur sur le tableau LEtd
 	 do{
   		x= menu();
   		switch(x){	 // (switch/case) selon le choix recupere dans la fonction menu

   		case 1 : Afficher(lt,n);
   		    break;

	    case 2 : printf("donnez le cne de l'etudiant :");
   	             scanf("%d",&cne);
   	             afficheparCNE(lt,cne,n);
			break;

		case 3 :printf("donnez le cne d'etudiant :");
		        scanf("%d",&cne);
		       SupprimerEtdParCNE(lt , cne , &n);
		    break;
		case 4 :printf("donnez le nom  d'etudiants\n");
		        scanf("%s",&PN);
		        Affiche_PN(lt,PN,n);
		    break;
		case 5 :
			    printf("ATTENTION ! : la liste commence par l'indice  0 !!! \n\n ");
				printf("donnez le numero du 1er  etudiants: ");
				scanf("%d",&i);                                     // le tableau commence par l indice 0!!!!
				printf("donnez le numero du 2eme etudiants: ");
				scanf("%d",&j);
				echange_Etd(i,j,lt);
				Afficher(lt,n);
			break;
		case 6 :
			    printf("\n\n\tTri du tableau par ordre croisant !!!!\n\n");
		        tri_Par_CNE(lt,n);
		        Afficher(lt,n);
		        break;
		 case 7 :
		        Tri(lt,n);
		        Afficher(lt,n);
		        break;
		case 8 :
		    	do{
					pRech = ChercherDich(lt, n);
					printf(">>>> Voici ses informations :\n\n");
					printf("\n\n\tNom\t:%s",pRech->Nom);
					printf("\n\n\tPrenom \t:%s ",pRech ->Prenom);
					printf("\n\tCNE\t:%d",pRech->CNE);
	                printf("\n\tdate de naissance :%d/%d/%d",pRech ->dt.jour,pRech->dt.mois,pRech->dt.annee);
	                printf("\n\tAdresse -> num : %d,\tVille : %s",pRech->Ad.num, pRech->Ad.ville);
					printf("\n\n>>>> Recherche d'un autre etudiant o/n:\n\n");
				}while ( c=getchar()== 'o');
			     break;
		case 9 :
                  enregistrer(lt,n,liste);
			}
	 }while(x!=0);

   return 0 ;
   }
