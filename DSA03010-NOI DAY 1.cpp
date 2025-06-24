//Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. 
//Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng chi phí nối dây là nhỏ nhất. 
//Biết chi phí nối sợi dây thứ i và sợi dây thứ j là tổng độ dài hai sợi dây A[i] và A[j].
//Input
//2
//4
//4 3 2 6
//5
//4 2 7 6 9
//Output
//29
//62
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
    	int a[n];
    	multimap<int,int> mp;
    	for(int i=0;i<n;i++){
    		cin >> a[i];
			mp.insert({a[i],1});
		}
		long long sum=0, tien=0; 
		int cnt=0, dem=0;
		for(auto x:mp){
			int p, q;
			++cnt;
			if(cnt%2==1) p=x.first;
			else{
				q=x.first;
				++dem;
				sum+=p+q;
				tien+=sum;
				mp.insert({sum,1});
				sum=0;
			}
			if(dem==n-1) break;
		}
		cout << tien << endl;
	}
}