//Cho số nguyên dương P, hãy tìm số nguyên dương N nhỏ nhất mà tích các chữ số của N bằng P.
//Input
//2
//1
//10
//Output
//1
//25
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		long long n; cin >> n;
		map<int,int> mp;
		if(n==1) cout << 1;
		else{
			int i=9;
			while(i>=2){
				if(n%i==0){
					while(n%i==0){
						mp[i]++;
						n/=i;
					}
					i--;
				}
				else i--;
			}
			if(n==1){
				for(int i=2;i<=9;i++){
					if(mp[i]){
						while(mp[i]--){
							cout << i;
						}
					}
				}
			}
			else cout << -1;
		}
		cout << endl;
	}
}