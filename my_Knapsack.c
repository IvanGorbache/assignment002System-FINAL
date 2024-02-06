#include <stdio.h>

#define MAX_WEIGHT 20
#define MAX_LEN 5

#define max(A, B) ((A)>(B) ? (A) : (B))


int knapSack(int[MAX_LEN], int[MAX_LEN], int[MAX_LEN]);
void fillResults(char[MAX_LEN], int[MAX_LEN], char[MAX_LEN]);
void getInputs(char[MAX_LEN], int[MAX_LEN], int[MAX_LEN]);
void printResults(int profit, char result[MAX_LEN]);

int main()
{
	char items[MAX_LEN];
	char result[MAX_LEN] = {0,0,0,0,0};
	int values[MAX_LEN];
	int weights[MAX_LEN];
	int selected_bool[MAX_LEN] = {0,0,0,0,0};
	int profit = 0;
	getInputs(items, weights, values);
	
	profit = knapSack(weights, values, selected_bool);
	fillResults(items, selected_bool, result);

	printResults(profit,result);
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

void fillResults(char items[MAX_LEN], int selected_bool[MAX_LEN], char result[MAX_LEN])
{
	int k = 0;
	for(int i = 0; i < MAX_LEN; i++)
	{
		if(selected_bool[i])
		{
			result[k++] = items[i];
		}
	}
}

void getInputs(char items[MAX_LEN], int weights[MAX_LEN], int values[MAX_LEN])
{
	printf("\nPlease input values for %d item(s) (knapsack capacity: %d):",MAX_LEN,MAX_WEIGHT);
	for(int i = 0; i < MAX_LEN; i++)
	{
		printf("\nEnter name for item number (%d):",i+1);
		scanf(" %c",&items[i]);
	}
	for(int i = 0; i < MAX_LEN; i++)
	{
		printf("\nEnter value for item (%c):",items[i]);
		scanf("%d",&values[i]);
	}
	for(int i = 0; i < MAX_LEN; i++)
	{
		printf("\nEnter weight for item (%c):",items[i]);
		scanf("%d",&weights[i]);
	}
	printf("\nThank you! Happy trails!");
}

void printResults(int profit, char result[MAX_LEN])
{
	printf("\nMaximum profit: %d", profit);
	printf("\nItems that give the maximum profit: [");
	for(int i = MAX_LEN-1; i >= 0; i--)
	{
		if(result[i]!=0)
		{
			printf("%c",result[i]);
			if(i-1>=0 && result[i-1]!=' ')
			{
				printf(", ");
			}
		}
	}
	printf("]\n");
}

