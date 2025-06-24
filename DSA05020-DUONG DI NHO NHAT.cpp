//Cho bảng A[] kích thước N x M (N hàng, M cột). 
//Bạn được phép đi xuống dưới, đi sang phải và đi xuống ô chéo dưới. 
//Khi đi qua ô (i, j), điểm nhận được bằng A[i][j].
//Hãy tìm đường đi từ ô (1, 1) tới ô (N, M) sao cho tổng điểm là nhỏ nhất.
//Input
//1
//3 3
//1 2 3
//4 8 2
//1 5 3
//Output
//8
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
    	int n, m; cin >> n >> m;
    	int a[n+1][m+1], dp[n+1][m+1];
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			cin >> a[i][j];
			}
		}
		dp[1][1]=a[1][1];
		for(int j=2;j<=m;j++) dp[1][j]=dp[1][j-1]+a[1][j];
		for(int i=2;i<=n;i++) dp[i][1]=dp[i-1][1]+a[i][1];
		for(int i=2;i<=n;i++){
			for(int j=2;j<=m;j++){
				dp[i][j]=min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]})+a[i][j];
			}
		}
		cout << dp[n][m] << endl;
	}	
}