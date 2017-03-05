#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "matrix.h"

double sqr (double val)
{
    return val * val;
};

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf (stderr, "Not enough or too much arguments in programm call\n");
        return -1;
    }
    FILE* file = fopen (argv[1], "r");
    if (file == NULL)
    {
        fprintf (stderr, "can't open file\n");
        return -2;
    }
    Matrix* matrix = create_matrix_from_file(file);
    if (matrix == NULL)
    {
        return -3;
        }
    /*filling matrix*/
    int nonzero;
    if (fscanf(file, "%d", &nonzero) != 1 || nonzero <0)
    {
        fprintf (stderr, "creatematrix_from_file:\nCan't get nonzero count from file\n");
        return -4;
    }
    int row = get_rows(matrix), col = get_cols(matrix);
    int rown, coln;
    int _non0 = nonzero; /* for error output */
    double elval;
    while ( nonzero -- )
    {
        if (fscanf (file, "%d %d %lf", &rown, &coln, &elval) == 3 &&
                                         rown >= 0 && rown < row &&
                                                 coln >= 0 && coln < col)
            set_elem (matrix, rown, coln, elval);
        else
            {
                fprintf (stderr, "creatematrix_from_file:\n\tCan't get %d element from file\n", _non0-nonzero);
                return -5;
            }
    }
    if ( fclose (file) == EOF )
        fprintf (stderr, "error at closing file\n");
    /*calculating euclidean norm of matrix (with some calculating error
      due to C realisation)*/
    double sqrsum=0;
    for (int i = get_rows(matrix)-1; i>=0; i--)
    {
        double sqrrowsum=0;
        for (int j = get_cols(matrix)-1; j>=0; j--)
            sqrrowsum += sqr (get_elem (matrix, i, j));
        sqrsum+=sqrrowsum;
    }
    printf ("euclidean norm of matrix is %lf\n", sqrt(sqrsum));
    free_matrix (matrix);
	return 0;
}
