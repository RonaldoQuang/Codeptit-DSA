//Nam có N thẻ bài, mỗi thẻ ghi một con số từ 1 tới N. 
//Không có 2 thẻ nào ghi hai số trùng nhau. 
//Nam muốn xếp thứ tự các thẻ bài sao cho không có hai con số nào liền kề nhau ở cạnh nhau.
//Ví dụ với N = 4 thì cách xếp 3142 là hợp lệ nhưng cách xếp 1324 không hợp lệ.
//Hãy giúp Nam liệt kê tất cả các cách xếp thỏa mãn theo thứ tự từ điển.  
//Intput
//1
//4
//Output
//2413
//3142
#include <bits/stdc++.h>
using namespace std;
int check(int a[100], int n){
	int cnt=0;
	for(int i=1;i<=n-1;i++){
		if(abs(a[i]-a[i+1])==1){
			++cnt;
			break;
		}
	}
	if(cnt==0) return 1;
	else return 0;
}
void kq(int a[100], int n){
	for(int i=1;i<=n;i++){
		cout << a[i];
	}
	cout << endl;
}
void Try(int a[100], int b[100], int i, int n){
	for(int j=1;j<=n;j++){
		if(b[j]==1){
			a[i]=j;
			b[j]=0;
			if(i==n){
				if(check(a,n)) kq(a,n);
			}
			else Try(a,b,i+1,n);
			b[j]=1;
		}
	}
}
int main(){
    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
    	int a[100], b[100];
    	for(int i=1;i<=n;i++) b[i]=1;
    	Try(a,b,1,n);
	}
}