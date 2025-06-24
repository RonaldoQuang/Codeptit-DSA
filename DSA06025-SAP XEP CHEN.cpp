//Hãy thực hiện thuật toán sắp xếp chèn trên dãy N số nguyên. 
//Ghi ra các bước thực hiện thuật toán.
//Input
//4
//5 7 3 2
//Output
//Buoc 0: 5
//Buoc 1: 5 7
//Buoc 2: 3 5 7
//Buoc 3: 2 3 5 7
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a[100];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
    	cout << "Buoc " << i << ": ";
    	sort(a,a+i+1);
    	for(int j=0;j<=i;j++){
    		cout << a[j] << " ";
		}
		cout << endl;
	}
}