#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca para alocação de memória e funções auxiliares
#include <locale.h> // Biblioteca para configuração de localização
#include <string.h> // Biblioteca para manipulação de strings

int registro() // Função responsável pelo cadastro de usuários
{
    // Início da criação de variáveis/string
    char arquivo[40]; // Nome do arquivo que armazenará os dados do usuário
    char cpf[40]; // CPF do usuário
    char nome[40]; // Nome do usuário
    char sobrenome[40]; // Sobrenome do usuário
    char cargo[40]; // Cargo do usuário
    // Fim da criação de variáveis/string
    
    printf("Você selecionou o registro de usuários.\n\n");
    
    // Solicita o CPF do usuário a ser cadastrado
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf); // Lê o CPF como uma string
    
    strcpy(arquivo, cpf); // Copia o CPF para a variável arquivo, que será o nome do arquivo
    
    FILE *file; // Ponteiro para arquivo
    file = fopen(arquivo, "w"); // Abre o arquivo para escrita ("w")
    fprintf(file, cpf); // Escreve o CPF no arquivo
    fclose(file); // Fecha o arquivo
    
    // Abre o arquivo para adicionar informações
    file = fopen(arquivo, "a"); // Abre o arquivo para adicionar ("a")
    fprintf(file, ","); // Adiciona uma vírgula como separador
    fclose(file);
    
    // Solicita o nome do usuário
    printf("Digite o nome do usuário: ");
    scanf("%s", nome); // Lê o nome do usuário
    
    // Adiciona o nome ao arquivo
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    // Adiciona uma vírgula como separador
    file = fopen(arquivo, "a");
    fprintf(file, ","); 
    fclose(file);
    
    // Solicita o sobrenome do usuário
    printf("Digite o sobrenome do usuário: ");
    scanf("%s", sobrenome); // Lê o sobrenome do usuário
    
    // Adiciona o sobrenome ao arquivo
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    // Adiciona uma vírgula como separador
    file = fopen(arquivo, "a");
    fprintf(file, ","); 
    fclose(file);
    
    // Solicita o cargo do usuário
    printf("Digite o cargo do usuário: ");
    scanf("%s", cargo); // Lê o cargo do usuário
    
    // Adiciona o cargo ao arquivo
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    printf("\nRegistro realizado com sucesso!\n\n");
    
    system("pause"); // Pausa a execução para que o usuário veja a mensagem
}

int consulta() // Função responsável pela consulta de usuários
{
    setlocale(LC_ALL, "Portuguese"); // Configura o idioma para português
    
    printf("Você escolheu a consulta de usuários.\n\n");
    
    char cpf[40]; // CPF a ser consultado
    char conteudo[200]; // Buffer para armazenar o conteúdo do arquivo
    
    // Solicita o CPF para consulta
    printf("Digite o CPF que deseja consultar: ");
    scanf("%s", cpf); // Lê o CPF do usuário
    
    FILE *file; // Ponteiro para arquivo
    file = fopen(cpf, "r"); // Abre o arquivo para leitura ("r")
    
    // Verifica se o arquivo foi encontrado
    if(file == NULL) // Se o arquivo não existir
    {
        printf("O CPF digitado não localizou nenhum usuário.\n");
        system("pause");
        return; // Sai da função
    }
    
    // Lê o conteúdo do arquivo e imprime as informações encontradas
    while(fgets(conteudo, 200, file) != NULL) // Lê até 200 caracteres ou até encontrar o final do arquivo
    {
        printf("\nEssas são as informações encontradas do usuário:\n");
        printf("%s", conteudo); // Exibe o conteúdo lido
        printf("\n\n");
    }
    
    fclose(file); // Fecha o arquivo após leitura
    system("pause"); // Pausa a execução
}

int deletar() // Função responsável pela deleção de usuários
{
    setlocale(LC_ALL, "Portuguese"); // Configura o idioma para português
    
    printf("Você escolheu deletar usuários.\n\n");
    
    char cpf[40]; // CPF do usuário a ser deletado
    
    // Solicita o CPF do usuário a ser deletado
    printf("Digite o CPF do usuário que deseja deletar: ");
    scanf("%s", cpf); // Lê o CPF do usuário
    
    // Remove o arquivo correspondente ao CPF
    if (remove(cpf) == 0) // Se a remoção for bem-sucedida
    {
        printf("Usuário deletado com sucesso!\n\n");
    }
    else // Se não for possível remover
    {
        printf("O CPF digitado não foi encontrado no sistema.\n\n");
    }
    
    system("pause"); // Pausa a execução
}

int main() // Função principal
{
    int opcao = 0; // Variável para armazenar a opção do usuário
    int laco = 1; // Variável para controle de laço
    
    // Laço de repetição para o menu
    while (laco == 1) // Enquanto laco for igual a 1
    {
        system("cls"); // Limpa a tela
        
        setlocale(LC_ALL, "Portuguese"); // Configura o idioma para português
    
        printf("--- Cartório da EBAC ---\n\n"); // Título do programa
        printf("Escolha a opção desejada abaixo:\n\n");
        printf("\t1 - Registrar usuários\n");
        printf("\t2 - Consultar usuários\n");
        printf("\t3 - Deletar usuários\n\n"); 
        printf("Opção: "); // Solicita a opção do usuário
    
        scanf("%d", &opcao); // Armazena a escolha do usuário
    
        system("cls"); // Limpa a tela novamente
        
        // Verifica a opção escolhida
        switch(opcao)
        {
            case 1: // Opção para registrar usuários
                registro(); // Chama a função de registro
                break;
            
            case 2: // Opção para consultar usuários
                consulta(); // Chama a função de consulta
                break;
            
            case 3: // Opção para deletar usuários
                deletar(); // Chama a função de deleção
                break;
            
            default: // Opção inválida
                printf("Essa opção não está disponível.\nPor favor, selecione um número de 1 a 3.\n\n");
                system("pause"); // Pausa para mostrar mensagem
                break; // Fim da seleção do menu
        }
    }
}

