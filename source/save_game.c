/*
 ============================================================================
 Name        : save_game.c
 Author      : Delícias da noite
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "save_game.h"

int saveGame(){
	int i, j;
	FILE *f;

	if ((f = fopen("save", "w")) == NULL) 
		return -3;

	fprintf(f, "POKEMON V0.1\n# author: Gabriel & Rafael\n");

	//salva pokemons gerados
	for(i=0; i<MAX_PKM; i++){
		fprintf(f, "%d %d ", listOfPokemons[i].atk, listOfPokemons[i].res);
	}
	fprintf(f, "\n");
	
	//salva os pokemons da bag
	fprintf(f, "%d ", numberOfPokemons);
	for(i=0; i<numberOfPokemons; i++)
		fprintf(f, "%d %d ", bag[i].atk, bag[i].res);
	fprintf(f, "\n");

	//salva os pokemons selvagens ativos
	for(i=0; i<8; i++)
		fprintf(f, "%d ", achou[i]);
	fprintf(f, "\n");

	//salva mapa
	fprintf(f, "%d ", index_pkm);
	for(i=0; i<MAX_R; i++){
		for(j=0; j<MAX_R; j++){
			fprintf(f, "%d ", map[i][j]);
		}
		fprintf(f, "%d\n", map[i][j]);
	}

	fflush(f);
    	fclose(f);
    	return 0;
}

// int loadGame(){
// 	char ch1, ch2, ch3, ch4;
// 	int i, j, verify=0, id, res, emp;
// 	FILE *f;
// 
// 	if((f = fopen("save", "r")) == NULL)
// 		return -3;
// 
// 	if(fscanf(f, "POKEMON %c%c%c%c\n", &ch1, &ch2, &ch3, &ch4) != 1 || ch1 != 'V' || ch2 != '0' || ch3 != '.' || ch4 != '1') {
//   		fclose(f);
//     		printf("Invalid file.");
// 		return -1;
// 	}
// 
// 	/* Skipping comments */
//     	ch1 = getc(f);
// 	while (ch1 == '#') { /* Read all character until line end */
// 	        	do {
// 	             	ch1 = getc(f);
// 		} while (ch1 != '\n');
// 
// 		ch1 = getc(f);
// 	}
// 	ungetc(ch1, f);
// 
// 	//carrega atributos pokemons
// 	for(i=0; i<numberOfPokemons; i++){
// 	  fscanf(f, "%d %d ", &pokemon[i].atk, &pokemon[i].res);
// 	}
// 	
// 	//carrega a bag
// 	verify = fscanf(f, "%d", &numberOfPokemons);
// 	for(i=0; i<numberOfPokemons; i++){
// 		verify = fscanf(f, "%d %d", id, res);
// 		strcpy(bag[i].name, pokemon[id].name);
// 		bag[i].atk = pokemon[id].atk;
// 		bag[i].res = res;
// 	}
// 
// 	//vetor achou
// 	verify = fscanf(f, "\n%d %d %d %d %d %d %d %d", &achou[0], &achou[1], &achou[2], &achou[3], &achou[4], &achou[5], &achou[6], &achou[7]);
// 
// 	//lê mapa
// 	verify = fscanf(f, "%d ", &index_pkm);
// 	for(i=0; i<MAX_R; i++){
// 		for(j=0; j<MAX_R; j++){
// 			fscanf(f, "%d", &map[i][j]);
// 		}
// 		fscanf(f, "%d", &emp);
// 	}
// 
// 	if(verify!=1){
// 		printf("Deu merda =(\n");
// 		return -3;
// 	}
// 
// 	return 0;
// }
