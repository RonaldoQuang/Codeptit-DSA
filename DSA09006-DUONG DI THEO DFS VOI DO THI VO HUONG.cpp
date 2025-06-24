//Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
//Hãy tìm đường đi từ đỉnh sÎV đến đỉnh tÎV trên đồ thị bằng thuật toán DFS.
//Input
//1
//6 9 1 6
//1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6
//Output
//1 2 3 4 5 6
#include<bits/stdc++.h>
using namespace std;
void Try(vector<int> a[], int chuaxet[], int truoc[], int i){
	chuaxet[i]=0;
	for(int j=0;j<a[i].size();j++){
		if(chuaxet[a[i][j]]==1){
			truoc[a[i][j]]=i;
		    Try(a,chuaxet,truoc,a[i][j]);
		}
	}
}
int main(){
    int t; cin >> t;
    while(t--){
    	int n, k, x, y; cin >> n >> k >> x >> y;
    	int b[k+1], c[k+1], chuaxet[n+1], truoc[n+1];
    	for(int i=1;i<=k;i++){
    		cin >> b[i] >> c[i];
		}
		vector<int> a[n+1];
		for(int i=1;i<=k;i++){
			a[b[i]].push_back(c[i]);
			a[c[i]].push_back(b[i]);
		}
		for(int i=1;i<=n;i++){
			sort(a[i].begin(),a[i].end());
			chuaxet[i]=1;
			truoc[i]=0;
		}
		Try(a,chuaxet,truoc,x);
		if(truoc[y]==0) cout << "-1";
		else{
			vector<int> v;
			int u=truoc[y];
			v.push_back(y);
			while(u!=0){
				y=u;
				u=truoc[y];
				v.push_back(y);
			}
			for(int i=v.size()-1;i>=0;i--){
				cout << v[i] << " ";
			}
		}
		cout << endl;
	}	
}