#include "sudoku.h"
#include "grid.h"
#define N 9

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

Grid_T sudoku_generate(int nelts, int unique){
    Grid_T NewGrid;
    Choice_T c;
    int i,j,counter=0,value;
    srand(getpid());
    
    while(counter < nelts){ 
        i=rand() % N;
        j=rand() % N;
        value=rand() % N;

        NewGrid.cell[i][j].choices[0] = value;
    }

    for(i=0; i<N; i++){ 
        for(j=0; j<N; j++){
            if(NewGrid.cell[i][j].choices[0]!=0){
                continue;
            }else{
                NewGrid.cell[i][j].choices[0]=0;
            }
        }
    }
    
    c.i=0;
    c.j=0;
    c.n=NewGrid.cell[c.i][c.j].choices[0];

    NewGrid=sudoku_solve(NewGrid,c);

    return NewGrid; 
}

Grid_T sudoku_read(void){
    Grid_T NewGrid;
    Choice_T t;
    int i,j,value;

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            scanf("%d",&value);
            t.i=i;
            t.j=j;
            t.n=value;
            NewGrid=grid_update(NewGrid,t);
        }
    }
    
    return NewGrid; 
}

void sudoku_print(FILE *s, Grid_T g){
    int i,j;

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fprintf(s,"[%d]",g.cell[i][j].choices[0]);
        }
        fprintf(s,"\n");
    }
}

Grid_T sudoku_solve(Grid_T g, Choice_T c){
    int i, j, num;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (g.cell[i][j].choices[0] == 0) {
                for (num = 1; num <= 9; num++) {
                    c.i = i;
                    c.j = j;
                    c.n = num;
                    if (!check_row(g, c) && !check_col(g, c) && !check_sub(g, c)) {
                        g.cell[i][j].choices[0] = num;
                        g = sudoku_solve(g, c);
                        if (sudoku_is_correct(g))
                            return g;
                        g.cell[i][j].choices[0] = 0;
                    }
                }
                return g;
            }
        }
    }
    return g;
}

int sudoku_is_correct(Grid_T g){
    int i,j,correct_cell_counter=0;
    Choice_T c;

    for(i=0;i<9;i++){
        c.i=i;
        for(j=0;j<9;j++){
            c.j=j;
            c.n=g.cell[i][j].choices[0];
            if(!check_row(g,c) && 
              !check_col(g,c) &&
               !check_sub(g,c)){
                 correct_cell_counter++;
            }
        }
    }

    if(correct_cell_counter==81){
        return 0;
    }else 
        return 1;
}

void sudoku_print_errors(Grid_T g){}

/*f.e we have a 0 somewhere.Check for the possible numbers.
1st check if it exists for the row than the column than the sub 3x3 */
int check_row(Grid_T g,Choice_T c){
    int j;
    
    for(j=0;j<9;j++){
        if(g.cell[c.i][j].choices[0]==c.n){
            return 1;
        }
    }
    return 0;
}

int check_col(Grid_T g,Choice_T c){
    int i;

    for(i=0;i<9;i++){
        if(g.cell[i][c.j].choices[0]==c.n){
            return 1;
        }
    }

    return 0;
}

int check_sub(Grid_T g,Choice_T c){
    int dest_1,dest_2,i,j;

    if(c.i>=0 && c.i < 3){
        c.i=0;
        dest_1=2;
    }else if(c.i >= 3 && c.i < 6){
        c.i=3;
        dest_1=5;
    }else{
        c.i=6;
        dest_1=8;
    }

    if(c.j >= 0 && c.j < 3){
        c.j=0;
        dest_2=2;
    }else if(c.j >= 3 && c.j < 6){
        c.j=3;
        dest_2=5;
    }else{
        c.j=6;
        dest_2=8;
    }

    for(i=c.i;i<dest_1;i++){
        for(j=c.j;j<dest_2;j++){
            if(g.cell[i][j].choices[0]==c.n){
                return 1;
            }
        }
    }

    return 0;
}
