#include<stdio.h>
#include "my_mat.h"
void debugPrinter(int mat[SIZE][SIZE]);
void inputMatrix(int mat[SIZE][SIZE], int input[INPUT_SIZE])
{
    int k = 0;
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            mat[i][j] = input[k++];
        }
    }
    //debugPrinter(mat);
}
int pathExists(int mat[SIZE][SIZE], int i, int j)
{
    return shortestPath(mat,i,j)!=-1?TRUE:FALSE;
}
int shortestPath(int mat[SIZE][SIZE], int i, int j)
{
    int dist[SIZE][SIZE];
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            dist[i][j] = mat[i][j];
        }
    }
	for(int i=0;i<SIZE;i++)
    {
    	dist[i][i] = 0;
    }
	for(int k = 0;k < SIZE;k++)
	{
		for(int i = 0;i < SIZE;i++)
		{
		    for(int j = 0;j < SIZE;j++)
		    {
                if(dist[i][k]!=0  && dist[k][j]!=0)
                {
                    if((dist[i][j] > (dist[i][k] + dist[k][j])) || dist[i][j]==0)
				    {
					    dist[i][j] = dist[i][k] + dist[k][j];
				    }
                }
		    }
		}
	}
    return dist[i][j]!=0?dist[i][j]:-1;
}
void debugPrinter(int mat[SIZE][SIZE])
{
    printf("\n");
	for(int i = 0;i < SIZE;i++)
	{
		for(int j = 0;j < SIZE;j++)
		{
			printf(" %d ", mat[i][j]);
		}
		printf("\n");
	}
}


