//Hãy viết chương trình chuyển đổi một xâu mã Gray X có độ dài n thành một xâu mã nhị phân.
//Input::
//Dòng đầu tiên là số lượng test T.
//T dòng kế tiếp ghi lại mỗi dòng một test. Mỗi test là một xâu mã Gray độ dài n.
//T, n thỏa mãn ràng buộc: 1≤T, n≤10.
//Output:
//Đưa ra kết quả mỗi test theo từng dòng.
//Input
//2
//01101
//01011
//Output
//01001
//01101
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
    	string s; cin >> s;
		string a="";
		a+=s[0];
		for(int i=1;i<s.size();i++){
            if(s[i]!=a.back()) a+="1";
            else a+="0";
        }
		cout << a << endl;	
	}	
}