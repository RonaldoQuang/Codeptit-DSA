//Có N người xếp hàng với N cái tên phân biệt. 
//Người ta muốn ưu tiên một người duy nhất và người đó sẽ luôn luôn ở đầu hàng. 
//Hãy liệt kê tất cả các cách xếp hàng thoả mãn theo thứ tự từ điển.
//Input
//4
//DONG TAY NAM BAC
//NAM
//Output
//NAM BAC DONG TAY
//NAM BAC TAY DONG
//NAM DONG BAC TAY
//NAM DONG TAY BAC
//NAM TAY BAC DONG
//NAM TAY DONG BAC
#include <bits/stdc++.h>
using namespace std;
int c[100], d[100], n;
string a[100], b[100], s;
void kq(){
	cout << s << " ";
	for(int i=1;i<=n;i++){
		cout << b[c[i]] << " ";
	}
	cout << endl;
}
void Try(int i){
	for(int j=1;j<=n;j++){
		if(d[j]){
			c[i]=j;
			d[j]=0;
			if(i==n) kq();
			else Try(i+1);
			d[j]=1;
		}
	}
}
int main(){
    cin >> n;
    set<string> se;
    for(int i=1;i<=n;i++){
    	cin >> a[i];
    	d[i]=1;
	}
	cin >> s;
	for(int i=1;i<=n;i++){
    	if(a[i]!=s) se.insert(a[i]);
	}
	int cnt=1;
	for(auto x:se){
		b[cnt]=x;
		++cnt;
	}
	n=se.size();
	sort(b+1,b+cnt);	
	Try(1);
}