//Cho xâu ký tự str. 
//Nhiệm vụ của bạn là tìm số phép chèn tối thiểu các ký tự vào str để str trở thành xâu đối xứng. 
//Ví dụ: str =”ab” ta có số phép chèn tối thiểu là 1 để trở thành xâu đối xứng “aba” hoặc “bab”. 
//Với xâu str=”aa” thì số phép chèn tối thiểu là 0. 
//Với xâu str=”abcd” có số phép chèn tối thiểu là 3 để trở thành xâu “dcbabcd”
//Input
//3
//abcd
//aba
//geeks
//Output
//3
//0
//3
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