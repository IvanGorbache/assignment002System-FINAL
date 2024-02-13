#include <stdio.h>
#include <stdlib.h>

#define MAX_WEIGHT 20

#define MAX_LEN 5

#define STR_LEN 20

#define max(A, B) ((A)>(B) ? (A) : (B))

int knapSack(int[MAX_LEN], int[MAX_LEN], int[MAX_LEN]);
void getInputs(char*[MAX_LEN], int[MAX_LEN], int[MAX_LEN]);
void printResults(int, char*[MAX_LEN], int[MAX_LEN]);

int main()
{
	char* items[MAX_LEN];
	int values[MAX_LEN];
	int weights[MAX_LEN];
	int selected_bool[MAX_LEN] = {0,0,0,0,0};
	getInputs(items, weights, values);
	
	printResults(knapSack(weights, values, selected_bool),items,selected_bool);

	for(int i = 0; i < MAX_LEN; i++)
	{
		free(items[i]);
	}
	return 0;
}

int knapSack(int weights[MAX_LEN], int values[MAX_LEN], int selected_bool[MAX_LEN])
{

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
	
	int j = MAX_WEIGHT;
	for(int i = MAX_LEN; i >= 0; i--)
	{
		if(table[i][j] == table[i-1][j-weights[i-1]]+values[i-1])
		{
			selected_bool[i-1] = 1;
			j-=weights[i-1];
		}
	}	
	
	return table[MAX_LEN][MAX_WEIGHT];
}

void getInputs(char* items[MAX_LEN], int weights[MAX_LEN], int values[MAX_LEN])
{
	for(int i = 0; i < MAX_LEN; i++)
	{
		items[i] = malloc(STR_LEN * sizeof(char));
		scanf("%20s",items[i]);
		scanf("%d",&values[i]);
		scanf("%d",&weights[i]);
	}
}

void printResults(int profit, char* items[MAX_LEN], int selected_bool[MAX_LEN])
{
	printf("Maximum profit: %d", profit);
	printf("\nSelected items:");
	for(int i = 0; i < MAX_LEN; i++)
	{
		if(selected_bool[i]==1)
		{
			printf(" %s",items[i]);
		}
	}
}

