//Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
//Hãy kiểm tra xem đồ thị có liên thông mạnh hay không?
//Input
//1
//6 9 
//1 2 2 4 3 1 3 2 3 5 4 3 5 4 5 6 6  3
//Output
//YES
#include <bits/stdc++.h>
using namespace std;
int BFS(vector<int> a[], int chuaxet[], int x){
	queue<int> q;
	q.push(x);
	chuaxet[x]=0;
	vector<int> v;
	v.push_back(x);
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
    		cin >> b[i];
    		cin >> c[i];
		}
		vector<int> a[n+1];
		for(int i=1;i<=k;i++){
			a[b[i]].push_back(c[i]);
		}
		for(int i=1;i<=n;i++){
			sort(a[i].begin(),a[i].end());
			chuaxet[i]=1;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(BFS(a,chuaxet,i)!=n) ++cnt;
			for(int j=1;j<=n;j++) chuaxet[j]=1;
		}
		if(cnt==0) cout << "YES";
		else cout << "NO";
		cout << endl;
	}	
}