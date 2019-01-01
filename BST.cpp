#include "BST.h"
#include <vector>
#include <iostream>

using namespace std;

BST::BST(){
	BSTroot = nullptr;
	sizeOfBST = 0;
}

Employee BST::find(int id) {
	BSTNode * root = getNodeWith(id);			  // We don't need to know that root is a left child or right 
	return (root ? root->item : Employee(0, "")); // If it return nullptr that means employee with that id doesn't exists
												  // So return an employee with id 0
}

BSTNode * BST::getNodeWith(int id) {
	bool leftChild;
	return getNodeWith(id, leftChild);
}// Its job is to return the employee with the given key

BSTNode * BST::getNodeWith(int id, bool & leftChild) {
	BSTNode * parent;
	return getNodeWith(id, leftChild, parent);
}// Its job is to return the node we are looking for and tell if it is a right child or a left child

BSTNode * BST::getNodeWith(int id, bool& leftChild, BSTNode* & parent) {//This func has a problem its parent aint coming out to be right
	BSTNode * root = BSTroot;
	parent = nullptr;
	while (root) {
		int empID = root->item.id;
		if (id == empID) {
			return root;
		}
		parent = root;
		if (id < empID) {
			root = root->left;
			leftChild = true;
		}
		else {
			root = root->right;
			leftChild = false;
		}
	}
	return nullptr;
}// This would return the node that we are looking for and whether it is a leftChild and who it's parent is 

void BST::insert(Employee emp) {

	BSTNode * newEmp = new BSTNode;
	newEmp->item = emp;

	if (sizeOfBST == 0) { // This means there is no binary tree yet
		BSTroot = newEmp;
		sizeOfBST++;
		return;
	}

	BSTNode * root = BSTroot;
	BSTNode * keeper = nullptr;
	bool left = false;
	while (root) {
		keeper = root;
		if (emp.id == root->item.id)
			return;
		else if (emp.id < root->item.id) {
			root = root->left;
			left = true;
		}
		else {
			root = root->right;
			left = false;
			}
		}
		if (left)
			keeper->left = newEmp;
		else
			keeper->right = newEmp;

		sizeOfBST++;
}

BSTNode* BST::get_Right_Most_Or_Left_Most_Node(bool left, BSTNode * root, BSTNode* & parent) {
	parent = root;
	if (left)
		while (root->left) {
			parent = root;
			root = root->left;
		}
	else
		while (root->right) {
			parent = root;
			root = root->right;
		}
	return root;
}// This would return the rightmost or the left most node of the binary tree with the given root with its parent

void BST::swap(BSTNode * node1, BSTNode * node2) {
	Employee temp = node1->item;
	node1->item = node2->item;
	node2->item = temp;
}

int BST::max(int a, int b) {
	return (a > b ? a : b);
}

void BST::Delete(int key) {

	bool root_is_a_left_Child;
	BSTNode * parent;

	BSTNode* root = getNodeWith(key, root_is_a_left_Child, parent);
	
	if (!root)		// This means we don't have any node with that key
		return;
	else if (root == BSTroot){// Check if XOR there is nothing to the left or nothing to the right
		// this is wrong
		if (sizeOfBST == 1) {
			delete BSTroot;
			BSTroot = nullptr;
			sizeOfBST--;
			return;
		}
		else if (BSTroot->left) {// To check if we have something on the left
			BSTNode * rightMostNodeParent;
			BSTNode * rightMostNode_ofLeftTree = get_Right_Most_Or_Left_Most_Node(false, BSTroot->left, rightMostNodeParent);
			if (rightMostNode_ofLeftTree == BSTroot->left) {// This means there is no rightmost Node of the left tree
				rightMostNode_ofLeftTree = BSTroot->right;
				delete BSTroot;
				BSTroot = rightMostNode_ofLeftTree;
				sizeOfBST--;
				return;
			}
			else {
				rightMostNodeParent->right = rightMostNode_ofLeftTree->left;
				swap(BSTroot, rightMostNode_ofLeftTree);
				delete rightMostNode_ofLeftTree;
			  	sizeOfBST--;
				return;
			}
		}
		else {// If we don't have something on the left we have to have something on the right becasue sizeOfBST > 1
			BSTNode * leftMostNodeParent;
			BSTNode * leftMostNode_ofRightTree = get_Right_Most_Or_Left_Most_Node(true, BSTroot->right, leftMostNodeParent);
			if (leftMostNode_ofRightTree == BSTroot->right) {
				// This means right most tree has no leftest Node
				delete BSTroot;
				BSTroot = leftMostNode_ofRightTree;
				sizeOfBST--;
				return;
			}
			else{
				leftMostNodeParent->left = leftMostNode_ofRightTree->right;
				swap(BSTroot, leftMostNode_ofRightTree);
				delete leftMostNode_ofRightTree;
				sizeOfBST--;
				return;
			}
		}
	}

		bool has_left_child = root->left;
		bool has_right_child = root->right;

		if (!has_left_child && !has_right_child) {
			if (root_is_a_left_Child) {
				parent->left = nullptr;
				delete root;
				sizeOfBST--;
				return;
			}
			else {
				parent->right = nullptr;
				delete root;
				sizeOfBST--;
				return;
			}
		}
		else if(!has_left_child){
			if (root_is_a_left_Child) {
				parent->left = root->right;
				delete root;
				sizeOfBST--;
				return;
			}
			else {
				parent->right = root->left;
				delete root;
				sizeOfBST--;
				return;
			}
		}
		else if (!has_right_child) {
			if (root_is_a_left_Child) {
				parent->left = root->left;
				delete root;
				sizeOfBST--;
				return;
			}
			else {
				parent->right = root->right;
				delete root;
				sizeOfBST--;
				return;
			}
		}
		else {
			if (root_is_a_left_Child) {
				BSTNode * rightMostNodeParent;
				BSTNode * rightMostNode_ofLeftTree = get_Right_Most_Or_Left_Most_Node(false, root->left, rightMostNodeParent);
				if (rightMostNode_ofLeftTree == root->left) {// This means there is no rightmost Node of the left tree
					rightMostNode_ofLeftTree = root->right;
					delete root;
					root = rightMostNode_ofLeftTree;
					sizeOfBST--;
					return;
				}
				else {
					rightMostNodeParent->right = rightMostNode_ofLeftTree->left;
					swap(root, rightMostNode_ofLeftTree);
					delete rightMostNode_ofLeftTree;
					sizeOfBST--;
					return;
				}
			}
			else {
				BSTNode * leftMostNodeParent;
				BSTNode * leftMostNode_ofRightTree = get_Right_Most_Or_Left_Most_Node(true, root->right, leftMostNodeParent);
				if (leftMostNode_ofRightTree == root->right) {
					// This means right most tree has no leftest Node
					delete root;
					root = leftMostNode_ofRightTree;
					sizeOfBST--;
					return;
				}
				else {

					leftMostNodeParent->left = leftMostNode_ofRightTree->right;
					swap(root, leftMostNode_ofRightTree);
					delete leftMostNode_ofRightTree;
					sizeOfBST--;
					return;
				}
			}
		}
	


	
}
int BST::size() {
	return sizeOfBST;
}
int BST::height() {
	return height(BSTroot);
}
int BST::height(BSTNode * root){
	if (root == nullptr) 
		return 0;
	else 
		return (1 + max(height(root->left), height(root->right)));
}
void BST::in_order_transversal(BSTNode * root, vector<Employee>& vec) {
	if (!root) 
		return;
	in_order_transversal(root->left, vec);
	vec.push_back(root->item);
	in_order_transversal(root->right, vec);
}
vector<Employee> BST::inOrder() {
	vector<Employee> vec;
	in_order_transversal(BSTroot, vec);
	return vec;
}