//Cho dãy số A[] gồm có N phần tử.
//Nhiệm vụ của bạn là hãy đếm số bộ ba (i, j, k) mà A[i] + A[j] + A[k] < K cho trước.
//Input
//2
//4 2
//-2 0 1 3
//5 12
//5 1 3 4 7
//Output
//2
//4
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		long long n, k; cin >> n >> k;
		long long a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		long long cnt=0;
		sort(a,a+n);
		for(int i=0;i<n-2;i++){
			if(a[i]>=k) break;
			for(int j=i+1;j<n-1;j++){
				auto it=lower_bound(a+j+1,a+n,k-a[i]-a[j])-a;
				cnt+=it-j-1;
			}
		}
		cout << cnt << endl;
	}
}