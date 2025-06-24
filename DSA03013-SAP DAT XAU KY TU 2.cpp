//Cho xâu ký tự S bao gồm các ký tự và số D. 
//Nhiệm vụ của bạn là kiểm tra xem ta có thể sắp đặt lại các ký tự trong S để tất cả các ký tự giống nhau đều có khoảng cách là D hay không? 
//Đưa ra 1 nếu có thể sắp đặt lại các ký tự trong S thỏa mãn yêu cầu bài toán, ngược lại đưa ra -1.
//Input
//2
//2
//ABB
//2
//AAA
//Output
//1
//-1
#include<bits/stdc++.h> 
using namespace std; 
int main(){ 
    int t ; cin >> t; 
	while(t--){ 
	    int D; cin >> D ; 
		string s; cin >> s; 
		map<char,int> mp ; 
		for(char c:s){ 
		    mp[c]++; 
		} 
		int k=0; 
		for(auto x:mp) { 
		    k=max(k,x.second); 
		} 
		int n=s.size(); 
		if(k-(n-k)/(D-1)<=1) cout << "1";
		else cout <<"-1";
		cout << endl; 
	} 
}