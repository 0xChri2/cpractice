#include <stdio.h>

void gameboard (int player[20][20],char board[20][20]){
    for(int i = 0;i < 20;i++){
        for (int j = 0; j < 20; j++) {
            printf("%c",board[j][i]);
        }
    }
}
int main() {
    typedef struct {
        int player[20][20];
        int board[20][20]
    }Player;
    Player player1;
    player1.player[20][20] = '1';
    printf("Welcome to Maze!!\n");
    for(int i = 0;i < 20;i++){
        for (int j = 0; j < 20; j++) {
            player1.board[j][i] = '0';
        }
    }
    gameboard(&player1.player,&player1.board);
    return 0;
}
