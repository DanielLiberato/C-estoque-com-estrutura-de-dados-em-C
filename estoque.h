#ifndef ESTOQUE_H
    #define ESTOQUE_H
    #define MAX_SIZE 5000
    #define TRUE 1
    #define FALSE 0

    /**
	 * Caixa - estrutura 
	 */
    typedef struct _caixa{
		int numSerie;
	} Caixa;

    /**
	 * Pilha de Caixas
	 */
    typedef struct _pilha {
        Caixa *vet;
        int topo, max_size;
    } Pilha;

    // Cria uma pilha vazia
    Pilha criar_pilha();

    // Limpa uma variável do tipo Pilha
    void remover_pilha(Pilha *p);

    // Insere  um  Caixa  na  pilha/caixa segundo a  ordenação
    // LIFO,  em que o último a entrar é o primeiro a sair;
    int push(Pilha *p, Caixa c);

    // Retorna o Caixa no topo da pilha, sem removê-lo
    Caixa top(Pilha *p);

    // Remove o Caixa no topo da pilha
    void pop(Pilha *p);

    // Retorna “true” se a pilha estiver vazia; “false”, caso contrário;
    int esta_vazia_pilha(Pilha *p);

    // Retorna “true” se a pilha estiver cheia; “false”, caso contrário;
    int esta_cheia_pilha(Pilha *p);

    // Realiza um print do conteudo da pilha começando do topo:
    void print_pilha(Pilha *p);


    /**
	 * Fila de Caixas - Fila
	 */
    typedef struct _fila{
        Caixa *vet;
        int ini, fim, size;
    } Fila;

    // Cria uma nova Fila vazia
    Fila criar_fila();

    // Remove as configurações de uma variável do tipo Fila
    void remover_fila(Fila *f);

    // Insere uma caixa no final ou inicio da fila;
	//destino == 1 Venda, destino == 0 Concerto
	//inicio == 1 Inicio da fila, inicio == 0 Fim da fila
	//destino == 1 Venda, destino == 0 Concerto
    int inserir_na_fila(Fila *f, Caixa c, int inicio, int destino);

    // Remove e retorna a Caixa no inicio da fila
    Caixa remover_da_fila(Fila *f);

    // Retorna “true” se a fila estiver vazia; “false”, caso contrário;
    int esta_vazia_fila(Fila *f);

    // Retorna “true” se a fila estiver cheia; “false”, caso contrário;
    int esta_cheia_fila(Fila *f);

    // Realiza um print do conteudo da pilha começando do topo:
    void print_fila(Fila *f, int destino);

    // Realiza o envio de uma caixa da pilha para a fila
    int mover_caixa_para_fila(Pilha *p, Fila *f, int nextInicio);

    // Realiza o envio de uma caixa da fila para a pilha
	int mover_caixa_para_Pilha(Pilha *p, Fila *f);

	// Mover a Caixa de uma fila para outra no inicio ou no final
	// se inicio == 1, mover para o inicio
	// se inicio == 0, mover para o final
	// se numSerie != 0 procura a caixa com o numSerie e remove-a
	// se destino == 1, mover para a fila de venda , se destino == 0 mover para a fila de Avariada
    int mover_caixa_de_fila(Fila *f, Fila *faux, int inicio, int numSerie, int destino);

    // Remove a caixa da fila pelo numero de serie e retorna a caixa
    Caixa remover_pos_da_fila(Fila *f, int numSerie);

    //definir o sistema operacional para limpar
	void cls(void);
    
    //retorna a opção do menu
    int menu(void);

#endif