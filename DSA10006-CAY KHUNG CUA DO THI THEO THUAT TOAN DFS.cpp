//Cho đồ thị vô hướng G=(V, E). 
//Hãy xây dựng một cây khung của đồ thị G với đỉnh u ∈ V là gốc của cây bằng thuật toán DFS.
//Input
//2
//4 4 2
//1 2
//1 3
//2 4
//3 4
//4 2 2
//1 2
//3 4
//Output
//2 1
//1 3
//3 4
//-1
#include <bits/stdc++.h>
using namespace std;
int n, k;
void Tree_DFS(vector<int> a[], vector<pair<int,int>> &v, int chuaxet[], int i){
	chuaxet[i]=0;
	for(int j=0;j<a[i].size();j++){
		if(chuaxet[a[i][j]]){
			v.push_back({i,a[i][j]});
			Tree_DFS(a,v,chuaxet,a[i][j]);
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int u; cin >> n >> k >> u;
		vector<int> a[n+1];
		vector<pair<int,int>> v;
		int chuaxet[n+1];
		for(int i=1;i<=n;i++){
			sort(a[i].begin(),a[i].end());
			chuaxet[i]=1;
		}
		while(k--){
			int x, y; cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		Tree_DFS(a,v,chuaxet,u);
		if(v.size()==n-1){
			for(auto x:v){
				cout << x.first << " " << x.second << endl;
			}
		}
		else cout << -1 << endl;
	}
}