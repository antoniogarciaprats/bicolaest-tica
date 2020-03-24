// ******* Prueba del TAD Bicola Estatica para enteros ******

#include <stdio.h>
#include <conio.h>
#include "BCE_INT.H"

int main (void) {

  bce_int a,b,c;
  struct bce_int_typo e;
  int i=1;

  clrscr();
  printf("comienzo...\n");
  a=bce_int_nuev(); //crea nueva bicola
  printf("bicola a creada...\n");
//  if (bce_int_vacia(a)) printf("La bicola esta vacia\n");
//  else printf("La bicola no esta vacia\n");

  e.info=i;
  bce_int_meted(a,&e);  //meted(a,1)
  bce_int_mirai(a,&e); //mirai(a,&e)
  printf("MIRAI = %d\n",e.info);
  bce_int_mirad(a,&e); //mirad(a,&e)
  printf("MIRAD = %d\n",e.info);

  i++;
  e.info=i;
  bce_int_metei(a,&e);  //metei(a,2)

  bce_int_mirai(a,&e);
  printf("MIRAI = %d\n",e.info);
  bce_int_mirad(a,&e);
  printf("MIRAD = %d\n",e.info);

  i++;
  e.info=i;
  bce_int_metei(a,&e); //metei(a,3)

  bce_int_mirai(a,&e);
  printf("MIRAI = %d\n",e.info);
  bce_int_mirad(a,&e);
  printf("MIRAD = %d\n",e.info);

  bce_int_sacai(a,&e); //sacai(a,3)
  printf("Se ha sacado por la izq: %d\n",e.info);
  bce_int_mirai(a,&e);
  printf("MIRAI = %d\n",e.info);
  bce_int_mirad(a,&e);
  printf("MIRAD = %d\n",e.info);

  i++;
  e.info=i;
  bce_int_meted(a,&e); //meted(a,4)

  bce_int_mirai(a,&e);
  printf("MIRAI = %d\n",e.info);
  bce_int_mirad(a,&e);
  printf("MIRAD = %d\n",e.info);

  bce_int_sacad(a,&e); //sacai(a,2)
  printf("Se ha sacado por la izq: %d\n",e.info);
  bce_int_mirai(a,&e);
  printf("MIRAI = %d\n",e.info);
  bce_int_mirad(a,&e);
  printf("MIRAD = %d\n",e.info);

  i++;
  e.info=i;
  bce_int_meted(a,&e);  //meted(a,5)

  bce_int_mirai(a,&e);
  printf("MIRAI = %d\n",e.info);
  bce_int_mirad(a,&e);
  printf("MIRAD = %d\n",e.info);

  i++;
  e.info=i;
  bce_int_meted(a,&e);  //meted(a,6)

  bce_int_mirai(a,&e);
  printf("MIRAI = %d\n",e.info);
  bce_int_mirad(a,&e);
  printf("MIRAD = %d\n",e.info);

  printf("\nPulsa una tecla...\n");
  getch();
  clrscr();

  b=bce_int_copia2(a);
  e.info=7;
  bce_int_metei(b,&e);
  printf("\nContenido bicola por copia2");
  bce_int_imprime(b);
  printf("\nContenido bicola origen");
  bce_int_imprime(a);

  printf("\nPulsa una tecla...\n");
  getch();
  clrscr();

  c=bce_int_copia1(a);
  e.info=8;
  bce_int_metei(c,&e);
  printf("\nContenido bicola por copia1");
  bce_int_imprime(c);
  printf("\nContenido bicola origen");
  bce_int_imprime(a);

  bce_int_dest(&a);
  bce_int_dest(&b);
  printf("\ndestruida bicola");
  printf("\nfin prueba. Pulsa una tecla...\n");
  getch();

}

//Fin: PRUEBA1.C --------------------------------------
