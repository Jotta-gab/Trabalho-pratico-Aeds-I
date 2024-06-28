#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defini��o das estruturas para Cliente, Funcion�rio, Estadia e Quarto
typedef struct
{
    int codigo;
    char nome[100];
    char endereco[100];
    char telefone[20];
} Cliente;

typedef struct
{
    int codigo;
    char nome[100];
    char telefone[20];
    char cargo[50];
    float salario;
} Funcionario;

typedef struct
{
    int codigo;
    char data_entrada[11];
    char data_saida[11];
    int quantidade_diarias;
    int codigo_cliente;
    int numero_quarto;
} Estadia;

typedef struct
{
    int numero;
    int quantidade_hospedes;
    float valor_diaria;
    char status[20];
} Quarto;

// Prot�tipos das fun��es para salvar, carregar, cadastrar, pesquisar e listar
void slv_cliente(Cliente *clientes, int total_clientes);
void slv_funcionario(Funcionario *funcionarios, int total_funcionarios);
void slv_estadia(Estadia *estadias, int total_estadias);
void slv_quarto(Quarto *quartos, int total_quartos);
void carregar_client(Cliente *clientes, int *total_clientes);
void carregar_func(Funcionario *funcionarios, int *total_funcionarios);
void carregar_estd(Estadia *estadias, int *total_estadias);
void carregar_qrt(Quarto *quartos, int *total_quartos);
void cadastro_client(Cliente *clientes, int *total_clientes);
void cadastro_func(Funcionario *funcionarios, int *total_funcionarios);
void cadastro_estd(Estadia *estadias, int *total_estadias, Cliente *clientes, int total_clientes, Quarto *quartos, int *total_quartos);
void cadastro_qrt(Quarto *quartos, int *total_quartos);
void pesq_clint(Cliente *clientes, int total_clientes);
void pesq_func(Funcionario *funcionarios, int total_funcionarios);
void estd_cliente(Estadia *estadias, int total_estadias, int codigo_cliente);
void lt_clientes(Cliente *clientes, int total_clientes);
void lt_func(Funcionario *funcionarios, int total_funcionarios);
void lt_qrt(Quarto *quartos, int total_quartos);
void lt_estd(Estadia *estadias, int total_estadias);
void baixa_estadia(Estadia *estadias, int *total_estadias, Quarto *quartos, int total_quartos, int codigo_cliente);

// Fun��es para salvar os dados em arquivos bin�rios
void slv_cliente(Cliente *clientes, int total_clientes)
{
    FILE *file = fopen("clientes.dat", "wb"); // Abre o arquivo clientes.dat para escrita bin�ria
    if (file)
    {
        fwrite(clientes, sizeof(Cliente), total_clientes, file); // Escreve os dados do array clientes no arquivo
        fclose(file); // Fecha o arquivo
    }
    else
    {
        printf("Erro ao abrir arquivo de clientes\n"); // Exibe mensagem de erro se n�o conseguir abrir o arquivo
    }
}

void slv_funcionario(Funcionario *funcionarios, int total_funcionarios)
{
    FILE *file = fopen("funcionarios.dat", "wb"); // Abre o arquivo funcionarios.dat para escrita bin�ria
    if (file)
    {
        fwrite(funcionarios, sizeof(Funcionario), total_funcionarios, file); // Escreve os dados do array funcionarios no arquivo
        fclose(file); // Fecha o arquivo
    }
    else
    {
        printf("Erro ao abrir o arquivo de funcionarios.\n"); // Exibe mensagem de erro se n�o conseguir abrir o arquivo
    }
}

void slv_estadia(Estadia *estadias, int total_estadias)
{
    FILE *file = fopen("estadias.dat", "wb"); // Abre o arquivo estadias.dat para escrita bin�ria
    if (file)
    {
        fwrite(estadias, sizeof(Estadia), total_estadias, file); // Escreve os dados do array estadias no arquivo
        fclose(file); // Fecha o arquivo
    }
    else
    {
        printf("Erro ao abrir o arquivo de estadias.\n"); // Exibe mensagem de erro se n�o conseguir abrir o arquivo
    }
}

void slv_quarto(Quarto *quartos, int total_quartos)
{
    FILE *file = fopen("quartos.dat", "wb"); // Abre o arquivo quartos.dat para escrita bin�ria
    if (file)
    {
        fwrite(quartos, sizeof(Quarto), total_quartos, file); // Escreve os dados do array quartos no arquivo
        fclose(file); // Fecha o arquivo
    }
    else
    {
        printf("Erro ao abrir o arquivo de quartos.\n"); // Exibe mensagem de erro se n�o conseguir abrir o arquivo
    }
}

// Fun��es para carregar os dados salvos dos arquivos bin�rios para os arrays
void carregar_client(Cliente *clientes, int *total_clientes)
{
    FILE *file = fopen("clientes.dat", "rb"); // Abre o arquivo clientes.dat para leitura bin�ria
    if (file)
    {
        *total_clientes = fread(clientes, sizeof(Cliente), 100, file); // L� os dados do arquivo para o array clientes
        fclose(file); // Fecha o arquivo
    }
    else
    {
        printf("Erro ao abrir o arquivo de clientes.\n"); // Exibe mensagem de erro se n�o conseguir abrir o arquivo
    }
}

void carregar_func(Funcionario *funcionarios, int *total_funcionarios)
{
    FILE *file = fopen("funcionarios.dat", "rb"); // Abre o arquivo funcionarios.dat para leitura bin�ria
    if (file)
    {
        *total_funcionarios = fread(funcionarios, sizeof(Funcionario), 100, file); // L� os dados do arquivo para o array funcionarios
        fclose(file); // Fecha o arquivo
    }
    else
    {
        printf("Erro ao abrir o arquivo de funcionarios.\n"); // Exibe mensagem de erro se n�o conseguir abrir o arquivo
    }
}

void carregar_estd(Estadia *estadias, int *total_estadias)
{
    FILE *file = fopen("estadias.dat", "rb"); // Abre o arquivo estadias.dat para leitura bin�ria
    if (file)
    {
        *total_estadias = fread(estadias, sizeof(Estadia), 100, file); // L� os dados do arquivo para o array estadias
        fclose(file); // Fecha o arquivo
    }
    else
    {
        printf("Erro ao abrir o arquivo de estadias.\n"); // Exibe mensagem de erro se n�o conseguir abrir o arquivo
    }
}

void carregar_qrt(Quarto *quartos, int *total_quartos)
{
    FILE *file = fopen("quartos.dat", "rb"); // Abre o arquivo quartos.dat para leitura bin�ria
    if (file)
    {
        *total_quartos = fread(quartos, sizeof(Quarto), 100, file); // L� os dados do arquivo para o array quartos
        fclose(file); // Fecha o arquivo
    }
    else
    {
        printf("Erro ao abrir o arquivo de quartos.\n"); // Exibe mensagem de erro se n�o conseguir abrir o arquivo
    }
}

// Fun��o para cadastrar um novo cliente no sistema
void cadastro_client(Cliente *clientes, int *total_clientes)
{
    Cliente novo_cliente;
    printf("Codigo do Cliente: ");
    scanf("%d", &novo_cliente.codigo);

    // Verifica se j� existe um cliente com o mesmo c�digo
    for (int i = 0; i < *total_clientes; i++)
    {
        if (clientes[i].codigo == novo_cliente.codigo)
        {
            printf("Erro: Ja existe um cliente com este codigo.\n");
            return;
        }
    }

    // Pede e l� nome, endere�o e telefone do novo cliente
    printf("Nome: ");
    getchar();
    fgets(novo_cliente.nome, 100, stdin);
    novo_cliente.nome[strcspn(novo_cliente.nome, "\n")] = '\0';

    printf("Endereco: ");
    fgets(novo_cliente.endereco, 100, stdin);
    novo_cliente.endereco[strcspn(novo_cliente.endereco, "\n")] = '\0';

    printf("Telefone: ");
    fgets(novo_cliente.telefone, 20, stdin);
    novo_cliente.telefone[strcspn(novo_cliente.telefone, "\n")] = '\0';

    // Adiciona o novo cliente ao array de clientes
    clientes[*total_clientes] = novo_cliente;
    (*total_clientes)++;

    printf("Cliente cadastrado com sucesso!\n");
}

// Fun��o para cadastrar um novo funcion�rio no sistema
void cadastro_func(Funcionario *funcionarios, int *total_funcionarios)
{
    Funcionario novo_funcionario;
    printf("Codigo do Funcionario: ");
    scanf("%d", &novo_funcionario.codigo);

    // Verifica se j� existe um funcion�rio com o mesmo c�digo
    for (int i = 0; i < *total_funcionarios; i++)
    {
        if (funcionarios[i].codigo == novo_funcionario.codigo)
        {
            printf("Erro: Ja existe um funcionario com este codigo.\n");
            return;
        }
    }

    // Pede e l� nome, telefone, cargo e sal�rio do novo funcion�rio
    printf("Nome: ");
    getchar();
    fgets(novo_funcionario.nome, 100, stdin);
    novo_funcionario.nome[strcspn(novo_funcionario.nome, "\n")] = '\0';

    printf("Telefone: ");
    fgets(novo_funcionario.telefone, 20, stdin);
    novo_funcionario.telefone[strcspn(novo_funcionario.telefone, "\n")] = '\0';

    printf("Cargo: ");
    fgets(novo_funcionario.cargo, 50, stdin);
    novo_funcionario.cargo[strcspn(novo_funcionario.cargo, "\n")] = '\0';

    printf("Salario: ");
    scanf("%f", &novo_funcionario.salario);

    // Adiciona o novo funcion�rio ao array de funcion�rios
    funcionarios[*total_funcionarios] = novo_funcionario;
    (*total_funcionarios)++;

    printf("Funcionario cadastrado com sucesso!\n");
}

// Fun��o para cadastrar uma nova estadia no sistema
void cadastro_estd(Estadia *estadias, int *total_estadias, Cliente *clientes, int total_clientes, Quarto *quartos, int *total_quartos)
{
    Estadia nova_estadia;
    printf("Codigo do Cliente: ");
    scanf("%d", &nova_estadia.codigo_cliente);

    // Verifica se o cliente existe
    int cliente_existe = 0;
    for (int i = 0; i < total_clientes; i++)
    {
        if (clientes[i].codigo == nova_estadia.codigo_cliente)
        {
            cliente_existe = 1;
            break;
        }
    }

    if (!cliente_existe)
    {
        printf("Cliente nao encontrado.\n");
        return;
    }

    // Pede e l� n�mero do quarto, datas de entrada e sa�da, e quantidade de di�rias
    printf("Numero do Quarto: ");
    scanf("%d", &nova_estadia.numero_quarto);

    // Verifica se o quarto est� dispon�vel
    int quarto_disponivel = 0;
    for (int i = 0; i < *total_quartos; i++)
    {
        if (quartos[i].numero == nova_estadia.numero_quarto && strcmp(quartos[i].status, "Disponivel") == 0)
        {
            quarto_disponivel = 1;
            break;
        }
    }

    if (!quarto_disponivel)
    {
        printf("Quarto nao disponivel.\n");
        return;
    }

    printf("Data de Entrada (DD/MM/AAAA): ");
    scanf("%s", nova_estadia.data_entrada);

    printf("Data de Saida (DD/MM/AAAA): ");
    scanf("%s", nova_estadia.data_saida);

    printf("Quantidade de Diarias: ");
    scanf("%d", &nova_estadia.quantidade_diarias);

    // Atualiza o status do quarto para Indispon�vel
    for (int i = 0; i < *total_quartos; i++)
    {
        if (quartos[i].numero == nova_estadia.numero_quarto)
        {
            strcpy(quartos[i].status, "Indisponivel");
            break;
        }
    }

    // Adiciona a nova estadia ao array de estadias
    estadias[*total_estadias] = nova_estadia;
    (*total_estadias)++;

    printf("Estadia cadastrada com sucesso!\n");
}

// Fun��o para cadastrar um novo quarto no sistema
void cadastro_qrt(Quarto *quartos, int *total_quartos)
{
    Quarto novo_quarto;
    printf("Numero do Quarto: ");
    scanf("%d", &novo_quarto.numero);

    // Verifica se j� existe um quarto com o mesmo n�mero
    for (int i = 0; i < *total_quartos; i++)
    {
        if (quartos[i].numero == novo_quarto.numero)
        {
            printf("Erro: Ja existe um quarto com este numero.\n");
            return;
        }
    }

    // Pede e l� quantidade de h�spedes, valor da di�ria e status do novo quarto
    printf("Quantidade de Hospedes: ");
    scanf("%d", &novo_quarto.quantidade_hospedes);

    printf("Valor da Diaria: ");
    scanf("%f", &novo_quarto.valor_diaria);

    printf("Status (Disponivel/Indisponivel): ");
    scanf("%s", novo_quarto.status);

    // Adiciona o novo quarto ao array de quartos
    quartos[*total_quartos] = novo_quarto;
    (*total_quartos)++;

    printf("Quarto cadastrado com sucesso!\n");
}

// Fun��o para pesquisar um cliente pelo c�digo
void pesq_clint(Cliente *clientes, int total_clientes)
{
    int codigo;
    printf("Codigo do Cliente: ");
    scanf("%d", &codigo);

    // Procura pelo cliente com o c�digo fornecido e exibe suas informa��es
    for (int i = 0; i < total_clientes; i++)
    {
        if (clientes[i].codigo == codigo)
        {
            printf("Nome: %s\n", clientes[i].nome);
            printf("Endereco: %s\n", clientes[i].endereco);
            printf("Telefone: %s\n", clientes[i].telefone);
            return;
        }
    }

    printf("Cliente nao encontrado.\n");
}

// Fun��o para pesquisar um funcion�rio pelo c�digo
void pesq_func(Funcionario *funcionarios, int total_funcionarios)
{
    int codigo;
    printf("Codigo do Funcionario: ");
    scanf("%d", &codigo);

    // Procura pelo funcion�rio com o c�digo fornecido e exibe suas informa��es
    for (int i = 0; i < total_funcionarios; i++)
    {
        if (funcionarios[i].codigo == codigo)
        {
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("Telefone: %s\n", funcionarios[i].telefone);
            printf("Cargo: %s\n", funcionarios[i].cargo);
            printf("Salario: %.2f\n", funcionarios[i].salario);
            return;
        }
    }

    printf("Funcionario nao encontrado.\n");
}

// Fun��o para listar todos os clientes cadastrados
void lt_clientes(Cliente *clientes, int total_clientes)
{
    printf("Lista de Clientes:\n");
    for (int i = 0; i < total_clientes; i++)
    {
        printf("Codigo: %d | Nome: %s | Endereco: %s | Telefone: %s\n",
               clientes[i].codigo, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
    }
}

// Fun��o para listar todos os funcion�rios cadastrados
void lt_func(Funcionario *funcionarios, int total_funcionarios)
{
    printf("Lista de Funcionarios:\n");
    for (int i = 0; i < total_funcionarios; i++)
    {
        printf("Codigo: %d | Nome: %s | Telefone: %s | Cargo: %s | Salario: %.2f\n",
               funcionarios[i].codigo, funcionarios[i].nome, funcionarios[i].telefone, funcionarios[i].cargo, funcionarios[i].salario);
    }
}

// Fun��o para listar todos os quartos cadastrados
void lt_qrt(Quarto *quartos, int total_quartos)
{
    printf("Lista de Quartos:\n");
    for (int i = 0; i < total_quartos; i++)
    {
        printf("Numero: %d | Capacidade: %d | Diaria: %.2f | Status: %s\n",
               quartos[i].numero, quartos[i].quantidade_hospedes, quartos[i].valor_diaria, quartos[i].status);
    }
}

// Fun��o para listar todas as estadias cadastradas
void lt_estd(Estadia *estadias, int total_estadias)
{
    printf("Lista de Estadias:\n");
    for (int i = 0; i < total_estadias; i++)
    {
        printf("Codigo: %d | Cliente: %d | Quarto: %d | Entrada: %s | Saida: %s | Diarias: %d\n",
               i + 1, estadias[i].codigo_cliente, estadias[i].numero_quarto, estadias[i].data_entrada, estadias[i].data_saida, estadias[i].quantidade_diarias);
    }
}

// Fun��o para dar baixa em uma estadia, marcando o quarto como dispon�vel
void baixa_estadia(Estadia *estadias, int *total_estadias, Quarto *quartos, int total_quartos, int codigo_cliente)
{
    int encontrou_estadia = 0;
    for (int i = 0; i < *total_estadias; i++)
    {
        if (estadias[i].codigo_cliente == codigo_cliente)
        {
            // Marca o quarto da estadia como dispon�vel
            for (int j = 0; j < total_quartos; j++)
            {
                if (quartos[j].numero == estadias[i].numero_quarto)
                {
                    strcpy(quartos[j].status, "Disponivel");
                    break;
                }
            }

            // Remove a estadia do sistema
            for (int k = i; k < *total_estadias - 1; k++)
            {
                estadias[k] = estadias[k + 1];
            }
            (*total_estadias)--;
            encontrou_estadia = 1;
            break;
        }
    }

    if (encontrou_estadia)
    {
        printf("Baixa realizada com sucesso.\n");
    }
    else
    {
        printf("Cliente nao possui estadia registrada.\n");
    }
}

// Fun��o principal (main) onde o programa come�a a execu��o
int main()
{
    Cliente clientes[100]; // Array para armazenar clientes
    Funcionario funcionarios[100]; // Array para armazenar funcion�rios
    Estadia estadias[100]; // Array para armazenar estadias
    Quarto quartos[100]; // Array para armazenar quartos
    int total_clientes = 0; // Vari�vel para controlar o total de clientes cadastrados
    int total_funcionarios = 0; // Vari�vel para controlar o total de funcion�rios cadastrados
    int total_estadias = 0; // Vari�vel para controlar o total de estadias cadastradas
    int total_quartos = 0; // Vari�vel para controlar o total de quartos cadastrados
    int opcao;

    // Loop principal do programa
    do
    {
        // Menu de op��es
        printf("\n-- Menu Principal --\n");
        printf("1. Cadastro de Clientes\n");
        printf("2. Cadastro de Funcionarios\n");
        printf("3. Cadastro de Estadias\n");
        printf("4. Cadastro de Quartos\n");
        printf("5. Pesquisar Cliente\n");
        printf("6. Pesquisar Funcionario\n");
        printf("7. Listar Clientes\n");
        printf("8. Listar Funcionarios\n");
        printf("9. Listar Quartos\n");
        printf("10. Listar Estadias\n");
        printf("11. Dar Baixa em Estadia\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Executa a op��o escolhida pelo usu�rio
        switch (opcao)
        {
        case 1:
            cadastro_client(clientes, &total_clientes);
            slv_cliente(clientes, total_clientes);
            break;
        case 2:
            cadastro_func(funcionarios, &total_funcionarios);
            slv_funcionario(funcionarios, total_funcionarios);
            break;
        case 3:
            cadastro_estd(estadias, &total_estadias, clientes, total_clientes, quartos, &total_quartos);
            slv_estadia(estadias, total_estadias);
            slv_quarto(quartos, total_quartos);
            break;
        case 4:
            cadastro_qrt(quartos, &total_quartos);
            slv_quarto(quartos, total_quartos);
            break;
        case 5:
            pesq_clint(clientes, total_clientes);
            break;
        case 6:
            pesq_func(funcionarios, total_funcionarios);
            break;
        case 7:
            lt_clientes(clientes, total_clientes);
            break;
        case 8:
            lt_func(funcionarios, total_funcionarios);
            break;
        case 9:
            lt_qrt(quartos, total_quartos);
            break;
        case 10:
            lt_estd(estadias, total_estadias);
            break;
        case 11:
        {
            int codigo_cliente;
            printf("Codigo do Cliente para dar baixa na estadia: ");
            scanf("%d", &codigo_cliente);
            baixa_estadia(estadias, &total_estadias, quartos, total_quartos, codigo_cliente);
            slv_estadia(estadias, total_estadias);
            slv_quarto(quartos, total_quartos);
            break;
        }
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }

    }
    while (opcao != 0);

    return 0;
}
