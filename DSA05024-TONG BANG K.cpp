//Cho một mảng A[] gồm N số nguyên và số K. 
//Tính số cách lấy tổng các phần tử của A[] để bằng K. 
//Phép lấy lặp các phần tử hoặc sắp đặt lại các phần tử được chấp thuận. 
//Ví dụ với mảng A[] = {1, 5, 6}, K = 7 ta có 6 cách sau:
//7 = 1 + 1 + 1+1 + 1 + 1+1 (lặp số 1 7 lần)
//7 = 1 + 1 + 5 (lặp số 1)
//7 = 1 + 5 + 1 (lặp và sắp đặt lại số 1)
//7 = 5 + 1 + 1
//7 = 1 + 6
//7 = 6 + 1
//Input
//2
//3 7
//1 5 6
//4 14
//12 3 1 9
//Output
//6
//150
#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int a[n], dp[k+1];
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=0;i<n;i++) cin >> a[i];
		for(int i=1;i<=k;i++){
			for(int j=0;j<n;j++){
				if(i>=a[j]){
					dp[i]+=dp[i-a[j]];
					dp[i]%=mod;
				}
			}
		}
		cout << dp[k] << endl;
	}
}
