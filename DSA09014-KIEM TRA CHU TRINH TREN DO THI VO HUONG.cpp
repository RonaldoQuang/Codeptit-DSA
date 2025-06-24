//Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
//Hãy kiểm tra xem đồ thị có tồn tại chu trình hay không?
//Input
//1
//6 9
//1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6
//Output
//YES
#include<bits/stdc++.h>
using namespace std;
bool DFS(vector<int> a[], int chuaxet[], int truoc[], int i){
	chuaxet[i]=0;
	for(int j=0;j<a[i].size();j++){
		if(chuaxet[a[i][j]]==1){
			truoc[a[i][j]]=i;
		    DFS(a,chuaxet,truoc,a[i][j]);
		}
		else if(a[i][j]!=truoc[i]) return true; 
	}
	return false;
}
int main(){
    int t; cin >> t;
    while(t--){
    	int n, k; cin >> n >> k;
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
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(DFS(a,chuaxet,truoc,i)){
				++cnt;
				break;
			}
			for(int j=1;j<=n;j++){
				chuaxet[j]=1;
				truoc[j]=0;
			}
		}
		if(cnt==1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
}