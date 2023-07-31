#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() // Fun��o responsavel por cadastrar os usu�rios no sistemas
{
	//inicio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o das variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // abre o arquivo e o "w" significa escrever 
	fprintf(file, cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo "a" significa acrescentar 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", nome); // %s refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,nome); //salva o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,","); //acrescenta texto
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", sobrenome);// %s refere-se a string
	
	file = fopen(arquivo,"a"); // abre o arquivo
	fprintf(file,sobrenome);//salva o valor da variavel 
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo 
	fprintf(file,",");//acrescenta texto
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // coletando informa��o do usu�rio 
	scanf("%s", cargo); // %s refere-se a string
	
	file = fopen(arquivo,"a"); // abre o arquivo
	fprintf(file,cargo);// salva o valor da variavel 
	fclose(file);// fecha o arquivo
	
	system("pause"); // pausa a fun��o 
	
}

int consulta()// Fun��o responsavel por consultar os usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	// inicio da cria��o das variaveis/string
	char cpf[40];
	char conteudo[200];
	// Final da cria��o das variaveis/string
	
	printf("Digite o CPF a ser consultado: "); // coletando informa��o do usu�rio
	scanf("%s",cpf); // %s refere-se a string 
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // abre o arquivo, "r" significa leitura
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // pausa a fun��o 
}

int deletar() //Fun��o responsavel por deletar os usu�rios do sistema 
{
	// inicio da cria��o da variavel/string
	char cpf[40];
	// final da cria��o da variavel/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // Coletando inrfoma��o do usu�rio
	scanf("%s",cpf);//%s refere-se a string
	
	remove(cpf);// remove as informa��es solicitadas
	
	FILE * file; // cria o arquivo 
	file = fopen(cpf, "r"); // abre o arquivo, "r" significa leitura
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; // Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) // La�o de repeti��o
	{
		
		system("cls"); 
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cart�rio da EBAC ### \n\n"); // Inicio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - deletar nomes\n\n"); 
		printf("Op��o: "); // Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usu�rio
		
		system("cls"); // Responsavel por limpar a tela
		
		switch(opcao) // Inicio da sele��o do menu
		{
			case 1:
			registro();	// chamada de fun��es 	
			break;
			
			case 2:
			consulta();
			break;
				
			case 3:
			deletar();
			break;		
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;	
		}  // Fim da sele��o
	
	}
	
}


