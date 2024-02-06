#include <stdio.h>

#define MAX_WEIGHT 20
#define MAX_LEN 5

#define max(A, B) ((A)>(B) ? (A) : (B))


int knapSack(int [MAX_LEN], int[MAX_LEN]);

int main()
{
	char items[MAX_LEN] = {'A','B','C','D','E'};
	int values[MAX_LEN] = {35, 60, 100, 120, 130};
	int weights[MAX_LEN] = {2, 5, 6, 9, 9};
	printf("%d",knapSack(weights, values));
	return 0;
}

int knapSack(int weights[MAX_LEN], int values[MAX_LEN])
{
	char items[MAX_LEN] = {'A','B','C','D','E'};
	int selected_bool = {0,0,0,0,0};
	int profit = 0;
	int table[MAX_LEN+1][MAX_WEIGHT+1];
	
	for(int i = 0;i<=MAX_LEN;i++)
	{
		for(int j = 0;j<=MAX_WEIGHT;j++)
		{
			table[i][j] = 0;
		}
	}
	
	for(int i = 1;i<=MAX_LEN;i++)
	{
		for(int j = 1;j<=MAX_WEIGHT;j++)
		{
			if(weights[i-1]<=j)
			{
				table[i][j] = max(table[i-1][j],table[i-1][j-weights[i-1]]+values[i-1]);
			}
			else
			{
				table[i][j] = table[i][j-1];
			}
		}
	}
	
	profit = table[MAX_LEN][MAX_WEIGHT];
	
	int j = MAX_WEIGHT;
	for(int i = MAX_LEN; i >= 0; i--)
	{
		if(table[i][j] == table[i-1][j-weights[i-1]]+values[i-1])
		{
			printf("%c ",items[i-1]);
			j-=weights[i-1];
		}
	}	
	
	return table[MAX_LEN][MAX_WEIGHT];
}


