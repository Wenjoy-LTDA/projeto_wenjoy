#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void arquivo(){
	
}

int main() {	
FILE *cri;
	char c;
	
	
	//fprintf(cri,"teste");
	do{		
		c=fgetc(cri);
		
		printf("%c", c);
		
	}while (c!= EOF);
	
	fclose(cri);
	
	setlocale(LC_ALL, "Portuguese");
	char nomeCad[20], senhaCad[20], nomeLog[20], senhaLog[20];
	int i, escolha;
	char CHAVE[] = "b3%-~]mk+0_u9gum" ;
	int TAM_CHAVE = strlen(CHAVE);

	printf("Escolha uma das opções: \n \n 1: Fazer Cadastro \n 2: Fazer login \n 3: Sair \n\n");
	scanf("%d", &escolha);
	getchar();
	system("cls");

		do{
			switch (escolha){
				case 1:
					printf("------CADASTRO-------\n");
						
					printf("Digite o seu nome de usuario: \n \n");
					//scanf("%s", nomeCad);
					scanf("%s", nomeCad);
					
					printf("\n Digite sua senha:\n \n");
					scanf("%s", senhaCad);
					system("cls");
					
					//criptografando informação digitada pelo usuário
					for(i=0; i < strlen(nomeCad); i++){
						nomeCad[i] *= CHAVE[i % TAM_CHAVE];
					}
					
					for(i=0; i < strlen(senhaCad); i++){
						senhaCad[i] *= CHAVE[i % TAM_CHAVE];
					}
					
					if((cri = fopen("dados.txt","a")) == NULL ){
						printf("Ocorreu um erro na criacao do arquivo\n");
						system("pause");
					}

					//cri = fopen("dados.txt", "a");
					
					//if(cri == NULL){
					//	printf("Erro ao criar o arquivo\n");
					//	exit(1);
					//}
					
						fprintf(cri, "%s %s\n", nomeCad, senhaCad);
						fclose(cri);
					
						printf("Cadastro realizado com sucesso!\n");
						//Acesso com as informações criptografadas					
						printf("\n --Escolha uma das opções:-- \n \n 1: Fazer Cadastro \n 2: Fazer login \n 3: Sair \n");
						scanf("%d", &escolha);
						system("cls");
					

				break;
		
				case 2:	
				
					cri = fopen("dados.txt", "r");
					if(cri == NULL){
						printf("Erro ao abrir o arquivo de cadastro\n");
						exit(1);
					}
					
					do {
						
						printf("------EFETUE O LOGIN-------\n\n");
					
						printf("Digite o seu nome de usuario: \n\n");
						scanf("%s", nomeLog);
					
						printf("\n Digite sua senha:\n\n");
						scanf("%s", senhaLog);	

						for(i=0; i < strlen(nomeLog); i++){
						nomeLog[i] *= CHAVE[i % TAM_CHAVE];
						}
						//Acesso com as informações criptografadas
						for(i=0; i < strlen(senhaLog); i++){
						senhaLog[i] *= CHAVE[i % TAM_CHAVE];
						}
				
							
						if(strcmp(nomeCad,nomeLog)==0 && strcmp(senhaCad,senhaLog)==0){
							
							printf("\n Acesso concedido !!!!!\n\n");
							escolha = 3;
							
						}else{
						
							printf("\n-------Login ou senha errado------- \n\n");
						
						} 

					}while(strcmp(nomeCad,nomeLog)!=0 && strcmp(senhaCad,senhaLog)!=0 );
				break;
			}

		}while(escolha != 3);


	arquivo;
	
	return 0;
}

