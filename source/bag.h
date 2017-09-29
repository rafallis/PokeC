#ifndef BAG_H_
#define BAG_H_

#ifdef	__cplusplus
extern "C" {
#endif

#include "definitions.h"

    void addPokemon(int ID);

    void organizeBag(int ID);

    Pokemon* removePokemon(int ID);

    void* myRealloc(void *ptr, size_t size);

#ifdef	__cplusplus
}
#endif

#endif /* BAG_H_ */