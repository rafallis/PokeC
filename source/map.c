#include "map.h"

int new_fild(){
    int i, j;
    for(i=0; i<MAX_R; i++)
        for(j=0; j<MAX_R; j++)
            map[i][j] = -2;
        
    if(i!=MAX_R || j!=MAX_R)
        return -1;
    
    return 0;
}


int new_battleCamp(int n){
        int i, j, flag;
    n/=2;
    
    for(i=1; i<=n; i++){
        map[CENTER-i][CENTER-i] = -1;
        map[CENTER][CENTER-i] = -1;
        map[CENTER+i][CENTER-i] = -1;
        map[CENTER-i][CENTER] = -1;
        map[CENTER+i][CENTER] = -1;
        map[CENTER-i][CENTER+i] = -1;
        map[CENTER][CENTER+i] = -1;
        map[CENTER+i][CENTER+i] = -1;
        
        if(n>1)
            for(j=1;j<=n;j++){
                map[CENTER-i][CENTER-i+j] = -1;
                map[CENTER-i][CENTER+i-j] = -1;
                map[CENTER-i+j][CENTER-i] = -1;
                map[CENTER-i+j][CENTER+i] = -1;
                map[CENTER+i-j][CENTER-i] = -1;
                map[CENTER+i-j][CENTER+i] = -1;
                map[CENTER+i][CENTER-i+j] = -1;
                map[CENTER+i][CENTER+i-j] = -1;
            }
    }
    flag = saveGame();
  
    return 0;
}


int random_pkm(int n){
    int i, j, flag;
    n/=2;
    
    for(i=2; i<=n; i++){
        for(j=1; j<=n; j++){
            if(RND(rand()%15))
                map[CENTER-i][CENTER-i+j] = (rand()%10);
            if(RND(rand()%15))
                map[CENTER-i][CENTER+i-j] = (rand()%10);
            if(RND(rand()%15))
                map[CENTER-i+j][CENTER-i] = (rand()%10);
            if(RND(rand()%15))
                map[CENTER-i+j][CENTER+i] = (rand()%10);
            if(RND(rand()%15))
                map[CENTER+i-j][CENTER-i] = (rand()%10);
            if(RND(rand()%15))
                map[CENTER+i-j][CENTER+i] = (rand()%10);
            if(RND(rand()%15))
                map[CENTER+i][CENTER-i+j] = (rand()%10);
            if(RND(rand()%15))
                map[CENTER+i][CENTER+i-j] = (rand()%10);

        }
    }
    flag = saveGame();
    return 0;
}

    int next(int n){
            int i, j, k, ID, flag;
	    
	    for(i=0; i<MAX_PKM; i++)
	      achou[i] = -1;

            n = n/2;

            for(i=1; i<=n; i++){
                
	        if(map[CENTER][CENTER - i] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");
                        
                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);

                        flag = newBattle(map[CENTER][CENTER - i], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER][CENTER - i] = -1;
                    
                }

                if(map[CENTER - i][CENTER] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");

                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);

                        flag = newBattle(map[CENTER - i][CENTER], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER - i][CENTER] = -1;
                        

                }

                if(map[CENTER + i][CENTER] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");

                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);
                        
                        flag = newBattle(map[CENTER + i][CENTER], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER + i][CENTER] = -1;
                    
                }

                if(map[CENTER][CENTER + i] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");
                        
                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);
                            
                        flag = newBattle(map[CENTER][CENTER + i], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER][CENTER + i] = -1;
                }

                if(map[CENTER + i][CENTER + i] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");
                        
                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);
                        
                        flag = newBattle(map[CENTER + i][CENTER + i], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER + i][CENTER + i] = -1;
                
                }

                if(map[CENTER + i][CENTER - i] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");
                        
                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);
                            
                        flag = newBattle(map[CENTER + i][CENTER - i], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER + i][CENTER - i] = -1;
                        
                    
                }

                if(map[CENTER - i][CENTER - i] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");
                        
                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);
                            
                        flag = newBattle(map[CENTER - i][CENTER - i], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER - i][CENTER - i] = -1;
                    
                }

                if(map[CENTER - i][CENTER + i] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");
                        
                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);
                        
                        flag = newBattle(map[CENTER - i][CENTER + i], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER - i][CENTER + i] = -1;
                    
                }

        if(n>1){
            
            for(j=1;j<=n;j++){

                if(map[CENTER - i][CENTER - i + j] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");
                        
                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);

                        flag = newBattle(map[CENTER - i][CENTER - i + j], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER - i][CENTER - i + j] = -1;
                    
                }

                if(map[CENTER - i][CENTER + i - j] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");
                        
                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);
                            
                        flag = newBattle(map[CENTER - i][CENTER + i - j], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER - i][CENTER + i - j] = -1;
                    
                }

                if(map[CENTER - i + j][CENTER - i] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");

                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);
                            
                        flag = newBattle(map[CENTER - i + j][CENTER - i], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER - i + j][CENTER - i] = -1;
                    
                }

                if(map[CENTER - i + j][CENTER + i] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");
                        
                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);
                            
                        flag = newBattle(map[CENTER - i + j][CENTER + i], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER - i + j][CENTER + i];
                    
                }

                if(map[CENTER + i - j][CENTER - i] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");
                        
                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);
                            
                        flag = newBattle(map[CENTER + i - j][CENTER - i], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER + i - j][CENTER - i] = -1;

                }

                if(map[CENTER + i - j][CENTER + i] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");
                        
                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);
                            
                        flag = newBattle(map[CENTER + i - j][CENTER + i], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER + i - j][CENTER + i];
                    
                }

                if(map[CENTER + i][CENTER - i + j] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");
                        
                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);
                            
                        flag = newBattle(map[CENTER + i][CENTER - i + j], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER + i][CENTER - i + j] = -1;
                        
                    
                }

                if(map[CENTER + i][CENTER + i - j] > -1){
                    
                    flag = 2;
                    flaggy = TRUE;
                    
                    while(flag == 2 && numberOfPokemons>0){
                        printf("SUA POKEMON BAG:\n\n\n");

                        for(k=0;k<numberOfPokemons;k++)
                            printf("     %d)  %s\n     ATK: %d     RES: %d\n\n", k, listOfPokemons[bag[k].nameOfPokemon].nameOfPokemon, bag[k].atk, bag[k].res);
                        
                        printf("Escolha seu pokemon para essa batalha:\n");
                        scanf("%d", &ID);
                            
                        flag = newBattle(map[CENTER + i][CENTER + i - j], ID);
                    }
                    
                    if(flag == 1)
                        map[CENTER + i][CENTER + i - j] = -1;
                        
                }

            }
        }
    }
    return 0;
}

