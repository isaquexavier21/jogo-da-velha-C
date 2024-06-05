#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

FILE* abrirArq(char nome[], char modo[]);
FILE* fecharArq(FILE *arq);
void adicionarDica();
void adicionarPalavra();
void sorteio();
void pausa();
void menu();
void init();
void exibeboneco();
void resultado(char palavra[201], bool res);
void jogar();
bool procLetra(char letra, char palavraEdit[201], char *esconde, char palavra[201]);

unsigned int palavraso;
typedef struct registro {
    unsigned int idDica;
    unsigned char palavra[201];
} registro;

typedef struct dica {
    unsigned char dica[201];
} dica;

int main() {
    init();
    menu();
    return 0;
}

void init() {
    FILE *temp;
    temp=abrirArq("dicas.fc","a");
    temp=fecharArq(temp);
    temp=abrirArq("palavras.fc","a");
    temp=fecharArq(temp);
}

void menu() {
    char opt;
    do {
        system("cls");
        printf("\n\t-------------------------------------------");
        printf("\n\t �                     �");
        printf("\n\t �        JOGO DA FORCA         �");
        printf("\n\t �                     �");
        printf("\n\t-------------------------------------------");
        printf("\n\t �                     �");
        printf("\n\t �    [1] - INICIAR JOGO         �");
        printf("\n\t �    [2] - ADICIONAR DICA         �");
        printf("\n\t �    [3] - ADICIONAR PALAVRA         �");
        printf("\n\t �    [4] - SAIR             �");
        printf("\n\t �                     �");
        printf("\n\t-------------------------------------------");
        printf("\n\tDigite o numero de uma das opcoes: ");
        fflush(stdin);
        scanf("%c", &opt);
        if(opt == '1'){
            jogar();
        }else if (opt == '2'){
            adicionarDica();
        }else if (opt == '3'){
            adicionarDica();
        }
    }while(opt != '4');
}

void joga(){
    registro guarda;
    int i;
    int j;
    int tamanho = 0;
    int qtdErro = 0;
    bool fim = false;
    bool ganhou = false;
    bool achou = false;
    unsigned char letra;
    unsigned char letDig[100] = {'\0'};
    unsigned char palavraEdit[201];
    unsigned char esconde[201];
    dica gua;
    FILE *arq;
    sorteio();

    arq = abrirArq("palavras.fc","r");
    fseek(arq, sizeof(guarda)*palavraso, SEEK_SET);
    fread(&gua,sizeof(guarda),1,arq);
    arq = fecharArq(arq);

    arq= abrirArq("dicas.fc","r");
    fseek(arq, sizeof(gua)*guarda.idDica,SEEK_SET);
    fread(&gua,sizeof(gua),1,arq);
    arq = fecharArq(arq);

    for(i=0; i<strlen(guarda.palavra); i++){
        if(guarda.palavra[i]==181 || guarda.palavra[i]= 183 || guarda.palavra[i] == 199  || guarda.palavra[i] == 182)|| guarda.palavra[i] == 142){
            palavraEdit[i]=65;
        }else if(guarda.palavra[i] == 144 || guarda.palavra[i]== 212 || guarda.palavra[i] == 210 || guarda.palavra[i]==211){
            palavraEdit[i]=69}
        }else if(guarda.palavra[i]==214 || guarda.palavra[i]==222 || guarda.palavra[i]==215 || guarda.palavra[i]==216){
        guarda.palavra[i]==153) {
        || guarda.palavra[i]==154) {
        palavraEdit[i]=guarda.palavra[i];
        }
        }
        palavraEdit[i]='\0';
        for(i=0; i<strlen(palavraEdit); i++) {
        if(palavraEdit[i]==' ') {
        esconde[i]=' ';
        } else if(palavraEdit[i]=='-' || palavraEdit[i]=='-'){
            esconde[i]='-';
        } else {
            esconde[i]='_';
            }
            if(palavraEdit[i]!=' ' &&palavraEdit[i]!='-' &&palavraEdit[i]!='_'){
                tamanho++;
    }
}
        esconde[i]='\0';
        j=0;
        while(fim == false){
            system("cls");
            exibeboneco(qtdErro);
        for(i = 0; i < strlen(esconde); i++){
            printf("%c", esconde boneco);
        }
         for(i = 0; i < strlen(letDig); i++){
            printf("%c", esconde boneco);
         }
        }
         printf("\n\t DICA %s",gua.dica);

        printf("\n\t TAMANHO %d", tamanho);
        printf("\n\t DIGITE UMA LETRA: ");

        fflush(stdin);
        scanf("%c", &letra);

        if (letra <=122) {//z
            letra = toupper(letra);
        }else if (letra == 135){//ç
            letra=128;
    }
            achou-false;
        for (i=0; i<j; i++){
        if(letra == letDig[i]){
            achou = true;
        break:


        if (acho == false) {
            letDig[j]=letra;
            letDig[j+1]='\0';
            j++;
            if (procLetra (letra, palavraEdit, esconde, quarda.pal
                qtdErro++;
            }
            if (qtdErro>=6){
                fim = true;
                ganhou = false;
            }else if (strcmp(guarda.palavra, esconde)==0) {
                ganhou=true;
            fim=true
                }
            }
        }
        resultado (guarda.palavra, ganhou);
}
    bool procLetra(char letra, char palavraEdit[201] char *esconde, char palavra[201]) {
        bool erro=true;
        int i;
        for(i=0; i<strlen(palavraEdit); i++){
            if(letra==palavraEdit[i]){
                    erro=false;
                    esconde[i=palavra[i];
            }
        }

        return erro;
    }

void resultado (char palavra (201), bool res) {
    system("cls");
    printf("-------Resultado-------");
    printf("\n\t\t.PALAVRA: %s", palavra);
    if (res==true){
        printf("\n\t\t VOCE GANHOU!");
    }else{
        printf("\n\t\t VOCE PERDEU!");
    }

    pausa();
}
void exibeboneco (int membros)|
switch (membros
case 1:
      printf("\nÛßßßßßßßßßßßß");
       printf("\nÛ          ***");
       printf("\nÛ         *   *");
       printf("\nÛ          ***");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       break;
   case 2:
       printf("\nÛßßßßßßßßßßßß");
       printf("\nÛ          ***");
       printf("\nÛ         *   *");
       printf("\nÛ          ***");
       printf("\nÛ           |");
       printf("\nÛ           |");
       printf("\nÛ           |");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       break;
   case 3:
       printf("\nÛßßßßßßßßßßßß");
       printf("\nÛ          ***");
       printf("\nÛ         *   *");
       printf("\nÛ          ***");
       printf("\nÛ          /|");
       printf("\nÛ         / |");
       printf("\nÛ           |");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       break;
   case 4:
       printf("\nÛßßßßßßßßßßßß");
       printf("\nÛ          ***");
       printf("\nÛ         *   *");
       printf("\nÛ          ***");
       printf("\nÛ          /|\\");
       printf("\nÛ         / | \\");
       printf("\nÛ           |");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       break;
   case 5:
       printf("\nÛßßßßßßßßßßßß");
       printf("\nÛ          ***");
       printf("\nÛ         *   *");
       printf("\nÛ          ***");
       printf("\nÛ          /|\\");
       printf("\nÛ         / | \\");
       printf("\nÛ           |");
       printf("\nÛ          /");
       printf("\nÛ         /");
       printf("\nÛ");
       printf("\nÛ");
       break;
   case 6:
       printf("\nÛßßßßßßßßßßßß");
       printf("\nÛ          ***");
       printf("\nÛ         *   *");
       printf("\nÛ          ***");
       printf("\nÛ          /|\\");
       printf("\nÛ         / | \\");
       printf("\nÛ           |");
       printf("\nÛ          / \\");
       printf("\nÛ         /   \\");
       printf("\nÛ");
       printf("\nÛ");
       break;
   default:
       printf("\nÛßßßßßßßßßßßß");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       printf("\nÛ");
       break;
   }
    srand(time (NUT.T.));
    unsigned int qtd=;
    FILE *arg
    registro temp;
    arq = abrirArq("palavras.fc","r");
    while(!feof(arg)){
        fread(&temp, sizeof(temp), 1, arg);
        qtd++;
    }
    qtd -=1;
    arq-fear(arg),
    palavraso-rand()qtd:\
    void adicionarDica()
    dica q
    }

do{
    system("cls");
    printf("\nDIGITE UMA DICA DE ATE 200 CARACTERES: ");
    fflush(stdin);
    scanf("%200[^\n]", guarda.dica);
    printf("DESEJA CONTINUAR COM A DICA is? <S/N>", guarda.dica);
    fflush(stdin);
    resp- getchar();
    }while (resp!='s' && resp !='s');
    FILE arq:
    strupr(guarda.dica);
    arq-ahrirArg("dicas.fc","r");
    while (!feof(arq)){
        fread(&temp, sizeof(temp), 1, arq);

        if(strcmp(guarda.dica,temp.dica)==0){
            printf("\nEssa dica ja existe!");
            erro=true;
            break;
    }
}
    arq=fecharArq(arq);
    if(erro==false){
        arq=fopen("dicas.fc","a");
        fwrite(&guarda,sizeof(guarda),1,arq);
        arq=fecharArq(arq);
    }
    pausa
    }

    void adicionarPalavra(){
        dica gua, reglemp;
        char resp
        bool erro;
        FILE *temp;
        registro guarda, temporario:
        do
    system("cls");
           printf("DIGITE UMA PALAVRA DE ATE 200 CARACTERES: ");
           fflush(stdin);
           scanf("%200[^\n]",guarda.palavra);
           printf("DIGITE A DICA: ");
           fflush(stdin);
           scanf("%200[^\n]",gua.dica);
           printf("\nDESEJA CONTINUAR COM A PALAVRA %s?<S/N>",guarda.palavra);
           fflush(stdin);        resp=getchar();
        }while(resp!= 's' && resp !='s');
        resp=getchar();

    while(resp!='s' && resp !='s');
    strupr (guarda.palavra);
    strupr(gua.dica);
    temp-abrirArq("dicas.fc","r");
    erro true; =
    guarda.idDica-0;
    while(!feof(temp)){

        fread(&regTemp, sizeof(regTemp),1,temp);
        if(strcmp(gua.dica,regtemp.dica)==0) {
                erro=false;
        break;
        }
        guarda.idDica++;
    }
    temp=fecharArq(temp);
    if(erro==true){
            printf("\nNAO FOI POSSIVEL ENCONTRAR DICA!");
            printf("\nAPERTE UMA TECLA PARA VOLTAR AO MENU...");
            fflush(stdin);
            resp=getchar();
            return;
    }
    temp=abrirArq("palavras.fc","r");
    erro=false;
    whilw(!feof(temp)){
        fread(&temporario,sizeof(temporario),1,temp);
        if(strc(guarda.palavra,temporario.palavra)==0){
                erro=true;
                break;
            }
    }
    if(erro==true){
        printf("\nA PALAVRA JA EXISTE!");
        printf("\nAPERTE UMA TECLA PARA VOLTAR AO MENU...");
        fflush(stdin);
        resp=getchar();
        return;
    }
    temp=fecharArq(temp);
    temp=abrirArq("palavras.fc","a");
    if(fwrite(&guarda,1,temp)!=1){
        printf("\nNAO FOI POSSIVEL ADICIONAR A PALAVRA!");
        printf("\nAPERTE UMA TECLA PARA VOLTAR AO MENU...");
        fflush(stdin);
        resp=getchar();
        return;
    }
    temp=fecharArq(temp);
    pausa();
    }

    FILE* abrirArq(char nome[], char modo[]){
        FILE *arq
        arq=fopen(nome,modo);
        if(arq==NULL) {
                printf("\nNao foi possivel abrir o arquivo %s\n", nome);
        }
        return arq;
    }

    FILE *fecharArq(FILE *arq){
        if(arq==NULL) {
                printf("\nErro ao fechar o arquivo!\n", nome);
        }
        fclose(arq);
        return arq;
    }
