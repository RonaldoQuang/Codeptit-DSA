//Một con ếch có thể nhảy 1, 2, 3 bước để có thể lên đến một đỉnh cần đến. 
//Hãy đếm số các cách con ếch có thể nhảy đến đỉnh.
//Input
//2
//1
//5
//Output
//1
//13
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		long long dp[n+5];
		for(int i=2;i<=n;i++) dp[i]=0;
		dp[0]=dp[1]=1;
		for(int i=2;i<=n;i++){
			for(int j=i-min(i,3);j<=i-1;j++){
				dp[i]+=dp[j];
			}
		}
		cout << dp[n] << endl;
	}
}