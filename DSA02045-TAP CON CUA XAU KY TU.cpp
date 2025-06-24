//Cho một xâu ký tự S không có ký tự lặp lại. 
//Hãy đưa ra tất cả các tập con của xâu ký tự S theo thứ tự từ điển.
//Input:
//Dòng đầu tiên đưa vào số lượng test T.
//Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự.
//T, S thỏa mãn ràng buộc: 1≤T≤100; 1≤length(S)≤16.
//Output:
//Đưa ra kết quả mỗi test theo từng dòng.
//Input
//1
//3
//abc
//Output
//a ab abc ac b bc c
#include <bits/stdc++.h>
using namespace std;
void Try(map<char,int> mp, string a, string s, string x, int i){
	for(int j=0;j<a.size();j++){
		if(mp[a[j]]>mp[a[i]]){
		    x+=a[j];
		    cout << x << " ";
		    Try(mp,a,s,x,j);
		    x.pop_back();
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		map<char,int> mp;
		string a="";
		int b[17];
		for(int i=0;i<s.size();i++){
			mp[s[i]]=i;
			b[i]=s[i];
		}
		sort(b,b+s.size());
		for(int i=0;i<s.size();i++) a+=b[i];
		for(int i=0;i<a.size();i++){
			string x="";
			x+=a[i];
			cout << x << " ";
			Try(mp,a,s,x,i);
		}
		cout << endl;
	}
}