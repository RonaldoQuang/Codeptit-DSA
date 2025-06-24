//Cho 2 số nguyên N và K. 
//Bạn hãy đếm số lượng các số có N chữ số mà tổng các chữ số của nó bằng K. 
//Lưu ý, chữ số 0 ở đầu không được chấp nhận.
//Input
//3
//2 2
//2 5
//3 6
//Output
//2
//5
//21
#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long dp[101][901];
void tinh(){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=9;i++) dp[1][i]=1;
	for(int i=2;i<=100;i++){
		for(int j=1;j<=9*i;j++){
			for(int h=j-9;h<=j;h++){
				dp[i][j]+=dp[i-1][h]%mod;
			}
			dp[i][j]%=mod;
		}
	}
}
int main(){
	int t; cin >> t;
	tinh();
	while(t--){
		int n, k; cin >> n >> k;
		if(k>900||k/9>n) cout << "0";
		else{
			cout << dp[n][k]%mod << endl;
		}
	}
}