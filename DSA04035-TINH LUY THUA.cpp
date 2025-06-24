//Cho hai số nguyên không âm a và b. Hãy tính ab.
//Nếu kết quả quá lớn hãy chia dư cho 109 + 7.
//Input
//2 3
//2 4
//3 2
//0 0
//Output
//8
//16
//9
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
	long long a, b;
	long long m=1e9+7;
	while(cin >> a >> b){
		if(a!=0) cout << mod(a,b,m);
		else{
			if(b==0) cout << endl;
			else cout << mod(a,b,m);
		}
		cout << endl;
	}
}