#pragma once
#include <iostream>
class Node
{
public:
	Node();
	Node(int x, int y);
	~Node();
	void setH(int heuristic) { h = heuristic; };
	void setG(int g) {  this->g = g; }
	void setParent(Node *p) { parent = p; }
	int getX() { return x; };
	int getY() { return y; };
	int getH() { return h; }
	int getG() { return g; }
	int getF() { return f; }
	int getID() { return id; }
	int getParentG() { return parent->getG(); }
	bool getPointUp() { return pointUp; }
	void calculateF() { f = g + h; }
	bool getOnList();
	void trueList();
	void printNode();
private:
	int x;
	int y;
	int h; //distance from a node to the target node
	int g; //cost from node to another node
	int f;
	int id;
	bool pointUp;
	Node *parent;
	bool onList = false;
};

struct LessThanCompareNode 
{
	bool operator()(Node &n1, Node &n2) {
		// true if n1 ordered before n2
		return n1.getF() < n2.getF();
	}
};

