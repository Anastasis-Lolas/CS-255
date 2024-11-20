#include "grid.h"
#include "sudoku.h"

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

void printGrid(struct grid_s grid);

int main(){
          Choice_T c;
    Grid_T new;

     int sudoku[9][9] = {
	{5, 3, 0, 0, 7, 0, 0, 0, 0},
	{6, 0, 0, 1, 9, 5, 0, 0, 0},
	{0, 9, 8, 0, 0, 0, 0, 6, 0},
	{8, 0, 0, 0, 6, 0, 0, 0, 3},
	{4, 0, 0, 8, 0, 3, 0, 0, 1},
	{7, 0, 0, 0, 2, 0, 0, 0, 6},
	{0, 6, 0, 0, 0, 0, 2, 8, 0},
	{0, 0, 0, 4, 1, 9, 0, 0, 5},
	{0, 0, 0, 0, 8, 0, 0, 7, 9}
   };
   
    new=grid_init(new,sudoku);

    printf("\n----BEFORE----\n");
    printGrid(new);
   
    new=sudoku_solve(new,c);
    
    printf("\n----AFTER----\n");
    printGrid(new);
    
   

    


    return 0;
}

void printGrid(Grid_T  grid) {
    int i,j;
    printf("Sudoku Puzzle:\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
           printf("%d ", grid.cell[i][j].choices[0]);

        }
        printf("\n");
    }
}
