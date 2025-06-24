//Người ta tạo ra một dãy xâu ký tự nhị phân X[] trong đó:
//X[1] = “0”
//X[2] = “1”
//X[i] = X[i-2] + X[i-1] với i>2
//Với phép cộng (+) là phép nối hai xâu với nhau. 
//Cho hai số tự nhiên N và K (1<N<93; K đảm bảo trong phạm vi của xâu X[N]).
//Hãy xác định ký tự thứ K trong xâu X[N] là ký tự ‘0’ hay ký tự ‘1’.
//Input
//2
//3 1
//4 3
//Output
//0
//1
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
	if(n==1) cout << "0" << endl;
	else cout << "1" << endl;
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