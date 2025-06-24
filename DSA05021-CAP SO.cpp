//Cho N cặp số, trong đó số thứ nhất bao giờ cũng nhỏ hơn số thứ 2. 
//Ta nói, cặp số <c, d> được gọi là theo sau cặp số <a,b> nếu b<c. 
//Nhiệm vụ của bạn là tìm số lớn nhất chuỗi các cặp thỏa mãn ràng buộc trên. 
//Ví dụ với các cặp {<5, 24>, <39, 60>, <15, 28>, <27, 40>, <50, 90>} ta có kết quả là 3 tương ứng với chuỗi các cặp {<5,24>, <27, 40>, <50, 90>}.
//Input
//2
//5
//5  24 39 60 15 28 27 40 50 90
//2
//5 10 1 11
//Output
//3
//1
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		pair<int,int> a[n];
		int dp[n];
		for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
		sort(a,a+n);
		int max1=1;
		dp[0]=1;
		for(int i=1;i<n;i++){
			dp[i]=1;
			for(int j=0;j<i;j++){
				if(a[j].second<a[i].first) dp[i]=max(dp[i],dp[j]+1);
			}
			max1=max(max1,dp[i]);
		}
		cout << max1 << endl;
	}
}