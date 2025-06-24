//Có N ngôi nhà trên một dãy phố, mỗi ngôi nhà chứa đựng một số lượng tài sản khác nhau. 
//Một tên trộm muốn ăp cắp được nhiều nhất tài sản của dãy phố nhưng không muốn lấy tài sản của hai nhà kề nhau. 
//Hãy cho biết, bằng cách đó tên trộm có thể đánh cắp được nhiều nhất bao nhiêu tài sản.
//Input
//2
//6
//5 5 10 100 10 5
//4
//3 2 7 10
//Output
//110
//13
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		long long a[100000];
		for(int i=1;i<=n;i++) cin >> a[i];
		long long dp[100000];
		dp[1]=a[1], dp[2]=max(a[1],a[2]);
		long long max1=0;
		for(int i=3;i<=n;i++){
			dp[i]=max(dp[i-1],dp[i-2]+a[i]);
			max1=max(max1,dp[i]);
		}
		cout << max1 << endl;
	}
}