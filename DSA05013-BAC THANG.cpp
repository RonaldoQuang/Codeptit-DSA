//Một chiếc cầu thang có N bậc. 
//Mỗi bước, bạn được phép bước lên trên tối đa K bước. 
//Hỏi có tất cả bao nhiêu cách bước để đi hết cầu thang? (Tổng số bước đúng bằng N).
//Input
//2
//2 2
//4 2
//Output
//2
//5
#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		long long dp[n+5];
		for(int i=2;i<=n;i++) dp[i]=0;
		dp[0]=dp[1]=1;
		for(int i=2;i<=n;i++){
			for(int j=i-min(i,k);j<=i-1;j++){
				dp[i]+=dp[j];
				dp[i]%=mod;
			}
		}
		cout << dp[n] << endl;
	}
}