//Ma trận kề A của một đồ thị vô hướng là một ma trận chỉ có các số 0 hoặc 1 trong đó A[i][j] = 1 có ý nghĩa là đỉnh i kề với đỉnh j (chỉ số tính từ 1).
//Danh sách kề thì liệt kê các đỉnh kề với đỉnh đó theo thứ tự tăng dần.
//Input
//3
//0 1 1
//1 0 1
//1 1 0
//Output
//2 3
//1 3
//1 2
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==1) cout << j << " ";
		}
		cout << endl;
	}
}