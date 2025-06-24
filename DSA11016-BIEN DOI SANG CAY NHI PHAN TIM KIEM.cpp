//Cho cây nhị phân, nhiệm vụ của bạn là dịch chuyển cây nhị phân thành cây nhị phân tìm kiếm. 
//Phép dịch chuyển phải bảo toàn được cấu trúc cây nhị phân ban đầu. 
//Input
//2
//2
//1 2 R 1 3 L
//4
//10 20 L 10 30 R 20 40 L 20 60 R
//Output
//1 2 3
//10 20 30 40 60
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		set<int> se;
		while(n--){
			int x, y; char z;
			cin >> x >> y >> z;
			se.insert(x);
			se.insert(y);
		}
		for(auto x:se) cout << x << " ";
		cout << endl;
	}
}