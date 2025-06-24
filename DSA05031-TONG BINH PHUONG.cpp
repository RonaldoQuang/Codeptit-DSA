//Mọi số nguyên dương N đều có thể phân tích thành tổng các bình phương của các số nhỏ hơn N. 
//Ví dụ số 100 = 102 hoặc 100 = 52 + 52 + 52 + 52. 
//Cho số nguyên dương N. 
//Nhiệm vụ của bạn là tìm số lượng ít nhất các số nhỏ hơn N mà có tổng bình phương bằng N.
//Input
//3
//100
//6
//25
//Output
//1
//3
//1
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n+1];
		a[0]=0;
		for(int i=1;i<=n;i++){
		    a[i]=i;
		    for(int j=1;j<=sqrt(i);j++){
			    a[i]=min(a[i],a[i-j*j]+1);
		    }
	    }
	    cout << a[n] << endl;
	}
}