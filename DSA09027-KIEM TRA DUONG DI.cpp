//Cho đồ thị vô hướng có N đỉnh và M cạnh. 
//Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh x và y có tồn tại đường đi tới nhau hay không?
//Input
//1
//6 5
//1 2
//2 3
//3 4
//1 4
//5 6
//2
//1 5
//2 4
//Output
//NO
//YES
#include <bits/stdc++.h>
using namespace std;
void BFS(vector<int> a[], int chuaxet[], int truoc[], int x, int y){
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
	if(truoc[y]==0) cout << "NO";
	else cout << "YES";
	cout << endl;
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
		int tc; cin >> tc;
		while(tc--){
			int x, y; cin >> x >> y;
			BFS(a,chuaxet,truoc,x,y);
			for(int i=1;i<=n;i++){
			    chuaxet[i]=1;
			    truoc[i]=0;
		    }
		}	
	}	
}