#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include "dos.h"
#define BUFFER_SIZE 50
const int PossicaoColuna=8;
const int COLUNA=80;
const int LINHA=20;
SOCKET conexao;
struct sockaddr_in server_address;
char mensagem[BUFFER_SIZE];
char mensagemnome[BUFFER_SIZE];
char mensagemendereco[BUFFER_SIZE];
char mensagembairro[BUFFER_SIZE];

char resposta[BUFFER_SIZE];
char nome[61];
char pizzafinaldo[20];
char bebidaglobal[20];
   int valortotalfinal;
char endereco[61];
char bairro[61];
char telefone[12];
char cpf[11];
int contadorpizza1,contadorpizza2,contadorpizza3,contadorpizza4,contadorpizza5,contadorpizza6;


  int escbebida,valorbebida1,valorbebida2,valorbebida3,valorbebida4,valorbebida5,valorbebida6;
  int valortotal=0;
      int valortotal2=0;

    char bebida[20] = "NA";
   char bebida2[20] = "NA";
   char bebida3[20] = "NA";
   char bebida4[20] = "NA";
   char bebida5[20] = "NA";
   char bebida6[20] = "NA";
   
  int escpizza,valorpizza1,valorpizza2,valorpizza3,valorpizza4,valorpizza5,valorpizza6;
    

    char pizza[20] = "NA";
   char pizza2[20] = "NA";
   char pizza3[20] = "NA";
   char pizza4[20] = "NA";
   char pizza5[20] = "NA";
   char pizza6[20] = "NA";

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void registra_winsock() { // Inicializa o uso da DLL Winsock
	WSADATA wsadata;
	if (WSAStartup(0x101, (LPWSADATA)&wsadata) != 0) {
    	printf("Winsock Error\n");
    	exit(1);
	}
}


void cria_socket_conexao() {
	conexao = socket(AF_INET, SOCK_STREAM, 0); // TCP
	if (conexao < 0) {
		printf("Socket Error\n");
		exit(1);
	}
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP do servidor
	server_address.sin_port = htons(33000); // Número da porta
}

void abre_conexao() {
	int len = sizeof(server_address);
	int result = connect(conexao, (struct sockaddr *)&server_address, len);
	if (result < 0) {
		printf("Connect Error");
		exit(1);
	}
}

void envia_mensagem() {
	send(conexao, mensagem, BUFFER_SIZE, 0);
}

void le_resposta() {
	recv(conexao, resposta, BUFFER_SIZE, 0);
}

void fecha_conexao() {
	closesocket(conexao);
}

void transmite() {
	cria_socket_conexao();
	abre_conexao();
	envia_mensagem();
	le_resposta();
	fecha_conexao();
}

void opc_par_ou_impar() {
	int numero;
	char numerostr[10];
	printf("Numero: ");
	scanf("%i", &numero);
	itoa(numero, numerostr, 10); // 10 = Base 10
	strcpy(mensagem, "PAR-OU-IMPAR ");
	strcpy(&mensagem[13], numerostr);
	transmite();
	printf("%s\n", resposta);
}

void tela(char nome[30]){
    int x,y;

    system("cls");

    for(y=0;y<3;y++){
        gotoxy(0,y);
            for(x=0;x<80;x++){
                printf("%c",14);
            }
    }

    gotoxy(2,1);
    printf("%s",nome);

    //pintar(119);
}

void reclamar(){
	char confirmaswitch,reclamando[1000],nome2[100];
	
	setlocale(LC_ALL,"Portuguese");
		system("cls");
	printf("Vamos prosseguir\n");


  
  printf("Digite seu nome:");
  gets(nome);

  gets(nome);

printf("Digite sua reclamação ou elogio:  ");
gets(reclamando);

system("cls");
printf("Confirme a reclamação ou elogio:\nNome:%s  \nReclamação: %s ",nome,reclamando);
printf("\nDigite S para confirmar ou N para não: ");
scanf("%s",&confirmaswitch);
switch(confirmaswitch){
	case 'S':

		FILE*arqr;
		arqr= fopen("reclamaçoes.txt","a+");
if (!arqr)
{
printf("Não foi possível ler o arquivo!");

}


fprintf(arqr,"\n\nNome:%s --> \nReclamação: %s ",nome,reclamando);
fclose(arqr);
		printf("Registrada com sucesso\n");
		
		strcpy(mensagem, "PAR-OU-IMPAR ");
	strcpy(&mensagem[13], nome);
		transmite();			 
	
		system("pause");
		
break;
	case 's':


		arqr= fopen("reclamaçoes.txt","a+");
if (!arqr)
{
printf("Não foi possível ler o arquivo!");

}


fprintf(arqr,"Confirme a reclamação ou elogio:\nNome:%s  \nReclamação: %s ",nome,reclamando);
fclose(arqr);
		printf("Registrada com sucesso\n");
		
		strcpy(mensagem, "PAR-OU-IMPAR ");
	strcpy(&mensagem[13], nome);
		transmite();			 
	
		system("pause");
break;
case 'N':
reclamar();
   }
}






 int opc_pizza(){
system("cls");
setlocale(LC_ALL,"Portuguese");
    FILE * pf = NULL;
FILE * pf2 = NULL;
  
   

    pf = fopen( "pizzas.txt", "r" );

    if(!pf)
        return 1;

    fscanf( pf, "\n%s\n", &pizza );

    fscanf( pf, "\n%s\n", &pizza2 );
    fscanf( pf, "\n%s\n", &pizza3 );
        fscanf( pf, "\n%s\n", &pizza4 );
    fscanf( pf, "\n%s\n", &pizza5 );
    fscanf( pf, "\n%s\n", &pizza6 );

    fclose(pf);
     pf2 = fopen( "valorp.txt", "r" );
       fscanf( pf2, "\n%d\n", &valorpizza1 );
    fscanf( pf2, "\n%d\n", &valorpizza2);
    fscanf( pf2, "\n%d\n", &valorpizza3 );
    fscanf( pf2, "\n%d\n", &valorpizza4 );
        fscanf( pf2, "\n%d\n", &valorpizza5 );
    fscanf( pf2, "\n%d\n", &valorpizza6 );
    fclose(pf2);
 printf("Nosso Cardápio de pizzas:\n");

  printf( "1: %s %d ", pizza,valorpizza1 );	
    printf("Reais\n");

  
    printf( "2: %s %d ", pizza2,valorpizza2 );
     printf("Reais\n");
    printf( "3: %s %d ", pizza3,valorpizza3 );
     printf("Reais\n");
    printf( "4: %s %d ", pizza4,valorpizza4 );
     printf("Reais\n");
 
    printf( "5: %s %d ", pizza5,valorpizza5 );
     printf("Reais\n");

  
     printf( "6: %s %d ", pizza6,valorpizza6 );
      printf("Reais\n");
      
      printf("Digite 0 para voltar: ");
  
    scanf(" %i", &escpizza);
        switch(escpizza){
          
     default:
          
break;
	  }


}
int opc_gravarpizza(){
	system("cls");
	int voltar;
	setlocale(LC_ALL,"Portuguese");
	int valor;
  char promo,palavra[20]; // variável do tipo string
   FILE *arq;
arq= fopen("pizzas.txt", "a+");
if (!arq)
{
printf("Não foi possível ler o arquivo!");

}
FILE *arq2;
arq2 = fopen("valorp.txt", "a+");
if (!arq2)
{
	printf("Não foi possível ler o arquivo !");
}



  printf("Qual sabor você quer adicionar? ");
  gets(palavra);
  gets(palavra);
    printf("Qual o valor da pizza? ");
scanf("%d",&valor);
fprintf(arq2,"\n%d",valor);
fclose(arq2);
  printf("\nÉ uma promoção?: s para Sim n para não: ");
  scanf("%s",&promo);

switch(promo){
	case 's':
		fprintf(arq,"\n[PROMOÇÃO]%s",&palavra);
fclose(arq);
printf("Pizza adicionada com sucesso");

		break;
		case 'n':
				fprintf(arq,"\n%s",&palavra);
fclose(arq);
printf("Pizza adicionada com sucesso");

			break;
				case 'S':
		fprintf(arq,"\n[PROMOÇÃO]%s",&palavra);
fclose(arq);
printf("Pizza adicionada com sucesso");

		break;
		case 'N':
				fprintf(arq,"\n%s",&palavra);
fclose(arq);
printf("Pizza adicionada com sucesso");

			break;
}
}







int opc_bebida(){
	setlocale(LC_ALL,"Portuguese");
system("cls");
    FILE * pf = NULL;
FILE * pf2 = NULL;
  
    valorbebida1 = 0;
        valorbebida2 = 0;
            valorbebida3 = 0;
                valorbebida4 = 0;
                    valorbebida5 = 0;
                        valorbebida6 = 0;
    pf = fopen( "bebidas.txt", "r" );

    if(!pf)
        return 1;

    fscanf( pf, "\n%s\n", &bebida );

    fscanf( pf, "\n%s\n", &bebida2 );
    fscanf( pf, "\n%s\n", &bebida3 );
        fscanf( pf, "\n%s\n", &bebida4 );
    fscanf( pf, "\n%s\n", &bebida5 );
    fscanf( pf, "\n%s\n", &bebida6 );

    fclose(pf);
     pf2 = fopen( "valorb.txt", "r" );
       fscanf( pf2, "\n%d\n", &valorbebida1 );
    fscanf( pf2, "\n%d\n", &valorbebida2);
    fscanf( pf2, "\n%d\n", &valorbebida3 );
    fscanf( pf2, "\n%d\n", &valorbebida4 );
        fscanf( pf2, "\n%d\n", &valorbebida5 );
    fscanf( pf2, "\n%d\n", &valorbebida6 );
    fclose(pf2);
printf("Seja bem vindo ao nosso cardápio de bebidas\n");
  printf( "1: %s %d ", bebida,valorbebida1 );	
    printf("Reais\n");

  
    printf( "2: %s %d ", bebida2,valorbebida2 );
     printf("Reais\n");
    printf( "3: %s %d ", bebida3,valorbebida3 );
     printf("Reais\n");
    printf( "4: %s %d ", bebida4,valorbebida4 );
     printf("Reais\n");
 
    printf( "5: %s %d ", bebida5,valorbebida5 );
     printf("Reais\n");

  
     printf( "6: %s %d ", bebida6,valorbebida6 );
      printf("Reais\n");
      printf("Digite 0 para voltar: ");
      
  
    scanf(" %i", &escbebida);
        switch(escbebida){
         
     default:
          
break;
	  }


}
int opc_gravarbebida(){
	system("cls");
	setlocale(LC_ALL,"Portuguese");
	int valorb;
  char palavrab[20]; // variável do tipo string
   FILE *arq3;
arq3= fopen("bebidas.txt", "a+");
if (!arq3)
{
printf("Não foi possível ler o arquivo!");

}

  printf("Qual Bebida você quer adicionar?  ");
  scanf("%s", palavrab);
fprintf(arq3,"\n%s",palavrab);
fclose(arq3);


FILE *arq4;
arq4 = fopen("valorb.txt", "a+");
if (!arq4)
{
	printf("Não foi possível ler o arquivo !");
}
printf("Qual o valor da bebida? ");
scanf("%d",&valorb);
fprintf(arq4,"\n%d",valorb);
fclose(arq4);

return 0;


}
int opc_cadastrodecliente(){
	 int valorsomado,valoratual;
	int confirmaoun;
	setlocale(LC_ALL,"Portuguese");
		system("cls");
	printf("Vamos ao cadastro:\n");


  
  printf("Digite seu nome:");
  gets(nome);

  gets(nome);

printf("Digite seu endereço com número: ");
gets(endereco);
printf("Digite seu bairro com número: ");
gets(bairro);

printf("Digite o seu número de telefone: ");
gets(telefone);
printf("Digite o seu número de cpf: ");
gets(cpf);
system("cls");
printf("Confirme o pedido:\nNome:%s  \nEndereço: %s \nBairro: %s\nTelefone: %s\nCpf: %s\nPizza:%s\nBebida:%s\nValor total:%d reais",nome,endereco,bairro,telefone,cpf,pizzafinaldo,bebidaglobal,valortotalfinal);
printf("\nDigite S para confirmar o pedido N para não: ");
scanf("%s",&confirmaoun);
switch(confirmaoun){
	case 'S':

		FILE*arq;
		arq= fopen("pedidos.txt","a+");
if (!arq)
{
printf("Não foi possível ler o arquivo!");

}


fprintf(arq,"\nNome:%s  \nEndereço: %s \nBairro: %s\nTelefone: %s\nCpf: %s\nPizza:%s\nBebida:%s\nValor total:%d reais\n",nome,endereco,bairro,telefone,cpf,pizzafinaldo,bebidaglobal,valortotalfinal);
fclose(arq);
		
		
		FILE*arquivo;
		arquivo= fopen("relatoriovendasm.txt","a+");
		
		
if (!arquivo)
{
printf("Não foi possível ler o arquivo!");

}

 


fprintf(arquivo,"\npizza:%s bebida:%s valor:%d ",pizzafinaldo,bebidaglobal,valortotalfinal);
fclose(arquivo);
printf("Pedido confirmado muito obrigado\n");
			
		
			 
		
	
	
		system("pause");
	
break;
	case 's':

		
		arq= fopen("pedidos.txt","a+");
if (!arq)
{
printf("Não foi possível ler o arquivo!");

}


fprintf(arq,"\nNome:%s  \nEndereço: %s \nBairro: %s\nTelefone: %s\nCpf: %s\nPizza:%s\nBebida:%s\nValor total:%d reais\n",nome,endereco,bairro,telefone,cpf,pizzafinaldo,bebidaglobal,valortotalfinal);
fclose(arq);
		
	
		arquivo= fopen("relatoriovendasm.txt","a+");
		
		
if (!arquivo)
{
printf("Não foi possível ler o arquivo!");

}

 


fprintf(arquivo,"\npizza:%s bebida:%s valor:%d ",pizzafinaldo,bebidaglobal,valortotalfinal);
fclose(arquivo);
printf("Pedido confirmado muito obrigado\n");
			
		
		strcpy(mensagem, "PAR-OU-IMPAR ");
	strcpy(&mensagem[13], nome);
		transmite();			 
		
	
	
		system("pause");
	
break;
case 'N':
opc_cadastrodecliente();
   }
}
int opc_finalizarpedido2(){
	system("cls");
FILE * pf = NULL;
FILE * pf2 = NULL;
  
    valorbebida1 = 0;
        valorbebida2 = 0;
            valorbebida3 = 0;
                valorbebida4 = 0;
                    valorbebida5 = 0;
                        valorbebida6 = 0;
    pf = fopen( "bebidas.txt", "r" );

    if(!pf)
        return 1;

    fscanf( pf, "\n%s\n", &bebida );

    fscanf( pf, "\n%s\n", &bebida2 );
    fscanf( pf, "\n%s\n", &bebida3 );
        fscanf( pf, "\n%s\n", &bebida4 );
    fscanf( pf, "\n%s\n", &bebida5 );
    fscanf( pf, "\n%s\n", &bebida6 );

    fclose(pf);
     pf2 = fopen( "valorb.txt", "r" );
       fscanf( pf2, "\n%d\n", &valorbebida1 );
    fscanf( pf2, "\n%d\n", &valorbebida2);
    fscanf( pf2, "\n%d\n", &valorbebida3 );
    fscanf( pf2, "\n%d\n", &valorbebida4 );
        fscanf( pf2, "\n%d\n", &valorbebida5 );
    fscanf( pf2, "\n%d\n", &valorbebida6 );
    fclose(pf2);

  printf( "1: %s %d ", bebida,valorbebida1 );	
    printf("Reais\n");

  
    printf( "2: %s %d ", bebida2,valorbebida2 );
     printf("Reais\n");
    printf( "3: %s %d ", bebida3,valorbebida3 );
     printf("Reais\n");
    printf( "4: %s %d ", bebida4,valorbebida4 );
     printf("Reais\n");
 
    printf( "5: %s %d ", bebida5,valorbebida5 );
     printf("Reais\n");

  
     printf( "6: %s %d ", bebida6,valorbebida6 );
      printf("Reais\n");
      printf("Digite 0 para voltar ou escolha o sabor ");
      
  
    scanf(" %i", &escbebida);
 
        switch(escbebida){
            case 1:
            printf("bebida 1 selecioada %s\n",bebida);
            valortotal2=+valorbebida1;
            valortotalfinal=valortotal+valortotal2;
                  strcpy(bebidaglobal, bebida);
            printf("Valor total do pedido até agora %d\n",valortotalfinal);
            system("pause");
            opc_cadastrodecliente();
            break;
            case 2:
         printf("bebida  %s selecioada \n",bebida2);
            valortotal2=+valorbebida2;
            valortotalfinal=valortotal+valortotal2;
             strcpy(bebidaglobal, bebida2);
            printf("Valor total do pedido até agora %d\n",valortotalfinal);
            system("pause");
 opc_cadastrodecliente();
            break;
            case 3:
 printf("bebida  %s selecioada \n",bebida3);
            valortotal2=+valorbebida3;
            valortotalfinal=valortotal+valortotal2;
            printf("Valor total do pedido até agora %d\n",valortotalfinal);
             strcpy(bebidaglobal, bebida3);
            system("pause");
             opc_cadastrodecliente();
            break;
            case 4:
       printf("bebida  %s selecioada \n",bebida4);
            valortotal2=+valorbebida4;
            valortotalfinal=valortotal+valortotal2;
            printf("Valor total do pedido até agora %d\n",valortotalfinal);
             strcpy(bebidaglobal, bebida4);
              opc_cadastrodecliente();
            system("pause");
            break;
            case 5:
       printf("bebida  %s selecioada \n",bebida5);
            valortotal2=+valorbebida5;
            valortotalfinal=valortotal+valortotal2;
            printf("Valor total do pedido até agora %d\n",valortotalfinal);
             strcpy(bebidaglobal, bebida5);
              opc_cadastrodecliente();
            system("pause");
          break;
          case 6:
        printf("bebida  %s selecioada \n",bebida6);
            valortotal2=+valorbebida6;
            valortotalfinal=valortotal+valortotal2;
             strcpy(bebidaglobal, bebida6);
            printf("Valor total do pedido até agora %d\n",valortotalfinal);
             opc_cadastrodecliente();
            system("pause");
          	
     default:
          
break;
	  }
}
    int finalizarpedido(){
    	system("cls");
    	valortotal=0;
    	setlocale(LC_ALL,"Portuguese");
    	int op34;
    	
    	

    	FILE * pf = NULL;
FILE * pf2 = NULL;
pf = fopen( "pizzas.txt", "r" );

    if(!pf)
        return 1;

    fscanf( pf, "\n%s\n", &pizza );

    fscanf( pf, "\n%s\n", &pizza2 );
    fscanf( pf, "\n%s\n", &pizza3 );
        fscanf( pf, "\n%s\n", &pizza4 );
    fscanf( pf, "\n%s\n", &pizza5 );
    fscanf( pf, "\n%s\n", &pizza6 );

    fclose(pf);
     pf2 = fopen( "valorp.txt", "r" );
       fscanf( pf2, "\n%d\n", &valorpizza1 );
    fscanf( pf2, "\n%d\n", &valorpizza2);
    fscanf( pf2, "\n%d\n", &valorpizza3 );
    fscanf( pf2, "\n%d\n", &valorpizza4 );
        fscanf( pf2, "\n%d\n", &valorpizza5 );
    fscanf( pf2, "\n%d\n", &valorpizza6 );
    fclose(pf2);
    	printf("Escolha uma pizza:\n ");
    	
    	  printf( "1: %s %d ", pizza,valorpizza1 );	
    printf("Reais\n");

  
    printf( "2: %s %d ", pizza2,valorpizza2 );
     printf("Reais\n");
    printf( "3: %s %d ", pizza3,valorpizza3 );
     printf("Reais\n");
    printf( "4: %s %d ", pizza4,valorpizza4 );
     printf("Reais\n");
 
    printf( "5: %s %d ", pizza5,valorpizza5 );
     printf("Reais\n");

  
     printf( "6: %s %d ", pizza6,valorpizza6 );
      printf("Reais\n");
      
      printf("Digite 0 para voltar ou escolha o sabor ");
      scanf("%d",&op34);
      
      switch(op34){
	  
      case 1:
      	contadorpizza1++;
      	printf("Você escolheu a pizza: %s\n",pizza);
      	printf("Valor total de %d\n",valorpizza1);
      	valortotal=+valorpizza1;
        strcpy(pizzafinaldo, pizza);
   
		  	system("pause");
		  opc_finalizarpedido2();
    break;
    case 2:
    	contadorpizza2++;
    		printf("Você escolheu a pizza: %s\n",pizza2);
      	printf("Valor da pizza é de %d reais \n",valorpizza2);
      	valortotal=+valorpizza2;
      strcpy(pizzafinaldo, pizza2);
		  	system("pause");
		  opc_finalizarpedido2();
    	break;
    	case 3:
    		contadorpizza3++;
    			printf("Você escolheu a pizza: %s\n",pizza3);
      	printf("Valor da pizza é de %d reais \n",valorpizza3);
      	valortotal=+valorpizza3;
     strcpy(pizzafinaldo, pizza3);
		  	system("pause");
		  opc_finalizarpedido2();
    		break;
    		case 4:
    			contadorpizza4++;
    				printf("Você escolheu a pizza: %s\n",pizza4);
      	printf("Valor da pizza é de %d reais \n",valorpizza4);
      	valortotal=+valorpizza4;
      	    	 strcpy(pizzafinaldo, pizza4);
     
		  	system("pause");
		  opc_finalizarpedido2();
    			break;
    			case 5:
    				contadorpizza5++;
    					printf("Você escolheu a pizza: %s\n",pizza5);
      	printf("Valor da pizza é de %d reais \n",valorpizza5);
      	valortotal=+valorpizza5;
      	   	 strcpy(pizzafinaldo, pizza5);
     
		  	system("pause");
		  opc_finalizarpedido2();
    				break;
    				case 6:
    					contadorpizza6++;
    						printf("Você escolheu a pizza: %s\n",pizza6);
      	printf("Valor da pizza é de %d reais \n",valorpizza6);
      	valortotal=+valorpizza6;
      	 strcpy(pizzafinaldo, pizza6);
     
		  	system("pause");
		  opc_finalizarpedido2();
    					break;
    	}
         
  }
  void opc_funcionarios(){
  	system("cls");
	  int valor,pizza;
  char reclamacoes,sabor;
  
  float valortotal=0;
   
   
    printf ("Pizzaiolos\n");
    printf("1-Weltinho\n2-Flavinho\n3-Andreus\n");

    printf("Digite 0 para voltar: \n");
    
    scanf("%i",&valor);
    
    	switch ( valor )
   			 {
    	case 1 :
    		printf("Funcionario Welton, admissao 20.07.2019\n-Funcao: Pizzaiolo\n");
      		break;
      		
    	case 2 :
    		printf("Funcionario Flavinho, admissao 20.07.2019\n-Funcao: Pizaiolo\n");
      		break;
      	case 3 :
    		printf("Funcionario Andreus, admissao 20.07.2019\n-Funcao: Pizaiolo\n");
      		break;
        
    		}
    }
  opc_controleestoque(){
  	int valor;
  	system("cls");
  	 printf ("Controle de estoque\n");
    printf("1-Adicionar pizza\n2-Adicionar bebida\n");

    printf("Digite 0 para voltar: \n");
    
    scanf("%i",&valor);
    
    	switch ( valor )
   			 {
    	case 1 :
      opc_gravarpizza();
      
      		break;
      		
    	case 2 :
     opc_gravarbebida();
      		break;
  
        
    		}
    
  }
  int relatoriomensal(){
system("cls");
printf("Seja bem vindo ao relatório de vendas:\n");
 int i = 0;
    int numPalavras = 0;
    char* palavras[50];
    char line[50];

    FILE *arquivo;
    arquivo = fopen("relatoriovendasm.txt", "r");

    if (arquivo == NULL)
        return EXIT_FAILURE;

    while(fgets(line, sizeof line, arquivo) != NULL)
    {
   
        palavras[i] = strdup(line);

        i++;

        
        numPalavras++;
    }

    int j;

    for (j = 0; j < numPalavras; j++)
        printf("\n%s", palavras[j]); //Exibi as palavras que estao no vetor.

    printf("\n\n");

    fclose(arquivo);
    system("pause");
  }
  
int opc_contador(){
	system("cls");
setlocale(LC_ALL,"Portuguese");
    FILE * pf = NULL;
FILE * pf2 = NULL;
  
   

    pf = fopen( "pizzas.txt", "r" );

    if(!pf)
        return 1;
	fscanf( pf, "\n%s\n", &pizza );

    fscanf( pf, "\n%s\n", &pizza2 );
    fscanf( pf, "\n%s\n", &pizza3 );
        fscanf( pf, "\n%s\n", &pizza4 );
    fscanf( pf, "\n%s\n", &pizza5 );
    fscanf( pf, "\n%s\n", &pizza6 );
    
    printf("\nA pizza %s foi vendida %d vezes",pizza,contadorpizza1);
      printf("\nA pizza %s foi vendida %d vezes",pizza2,contadorpizza2);
        printf("\nA pizza %s foi vendida %d vezes",pizza3,contadorpizza3);
          printf("\nA pizza %s foi vendida %d vezes",pizza4,contadorpizza4);
            printf("\nA pizza %s foi vendida %d vezes",pizza5,contadorpizza5);
              printf("\nA pizza %s foi vendida %d vezes",pizza6,contadorpizza6);
              system("pause");
}
int relatorio_menu(){
	int oprelatorio;
	setlocale(LC_ALL,"Portuguese");
	system("cls");
	printf("Seja bem vindo ao menu de relatórios,escolha uma opção\n");
	printf("1.Relatório mensal\n");
	printf("2 Pizzas mais vendidas hoje\n");
	scanf("%d",&oprelatorio);
	switch(oprelatorio){
		case 1:
			relatoriomensal();
			break;
			case 2:
				opc_contador();
				break;
	}
}


void MenuPrincipal(){ //Menu principal para e seleçao da fanquia
setlocale(LC_ALL,"Portuguese");
    int ops,ops1=1,x=1;
    char nome[15]={'M','e','n','u',' ','P','r','i','n','c','i','p','a','l'};
    do{
    tela(nome);
    if(x==0){
    gotoxy(PossicaoColuna*3,4);
    printf("Opcao invalida");
    }
    gotoxy(PossicaoColuna*2,5);
    printf("Bem vindo a Pizzaria");
    gotoxy(PossicaoColuna,7);

    printf("1.Cardápio de Pizzas");
    gotoxy(PossicaoColuna,9);
    printf("2.Cardápio de Bebidas");
    gotoxy(PossicaoColuna,11);
    printf("3.Fazer novo pedido");
    gotoxy(PossicaoColuna,13);
    printf("4.Nossos funcionarios");
     gotoxy(PossicaoColuna,15);
    printf("5.Controle de estoque");
    gotoxy(PossicaoColuna,17);
         printf("6.Elogios ou reclamações");
     gotoxy(PossicaoColuna,19);
     printf("7.Relatório de vendas");
   gotoxy(PossicaoColuna,21);
    printf(" ___");
     gotoxy(PossicaoColuna+1,21);
    scanf(" %i", &ops);
        switch(ops){
            case 1:
            opc_pizza();

            break;
            case 2:
           opc_bebida();

            break;
            case 3:
   finalizarpedido();

            break;
            case 4:
            	opc_funcionarios();
            break;
            case 5:
            	opc_controleestoque();
    
      break;
    case 6:
    	reclamar();
    	 
          break;
          case 7:
          	relatorio_menu();
         
          	break;
          	
     default:
                x=0;

	  }
	}while(ops1!=0);
}
    

    
    
    
    

void FazerLogin(){
    int total_contas = 0, arq_tamanho = 0, op = 0, i;

    struct usuarios_infos {
        char login[10];
        char senha[10];
    };

    struct usuarios_infos usuario_cadastrado, *lista_de_contas;


    FILE* logs;

    while (op != 3){
            printf("######################### - UNIP  - ######################### \n");
            printf("*************************************************************\n");
            printf("             SISTEMA DE GERENCIAMENTO DE PIZZARIAS\n");
            printf("*************************************************************\n");
            printf("-------------------------------------------------------------\n");
            printf("             MENU INICIAL\n");
            printf("-------------------------------------------------------------\n");


        printf("\n 1 - Cadastrar nova conta\n");
        printf(" 2 - Fazer login\n");
        printf(" 3 - Sair\n");

        printf("\nOpcao: ");
        scanf("%d%*c", &op);

        switch(op){
            case 1:
                logs = fopen ("contas.db","ab");
                if(logs == NULL)
                {
                    printf("\nErro ao tentar abrir o arquivo.\n\n");
                }
                else
                {
                    memset(&usuario_cadastrado,0,sizeof(struct usuarios_infos));
                    printf("Cadastrar usuario: ");
                    scanf("%s", usuario_cadastrado.login);
                    printf("Cadastrar senha: ");
                    scanf("%s", usuario_cadastrado.senha);
                    fwrite(&usuario_cadastrado, sizeof usuario_cadastrado, 1, logs);
                    fclose(logs);
                }
                break;

            case 2:

                memset(&usuario_cadastrado, 0, sizeof(struct usuarios_infos));
                printf("USUARIO: ");
                scanf("%s", usuario_cadastrado.login);
                printf("SENHA: ");
                scanf("%s", usuario_cadastrado.senha);

                logs = fopen ("contas.db","rb");
                if(logs == NULL)
                {
                    printf("\nErro ao tentar abrir o arquivo.\n\n");
                }
                else
                {
                    fseek(logs,0,SEEK_END);
                    arq_tamanho = ftell(logs);
                    total_contas = arq_tamanho / sizeof (struct usuarios_infos);
                    rewind(logs);
                
                    if(fread(lista_de_contas, sizeof usuario_cadastrado, total_contas, logs) != total_contas)
                    {
                        printf("Falha ao tentar ler contas\n");
                        fclose(logs);
                        free(lista_de_contas);
                    
                    }
                    fclose(logs);
                    for (i=0; i<total_contas; i++){
                        if(memcmp(&usuario_cadastrado, &lista_de_contas[i], sizeof(struct usuarios_infos)) == 0)
                        {
                           printf("\n LOGADO COM SUCESSO\n");
                                 system("cls");

    MenuPrincipal();
                             op = 3;
                            break;
                        }
                    }
                    if(i == total_contas)
                    {
                        printf("\n Acesso NEGADO\n");
                        system("cls");
                    }
                    free(lista_de_contas);
                }
                break;

            case 3:
            
                break;

            default:
                printf("\n Opcao invalida!\n");
        }
    }


}

 

int main(int argc, char *argv[]) {
FazerLogin();
}

