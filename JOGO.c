#include <stdio.h>
#include <stdlib.h>
#include <time.h>



struct jogador1
{
    char nome[50];
    int tentativas;

};

void cadastro(struct jogador1 *playerr)
{
    printf("Digite seu nome: ");
    fgets(playerr->nome, 50, stdin);
    playerr->nome[strcspn(playerr->nome, "\n")] = '\0';
}


void game(struct jogador1 *playerr)
{
    
    int vetor[10];
    int aleatorio = 0;
    int player;
    int tentativasusadas = 0;
    
    
    
    
    srand(time(NULL));


        aleatorio = rand() %101;
        
//------------------------------LÓGICA DO JOGO JÁ PRONTA--------------------------------------------------------------//
        //printf("O numero escolhido pelo PC foi %d \n", aleatorio); //RETIRAR NO FINAL

         printf("Digite um numero para ver se eh igual o do PC: \n");
         printf("Restam 10 tentativas !\n");
            scanf("%d", &player);

            vetor[0] = player; 

        for (int i = 9; i > 0; i--)
        {   
            tentativasusadas ++;
            playerr->tentativas = tentativasusadas;

            printf("Restam %d tentativas \n", i);
           
            if (player == aleatorio)
            {
                printf("PARABENS %s VOCE ACERTOU O NUMERO COM %d TENTATIVAS !\n", playerr->nome,playerr->tentativas);
                return;
            }
            else if (player < aleatorio)
            {
                printf("Voce errou Tente um valor maior: \n");
                scanf("%d", &player);
            }
            else if (i<=0)
            {
                printf("Voce perdeu, tente iniciar um novo jogo !\n");
            }
            
            else{printf("Voce errou Tente um valor menor: \n");
                scanf("%d", &player);}
        }
//---------------------------------------------------------------------------------------------------------------------//
}

int main()

{
   struct jogador1 playerr;
   int x;

    cadastro(&playerr);

    while (1)
    {
        printf(" 01 - Novo Jogo\n 2 - Ver Regras\n 3 - Sair do jogo\n");
        scanf("%d", &x);

        switch (x)
      {
        case 1:
            game(&playerr);
            break;

        case 2:
            printf("\t\t\tRegras do Jogo\t\t\t\n O computador escolhe um numero entre 1 e 100, e o jogador tenta adivinhar.\n Recebera dicas se o palpite e maior ou menor que o numero.\n O jogo registra as tentativas e continua ate o jogador acertar ou sair pelo menu.\n");

        break;

        case 3:
            printf("VOCE SAIU DO JOGO !\n");
            return 0;
        
        default:
            printf("Opcao invalida escolha novamente !\n");
            break;
      }

    }
    
      
    
    
   

   
     
        






    return 0;
}