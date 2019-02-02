#include <stdio.h>
#define MAX(a,b)(a>b?a:b)

struct koi{
	int x;
	int y;
}queue[1000005];


int main(){
	
	int map[1005][1005], i, j, n = 4, m = 6, f = 1, b = 1, tmp = 0 , x, y;
	
	scanf("%d %d",&m ,&n);
	
	for(i = 0; i < n; i++){
		for(j= 0; j < m; j++){
			scanf("%d",&map[i][j]);
			if(map[i][j] == 1){
				queue[b].x = i;
				queue[b++].y = j;
			}
			if(map[i][j] == 0) tmp = 1;
		}
	}
	
	if(tmp == 0) {
		printf("0");
		return 0;
	}
	
	while(f < b){
		
		x = queue[f].x;
		y = queue[f++].y;
		
		if(x - 1 >= 0 && map[x - 1][y] == 0){
			map[x - 1][y] = map[x][y] + 1;
			queue[b].x = x - 1;
			queue[b++].y = y;
		}
		
		if(y - 1 >= 0 && map[x][y - 1] == 0){
			map[x][y - 1] = map[x][y] + 1;
			queue[b].x = x;
			queue[b++].y = y - 1;
		}
		
		if(x + 1 < n && map[x + 1][y] == 0){
			map[x + 1][y] = map[x][y] + 1;
			queue[b].x = x + 1;
			queue[b++].y = y;
		}
		
		if(y + 1 < m && map[x][y + 1] == 0){
			map[x][y + 1] = map[x][y] + 1;
			queue[b].x = x;
			queue[b++].y = y + 1;
		}
	}
	
	tmp = 0;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(map[i][j] == 0){
				printf("-1");
				return 0;
			}
			tmp = MAX(tmp,map[i][j]);
		}
	}
	
	printf("%d",tmp - 1);
	
	return 0;
}
