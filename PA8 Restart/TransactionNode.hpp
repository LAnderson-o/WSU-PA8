#include "Node.hpp"

class TransactionNode : public Node {
public:
	TransactionNode(int newUnits = 0, std::string newData = "") : Node(newData), mUnits(newUnits) {}
	//~TransactionNode();

	void setData(int newUnits);
	void setData(int newUnits, std::string newData);
	void setData(std::string newData);

	int getUnits();
	//std::string getData();

	void printData();
private:
	int mUnits;
};