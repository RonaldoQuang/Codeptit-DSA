//Đồ thị hai phía là một đồ thị đặc biệt, trong đó tập các đỉnh có thể được chia thành hai tập không giao nhau thỏa mãn điều kiện không có cạnh nối hai đỉnh bất kỳ thuộc cùng một tập. 
//Cho đồ thị N đỉnh và M cạnh, bạn hãy kiểm tra đồ thị đã cho có phải là một đồ thị hai phía hay không?
//Input
//2
//5 4
//1 5
//1 3
//2 3
//4 5
//3 3
//1 2
//1 3
//2 3
//Output
//YES
//NO
#include <bits/stdc++.h>
using namespace std;
int BFS(vector<int> a[], int color[], int n){
	queue<int> q;
	q.push(n);
	color[n]=1;
	while(!q.empty()){
		int i=q.front(); q.pop();
		for(int j=0;j<a[i].size();j++){
			if(color[a[i][j]]==0){
				if(color[i]==1) color[a[i][j]]=2;
				else color[a[i][j]]=1;
				q.push(a[i][j]);
			}
			else{
				if(color[i]==color[a[i][j]]) return 0;
			}
		}
	}
	return 1;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n, k, ok=1; cin >> n >> k;
		vector<int> a[n+1];
		int color[n+1]={};
		while(k--){
			int x, y; cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			if(color[i]==0){
				if(!BFS(a,color,i)){
					ok=0;
					break;
				}
			}
		}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}