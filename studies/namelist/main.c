
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * a single entry of the name list contains
 * the name and how often it occurs
 */
typedef struct {
    char* name;
    int occurrence;
} entry_t ;

/** the capacity (maximum number of elements) of the name list */
unsigned list_capacity = 1000;

/** the length (actual number of elements) of the name list */
unsigned list_length = 0;

/** the name list (stored as an array) */
entry_t name_list [1000];


/**
 * Appends an entry to the list.
 * @param name of the new entry
 * @param occurrence of the new entry
 */
void append_entry( char* name, int occurrence ) {
    if(list_length == list_capacity) {
        return;
    }

    // append entry to the list
    // by setting the attributes and increasing the length
    // TODO (1)
    name_list[list_length].name = "???";
    name_list[list_length].occurrence = 0;
    list_length++;
}


/**
 * Reads all the entries from standard inputs
 */
void read_entries() {
    int occ; char name[100];
    // the following loop reads a new name in every iteration
    // until the end of the file (entry with pos 0)
    while (1) {
        scanf("%100s %i", name, &occ);
        if( occ == 0 ) break;
        append_entry( name, occ );
    }
}


/**
 * Compare function for sorting entries by name
 */
int compare_name( const void *p1, const void *p2) {
    const entry_t* e1 = (const entry_t*)p1;
    const entry_t* e2 = (const entry_t*)p2;
    return strcmp(e1->name, e2->name);
}

/**
 * Compare function for sorting entries by occurence
 */
int compare_occ( const void *p1, const void *p2) {
    // TODO (4)
    return 0;
}


/**
 * Prints the first entrys of the given list of names
 */
void print_list( int nr_entries ) {
    for(unsigned i=0; i<nr_entries && i<list_length; i++)
        printf("%6i %-15s %10i\n", i+1, name_list[i].name, name_list[i].occurrence);
}


/**
 * Returns the entry of a given name
 * @param n given name
 * @returns pointer to entry (or NULL if not found)
 */
entry_t* find_entry( char* n ) {
    // TODO (2)
    return NULL;
}


/**
 * Returns the occurence of a given name
 * @param n given name
 * @returns pos (or 0 if not found)
 */
void print_occ_of_name( char* n ) {
    entry_t* e = find_entry(n);
    if( e != NULL )
        printf("Der Name %s existiert insgesamt %d mal.\n", n, e->occurrence );
    else
        printf("Der Name %s steht nicht in der Liste.\n", n);
}


// ----------------------

int main() {
    // read list of names
    read_entries();

    // print first 100 entries of the resulting list
    print_list(10);

    // the user is asked for search strings
    print_occ_of_name("GARCIA");
    print_occ_of_name("Thomas");
    print_occ_of_name("Snyder");
    print_occ_of_name("XILOL");

    // sort the list of names
    qsort(name_list, list_length, sizeof(entry_t), compare_occ);

    print_list(10);
}
