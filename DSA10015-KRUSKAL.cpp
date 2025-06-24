//Cho đồ thị vô hướng có trọng số G=<V, E, W>. 
//Nhiệm vụ của bạn là hãy xây dựng một cây khung nhỏ nhất của đồ thị bằng thuật toán Kruskal.
//Input
//1
//6 9
//1 2 12
//1 3 4
//2 3 1
//2 4 5
//2 5 3
//3 5 2
//4 5 3
//4 6 10
//5 6 8
//Ouput
//18
#include <bits/stdc++.h>
using namespace std;
struct Canh{
	int u, v, g;
};
typedef struct Canh canh;
bool cmp(canh a, canh b){
	return a.g<b.g;
}
int find(int truoc[], int v){
	if(v==truoc[v]) return v;
	return find(truoc,truoc[v]);
}
bool unit(int truoc[], int sz[], int a, int b){
	a=find(truoc,a);
	b=find(truoc,b);
	if(a==b) return false;
	if(sz[a]<sz[b]) swap(a,b);
	truoc[b]=a;
	sz[a]+sz[b];
	return true;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n, k, dT=0; cin >> n >> k;
		canh a[k];
		int truoc[n+1], sz[n+1];
		vector<pair<int,int>> T, ve;
		for(int i=1;i<=n;i++){
			truoc[i]=i;
			sz[i]=1;
		}
		for(int i=0;i<k;i++){
			cin >> a[i].u >> a[i].v >> a[i].g;
			ve.push_back({a[i].u,a[i].v});
		}
		sort(a,a+k,cmp);
		int i=0;
		while(T.size()<n-1&&ve.size()>0){
			ve.erase(ve.begin()+i);
			if(unit(truoc,sz,a[i].u,a[i].v)){
				T.push_back({a[i].u,a[i].v});
				dT+=a[i].g;
			}
			++i;
		}
		cout << dT << endl;
	}
}