//Cho đồ thị có trọng số không âm G=<V, E> được biểu diễn dưới dạng danh sách cạnh trọng số. 
//Hãy viết chương trình tìm đường đi ngắn nhất từ đỉnh uÎV đến tất cả các đỉnh còn lại trên đồ thị.
//Input
//1
//9  12 1
//1  2   4
//1  8   8
//2  3   8
//2  8   11
//3  4   7
//3  6   4
//3  9   2
//4  5   9
//4  6  14
//5  6  10
//6  7  2
//6  9  6
//Output
//0 4 12 19 26 16 18 8 14
#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
void dijkstra(vector<pair<int,int>> a[], int n, int s){
	vector<int> d(n+1,inf);
	d[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,s});
	while(!q.empty()){
		pair<int,int> p=q.top(); q.pop();
		int u=p.second, kc=p.first;
		for(auto it:a[u]){
			int v=it.first, w=it.second;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout << d[i] << " ";
	}
	cout << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n, m, s; cin >> n >> m >> s;
		vector<pair<int,int>> a[n+1];
		while(m--){
			int u, v, w; cin >> u >> v >> w;
			a[u].push_back({v,w});
			a[v].push_back({u,w});
		}
		dijkstra(a,n,s);
	}
}