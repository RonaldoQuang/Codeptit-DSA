//Cho xâu ký tự S. 
//Nhiệm vụ của bạn là tìm số phép loại bỏ ít nhất các ký tự trong S để S trở thành xâu đối xứng. 
//Chú ý, phép loại bỏ phải bảo toàn tính trước sau của các ký tự trong S.
//Input
//2
//aebcbda
//geeksforgeeks
//Output
//2
//8
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		string a, b=""; cin >> a;
		for(int i=a.size()-1;i>=0;i--){
			b+=a[i];
		}
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
		cout << a.size()-dp[m][n] << endl; 
	}
}