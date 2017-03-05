#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>

/*remove all inline comment symbols ("//") in matrix.c and this comment if
  you're going to use this lib not only for my alghorythm.
  The next comment is true only if you've did it.*/

/*all functions makes entrys in stderr in case of errors.
 Use it if you get incorrect results*/

typedef struct Matrix {
    int maxrow;
    int maxcol;
    double** array;
} Matrix;

Matrix* create_matrix_from_file(FILE* file);
/*calls create_matrix with file data*/
/*returns NULL in case of error with mem loc or data reading*/

Matrix* create_matrix(int row, int col);
/*allocs Matrix (struct) and its array array
 uses calloc according to task */
/*returns NULL in case of mem loc error*/

void free_matrix(Matrix* matrix);
/*frees Matrix (struct) */

double get_elem(Matrix* matrix, int row, int col);
/*returns array element, or zero in case of error*/

void set_elem(Matrix* matrix, int row, int col, double val);
/*sets array element, or do nothing in case of error*/

int get_rows(Matrix* matrix);
/*returns maxrow from Matrix (struct), or -1 in case of error */

int get_cols(Matrix* matrix);
/*returns maxcol from Matrix (struct), or -1 in case of error */

#endif //_MATRIX_H_
