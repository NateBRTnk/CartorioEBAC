#include <stdio.h> //biblioteca de comunica��o com usuario 
#include <stdlib.h> //biblioteca dealoca��o de espa�o em memoria
#include <locale.h> //biblioteca aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings
int registro() //Fun��o responsavel por cadastras os usu�rios no sistema
{
		//inicio cria��o de vari�veis/string	
		char arquivo [40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//final cria��o de vari�veis/string
		
		printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
		scanf("%s", cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
		
		FILE *file; // cria o arquivo
		file = fopen(arquivo, "w"); // cria o arquivo
		fprintf(file,cpf); // salva o valor da variavel
		fclose(file); // fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s" ,nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		
		printf("Digite o sobrenome a ser cadastro: ");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
}

int consulta() //Fun��o responsavel por consultar os usu�rios no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); //Linguagem definida
	//inicio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, nao localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
}

int deletar() //Fun��o responsavel por deletar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char cpf[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	

	
}

int main()
{
	int opcao=0; //definindo a linguagem
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	
	system ("cls");
	
	setlocale(LC_ALL, "Portuguese"); //Linguagem definida
	
	
	printf("### Cart�rio da Ebac ###\n\n"); //inicio do menu
	printf("Escolha a op��o desejada do menu:\n\n");
   	printf("\t1 - Registra nomes\n");
   	printf("\t2 - Consultar nomes\n");
   	printf("\t3 - Deletar nomes\n\n"); 
   	printf("\t4 - Sair do sistema \n\n");
    printf("Op��o: "); //fim do menu
   
    scanf("%d", &opcao);
   
    system("cls"); //responsavel por limpar a tela
    
    
    switch(opcao) //inicio da sele��o do menu
    {
    	case 1:
    	registro(); //chamada de fun��es
    	break;
    	
    	case 2:
	    consulta();
		break;
		
		case 3:
	    deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		default:
		printf("Essa op��o n�o esta disponivel\n");
   		system("pause");
   		break;
        
	}
	
	
    
  }   
 }
