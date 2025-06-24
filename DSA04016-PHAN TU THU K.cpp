//Cho hai mảng đã được sắp xếp A[], B[] gồm M, N phần tử theo thứ tự và số K. 
//Nhiệm vụ của bạn là tìm phần tử ở vị trí số K sau khi trộn hai mảng để nhận được một mảng được sắp xếp.
#include<bits/stdc++.h> 
using namespace std; 
int main(){ 
    int t; cin >> t; 
	while(t--){ 
	    int n, m, k, x; cin >> n >> m >> k;
        vector<int> v;
        for (int i=0;i<n+m;i++){
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        cout << v[k-1] << endl;
	} 
}