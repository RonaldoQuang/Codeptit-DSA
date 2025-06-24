//Cho ba xâu ký tự X, Y, Z. 
//Nhiệm vụ của bạn là tìm độ dài dãy con chung dài nhất có mặt trong cả ba xâu.
//Input
//2
//5 8 13
//geeks geeksfor geeksforgeeks
//7 6 5
//abcd1e2 bc12ea bd1ea
//Output
//5
//3
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int x, y, z; cin >> x >> y >> z;
		string a, b, c; cin >> a >> b >> c;
		int dp[x+1][y+1][z+1];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=x;i++){
			for(int j=1;j<=y;j++){
				for(int k=1;k<=z;k++){
					if(a[i-1]==b[j-1]&&b[j-1]==c[k-1]){
						dp[i][j][k]=dp[i-1][j-1][k-1]+1;
					}
					else{
						dp[i][j][k]=max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
					}
				}
			}
		}
		cout << dp[x][y][z] << endl;
	}
}
