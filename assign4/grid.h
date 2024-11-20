/********************************************************************
   grid.h
   Definition of grid ADT 
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#ifndef grid_h
#define grid_h


typedef struct grid_s Grid_T;

typedef struct choice_s Choice_T;

Grid_T grid_init(Grid_T g, int v[9][9]);		/* init g with values from array v */
Grid_T grid_update(Grid_T g, Choice_T c);		/* update value of c.i,c.j to c.n and eliminate c from choices in grid */
Choice_T grid_iterate(Grid_T g, Choice_T t);	/* iterate over all choices in all cells starting from (t.i,t.j,t.n+1). 
												   If no choice is left, return (0,0,0) */

int grid_unique(Grid_T g);						/* return unique flag for g */
Choice_T grid_exist_unique(Grid_T g);			/* return a cell with a unique choice, if one exists, otherwise return (0,0,0) */
Grid_T grid_clear_unique(Grid_T g);				/* clear unique flag */

Choice_T grid_read_value(Grid_T g, Choice_T c);	/* return value of i,j */
#ifdef DEBUG
void grid_cell_print(FILE *stream, Grid_T g, Choice_T c);
#endif
#endif