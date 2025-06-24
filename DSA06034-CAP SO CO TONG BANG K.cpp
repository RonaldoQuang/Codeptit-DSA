//Cho dãy số A[] gồm có N phần tử.
//Nhiệm vụ của bạn là đếm xem có bao nhiêu cặp (i, j) mà A[i] + A[j] = K cho trước.
//Mỗi test gồm số nguyên N và K (1≤ N ≤ 100 000, 0 ≤ K ≤ 10^9).
//Input
//4
//4 6
//1 5 7 -1
//5 6
//1 5 7 -1 5
//4 2
//1 1 1 1
//13 11
//10 12 10 15 -1 7 6 5 4 2 1 1 1
//Output
//2
//3
//6
//9
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		sort(a,a+n);
		long long cnt=0;
		for(int i=0;i<n;i++){
			auto it=upper_bound(a+i+1,a+n,k-a[i])-a;
			auto it1=lower_bound(a+i+1,a+n,k-a[i])-a;
			cnt+=it-it1;
		}
		cout << cnt << endl;
	}
}