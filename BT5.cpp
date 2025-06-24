//Xét dãy xâu ký tự được tạo bởi quy tắc sau:
//F[0]  =  “A”
//F[1]  =  “B”
//…
//F[n]   =  F[n-1]  +  F[n-2]  với n > 1
//Cho hai số nguyên dương n và k. 
//Hãy đếm số lượng ký tự ‘A’ trong k vị trí đầu tiên của xâu F[n].
//Input
//4
//0 1
//1 1
//3 2
//7 7
//Output
//1
//0
//1
//3
#include <bits/stdc++.h>
using namespace std;
int n, k;
long long f[46], cnt[46];
long long find(int n, int k){
	if(k==f[n]) return cnt[n];
	if(k>f[n-1]){
		return cnt[n-1]+find(n-2,k-f[n-1]);
	}
	else return find(n-1,k);
}
int main(){
	f[0]=1, f[1]=1;
	for(int i=2;i<=45;i++) f[i]=f[i-1]+f[i-2];
	cnt[0]=1;
	cnt[1]=0;
	for(int i=2;i<=45;i++) cnt[i]=cnt[i-1]+cnt[i-2];
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
	    cout << find(n,k) << endl;
	}
}