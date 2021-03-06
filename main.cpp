#include <iostream>
#include "BST.h"
#include <string>

using namespace std;

int main(){
	BST obj;
	
	cout << "[Label A]: Size of object = " << obj.size() << " and it's height = " << obj.height() << endl;
	int key[] = { 100, 50, 500, 60, 30 };
	string name[] = { "Alice", "Betsy", "Cathy", "Daniel", "Ella" };

	for (int i = 0; i < 5; i++) {
		Employee emp(key[i], name[i]);
		obj.insert(emp);
	}

	cout << "[Label B]: Size of object = " << obj.size() << " and it's height = " << obj.height() << endl;

	cout << "[Label C]:" << endl;
	vector<Employee> vec = obj.inOrder();
	
	for (unsigned i = 0; i < vec.size(); i++) {
		cout << "ID = " << vec[i].id << " Name = " << vec[i].name << endl;
	}
	obj.Delete(60);
	obj.Delete(50);
	
	cout << "[Label D]: Size of object = " << obj.size() << " and it's height = " << obj.height() << endl;
	cout << "[Label E]:" << endl;

	vector<Employee> nvec = obj.inOrder();
	for (unsigned i = 0; i < nvec.size(); i++)
		cout << "ID = " << nvec[i].id << " Name = " << nvec[i].name << endl;
	
	int key2[] = { 10, 40, 400, 300, 450, 350 };
	string name2[] = { "Andy", "Bill", "Carmine", "Doug", "Ernie", "Frodo" };

	for (int i = 0; i < 6; i++) {
		Employee emp(key2[i], name2[i]);
		obj.insert(emp);
	}
	
	cout << "[Label F]: Size of object = " << obj.size() << " and it's height = " << obj.height() << endl;
	cout << "[Label G]:" << endl;

	nvec = obj.inOrder();
	for (unsigned i = 0; i < nvec.size(); i++) {
		cout << "ID = " << nvec[i].id << " Name = " << nvec[i].name << endl;
	}

	obj.Delete(100);

	cout << "[Label H]: Size of object = " << obj.size() << " and it's height = " << obj.height() << endl;
	cout << "[Label I]:" << endl;

	nvec = obj.inOrder();
	for (unsigned i = 0; i < nvec.size(); i++) {
		cout << "ID = " << nvec[i].id << " Name = " << nvec[i].name << endl;
	}

	int arr[] = { 400, 10, 450, 999 };
	for (int i = 0; i < 4; i++) {
		cout << "[Label " << (char)('J' + i) << "]:";
		Employee emp = obj.find(arr[i]);
		if (emp.id == 0)
			cout << "Not Found" << endl;
		else 
			cout << "(" << emp.id << "," << emp.name << ")" << endl;
	}
	return 0;
}
