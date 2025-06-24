//Cho mảng A[] gồm N số nguyên. 
//Nhiệm vụ của bạn là sắp xếp lại mảng số với số lượng bước là ít nhất. Tại mỗi bước, bạn chỉ được phép chèn phần tử bất kỳ của mảng vào vị trí bất kỳ trong mảng. 
//Ví dụ A[] = {2, 3, 5, 1, 4, 7, 6 }sẽ cho ta số phép chèn ít nhất là 3 bằng cách lấy số 1 chèn trước số 2, lấy số 4 chèn trước số 5, lấy số 6 chèn trước số 7 ta nhận được mảng được sắp.
//Input
//2
//7
//2 3 5 1 4 7 6
//4
//1 1 2 1
//Output
//3
//1

#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
	    int a[n];
	    for(int i=0;i<n;i++){
		    cin >> a[i];
	    }
	    map<int,int> mp;
	    mp[0]=0;
	    int m=0;
	    for(int i=1;i<n;i++){
		    int max1=-1e9;
		    for(int j=0;j<i;j++){
			    if(a[j]<=a[i]&&mp[j]+1>max1){
				    max1=mp[j]+1;
				    mp[i]=mp[j]+1;
				    m=max(m,max1);
			    }
		    }
	    }
	    cout << n-m-1 << endl;
	}
}