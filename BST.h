#ifndef BST_H
#define BST_H

#include <string>
#include <vector>
using namespace std;

struct Employee {
	int id;
	string name;
	Employee(int empId = 0, string empName = "") : id(empId), name(empName) {};
	void insert(int ID, string  NAME) {
		id = ID;
		name = NAME;
	}
};

typedef Employee ItemType;

struct BSTNode {
	ItemType item;
	BSTNode * left;
	BSTNode * right;
	BSTNode() {
		left = nullptr;
		right = nullptr;
	}
	BSTNode(ItemType i) : BSTNode() {
		item = i;
	}
};
class BST {
private:
	BSTNode * BSTroot;
	int sizeOfBST;
	void in_order_transversal(BSTNode * root, vector<Employee>& vec);
	int max(int, int);
	int height(BSTNode *);
	BSTNode * getNodeWith(int id, bool& leftChild, BSTNode *& parent);
	BSTNode * getNodeWith(int id, bool& leftChild);
	BSTNode * getNodeWith(int id);
	void swap(BSTNode *, BSTNode *);
	BSTNode* get_Right_Most_Or_Left_Most_Node(bool left, BSTNode *, BSTNode * &);

public:
	BST();
	Employee find(int id);
	void insert(Employee emp);
	void Delete(int key);
	int size();
	int height();
	vector<Employee> inOrder();

};
#endif