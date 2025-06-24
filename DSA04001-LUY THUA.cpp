//Cho số nguyên dương N và K. Hãy tính NK modulo 109+7.
//Input
//2
//2 3
//4 2
//Output
//8
//16
#include <bits/stdc++.h>
using namespace std;
long long mod(long long a, long long b, long long m){
	long long z=1;
	while(b){
	    if(b%2==1){
	        z*=a;
	        z%=m;
	    }
	    a*=a;
	    a%=m;
	    b/=2;
	}
	return z;
}
int main(){
	int t; cin >> t;
	while(t--){
		long long n, k, m=1e9+7; cin >> n >> k;
		cout << mod(n,k,m) << endl; 
	}
}