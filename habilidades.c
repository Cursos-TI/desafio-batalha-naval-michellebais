#include <stdio.h>

#define LINHAS 5
#define COLUNAS 5

int matriz[LINHAS][COLUNAS];
int centro = COLUNAS / 2;

void imprimeHabilidade(){ //Imprimindo o tabuleiro
    for (int linha = 0; linha < 5; linha++){
        for (int coluna = 0; coluna < 5; coluna++){
            printf("%d ", matriz[linha][coluna]);
        }
        printf("\n");
    }
}

int main() { //deixei com tamanho 5 para poder sobrepor o tabuleiro no 10x10 com folga
  int linha, coluna;

/*Fazendo a Cruz
    for (linha = 0; linha < 5; linha++){
        for (coluna = 0; coluna < 5; coluna++){
            matriz[2][coluna] = 1; //quando na linha 2, aparece 1 em todas as colunas
            matriz[linha][2] = 1; //em todas as linhas, na coluna 2 aparece 1
        }
    }
    imprimeHabilidade();*/

/*Fazendo o Cone
    for (linha = 0; linha < 5; linha++){
        for (coluna = 0; coluna < 5; coluna++){ //começa em 0, entao o meio é a 3ª posição
            if (coluna >= 2 - linha && coluna <= 2 + linha && linha <= 2) {  
                //Coluna ><=2 pq o centro é na 3ª posição (0,1,2): parte do centro - 0(linha), qdo desce aumenta o "nº" de linhas pra esquerda (-linha) e pra direita (+ linha).
            matriz[linha][coluna] = 1; //puxa a matriz feita
            }
        }
    }
    imprimeHabilidade();*/

//Octoedro (30ª tentativa)

    for (linha = 0; linha <= centro; linha++){
        for (coluna = centro - linha; coluna <= centro + linha; coluna++){ //'coluna = centro - linha': pq conforme desce a linha, vai 1 pra esquerda; 'coluna <= centro + linha' conforme a coluna vai andando pra esquerda vai aumentando 1 casa
            matriz[linha][coluna] = 1; //valor a ser mostrado
        }
    }
    for (linha = centro + 1; linha < LINHAS; linha++) { //'linha = centro + 1' linha debaixo da central; 'linha < LINHAS': limite é o limite da matriz
        for (coluna = linha - centro; coluna < COLUNAS - (linha - centro); coluna++){ 
            //'coluna = linha - centro': começa na coluna que seria a linha central - 1 (já que é quadrada);
            //'COLUNAS - (linha - centro)': são 4 colunas - (4 linhas - 2 colunas) = posição 2 => total de colunas (menos) a diferença da possição do centro e da linha que está
            matriz[linha][coluna] = 1;
        }
    }

    imprimeHabilidade();

    return 0;
}