//Trên trục Ox tính từ vị trí 0, người ta muốn xếp nhiều nhất các đoạn thẳng sao cho không đoạn nào chồng lấn lên nhau. 
//Đoạn thẳng thứ i có vị trí bắt đầu là X1[i] và kết thúc tại X2[i], với X1[i] <= X2[i].
//Hãy tính số đoạn thẳng nhiều nhất có thể được lựa chọn để đưa lên trục Ox và không có đoạn nào chồng lấn lên nhau.
//Input
//1
//10
//39 55
//37 74
//0 1
//19 25
//65 76
//51 52
//19 21
//5 94
//46 65
//32 40
//Output
//5
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