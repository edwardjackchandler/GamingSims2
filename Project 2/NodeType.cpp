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
		typeString = "road";
	}

	if (type == "l")
	{
		typeCost = 1;
		typeString = "lake";
	}

	if (type == "h")
	{
		typeCost = 2;
		typeString = "hill";
	}

	if (type == "f")
	{
		typeCost = 3;
		typeString = "forest";
	}

	if (type == "m")
	{
		typeCost = 300;
		typeString = "mountain";
	}
}


NodeType::~NodeType()
{
}

void NodeType::changeType(string type)
{
	if (type == "road")
	{
		typeCost = 1;
		typeString = "road";
	}

	if (type == "lake")
	{
		typeCost = 1;
		typeString = "lake";
	}

	if (type == "hill")
	{
		typeCost = 2;
		typeString = "hill";
	}

	if (type == "forest")
	{
		typeCost = 3;
		typeString = "forest";
	}

	if (type == "mountain")
	{
		typeString = "mountain";
	}
}

void NodeType::printType()
{
	cout << "Type: " << typeString << "\n";
}