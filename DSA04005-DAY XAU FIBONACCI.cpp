//Một dãy xâu ký tự G chỉ bao gồm các chữ cái A và B được gọi là dãy xâu Fibonacci nếu thỏa mãn tính chất:    
//G(1) = A; G(2) = B; G(n) = G(n-2)+G(n-1). 
//Với phép cộng (+) là phép nối hai xâu với nhau.  
//Bài toán đặt ra là tìm ký tự ở vị trí thứ i (tính từ 1) của xâu Fibonacci thứ n.
//Input
//2
//6 4
//8 19
//Output
//A
//B
#include <bits/stdc++.h>
using namespace std;
long long f[93];
void kq(long long n, long long k){
	while(n>2){
		if(k>f[n-2]){
			k-=f[n-2];
			n-=1;
		}
		else n-=2;
	}
	if(n==1) cout << "A" << endl;
	else cout << "B" << endl;
}
int main(){
    f[1]=f[2]=1;
    for(int i=3;i<93;i++){
    	f[i]=f[i-2]+f[i-1];
	}
	int t; cin >> t;
	while(t--){
		long long n, k; cin >> n >> k;
		kq(n,k);
	}
}