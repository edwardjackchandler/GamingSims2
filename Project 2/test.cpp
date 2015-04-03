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

	//Fill array of Nodes with coordinates
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

	//Fill type array of node types
	typeVector.resize(gridX);
	for (int i = 0; i < gridX; i++)
	{
		typeVector[i].resize(gridY);

	}

	for (int j = 0; j < gridY; j++)
	{
		int i = 0;
		while (i < gridX)
		{
			typeVector[i][j] = NodeType("r");
			i++;
		}
	}
	
	cout << AStarAlgorithm::distanceToEnd(geographyVector[5][3], geographyVector[20][2]) << "\n";
	cout << AStarAlgorithm::distanceToEnd(geographyVector[7][7], geographyVector[5][5]) << "\n";
	
	Node *end = &geographyVector[5][2];
	Node *start = &geographyVector[1][1];
	Node *p = start;
	vector<Node*> q;

	//Set all heuristics
	for (int i = 0; i < gridX; i++)
	{
		for (int j = 0; j < gridY; j++)
		{
			geographyVector[i][j].setH(AStarAlgorithm::distanceToEnd(geographyVector[i][j], *end));
			//geographyVector[i][j].printNode();
			//typeVector[i][j].printType();
		}
	}

	start->setG(0);
	start->calculateF();

	/*priority_queue<Node*, vector<Node*>, std::less<Node*> >test;
	Node* one = &geographyVector[4][2];
	Node* four = &geographyVector[1][2];
	Node* two = &geographyVector[3][2];
	Node* three = &geographyVector[2][2];
	Node* five = &geographyVector[0][0];

	one->setG(1);
	two->setG(1);
	three->setG(1);
	four->setG(1);
	five->setG(1);

	one->calculateF();
	two->calculateF();
	three->calculateF();
	four->calculateF();
	five->calculateF();

	test.push(one);
	test.push(four);
	test.push(two);
	test.push(three);
	test.push(five);

	test.top()->printNode();*/


	//Contains ids of Nodes to check parents
	priority_queue<Node*, vector<Node*>, std::less<Node*>>openList;
	vector<Node*> closeList;

	openList.push(start);
	start->trueList();
	start->setG(0);
	int cLCount = 0;

 	while (pathFound != true)
	{
		//while (openList.empty() == false)
		cout << "openList top: ";
		openList.top()->printNode();
		closeList.push_back(openList.top());
		p = closeList[cLCount];
		openList.pop();
		cout << "p = ";
		p->printNode();
			
		//Checks if p is end node
		if (p == end)
		{
			pathFound = true;
		}
		
		//Next 5 if/else statements decide which nodes are connected

		//If not at edges of grid
		if ((p->getX() < gridX - 1) && (p->getX() > 0)
			&& (p->getY() < gridY - 1) && (p->getY() < gridY - 1))
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

			if (p->getY() != gridY - 1 || p->getY() != 0)
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

			if (p->getY() != gridY - 1 || p->getY() != 0)
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

		//bottom
		else if (p->getY() == gridY - 1)
		{
			q.push_back(&geographyVector[p->getX() - 1][p->getY()]);
			cout << "Added to q: " << "\n";
			q[0]->printNode();

			if (p->getX() != gridX - 1 || p->getX() != 0)
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
		else if (p->getY() == gridY - 1)
		{
			if (p->getY() != gridX - 1 || p->getX() != 0)
			{
				q.push_back(&geographyVector[p->getX() - 1][p->getY()]);
				q.push_back(&geographyVector[p->getX() - 1][p->getY()]);
				cout << "Added to q: " << "\n";
				q[0]->printNode();
				q[1]->printNode();

				//if pointing up, add node below it to q
				if (p->getPointUp())
				{
					q.push_back(&geographyVector[p->getX()][p->getY() + 1]);
					q[2]->printNode();

				}
			}
		}

	

		//For each connected node, q[j]
		for (int j = 0; j < q.size(); j++)
		{
				
			//calculate G and F
			int newG = AStarAlgorithm::getTileCost(typeVector, q[j]) + p->getG();
			int newF = newG + q[j]->getH();
			//Is Q on open / closed list?
			if (q[j]->getOnList() == true)
			{
				if (newF < q[j]->getF())
				{
					//assign new F, G and H values
					q[j]->setParent(p);
					q[j]->setG(newG);
					q[j]->calculateF();
				}
			}

			else
			{
				openList.push(q[j]);
				q[j]->setParent(p);
				q[j]->setG(newG);
				q[j]->calculateF();
			}
							
		}

		cout << "ADDED TO OPENLIST: " << "\n";
		for (int i = 0; i < q.size(); i++)
		{
			q[i]->printNode();
		}
		q.clear();
		cLCount++;
	}   



		//If triangle points up and is not on bottom of grid 
		//(no connected nodes can be below bottom and only 
		//nodes that point up can have that possible) 
		/*if (p->getPointUp() & (p->getY() < gridY - 1))
		{
			for (int i = 0; i < 3; i++)
			{
				q = geographyVector[p->getX() - 1][p->getY()];
			}
			
		}*/

	
	
	///*while (pathFound != true)
	//{

	//}*/

	system("pause");

}
