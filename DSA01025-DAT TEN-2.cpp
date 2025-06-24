//Vương quốc PTIT sử dụng bảng chữ cái gồm N chữ cái Latinh viết hoa. 
//Quy tắc đặt tên của gia đình Hoàng gia  PTIT là chọn ra K chữ cái (không trùng nhau) và sắp xếp lại theo thứ tự từ điển.
//Hãy liệt kê tất cả các cái tên có thể có của gia đình Hoàng gia PTIT
//Input
//Dòng đầu ghi số bộ test T (không quá 10)
//Mỗi bộ test ghi 2 số N và K (3 < K < N < 16)
//Output
//Với mỗi bộ test, ghi ra tất cả các cái tên có thể được tạo ra, mỗi kết quả viết trên một dòng.
//Input
//1
//4 2
//Output
//AB
//AC
//AD
//BC
//BD
//CD
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
        int n,k; cin >> n >> k;
        int a[100];
        int x=1;
        kt(a,k);
        for(int i=1;i<=k;i++){
            cout << (char) (a[i]+64);
        }
        cout << endl;
        int i=k;
        while(i>=1){
            if(a[i]<n-(k-i)){
        	    a[i]+=1;
                for(int j=i+1;j<=k;j++){
                    a[j]=a[j-1]+1;
                }
                for(int j=1;j<=k;j++){
                	cout << (char) (a[j]+64);
				}
				cout << endl;
				i=k;
            }
            else{
                --i;
            }
        }
    }
}