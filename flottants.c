#include <stdlib.h>
#include <stdio.h>

int main(void) {

// Initialisation des constantes avec les trois types de floattants
    const float f = 0.1f;
    const double d = 0.2;
    const long double Ld = 0.3L;

// Calcul de l'opération et affectation dans les trois types de flottants
    float s1 = f + d - Ld;
    double s2 = f + d - Ld;
    long double s3 = f + d - Ld;

// Affichage par ordre croissant (float < double < long double)
    printf("%.6fe \n", s1);
    printf("%.6le \n", s2);
    printf("%.6Le \n", s3);


// Sans variables intermédiaires:
    printf("%.6fe \n", (float)(f + d - Ld));
    printf("%.6le \n", (double)(f + d - Ld));
    printf("%.6Le \n", (long double)(f + d - Ld));


     return EXIT_SUCCESS; 
}

