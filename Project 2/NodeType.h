#pragma once
#include <string>
#include <iostream>
using namespace std;

class NodeType
{
public:
	NodeType();
	NodeType(string type);
	~NodeType();

	int getTypeCost() const { return typeCost; };
	string getType() const { return typeString; };

	void changeType(string type);

	void printType();
private:
	int typeCost;
	string typeString;
};

