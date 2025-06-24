//Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
//Hãy viết thuật toán duyệt theo chiều sâu bắt đầu tại đỉnh uÎV (DFS(u)=?)
//Input
//1
//6 9 5
//1 2
//1 3
//2 3
//2 4
//3 4
//3 5
//4 5
//4 6
//5 6
//Output
//5 3 1 2 4 6
#include <bits/stdc++.h>
using namespace std;
void Try(vector<int> a[], int chuaxet[], int i){
	cout << i << " ";
	chuaxet[i]=0;
	for(int j=0;j<a[i].size();j++){
		if(chuaxet[a[i][j]]==1) Try(a,chuaxet,a[i][j]);
	}
}
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
		Try(a,chuaxet,x);
		cout << endl;	
	}
	
}