//Một người có cái túi thể tích V (V<1000). 
//Anh ta có N đồ vật cần mang theo (N≤1000), mỗi đồ vật có thể tích là A[i] (A[i]≤100) và giá trị là C[i] (C[i]≤100). 
//Hãy xác định tổng giá trị lớn nhất của các đồ vật mà người đó có thể mang theo, sao cho tổng thể tích không vượt quá V.
//Input
//5 3
//2 5 15 10 201
//15 10
//5 2 1 3 5 2 5 8 9 6 3 1 4 7 8
//1 2 3 5 1 2 5 8 7 4 1 2 3 2 1
//Output
//15
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int a[n+1], b[n+1];
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++) cin >> b[i];
		int dp[1001][1001];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=k;j++) {
				dp[i][j]=dp[i-1][j];
				if(j>=a[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+b[i]);
			}
		}
		cout << dp[n][k] << endl;
	}
}