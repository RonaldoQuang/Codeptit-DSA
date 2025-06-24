//John có một đàn bò. 
//Một ngày đẹp trời, anh ta quyết định mua xe tải với khả năng chở được C kg (1000 ≤ C ≤ 25000) để đưa những con bò đi xem phim. 
//Cho số con bò là N (20 ≤ N ≤ 100) và khối lượng w[i] của từng con (đều nhỏ hơn C), hãy cho biết khối lượng bò lớn nhất mà John có thể đưa đi xem phim là bao nhiêu.
//Input
//259 5
//81
//58
//42
//33
//61
//Output
//242
#include <bits/stdc++.h>
using namespace std;
int main() {
	int k ,n ; cin >> k >> n;
	int a[n+1];
	for(int i=1;i<=n;i++) cin >> a[i];
	int dp[101][25001];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=a[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+a[i]);
		}
	}
	cout << dp[n][k] << endl;		
}