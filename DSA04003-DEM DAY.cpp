//Cho số nguyên dương n. 
//Hãy cho biết có bao nhiêu dãy số nguyên dương có tổng các phần tử trong dãy bằng n. 
//Input
//1
//3
//Output
//4
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
		long long n, m=123456789; cin >> n;
		cout << mod(2,n-1,m) << endl; 
	}
}