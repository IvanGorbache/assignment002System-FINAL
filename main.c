#include<stdio.h>
#include "my_mat.h"


void debugPrinter(int[SIZE][SIZE]);

int main(int argc, char **argv)
{
    if(argc>=1)
    {   
            int mat[SIZE][SIZE];
	        FILE *f;
	        f = fopen(argv[1], "r"); 
	        int i=0, j=0, matrixInput[INPUT_SIZE], loop = TRUE;
	        char option;
	        while (fscanf(f, "%c ", &option)!=EOF && loop == TRUE){
		        switch (option) {
                    case 'A':
				        for (int i = 0; i < INPUT_SIZE; i++) {
					        fscanf(f, "%d ", &matrixInput[i]);
                            //printf("%d ",matrixInput[i]);
                    	}
                        inputMatrix(mat,matrixInput);
                        break;

                    case 'B':
				        fscanf(f, "%d ", &i);
				        fscanf(f, "%d ", &j);
                        pathExists(mat,i,j)?printf("True\n"):printf("False\n");
                        break;

                    case 'C':
				        fscanf(f, "%d ", &i);
				        fscanf(f, "%d ", &j);
                        printf("%d\n",shortestPath(mat,i,j));
                        break;

                    case 'D':
				        loop = FALSE;
                        break;

                    default:
                        continue;
                }
	        }
	        fclose(f);
    }
    return 0;
}

