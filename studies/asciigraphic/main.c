#include <stdio.h>
#include <stdlib.h>

/* screen size - adapt to console size */
#define NUM_COLUMNS 80
#define NUM_ROWS 25

/* screen buffer */
char screen[NUM_COLUMNS][NUM_ROWS];

/* initialize buffer by setting all pixels to spaces */
void initialize_buffer()
{
    for(int i=0; i<NUM_ROWS; i++)
        for(int j=0; j<NUM_COLUMNS; j++)
            screen[j][i] = ' ';
}


/* update screen by copying buffer to console window */
void update_screen()
{
    for(int i=0; i<NUM_ROWS; i++) {
        for(int j=0; j<NUM_COLUMNS; j++)
            putchar(screen[j][i]);
        putchar('\n');
    }
    fflush(stdout);
}

/* checks whether a given point (x,y) is within the screen */
unsigned in_screen(int x, int y) {
    // TODO
    if(x >= 0 && x < NUM_COLUMNS && y >= 0 && y < NUM_ROWS)
    {

        return 1;
    }
    else
    {

    }
    return 0;
}

/* draw a single point at given position (x,y) and with given character */
void draw_pixel(int x, int y, char c) {
    // TODO
    if(in_screen(x,y)) {
        screen[x][y] = c;
    }
}

/* clear a single pixel at position (x,y) */
void clear_pixel(int x, int y) {
    // TODO
    if(in_screen(x,y))
    {
        screen[x][y] = ' ';
    }
}

/* draw a horizontal line (x1,y)-(x2,y) with dashes (-) */
void draw_horizontal_line(int x1, int x2, int y) {
    // TODO
    if(x1 < x2){
        for(int i = x1; i <=x2;i++)
        {
            screen[i][y] = '-';
        }
    }
    else{
        for(int i = x2; i <=x1;i++)
       {
            screen[i][y] = '-';
       }
    }
}

/* draw a vertical line (x,y1)-(x,y2) with vertical bars (|) */
void draw_vertical_line(int x, int y1, int y2) {
    // TODO
    for(int i = y1; i <=y2;i++)
    {
        screen[x][i] = '|';
    }
}

/* draw a horizontal arrow (x1,y)-(x2,y) */
void draw_horizontal_arrow(int x1, int x2, int y) {
    draw_horizontal_line(x1, x2, y);
    if (x1<x2)
        draw_pixel(x2, y, '>');
    else
        draw_pixel(x2, y, '<');
}

/* draw a vertical arrow (x,y1)-(x,y2) */
void draw_vertical_arrow(int x, int y1, int y2) {
    draw_vertical_line(x, y1, y2);
    if (y1<y2)
        draw_pixel(x, y2, 'v');
    else
        draw_pixel(x, y2, '^');
}

/* draw a rectangle (x1,y1)-(x2,y1)-(x2,y2)-(x1,y2) with plus, dashes and vertical bars */
void draw_rectangle(int x1, int y1, int x2, int y2) {
    // TODO
    draw_horizontal_line(x1, x2, y1);
    draw_horizontal_line(x1, x2, y2);
    draw_vertical_line(x1, y1, y2);
    draw_vertical_line(x2, y1, y2);
    draw_pixel(x1,y1, '+');
    draw_pixel(x1,y2, '+');
    draw_pixel(x2,y1, '+');
    draw_pixel(x2,y2, '+');
}

void draw_filled_rectangle(int x1, int y1, int x2, int y2, char c) {
    // TODO
    for(int i = x1 + 1; i < x2; i++)
    {
        for(int j = y1 + 1; j < y2;j++)
        {
            screen[i][j] = c;
        }
    }
    draw_rectangle(x1,y1,x2,y2);
}

/* draw a general line (x1,y1)-(x2,y2) with character c */
void draw_line(int x1, int y1, int x2, int y2, char c) {
    // TODO
    int dx = abs(x2-x1), sx = x1<x2 ? 1 : -1;
    int dy = abs(y2-y1), sy = y1<y2 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2, e2;

    for(;;){
        draw_pixel(x1,y1, c);
        if (x1==x2 && y1==y2) break;
        e2 = err;
        if (e2 >-dx) { err -= dy; x1 += sx; }
        if (e2 < dy) { err += dx; y1 += sy; }
    }
}

/* flood fill an area starting at given position with character c */
void flood_fill(int x, int y, char c) {
    // TODO
    if(in_screen(x, y)) {
        if(screen[x][y] == ' ') {
            draw_pixel(x, y, c);
            flood_fill(x+1, y, c);
            flood_fill(x-1, y, c);
            flood_fill(x, y+1, c);
            flood_fill(x, y-1, c);
        }
    }

}


/* main program: entry point */

int main(int argc, const char * argv[]) {

    initialize_buffer();

    draw_rectangle(25, 2, 68, 8);
    draw_line(0,NUM_ROWS-1,NUM_COLUMNS-1,0,'*');
    flood_fill(2,2,'.');
    draw_pixel(30, 10, '1');
    draw_pixel(20, 15, '2');
    draw_pixel(75, 20, '3');
    draw_line(8,8, 45, 15, '+');
    draw_horizontal_arrow(0, NUM_COLUMNS-1, 0);
    draw_horizontal_arrow(NUM_COLUMNS-1, NUM_COLUMNS/2, NUM_ROWS-2);
    draw_vertical_arrow(0, 1, NUM_ROWS-1);
    draw_filled_rectangle(3,3,8,5,'#');

    update_screen();
    return 0;
}

