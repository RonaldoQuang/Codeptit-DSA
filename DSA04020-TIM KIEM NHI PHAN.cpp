//Cho dãy số A[] gồm có N phần tử đã được sắp xếp tăng dần và số K.
//Nhiệm vụ của bạn là kiểm tra xem số K có xuất hiện trong dãy số hay không. 
//Nếu có hãy in ra vị trí trong dãy A[], nếu không in ra “NO”.
//Input
//2
//5 3
//1 2 3 4 5
//6 5
//0 1 2 3 9 10
//Output
//3
//NO
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    int t; cin >> t; 
	while(t--){ 
	    int n, k; cin >> n >> k;
	    int a[n+1];
	    for(int i=1;i<=n;i++) cin >> a[i];
	    int cnt=0;
	    int l=1, r=n, x;
	    while(l<=r){
	    	int m=(l+r)/2;
	    	if(a[m]==k){
	    		x=m;
	    		++cnt;
	    		break;
			}
			else if(a[m]<k){
				l=m+1;
			}
			else if(a[m]>k){
				r=m-1;
			}
		}
		if(cnt==0) cout << "NO" << endl;
		else cout << x << endl;
	}
}