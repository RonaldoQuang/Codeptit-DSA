//Cho đồ thị vô hướng có N đỉnh và M cạnh. 
//Bạn hãy tìm đường đi dài nhất trên đồ thị, sao cho mỗi cạnh chỉ được đi qua nhiều nhất 1 lần.
//Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 10). 
//Mỗi test bắt đầu bằng số nguyên N và M (1 ≤ N, M ≤ 20). 
//Các đỉnh đánh dấu từ 0, 1, …, N-1. M dòng tiếp theo, mỗi dòng gồm 2 số u, v cho biết có cạnh nối giữa uàv.
//Output: Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.
//Input
//2
//3 2
//0 1
//1 2
//15 16
//0 2
//1 2
//2 3
//3 4
//3 5
//4 6
//5 7
//6 8
//7 8
//7 9
//8 10
//9 11
//10 12
//11 12
//10 13
//12 14
//Ouput
//2
//12
#include <bits/stdc++.h>
using namespace std;
void Try(vector<int> a[20], int b[20][20], int &m, int cnt, int i){
	for(int j=0;j<a[i].size();j++){
		if(b[i][a[i][j]]==0){
			++cnt;
			b[i][a[i][j]]=1;
			b[a[i][j]][i]=1;
			Try(a,b,m,cnt,a[i][j]);
			m=max(m,cnt);
			--cnt;
			b[i][a[i][j]]=0;
			b[a[i][j]][i]=0;
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int n, k, m=1, cnt=0; cin >> n >> k;
		vector<int> a[20];
		int b[20][20]={};
		while(k--){
			int x, y; cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		for(int i=0;i<n;i++){
			Try(a,b,m,cnt,i);
		}
		cout << m << endl;
	}
}