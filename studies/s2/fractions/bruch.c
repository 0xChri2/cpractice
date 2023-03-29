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

bruch_t multisum ( bruch_t * values , int n ){
    bruch_t r = values[0];
    for (int i =1;i<n;i++)
        r = multi(r,values[i]);
    return r;
}

bruch_t divisum ( bruch_t * values , int n ){
    bruch_t r = values[0];
    for (int i =1;i<n;i++)
        r = div(r,values[i]);
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

bruch_t multi (bruch_t a, bruch_t b){
    int z = a.z * b.z;
    int n = a.n * b.n;
    bruch_t r = {z,n};
    return r;
}
bruch_t div (bruch_t a, bruch_t b){
    if(b.n | a.n == 0)
    {
        return a;
    }
    int z = a.z * b.n;
    int n = a.n * b.z;
    bruch_t r = {z,n};
    return r;
}

bruch_t valueof (double value){
    double z = value;
    double n = 1.00;
    for(int i = 0;i<=50;i++){
         n *= 10;
         z *= 10;
        if(((int)z/n) == value)
        {
            bruch_t r ={z,n};
            return r;
        }
    }
}

void output ( bruch_t q ) {
    printf ("(%d /%d)\n " , q.z , q. n );
}
