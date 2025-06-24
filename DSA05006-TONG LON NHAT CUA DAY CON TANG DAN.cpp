//Cho dãy số A[] gồm N số. 
//Nhiệm vụ của bạn là tìm tổng lớn nhất của dãy con được sắp theo thứ tự tăng dần của dãy A[]. 
//Ví dụ với dãy A[] = {1, 101, 2, 3, 100, 4, 5} ta có kết quả là 106 = 1 + 2 + 3 + 100. 
//Với dãy A[] = {10, 7, 5} ta có kết quả là 10. 
//Với dãy A[] = {1, 2, 3, 5} ta có kết quả là 11.
//Input
//3
//7
//1 101 2 3 100 4 5
//3
//10 7 5
//4
//1 2 3 5
//Output
//106
//10
//11
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		long long a[100000];
		for(int i=1;i<=n;i++) cin >> a[i];
		long long dp[100000];
		dp[1]=a[1];
		if(a[1]<a[2]) dp[2]=dp[1]+a[2];
		else dp[2]=a[2];
		long long max1=max(dp[1],dp[2]);
		for(int i=3;i<=n;i++){
			dp[i]=a[i];
			for(int j=1;j<i;j++){
				if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+a[i]);
				max1=max(max1,dp[i]);
			}
		}
		cout << max1 << endl;
	}
}