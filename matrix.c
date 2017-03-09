#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

/* struct copy
typedef struct Matrix {
    int maxrow;
    int maxcol;
    double** array;
} Matrix;   */

Matrix* create_matrix_from_file(FILE* file)
{
    int row, col;
    if (fscanf(file, "%d %d", &row, &col) != 2 || row <= 0 || col <= 0)
    {
        fprintf (stderr, "creatematrix_from_file:\n\tCan't correctly get rows & columns\n");
        return NULL;
    }

    Matrix* matrix = create_matrix(row, col);
    if (matrix == NULL)
        return NULL;
    return matrix;
}




Matrix* create_matrix(int row, int col)
{
    Matrix* matrix = malloc (sizeof (Matrix));
    if (matrix == NULL )
    {
            fprintf (stderr, "create_matrix:\n\tCan't allocate %d bytes of memory\n",
                                            (int) sizeof (Matrix));
            return NULL;
    }
    matrix -> maxrow = row;
    matrix -> maxcol = col;
    matrix -> array = malloc (row * sizeof (double*));
    if (( matrix -> array ) == NULL)
    {
        fprintf (stderr, "create_matrix:\n\tCan't allocate %d bytes of memory\n",
                                            (int) (row * sizeof (double*)));
        free (matrix);
        return NULL;
    }
    for (int i = row -1 ; i >= 0 ; i--)
    {
        (matrix -> array)[i] = calloc (col, sizeof (double));
        if ((matrix -> array)[i]  == NULL)
        {
            fprintf (stderr, "create_matrix:\n\tCan't allocate %d bytes of memory\n",
                                            (int) (col * sizeof (double*)));
            for (int j=row - 1; j>i; j--)
                free (matrix -> array [j]);
            free (matrix -> array);
            free (matrix);
            return NULL;
        }
    }
    return matrix;

}
void free_matrix(Matrix* matrix)
{
    for (int i = matrix -> maxrow -1 ; i >= 0 ; i--)
        free ((matrix -> array)[i]);
    free (matrix -> array);
    free (matrix);
}



double get_elem(Matrix* matrix, int row, int col)
{
    //if (matrix == NULL)
    //{
    //  fprintf (stderr, "There was an error in call get_elem (matrix)\n\tElement [%d][%d] was read as 0\n", row, col);
    //  return 0;
    //}
    if (row >= 0 && row < matrix -> maxrow && col >= 0 && col < matrix -> maxcol )
        return (matrix -> array) [row][col];
    else
    {
        fprintf (stderr, "There was an error in call get_elem (row %d, col %d)\n\tThat element was read as 0\n", row, col);
        return 0;
    }
}
void set_elem(Matrix* matrix, int row, int col, double val)
{
    //if (row >= 0 && row < matrix -> maxrow && col >= 0 && col < matrix -> maxcol )
        (matrix -> array)[row][col] = val;
}

int get_rows(Matrix* matrix)
{
    //if (matrix != NULL)
        return (matrix -> maxrow);
    //else
    //{
    //fprintf (stderr, "There was an error in call get_rows (matrix)\n\tIt've returned -1\n");
        //return -1;
    //}
}

int get_cols(Matrix* matrix)
{
    //if (matrix != NULL)
        return (matrix -> maxcol);
    //else
    //{
    //fprintf (stderr, "There was an error in call get_cols (matrix)\n\tIt've returned -1\n");
        //return -1;
    //}
}
