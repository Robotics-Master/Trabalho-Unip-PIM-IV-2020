#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 200
#include <conio.h>



int main(void) {

    char login[15] = "Covid";
    char login1[15];
    char senha[15] = "Covid";
    char senha1[15];
    char res[15] = "SIM";
    char logado;
    int calculaidade;
    int retorno;
    int risco = 0;
    struct cadastro {
    char nome[SIZE];
    char email[SIZE];
    int numero, dia, mes, ano;
    char cpf[SIZE], telefone[SIZE], cep[SIZE], diag[SIZE];
    char rua[SIZE], bairro[SIZE], cidade[SIZE], estado[SIZE], comorbidade[10], quais[SIZE];
    };
        struct cadastro pac;

    int anoAtual;
    time_t data_ano;
    time(&data_ano);
    void cadastro(){};

    struct tm * data = localtime(&data_ano);
    anoAtual = (data -> tm_year+1900);

    system("cls || clear");
    system("color 1F");

    printf("\n    ********************************************************************\n");
    printf("    ** Sistema de Cadastro para pacientes diagnosticados com COVID-19 **\n");
    printf("    ********************************************************************\n");
    printf("\n                             LOGIN: ");
    gets(login1);
    if (strcmp(login, login1) == 0) {
        printf("\n                             SENHA: ");
        gets(senha1);
        if (strcmp(senha, senha1) == 0) {
            printf("\n                       VOCE ESTA LOGADO! \n                      Cadastre o Paciente!!!");
            cadastro(cadastro);
            logado = 'S';

            system("\n pause");
            system("\n cls || clear");

        }
        else {
            printf("Senha inválida!");
        }
    }
    else {
        printf("Login inválido!");
    }

    if (logado == 'S') {
        fflush(stdin);
        FILE *ponteiroArquivo;
        ponteiroArquivo=(fopen("cadastros-dos-pacientes.txt", "a"));
        printf("\n\n     Nome do paciente: ");
        fgets(pac.nome, 200, stdin);
        printf("     CPF: ");
        fflush(stdin);
        fgets(pac.cpf, 200, stdin);
        printf("     Data de nascimento:");
        printf("\n     Dia: ");
        fflush(stdin);
        scanf("%d", &pac.dia);
        printf("     Mes: ");
        fflush(stdin);
        scanf("%d", &pac.mes);
        printf("     Ano: ");
        fflush(stdin);
        scanf("%d", &pac.ano);
        printf("     Telefone: ");
        scanf(" %30[^\n]s", &pac.telefone);

        printf("     CEP: ");
        scanf(" %30[^\n]s", &pac.cep);

        printf("     Rua: ");
        scanf(" %30[^\n]s", &pac.rua);

        printf("     Numero: ");
        fflush(stdin);
        scanf("%d", &pac.numero);
        printf("     Bairro: ");
        scanf(" %30[^\n]s", &pac.bairro);

        printf("     Cidade: ");
        scanf(" %30[^\n]s", &pac.cidade);

        printf("     Estado: ");
        scanf(" %30[^\n]s", &pac.estado);

        printf("     Email: ");
        scanf(" %30[^\n]s", &pac.email);

        printf("     Data do diagnostico: ");
        scanf(" %30[^\n]s", &pac.diag);
        setbuf(stdin, NULL);

        printf("     O paciente tem alguma comorbidade (Doencas pre-existentes)? 1. Sim / 0. Nao ");
        scanf("%d", &risco);
        setbuf(stdin, NULL);

        if(risco == 1)
        {
            strcpy(pac.comorbidade, "SIM");
            printf("     Quais Doencas Pre-Existentes? ");

            fflush(stdin);
            fgets(pac.quais, 200, stdin);
        }
        else{
            strcpy(pac.comorbidade, "NAO");
            strcpy(pac.quais, "Nenhum");
        }
        printf("\n");
        fprintf(ponteiroArquivo, "\nNome: %s", pac.nome);
        fprintf(ponteiroArquivo, "CPF: %s", pac.cpf);
        fprintf(ponteiroArquivo, "Data de nascimento: %d/%d/%d\n", pac.dia, pac.mes, pac.ano);
        fprintf(ponteiroArquivo, "Telefone: %s", pac.telefone);
        fprintf(ponteiroArquivo, "\nCEP: %s", pac.cep);
        fprintf(ponteiroArquivo, "\nRua: %s", pac.rua);
        fprintf(ponteiroArquivo, "\nNúmero: %i\n", pac.numero);
        fprintf(ponteiroArquivo, "Bairro: %s", pac.bairro);
        fprintf(ponteiroArquivo, "\nCidade: %s", pac.cidade);
        fprintf(ponteiroArquivo, "\nEstado: %s", pac.estado);
        fprintf(ponteiroArquivo, "\nEmail: %s", pac.email);
        fprintf(ponteiroArquivo, "\nData do diagnostico: %s", pac.diag);
        fprintf(ponteiroArquivo, "\nComorbidade: %s", pac.comorbidade);
        fprintf(ponteiroArquivo, "\nQuais comorbidade(s)? %s\n", pac.quais);
        calculaidade = anoAtual - pac.ano;
        if (calculaidade > 65 || risco == 1) {
            FILE *ponteiroRisco;
            ponteiroRisco=(fopen("Cadastro-do-grupo-de-risco.txt", "a"));
            fprintf(ponteiroRisco, "\nCEP: %s", pac.cep);
            fprintf(ponteiroRisco, "\nIdade: %d\n", calculaidade);
            printf("\n\nO Paciente foi identificado como pertencente ao grupo de risco.\n");
            fclose(ponteiroRisco);
    }
        fclose(ponteiroArquivo);

    }
}
