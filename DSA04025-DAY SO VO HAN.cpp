//Dãy số nguyên dương vô hạn A[] được định nghĩa một cách đệ quy như sau:
//A[0] = 0
//A[1] = 1;
//A[i] = A[i-1] + A[i-2] với mọi n ≥ 2.
//Cho số nguyên dương N không quá 109. Hãy xác định số thứ N trong dãy A[]. Nếu kết quả quá lớn, hãy in ra theo modulo 10^9+7.
//Input
//2
//2
//6
//Output
//1
//8
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