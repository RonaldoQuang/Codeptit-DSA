//Cho một bản đồ kích thước N x M được mô tả bằng ma trận A[][].A[i][j] = 1 có nghĩa vị trí (i, j) là nổi trên biển. 
//2 vị trí (i, j) và (x, y) được coi là liền nhau nếu như nó có chung đỉnh hoặc chung cạnh. 
//Một hòn đảo là một tập hợp các điểm (i, j) mà A[i][j] = 1 và có thể di chuyển giữa hai điểm bất kì trong đó.
//Nhiệm vụ của bạn là hãy đếm số lượng đảo xuất hiện trên bản đồ.
//Input
//1
//5 5
//1 1 0 0 0
//0 1 0 0 1
//1 0 0 1 1
//0 0 0 0 0
//1 0 1 0 1
//Output
//5
#include <bits/stdc++.h>
using namespace std;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
void duyet(int a[505][505], int i, int j, int n, int m){
	a[i][j]=0;
	for(int k=0;k<8;k++){
		int i1=i+dx[k], j1=j+dy[k];
		if(i1>=0&&i1<n&&j1>=0&&j1<m&&a[i1][j1]==1){
			duyet(a,i1,j1,n,m);
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int n, m, a[505][505]; cin >> n >> m;
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> a[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]==1){
					++cnt;
					duyet(a,i,j,n,m);
				}
			}
		}
		cout << cnt << endl; 
	}
}