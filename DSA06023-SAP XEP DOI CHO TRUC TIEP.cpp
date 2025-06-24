//Hãy thực hiện thuật toán sắp xếp đổi chỗ trực tiếp trên dãy N số nguyên. 
//Ghi ra các bước thực hiện thuật toán.
//Input
//4
//5 7 3 2
//Output
//Buoc 1: 2 7 5 3
//Buoc 2: 2 3 7 5
//Buoc 3: 2 3 5 7
#include <bits/stdc++.h>
using namespace std;
int dem(int a[100], int n){
	int cnt=0;
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			++cnt;
			break;
		}
	}
	if(cnt==0) return 1;
	else return 0;
}
int main() {
    int t=1;
    while(t--){
    	int n; cin >> n;
    	int a[100];
    	for(int i=0;i<n;i++) cin >> a[i];
    	for(int i=0;i<n-1;i++){
    		for(int j=i+1;j<n;j++){
    			if(a[i]>a[j]){
    				int temp=a[i];
    				a[i]=a[j];
    				a[j]=temp;
				}
			}
			if(dem(a,n)==1){
				cout << "Buoc " << i+1 << ": ";
				for(int j=0;j<n;j++){
					cout << a[j] << " ";
				}
				cout << endl;
				break;
			}
			else{
				cout << "Buoc " << i+1 << ": ";
				for(int j=0;j<n;j++){
					cout << a[j] << " ";
				}
				cout << endl;
			}
		}
	}
}