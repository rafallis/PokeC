/*
 ============================================================================
 Name        : bag.c
 Author      : Delícias da noite
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "bag.h"

 void addPokemon(int ID){

    numberOfPokemons = (numberOfPokemons)+1;
 
    bag = (Pokemon *) realloc(bag, numberOfPokemons*sizeof(Pokemon));
 
    bag[numberOfPokemons-1].nameOfPokemon = ID;
    bag[numberOfPokemons-1].atk = listOfPokemons[ID].atk;
    bag[numberOfPokemons-1].res = listOfPokemons[ID].res;
 }

 void organizeBag(int ID){
    int i;

    for(i=ID; i<numberOfPokemons; i++)
        bag[i] = bag[i+1];
 }

 Pokemon* removePokemon(int ID){
    int i;

    organizeBag(ID);

    numberOfPokemons--;

    Pokemon *baggy = (Pokemon *)  malloc(numberOfPokemons*sizeof(Pokemon));

    for(i=0; i<numberOfPokemons; i++)
        baggy[i] = bag[i];

    return baggy;
}

void* myRealloc(void *ptr, size_t size){
    void *newptr;
    int msize;
    msize = numberOfPokemons;
    if(size <= msize)
        return ptr;
    newptr = malloc(size);
    memcpy(newptr, ptr, msize);
    free(ptr);
    
    return newptr;
}