//Số Ugly là các số chỉ có ước số là 2, 3, 5. 
//Theo qui ước số 1 cũng là 1 số Ugly. 
//Dưới đây là 11 số Ugly đầu tiên: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15. 
//Cho số tự nhiên N, nhiệm vụ của bạn là tìm số Ugly thứ N.
//Input
//2
//10
//4
//Output
//12
//4
#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int t; cin >> t;
	set<long long> se;
	vector<long long> v;
	se.insert(1); 
	for(auto x:se){
	    se.insert(x*2);
	    se.insert(x*3);
	    se.insert(x*5);
	    if(se.size()>11000) break;
	}
	for(auto x:se) v.push_back(x);
	while(t--){ 
	    int n; cin >> n;
	    cout << v[n-1] << endl;
	} 
}