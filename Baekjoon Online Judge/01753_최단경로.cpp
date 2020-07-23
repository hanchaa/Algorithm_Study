#include <stdio.h>
#include <vector>
#include <queue>

#define M 300005
#define mk make_pair
#define MAX 1000000000

using namespace std;

vector <pair <int, int>>  edge[M];
priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;

int main(){
	int n , m, i, j, a, b, d, s, v, u;
	int D[M];
	bool chk[M];
	
	scanf("%d %d", &n, &m);
	scanf("%d", &s);
	
	for(i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b ,&d);
		edge[a].push_back(mk(b, d));
	}
	
	for(i = 1; i <= n; i++) D[i] = MAX;
	D[s] = 0;
	
	pq.push(mk(0, s));
	
	while(!pq.empty()){
		v = pq.top().second;
		pq.pop();
		
		if(chk[v]) continue;
		chk[v] = true;
		
		for(j = 0; j < edge[v].size(); j++){
			u = edge[v][j].first;
			d = edge[v][j].second;
			
			if(D[u] > D[v] + d){
				D[u] = D[v] + d;
				pq.push(mk(D[u], u));
			}
		}
	}
	
	for(i = 1; i <= n; i++){
		if(D[i] == MAX) printf("INF\n");
		else printf("%d\n", D[i]);
	}
	
	return 0;	
}