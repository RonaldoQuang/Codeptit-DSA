//Cho một tổ hợp chập K của N số nguyên dương đầu tiên (2 < K < N < 15).
//Hãy xác định xem đó là tổ hợp thứ bao nhiêu nếu liệt kê tất cả các tổ hợp theo thứ tự tăng dần (tính từ 1).
//Input
//Dòng đầu ghi số T là số bộ test (T < 10)
//Mỗi bộ test gồm 2 dòng
//Dòng đầu ghi 2 số nguyên dương N và K (2 < K < N < 15)
//Dòng tiếp theo ghi một tổ hợp chập K của các số nguyên dương từ 1 đến N.  
//Output
//Với mỗi bộ test, ghi ra trên một dòng số thứ tự của tổ hợp (tính từ 1, theo thứ tự liệt kê tăng dần).
//Input
//2
//6 4
//1 3 5 6
//6 4
//2 3 4 6
//Output
//9
//12
#include <bits/stdc++.h>
using namespace std;
void kt(int a[100], int k){
    for(int i=1;i<=k;i++){
        a[i]=i;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int n, k, stt=1; cin >> n >> k;
        string s1="", s2="";
        int b[k+1];
        for(int i=1;i<=k;i++){
        	cin >> b[i];
        	s2+=b[i]+'0';
		}
        int a[100];
        kt(a,k);
        for(int i=1;i<=k;i++){
        	s1+=a[i]+'0';
		}
		if(s1==s2){
			cout << 1;
		}
        else{
        	int i=k;
        	stt=2;
            while(i>=1){
            	s1="";
                if(a[i]<n-(k-i)){
        	        a[i]+=1;
                    for(int j=i+1;j<=k;j++){
                        a[j]=a[j-1]+1;
                    }
                    for(int j=1;j<=k;j++){
                	    s1+=a[j]+'0';
				    }
				    if(s1==s2){
				    	cout << stt;
				    	break;
					}
					else ++stt;
				    i=k;
                }
                else{
                    --i;
                }
            }
		}
		cout << endl;
    }
}