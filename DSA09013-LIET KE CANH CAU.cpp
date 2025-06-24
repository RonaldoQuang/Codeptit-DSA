//Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
//Hãy đưa ra tất cả các cạnh cầu của đồ thị?
//Input
//1
//5 5
//1 2 1 3 2 3 2 5 3 4
//Output
//2 5 3 4
#include <bits/stdc++.h>
using namespace std;
int BFS(vector<int> a[], int chuaxet[], int x, int m, int p){
	queue<int> q;
	q.push(x);
	chuaxet[x]=0;
	vector<int> v;
	v.push_back(x);
	while(!q.empty()){
		int s=q.front();
		q.pop();
		for(int i=0;i<a[s].size();i++){
			if(s==m){
				if(chuaxet[a[s][i]]&&a[s][i]!=p){
				    chuaxet[a[s][i]]=0;
				    q.push(a[s][i]);
				    v.push_back(a[s][i]);
			    }	
			}
			else if(s==p){
				if(chuaxet[a[s][i]]&&a[s][i]!=m){
				    chuaxet[a[s][i]]=0;
				    q.push(a[s][i]);
				    v.push_back(a[s][i]);
			    }	
			}
			else{
				if(chuaxet[a[s][i]]){
				    chuaxet[a[s][i]]=0;
				    q.push(a[s][i]);
				    v.push_back(a[s][i]);
			    }
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
		for(int i=1;i<=k;i++){
			if(BFS(a,chuaxet,1,b[i],c[i])!=n){
				v.push_back(b[i]);
				v.push_back(c[i]);
			}
			for(int j=1;j<=n;j++) chuaxet[j]=1;
		}
		for(auto x:v) cout << x << " ";
		cout << endl;	
	}	
}