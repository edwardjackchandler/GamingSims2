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

	int getTypeCost() { return typeCost; };

	void printType();
private:
	int typeCost;
	string typeString;
};

