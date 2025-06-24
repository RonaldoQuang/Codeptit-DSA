//Cho 5 số nguyên dương A, B, C, D, E. 
//Bạn có thể hoán vị các phần tử cho nhau, hãy đặt các dấu biểu thức +, -, * sao cho biểu thức sau đúng:
//[[[A o(1) B] o(2) C] o(3) D] o(4) E = 23
//Trong đó: o(1) … o(4) là các phép toán +, -, *.
//Input:
//Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
//Mỗi test gồm 5 số nguyên dương A, B, C, D, E có giá trị không vượt quá 100.
//Output: Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.
//Input
//3
//1 1 1 1 1
//1 2 3 4 5
//2 3 5 7 11
//Output
//NO
//YES
//YES
#include <bits/stdc++.h>
using namespace std;
vector<string> v, v1;
int a[6]={}, b[6]={};
char c[3]={'+','-','*'}, d[5];
void kq(){
	string s="";
	for(int i=1;i<=5;i++){
		s+=a[i]+'0';
	}
	v.push_back(s);
}
void kq_1(){
	string s="";
	for(int i=1;i<=4;i++){
		s+=d[i];
	}
	v1.push_back(s);
}
void Try(int i){
	for(int j=1;j<=5;j++){
		if(b[j]==0){
			a[i]=j;
			b[j]=1;
			if(i==5) kq();
			else Try(i+1);
			b[j]=0;
		}
	}
}
void Try_1(int i){
	for(int j=0;j<3;j++){
		d[i]=c[j];
		if(i==4) kq_1();
		else Try_1(i+1);
	}
}
int tinh(int x, int y, char z){
	if(z=='+') return x+y;
	if(z=='-') return x-y;
	if(z=='*') return x*y;
}
int result(int arr[6], string s, string w){
	int a=tinh(arr[s[0]-'0'],arr[s[1]-'0'],w[0]);
	int b=tinh(a,arr[s[2]-'0'],w[1]);
	int c=tinh(b,arr[s[3]-'0'],w[2]);
	int d=tinh(c,arr[s[4]-'0'],w[3]);
	return d;
}
int main(){
	Try(1);
	Try_1(1);
	int t; cin >> t;
	while(t--){
		int arr[6], ok=0;
		for(int i=1;i<=5;i++) cin >> arr[i];
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v1.size();j++){
				if(result(arr,v[i],v1[j])==23){
					ok=1;
					break;
				}
			}
			if(ok==1) break;
		}
		if(ok==1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}