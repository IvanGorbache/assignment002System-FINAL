#include<stdio.h>
#include "my_mat.h"


void debugPrinter(int[SIZE][SIZE]);

int main(int argc, char **argv)
{
            int mat[SIZE][SIZE];
	        int i=0, j=0, loop = TRUE;
	        char option;
	        while (scanf("%c",&option) != 'D' && loop == TRUE){
		        switch (option) {
                    case 'A':
                        inputMatrix(mat);
                        break;

                    case 'B':
				        scanf("%d", &i);
				        scanf("%d", &j);
                        pathExists(mat,i,j)?printf("True\n"):printf("False\n");
                        break;

                    case 'C':
				        scanf("%d", &i);
				        scanf("%d", &j);
                        printf("%d\n",shortestPath(mat,i,j));
                        break;

                    case 'D':
				        loop = FALSE;
                        break;

                    default:
                        continue;
                }
	    }
        return 0;
}

