#include <bits/stdc++.h>
using namespace std;
class Node 
{ 
	public: 
	int data; 
	Node* left; 
	Node* right; 
}; 
Node* newNode(int data) 
{ 
	Node* node = new Node(); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return(node); 
} 
int height(Node* root){
  if(root==NULL) return 0;
  return max(height(root->left), height(root->left));
}
void store(Node* root, vector<int> ans){
  if(root!=NULL){
   store(root->left, ans);
    ans.push_back(root->data);
    store(root->right, ans);
  }
}
Node* makebst(vector<int>& newarray, int start, int end){
 if(start>end) {
   return NULL;
 }
  int mid = start+(end - start)/2;
   Node* root = newNode(newarray[mid]);
   root->left = makebst(newarray, start, mid-1);
   root->right = makebst(newarray, mid+1, end);
  return root;
}
Node* mergebsts(Node* root1, Node* root2){
 if(root1==NULL && root2==NULL)
   return NULL;
  if(root1==NULL) return root2;
    if(root2==NULL) return root1;
  int n=height(root1), m=height(root2);
  vector<int> a(n), b(m), newarray(n+m);
    store(root1, a);
  store(root2, b);
  merge(a, b, n, m, newarray);
  return makebst(newarray, 0, m+n-1);
}
void merge(vector<int> a, vector<int> b, int n, int m, vector<int>& newarray){
   int i=0, j=0, k=0;
  while(i<n && j<m){
    if(a[i]<=b[j]){
       newarray[k++]=a[i++];
    }
    else 
       newarray[k++]=b[j++];
  }
  while(i<n){
     newarray[k++]=a[i++];
  }
   while(j<m){
     newarray[k++]=b[j++];
  }
}

void printInorder(Node* node) 
{ 
	if (node == NULL) 
		return; 
	printInorder(node->left); 

	cout << node->data << " "; 
	printInorder(node->right); 
} 
int main() {
    Node *root1 = newNode(100); 
	root1->left	 = newNode(50); 
	root1->right = newNode(300); 
	root1->left->left = newNode(20); 
	root1->left->right = newNode(70); 

	Node *root2 = newNode(80); 
	root2->left	 = newNode(40); 
	root2->right = newNode(120); 

	Node *mergedTree = mergebsts(root1, root2); 

	cout << "Following is Inorder traversal of the merged tree \n"; 
	printInorder(mergedTree); 

	return 0; 
}
