//Xét các số X có các chữ số được sắp xếp tăng dần, tức a[1] ≤ a[2] ≤ … ≤ a[N] trong đó a[1], a[2], …, a[N] lần lượt là các chữ số của X. 
//Chẳng hạn 223, 8999, …
//Cho trước số chữ số N. 
//Nhiệm vụ của bạn là đếm xem có bao nhiêu số như vậy.
//Input
//3
//1
//2
//3
//Output
//10
//55
//220
#include <bits/stdc++.h> 
using namespace std;
const int mod=1e9+7; 
int main(){ 
    int t; cin >> t; 
    while(t--){ 
        int n; cin >> n; 
        long long dp[101][10];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<10;i++) dp[1][i]=1;
        for(int i=2;i<=100;i++){
        	for(int j=0;j<=9;j++){
        		for(int k=0;k<=j;k++){
        			dp[i][j]+=dp[i-1][k]%mod;
				}
				dp[i][j]%=mod;
			}
		}
		if(n==1) cout << "10" << endl;
		else{
			long long sum=0;
			for(int i=0;i<=9;i++){
				sum+=dp[n][i]%mod;
			}
			cout << sum%mod << endl;
		}
	} 	 
}