//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Questão 10 <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
//Autor: Ian dos Santos Silva
//Professor: Josildo
//Data: 12/02/2023
/*
Desenvolver um programa para determinar a próxima jogada em um jogo da velha. Assumir que o tabuleiro é representado por uma matriz de 3 x 3, onde cada posição representa uma das casas do tabuleiro. A matriz pode conter os seguintes valores -1, 0, 1 representando respectivamente uma casa contendo uma peça X=(-1), uma casa vazia do tabuleiro (0), e uma casa contendo uma peça do O=(1). O programa deve apresentar um menu contendo as opções de localizações disponíveis no tabuleiro, permitir que um jogador por vez faça sua escolha (X ou O), e ao final exibir o vencedor ou se houve empate.
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#define ordem 3

//Subprogramas

void peenchementoInicial(int matriz[][ordem], int elementos){
  int j,i;

  for(i=0;i<elementos;i++){
      for(j=0;j<elementos;j++){
        matriz[i][j] = 0;
    }
  }

}

int verificaLinhas(int matriz[][ordem], int elementos){
  int j,i, linhas=0;

  for(i=0;i<elementos;i++){
      for(j=0;j<elementos;j++){
        if(j == 0){
          linhas = matriz[i][j];
        }
        else if(linhas != matriz[i][j]){
          linhas = 0;
          break;
        }
     }
    if(linhas != 0){
      return linhas;
    }
  }
  return linhas;
}

int verificaColunas(int matriz[][ordem], int elementos){
  int j,i, colunas=0;

  for(i=0;i<elementos;i++){
      for(j=0;j<elementos;j++){
        if(j == 0){
          colunas = matriz[j][i];
        }
        else if(colunas != matriz[j][i]){
          colunas = 0;
          break;
        }
     }
    if(colunas != 0){
      return colunas;
    }
  }
  return colunas;
}

int verificaDiagP(int matriz[][ordem], int elementos){
  int j,i, dP=0;

  for(i=0;i<elementos;i++){
      for(j=0;j<elementos;j++){
        if (i == j){
          if(j == 0){
            dP = matriz[i][j];
          }
          else if(dP != matriz[i][j]){
            dP = 0;
            break;
          }
        }
      }
  }
  return dP;
}

int verificaDiagS(int matriz[][ordem], int elementos){
  int j,i, dS=0;

  for(i=0;i<elementos;i++){
      for(j=0;j<elementos;j++){
        if (i == elementos-j-1){
          
          if(j == elementos-1 && i == 0){
            dS = matriz[i][j];
          }
            
          else if(dS != matriz[i][j]){
            dS = 0;
            break;
          }
        }
      }
  }
  return dS;
}

int winOrLose(int matriz[][ordem], int elementos){ 
  
  if(verificaDiagS(matriz, elementos) != 0 ){
    return verificaDiagS(matriz, elementos);
  }
  else if(verificaDiagP(matriz, elementos) != 0 ){
    return verificaDiagP(matriz, elementos);
  }
  else if(verificaColunas(matriz, elementos) != 0 ){
    return verificaColunas(matriz, elementos);
  }
  else if(verificaLinhas(matriz, elementos) != 0 ){
    return verificaLinhas(matriz, elementos);
  }
  return 0;
}

int game(int matriz[][ordem], int elementos, char p1[50], char p2[50]){
  char p[50];
  char a;
  int marcas[elementos*elementos], rodada=0;
  int i,j,k=0, play;
  strcpy(p, p1);

  do {

    if (rodada != 0){
      if(strcmp(p,p1) == 0){
        strcpy(p, p2);
      }
      else if(strcmp(p,p2) == 0){
        strcpy(p, p1);
      }
    }
    
    for(i=0;i<elementos;i++){
      printf("\n");
      
      for(j=0,k=0;j<elementos;j++){
        
        if(matriz[i][j] == 1){
          a = 'X';
        }
        else if(matriz[i][j] == -1){
          a = 'O';
        }
        else{
          a = ' ';
        }
         printf("| %c | ", a);
         k++;
        }
      }
  
      do{
      printf("\n%s, faça seu movimento: ", p);
      scanf("%i",&play);
      for(i=0;i<elementos*elementos;i++){
        if (play == marcas[i]){
          printf("Escolha outra posição, esta já foi jogada\n");
          break;
        }
        else if (play < 1 || play > 9){
          printf("Posição inválida\n");
          break;
        }
      }
    }while(play == marcas[i] || (play < 1 || play > 9));
    
    marcas[rodada] = play;
    rodada++;
      
    switch(play){
      case 1: if( strcmp(p1,p) == 0){matriz[0][0] = 1;} else {matriz[0][0] = -1;}break;
      case 2: if( strcmp(p1,p) == 0){matriz[0][1] = 1;} else {matriz[0][1] = -1;}break;
      case 3: if( strcmp(p1,p) == 0){matriz[0][2] = 1;} else {matriz[0][2] = -1;}break;
      case 4: if( strcmp(p1,p) == 0){matriz[1][0] = 1;} else {matriz[1][0] = -1;}break;
      case 5: if( strcmp(p1,p) == 0){matriz[1][1] = 1;} else {matriz[1][1] = -1;}break;
      case 6: if( strcmp(p1,p) == 0){matriz[1][2] = 1;} else {matriz[1][2] = -1;}break;
      case 7: if( strcmp(p1,p) == 0){matriz[2][0] = 1;} else {matriz[2][0] = -1;}break;
      case 8: if( strcmp(p1,p) == 0){matriz[2][1] = 1;} else {matriz[2][1] = -1;}break;
      case 9: if( strcmp(p1,p) == 0){matriz[2][2] = 1;} else {matriz[2][2] = -1;}break;
    }
  }while(winOrLose(matriz, elementos) == 0 && rodada < 9);

  for(i=0;i<elementos;i++){
      printf("\n");
      
      for(j=0,k=0;j<elementos;j++){
        
        if(matriz[i][j] == 1){
          a = 'X';
        }
        else if(matriz[i][j] == -1){
          a = 'O';
        }
        else{
          a = ' ';
        }
         printf("| %c | ", a);
         k++;
        }
      }
  
  return winOrLose(matriz, elementos);
}

void exibirPlacar(int scoreFinal, char p1[50], char p2[50] ){
  char winner[50], looser[50];

  printf("\n\n\n");
  
  if (scoreFinal == 1){
    strcpy(winner, p1);
    strcpy(looser, p2);
  }
  if (scoreFinal == -1){
    strcpy(winner, p2);
    strcpy(looser, p1);
  }
  
  if(scoreFinal != 0){
    printf("PARABÉNS %s, VOCÊ VENCEU",winner);
  }
  else{
    printf("OS CAVALHEIROS EMPATARAM");
    }

  }

void present(char *x, char *y){
  printf("BEM VINDO AO JOGO DA VELHA\n| 1 | 2 | 3 |\n-------------\n| 4 | 5 | 6 |\n-------------\n| 7 | 8 | 9 |\n-------------\n\n");

  printf("JOGADOR 1, INSIRA SEU NOME:");
  scanf("%s", x);
  printf("JOGADOR 2, INSIRA SEU NOME:");
  scanf("%s", y);

  printf("\nJOGADOR 1: %s\nJOGADOR 2: %s", x,y);
  
  printf("\n\nBOA SORTE!\nPRESSIONE ENTER PARA INICIAR\n");
  getchar();
}

//Programa Principal
int main(void) {
  setlocale(LC_ALL, "portuguese");
  
  char p1[50], p2[50];
  int dimens = 3, tabuleiro[dimens][dimens], placar;

  //Apresentar o jogo
  present(p1,p2);
  //Preencher inicialmente a matriz
  peenchementoInicial(tabuleiro, dimens);
  //Ter uma partida
  placar = game(tabuleiro, dimens, p1, p2);
  exibirPlacar(placar, p1,p2);
  
}
