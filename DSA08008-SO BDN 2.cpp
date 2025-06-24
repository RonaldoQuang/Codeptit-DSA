//Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong K chỉ bao gồm các 0 hoặc 1 có nghĩa. 
//Ví dụ số K =  101 là số BDN, k=102 không phải là số BDN.
//Số BDN của N là số P =M*N sao cho P là số BDN. 
//Cho số tự nhiên N (N<1000), hãy tìm số BDN nhỏ nhất của N.
//Input
//3
//2
//12
//17
//Output
//10
//11100
//11101
#include <bits/stdc++.h>
using namespace std;
long long kq(string s, long long m){
	long long sum=0;
	for(int i=0;i<s.size();i++){
		sum=sum*10+s[i]-'0';
		sum%=m;
	}
	return sum;
}
int main(){
	int t; cin >> t;
	while(t--){
		long long n; cin >> n;
		queue<string> q;
		string s="1";
		q.push(s);
		string z;
		while(1){
			s=q.front();
			if(kq(q.front(),n)==0){
				z=q.front();
				break;
			}
			q.push(s+"0");
			q.push(s+"1");
			q.pop();
		}
		cout << z << endl;
	}
}