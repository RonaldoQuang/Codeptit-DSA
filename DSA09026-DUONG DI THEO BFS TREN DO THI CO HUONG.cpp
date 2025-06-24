//Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
//Hãy tìm đường đi từ đỉnh uÎV đến đỉnh vÎV trên đồ thị bằng thuật toán BFS.
//Input
//1
//6 9 1 6
//1 2 2 5 3 1 3 2 3 5 4 3 5 4 5 6 6 4
//Output
//1 2 5 6
#include <bits/stdc++.h>
using namespace std;
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
		}
		for(int i=1;i<=n;i++){
			sort(a[i].begin(),a[i].end());
			chuaxet[i]=1;
			truoc[i]=0;
		}
		queue<int> q;
		q.push(x);
		chuaxet[x]=0;
		while(!q.empty()){
			int s=q.front();
			q.pop();
			for(int i=0;i<a[s].size();i++){
				if(chuaxet[a[s][i]]){
					chuaxet[a[s][i]]=0;
					q.push(a[s][i]);
					truoc[a[s][i]]=s;
				}
			}
		}
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