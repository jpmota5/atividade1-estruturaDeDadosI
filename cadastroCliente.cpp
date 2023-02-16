#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define TAM 51

typedef struct cliente{
    char nome[50];
    char sexo[50];
    int idade, data, anoAtual;
    int dia, mes, ano;
} Cliente;


Cliente cadastrar(){
    Cliente aux;

    printf("Nome do cliente: ");
    scanf(" %s", aux.nome);
    printf("Informe seu sexo:\n[M]-Masculino\t[F]-Feminino\n");
    scanf(" %s", aux.sexo);
    printf("Informe o ano atual: ");
    scanf("%d", &aux.anoAtual);
    printf("Informe sua data de nascimento dd/mm/aaaa: ");
    scanf("%d %d %d", &aux.dia, &aux.mes, &aux.ano);

    //(aux.mesA > aux.mes || aux.mesA == aux.mes && aux.diaA >= aux.dia);
    
    return aux;
}

void imprimir(Cliente aux){
    printf("Nome: %s\n", aux.nome);
    printf("Sexo: %s\n", aux.sexo);
    printf("Data Nascimento: %d/%d/%d \n", aux.dia, aux.mes, aux.ano);
    printf("Idade:  %d anos\n", aux.idade);
}

void listar(Cliente cliente[], int cont){
    system("cls");

    if(cont == 0){
        printf("Nao ha clientes cadastrados. \n");
    }else{
        printf("Listando Clientes...\n\n");
        for(int i = 0; i < cont; i++){
            imprimir(cliente[i]);
        }
    }
    system("pause");
    system("cls");
}

void calcularIdade(){
}

int main(){
    Cliente clientes[TAM];
    int contador = 0;
    int op;

    do{
        printf("------------ MENU DE CADASTRO-----------\n");
        printf("|                                      |\n");
        printf("|         1. Cadastrar Cliente         |\n");
        printf("|         2. Listar Clientes           |\n");
        printf("|         3. Sair                      |\n");
        printf("|                                      |\n");
        printf("---------------------------------------\n");
        scanf("%d", &op);

        system("cls");

        switch(op){
            case 1:
                clientes[contador] = cadastrar();//clientes recebera um novo cliente a cada iteração do contador
                contador++;
                break;
            case 2:
                listar(clientes,  contador);
                break;
            case 3:
                system("cls");
                break;
            default:
                printf("Opcao invalida, informe uma opcao valida: ");
                scanf("%d", &op);
                break;
        }
    } while(op != 3);

    return 0;
}