#include "NodeType.h"

NodeType::NodeType()
{
	typeCost = 0;
}

NodeType::NodeType(string type)
{
	if (type == "r")
	{
		typeCost = 1;
		typeString = "Road";
	}
}


NodeType::~NodeType()
{
}

void NodeType::printType()
{
	cout << "Type: " << typeString << "\n";
}
