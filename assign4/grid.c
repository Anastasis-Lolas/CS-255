#include "grid.h"

struct grid_s {
  struct { 
    int count;       /* count of valid (1) choices in the choices array */
    int choices[10]; /* choices[k]=1 if k is a valid choice for element i,j, else choices[k]=0. 
	                   choices[0] is the value 1..9 assigned to the cell, when resolved */
  } cell[9][9];      /* sudoku puzzle cells; 0<=i,j<9 */
  int unique;        /* if 1 after solving, puzzle has unique-choice solution */
};

struct choice_s {
  int i,j,n;		/* n is the value 1..9 of a choice for cell i,j. 0 means the cell is empty. */
};



Grid_T grid_init(Grid_T g,int v[9][9]){
    int i,j,k;
    Choice_T choice;
    

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            for(k=1;k<9;k++){
                g.cell[i][j].choices[k]=1;
            }

                choice.i=i;
                choice.j=j;
                choice.n=v[i][j]; 
                g=grid_update(g,choice);
           
        }
        printf("\n");
    }
    return g;
   
}

Grid_T grid_update(Grid_T g, Choice_T c){
    assert(c.i>=0 && c.i<9);
    assert(c.j>=0 && c.j<9);
    
    g.cell[c.i][c.j].choices[0] = c.n;
    g.cell[c.i][c.j].choices[c.n]=0;

    return g;
}

Choice_T grid_iterate(Grid_T g, Choice_T t){
    int k;

    assert(t.i>=0 && t.i<9);
    assert(t.j>=0 && t.j<9);

    for(k=t.n + 1; k<9;k++){
        if(g.cell[t.i][t.j].choices[k]==1){
            return t;
        }
    }

    t.i=0;
    t.j=0;
    t.n=0;

    return t;

}

int grid_unique(Grid_T g){
    return g.unique;
}

Choice_T grid_exist_unique(Grid_T g){
   Choice_T temp;
   temp.i=0;
   temp.j=0;
   temp.n=0;

   return temp;
}

Grid_T grid_clear_unique(Grid_T g){
    g.unique=0;
    return g;
}

Choice_T grid_read_value(Grid_T g, Choice_T c){
        return c;
}

void grid_cell_print(FILE *stream, Grid_T g, Choice_T c){
    fprintf(stream,"Cell-Value [%d]\n",g.cell[c.i][c.j].choices[0]);
}
