//Cho dãy số gồm N số là phép duyệt theo thứ tự trước (Preorder) của một cây nhị phân tìm kiếm. 
//Hãy đưa ra số các node trung gian của cây ?
//Ví dụ với dãy A[] = {30, 20, 15, 25, 23, 28, 40, 35, 33, 38, 45} là phép duyệt cây theo thứ tự trước sẽ cho ta kết quả là 5 bao gồm các node: 30, 20, 25, 40, 35.
//Input
//2
//6
//10 5 1 7 40 50
//11
//30 20 15 25 23 28 40 35 33 38 45
//Output
//3
//5
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
	Node(int x){
		this->data=x;
		this->left=NULL;
		this->right=NULL;
	}
};
typedef struct Node* node;
void Insert(node &a, int x){
	if(a==NULL) a=new Node(x);
	else{
		if(x<a->data) Insert(a->left,x);
		else Insert(a->right,x);
	}
}
void in(node a, int &cnt){
	if(a==NULL) return;
	if(!(a->left==NULL&&a->right==NULL)) ++cnt;
	in(a->left,cnt);
	in(a->right,cnt);
}
int main(){
	int t; cin >> t;
	while(t--){
		int n, cnt=0; cin >> n;
		node a=NULL;
		while(n--){
			int x; cin >> x;
			Insert(a,x);
		}
		in(a,cnt);
		cout << cnt << endl;
	}
}