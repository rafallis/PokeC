#ifndef BATTLE_H_
#define BATTLE_H_

#ifdef	__cplusplus
extern "C" {
#endif

#include "definitions.h"
#include "bag.h"
    
int newBattle(int ID, int IDbag);

int atkValue(int maxAtk);

int defValue(int maxRes);

#ifdef	__cplusplus
}
#endif

#endif /* BATTLE_H_ */