# include <stdio.h>
# include "bruch.h"


bruch_t summe ( bruch_t * values , int n ) {
    bruch_t r = values [0];
    for (int i = 1; i < n; i ++)
        r = add (r , values [ i ]);
    return r;
}
bruch_t subsum ( bruch_t * values , int n ) {
    bruch_t r = values [0];
    for (int i = 1; i < n; i ++)
        r = sub(r , values [ i ]);
    return r;
}

void btos ( bruch_t q , char *s , int n) {
    snprintf (s , n , " (% d /% d )" , q .z , q .n );
}

static int gcd ( int p , int q) { // von au ß en nicht sichtbar !!!
    int r;
    do { // Algorithmus
        r = p % q; // von Euklid
        p = q ;
        q = r ;
    } while ( r != 0);
    return p;
}

static void reduce ( bruch_t * q) { // warum ein Zeiger ??
    int t = gcd (q ->z , q ->n );
    q ->z /= t ;
    q ->n /= t ;
}

bruch_t add ( bruch_t a , bruch_t b) {
    int z = a.z * b.n + b.z * a.n;
    int n = a.n * b.n ;
    bruch_t r = {z , n };
    reduce (& r ); // call by reference !!!
    return r;
}

bruch_t sub ( bruch_t a , bruch_t b) {
    int z = a.z * b.n - b.z * a.n;
    int n = a.n * b.n ;
    bruch_t r = {z , n };
    reduce (& r ); // call by reference !!!
    return r;
}

void output ( bruch_t q ) {
    printf (" (% d /% d )\ n " , q.z , q. n );
}
