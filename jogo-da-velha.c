#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<conio.h>
#include<windows.h>

int i, j;
char tabela[3][3];

void titulo(){

	system("color 0D");
	
	printf("\t\t  OooOoo  .oOOOo.   .oOOOo.   .oOOOo. \n");Sleep(200);
	printf("\t\t      O  .O     o. .O     o  .O     o. \n");Sleep(200);
	printf("\t\t      o  O       o o         O       o \n");Sleep(200);
	printf("\t\t      O  o       O O         o       O \n");Sleep(200);
	printf("\t\t      o  O       o O   .oOOo O       o \n");Sleep(200);
	printf("\t\t      O  o       O o.      O o       O \n");Sleep(200);
	printf("\t\tO     o  `o     O'  O.    oO `o     O' \n");Sleep(200);
	printf("\t\t`OooOO'   `OoooO'    `OooO'   `OoooO' \n\n");Sleep(200);

	system("color 0C");
	
	printf("\t\t\t\t\to.OOOo.      Oo   \n");Sleep(200);
	printf("\t\t\t\t\t O    `o    o  O  \n");Sleep(200);
	printf("\t\t\t\t\t o      O  O    o \n");Sleep(200);
	printf("\t\t\t\t\t O      o oOooOoOo\n");Sleep(200);
	printf("\t\t\t\t\t o      O o      O\n");Sleep(200);
	printf("\t\t\t\t\t O      o O      o\n");Sleep(200);
	printf("\t\t\t\t\t o    .O' o      O\n");Sleep(200);
	printf("\t\t\t\t\t OooOO'   O.     O\n\n");Sleep(200);

	system("color 0A");
	
	printf("\t\t\t\t\t\to      'O o.OOoOoo  o      o      O    Oo   \n");Sleep(200);
	printf("\t\t\t\t\t\tO       o  O       O       O      o   o  O  \n");Sleep(200);
	printf("\t\t\t\t\t\to       O  o       o       o      O  O    o \n");Sleep(200);
	printf("\t\t\t\t\t\to       o  ooOO    o       OoOooOOo oOooOoOo\n");Sleep(200);
	printf("\t\t\t\t\t\tO      O'  O       O       o      O o      O\n");Sleep(200);
	printf("\t\t\t\t\t\t`o    o    o       O       O      o O      o\n");Sleep(200);
	printf("\t\t\t\t\t\t `o  O     O       o     . o      o o      O\n");Sleep(200);
	printf("\t\t\t\t\t\t  `o'     ooOooOoO OOoOooO o      O O.     O\n");Sleep(200);
	
}

void inicializarMatriz(){  //colocar valores vazios na matriz
	
		for(i = 0; i < 3; i++) {
	        for(j = 0; j < 3; j++) {
	            tabela[i][j] = ' ';
	        }
	    }
}

void imprimirTabela(){
	
	// i = linha ; j = coluna //
    printf("\n\t\t\t\t    1  2  3 \n\n");
    for(i = 0; i < 3; i++){
        printf("\t\t\t\t%d ", i+1);
	        for(j = 0; j < 3; j++) {
	            if(j < 2){
	            	printf(" %c |", tabela[i][j]);
	            	
				} else{
					printf(" %c ", tabela[i][j]);
				}      
	        }
        
        if(i < 2){
        	printf("\n\t\t\t\t   ---------\n");
        	
		}      
    }	
}

int ganhouPorLinha(){
	
	int aux = 1;
	int ganhou = 0;
	
	for(i = 0 ; i < 3 ; i++){
		for(j = 0 ; j < 2 ; j++){	
		
			if(tabela[i][j] == 'X' || tabela[i][j] == 'O'){
				if(tabela[i][j] == tabela[i][j+1]){
					aux++;	
				}
			}
		}
		
		if(aux == 3){
			ganhou++;
		}
		
		aux = 1;
	}	
		
	return ganhou;
}

int ganhouPorColuna(){
	
	int aux = 1;
	int ganhou = 0;
	
	for(i=0 ; i<3 ; i++){
		for(j=0 ; j<3 ; j++){
			
			if(tabela[j][i] == 'X' || tabela[j][i] == 'O'){
				
				if(tabela[j][i] == tabela[j+1][i]){
					aux++;
				}
			}
		}
		
		if(aux == 3)		
			ganhou++;
					
		aux = 1;
	}	
		
	return ganhou;	
}

int ganhouPorDiagonal_1(){
	
	int aux = 1;
	int ganhou = 0;
			
	for(i = 0; i < 2; i++){
		
		if(tabela[i][i] == 'X' || tabela[i][i] == 'O'){	
			if(tabela[i][i] == tabela[i+1][i+1]){    	
	        	aux++;	
			}
		}
    }
	
	if(aux == 3)
		ganhou++;
	
	return ganhou;
}

int ganhouPorDiagonal_2(){
	
		int aux = 1;
		int ganhou = 0;
		int i = 1,  a = 0, b = 2;
		
		if(tabela[i][i] == 'X' || tabela[i][i] == 'O'){
			
	        if(tabela[i][i] == tabela[a][b] && tabela[i][i] == tabela[b][a]){
	        	aux = 3;
			}			
		}	    
	
		if(aux == 3)
			ganhou++;

		return ganhou;
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int op;
	int l, c; // linha e coluna
	int jogada;
	int vencedor;
	int repetiu;
	int win1, win2, auxWin;
	char jogador1[50], jogador2[50], aux[50];	
	
	titulo();
	printf("  Digite qualquer botão para começar...");getch();
	system("cls");
	
	do{ // se o usuário recomeçar o jogo e trocar os nomes.
		
			printf("\n\n");
			
			if(op != 2)
				printf("\t\t\t\t   Bem-vindo(a) ao jogo da velha!");
					
			printf("\n\n\n\t Digite o nome do Jogador 1: ");
			fflush(stdin);
			scanf("%s", jogador1);
		
			printf("\n\t Digite o nome do Jogador 2: ");
			scanf("%s", jogador2);
			
			win1 = 0;
			win2 = 0;
			
			do{ //jogar mais uma vez
			
					printf("\n\n\n\n\t\t-> %s será o símbolo bola \t\t", jogador1);
					printf("-> E o %s sera o símbolo Xis\n", jogador2);
					printf("\t\t\t    O \t\t\t\t\t      X\n\n\n\n");
					jogada = 0;
					vencedor = 0;
					
					printf("\t\t\t\t    Digite Enter para começar...");
					do{
						c = getch();
					} while(c != 13);
					system("cls");
					
					inicializarMatriz();
					
					do{ //ate alguem ganhar ou dar velha
				
						printf("\n\n\n\n\n");
							
							if(jogada % 2 == 0){
								
									printf("\t\t --> Vez de %s:\n\n", jogador1);
								
							} else{
								
									printf("\t\t --> Vez de %s:\n\n", jogador2);
								
							}
							
							imprimirTabela();
								
								do{ //se repetir a posicao
								
									repetiu = 0;
										
										do { //se a coordenada nao existir
											
												printf("\n\n\n\t\t Digite a coordenada que você deseja jogar: \n\n");
												
												printf("\t\t\t --> Digite a linha: ");
												scanf("%d", &l);
												
												printf("\t\t\t --> Digite a coluna: ");
												scanf("%d", &c);
												
													if(l < 1 || l > 3 || c < 1 || c > 3){
														
															printf("\n\t\t\tX Essa coordenada não existe, tente de novo... X\n\n");
															Sleep(2000);
															system("cls");
															
															printf("\n\n\n\n\n");
							
																if(jogada % 2 == 0){
																	
																		printf("\t\t --> Vez de %s:\n\n", jogador1);
																	
																} else{
																	
																		printf("\t\t --> Vez de %s:\n\n", jogador2);
																	
																}
																
															imprimirTabela();
														
													}
													
										} while(l < 1 || l > 3 || c < 1 || c > 3);
										
										l = l - 1;
										c = c - 1;			
													
										if(tabela[l][c] == ' '){
											
												if(jogada % 2 == 0){
													
														tabela[l][c] = 'O';
														jogada++;
													
												} else{
													
														tabela[l][c] = 'X';
														jogada++;
													
												}
												
										} else{
											
												printf("\t\t\tX Essa posição já esta preenchida, tente de novo... X");
												Sleep(2000);
												system("cls");
												printf("\n\n\n\n\n");
												if(jogada % 2 == 0){
																	
														printf("\t\t --> Vez de %s:\n\n", jogador1);
																	
												} else{
																	
														printf("\t\t --> Vez de %s:\n\n", jogador2);
																	
												}
																
												imprimirTabela();
												repetiu++;
											
										}	
											
								} while (repetiu == 1);
							
								vencedor += ganhouPorLinha();
								vencedor += ganhouPorColuna();
								vencedor += ganhouPorDiagonal_1();
								vencedor += ganhouPorDiagonal_2();
								
									if(vencedor != 0){ // se por acaso o jogador ganhar com as nove casas cheias
										
										jogada--;
										
									}
					
								system("cls");
							
					} while(jogada < 9 && vencedor == 0);
					
					printf("\n\n\n\n");
					
					imprimirTabela(); 
					
					if(jogada == 9){
						
							printf("\n\n\t\t DEU VELHAA!!!!\n\n");
						
					} else{
						
						
							if(jogada % 2 == 0){ //se o jogador 1 ganhar
								
										if(ganhouPorLinha() != 0){
											
												printf("\n\n\n\t\tPARABÉNS, o jogador %s venceu por linha!! \n\n", jogador1);
											
										}
										
										if(ganhouPorColuna() != 0){
											
												printf("\n\n\n\t\tPARABÉNS, o jogador %s venceu por coluna!! \n\n", jogador1);
											
										}
										
										if(ganhouPorDiagonal_1() != 0 || ganhouPorDiagonal_2() != 0){
											
												printf("\n\n\n\t\tPARABÉNS, o jogador %s venceu por diagonal!! \n\n", jogador1);
											
										}
										
										win1++;
												
							} else{ //if player 2 wins
								
										if(ganhouPorLinha() != 0){
											
												printf("\n\n\n\t\tPARABÉNS, o jogador %s venceu por linha!! \n\n", jogador2);
											
										}
										
										if(ganhouPorColuna() != 0){
											
											printf("\n\n\n\t\tPARABÉNS, o jogador %s venceu por coluna!! \n\n", jogador2);
								
										}
										
										if(ganhouPorDiagonal_1() != 0 || ganhouPorDiagonal_2() != 0){
											
											printf("\n\n\n\t\tPARABÉNS, o jogador %s venceu por diagonal!! \n\n", jogador2);
											
										}
										
										win2++;
							}	
					}
					
					printf("\n\t\tDigite Enter para prosseguir...");
					do{
						c = getch();
					} while(c != 13);
					
					do{ // if the user doesnt type any option down, repeat this part.
					
							system("cls");
							
							printf("\n\n\n\n");
							printf("\t\t===============================================\n");
							printf("\t\t|                                             |\n\n");
							printf("\t\t    Placar de vitórias:                        \n\n");
							printf("\t\t    %s ------------> %d vitórias\n             \n", jogador1, win1);
							printf("\t\t                                               \n");
							printf("\t\t    %s ------------> %d vitórias\n             \n", jogador2, win2);
							printf("\t\t|                                             |\n");
							printf("\t\t===============================================\n\n");
							
							printf("    Escolha uma das opções abaixo:\n\n");
							printf("   1 - Jogar novamente.\n");
							printf("   2 - Mudar os nomes e reiniciar o jogo.\n");
							printf("   3 - Sair do jogo.\n\n");
							printf("      Digite aqui: ");
							scanf("%d", &op);
							
							if(op == 1){ //aqui serve pro  jogardor 2 ser a bola, 
								
									strcpy(aux, jogador1);
									strcpy(jogador1, jogador2);
									strcpy(jogador2, aux);
									
									auxWin = win1;
									win1 = win2;
									win2 = auxWin;
									
									system("cls");
								
							}
					//		
							else if(op == 2){
								
									system("cls");
								
							}
					//		
							else if(op == 3){
								
									//nothing happens here
								
							}
					//		
							else{
								
								printf("\n\tX Você não digitou nenhuma das opções, tente novamente... X");
								Sleep(1800);
								
							}
														
					} while(op != 1 && op != 2 && op != 3);
					
			} while(op == 1);
	
	} while(op == 2);
	
	system("cls");
	Sleep(500);
	
	printf("\n\t\t\t                   Créditos");
	
	printf("\n\n");
	printf("\t\t\tSom ---------------------------------------> Rodrigo Neves\n\n");Sleep(1000);
	printf("\t\t\tDesenhos ----------------------------------> Rodrigo Neves\n\n");Sleep(1000);
	printf("\t\t\tAnimações ---------------------------------> Rodrigo Neves\n\n");Sleep(1000);
	printf("\t\t\tCriação -----------------------------------> Rodrigo Neves\n\n");Sleep(1000);
	printf("\t\t\tDublagem ----------------------------------> Rodrigo Neves\n\n");Sleep(1000);
	printf("\t\t\tProdução Geral ----------------------------> Rodrigo Neves\n\n");Sleep(1000);
	printf("\t\t\tDireção -----------------------------------> Rodrigo Neves\n\n");Sleep(1000);
	printf("\t\t\tPatrocínio --------------------------------> Rodrigo Neves\n\n");Sleep(1000);
	printf("\t\t\tAgradecimentos ----------------------------> Rodrigo Neves\n\n");Sleep(1000);
	
	printf("\t\t\t\tObrigado por jogar meu joguinho :-)");

	return 0;
}
