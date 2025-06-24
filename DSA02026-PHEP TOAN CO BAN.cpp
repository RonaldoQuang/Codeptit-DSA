//Cho một biểu thức trong phạm vi hai chữ số với các phép toán cộng trừ nhân chia. 
//Các toán hạng và kết quả đảm bảo là số nguyên dương có hai chữ số, nếu có phép chia thì phải thỏa mãn tính chia hết.
//Người ta có thể ẩn đi một số chữ số hoặc phép toán bằng cách điền dấu chấm hỏi (?). 
//Nhiệm vụ của bạn là khôi phục các dấu chấm hỏi và in ra phép toán chính xác ban đầu. 
//Nếu không thể có kết quả đúng thì ghi ra WRONG PROBLEM!
//Dữ liệu vào
//Dòng đầu ghi số bộ test T (1 ≤ T ≤ 100).
//T dòng tiếp theo, mỗi dòng là một biểu thức có thể có các dấu ?.
//Nếu có thể có nhiều kết quả đúng thì in ra kết quả đầu tiên theo thứ tự từ điển, tức là số nhỏ nhất có thể tính từ trái sang phải.
//Kết quả
//Với mỗi bộ test, ghi ra biểu thức đúng tìm được. Hoặc WRONG PROBLEM!
//Input
//2
//?0 ? 12 = 28
//40 / ?3 = ??
//Output
//40 - 12 = 28
//WRONG PROBLEM!
#include <bits/stdc++.h>
using namespace std;
int cmp(string a, string s){
	int cnt=0, dem=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='?') ++cnt;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!='?'&&s[i]==a[i]) ++dem;
	}
	if(cnt==s.size()-dem) return 1;
	else return 0;
}
int main(){
	int t; cin >> t;
	cin.ignore();
	while(t--){
		string s; getline(cin,s);
		int a[90];
		int n=10, x=0, ok=0;
		while(n<=99){
			a[x]=n;
			++x;
			++n;
		}
		if(s.substr(3,1)=="*"||s.substr(3,1)=="/"){
			cout << "WRONG PROBLEM!" << endl;
		}
		else{
			for(int i=0;i<90;i++){
				for(int j=0;j<90;j++){
					if(a[i]+a[j]<=99&&a[i]+a[j]>=10){
						int x=a[i], y=a[j];
						string w=to_string(x)+" + "+to_string(y)+" = "+to_string(x+y);
						if(cmp(w,s)){
							cout << w << endl;
							ok=1;
							break;
						}
					}
					if(a[i]-a[j]<=99&&a[i]-a[j]>=10){
						int x=a[i], y=a[j];
						string w=to_string(x)+" - "+to_string(y)+" = "+to_string(x-y);
						if(cmp(w,s)){
							cout << w << endl;
							ok=1;
							break;
						}
					}
				}
				if(ok==1) break;
			}
			if(ok==0) cout << "WRONG PROBLEM!" << endl;
		}
	}
}