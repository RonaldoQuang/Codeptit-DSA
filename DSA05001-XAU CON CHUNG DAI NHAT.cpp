//Cho 2 xâu S1 và S2. 
//Hãy tìm xâu con chung dài nhất của 2 xâu này (các phần tử không nhất thiết phải liên tiếp nhau).
//Input
//2
//AGGTAB
//GXTXAYB
//AA
//BB
//Output
//4
//0
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		string a, b; cin >> a >> b;
		int m=a.size(), n=b.size();
		int dp[m+1][n+1];
		for(int i=0;i<=n;i++){
			dp[0][i]=0;
		}
		for(int i=0;i<=m;i++){
			dp[i][0]=0;
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(a[i-1]==b[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		cout << dp[m][n] << endl; 
	}
}