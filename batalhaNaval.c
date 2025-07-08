#include <stdio.h>
#include <stdlib.h>

#define LINHAS 10  //definindo tamanho do tabuleiro (nao precisa repetir ao longo do codigo)
#define COLUNAS 10 

int tabuleiro[LINHAS][COLUNAS];
int matrizCone[5][5];
int matrizCruz[3][3];
int matrizOcta[5][5];
int centro = 5 / 2;


void criaCone(){
    for (int linha = 0; linha < 5; linha++){
        for (int coluna = 0; coluna < 5; coluna++){ //começa em 0, entao o meio é a 3ª posição
            if (coluna >= 2 - linha && coluna <= 2 + linha && linha <= 2) {  
                //Coluna ><=2 pq o centro é na 3ª posição (0,1,2): parte do centro - 0(linha), qdo desce aumenta o "nº" de linhas pra esquerda (-linha) e pra direita (+ linha).
            matrizCone[linha][coluna] = 1; //puxa a matriz feita
            }
        }
    }
}

void criaCruz(){
    for (int linha = 0; linha < 4; linha++){
        for (int coluna = 0; coluna < 4; coluna++){
            matrizCruz[1][coluna] = 1; //quando na linha 2, aparece 1 em todas as colunas
            matrizCruz[linha][1] = 1; //em todas as linhas, na coluna 2 aparece 1
        }
    }
}

void criaOcta(){
    for (int linha = 0; linha <= centro; linha++){
        for (int coluna = centro - linha; coluna <= centro + linha; coluna++){ 
            //'coluna = centro - linha': pq conforme desce a linha, vai 1 pra esquerda; 'coluna <= centro + linha' conforme a coluna vai andando pra esquerda vai aumentando 1 casa
            matrizOcta[linha][coluna] = 1; //valor a ser mostrado
        }
    }
    for (int linha = centro + 1; linha < 5; linha++) { //'linha = centro + 1' linha debaixo da central; 'linha < LINHAS': limite é o limite da matriz
        for (int coluna = linha - centro; coluna < 5 - (linha - centro); coluna++){ 
            //'coluna = linha - centro': começa na coluna que seria a linha central - 1 (já que é quadrada);
            //'COLUNAS - (linha - centro)': são 4 colunas - (4 linhas - 2 colunas) = posição 2 => total de colunas (menos) a diferença da possição do centro e da linha que está
            matrizOcta[linha][coluna] = 1;
        }
    }
}

void imprimeTabuleiro(){            //Imprimindo o tabuleiro
    printf("  A B C D E F G H I J\n");
    for (int linha = 0; linha < 10; linha++){
        printf("%d ", linha);
        for (int coluna = 0; coluna < 10; coluna++){
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

}
//Posicionando navio
void main(){

    int linha, coluna;              
    int posicaoNavio = 5;   //coluna que inicia o navio
    int navioPosicionado = 0;

    criaCone();
    criaCruz();
    criaOcta();

    for (linha = 0; linha < 10; linha++){
        for (coluna = 0; coluna < 10; coluna++){
            if (linha >= 1 && linha <= 3){ //NAVIO DIAGONAL ESQUERDA
                if (navioPosicionado == 0){  //quando a variavel for 0 (falso), não tem navio
                    tabuleiro[linha][posicaoNavio] = 3; //valor (identificação do navio) 
                    posicaoNavio--;  //decrescendo para andar 1 coluna à esquerda por linha
                    navioPosicionado = 1; //quando a variavel for 1 (veradeiro), tem navio e não faz mais o if
                }
            }
            
            if (posicaoNavio <= 2){  //nova posição de inicio do navio, pq são 3 posições decrementadaas de 5 (5-3=2)
                posicaoNavio = 6;
            }
            
            if (linha >= 5 && linha <= 7){ //NAVIO DIAGONAL DIREITA
                if (navioPosicionado == 0) {  //quando a variavel for 0 (falso), não tem navio
                    tabuleiro[linha][posicaoNavio] = 3; //valor (identificação do navio)
                    posicaoNavio++;  //incremento para andar 1 coluna à direita por linha
                    navioPosicionado = 1; //quando a variavel for 1 (veradeiro), tem navio e não faz mais o if   
                }
            
            }

            if (linha == 5 && coluna >= 2 && coluna <= 4){
                tabuleiro[linha][coluna] = 3;  //NAVIO HORIZONTAL
            } else if (linha >= 6 && linha <= 8 && coluna == 6){ //NAVIO VERTICAL
                tabuleiro[linha][coluna] = 3;
            }
//Colocando Cone
            if (linha == 7 && coluna == 2){
                tabuleiro[linha][coluna] = matrizCone[0][2];
            }
            else if (linha == 8 && coluna >= 1 && coluna <= 3){
                tabuleiro[linha][coluna] = matrizCone[0][2];
            }
            else if (linha == 9 && coluna >= 0 && coluna <= 4){
                tabuleiro[linha][coluna] = matrizCone[0][2];
            }

//Colocando Cruz
            if (linha == 0 && coluna == 1){
                tabuleiro[linha][coluna] = matrizCruz[0][1];
            }
            else if (linha == 1 && coluna >= 0 && coluna <= 2){
                tabuleiro[linha][coluna] = matrizCruz[0][1];
            }
            else if (linha == 2 && coluna == 1){
                tabuleiro[linha][coluna] = matrizCruz[0][1];
            }

//Colocando Octaedro
            if ((linha == 0 || linha == 4) && coluna == 7){
                tabuleiro[linha][coluna] = matrizOcta[0][2];
            }
            else if ((linha == 1 || linha == 3) && coluna >= 6 && coluna <= 8){
                tabuleiro[linha][coluna] = matrizOcta[0][2];
            }
            else if (linha == 2 && coluna >= 5 && coluna <= 9){
                tabuleiro[linha][coluna] = matrizOcta[0][2];
            }
        }
        navioPosicionado = 0; //quando a variavel for 0 (falso), não tem navio e inicia nova linha   
    }
    imprimeTabuleiro();              //Mostrando Tabuleiro + Navios + Habilidades
}