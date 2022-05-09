#include <stdio.h>
#include <stdlib.h>
#include "estoque.h"

    /**
     * Pilha Functions
     */
	
	// Cria uma pilha vazia
	Pilha criar_pilha(){
		Pilha p;
		p.max_size = MAX_SIZE;
		p.topo = -1;
		p.vet = (Caixa*) malloc(p.max_size*sizeof(Caixa));
		return p;
	}

	// Limpa uma variável do tipo Pilha
	void remover_pilha(Pilha *p){
		if(p->vet != NULL) free(p->vet);
		p->topo = -1;
	}

	// Insere  um  Caixa  na  pilha/caixa segundo a  ordenação
	// LIFO,  em que o último a entrar é o primeiro a sair;
	int push(Pilha *p, Caixa b){
		if(esta_cheia_pilha(p)) return 1;
		p->topo++;
		p->vet[p->topo] = b;
		return 0;
	}

	// Retorna o Caixa no topo da pilha, sem removê-lo
	Caixa top(Pilha *p){
		return p->vet[p->topo];
	}

	// Remove o Caixa no topo da pilha
	void pop(Pilha *p){
		if(!esta_vazia_pilha(p)) 
			--p->topo;
	}

	// Retorna “true” se a pilha estiver vazia; “false”, caso contrário;
	int esta_vazia_pilha(Pilha *p){
		return (p->topo == -1) ? TRUE : FALSE;
	}

	// Retorna “true” se a pilha estiver cheia; “false”, caso contrário;
	int esta_cheia_pilha(Pilha *p){
		return (p->topo+1 == p->max_size) ? TRUE : FALSE;
	}

	// Realiza um print do conteudo da pilha começando do topo:
	void print_pilha(Pilha *p){
        printf(" *-----------------------------------------------* \n");
        printf(" | Caixas em aguardo para mover para a venda: | \n");   
        printf("     ___ \n\n");
		for(int i = p->topo; i >= 0; i--){
            printf("    | %d |\n", p->vet[i].numSerie);
            printf("     ___ \n");
		    printf("\n");
        }
        printf("\n");        
	}


    /**
	 * Fila Functions
	 */

	// Cria uma nova Fila vazia
	Fila criar_fila(){
		Fila f;
		f.vet  = (Caixa*) malloc(MAX_SIZE*sizeof(Caixa)); 
		f.ini  = 0;
		f.fim  = 0;
		f.size = 0;
		return f;
	}

	// Remove as configurações de uma variável do tipo Fila
	void remover_fila(Fila *f){
		if(f->vet != NULL) free(f->vet);
		f->ini  =  0;
		f->fim  = -1;
		f->size =  0;
	}

	// Insere uma caixa no final ou inicio da fila;
	//destino == 1 Venda, destino == 0 Concerto
	//inicio == 1 Inicio da fila, inicio == 0 Fim da fila
	//destino == 1 Venda, destino == 0 Concerto
	int inserir_na_fila(Fila *f, Caixa c, int inicio, int destino){
		if(esta_cheia_fila(f)) return 0;

			//inserindo no inicio
		if(inicio){
 		    // pegando a primeira caixa da filaz
			Caixa cauxOld = f->vet[f->ini];

            // aumentando o tamanho da fila
			f->fim++;
			f->size++;

            // inserindo a nova caixa no inicio da fila
			f->vet[f->ini] = c;

			//reposicionando todas as caixas
			for(int i = f->ini; i < f->size; i++){
				Caixa cauxNew = f->vet[i+1];

				f->vet[i+1] = cauxOld;

				cauxOld = cauxNew;
			}
			printf("*-----------------------------------------------* \n");
			printf("\n caixa %d que havia sido consertada foi enviada para a fila de venda\n\n", c.numSerie);
			printf("*-----------------------------------------------* \n");
		}else {
			//inserindo no final
			if (f->size == 0){
				f->vet[f->ini] = c;
			} else {
				f->fim = ((f->fim+1) < MAX_SIZE) ? f->fim+1 : 0;
				f->vet[f->fim] = c;
			}
			
			f->size += 1;

			if(destino == 1) {
				printf("*-----------------------------------------------* \n");
				printf("\n caixa %d enviada para o setor de preparadas para Venda\n\n", c.numSerie);
				printf("*-----------------------------------------------* \n");
			} else {
				printf("*-----------------------------------------------* \n");
				printf("\n caixa %d enviada para o setor de Avariadas\n\n", c.numSerie);
				printf("*-----------------------------------------------* \n");
			}
		}

		return 1;
	}

	// Remove e retorna a Caixa no inicio da fila
	Caixa remover_da_fila(Fila *f){
		if(esta_vazia_fila(f)){
			printf("\n Sem dados na fila no momento\n");
			Caixa c;
			c.numSerie = -1;
			return c;
		}
		
		Caixa c = f->vet[f->ini];

		f->fim--;
		f->size--;

		//reposicionando todas as caixas
		for(int i = f->ini; i < f->size; i++){
			f->vet[i] = f->vet[i+1];
		}

		// Retornando a caixa removida da fila
		return c;
	}

	// Retorna “true” se a fila estiver vazia; “false”, caso contrário;
	int esta_vazia_fila(Fila *f){
		return (f->size == 0) ? TRUE : FALSE;
	}

	// Retorna “true” se a fila estiver cheia; “false”, caso contrário;
	int esta_cheia_fila(Fila *f){
		return (f->size == MAX_SIZE) ? TRUE : FALSE;
	}

	// Realiza um print do conteudo da fila começando do inicio:
    void print_fila(Fila *f, int destino){
		if(destino == 1){
			//imprimir Fila para venda
			printf("*-----------------------------------------------* \n");
			printf("| Caixas na fila para a venda: | \n");
		} else {
			//imprimir Fila avariadas
			printf("*-----------------------------------------------* \n");
			printf("| Caixas na fila de Avariadas: | \n");
		}

		if(esta_vazia_fila(f)){
			printf("\n Sem Caixas na fila no momento\n");
			printf("*-----------------------------------------------* \n");
			return;
		}

		for(int i = 0; i < f->size; i++){
			int pos = i + f->ini;

			if(pos >= MAX_SIZE)
				pos = pos - MAX_SIZE;

			printf(" %d\n", f->vet[pos].numSerie);
		}
		printf("\n");
		printf("*-----------------------------------------------* \n");
	}

	// Realiza o envio de uma caixa da pilha para a fila
	int mover_caixa_para_fila(Pilha *p, Fila *f, int nextInicio){
		if(esta_vazia_pilha(p)){
			printf("*-----------------------------------------------* \n");
			printf("\n Sem caixas para enviar para venda no momento\n\n");
			printf("*-----------------------------------------------* \n");
			return 0;
		}

		Caixa c = top(p);
		inserir_na_fila(f, c, nextInicio, 1);
		pop(p);

		return 1;
	}

	// Realiza o envio de uma caixa da fila para a pilha
	int mover_caixa_para_Pilha(Pilha *p, Fila *f){
		if(esta_vazia_fila(f)){
			printf("*-----------------------------------------------* \n");
			printf("\n Sem caixas para corrigir no momento\n\n");
			printf("*-----------------------------------------------* \n");
			return 0;
		}

		Caixa c = remover_da_fila(f);
		push(p,c);
		printf("*-----------------------------------------------* \n");
		printf("\n caixa %d corrigida e enviada para preparação para a venda\n\n", c.numSerie);
		printf("*-----------------------------------------------* \n");
		return 1;
	}

	// Mover a Caixa de uma fila para outra no inicio ou no final
	// se inicio == 1, mover para o inicio
	// se inicio == 0, mover para o final
	// se numSerie != 0 procura a caixa com o numSerie e remove-a
	// se destino == 1, mover para a fila de venda , se destino == 0 mover para a fila de Avariada
	int mover_caixa_de_fila(Fila *f, Fila *faux , int inicio, int numSerie, int destino){
		if(esta_vazia_fila(f)){
			if(destino == 1) {
				printf("\n Sem dados na fila de Vendas no momento para enviar para a fila de Avariadas \n");
			} else {
				printf("\n Sem dados na fila de Avariadas no momento para enviar para a fila de Vendas\n");
			}
			return 0;
		}
		Caixa c;

		// se busca a caixa pelo numero de serie
		if(numSerie != 0){
			c  = remover_pos_da_fila(f, numSerie);

			if(c.numSerie == -1){
				if(destino == 1) {
					printf("\n caixa %d nao encontrada na fila de avariadas\n\n", numSerie);
					printf("*-----------------------------------------------* \n");
				} else {
					printf("\n caixa %d nao encontrada na fila de vendas\n\n", numSerie);
					printf("*-----------------------------------------------* \n");
				}
				return 0;
			}else{
				if(destino == 1) {
					printf("\n caixa %d removida do setor de avariadas\n\n", c.numSerie);
				} else {
					printf("\n caixa %d removida do setor preparada para venda\n\n", c.numSerie);
				}
			}

		}else{
			c = remover_da_fila(f);
		}

		//insere a caixa na nova fila
		inserir_na_fila(faux, c, inicio, destino);

		return 1;
	}

	// Remove a caixa da fila pelo numero de serie e retorna a caixa
	Caixa remover_pos_da_fila(Fila *f, int numSerie){
		Caixa c;
		c.numSerie = -1;


		//encontrar caixa de número de série i na fila
		for(int j = f->ini; j < f->size; j++){
			if(f->vet[j].numSerie == numSerie){
				c = f->vet[j];
				f->fim--;
				f->size--;

				//reposicionando todas as caixas
				for(int k = j; k < f->size; k++){
					f->vet[k] = f->vet[k+1];
				}
			}
		}

		return c;
	}
	//definir o sistema operacional para limpar
	void cls(void){
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
	}

	//retorna a opção do menu
	int menu(void){
		int opt;

		printf("\n \nEscolha a opcao:\n");
		printf(" 0. Enviar para Venda\n");
		printf("-1. Corrigir uma caixa do setor de avariadas\n");
		printf("-2. Exibir caixas aguardando para serem vendidas,da mais apta para a menos apta\n");
		printf("-3. Exibir caixas avariadas\n");
		printf("-4. Sair\n");
		printf("Opcao: "); scanf("%d", &opt);

		return opt;
	}

	//Função principal do Sistema
	int main(void){

		Pilha pilhaCaixasAguardoVenda = criar_pilha();
		Fila  filaParaVenda = criar_fila();
		Fila  filaAvariadas = criar_fila();

		int qtdCaixas;

		//digite a quantidade de caixas para serem inseridas
		printf("\nDigite a quantidade de caixas para serem inseridas.\n");
		printf("Quantidade: "); scanf("%d", &qtdCaixas);

		if(qtdCaixas <= 0){
			printf("\nQuantidade invalida, menor ou igual a zero, encerrando programa...\n");
			return 0;
		}

		for(int l = 1; l <= qtdCaixas; l++){
			int numSerie;
			Caixa c;
			printf("\nInsira o numero de serie da caixa %d :\n", l);
			printf("numero de serie: "); scanf("%d", &numSerie);
			c.numSerie = numSerie;
			push(&pilhaCaixasAguardoVenda, c);
			cls();
		}
		
		//menu de opções
		int opt;
		int nextInicio = 0;
		int corrigirQtd = 0;
		int response = 0;
		do{
			opt = menu();
			cls();
			switch(opt){
				case 0:
					mover_caixa_para_fila(&pilhaCaixasAguardoVenda, &filaParaVenda, nextInicio);
					if(corrigirQtd == 1 || corrigirQtd == 0){
						nextInicio = 0;
						corrigirQtd = 0;
					} else {
						corrigirQtd--;
					}
					break;

				case -1:
					response = mover_caixa_para_Pilha(&pilhaCaixasAguardoVenda, &filaAvariadas);
					if(response == 1){
						corrigirQtd++;
						nextInicio=1;
					}
				
					break;

				case -2:
					print_fila(&filaParaVenda, 1);
					break;

				case -3:
					print_fila(&filaAvariadas, 0);
					break;

				case -4:
					printf("*-----------------------------------------------* \n");
					printf("\n Saindo...Até logo :)\n\n");
					printf("*-----------------------------------------------* \n");
					break;

				default:
					printf("*-----------------------------------------------* \n");
					printf("Procurando pela caixa %d na fila para venda...\n", opt);
					mover_caixa_de_fila(&filaParaVenda, &filaAvariadas, 0, opt, 0);
				}
		}while(opt != -4);

		return 0;
	}