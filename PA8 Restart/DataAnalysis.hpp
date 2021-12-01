#include "BST.hpp"

class DataAnalysis {
public:
	//constructors
	DataAnalysis(std::string filename);
	~DataAnalysis();

	//member functions
	void runAnalysis();
private:
	void openCSV(std::string filename);
	void parseLine();
	void loopEOF();
	void compareAndInsert(std::vector<std::string> parts);
	Node*& getMostSold();
	Node*& getLeastSold();
	Node*& getMostPurchased();
	Node*& getLeastPurchased();

	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCsvStream;
};