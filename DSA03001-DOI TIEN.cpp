//Tại ngân hàng có các mệnh giá bằng 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000. 
//Tổng số tiền cần đổi có giá trị bằng N.  
//Hãy xác định xem có ít nhất bao nhiêu tờ tiền sau khi đổi tiền?
//Input
//2
//70
//121
//Output
//2
//3
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[10]={1,2,5,10,20,50,100,200,500,1000};
		int cnt=0;
		int i=9;
		while(n){
			while(a[i]>n){
				i--;
			}
			cnt+=n/a[i];
			n=n-(n/a[i])*a[i];
		}
		cout << cnt << endl;
	}
}