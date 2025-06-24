//Cho hai xâu ký tự str1, str2 bao gồm các ký tự in thường và các thao tác dưới đây:
//Insert: chèn một ký tự bất kỳ vào str1.
//Delete: loại bỏ một ký tự bất kỳ trong str1.
//Replace: thay một ký tự bất kỳ trong str1.
//Nhiệm vụ của bạn là đếm số các phép Insert, Delete, Replace ít nhất thực hiện trên str1 để trở thành str2.
//Input
//1
//geek gesek
//Output
//1
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		string a, b; cin >> a >> b;
		int m=a.size(), n=b.size();
		int dp[m+1][n+1];
		for(int i=0;i<=n;i++){
			dp[0][i]=i;
		}
		for(int i=0;i<=m;i++){
			dp[i][0]=i;
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(a[i-1]==b[j-1]){
					dp[i][j]=dp[i-1][j-1];
				}
				else{
					dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
				}
			}
		}
		cout << dp[m][n] << endl;
	}
}