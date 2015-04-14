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
	static void typeSetup(vector<vector<NodeType> > &typeGrid);
	static pair<int, int> stringToInts(string coords);
	static bool mountainCheck(vector<vector<NodeType> > typeGrid, Node *end);
	static void changeType(string change, vector<vector<NodeType> > &typeGrid);
};

