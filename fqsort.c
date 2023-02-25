#include <assert.h>
#include <complex.h>
#include <stdlib.h>
#include <stdio.h>

/**
   Ajouter la fonction de comparaison du tri ici   
*/
int compare(const void *a_void, const void *b_void){
  double complex *c_a = (double complex *)a_void;
  double complex *c_b = (double complex *)b_void;

// on récupère les arguments de a et b qu'on compare ensuite
  double arg_a = carg(*c_a);
  double arg_b = carg(*c_b);

  if (arg_a < arg_b)
    return -1;
  else if(arg_a > arg_b)
    return 1;
  else
    return 0;
}

const int TAILLE = 100;

int main(void) {
  /* initialisation du tableau */
  double complex tableau[TAILLE];
  srand48(123456);
  for (int i = 0; i < TAILLE; i++) {
    tableau[i] = drand48() + (drand48() * 1.0i);
  }

  /**
     Mettre le code d'appel de qsort ici
  */
  qsort(tableau, TAILLE, sizeof(double complex), compare);
  /*
  verification visuelle
   for (int i = 0; i < TAILLE - 1; i++) {
    printf ("%lf + %lfI arg= %lf \n",creal(tableau[i]), cimag(tableau[i]), carg(tableau[i]));
  }
  */

  /**
     Vérification du tri
  */
  for (int i = 0; i < TAILLE - 1; i++) {
    assert(carg(tableau[i]) <= carg(tableau[i + 1]));
  }

  return EXIT_SUCCESS;
}
