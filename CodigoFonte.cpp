#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;


void parametroInvalido(){
    cout<<"Por favor, insira uma parâmetro válido!"<<endl;
}

void opcoes(){
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"-              Por favor digite o numero da opçao desejada:                 -"<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"- 1- Relatorio com nomes de candidatos e suas respectivas notas.            -"<<endl;
    cout<<"- 2- Apresentar media geral do candidatos.                                  -"<<endl;
    cout<<"- 3- Apresentar quantidade e percentual de classificados e desclassificados.-"<<endl;
    cout<<"- 4- Relatorio de candidatos classificados.                                 -"<<endl;
    cout<<"- 5- Melhor nota obtida e seu(s) respectivo(s) candidato(s)                 -"<<endl;  
    cout<<"- 6- Percentual de acerto de cada questao                                   -"<<endl;       
    cout<<"- 7- Limpar a tela                                                          -"<<endl;       
    cout<<"- 8- Sair                                                                   -"<<endl;       
    cout<<"-----------------------------------------------------------------------------"<<endl;
}

void opcao1(int N, string nome_candidato[], float nota[]){

    cout<<"\n--------------------------"<<endl;
    cout<<"- Candidato      NOTA      -"<<endl;
    for(int i=0; i<N; i++)
        {
            cout<<"- "<<nome_candidato[i]<<" \t\t "<<nota[i]<<"\t -"<<endl;
        }
    cout<<"--------------------------"<<endl;
}

void opcao2(int N, float nota[]){
    float somaMedia;
        
    for (int i=0; i<N; i++)
        somaMedia=somaMedia+nota[i];

    cout<<"---------------------------------------------"<<endl;
    cout<<"A media geral dos candidatos eh "<<somaMedia/N<<endl;
    cout<<"---------------------------------------------"<<endl;
}

void opcao3(int N, float nota[]){
    int classificados=0, desclassificados=0;
    for(int i=0; i<N; i++)
        {
            if(nota[i]>=5)
                classificados++;
            else
                desclassificados++;
        }
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"Classificados: "<<classificados<<"("<<classificados*100.0/N<<"%)"<<endl;
    cout<<"Desclassificados: "<<desclassificados<<"("<<desclassificados*100.0/N<<"%)"<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
}

void opcao4(int N, string nome_candidato[], float nota[]){

    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"-                       Candidatos Classificados                            -"<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    for (int i=0; i<N; i++)
    {
        if(nota[i]>=5)
        cout<<nome_candidato[i]<<endl;
    }
}

void opcao5(int N, float nota[], string nome_candidato[]){
    
    float melhorNota=0;
    for(int i=0; i<N; i++)
    {
        if(melhorNota<=nota[i])
            melhorNota=nota[i];
    }
    cout<<"- Melhor nota: "<<melhorNota<<".\n\n";
    cout<<"- Candidato(s) com a melhor nota: "<<endl;

    for(int i=0; i<N; i++)
    {
        if (nota[i]==melhorNota)
            cout<<nome_candidato[i]<<endl;
    }

}

void opcao6(int M, int acertos[]){
cout<<"-----------------------------------------------------------------------------"<<endl;
cout<<"-                       Percentual de acerto por questao                    -"<<endl;
cout<<"-----------------------------------------------------------------------------"<<endl;
for (int i=0; i<M; i++)
    {
       cout<<"- "<<i+1<<"\t"<<acertos[i]*100.0/M<<"%"<<endl;
    }
}

void limparTela(){
    system("cls");
}

main(){
    int N, M, cont_candidato, cont_questao, respCorreta=0, i, opcao;
    
    cout<<"Qual a quantidade de candidatos?"<<endl;
    cin>>N;
    

    cout<<"Quantas questoes serao aplicadas?"<<endl;
    cin>>M;

    //Declaração de variávies compostas dependentes M ou N
    char gabarito[M], respostas[N][M];
    string nome_candidato[N];
    float nota[N];
    int acertos[N]={0};
    
        for (cont_questao=0; cont_questao<M; cont_questao++)
        {
            cout<<"\nQual o gabarito da questao "<<cont_questao+1<<"? (A, B, C, D ou E)"<<endl;
            cin>>gabarito[cont_questao];
            gabarito[cont_questao]=toupper(gabarito[cont_questao]);

            if (gabarito[cont_questao]<'A' || gabarito[cont_questao]>'E')
            {
                cont_questao--;
                parametroInvalido();
            }
        };

    for(cont_candidato=0; cont_candidato<N; cont_candidato++)
    {
        cout<<"\nQual o nome do candidato?"<<endl;
        cin>>nome_candidato[cont_candidato];
        

        for(cont_questao=0; cont_questao<M; cont_questao++)
        {
            cout<<"\nQual a resposta da questao "<<cont_questao+1<<"? (A, B, C, D ou E)"<<endl;
            cin>>respostas[cont_candidato][cont_questao];
            respostas[cont_candidato][cont_questao]=toupper(respostas[cont_candidato][cont_questao]);

            if (respostas[cont_candidato][cont_questao]<'A' || respostas[cont_candidato][cont_questao]>'E')
                {
                    cont_questao--;
                    parametroInvalido();
                }
            else 
                if (respostas[cont_candidato][cont_questao]==gabarito[cont_questao])
                    {
                        respCorreta++;
                        acertos[cont_questao]++;
                    }
        }

        nota[cont_candidato]=respCorreta*10.0/M;
        respCorreta=0;

    }
    
    limparTela();

    do{
        opcoes();
        cin>>opcao;
        
        if (opcao==1)
        opcao1(N, nome_candidato, nota);

        else
            if (opcao==2)
            opcao2(N, nota);

            else
                if (opcao==3)
                opcao3(N, nota);

                else
                    if (opcao==4)
                    opcao4(N, nome_candidato, nota);

                    else
                        if (opcao==5)
                        opcao5(N, nota, nome_candidato);

                        else
                            if (opcao==6)
                            opcao6(M, acertos);
                                
                                else
                                    if (opcao==7)
                                    limparTela();
                    
    }while (opcao!= 8);
}