
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

/* ------------------------------------------------------------ */

#ifdef WINDOWS

#include <windows.h>
#include <conio.h>

char get_keypress(){
    char c = getch();
    return c;
}

#else

char get_keypress(){

    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    return buf;
}

#endif

/* ------------------------------------------------------------ */

#define MAX_LEVELS 100
#define MAX_BOARD_WIDTH 25
#define MAX_BOARD_HEIGHT 25

// a square is either empty, a wall, a box or the player
typedef enum { EMPTY, WALL, BOX, PLAYER } square_t;

typedef struct {
    unsigned x;
    unsigned y;
} position_t;

/*
 * read a single level from a given file,
 * information is stored in board and target arrays,
 */
void read_board( FILE* fp,
                 square_t board[MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT],
                 unsigned target[MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT] ) {

    unsigned x = 0;
    unsigned y = 0;
    unsigned end_of_level = 0;

    while( !feof(fp) && !end_of_level ) {

        switch(fgetc(fp)) {
            case '\n':
                // fill the rest of row with empty squares
                for( int i=x; i<MAX_BOARD_WIDTH; i++) {
                    board[i][y] = EMPTY;
                    target[i][y] = 0;
                }
                // move to the next line of the board
                x = 0; y++;
                break;
            case '#':
                board[x][y] = WALL; target[x][y] = 0; x++;
                break;
            case '$':
                board[x][y] = BOX; target[x][y] = 0; x++;
                break;
            case ' ':
                board[x][y] = EMPTY; target[x][y] = 0; x++;
                break;
            case '@':
                board[x][y] = PLAYER; target[x][y] = 0; x++;
                break;
            case '.':
                board[x][y] = EMPTY; target[x][y] = 1; x++;
                break;
            case ';':
                // skip all remaining characters of the line
                while( fgetc(fp) != '\n' );
                end_of_level = 1;
                break;
        }
    }

}


/* ------------------------------------------------------------ */

/*
 * read all levels from the given file,
 * information is stored in boards and targets arrays,
 * total number of levels is stored in nr_levels
 */

void read_boards( char* filename,
                  square_t boards[MAX_LEVELS][MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT],
                  unsigned targets[MAX_LEVELS][MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT],
                  unsigned *nr_levels ) {

    FILE *fp = fopen(filename, "r");
    if( fp == NULL ) {
        perror("Fatal Error: Could not open input file %s\n");
        exit(1);
    }

    for( *nr_levels = 0; *nr_levels < MAX_LEVELS && !feof(fp); (*nr_levels)++ )
        read_board(fp, boards[*nr_levels], targets[*nr_levels]);

    fclose(fp);
}


/* ------------------------------------------------------------ */

unsigned move_left( square_t board[MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT],
                    position_t *player_pos ){
    if( (player_pos->x >= 1) &&
        (board[player_pos->x-1][player_pos->y] == EMPTY) ) {

        board[player_pos->x][player_pos->y] = EMPTY;
        board[player_pos->x-1][player_pos->y] = PLAYER;
        player_pos->x--;
        // result 1 = make move
        return 1;
    }
    if((player_pos->x >= 2) && (board[player_pos->x-2][player_pos->y] == EMPTY) && (board[player_pos->x-1][player_pos->y] == BOX)){
        board[player_pos->x][player_pos->y] = EMPTY;
        board[player_pos->x-1][player_pos->y] = PLAYER;
        board[player_pos->x-2][player_pos->y] = BOX;
        player_pos->x--;
        return 1;
    }
    // result 0 = no move is possible
    return 0;
}

unsigned move_right( square_t board[MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT],
                     position_t *player_pos ){
    if( (player_pos->x <= MAX_BOARD_WIDTH-2) &&
        (board[player_pos->x+1][player_pos->y] == EMPTY) ) {

        board[player_pos->x][player_pos->y] = EMPTY;
        board[player_pos->x+1][player_pos->y] = PLAYER;
        player_pos->x++;
        // result 1 = make move
        return 1;
    }
    if((player_pos->x <= MAX_BOARD_WIDTH-2) && (board[player_pos->x+2][player_pos->y] == EMPTY) && (board[player_pos->x+1][player_pos->y] == BOX)){
        board[player_pos->x][player_pos->y] = EMPTY;
        board[player_pos->x+1][player_pos->y] = PLAYER;
        board[player_pos->x+2][player_pos->y] = BOX;
        player_pos->x++;
        return 1;
    }
    // result 0 = no move is possible
    return 0;
}


unsigned move_up( square_t board[MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT],
               position_t *player_pos ){
    if( (player_pos->y >= 1) &&
        (board[player_pos->x][player_pos->y-1] == EMPTY) ) {

        board[player_pos->x][player_pos->y] = EMPTY;
        board[player_pos->x][player_pos->y-1] = PLAYER;
        player_pos->y--;
        // result 1 = make move
        return 1;
    }
    if (( (player_pos->y >= 2) &&
           (board[player_pos->x][player_pos->y-2] == EMPTY) && (board[player_pos->x][player_pos->y-1] == BOX))){
        board[player_pos->x][player_pos->y] = EMPTY;
        board[player_pos->x][player_pos->y-2] = BOX;
        board[player_pos->x][player_pos->y-1] = PLAYER;
        player_pos->y--;
        return 1;
    }
    // result 0 = no move is possible
    return 0;
}

unsigned move_down( square_t board[MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT],
                  position_t *player_pos ){
    if( (player_pos->y <= MAX_BOARD_HEIGHT-2) &&
        (board[player_pos->x][player_pos->y+1] == EMPTY) ) {

        board[player_pos->x][player_pos->y] = EMPTY;
        board[player_pos->x][player_pos->y+1] = PLAYER;
        player_pos->y++;
        // result 1 = make move
        return 1;
    }
    if((player_pos->y <= MAX_BOARD_HEIGHT-3) && (board[player_pos->x][player_pos->y+1] == BOX) && (board[player_pos->x][player_pos->y+2] == EMPTY)){
        board[player_pos->x][player_pos->y] = EMPTY;
        board[player_pos->x][player_pos->y+1] = PLAYER;
        board[player_pos->x][player_pos->y+2] = BOX;
        player_pos->y++;
        return 1;
    }
    // result 0 = no move is possible
    return 0;
}

unsigned move(square_t board[MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT],
              position_t *player_pos ){
    int move_directionx = 0;
    int  move_directiony= 0;
    //move down
    if( (player_pos->y <= MAX_BOARD_HEIGHT-2) &&
        (board[player_pos->x][player_pos->y+1] == EMPTY) ) {
        move_directiony = 1;
        // result 1 = make move

    }
    else if((player_pos->y <= MAX_BOARD_HEIGHT-3) && (board[player_pos->x][player_pos->y+1] == BOX) && (board[player_pos->x][player_pos->y+2] == EMPTY)){
        move_directiony = 1;
    }
    // result 0 = no move is possible

    //move up
    else if( (player_pos->y >= 1) &&
             (board[player_pos->x][player_pos->y-1] == EMPTY) ) {
        move_directiony = -1;
    }
    else if (( (player_pos->y >= 2) &&
          (board[player_pos->x][player_pos->y-2] == EMPTY) && (board[player_pos->x][player_pos->y-1] == BOX))){
        move_directiony = -1;
    }

    // move right
    else if( (player_pos->x <= MAX_BOARD_WIDTH-2) &&
             (board[player_pos->x+1][player_pos->y] == EMPTY) ) {
        move_directionx = 1;
    }
    else if((player_pos->x <= MAX_BOARD_WIDTH-2) && (board[player_pos->x+2][player_pos->y] == EMPTY) && (board[player_pos->x+1][player_pos->y] == BOX)){
        move_directionx = 1;
    }

    //move left
    else if( (player_pos->x >= 1) &&
             (board[player_pos->x-1][player_pos->y] == EMPTY) ) {
        move_directiony= -1;
    }
    else if((player_pos->x >= 2) && (board[player_pos->x-2][player_pos->y] == EMPTY) && (board[player_pos->x-1][player_pos->y] == BOX)){
        move_directiony= -1;
    }
    if(move_directiony != 0){
        board[player_pos->x][player_pos->y] = EMPTY;
        board[player_pos->x-1][player_pos->y] = PLAYER;
        board[player_pos->x-2][player_pos->y] = BOX;
        player_pos->x+ move_directiony;
        return 1;
    }
    else if(move_directionx != 0)
    {
        board[player_pos->x][player_pos->y] = EMPTY;
        board[player_pos->x + move_directionx][player_pos->y] = PLAYER;
        board[player_pos->x+ (move_directionx+move_directionx)][player_pos->y] = BOX;
        player_pos->x+ move_directionx;
        return 1;
    }
    return 0;
}

/*
 * draws the board
 */

void draw_board( square_t board[MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT],
                 unsigned target[MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT],
                 unsigned current_level,
                 unsigned nr_levels,
                 unsigned nr_moves ) {
    // first clear the screen
#ifdef WINDOWS
    system("cls");
#else
    system("clear");
#endif

    // top line: some general information
    printf("Level %i of %i / Moves: %i\n", current_level+1, nr_levels, nr_moves);

    // draw every square of the boardƒs
    for( int j=0; j<MAX_BOARD_HEIGHT; j++ ) {
        for( int i=0; i<MAX_BOARD_WIDTH; i++ ) {
            switch(board[i][j]) {
                case EMPTY:
                    if(target[i][j]) printf(".."); else printf("  ");
                    break;
                case WALL:
                    printf("##");
                    break;
                case BOX:
                    if(target[i][j]) printf("()"); else printf("[]");
                    break;
                case PLAYER:
                    printf("><");
            }
        }
        printf("\n");
    }
}


/*
 * count the number of boxes in target squares,
 * if all boxes are in target squares, return 1 - otherwise 0
 */
unsigned all_boxes_on_target( square_t board[MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT],
                      unsigned target[MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT] ) {
    /*
 * count the number of boxes in target squares,
 * if all boxes are in target squares, return 1 - otherwise 0
 */
    unsigned nr_boxes = 0;
    unsigned nr_boxes_on_target = 0;
    for( int j=0; j<MAX_BOARD_HEIGHT; j++ ) {
        for( int i=0; i<MAX_BOARD_WIDTH; i++ ) {
            if(board[i][j] == BOX) {
                nr_boxes++;
                if(target[i][j]) nr_boxes_on_target++;
            }
        }
    }
    return (nr_boxes == nr_boxes_on_target);

}


int main(int argc, const char * argv[]) {

    // stores the boards of all leveles
    square_t boards[MAX_LEVELS][MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT];
    // stores the target information of all levels
    unsigned targets[MAX_LEVELS][MAX_BOARD_WIDTH][MAX_BOARD_HEIGHT];
    // total number of levels (in input file)
    unsigned nr_levels;

    // current level number
    unsigned current_level = MAX_LEVELS;
    // current position of player
    position_t player_pos;
    // current number of moves (in this level)
    unsigned nr_moves;
    // current number of boxes (in this level)
    unsigned nr_boxes;

    // read the boards of all levels from the given file
    read_boards("Simple.txt", boards, targets, &nr_levels );

    // read the start level
    do {
        printf("Select start level (1-%d)...", nr_levels);
        scanf("%u", &current_level);
    } while (current_level > nr_levels );

    // start the game with given level, then proceed to next level
    for( current_level-=1; current_level < nr_levels; current_level++ ) {
        // extract player position and number of boxes from the current board
        nr_boxes = 0;
        for(unsigned i=0; i<MAX_BOARD_WIDTH; i++)
            for(unsigned j=0; j<MAX_BOARD_HEIGHT; j++) {
                // if player position is found, store it
                if( boards[current_level][i][j] == PLAYER ) {
                    player_pos.x = i;
                    player_pos.y = j;
                }
                // count the number of boxes (on target)
                if( boards[current_level][i][j] == BOX ) {
                    nr_boxes++;
                }
            }
        // initialize the number of moves for the current level
        nr_moves = 0;

        // for every move of the player, do the following
        do {
            // check if boxes are in target position,
            // if this is the case, current level is finished
            if( all_boxes_on_target( boards[current_level], targets[current_level] ) )
                break;
            // draw the board
            draw_board( boards[current_level], targets[current_level], current_level, nr_levels, nr_moves );

            // wait for keypress, then execute appropriate function
            switch (get_keypress() ) {
                case 'a':
                    nr_moves += move_left( boards[current_level], &player_pos );
                    break;
                case 'd':
                    nr_moves += move_right( boards[current_level], &player_pos );
                    break;
                case 'w':
                    nr_moves += move_up( boards[current_level], &player_pos );
                    break;
                case 's':
                    nr_moves += move_down( boards[current_level], &player_pos );
                    break;
                case 'q':
                    exit(0);
            }
        } while (1);

        // loop exited by break: level completed
        draw_board( boards[current_level], targets[current_level], current_level, nr_levels, nr_moves );
        printf("Level %d completed! Press any key to continue...", current_level);
        get_keypress();
    }
    printf("All levels completed. Congratulation!");
}

