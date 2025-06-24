//Cho hai cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có giống nhau hay không?
//Input
//2
//2
//1 2 L 1 3 R
//2
//1 2 L 1 3 R
//2
//1 2 L 1 3 R
//2
//1 3 L 1 2 R
//Output
//1
//0
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
void makeNode(node a, int x, int y, char z){
    if(z=='L'){
    	a->left=new Node(y);
	}	
	else a->right=new Node(y);
}
void Insert(node &a, int x, int y, char z){
	if(a==NULL) return;
	if(a->data==x) makeNode(a,x,y,z);
	else{
		Insert(a->left,x,y,z);
		Insert(a->right,x,y,z);
	}
}
string in(node a){
	string s="";
	queue<node> q;
	q.push(a);
	while(!q.empty()){
		node x=q.front(); q.pop();
		s+=to_string(x->data)+" ";
		if(x->left!=NULL) q.push(x->left);
		if(x->right!=NULL) q.push(x->right);
	}
	return s;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		node a=NULL;
		node b=NULL;
		while(n--){
			int x, y; char z;
			cin >> x >> y >> z;
			if(a==NULL){
				a=new Node(x);
			}
			Insert(a,x,y,z);
		}
		int k; cin >> k;
		while(k--){
			int i, j; char l;
			cin >> i >> j >> l;
			if(b==NULL){
				b=new Node(i);
			}
			Insert(b,i,j,l);
		}
		if(in(a)==in(b)) cout << "1" << endl;
		else cout << "0" << endl;
	}
}