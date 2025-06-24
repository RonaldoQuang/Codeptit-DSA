//Cho biểu thức P chỉ bao gồm các ký tự mở ngoặc ‘(’ hoặc đóng ngoặc ‘)’. 
//Biểu thức P có thể viết đúng hoặc không đúng. 
//Nhiệm vụ của bạn là tìm tổng độ dài lớn nhất của các biểu thức con viết đúng trong P (các biểu thức đúng không nhất thiết phải liên tiếp nhau).
//Chú ý: Độ dài của biểu thức đúng ngắn nhất là 2.
//Input
//4
//(()(
//()()((
//((()()())))
//()(())(
//Output
//2
//4
//10
//6
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int cnt=0;
		while(1){
			int x=s.find("()");
			if(x==-1) break;
			else{
				cnt+=2;
				s.erase(x,2);
			}
		}
		cout << cnt << endl;
	}
}