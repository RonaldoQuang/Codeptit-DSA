//Cho một dãy N viên bi gồm 3 màu xanh, trắng, đỏ xếp lẫn lộn. 
//Bằng cách đổi chỗ từng cặp viên bi cho nhau có thể xếp lại dãy bi trên sao cho các viên bi xanh đứng trước, sau đó đến các viên bi trắng và cuối cùng là các viên bi đỏ. 
//Tìm số lượng ít nhất các phép đổi chỗ cần thực hiện
//Input
//9
//TTXDDDTDX
//Output
//4
#include <bits/stdc++.h> 
using namespace std;
int main(){ 
    int n; cin >> n;
    string s; cin >> s;
    int x=0, t=0, d=0;
    for(int i=0;i<n;i++){
		if(s[i]=='X') ++x;
		else if(s[i]=='T') ++t;
		else ++d;
	}
	int dem=0;
	for(int i=n-d;i<n;i++) if(s[i]!='D') ++dem;
	for(int i=0;i<x;i++) if(s[i]!='X') ++dem;
	int a=0,b= 0;
	for(int i=n-d;i<n;i++) if(s[i]=='X') ++a;
	for(int i=0;i<x;i++) if(s[i]=='D') ++b;
	cout << dem-min(a,b) << endl;
}