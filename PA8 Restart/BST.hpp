#include "TransactionNode.hpp"

class BST {
public:
	BST();
	~BST();
	//setters & getters
	Node* getRoot();

	void insert(TransactionNode newNode);
	void inOrderTraversal();
private:
	void inOrderTraversal(Node* pTree);
	void insert(TransactionNode newNode, Node*& pTree);
	void destroyTree(Node* pTree);

	Node* mpRoot;
};
