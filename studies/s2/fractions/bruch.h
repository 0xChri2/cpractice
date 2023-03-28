#ifndef _BRUCH_H
#define _BRUCH_H

typedef struct {
    int z , n;
} bruch_t ;

bruch_t summe ( bruch_t * values , int n ); // neu
bruch_t subsum ( bruch_t * values , int n );
void btos (bruch_t q, char *s, int n);
bruch_t add ( bruch_t a , bruch_t b );
bruch_t sub ( bruch_t a , bruch_t b);
void output ( bruch_t q );



#endif
