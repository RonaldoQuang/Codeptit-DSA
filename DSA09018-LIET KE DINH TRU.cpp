//Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
//Hãy đưa ra tất cả các đỉnh trụ của đồ thị?
//Input
//1
//5 5
//1 2 1 3 2 3 2 5 3 4
//Output
//2 3
#include <bits/stdc++.h>
using namespace std;
int BFS(vector<int> a[], int chuaxet[], int x){
	queue<int> q;
	q.push(x);
	vector<int> v;
	while(!q.empty()){
		int s=q.front();
		q.pop();
		for(int i=0;i<a[s].size();i++){
			if(chuaxet[a[s][i]]){
				chuaxet[a[s][i]]=0;
				q.push(a[s][i]);
				v.push_back(a[s][i]);
			}
		}
	}
	return v.size();
}
int main(){
    int t; cin >> t;
    while(t--){
    	int n, k; cin >> n >> k;
    	int b[k+1], c[k+1], chuaxet[n+1];   	
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
		}
		vector<int> v;
		for(int i=1;i<=n;i++){
			chuaxet[i]=0;
			if(i<n){
				if(BFS(a,chuaxet,i+1)!=n-1) v.push_back(i);
			}
			else if(BFS(a,chuaxet,i-1)!=n-1) v.push_back(i);
			for(int j=1;j<=n;j++) chuaxet[j]=1;
		}
		for(auto x:v) cout << x << " ";
		cout << endl;	
	}	
}