#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static unsigned long long X = 123456ULL;

unsigned char crand48(void) {

// votre code ici

  unsigned long long exp = pow(2, 48);
  unsigned char s = 0;

/*
  Principe: X est codé sur 8 octets (on a observer avec sizeof())
  on veut les bits 32 à 39 soit le 4ème octet
  on fait un décalage à droite de 3 octets sur X pour metttre l'octet recherché en début
  puis on fait un & avec 0x0F pour mettre les 4 octets qui suivent notre octet à zéro
*/

  X = (0x5DEECE66D*X + 0xB) % exp;
  s = (unsigned char)((X >> 24) & 0x0F);

  return s;
}

int main(void) {
  printf("%hhu\n", crand48());
  printf("%hhu\n", crand48());
  printf("%hhu\n", crand48());

  return EXIT_SUCCESS;
}