//Cho ma trận A[M][N]. 
//Nhiệm vụ của bạn là đếm tất cả các đường đi từ phần tử A[0][0] đến phần tử A[M-1][N-1]. 
//Bạn chỉ được phép dịch chuyển xuống dưới hoặc sang phải phần tử liền kề với vị trí hiện tại.
//Input:
//Dòng đầu tiên đưa vào số lượng bộ test T.
//Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số M, N tương ứng với số hàng và số cột của ma trận; dòng tiếp theo đưa vào các phần tử của ma trận A[][]; các số được viết cách nhau một vài khoảng trống.
//T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 1≤M, N, A[i][j]≤100.
//Output:
//Đưa ra số cách di chuyển của mỗi test theo từng dòng.
//Giải thích test 1: Có 3 cách di chuyển là [1 4 5 6], [1 2 5 6] và [1 2 3 6].
//Input
//2
//2  3
//1  2  3 
//4  5  6
//2  2
//1  2 
//3  4
//Output
//3
//2
#include <bits/stdc++.h>
using namespace std;
int cnt=0;
int d1[2]={1,0};
int d2[2]={0,1};
void Try(int a[100][100], int i, int j, int n, int m){
	for(int k=0;k<2;k++){
        int x=i+d1[k], y=j+d2[k]; 
		if(x<n&&y<m||x<n&&y==m||x==n&&y<m){
			Try(a,x,y,n,m);
		}
		else if(x==n&&y==m){
		    ++cnt;
		}
	}
}
int sum1=0;
int main(){
    int t; cin >> t;
    while(t--){
    	int n, m; cin >> n >> m;
    	int a[100][100];
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			cin >> a[i][j];
			}
		}
		Try(a,1,1,n,m);
		cout << cnt-sum1 << endl;
		sum1+=cnt-sum1;
	}
}