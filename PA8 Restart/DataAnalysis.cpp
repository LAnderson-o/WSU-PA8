#include "DataAnalysis.hpp"

//constructors
DataAnalysis::DataAnalysis(std::string filename) {
	openCSV(filename);
}

DataAnalysis::~DataAnalysis() {
	mCsvStream.close();
}

void DataAnalysis::openCSV(std::string filename) {
	mCsvStream.open(filename, std::ios::in);
}

void DataAnalysis::parseLine() {
	std::vector<std::string> parts;
	std::string line;
	std::getline(mCsvStream, line, '\n');
	std::stringstream wholeline(line);
	while (std::getline(wholeline, line, ',')) {
		parts.push_back(line);
	}
	if(parts.size() != 0){
		if (parts[0] != "Units") {
			compareAndInsert(parts);
		}
	}
}

void DataAnalysis::loopEOF() {
	while (!mCsvStream.eof()) {
		parseLine();
	}
	std::cout << "Purchased\n";
	mTreePurchased.inOrderTraversal();
	std::cout << "Sold\n";
	mTreeSold.inOrderTraversal();
	Node* mostSold = getMostSold();
	Node* mostPurchased = getMostPurchased();
	Node* leastSold = getLeastSold();
	Node* leastPurchased = getLeastPurchased();
	std::cout << "Most Sold: " << mostSold->getData() << " Total Units: " << ((TransactionNode*)mostSold)->getUnits() << std::endl;
	std::cout << "Least Sold: " << leastSold->getData() << " Total Units: " << ((TransactionNode*)leastSold)->getUnits() << std::endl;
	std::cout << "Most Purchased: " << mostPurchased->getData() << " Total Units: " << ((TransactionNode*)mostPurchased)->getUnits() << std::endl;
	std::cout << "Least Purchased: " << leastPurchased->getData() << " Total Units: " << ((TransactionNode*)leastPurchased)->getUnits() << std::endl;
}

void DataAnalysis::compareAndInsert(std::vector<std::string> parts) {
	TransactionNode newNode(stoi(parts[0]), parts[1]);
	if (parts[2] == "Purchased") {
		mTreePurchased.insert(newNode);
	}
	else if (parts[2] == "Sold") {
		mTreeSold.insert(newNode);
	}
}

Node*& DataAnalysis::getLeastSold() {
	Node* temp = mTreeSold.getRoot();
	while (temp->getLeft() != nullptr) {
		temp = temp->getLeft();
	}
	return temp;
}

Node*& DataAnalysis::getMostSold() {
	Node* temp = mTreeSold.getRoot();
	while (temp->getRight() != nullptr) {
		temp = temp->getRight();
	}
	return temp;
}

Node*& DataAnalysis::getLeastPurchased() {
	Node* temp = mTreePurchased.getRoot();
	while (temp->getLeft() != nullptr) {
		temp = temp->getLeft();
	}
	return temp;
}

Node*& DataAnalysis::getMostPurchased() {
	Node* temp = mTreePurchased.getRoot();
	while (temp->getRight() != nullptr) {
		temp = temp->getRight();
	}
	return temp;
}

//grandad
void DataAnalysis::runAnalysis() {
	loopEOF();
}