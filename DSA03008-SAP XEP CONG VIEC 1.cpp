//Cho hệ gồm N hành động. 
//Mỗi hành động được biểu diễn như một bộ đôi <Si, Fi> tương ứng với thời gian bắt đầu và thời gian kết thúc của mỗi hành động. 
//Hãy tìm phương án thực hiện nhiều nhất các hành động được thực hiện bởi một máy hoặc một người sao cho hệ không xảy ra mâu thuẫn.
//Input
//1
//6
//1 3 0 5 8 5
//2 4 6 7 9 9
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
		}
		for(int i=0;i<n;i++){
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