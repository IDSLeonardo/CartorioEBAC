#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca para aloca��o de mem�ria e fun��es auxiliares
#include <locale.h> // Biblioteca para configura��o de localiza��o
#include <string.h> // Biblioteca para manipula��o de strings

int registro() // Fun��o respons�vel pelo cadastro de usu�rios
{
    // In�cio da cria��o de vari�veis/string
    char arquivo[40]; // Nome do arquivo que armazenar� os dados do usu�rio
    char cpf[40]; // CPF do usu�rio
    char nome[40]; // Nome do usu�rio
    char sobrenome[40]; // Sobrenome do usu�rio
    char cargo[40]; // Cargo do usu�rio
    // Fim da cria��o de vari�veis/string
    
    printf("Voc� selecionou o registro de usu�rios.\n\n");
    
    // Solicita o CPF do usu�rio a ser cadastrado
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf); // L� o CPF como uma string
    
    strcpy(arquivo, cpf); // Copia o CPF para a vari�vel arquivo, que ser� o nome do arquivo
    
    FILE *file; // Ponteiro para arquivo
    file = fopen(arquivo, "w"); // Abre o arquivo para escrita ("w")
    fprintf(file, cpf); // Escreve o CPF no arquivo
    fclose(file); // Fecha o arquivo
    
    // Abre o arquivo para adicionar informa��es
    file = fopen(arquivo, "a"); // Abre o arquivo para adicionar ("a")
    fprintf(file, ","); // Adiciona uma v�rgula como separador
    fclose(file);
    
    // Solicita o nome do usu�rio
    printf("Digite o nome do usu�rio: ");
    scanf("%s", nome); // L� o nome do usu�rio
    
    // Adiciona o nome ao arquivo
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    // Adiciona uma v�rgula como separador
    file = fopen(arquivo, "a");
    fprintf(file, ","); 
    fclose(file);
    
    // Solicita o sobrenome do usu�rio
    printf("Digite o sobrenome do usu�rio: ");
    scanf("%s", sobrenome); // L� o sobrenome do usu�rio
    
    // Adiciona o sobrenome ao arquivo
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    // Adiciona uma v�rgula como separador
    file = fopen(arquivo, "a");
    fprintf(file, ","); 
    fclose(file);
    
    // Solicita o cargo do usu�rio
    printf("Digite o cargo do usu�rio: ");
    scanf("%s", cargo); // L� o cargo do usu�rio
    
    // Adiciona o cargo ao arquivo
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    printf("\nRegistro realizado com sucesso!\n\n");
    
    system("pause"); // Pausa a execu��o para que o usu�rio veja a mensagem
}

int consulta() // Fun��o respons�vel pela consulta de usu�rios
{
    setlocale(LC_ALL, "Portuguese"); // Configura o idioma para portugu�s
    
    printf("Voc� escolheu a consulta de usu�rios.\n\n");
    
    char cpf[40]; // CPF a ser consultado
    char conteudo[200]; // Buffer para armazenar o conte�do do arquivo
    
    // Solicita o CPF para consulta
    printf("Digite o CPF que deseja consultar: ");
    scanf("%s", cpf); // L� o CPF do usu�rio
    
    FILE *file; // Ponteiro para arquivo
    file = fopen(cpf, "r"); // Abre o arquivo para leitura ("r")
    
    // Verifica se o arquivo foi encontrado
    if(file == NULL) // Se o arquivo n�o existir
    {
        printf("O CPF digitado n�o localizou nenhum usu�rio.\n");
        system("pause");
        return; // Sai da fun��o
    }
    
    // L� o conte�do do arquivo e imprime as informa��es encontradas
    while(fgets(conteudo, 200, file) != NULL) // L� at� 200 caracteres ou at� encontrar o final do arquivo
    {
        printf("\nEssas s�o as informa��es encontradas do usu�rio:\n");
        printf("%s", conteudo); // Exibe o conte�do lido
        printf("\n\n");
    }
    
    fclose(file); // Fecha o arquivo ap�s leitura
    system("pause"); // Pausa a execu��o
}

int deletar() // Fun��o respons�vel pela dele��o de usu�rios
{
    setlocale(LC_ALL, "Portuguese"); // Configura o idioma para portugu�s
    
    printf("Voc� escolheu deletar usu�rios.\n\n");
    
    char cpf[40]; // CPF do usu�rio a ser deletado
    
    // Solicita o CPF do usu�rio a ser deletado
    printf("Digite o CPF do usu�rio que deseja deletar: ");
    scanf("%s", cpf); // L� o CPF do usu�rio
    
    // Remove o arquivo correspondente ao CPF
    if (remove(cpf) == 0) // Se a remo��o for bem-sucedida
    {
        printf("Usu�rio deletado com sucesso!\n\n");
    }
    else // Se n�o for poss�vel remover
    {
        printf("O CPF digitado n�o foi encontrado no sistema.\n\n");
    }
    
    system("pause"); // Pausa a execu��o
}

int main() // Fun��o principal
{
    int opcao = 0; // Vari�vel para armazenar a op��o do usu�rio
    int laco = 1; // Vari�vel para controle de la�o
    
    // La�o de repeti��o para o menu
    while (laco == 1) // Enquanto laco for igual a 1
    {
        system("cls"); // Limpa a tela
        
        setlocale(LC_ALL, "Portuguese"); // Configura o idioma para portugu�s
    
        printf("--- Cart�rio da EBAC ---\n\n"); // T�tulo do programa
        printf("Escolha a op��o desejada abaixo:\n\n");
        printf("\t1 - Registrar usu�rios\n");
        printf("\t2 - Consultar usu�rios\n");
        printf("\t3 - Deletar usu�rios\n\n"); 
        printf("Op��o: "); // Solicita a op��o do usu�rio
    
        scanf("%d", &opcao); // Armazena a escolha do usu�rio
    
        system("cls"); // Limpa a tela novamente
        
        // Verifica a op��o escolhida
        switch(opcao)
        {
            case 1: // Op��o para registrar usu�rios
                registro(); // Chama a fun��o de registro
                break;
            
            case 2: // Op��o para consultar usu�rios
                consulta(); // Chama a fun��o de consulta
                break;
            
            case 3: // Op��o para deletar usu�rios
                deletar(); // Chama a fun��o de dele��o
                break;
            
            default: // Op��o inv�lida
                printf("Essa op��o n�o est� dispon�vel.\nPor favor, selecione um n�mero de 1 a 3.\n\n");
                system("pause"); // Pausa para mostrar mensagem
                break; // Fim da sele��o do menu
        }
    }
}

