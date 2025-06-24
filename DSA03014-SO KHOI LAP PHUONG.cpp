//Một số X được gọi là số khối lập phương nếu X là lũy thừa bậc 3 của số Y (X= Y3). 
//Cho số nguyên dương N, nhiệm vụ của bạn là tìm số khối lập phương lớn nhất bằng cách loại bỏ đi các chữ số của N. 
//Ví dụ số 4125 ta có kết quả là 125 = 5^3.
//Input
//2
//4125
//976
//Output
//125
//-1
#include <bits/stdc++.h>
using namespace std;
int check(long long n, long long k){
	int x=-1;
	long long m=k*k*k;
	string s=to_string(n);
	string a=to_string(m);
	for(int i=0;i<a.size();i++){
		int ok=0;
		for(int j=0;j<s.size();j++){
			if(s[j]==a[i]&&j>x){
				ok=1;
				x=j;
				break;
			}
		}
		if(ok==0) return 0;
	}
	return 1;
}
int main(){
	int t; cin >> t;
	while(t--){
		long long n, m=-1; cin >> n;
		long long x=cbrt(n);
		for(long long i=x;i>=1;i--){
			if(check(n,i)){
				m=i*i*i;
				break;
			}
		}
		cout << m << endl;
	}
}