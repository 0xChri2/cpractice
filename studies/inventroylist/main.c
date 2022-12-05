
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// structure to store all information about items
struct item_s {
    // each item has a unique id to clearly identify it
    unsigned id;
    // where the item is stored: rack and position within rack
    unsigned rack;
    unsigned position;
    // price per piece
    double price;
    // number of items in stock
    unsigned quantity;
};
typedef struct item_s item_t;

// maximum capacity of the stock
#define MAX_NR_ITEMS 10000
// all items in stock
item_t stock[MAX_NR_ITEMS];
// current number of items in stock
unsigned stock_size = 0;


/**
 * Read items from file "filename" and write them to array items
 * the number of items actually read is returned */

void read_items_from_file(char *filename) {
    printf("Lese aktuelle Inventarliste...\n");

    // storage to preliminarily store the information of an item
    unsigned id; double price;
    unsigned rack; unsigned position; unsigned quantity;
    // number of tokens read from current input line
    size_t len = 0;

    // open the input file for reading
    FILE * fp = fopen(filename, "r");
    if (fp == NULL) {
        // if file could not be opened (wrong path, not readable, ...)
        // output a short message and immediately exit
        perror("Inventarliste kann nicht gelesen werden");
    }

    // the following loop reads a new item in every iteration
    // until the end of the file (or an invalid entry appears)
    len = fscanf(fp, "%i %lf %i %i %i", &id, &price, &rack, &position, &quantity);

    // as long as there is space in the array and a correct line is read
    while ((stock_size < MAX_NR_ITEMS) && (len == 5)) {
        // printf("Lese Element: %i\n", id);
        stock[stock_size].id = id;
        stock[stock_size].price = price;
        stock[stock_size].rack = rack;
        stock[stock_size].position = position;
        stock[stock_size].quantity = quantity;
        stock_size++;
        // reading next item
        len = fscanf(fp, "%i %lf %i %i %i", &id, &price, &rack, &position, &quantity);
    }

    // finally close the input file
    fclose(fp);
}


/**
 * Print all items in current stock
 */
void print_stock() {
    printf("  ID | price | rack/pos | #items\n");
    printf("-----+-------+----------+-------\n");
    for(int i = 0;i < stock_size;i++)
    {
        printf("%04i | %5.2lf |%5i/%-4i| %6i \n", stock[i].id, stock[i].price, stock[i].rack, stock[i].position, stock[i].quantity);
    }
}


/**
 * Checks whether some item is in stock
 */
item_t* find_item_stock(unsigned item_id ) {
    // TODO
    for(int i = 0;i < stock_size;i++)
    {
        if(stock[i].id == item_id)
        {
            return &stock[i];
        }
    }
    return NULL;
}


/**
 * Remove some items from the stock
 */
void remove_from_stock() {
    unsigned id;
    unsigned nr;
    printf("Bitte geben Sie die ID des Artikels ein: ");
    scanf("%u", &id);
    printf("Bitte geben Sie die Anzahl ein: ");
    scanf("%u", &nr);

    item_t *item = find_item_stock(id);

    // TODO
    // Meldung wenn nicht vorhanden:
    // "Der Artikel XXXX ist nicht auf Lager."
    // Meldung wenn nicht ausreichender Anzahl:
    // "Von Artikel XXXX sind nur noch XX Stueck auf Lager."
}


/**
 * Add some items to the stock
 */
void add_to_stock() {
    unsigned id;
    unsigned nr;
    printf("Bitte geben Sie die ID des Artikels ein: ");
    scanf("%u", &id);
    printf("Bitte geben Sie die Anzahl ein: ");
    scanf("%u", &nr);
    // find similar items in stock
    item_t *item = find_item_stock(id);
    if(item == id)
    {
        item->quantity+= nr;
    }
    else
    {
        printf("Bitte geben Sie den Preis ein: ");
        scanf("%lf", &stock[stock_size].price);
        printf("Bitte geben Sie Regal und Fach ein: ");
        scanf("%i/%i",&stock[stock_size].rack,&stock[stock_size].position);
        //scanf("%i",&stock[stock_size].rack);
        //scanf("%i",&stock[stock_size].position);
        stock[stock_size].id = id;
        stock[stock_size].quantity = nr;
        stock_size++;

    }

    // TODO
    //
}


/**
 * Save all items to the given file.
 */

void save_items_to_file(char *filename) {
    printf("Speichere Inventarliste...\n");
    // TODO
}


/* ----------- */

int main() {
    read_items_from_file("inventar.txt");
    do {
        printf("--- Inventarliste --- \n");
        print_stock();
        printf("--- Was wollen Sie tun? ---\n");
        printf("(1) Artikel entnehmen\n");
        printf("(2) Artikel hinzufuegen\n");
        printf("(0) Programm beenden\n");

        int choice;
        scanf("%d", &choice);

        // menu items
        switch(choice) {
            case 1:
                remove_from_stock();
                break;
            case 2:
                add_to_stock();
                break;
            case 0:
                save_items_to_file("inventar.txt");
                return 0;
            default:
                printf("Ungueltige Eingabe.\n");
        }
    } while(1);
}

