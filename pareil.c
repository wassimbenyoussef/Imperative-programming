#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"pareil2.c"



/*@ requires : 
  @ assigns : création d'un tableau dont le contenu est modifié au fur et à mesure des commandes que l'on tape
  @ ensures : le jeu est fini
*/
int main()
{
  int i,j,h,l,a,o;
  int score=0;
  int n=0;
  char z;
  char tableau[]={'A','H','X','O'}; /* on crée un tableau composé des 4 lettres précédentes*/
  char** pl;   /* on crée une matrice pl de char */
  printf("sélectionner la hauteur du tableau : ");
  scanf("%d",&h);
  printf("sélectionner la largeur du tableau : ");
  scanf("%d",&l);
  pl=remplissage(h,l);
  for(i=0;i<h;i=i+1)    /* ici on remplit la matrice pl directement avec des lettres aléatoirement */
    {
      
      for(j=0;j<l;j=j+1)
	{	 
	      /*	      srand(time(NULL)); cette fonction servirait à donner un vrai aléatoire mais elle ne fonctionne pas et si on la met dans le code on obtient un tableau avec la meme lettre dans toutes les cases*/
	  pl[i][j]= tableau[rand()%4];/* on met dans chaque case de la matrice une lettre choisie aléatoirement parmi les 4 lettres contenue dans le tableau tableau*/
	    
         }
    }

  affichage(pl,l,h,score);
  while(score<1000)   /* la boucle se fini quand le jeu est terminé, c'est à dire quand toutes les cases du tableau ont disparu*/
    {
      printf("sélection de l'abcsisse : ");
      scanf("%d",&a);
      printf("sélection de l'ordonnée : "); 
      scanf("%d",&o);
      z=pl[h-o-1][a]; /* on stocke la valeur de la case séléctionnée dans une variable pour pouvoir l'utiliser dans la fonction diese*/ 
      /* pl[h-o-1][a]='#';*/
      diese(pl,z,h,l,a,o);
      system("clear");
      affichage(pl,l,h,score);
      score=(n-1)*(n-2)/2;
      char p;
      char buffer[2];
      printf("supprimer le groupe ? y / n : ");
      scanf("%1s",buffer);
      p=buffer[0];
      if(p=='y')
	{
	  for(i=0;i<h;i=i+1)
	    {
	      for(j=0;j<l;j=j+1)
		{
		  if(pl[i][j]=='#')
		    {
		      pl[i][j]=' ';
		      n=n+1;  /* compteur pour le score */
		      
		    } 
		}
	    }
	}
      else if(p=='n')
	{
	  printf(" annulé  \n");
	}
      else 
	{
	  printf(" erreur  \n");
	}
      for(i=0;i<h;i=i+1) /* on effectue la fonction descendre h fois pour etre sur que toutes les cases sont bien descendus et que les trous ont bien tous été bouchés sur toute la hauteur de la matrice*/
	{
	  descendre(&pl,h,l);
	}
      system("clear");
      affichage(pl,l,h,score);	
      fin(pl,score);
    }
  printf("Game over");
  return 0;
}
