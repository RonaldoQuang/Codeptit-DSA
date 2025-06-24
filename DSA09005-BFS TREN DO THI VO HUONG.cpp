//Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
//Hãy viết thuật toán duyệt theo chiều rộng bắt đầu tại đỉnh uÎV (BFS(u)=?)
//Input
//1
//6 9 1
//1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6
//Output
//1 2 3 5 4 6
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
    	int n, k, x; cin >> n >> k >> x;
    	int b[k+1], c[k+1], chuaxet[n+1];   	
    	for(int i=1;i<=k;i++){
    		cin >> b[i];
    		cin >> c[i];
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
		for(auto x:v){
			cout << x << " ";
		}
		cout << endl;	
	}	
}