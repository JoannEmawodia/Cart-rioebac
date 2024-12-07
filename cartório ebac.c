#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //bibliot�ca responsavel por cuidar das strings

int registro() // fun��o responsavel por registrar usu�rios no sistemas
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da cria��o de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�vel
	
	printf("Digite o CPF a ser cadastrado:");
	scanf("%s", cpf); //%s se refere a strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valres das strings
	
	FILE *file; //cria o aquivo no banco de dados
	file = fopen(arquivo, "w");// cria o arquivo, w de escrever em ingl�s
	fprintf(file,cpf);//salvo o valor da varivel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a"); // a de atualiza��o
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // r de ler em ingl�s
	
	if(file == NULL)
	{
		printf("Informa��o n�o localizada!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //NULL � nulo, o while � um la�o
	{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);
			printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	

	if(file == NULL)
	{
		printf("\tO usu�rio n�o se encontra no sistema!\n\n\n");
		system("pause");
	}
	
}



int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("\tCart�rio da EBAC\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n\n");
		printf("Selecione sua op��o:\n\n");//fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");
		
		switch(opcao)
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
			printf("\tObrigado por utilizar o sistema!");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel\n");
			system("pause");
			break;
			
		} //fim da sele��o

	}

}
