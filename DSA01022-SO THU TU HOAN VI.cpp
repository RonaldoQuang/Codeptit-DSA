//Cho một hoán vị của N số nguyên dương đầu tiên.
//Hãy xác định xem đó là hoán vị thứ bao nhiêu nếu liệt kê theo thứ tự tăng dần (tính từ 1).
//Input
//Dòng đầu ghi số T là số bộ test (T < 10)
//Mỗi bộ test gồm 2 dòng
//Dòng đầu ghi số nguyên dương N (3 < N < 10)
//Dòng tiếp theo ghi một hoán vị của các số nguyên dương từ 1 đến N.  
//Output
//Với mỗi bộ test, ghi ra trên một dòng số thứ tự của hoán vị (tính từ 1, theo thứ tự liệt kê tăng dần).
//Ví dụ
//Input
//2
//4
//1 4 3 2
//4
//1 2 3 4
//Output
//6
//1
#include <bits/stdc++.h>
using namespace std;
void kt(int a[100], int n){
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int n, stt=1; cin >> n;
        string s1="", s2="";
        int b[n+1];
        for(int i=1;i<=n;i++){
        	cin >> b[i];
        	s2+=b[i]+'0';
		}
        int a[100];
        kt(a,n);
        for(int i=1;i<=n;i++){
        	s1+=a[i]+'0';
		}
		if(s1==s2){
			cout << 1;
		}
		else{
			stt=2;
			int x=1;
		    while(x){
			    int m,z,cnt=0,min=100;
			    s1="";
			    for(int i=n-1;i>=1;i--){
				    if(a[i]<a[i+1]){
					    m=i;
					    ++cnt;
					    break;
				    }
			    }
			    for(int i=m+1;i<=n;i++){
				    if(a[i]>a[m]&&a[i]<min){
					    min=a[i];
					    z=i;
				    }
			    }
			    int temp=a[m];
			    a[m]=a[z];
			    a[z]=temp;
			    sort(a+m+1,a+n+1);
			    if(cnt==1){
				    x=1;
				    for(int i=1;i<=n;i++){
					    s1+=a[i]+'0';
				    }
				    if(s1==s2){
				    	cout << stt;
				    	break;
					}
					else ++stt;
			    }
			    else x=0; 
		    }
		}
		cout << endl;
    }
}