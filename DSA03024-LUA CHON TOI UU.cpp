//Bạn được giao cho N công việc, công việc thứ i có thời gian bắt đầu là A[i] và kết thúc tại B[i]. 
//Tại một thời điểm, bạn chỉ có thể làm một công việc.
//Bạn hãy lựa chọn các công việc một cách tối ưu sao cho số công việc làm được là nhiều nhất.
//Input
//1
//6
//5 9
//1 2
//3 4
//0 3
//5 7
//8 9
//Output
//4
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
    	int a[n], b[n];
    	multimap<int,int> mp;
    	for(int i=0;i<n;i++){
    		cin >> a[i];
    		cin >> b[i];
    		mp.insert({b[i],a[i]});
		}
		int cnt=0, t=0;
		for(auto x:mp){
			if(x.second>=t){
				++cnt;
				t=x.first;
			}
		}
		cout << cnt << endl;
	}
}