#include <iostream.h>
#include <conio.h>
#include <locale.h>
#include <iomanip>
#define MAX 50

struct quartos{
    int nquartos, acomod, refcliente, status;
    float preco;
};

struct cliente{
    int refquartos, livre, dia1, mes1, ano1, dia2, mes2, ano2;
    char nome[20], cpf[12];
    float despextra, total;
};

void tela();
int inseririnf(quartos p[MAX]);
void inserhosp(cliente c [MAX],quartos p [MAX],int totalquartos);
void listarinf_ocup(cliente c [MAX], quartos p[MAX], int totalquartos);
void listarinf_all(cliente c [MAX], quartos p[MAX], int totalquartos);
void alterastatus(quartos p[MAX], int totalquartos);
void despesasextras(cliente c [MAX],quartos p [MAX],int totalquartos);
void final(cliente c [MAX],quartos p [MAX],int totalquartos);



int main()
{
//Personalização de Cor
system("color 17");
//Configurando Idioma
setlocale(LC_ALL, "Portuguese");

system("cls");
tela();
//Inicio
quartos p[MAX];
cliente c[MAX];
int i;
for(i=0;i<MAX;i++){
    c[i].livre=0;
    c[i].despextra=0;
}
int totalquartos, escolha;
cout << "\n Seja bem vindo ao sistema de controle de Pousadas.\n\n";
cout << "  Primeiramente, insira os dados de todos os quartos da pousada.";
cout << "\n\n\n     Pressione ENTER para começar.";
getch();
totalquartos=inseririnf(p)-1;

system("cls");
tela();
do{
        system("cls");
        tela();
        cout << " 1 - Registrar entrada de hospedes";
        cout << "\n\n 2 - Inserir despesas extras para hospedes";
        cout << "\n\n 3 - Registrar saída de hospedes";
        cout << "\n\n 4 - Alterar status do quarto";
        cout << "\n\n 5 - Listar todos os quartos";
        cout << "\n\n 6 - Listar quartos ocupados";
        cout << "\n                                                                   7 - Finalizar";

        cin >> escolha;
        while(escolha > 7 || escolha < 1){
            cout << "Opção inválida! Tente novamente:";
            cin >> escolha;
        }
        if (escolha == 1){
            inserhosp(c, p, totalquartos);
        }
        if (escolha == 2){
            despesasextras(c, p, totalquartos);
        }
        if (escolha == 3){
            final(c, p, totalquartos);
        }
        if (escolha == 4){
            alterastatus(p, totalquartos);
        }
        if (escolha == 5){
            listarinf_all(c, p, totalquartos);
        }
        if (escolha == 6){
            listarinf_ocup(c, p, totalquartos);
        }


}while(escolha!=7);
}

void tela(){
       cout << "                        ___  ____  __  _________   ___  ___ \n";
       cout << "                       / _ \\/ __ \\/ / / / __/ _ | / _ \\/ _ |\n";
       cout << "                      / ___/ /_/ / /_/ /\\ \\/ __ |/ // / __ |\n";
       cout << "                     /_/   \\____/\\____/___/_/ |_/____/_/ |_|\n";
       cout << "                      _________   ___  ___     _____   ___  ___ \n";
       cout << "                     /_  __/ _ | / _ )/ _ |__ / / _ | / _ \\/ _ |\n";
       cout << "                      / / / __ |/ _  / __ / // / __ |/ , _/ __ |\n";
       cout << "                     /_/ /_/ |_/____/_/ |_\\___/_/ |_/_/|_/_/ |_|\n";
       cout << "================================================================================\n";
       }



int inseririnf(quartos p[MAX]){
    int qtd_quartos, i, q=1;
    cout << "\n\n\n\n Primeiramente vamos cadastrar todos os quartos.";
    cout << "\n Insira a quantidade de quartos existentes na pousada: ";
    cin >> qtd_quartos;
    for(i=0;i<qtd_quartos;i++){
        system("cls");
        tela();
        cout << "\n Digite o número do "<<q<<"º quarto: ";
        cin >> p[i].nquartos;
        cout << "\n Digite a quantidade de acomodações do quarto nº"<<p[i].nquartos<<": ";
        cin >> p[i].acomod;
        cout << "\n Digite o preço da diária do quarto nº"<<p[i].nquartos<<": R$";
        cin >> p[i].preco;
        cout << "\n Digite a situação do quarto nº"<<p[i].nquartos<<"(1 - Livre, 2 - Ocupado, 3 - Reservado): ";
        cin >> p[i].status;
            while(p[i].status!=1 && p[i].status!=2 && p[i].status!=3){
                cout<<"\n Valor inválido! Tente novaimente.";
                cout << "\n Digite a situação do quarto nº"<<p[i].nquartos<<"(1 - Livre, 2 - Ocupado, 3 - Reservado): ";
                cin >> p[i].status;
            }
    q=q+1;
    }
return q;
}


void inserhosp(cliente c [MAX],quartos p [MAX],int totalquartos){
    int i, f, escolha, fazer=1;
        system("cls");
        tela();
        cout << "                                 Entrada de Hospede";
        for(i=0;i<MAX;i++){
                if(c[i].livre==0){
                    cout << "\n\n Digite o nome do hospede: ";
                    cin >> c[i].nome;
                    cout << "\n\n Digite o CPF do hospede: ";
                    cin >> c[i].cpf;
                    cout << "\n\n Digite a data de entrada:\n Dia: ";
                    cin >> c[i].dia1;
                    cout << "\n Mês: ";
                    cin >> c[i].mes1;
                    cout << "\n Ano: ";
                    cin >> c[i].ano1;
                    f=i;
                    c[i].livre=1;
                    break;
                }
        }
        system("cls");
        tela();
        cout << "                                 Entrada de Hospede";
        cout << "\n\n Confira todos os quartos livres:\n\n";
        for(i=0;i<totalquartos;i++){
            if(p[i].status==1){
                    cout << "   Nº" << p[i].nquartos << " com "<<p[i].acomod << " acomodações.\n";
            }
        fazer=0;
        }
        if(fazer==0){
            cout << "\n_______________________________________________________________________________";
            cout << "\n Numero do quarto desejado:";
            cin  >> escolha;
            for(i=0;i<totalquartos;i++){
                if(escolha==p[i].nquartos){
                    c[i].refquartos=i;
                    p[i].refcliente=f;
                    system("cls");
                    tela();
                    cout << "                                 Entrada de Hospede";
                    cout << "\n\n Entrada efetuada com sucesso. Confira:";
                    cout << "\n\n Nome: "<<c[f].nome;
                    cout << "\n CPF: "<<c[f].cpf;
                    cout << "\n\n Hospedado no quarto Nº"<<p[i].nquartos;
                    cout << "\n\n STATUS do quarto alterado para OCUPADO.";
                    p[i].status=2;
                    c[f].total=p[i].preco;
                    cout << "\n\n\n         Pressione ENTER para voltar ao menu.";
                    getch();
                    break;
                }
            }
        }
        if(fazer==1){
                cout << "\n\n Não existem quartos livres.";
                cout << "\n\n\n\n\n    Pressione ENTER para voltar ao menu.";
                c[f].livre=0;
                getch();
        }
}


void listarinf_all(cliente c [MAX], quartos p[MAX], int totalquartos){
    system("cls");
    tela();
    int i, f;
    cout << "Confira as informações sobre os quartos\n";
    for(i=0;i<totalquartos;i++){
        cout << "================================";
        cout << "\nQuarto Nº"<<p[i].nquartos<<" :" ;
        cout << "\n================================";
        cout << "\nQuantidade de acomodações: "<<p[i].acomod;
        cout << "\nPreço da diária: "<<p[i].preco;
        cout << "\nSTATUS: ";
                if(p[i].status==1)
                    cout << "Livre";
                if(p[i].status==2)
                    cout << "Ocupado";
                if(p[i].status==3)
                    cout << "Reservado";
        if(p[i].status==2){
            f=p[i].refcliente;
            cout<<"\nOcupado por: "<<c[f].nome<<" desde: "<<c[f].dia1<<"/"<<c[f].mes1<<"/"<<c[f].ano1;
        }
    }
    getch();
}


void listarinf_ocup(cliente c [MAX], quartos p[MAX], int totalquartos){
    int i, f;

    cout << "Confira os dados dos quartos ocupados:";
     for(i=0;i<totalquartos;i++){
        if(p[i].status==2){
            cout << "\nQuarto Nº"<<p[i].nquartos<<" :" ;
            cout << "\n================================";
            cout << "\nQuantidade de acomodações: "<<p[i].acomod;
            cout << "\nPreço da diária: "<<p[i].preco;
            cout << "\nSTATUS: ";
                if(p[i].status==1)
                    cout << "Livre";
                if(p[i].status==2)
                    cout << "Ocupado";
                if(p[i].status==3)
                    cout << "Reservado";
                f=p[i].refcliente;
                cout<<"\nOcupado por: "<<c[f].nome<<" desde: "<<c[f].dia1<<"/"<<c[f].mes1<<"/"<<c[f].ano1;
        }

     }

getch();

}


void alterastatus(quartos p[MAX], int totalquartos){
    system("cls");
    tela();
    int escolha, i;
    cout << "Confira todos os quartos existentes na pousada: ";
    for(i=0;i<totalquartos;i++){
        cout<<"\n Nº"<<p[i].nquartos<<" - ";
                if(p[i].status==1)
                    cout << "Livre";
                if(p[i].status==2)
                    cout << "Ocupado";
                if(p[i].status==3)
                    cout << "Reservado";
    }
    cout << "\n\nEscolha o número do quarto para alterar o STATUS: ";
    cin >> escolha;
    for(i=0;i<totalquartos;i++){
        if(escolha==p[i].nquartos){
            cout<<"Esse quarto está: ";
                if(p[i].status==1)
                    cout << "Livre";
                if(p[i].status==2)
                    cout << "Ocupado";
                if(p[i].status==3)
                    cout << "Reservado";
        cout << "\n\n\n Digite a nova situação do quarto nº"<<p[i].nquartos<<"(1 - Livre, 2 - Ocupado, 3 - Reservado)";
        cin >> p[i].status;
                                        while(p[i].status!=1 && p[i].status!=2 && p[i].status!=3){
                                                    cout<<"\n Valor inválido! Tente novaimente.";
                                                    cout << "\n\n Digite a situação do quarto nº"<<p[i].nquartos<<"(1 - Livre, 2 - Ocupado, 3 - Reservado)";
                                                    cin >> p[i].status;
                                        }
        p[i].status==escolha;
        cout << "\n\n Alterado com Sucesso!";
        getch();
        }

    }

}

void despesasextras(cliente c [MAX],quartos p [MAX],int totalquartos){
    int i,f, escolha;
    system("cls");
    tela();
    cout << "                                 Despesas Extras do Hospede";
    cout << "\n\n Digite o nº do quarto: ";
    cin >> escolha;
    for(i=0;i<totalquartos;i++){
        if(escolha==p[i].nquartos){
            f=p[i].refcliente;
            cout << "Digite o valor extra a ser inserido na despesa do Hospede: ";
            cin >> c[f].despextra;
        }
    }
    cout << "Valor inserido com Sucesso!\n";
    cout << "\n\n\n\n          Pressione ENTER para voltar ao menu.";
    getch();
}

void final(cliente c [MAX],quartos p [MAX],int totalquartos){

    int i, f, j, escolha, diarias;
    float troco, result;
    int naobissexto=0, anocomum=0, anoini=0, anofim=0, bissexto=0;
    int mes30=0, mes31=0, fevcomum=0, mescomum=0, mesini=0, mesfim=0;
    int dias=0, diasbi=0, diasnaobi=0;
    int somaanos=0,somameses=0,somadias=0,resultado=0;
    system("cls");
    tela();
    cout << "                                   Saída de Hospede";
    cout << "\n\n Digite o número do quarto: ";
    cin >> escolha;
    for(i=0;i<totalquartos;i++){
        if(escolha==p[i].nquartos){
            f=p[i].refcliente;
            p[i].status=1;
            cout << "\n Confira os valores e o hospede: ";
            cout << "\n\n Nome: "<<c[f].nome;
            cout << "\n CPF:  "<<c[f].cpf;
            cout << "\n Data de entrada: "<<c[f].dia1<<"/"<<c[f].mes1<<"/"<<c[f].ano1;
            cout << "\n\n Informe a data de saída: ";
            cout << "\n  Dia: ";
            cin >> c[f].dia2;
            cout << "\n Mês: ";
            cin >> c[f].mes2;
            cout << "\n Ano: ";
            cin >> c[f].ano2;
            cout << "\n\n Status do quarto alterado para LIVRE. Pressione ENTER para continuar";
            getch();

//Calculando Anos
                if (c[f].ano1!=c[f].ano2) {
                    anocomum=365;
                }
            anoini=c[f].ano1+1;
            anofim=c[f].ano2-1;
                for (i=anoini; i<=anofim; i=i+1) {
                    if ((i%4==0)&&(i%100!=0)&&(i%400!=0))  {
                        bissexto=bissexto+1;
                    }
                        else {
                            naobissexto=naobissexto+1;
                        }
                }
//Calculando Meses

                if (c[f].mes1!=c[f].mes2) {
                    mescomum=30;
                }
            mesini=c[f].mes1+1;
            mesfim=c[f].mes2-1;
                for (j=mesini; j<=mesfim ;j=j+1)  {
                    if (j==04||j==06||j==9||j==11)  {
                        mes30=dias+30;
                    }
                        else if (j==01||j==03||j==05||j==07||j==8||j==10||j==12) {
                            mes31=dias+31;
                        }
                            else if (j==02) {
                                fevcomum=dias+28;
                            }
                                else if ((j==02)&&((i%4==0)&&(i%100!=0)&&(i%400!=0))) {
                                    fevcomum=dias+29;
                                }
                }
//Calculos
            diasbi=bissexto*366;
            diasnaobi=naobissexto*365;
            somaanos=diasbi+diasnaobi;
            somameses=mes30+mes31+fevcomum+mescomum+anocomum;
            somadias=c[f].dia2-c[f].dia1;
            resultado=somaanos+somameses+somadias;
            break;
        }
    }
result=c[f].total*resultado+c[f].despextra;

system("cls");
tela();
cout << "                                   Saída de Hospede";
cout << "\n\n\n\n Total de dias na pousada: "<<resultado;
cout << "\n\n              Diaria: R$"<<c[f].total*resultado;
cout << "\n\n        Desp. Extras: R$"<<c[f].despextra;
cout << "\n\n\n\n                     Total: R$: "<<result;
cout << "\n                           Total pago: R$";
cin >> troco;
cout << "\n                           Troco: R$"<<troco-result;
getch();






//limpando dados
c[f].livre=0;
c[f].despextra=0;
c[f].total=0;

}
