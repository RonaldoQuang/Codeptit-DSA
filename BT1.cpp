//Viết chương trình nhập vào một chuỗi ký tự S (độ dài không quá 1000). 
//Chương trình thực hiện các thao tác sau:
//Đếm số lần xuất hiện của mỗi ký tự (không phân biệt hoa thường) trong chuỗi.
//In ra các ký tự cùng với số lần xuất hiện, sắp xếp theo thứ tự giảm dần của số lần xuất hiện. 
//Trường hợp bằng nhau, liệt kê theo thứ tự xuất hiện của ký tự trong từ điển.
//Input
//2
//5 3
//2 1 4 5 6
//5 3
//2 1 5 5 6
//Ouput
//1
//0
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<char,int> a, pair<char,int> b){
	return a.second>b.second;
	if(a.second==b.second) return a.first<b.first;
}
int main(){
	string s; cin >> s;
	map<char,int> mp;
	for(char x:s){
		if(x<='z'&&x>='a') mp[x]++;
		else mp[x+32]++;
	}
	vector<pair<char,int>> v;
	for(auto x:mp){
		pair<char,int> p;
		p.first=x.first, p.second=x.second;
		v.push_back(p);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		cout << v[i].first << ": " << v[i].second << endl;
	}
}