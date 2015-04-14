#include "AStarAlgorithm.h"
#include <functional>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
	//2D array using vectors to store grid coordinates
	const int gridX = 21;
	const int gridY = 8;

	bool pathFound = false;

	vector<vector<Node> > geographyVector;
	vector<vector<NodeType> > typeVector;

	//Fill geography vector of Nodes with coordinates
	geographyVector.resize(gridX);
	for (int i = 0; i < gridX; i++)
	{
		geographyVector[i].resize(gridY);

	}
	
	for (int j = 0; j < gridY; j++)
	{
		int i = 0;
		while (i < gridX)
		{
			geographyVector[i][j] = Node(i, j);
			i++;
		}
	}

	//Fill type vector of node types
	typeVector.resize(gridX);
	for (int i = 0; i < gridX; i++)
	{
		typeVector[i].resize(gridY);

	}

	//Sets up the types from the given map
	AStarAlgorithm::typeSetup(typeVector);


	int choice;
	cout << "Input 1 to calculate a path, or input 2 to change part of the map" << "\n";
	cin >> choice;

	string change;

	//Loop until you want to calculate the path, ie. choice == 1
	while (choice == 2)
	{
		//Input coords and a type to change the type map
		cout << "Input coords and a type, eg. 'a1lake' with no spaces" << "\n" << "Types are: road, lake, hill, forest, mountain." << "\n";
		cin >> change;
		AStarAlgorithm::changeType(change, typeVector);

		cout << "Input 1 to calculate a path, or input 2 to change part of the map" << "\n";
		cin >> choice;

	}

	//variables for taking user input and turning it into the start and end of the route 
	string startString;
	string endString;
	pair<int, int>	startPair;
	pair<int, int>	endPair;
	Node *start;
	Node *end;

	//Loop that sets up the start and end of the route
	//If the given route ends at a mountain, you must input the coords again
	do 
	{
		//Takes coords in form a3, checking there are only 2 characters input into the console.
		cout << "Please enter start node's coordinates." << "\n";
		cin >> startString;
		while (!(startString.length() > 1 & startString.length() < 3))
		{
			cout << "Please enter correct coordinates" << "\n";
			cin >> startString;
		}
		startPair = AStarAlgorithm::stringToInts(startString);

		cout << "Please enter end node's coordinates." << "\n";
		cin >> endString;
		while (!(endString.length() > 1 & endString.length() < 3))
		{
			cout << "Please enter correct coordinates" << "\n";
			cin >> endString;
		}
		endPair = AStarAlgorithm::stringToInts(endString);

		start = &geographyVector[startPair.first - 1][startPair.second - 1];
		end = &geographyVector[endPair.first - 1][endPair.second - 1];

		if (AStarAlgorithm::mountainCheck(typeVector, end) == true || AStarAlgorithm::mountainCheck(typeVector, start) == true)
		{
			cout << "Route cannot start or end on a mountain, please choose another route" << "\n";

		}

	}
	while (AStarAlgorithm::mountainCheck(typeVector, end) == true || AStarAlgorithm::mountainCheck(typeVector, start) == true);

	//Node P with lowest F, and vector Q
	Node *p = start;
	vector<Node*> q;
	
	cout << "Calculating path from " << startString << " to " << endString << "\n";

	start->setH(AStarAlgorithm::distanceToEnd(*start, *end));
	start->setG(0);
	start->calculateF();

	//OpenList in a priority queue to automatically get the Node with the least f value
	priority_queue<Node*, vector<Node*>, LessThanCompareNode>openList;
	//CloseList in a vector
	vector<Node*> closeList;

	//Set up starting node with a cost of zero, and put it on openList
	openList.push(start);
	start->trueList();
	start->setG(0);
	int cLCount = 0;

 	while (pathFound != true)
	{
		//Put top of openList (node with least f value) on closed list
		closeList.push_back(openList.top());
		p = closeList[cLCount];
		//Take it off openList
		openList.pop();
		cout << "p = ";
		p->printNode();
			
		
		//Next 5 if/else statements decide which nodes are connected and added to vector Q

		//If not at edges of grid
		if ((p->getX() < gridX - 1) && (p->getX() > 0)
			&& (p->getY() < gridY - 1) && (p->getY() > 0))
		{
			q.push_back(&geographyVector[p->getX() - 1][p->getY()]);
			cout << "Added to q: " << "\n";
			q[0]->printNode();
			q.push_back(&geographyVector[p->getX() + 1][p->getY()]);
			q[1]->printNode();

			//if pointing up, add node below it to q
			if (p->getPointUp())
			{
				q.push_back(&geographyVector[p->getX()][p->getY() + 1]);
				q[2]->printNode();

			}
			//else add node above
			else
			{
				q.push_back(&geographyVector[p->getX()][p->getY() - 1]);
				q[2]->printNode();

			}

		}

		//left
		else if (p->getX() == 0)
		{
			q.push_back(&geographyVector[p->getX() + 1][p->getY()]);
			cout << "Added to q: " << "\n";
			q[0]->printNode();

			if (p->getY() != gridY - 1 & p->getY() != 0)
			{
				//if pointing up, add node below it to q
				if (p->getPointUp())
				{
					q.push_back(&geographyVector[p->getX()][p->getY() + 1]);
					q[1]->printNode();

				}
				//else add node above
				else q.push_back(&geographyVector[p->getX()][p->getY() - 1]);
				q[1]->printNode();

			}
		}

		//right
		else if (p->getX() == gridX - 1)
		{
			q.push_back(&geographyVector[p->getX() - 1][p->getY()]);
			cout << "Added to q: " << "\n";
			q[0]->printNode();

			if (p->getY() != gridY - 1 & p->getY() != 0)
			{
				//if pointing up, add node below it to q
				if (p->getPointUp())
				{
					q.push_back(&geographyVector[p->getX()][p->getY() + 1]);
					q[1]->printNode();

				}
				//else add node above
				else q.push_back(&geographyVector[p->getX()][p->getY() - 1]);
				q[1]->printNode();

			}
		}

		//top
		else if (p->getY() == 0)
		{
			cout << "Added to q: " << "\n";

			if (p->getX() == 0)
			{
				q.push_back(&geographyVector[p->getX() + 1][p->getY()]);
				geographyVector[p->getX() + 1][p->getY()].printNode();
			}

			if (p->getX() == gridX - 1)
			{
				q.push_back(&geographyVector[p->getX() - 1][p->getY()]);
				geographyVector[p->getX() - 1][p->getY()].printNode();

			}			
			
			//if pointing up, add all nodes around

			else
			{
				q.push_back(&geographyVector[p->getX() - 1][p->getY()]);
				q.push_back(&geographyVector[p->getX() + 1][p->getY()]);

				if (p->getPointUp())
				{
					q.push_back(&geographyVector[p->getX()][p->getY() + 1]);
				}

				geographyVector[p->getX() - 1][p->getY()].printNode();
				geographyVector[p->getX() + 1][p->getY()].printNode();
				geographyVector[p->getX()][p->getY() + 1].printNode();

			}

			
		}

		//bottom
		else if (p->getY() == gridY - 1)
		{
			cout << "Added to q: " << "\n";

			if (p->getX() == 0)
			{
				q.push_back(&geographyVector[p->getX() + 1][p->getY()]);
				geographyVector[p->getX() + 1][p->getY()].printNode();
			}

			if (p->getX() == gridX - 1)
			{
				q.push_back(&geographyVector[p->getX() - 1][p->getY()]);
				geographyVector[p->getX() - 1][p->getY()].printNode();

			}

			//if pointing down, add all nodes around

			else if (!p->getPointUp())
			{
				q.push_back(&geographyVector[p->getX() - 1][p->getY()]);
				q.push_back(&geographyVector[p->getX() + 1][p->getY()]);
				q.push_back(&geographyVector[p->getX()][p->getY() - 1]);
				geographyVector[p->getX() - 1][p->getY()].printNode();
				geographyVector[p->getX() + 1][p->getY()].printNode();
				geographyVector[p->getX()][p->getY() - 1].printNode();

			}

		}

		//Loop through q to see if a connected node is the end node
		//If so, set the parent of the end node to P
		for (int i = 0; i < q.size(); i++)
		{
			if (q[i] == end)
			{
				end->setParent(p);
				pathFound = true;
				cout << "PATH FOUND!" << "\n";
			}
		}
	

		//For each connected node, q[j]
		for (int j = 0; j < q.size(); j++)
		{
				
			//calculate H, G and F
			int newH = AStarAlgorithm::distanceToEnd(*q[j], *end);
			int newG = AStarAlgorithm::getTileCost(typeVector, q[j]) + p->getG();
			int newF = newG + q[j]->getH();
			//Is Q on open / closed list?
			if (q[j]->getOnList() == true)
			{
				if (newF < q[j]->getH())
				{
					//assign new F, G, and H values and set P as Q's parent
					q[j]->setParent(p);
					q[j]->setH(newH);
					q[j]->setG(newG);
					q[j]->calculateF();
				}
			}

			else
			{
				//If the node type is mountain, then do not put on openList, ie. ignore the node, else...
				if (typeVector[q[j]->getX()][q[j]->getY()].getType() != "mountain")
				{
					//Put on openList, assign new F, G, and H values and set P as Q's parent

					openList.push(q[j]);
					q[j]->trueList();
					q[j]->setParent(p);
					q[j]->setH(newH);
					q[j]->setG(newG);
					q[j]->calculateF();
					cout << "ADDED TO OPENLIST: " << "\n";
					q[j]->printNode();
				}
			}
			//Remake the heap for the openList after changing values
			make_heap(const_cast<Node**>(&openList.top()), const_cast<Node**>(&openList.top()) + openList.size(), LessThanCompareNode());
							
		}

		//clear the vector q
		q.clear();
		//increment counter for the closedList
		cLCount++;
	}   

	vector<Node> path;
	path.push_back(*end);


	int pathCount = 0;

	//Loop through from the end node and find each parent until the start node to find the path
	do{
		
		path.push_back(*path[pathCount].getParent());
		pathCount++;
	}

	while ((path[pathCount].getX() != start->getX()) || (path[pathCount].getY() != start->getY()));

	cout << "PATH: " << startString << " to " << endString <<"\n";
	//Print the path
	for (int i = path.size() - 1; i >= 0; i--)
	{
		path[i].printPos();
	}

	system("pause");

}
