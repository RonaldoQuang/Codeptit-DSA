//Cho biểu thức số học, hãy cho biết biểu thức số học có dư thừa các cặp ký hiệu ‘(’,’) ‘ hay không?
//Input
//3
//((a+b))
//(a + (b)/c)
//(a + b*(c-d))
//Output
//Yes
//Yes
//No
#include <bits/stdc++.h>
using namespace std;
string check(string s){
	stack<char> st;
	for(auto c:s) {
		if(c==')'){
			bool ok=true;
			while(st.top()!='('){
				char x=st.top();
				if(x=='+'||x=='-'||x=='*'||x=='/') ok=false;
				st.pop();
			}
			if(ok) return "Yes";
			st.pop();
		}
		else st.push(c);
	}
	return "No";
}
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		cout << check(s) << endl;
	}
}