#include<stdlib.h>
#include<stdio.h>


/* @ requires : h et l des entiers supérieurs à 0
   @ assigns : ouvre des zones mémoires pour recueillir un tableau
   @ ensure : de la place mémoire a été aloué pour un tableau
*/
char** remplissage(int h, int l )
{
  
  int i;
  char **tab;
  tab=(char**)malloc(h*sizeof(char*));
  for(i=0;i<h;i=i+1)
    {
      tab[i]=(char*)malloc(l*sizeof(char));
    }
  return tab;
}

/* @ requires : un tableau pl, h et l des entiers strictement supérieurs à 0 et score un entier supérieur ou égal à 0
   @ assigns : 
   @ ensure : le tableau est affiché à l'écran
*/ 
void affichage(char** pl, int l, int h, int score)
{
int j,i;
 for(i=0;i<h;i=i+1)
    {
	
	      for(j=0;j<l;j=j+1)
		{ 
		  printf("%c ",pl[i][j]);			    
		}
	      printf("\n");
    }
  for(j=0;j<l;j=j+1)
    {
      printf("- ");
    }
printf("\n score : %d \n",score);
}
/* @requires : un tableau, l'abscisse a>0 , l'ordonnée o>0, la hauteur h>0
   @assigns : modifie le contenu des cases du tableau
   @ensure : le contenu des cases du tableau a pu etre modifié 
*/
void diese(char** pl,char z, int h, int l,int a, int o)
{ 
  if(0<=a-1 && a-1<l && pl[h-o-1][a-1]==z) /* si la case à gauche est la meme que celle séléctionné alors elle devient # puis effectue la fonction diese pour cette case*/
    { 
      pl[h-o-1][a-1]='#';	
      diese(pl,z,h,l,a-1,o);
	
    }
  if(0<=a+1 && a+1<l && pl[h-o-1][a+1]==z) /* si la case à droite est la meme que celle séléctionnée alors elle devient # puis on effectue la fonction diese pour cette case*/
    {
      pl[h-o-1][a+1]='#';
      diese(pl,z,h,l,a+1,o);
	
    }
  if(0<=h-o-2 && h-o-2<h && pl[h-o-2][a]==z)/* si la case en bas est la meme que celle séléctionnée elle devient # puis on effectue la fonction diese pour cette case*/
    {
      pl[h-o-2][a]='#';
      diese(pl,z,h,l,a,o-1);
    }
  if(0<=h-o && h-o<h && pl[h-o][a]==z)/* meme chose pour la case en dessous*/
    {
      pl[h-o][a]='#';
      diese(pl,z,h,l,a,o+1);	
    }
  /* else
    {
      pl[h-o-1][a]=z;
      }*/
}
/* @requires : on prend un tableau de pointeur de pointeur, c'est à dire que les cases de la matrice seront des pointeurs vers des char et non plus des char, on prend également en paramètre la hauteur et la largeur de la matrice
   @ assign : on modifie ce sur quoi pointe les pointeurs de la matrice
   @ ensure : tout les emplacements de ' ' de la matrice seront translaté vers le haut jusqu'à ce que la case d'au dessus soit également un ' ' ou qu'il n'y ait pas de case au dessus
*/
void descendre(char*** pl, int h, int l)
{
  int i,j;
  for(i=0;i<l;i=i+1)
    {
    for(j=h-1;j>0;j=j-1)
      {
      if((*pl)[j][i]==' ')
	{
	  (*pl)[j][i]=(*pl)[j-1][i];
	  (*pl)[j-1][i]=' ';
	}
      }
    }
}
/* @requires : la matrice pl, le score défini précédement
   @assign : on modifie le score si besoin
   @ ensure : si toutes les cases de la matrice ne contiennent que des ' ' le score sera égale à mille ce qui stoppera le jeu
*/

void fin(char** pl, int score)
{

  if(pl[0][0]==' ')
    {
      score=1000;
    }
  else
    {
      score=score;
    }

}


