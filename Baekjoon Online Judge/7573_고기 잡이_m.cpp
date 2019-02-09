#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX(a,b)(a>b?a:b)

using namespace std;

struct koi{
	int x,y;
};


int main(){
	
	int l, n, m, i, j, k, cnt = 0, max = 0, x, y, dx[105], dy[105];
	koi data[105];
	
	memset(dx,0,sizeof(dx));
	memset(dy,0,sizeof(dy));
	
	scanf("%d %d %d", &n, &l, &m);
	
	for(i = 0; i < m; i++){
		scanf("%d %d", &data[i].x, &data[i].y);
		dx[i] = data[i].x;
		dy[i] = data[i].y;
	}
	
	sort(dx,dx+m);
	sort(dy,dy+m);
	
	for(i = 0; i < m; i++){
		for(j = 0; j < m; j++){
			for(k = 1; k < l/2; k++){
				
				cnt = 0;
				
				for(n = 0; n < m; n++){
					if(data[n].x <= dx[i] + k && data[n].x >= dx[i] && data[n].y <= dy[j] + l / 2 - k && data[n].y >= dy[j]) cnt++;
				}
				
				max = MAX(max,cnt);
			}
		}
		
	}
	
	printf("%d",max);
	
	return 0;
}