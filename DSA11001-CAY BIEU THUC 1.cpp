//Cây biểu thức là một cây nhị phân trong đó mỗi node trung gian là một phép toán, mỗi node lá là một toán hạng.
//Đối với cây biểu thức, duyệt theo thứ tự trước ta sẽ được biểu thức tiền tố, duyệt theo thứ tự sau ta sẽ được biểu thức hậu tố, duyệt theo thứ tự giữa ta được biểu thức trung tố. 
//Chú ý, cây biểu thức luôn là cây nhị phân đầy (mỗi node trung gian đều có hai node con).
//Cho biểu thức hậu tố P, hãy sử dụng cây biểu thức để đưa ra biểu thức trung tố tương ứng với biểu thức P.
//Input
//2
//ab+ef*g*-
//wlrb+-*
//Output
//a+b-e*f*g
//w*l-r+b
#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int t; cin >> t;
    while(t--){
    	string s; cin >> s;
    	stack<string> st;
    	for(int i=0;i<s.size();i++){
    		if(s[i]>='a'&&s[i]<='z') st.push(string(1,s[i]));
    		else{
    			string b=st.top(); st.pop();
    			string a=st.top(); st.pop();
    			st.push(a+s[i]+b);
			}
		}
		cout << st.top() << endl;
	}
}