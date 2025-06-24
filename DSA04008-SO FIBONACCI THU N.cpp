//Dãy số Fibonacci được xác định bằng công thức như sau:
//F[0] = 0, F[1] = 1;
//F[n] = F[n-1] + F[n-2] với mọi n >= 2.
//Các phần tử đầu tiên của dãy số là 0, 1, 1, 2, 3, 5, 8, ...
//Nhiệm vụ của bạn là hãy xác định số Fibonaci thứ n. 
//Do đáp số có thể rất lớn, in ra kết quả theo modulo 109+7.
//Input
//3
//2
//6
//20
//Output
//1
//8
//6765
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long f[2][2], m[2][2], n;
void mul(long long f[2][2], long long m[2][2]){
	long long x=(f[0][0]*m[0][0]%mod+f[0][1]*m[1][0]%mod)%mod;
	long long y=(f[0][0]*m[0][1]%mod+f[0][1]*m[1][1]%mod)%mod;
	long long z=(f[1][0]*m[0][0]%mod+f[1][1]*m[1][0]%mod)%mod;
	long long t=(f[1][0]*m[0][1]%mod+f[1][1]*m[1][1]%mod)%mod;
	f[0][0]=x, f[0][1]=y, f[1][0]=z, f[1][1]=t;
}
void pow(long long f[2][2], long long n){
	if(n<=1) return;
	pow(f,n/2);
	mul(f,f);
	if(n%2==1) mul(f,m);
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
    	f[0][0]=f[0][1]=f[1][0]=1;
    	f[1][1]=0;
    	m[0][0]=m[0][1]=m[1][0]=1;
    	m[1][1]=0;
    	if(n==0) cout << "0" << endl;
    	else{
    		pow(f,n-1);
    		cout << f[0][0] << endl;
		}
	}
}