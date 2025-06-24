//Giả sử bạn đang ở điểm có tọa độ nguyên dương (n,m) và cần dịch chuyển về tọa độ (0,0). 
//Mỗi bước dịch chuyển bạn chỉ được phép dịch chuyển đến tọa độ (n-1, m) hoặc (n, m-1); 
//Từ ô (0,m), hoặc (n, 0) thì có thể di chuyển 1 bước để về gốc (0,0).
//Hãy đếm số cách bạn có thể dịch chuyển về tọa độ (0,0).
//Input
//3
//3 2
//3 6
//3 0
//Output
//10
//84
//1
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		long long dp[n+1][m+1];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) dp[i][0]=1;
		for(int i=1;i<=m;i++) dp[0][i]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]+=dp[i-1][j]+dp[i][j-1];
			}
		}
		cout << dp[n][m] << endl;
	}
}