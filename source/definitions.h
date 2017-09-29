#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "save_game.h"

//Constants

#define MAX_NAME 20
#define MAX_PKM 10
#define MAX_ATK 10
#define MAX_RES 50

#define L 200
#define C 200

#define WIN 7
#define LOOSE -7

#define CENTER (MAX_R/2)
#define MAX_R 41
#define MAX_PKM 10
    
#define RND(a) ((a)+1)<3 ? 1 : 0

//Structs
typedef struct _Pokemon{
    //char name[MAX_NAME];
    int nameOfPokemon, atk, res;
} Pokemon;

typedef enum _bool{
    FALSE, TRUE
}bool;

typedef struct _ListOfPokemons{
    char nameOfPokemon[MAX_NAME];
    int atk, res;
} ListOfPokemons;

//Global variables
int map[MAX_R][MAX_R];    
int achou[8]; // variavel que contem os pokemons encontrados proximos
int gameover;
int index_pkm;
int numberOfPokemons;
bool flaggy;

ListOfPokemons listOfPokemons[10];
Pokemon *bag;

// Pokemon pokemon[MAX_PKM]; // Struct com características dos pokemons

#ifdef	__cplusplus
}
#endif

#endif /* DEFINITIONS_H_ */
