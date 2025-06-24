#include <bits/stdc++.h>
using namespace std;
void BFS(vector<int> a[], int chuaxet[], int i){
	chuaxet[i]=0;
	for(int j=0;j<a[i].size();j++){
		if(chuaxet[a[i][j]]==1) BFS(a,chuaxet,a[i][j]);
	}
}
int main(){
    int t; cin >> t;
    while(t--){
    	int n, k; cin >> n >> k;
    	int b[k+1], c[k+1], chuaxet[n+1], cnt=0;   	
    	for(int i=1;i<=k;i++){
    		cin >> b[i] >> c[i];
		}
		vector<int> a[n+10];
		for(int i=1;i<=k;i++){
			a[b[i]].push_back(c[i]);
			a[c[i]].push_back(b[i]);
		}
		for(int i=1;i<=n;i++){
			sort(a[i].begin(),a[i].end());
			chuaxet[i]=1;
		}
		for(int i=1;i<=n;i++){
			if(chuaxet[i]==1){
				++cnt;
				BFS(a,chuaxet,i);
			}
		}
		cout << cnt << endl;				
	}	
}