//Cho mảng A[] gồm n số nguyên dương và số k. 
//Nhiệm vụ của bạn là đếm số các cặp phần tử có hiệu nhỏ hơn k. 
//Ví dụ A[] = {1, 10, 4, 2 }, k=3 ta nhận được kết quả là 2 tương ứng với hiệu các cặp (1, 2), (4, 2).
//Input
//2
//4 3
//1 10 4 2
//3 5
//2 3 4
//Output
//2
//3
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n,k; cin >> n >> k;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		sort(a,a+n);
		long long cnt=0;
		for(int i=0;i<n;i++){
			auto it=lower_bound(a+i+1,a+n,a[i]+k);
			cnt+=it-1-(a+i);
		}
		cout << cnt << endl;
	}
}