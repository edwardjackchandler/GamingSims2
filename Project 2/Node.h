#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	Node();
	Node(int x, int y);
	~Node();
	void setH(int heuristic) { h = heuristic; };
	void setG(int g) {  this->g = g; }
	void setParent(Node *p) { parent = p; }
	int getX() const { return x; };
	int getY() const { return y; };
	int getH() const { return h; }
	int getG() const { return g; }
	int getF() const { return f; }
	int getID() const { return id; }
	Node* getParent() const { return parent; }
	bool getPointUp() const { return pointUp; }
	void calculateF() { f = g + h; }
	bool getOnList() const;
	void trueList();
	void printNode() const;
	void printPos() const;

private:
	int x;
	int y;
	int h; //distance from a node to the target node
	int g; //cost from node to another node
	int f;
	int id;
	bool pointUp;
	Node *parent = NULL;
	bool onList = false;
};

struct LessThanCompareNode 
{
	public:
		bool operator()(const Node *n1, const Node *n2) 
		{
			// true if n1 ordered before n2
			return n1->getF() > n2->getF();
		}
};

