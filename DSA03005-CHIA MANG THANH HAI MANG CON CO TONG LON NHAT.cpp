//Cho mảng A[] gồm N số nguyên không âm và số K. 
//Nhiệm vụ của bạn là hãy chia mảng A[] thành hai mảng con có kích cỡ K và N-K sao cho hiệu giữa tổng hai mảng con là lớn nhất. 
//Ví dụ với mảng A[] = {8, 4, 5, 2, 10}, K=2 ta có kết quả là 17 vì mảng A[] được chia thành hai mảng {4, 2} và { 8, 5,10} có hiệu của hai mảng con là 23-6=17 là lớn nhất.
//Input
//2
//5 2
//8 4 5 2 10
//8 3
//1 1 1 1 1 1 1 1
//Output
//17
//2
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int a[n];
		int sum=0, sum1=0;
		for(int i=0;i<n;i++){
			cin >> a[i];
			sum+=a[i];
		}
		sort(a,a+n);
		int x=min(k,n-k);
		for(int i=0;i<x;i++){
			sum1+=a[i];
		}
		cout << sum-2*sum1 << endl;
	}
}