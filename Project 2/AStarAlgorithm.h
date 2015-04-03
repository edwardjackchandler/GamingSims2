#pragma once
#include <Math.h>
#include "Node.h"
#include "NodeType.h"
#include <vector>
using namespace std;

class AStarAlgorithm
{
public:
	static int distanceToEnd(Node start, Node end);
	static int getTileCost(vector<vector<NodeType> > typeGrid, Node *n);
};

