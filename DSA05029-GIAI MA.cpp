//Một bản tin M đã mã hóa bí mật thành các con số theo ánh xạ như sau: ‘A’->1, ‘B’->2, .., ‘Z’->26. 
//Hãy cho biết có bao nhiêu cách khác nhau để giải mã bản tin M. 
//Ví dụ với bản mã M=”123” nó có thể được giải mã thành ABC (1 2 3), LC (12 3), AW(1 23).
//Input
//2
//123
//2563
//Output
//3
//2
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n=s.size();
		int dp[n+1];
		memset(dp,0,sizeof(dp));
		dp[0]=dp[1]=1;
		for(int i=2;i<=n;i++){
			if(s[i-1]>'0') dp[i]=dp[i-1];
			if(s[i-2]=='1'||s[i-2]=='2'&&s[i-1]<='6'){
				dp[i]+=dp[i-2];
			}
		}
		if(s[0]=='0') cout << "0" << endl;
		else cout << dp[n] << endl;
	}
}