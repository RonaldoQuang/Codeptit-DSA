//Cho mảng A[] gồm n phần tử và số k. 
//Đếm tất cả các cặp phần tử của mảng có tổng bằng k. 
//Ví dụ A[] = {1, 5, 3, 4, 2 }, k = 7 ta có kết quả là 2 cặp (3, 4), (5, 2).
//Input
//2
//5 9 
//1 5 4 1 2
//3 2
//1 1 1
//Output
//1
//3
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n,k,cnt=0; cin >> n >> k;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]<=k&&a[i]+a[j]==k){
					++cnt;
				}
			}
		}
		cout << cnt << endl;
	}
}