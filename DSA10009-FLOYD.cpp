//Cho đơn đồ thị vô hướng liên thông G = (V, E) gồm N đỉnh và M cạnh, các đỉnh được đánh số từ 1 tới N và các cạnh được đánh số từ 1 tới M.
//Có Q truy vấn, mỗi truy vấn yêu cầu bạn tìm đường đi ngắn nhất giữa đỉnh X[i] tới Y[i].
//Input
//5 6
//1 2 6
//1 3 7
//2 4 8
//3 4 9
//3 5 1
//4 5 2
//3
//1 5
//2 5
//4 3
//Output
//8
//10
//3
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m; cin >> n >> m;
	int a[n+1][n+1], d[n+1][n+1]={};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=1e9;
		}
	}
	while(m--){
		int u, v, c; cin >> u >> v >> c;
		a[u][v]=c;
		a[v][u]=c;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) d[i][j]=0;
			else d[i][j]=a[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
	int q; cin >> q;
	while(q--){
		int x, y; cin >> x >> y;
		cout << d[x][y] << endl;
	}
}