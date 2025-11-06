//Cho N số nguyên A[1], A[2], …, A[N] thỏa mãn A[1] x A[2] x … x A[N] = P với số P cho trước.
//Nhiệm vụ của bạn là hãy tính giá trị lớn nhất có thể của GCD(A[1], A[2], …, A[N]).
//Input: 
//Input gồm hai số nguyên dương N và P (1 ≤ N, P ≤ 1012).
//Output: 
//In ra một số nguyên là đáp án tìm được.
//Input
//3 24
//3 1
//1 20
//Output
//2
//1
//20
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    long long n, p; cin >> n >> p;
    vector<pair<long long,long long>> v;
    for(long long i=2;i<=sqrt(p);i++){
    	int cnt=0;
    	while(p%i==0){
    		++cnt;
    		p/=i;
		}
		if(cnt) v.push_back({i,cnt});
	}
	if(p!=1) v.push_back({p,1});
	if(v.size()==0) cout << 1;
	else{
		long long tich=1;
		for(auto x:v){
			tich*=pow(x.first,x.second/n);
		}
		cout << tich;
	}
}