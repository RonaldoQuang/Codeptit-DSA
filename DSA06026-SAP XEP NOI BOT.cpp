//Hãy thực hiện thuật toán sắp xếp nổi bọt trên dãy N số nguyên. 
//Ghi ra các bước thực hiện thuật toán.
//Input
//4
//5 7 3 2
//Output
//Buoc 1: 3 2 5 7
//Buoc 2: 2 3 5 7
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
int main(){
    int n; cin >> n;
    int a[100];
    for(int i=0;i<n;i++) cin >> a[i];
    int x=dem(a,n), cnt=1;
    while(x==0){
    	for(int i=0;i<n-1;i++){
    		if(a[i]>a[i+1]) swap(a[i],a[i+1]);
		}
		cout << "Buoc " << cnt << ": ";
		for(int i=0;i<n;i++) cout << a[i] << " ";
		cout << endl;
		++cnt;
		x=dem(a,n);
	}
}