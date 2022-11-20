#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/** complex numbers have a real and an imaginary part */
typedef struct {
    double real;
    double imag;
} complex_t;

/** constant 0 */
const complex_t complex_0 = {0,0};
/** constant 1 */
const complex_t complex_1 = {1,0};
/** constant i (often called j in electrical engineering) */
const complex_t complex_j = {0,1};

//dont know if const is right right here
void complex_print(const complex_t *c ) {
    printf("%lf + %lf*j\n", c->real, c->imag );
}

/**
 * Computes the absolute value of a complex number (distance to origin in complex plane).
 * @param c complex number
 * @return absolute value of given complex number
 * @return absolute value of given complex number
 */
double complex_abs( complex_t *c ) {
    // TODO
    return 0.0;
}


/**
 * Adds two complex numbers
 * @param c0 pointer to the complex number storing the result
 * @param c1 pointer to first number
 * @param c2 pointer to second number
 */
void complex_add( complex_t *c0, complex_t *c1, complex_t *c2 ) {
    // TODO
    c0->real = c1->real + c2->real;
    c0->imag = c1->imag + c2->imag;
}


/**
 * Substracts a complex numbers from another number
 * @param c0 pointer to the complex number storing the result
 * @param c1 pointer to first number
 * @param c2 pointer to second number
 */
void complex_sub( complex_t *c0, complex_t *c1, complex_t *c2 ) {
    // TODO
    c0->real = c1->real - c2->real;
    c0->imag = c1->imag - c2->imag;
}


/**
 * Multiplies two complex numbers
 * @param c0 pointer to the complex number storing the result
 * @param c1 pointer to first number
 * @param c2 pointer to second number
 */
void complex_mul( complex_t *c0, complex_t *c1, complex_t *c2 ) {
    // TODO
    c0->real = c1->real * c2->real;
    c0->imag = c1->imag * c2->imag;
}


/**
 * Divides a complex numbers by another number
 * @param c0 pointer to the complex number storing the result
 * @param c1 pointer to first number
 * @param c2 pointer to second number
 */
void complex_div( complex_t *c0, complex_t *c1, complex_t *c2 ) {
    // TODO
    c0->real = c1->real / c2->real;
    c0->imag = c1->imag / c2->imag;
}


/**
 * Computes the reciprocal of a complex number.
 * @param c complex number
 * @return reciprocal of a complex number
 */
void complex_reciprocal( complex_t *c0, complex_t *c1 ) {
    // TODO
}


/**
 * Computes the conjugate complex number.
 * @param c complex number
 * @return conjugate complex number
 */
void complex_conjugate( complex_t *c0, complex_t *c1 ) {
    // TODO
}


/**
 * Turns a value between 0.0 and 1.0 to a character (for gray-scale purposes)
 * @param gray-scale value (0.0 = white, 1.0 = black)
 * @return char
 */
char grayscale( double x ) {
    const char map[] = " .:-=+*#%@";
    if( x > 0.0) {
        return 'O';
    } else
        return ' ';
}


void complex_number_test01() {
    complex_t a = {3,-4};
    complex_t b = {-2,5};
    complex_t c;
    double r = complex_abs(&a);
    printf("%lf\n", r);
    complex_add(&c, &a, &b);
    complex_print(&c);
    complex_sub(&c, &a, &b);
    complex_print(&c);
    complex_mul(&c, &a, &b);
    complex_print(&c);
    complex_div(&c, &a, &b);
    complex_print(&c);
    complex_conjugate(&c, &a);
    complex_print(&c);
    complex_reciprocal(&c, &a);
    complex_print(&c);
}


/**
 * Computes and illustrates the Mandelbrot set
 * with the help of complex numbers (on the stack).
 */
void mandelbrot_on_stack() {
     for (double imag = -1.5; imag <= 1.5; imag += 0.1) {
            for (double real = -2.0; real <= 1; real += 0.03) {
                complex_t z = complex_0;
                complex_t z2 = complex_0;
                complex_t c = {real, imag};
                double gray = 0.0;
                for (int i = 0; i < 16; i++) {
                    complex_mul(&z2, &z, &z);
                    complex_add(&z, &z2, &c);
                    if (complex_abs(&z) > 2.0) {
                        gray = i / 16.0;
                        break;
                    }
                }
                printf("%c", grayscale(gray));
            }
            printf("\n");
        }

}

/* main function */

int main () {

    // testing complex numbers
    complex_number_test01();

    // TODO: uncomment after implementing complex numbers
    // mandelbrot_on_stack();

    return 0;
}