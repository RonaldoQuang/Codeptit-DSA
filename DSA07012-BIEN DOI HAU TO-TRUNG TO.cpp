//Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng hậu tố về dạng trung tố.
//Input
//2
//ABC++
//AB*C+
//Output
//(A+(B+C))
//((A*B)+C)
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		stack<string> st;
		for(int i=0;i<s.size();i++){
			if(s[i]<='Z'&&s[i]>='A') st.push(string(1,s[i]));
			if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
				string b=st.top(); st.pop();
				string a=st.top(); st.pop();
				string w="("+a+s[i]+b+")";
				st.push(w);
			}
		}
		cout << st.top() << endl;
	}
}