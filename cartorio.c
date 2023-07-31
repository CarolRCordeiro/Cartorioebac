#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() // Função responsavel por cadastrar os usuários no sistemas
{
	//inicio da criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação das variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // abre o arquivo e o "w" significa escrever 
	fprintf(file, cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo "a" significa acrescentar 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", nome); // %s refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,nome); //salva o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,","); //acrescenta texto
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", sobrenome);// %s refere-se a string
	
	file = fopen(arquivo,"a"); // abre o arquivo
	fprintf(file,sobrenome);//salva o valor da variavel 
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo 
	fprintf(file,",");//acrescenta texto
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // coletando informação do usuário 
	scanf("%s", cargo); // %s refere-se a string
	
	file = fopen(arquivo,"a"); // abre o arquivo
	fprintf(file,cargo);// salva o valor da variavel 
	fclose(file);// fecha o arquivo
	
	system("pause"); // pausa a função 
	
}

int consulta()// Função responsavel por consultar os usuários do sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	// inicio da criação das variaveis/string
	char cpf[40];
	char conteudo[200];
	// Final da criação das variaveis/string
	
	printf("Digite o CPF a ser consultado: "); // coletando informação do usuário
	scanf("%s",cpf); // %s refere-se a string 
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // abre o arquivo, "r" significa leitura
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // pausa a função 
}

int deletar() //Função responsavel por deletar os usuários do sistema 
{
	// inicio da criação da variavel/string
	char cpf[40];
	// final da criação da variavel/string
	
	printf("Digite o CPF do usuário a ser deletado: "); // Coletando inrfomação do usuário
	scanf("%s",cpf);//%s refere-se a string
	
	remove(cpf);// remove as informações solicitadas
	
	FILE * file; // cria o arquivo 
	file = fopen(cpf, "r"); // abre o arquivo, "r" significa leitura
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; // Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;) // Laço de repetição
	{
		
		system("cls"); 
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cartório da EBAC ### \n\n"); // Inicio do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - deletar nomes\n\n"); 
		printf("Opção: "); // Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usuário
		
		system("cls"); // Responsavel por limpar a tela
		
		switch(opcao) // Inicio da seleção do menu
		{
			case 1:
			registro();	// chamada de funções 	
			break;
			
			case 2:
			consulta();
			break;
				
			case 3:
			deletar();
			break;		
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;	
		}  // Fim da seleção
	
	}
	
}


