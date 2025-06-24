//Cho xâu ký tự S[] bao gồm các ký tự in hoa [A, B, …,Z]. 
//Ta định nghĩa giá trị của xâu S[] là tổng bình phương số lần xuất hiện mỗi ký tự trong xâu. 
//Ví dụ với xâu S[] = “AAABBCD” ta có F(S) = 32 + 22 + 12 + 12 = 15. 
//Hãy tìm giá trị nhỏ nhất của xâu S[] sau khi loại bỏ K ký tự trong xâu.
//Input
//2
//0
//ABCC
//1
//ABCC
//Output
//6
//3
#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int t; cin >> t; 
	while(t--){ 
	    int k; cin >> k;
	    string s; cin >> s;
	    map<char,long long> mp;
		for(char x:s) mp[x]++;
		priority_queue<long long> pq;
		for(auto x:mp) pq.push(x.second);
		while(k--){
			long long x=pq.top();
			pq.pop();
			pq.push(x-1);
		}
		long long sum=0;
		while(!pq.empty()){
			sum+=pq.top()*pq.top();
			pq.pop();
		}
		cout << sum << endl;
	} 
}