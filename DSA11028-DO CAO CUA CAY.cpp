//Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số A[] =(a0, a1, .., an-1}. 
//Đưa ra phép duyệt theo thứ tự sau (post-order) của cây tìm kiếm cân bằng.  
//Cho một cây có N node, gốc tại  1. 
//Độ cao của một node u được tính bằng khoảng cách từ u tới node gốc. 
//Độ cao của node gốc bằng 0. 
//Nhiệm vụ của bạn là hãy tìm node xa node gốc nhất và in ra độ cao của node này.
//Input
//2
//5
//1 2
//1 3
//2 4
//2 5
//4
//1 2
//2 3
//3 4
//Output
//2
//3
#include <bits/stdc++.h>
using namespace std;
void DFS(vector<int> a[], int chuaxet[], int &m, int i, int cnt){
	m=max(m,cnt);
	chuaxet[i]=1;
	for(int j=0;j<a[i].size();j++){
		if(!chuaxet[a[i][j]]) DFS(a,chuaxet,m,a[i][j],cnt+1);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int n, m=0; cin >> n;
		int chuaxet[n+1]={};
		vector<int> a[n+1];
		int k=n-1;
		while(k--){
			int x, y; cin >> x >> y;
			a[x].push_back(y);
		}
		DFS(a,chuaxet,m,1,0);
		cout << m << endl;	
	}
}