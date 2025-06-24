//Cho N cặp số, trong đó số thứ nhất bao giờ cũng nhỏ hơn số thứ 2. 
//Ta nói, cặp số <c, d> được gọi là theo sau cặp số <a,b> nếu b<c. 
//Cho cặp số S và T là các số nguyên tố có 4 chữ số (Ví dụ S = 1033, T = 8197 là các số nguyên tố có 4 chữ số). 
//Hãy viết chương trình tìm cách dịch chuyển S thành T thỏa mãn đồng thời những điều kiện dưới đây:
//Mỗi phép dịch chuyển chỉ được phép thay đổi một chữ số của số ở bước trước đó (ví dụ nếu S=1033 thì phép dịch chuyển S thành 1733 là hợp lệ);
//Số nhận được cũng là một số nguyên tố có 4 chữ số (ví dụ nếu S=1033 thì phép dịch chuyển S thành 1833 là không hợp lệ, và S dịch chuyển thành 1733 là hợp lệ);
//Số các bước dịch chuyển là ít nhất.
//Ví dụ số các phép dịch chuyển ít nhất để S = 1033 thành  T = 8179 là 6 bao gồm các phép dịch chuyển như sau:       
//8179<-8779<-3779<-3739<-3733<-1733<-1033.
//Input
//2
//1033 8179
//1033 8779
//Output
//6
//5
#include <bits/stdc++.h>
using namespace std;
int a[100001];
void sang(){
	for(int i=1;i<=100000;i++){
		a[i]=1;
	}
	a[0]=a[1]=0;
	for(int i=2;i<=sqrt(100000);i++){
		if(a[i]){
			for(int j=i*i;j<=100000;j+=i){
				a[j]=0;
			}
		}
	}
}
int main(){
	sang();
	int t; cin >> t;
	char b[10]={'0','1','2','3','4','5','6','7','8','9'};
	while(t--){
		string l, r; cin >> l >> r;
		queue<pair<string,int>> q;
		map<string,int> mp;
		q.push({l,0});
		while(!q.empty()){
			pair<string,int> x=q.front(); q.pop();
			if(x.first==r){
				cout << x.second << endl;
				break;
			}
			for(int i=0;i<x.first.size();i++){
				for(int j=0;j<10;j++){
					string s=x.first;
					if(i==0){
						if(b[j]!=s[i]&&b[j]!='0'){
							s[i]=b[j];
							if(mp[s]==0&&a[stoi(s)]){
								mp[s]=1;
								q.push({s,x.second+1});
							}
						}
					}
					else{
						if(b[j]!=s[i]){
							s[i]=b[j];
							if(mp[s]==0&&a[stoi(s)]){
								mp[s]=1;
								q.push({s,x.second+1});
							}
						}
					}
				}
			}
		}
	}
}