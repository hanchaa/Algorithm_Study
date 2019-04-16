#include <stdio.h>
#include <string.h>
#include <math.h>

void bfs(int list[10][15], int order[10], int start){
	int queue[15] = { 0 };
	int front = 0, rear = 0;
	
	queue[rear++] = start;
	
	while(front < rear){
		for(int i = 0; list[queue[front]][i] != 0; i++){
			if(order[list[queue[front]][i]] == 0 && list[queue[front]][i] != start){
				queue[rear++] = list[queue[front]][i];
				order[queue[rear - 1]] = order[queue[front]] + 1;
			}
		}
		front++;
		
	}
}

int main(void){
	int M[10][15] = { {0}, {2, 4, 5}, {3, 4, 5}, {2}, {5}, {3} };
	int R1[10][15] = { {0}, {2, 4}, {3, 5}, {2}, {0}, {3} };
	int R2[10][15] = { {0}, {2, 4}, {5}, {2}, {5}, {3} };
	float d[10] = {0, 0.1, 0.5, 0.2, 0.2, 0.5};
	int morder[10], order1[10], order2[10];
	float sum1 = 0, sum2 = 0, a = 0.5;
	
	for(int i = 1; i <= 5; i++){
		memset(morder,0,sizeof(morder));
		memset(order1,0,sizeof(order1));
		memset(order2,0,sizeof(order2));
		
		bfs(M, morder, i);
		bfs(R1, order1, i);
		bfs(R2, order2, i);
		
		for(int j = 1; j <= 5; j++){
			if(j != i && morder[j] != 0 && order1[j] != 0){
				sum1 += d[i] * d[j] * pow(a, morder[j] + order1[j] - 2);
			}
			
			if(j != i && morder[j] != 0 && order2[j] != 0){
				sum2 += d[i] * d[j] * pow(a, morder[j] + order2[j] - 2);
			}
		}
	}
	
	printf("%f %f\n", sum1, sum2);
}