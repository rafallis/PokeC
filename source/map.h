#ifndef MAP_H_
#define MAP_H_

#ifdef	__cplusplus
extern "C" {
#endif

#include "definitions.h"
#include "battle.h"
   
    int new_fild();
    int new_battleCamp(int n);
    int random_pkm(int n);
    int next(int n);

    void oponente(int cont);

    void luta(int selvagem);

#ifdef	__cplusplus
}
#endif

#endif /* MAP_H_ */