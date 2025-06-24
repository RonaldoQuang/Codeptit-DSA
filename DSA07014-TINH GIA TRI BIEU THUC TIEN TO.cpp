//Hãy viết chương trình tính toán giá trị của biểu thức tiền tố.
//Input
//2
//-+8/632
//-+7*45+20
//Output
//8
//25
#include <bits/stdc++.h>
using namespace std;
int tinh(int a, int b, char c){
	if(c=='+') return a+b;
	if(c=='-') return a-b;
	if(c=='*') return a*b;
	if(c=='/') return a/b;
}
int main(){ 
    int t; cin >> t;
    while(t--){
    	string s; cin >> s;
    	stack<int> st;
    	for(int i=s.size()-1;i>=0;i--){
    		if(s[i]>='0'&&s[i]<='9') st.push(s[i]-'0');
    		else{
    			int a=st.top(); st.pop();
    			int b=st.top(); st.pop();
    			st.push(tinh(a,b,s[i]));
			}
		}
		cout << st.top() << endl;
	}
}