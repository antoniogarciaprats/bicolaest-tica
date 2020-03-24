// -----------------BCE_INT.H - Bicola estatica para enteros ---------------

#ifndef BCE_int_H
#define BCE_int_H

#define MAXPint 9   //Tamanio maximo del array

struct bce_int_typo {   //Tipo base de la pila
  int info;
};


typedef struct bce_int_rep *bce_int;

bce_int bce_int_nuev(void);
int bce_int_vacia(bce_int bce);
int bce_int_llena(bce_int bce);
void bce_int_metei(bce_int bce,struct bce_int_typo *e);
void bce_int_meted(bce_int bce,struct bce_int_typo *e);
void bce_int_sacai(bce_int bce,struct bce_int_typo *e);
void bce_int_sacad(bce_int bce,struct bce_int_typo *e);
void bce_int_mirai(bce_int bce,struct bce_int_typo *e);
void bce_int_mirad(bce_int bce,struct bce_int_typo *e);
bce_int bce_int_copia1(bce_int origen);
bce_int bce_int_copia2(bce_int origen);
void bce_int_imprime(bce_int bce);
bce_int bce_int_dest(bce_int *bce);

#endif


// Fin de BCE_INT.H ----------------------------------------
