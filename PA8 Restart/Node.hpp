#include <string>
#include<iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Node {
public:
	Node(std::string newData);
	virtual ~Node();

	virtual void setData(std::string newData);
	virtual void setLeft(Node* newNode);
	virtual void setRight(Node* newNode);

	std::string getData();
	Node*& getLeft();
	Node*& getRight();

	virtual void printData() = 0;
protected:
	std::string mData;
	Node* mpLeft;
	Node* mpRight;
};