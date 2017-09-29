/*
 ============================================================================
 Name        : pokemon.c
 Author      : Delícias da noite
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "definitions.h"
#include "map.h"
#include "bag.h"
#include "battle.h"
#include "save_game.h"

int main(int argc, char** argv) {

    srand(time(NULL));

    int i, j, flag;
    bool EXIT = FALSE;

    strcpy(listOfPokemons[0].nameOfPokemon, "Pikachu");
    strcpy(listOfPokemons[1].nameOfPokemon, "Squirtle");
    strcpy(listOfPokemons[2].nameOfPokemon, "Bubassaur");
    strcpy(listOfPokemons[3].nameOfPokemon, "Charmander");
    strcpy(listOfPokemons[4].nameOfPokemon, "Jigglypuff");
    strcpy(listOfPokemons[5].nameOfPokemon, "Snorlax");
    strcpy(listOfPokemons[6].nameOfPokemon, "Meowth");
    strcpy(listOfPokemons[7].nameOfPokemon, "Onix");
    strcpy(listOfPokemons[8].nameOfPokemon, "Zapdos");
    strcpy(listOfPokemons[9].nameOfPokemon, "Articuno");

    //if(flag < 0)
      //printf("Save não encontrado!\n");
    
    for(i=0;i<MAX_PKM;i++){
        listOfPokemons[i].atk = (rand()%MAX_ATK) + 1;
        listOfPokemons[i].res = (rand()%MAX_RES) + 1;
    }

    
    numberOfPokemons = 1;

    bag = (Pokemon *) malloc(1 * sizeof(Pokemon));
    

    printf("\nPOKEMON GO!\n\n");

    printf("\nESCOLHA UM POKEMON PARA INICIAR:\n");

    for(i=0;i<3;i++){
        printf("\n%d)NOME: %s\n", i+1, listOfPokemons[i].nameOfPokemon);
        printf("ATK: %d\tRES: %d\n", listOfPokemons[i].atk, listOfPokemons[i].res);
    }

    scanf("%d", &index_pkm);

        bag[0].nameOfPokemon = index_pkm-1;
   	bag[0].atk = listOfPokemons[index_pkm-1].atk;
   	bag[0].res = listOfPokemons[index_pkm-1].res;

    //flag = saveGame();
    gameover = 1;

    while(gameover!=0){

	    printf("\nRaio:\n");
	    scanf("%d", &index_pkm);
            
            //renova pokemons da bag
            for(i=0; i<numberOfPokemons; i++){
                bag[i].atk = listOfPokemons[bag[i].nameOfPokemon].atk;
                bag[i].res = listOfPokemons[bag[i].nameOfPokemon].res;
            }

	    //MAP test
	    i = new_fild();
	    map[CENTER][CENTER] = -8;
	    i = new_battleCamp(index_pkm);
	    i = random_pkm(index_pkm);

	        for(i=0; i<MAX_R; i++){
	        printf("| ");
	        for(j=0; j<MAX_R; j++){
	            if(map[i][j] == -8) printf("O ");
	            else if(map[i][j] == -2) printf("# ");
	            else if(map[i][j] == -1) printf("- ");
	            else if(map[i][j] >= 0) printf("* ");
	        }
	        printf("|\n");
	    }
	    
	    flag = next(index_pkm);
}


    if(gameover == 0){
        printf("GAME OVER!!!\n");
    }


    return (EXIT_SUCCESS);
}
