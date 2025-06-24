//Cho một bảng số N hàng, M cột chỉ gồm 0 và 1. 
//Bạn hãy tìm hình vuông có kích thước lớn nhất, sao cho các số trong hình vuông toàn là số 1.
//Input
//2
//6 5
//0 1 1 0 1
//1 1 0 1 0
//0 1 1 1 0
//1 1 1 1 0
//1 1 1 1 1
//0 0 0 0 0
//2 2
//0 0
//0 0
//Output
//3
//0
#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int t; cin >> t; 
	while(t--){ 
	    int n, m; cin >> n >> m;
	    int a[n+1][m+1], dp[n+1][m+1];
	    for(int i=1;i<=n;i++){
	    	for(int j=1;j<=m;j++){
	    		cin >> a[i][j];
			}
		}
		memset(dp,0,sizeof(dp));
		int max1=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]){
					dp[i][j]=min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+1;
				}
				max1=max(max1,dp[i][j]);
			}
		}
		cout << max1 << endl;
	} 
}