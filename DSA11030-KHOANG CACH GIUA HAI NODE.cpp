//Cho một cây có N node, gốc tại 1. 
//Có Q truy vấn, mỗi truy vấn yêu cầu bạn tìm khoảng cách giữa hai node u và v.
//Input
//1
//8
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//6 8
//5
//4 5
//4 6
//3 4
//2 4
//8 5
//Ouput
//2
//4
//3
//1
//5
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &v, vector<int> a[], int check[], int i, int y, int &ok){
	for(int j=0;j<a[i].size();j++){
		if(!check[a[i][j]]){
			v.push_back(a[i][j]);
			check[a[i][j]]=1;
			if(a[i][j]==y){
				cout << v.size()-1 << endl;
				return;
			}
			else dfs(v,a,check,a[i][j],y,ok);
		    v.pop_back();
		}
	}	
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a[n+1];
		int check[n+1];
		for(int i=1;i<=n-1;i++){
			int x, y; cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		int q; cin >> q;
		while(q--){
			vector<int> v;
			int x, y, cnt=0, ok=0; cin >> x >> y;
			v.push_back(x);
			memset(check,0,sizeof(check));
			check[x]=1;
			if(x==y) cout << 0 << endl;
			else dfs(v,a,check,x,y,ok);
		}
	}
}