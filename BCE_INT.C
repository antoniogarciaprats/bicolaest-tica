// -----------------BCE_INT.C - Bicola estatica para enteros ---------------

#include <stdio.h>
#include <stdlib.h>
#include "BCE_INT.H"

struct bce_int_rep {
  struct bce_int_typo arr[MAXPint];
  int izq;
  int usados;
};

//---------------------------- PRIMITIVAS PUBLICAS --------------------

bce_int bce_int_nuev(void) {

  bce_int bce;

  bce=(struct bce_int_rep *) malloc (sizeof (struct bce_int_rep));
  if (!bce) {
     fprintf(stderr,"bce_int_nuev : no hay memoria.\n");
     exit(1);
  }
  bce->izq=bce->usados=0;
  return(bce);

}

//-------------------------------------------------------------------

int bce_int_vacia(bce_int bce) {

  if (!bce) {
     fprintf(stderr,"bce_int_vacia : la bicola no existe.\n");
     exit(2);
  }
  return(bce->usados==0);

}

//-------------------------------------------------------------------

int bce_int_llena(bce_int bce) {

  if (!bce) {
     fprintf(stderr,"bce_int_llena : la bicola no existe.\n");
     exit(2);
  }
  return(bce->usados==MAXPint);

}

//-------------------------------------------------------------------

void bce_int_metei(bce_int bce,struct bce_int_typo *e) {

  if (!bce) {
     fprintf(stderr,"bce_int_metei : la bicola no existe.\n");
     exit(2);
  }
  if (bce->usados==MAXPint) { //Si la bicola esta llena
     printf("c_int_metei : la bicola esta llena.\n");
     exit(3);
  }
  if ((bce->izq-1)<0) //Reajusta extremo izq
     bce->izq=MAXPint-1;
  else
     bce->izq--;
  bce->arr[bce->izq]=*e; //Meto dato
  bce->usados++;

}

//-------------------------------------------------------------------

void bce_int_meted(bce_int bce,struct bce_int_typo *e) {

  if (!bce) {
     fprintf(stderr,"bce_int_meted : la bicola no existe.\n");
     exit(2);
  }
  if (bce->usados==MAXPint) { //Si la bicola esta llena
     printf("c_int_meted : la bicola esta llena.\n");
     exit(3);
  }
  bce->arr[(bce->izq + bce->usados)%MAXPint]=*e; //Meto dato
  bce->usados++;

}

//-------------------------------------------------------------------

void bce_int_sacai(bce_int bce,struct bce_int_typo *e) {

  if (!bce) {
     fprintf(stderr,"bce_int_sacai : la bicola no existe.\n");
     exit(2);
  }
  if (bce->usados==0) { //Si la bicola esta vacia
     printf("c_int_sacai : la bicola esta vacia.\n");
     exit(4);
  }
  *e=bce->arr[bce->izq]; //Devuelve el valor en 'e'
  bce->izq=(1+bce->izq)%MAXPint; //incrementa extr. izq
  bce->usados--;

}

//-------------------------------------------------------------------

void bce_int_sacad(bce_int bce,struct bce_int_typo *e) {

  if (!bce) {
     fprintf(stderr,"bce_int_sacad : la bicola no existe.\n");
     exit(2);
  }
  if (bce->usados==0) { //Si la bicola esta vacia
     printf("c_int_sacad : la bicola esta vacia.\n");
     exit(4);
  }
  *e=bce->arr[((bce->izq + bce->usados)-1)%MAXPint];//Devuelce el valor en 'e'
  bce->usados--;

}

//-------------------------------------------------------------------

void bce_int_mirai(bce_int bce,struct bce_int_typo *e) {

  if (!bce) {
     fprintf(stderr,"bce_int_mirai : la bicola no existe.\n");
     exit(2);
  }
  if (bce->usados==0) { //Si la bicola esta vacia
     printf("c_int_mirai : la bicola esta vacia.\n");
     exit(4);
  }
  *e=bce->arr[bce->izq]; //Devuelve el valor en 'e'

}

//-------------------------------------------------------------------

void bce_int_mirad(bce_int bce,struct bce_int_typo *e) {

  if (!bce) {
     fprintf(stderr,"bce_int_mirad : la bicola no existe.\n");
     exit(2);
  }
  if (bce->usados==0) { //Si la bicola esta vacia
     printf("c_int_mirad : la bicola esta vacia.\n");
     exit(4);
  }
  *e=bce->arr[((bce->izq + bce->usados)-1)%MAXPint];//Devuelce el valor en 'e'

}

//-------------------------------------------------------------------

//El nuevo objeto apunta al original
bce_int bce_int_copia1(bce_int origen) {

  bce_int destino;

  if (!origen) {
     fprintf(stderr,"bce_int_copia1 : la bicola no existe.\n");
     exit(2);
  }
  return(destino=origen);

}

//-------------------------------------------------------------------

//El nuevo objeto es un copia del original
bce_int bce_int_copia2(bce_int origen) {

  bce_int destino;

  if (!origen) {
     fprintf(stderr,"bce_int_copia2 : la bicola no existe.\n");
     exit(2);
  }
  destino=(struct bce_int_rep *) malloc (sizeof (struct bce_int_rep));
  if (!destino) {
     fprintf(stderr,"bce_int_copia2 : no hay memoria.\n");
     exit(1);
  }
  destino->izq=origen->izq;
  destino->usados=origen->usados;
  memcpy(destino->arr,origen->arr,sizeof(struct bce_int_typo)*MAXPint);
//  for (i=;i < origien->usados;i++) {
//     if ()

//  }
  return(destino);

}

//-------------------------------------------------------------------

void bce_int_imprime(bce_int bce) {

  int i;

  if (!bce) {
     fprintf(stderr,"bce_int_imprime : la bicola no existe.\n");
     exit(2);
  }
  printf("\nCONTENIDO DE LA BICOLA:");
  printf("\n=======================");
  for (i=0;i<bce->usados;i++)
     printf("\n%d",bce->arr[(bce->izq+i)%MAXPint]);

}

//-------------------------------------------------------------------

bce_int bce_int_dest(bce_int *bce) {

  if (!bce) {
     fprintf(stderr,"bce_int_dest : la bicola no existe.\n");
     exit(2);
  }
  free(*bce);
  *bce=NULL;

}


//Fin: BCE_INT.C ------------------------------------
