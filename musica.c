#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <malloc.h>

//----------------------------------------------------

typedef struct
{
    char nome [100];
    int senha , registro ;
    float dinheiro ;
} CONTA ;

typedef struct nodo
{
    struct nodo *pProximo;
    struct nodo *pAnterior;
    CONTA *pConta;

} NODO;

//---------------------------------------------------

NODO  *pInicio = NULL;
NODO  *pFim = NULL;
NODO  *pAux = NULL;

//--------------------------------------------------

CONTA *AbrirConta()
{
    CONTA *pConta = (CONTA *)malloc(sizeof(CONTA));
    if (pConta == NULL)
    {
        printf("Erro ao criar conta.\n");
        exit(1);
    }
    return pConta;
}

NODO *criarNodo()
{
    NODO *pNodo = (NODO *)malloc(sizeof(NODO));

    if (pNodo == NULL)
    {
        printf("Erro ao alocar memoria para o nodo.\n");
        exit(1);
    }
    pNodo->pProximo = NULL;
    pNodo->pAnterior = NULL;
    pNodo->pConta = NULL;
    return pNodo;
}

//-----------------------------------------------------------

void InsereLista(CONTA *pConta, NODO *pLocal)
{
    NODO *pNovo = criarNodo();
    pNovo->pConta = pConta;

    if(pInicio == NULL) //Lista vazia
    {
        pInicio = pNovo;
        pFim = pNovo;
        return;

    }
    else if(pLocal == pInicio) //Insere no inicio da lista
         {
            pNovo->pProximo = pInicio;
            pInicio->pAnterior = pNovo;
            pInicio = pNovo;

            return;
        
        }
    else if(pLocal == pFim) //Insere no fim da lista
         {
            pFim->pProximo = pNovo;
            pNovo->pAnterior = pFim;
            pFim = pNovo;
            return;
         }
    else if(pLocal->pAnterior != NULL && pLocal->pProximo != NULL) //Insere no meio da lista
         {
            pAux = pLocal;

                pAux->pAnterior->pProximo = pNovo;
                pAux->pProximo->pAnterior = pNovo;
                return;
           
        }
    }

//----------------------------------------------------------------------

void ImprimeConta()
{
    pAux = pInicio;

    if(pAux == NULL)
    {
        printf("A lista esta vazia.\n");
        return;
    }
    
    while(pAux != NULL)
    {
        printf("Nome: %s\n", pAux->pConta->nome);
        printf("senha: %d\n", pAux->pConta->senha);
        printf("registro: %d\n", pAux->pConta->registro);
        printf("Dinheiro na conta: %.2f\n", pAux->pConta->dinheiro);
        printf("-------------------------\n");
        pAux = pAux->pProximo;
    }
}

//------------------------------------------------------

void CadastrarConta()
{
    CONTA *pConta = AbrirConta();

    getchar(); // Limpa o buffer do teclado
    printf("Digite o nome do titular da conta: ");
    fgets(pConta->nome, sizeof(pConta->nome), stdin);
    pConta->nome[strcspn(pConta->nome, "\n")] = '\0'; // Remove a nova linha

    printf("Digite seu código de registro: ");
    scanf("%d", &pConta->registro);

    printf("Digite sua senha: ");
    scanf("%d", &pConta->senha);

    printf("Digite quantos reais vai depositar na abertura da conta: ");
    scanf("%f", &pConta->dinheiro);

    InsereLista(pConta);
}

//-------------------------------------------------------------------------------

void Menu()
{
    int opcao;

    do
    {
        printf("Menu:\n");
        printf("1. Abrir conta\n");
        printf("2. Imprimir contas\n");
       // printf("3. Salvar Cadastro\n");
       // printf("4. Carregar Cadastro\n");
       // printf("5. Buscar Pessoa\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:               
                AbrirConta();
                break;
            case 2:
                ImprimeConta();
                break;
            case 6:
                printf("Saindo do programa...\n");
                break;
            
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
        

    } while (opcao != 5);
}