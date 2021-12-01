#include "TransactionNode.hpp"

void TransactionNode::printData() {
	std::cout << mUnits << " " << mData << std::endl;
}

void TransactionNode::setData(int newUnits) {
	mUnits = newUnits;
}

void TransactionNode::setData(int newUnits, std::string newData) {
	mUnits = newUnits;
	mData = newData;
}

void TransactionNode::setData(std::string newData) {
	mData = newData;
}

int TransactionNode::getUnits() {
	return mUnits;
}

//std::string TransactionNode::getData() {
//	return mData;
//}