#include "Node.h"
using namespace std;

Node::Node()
{
	this->x = 0;
	this->y = 0;
	h = 0;
	g = 0;
	f = 0;
}

Node::Node(int x, int y)
{
	this->x = x;
	this->y = y;
	h = 0;
	g;
	f = 0;
	id = this->x + (this->y * 21) + 1;
	if ((x % 2 == 0 & y % 2 == 1) || (x % 2 == 1 & y % 2 == 0))
	{
		pointUp = true;
	}

	else pointUp = false;

}

Node::~Node()
{
}

bool Node::getOnList()
{
	return onList;
}

void Node::trueList()
{
	onList = true;
}

void Node::printNode()
{
	cout << "Node pos: (" << x << ", " << y << ") H = " << h << " ID = " << id << " Points up = " << pointUp << "\n";
}



