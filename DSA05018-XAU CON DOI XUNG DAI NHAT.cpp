//Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự.
//Hãy tìm xâu con đối xứng dài nhất của S.
//Input
//2
//abcbadd
//aaaaa
//Output
//5
//5
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
    	string s; cin >> s;
    	int n=s.size();
    	int dp[n][n];
    	memset(dp,0,sizeof(dp));
    	for(int i=0;i<n;i++){
    		dp[i][i]=1;
    		if(i<n-1){
    			if(s[i]==s[i+1]) dp[i][i+1]=1;
			}
		}
		int max1=1;
		for(int i=2;i<=n-1;i++){
			for(int j=0;j<=n-i;j++){
				if(s[j]==s[j+i]&&dp[j+1][j+i-1]==1){
					dp[j][j+i]=1;
				}
			}
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(dp[i][j]==1) max1=max(max1,j-i+1);
			}
		}
		cout << max1 << endl;
	}	
}