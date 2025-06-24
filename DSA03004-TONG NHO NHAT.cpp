//Cho mảng A[] gồm các số từ 0 đến 9. Nhiệm vụ của bạn là tìm tổng nhỏ nhất của hai số được tạo bởi các số trong mảng A[]. 
//Chú ý, tất cả các số trong mảng A[] đều được sử dụng để tạo nên hai số.
//Input
//2
//6
//6 8 4 5 2 3
//5
//5 3 0 7 4
//Output
//604
//82
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n+1];
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		string s1="", s2="";
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(i%2==1) s1+=a[i]+'0';
			else s2+=a[i]+'0';
		}
		cout << stoll(s1)+stoll(s2) << endl;
	}
}