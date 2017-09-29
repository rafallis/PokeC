/*
 ============================================================================
 Name        : battle.c
 Author      : Delícias da nopte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "battle.h"

 int newBattle(int ID, int IDbag){

        int myAtk, wildAtk, tempDef, run, roll, n=0, newPKM;
 	static int wildPkmAtk, wildPkmRes;

 	int op;

        if(flaggy == TRUE){
            wildPkmAtk = listOfPokemons[ID].atk;
            wildPkmRes = listOfPokemons[ID].res;
        }
        flaggy = TRUE;

 	while(gameover!=0){

	 	printf("\nMY Pokemon: %s  atk: %d  res: %d\n\n", listOfPokemons[bag[IDbag].nameOfPokemon].nameOfPokemon, bag[IDbag].atk, bag[IDbag].res);
                printf("Wild Pokemon: %s  atk: %d  res: %d\n\n", listOfPokemons[ID].nameOfPokemon, wildPkmAtk, wildPkmRes);

	 	//opções de batalha
	 	printf("1)Attack     2)Defend     3)Run\n");
	 	scanf("%d", &op);

	 	switch(op){
	 		case 1:
		 		myAtk = atkValue(bag[IDbag].atk);
		 		wildPkmRes -= myAtk;

		 		if(wildPkmRes <= 0){
                                    
                                    addPokemon(ID);
                                    
		 			n=1;
		 		}

		 		else{
		 			wildAtk = atkValue(wildPkmAtk);
		 			bag[IDbag].res -= wildAtk;
                                        
                                        
		 			if(bag[IDbag].res <= 0){

		 				printf("Seu pokemon morreu\n");

		 				if(numberOfPokemons > 0){
		 					bag = removePokemon(IDbag);
                                                        flaggy = FALSE;
		 				}

		 				if(numberOfPokemons <= 0){
		 					gameover = 0;
		 				}
		 				
		 				n=2;
		 			}
		 		}

		 		break;

		 	case 2:
		 		wildAtk = atkValue(wildPkmAtk);
		 		tempDef = bag[IDbag].res + defValue(bag[IDbag].res);
		 		tempDef -= wildAtk;
		 		if(tempDef <= 0){
		 			printf("E morreu =,(\n");
		 			bag = removePokemon(IDbag);
                                        flaggy = FALSE;
                                        
                                        if(numberOfPokemons <0)
                                            gameover = 0;
                                        
		 			n=2;
		 		}

		 		bag[IDbag].res = tempDef;
		 		
		 		break;

		 	case 3:
		 		printf("O atk do pokemon selvagem vale: %d\n", wildPkmAtk);
		 		run = rand()%6 + 1;
		 		printf("O primeiro dado rolado é %d\n", run);

		 		roll = (rand()%6)+1;

		 		printf("O segundo dado rolado é %d\n", roll);
		 		run += roll;
		 		printf("Total: %d\n", run);

		 		if(run >= 2 * wildPkmAtk){
		 			printf("CORRE NEGADA!!!\n");
		 			n=1;
		 		}
		 		
		 		else
		 			printf("\"Daqui você não sai Muahahahah\"\n");

		 		break;

		 	default:
		 		printf("Selecione uma opção válida.\n");
	 	}

	 	if(n == 1 || n == 2){

	 		return n;
	 	}
	 }
 }

//O ataque é definido randomicamente de 1 até o valor máximo de ataque do pokemon
 int atkValue(int maxAtk){
 	return (rand()%maxAtk +1);
 }

//A defesa aumenta no máximo metade do máximo de resistencia do pokemon
 int defValue(int maxRes){
 	return ((rand()%maxRes +1) * .5);
 }
