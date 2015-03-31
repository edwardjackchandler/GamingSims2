#include "AStarAlgorithm.h"



int AStarAlgorithm::distanceToEnd(Node start, Node end)
{
	int moves = 0;
	int xVal, yVal;

	if (abs(start.getX() - end.getX()) >= abs(start.getY() - end.getY()))
	{
		xVal = start.getX();
		yVal = start.getY();

		while (yVal != end.getY())
		{
			if (end.getY() > start.getY())
			{
				if (end.getX() > start.getX())
				{
					xVal++;
					yVal++;
					moves+= 2;
				}

				if (end.getX() < start.getX())
				{
					xVal--;
					yVal++;
					moves+= 2;
				}
			}

			if (end.getY() < start.getY())
			{
				if (end.getX() > start.getX())
				{
					xVal++;
					yVal--;
					moves+= 2;
				}

				if (end.getX() < start.getX())
				{
					xVal--;
					yVal--;
					moves+= 2;
				}
			}
		}

		while (xVal != end.getX())
		{
			if (end.getX() > start.getX())
			{
				xVal++;
				moves++;
			}

			if (end.getX() < start.getX())
			{
				xVal--;
				moves++;
			}
		}
	}

	if (abs(start.getX() - end.getX()) < abs(start.getY() - end.getY()))
	{
		xVal = start.getX();
		yVal = start.getY();

		while (xVal != end.getX())
		{
			if (end.getY() > start.getY())
			{
				if (end.getX() > start.getX())
				{
					xVal++;
					yVal++;
					moves += 2;
				}

				else if (end.getX() < start.getX())
				{
					xVal--;
					yVal++;
					moves += 2;
				}
			}

			if (end.getY() < start.getY())
			{
				if (end.getX() > start.getX())
				{
					xVal++;
					yVal--;
					moves += 2;
				}

				else if (end.getX() < start.getX())
				{
					xVal--;
					yVal--;
					moves += 2;
				}
			}

		}

		while (yVal != end.getY())
		{	
			//go down grid
			if (end.getY() > start.getY())
			{
				
				//if triangle points up (even/odd or odd / even)
				if ((xVal % 2 == 0 & yVal % 2 == 1) || (xVal % 2 == 1 & yVal % 2 == 0))
				{
					yVal++;
					moves++;
				}

				//if triangle points down (even/even or odd / odd)
				else if ((xVal % 2 == 0 & yVal % 2 == 0) || (xVal % 2 == 1 & yVal % 2 == 1))
				{
					yVal++;
					moves += 3;
				}
				
			}

			//go up
			if (end.getY() < start.getY())
			{
				
				//if triangle points up (even/odd or odd / even)
				if ((xVal % 2 == 0 & yVal % 2 == 1) || (xVal % 2 == 1 & yVal % 2 == 0))
				{
					yVal--;
					moves++;
				}

				//if triangle points down (even/even or odd / odd)
				if ((xVal % 2 == 0 & yVal % 2 == 0) || (xVal % 2 == 1 & yVal % 2 == 1))
				{
					yVal--;
					moves += 3;
				}
				
			}
		}
	}

	return moves;
}

int AStarAlgorithm::getTileCost(vector<vector<NodeType> > typeGrid, Node *n)
{
	int x = n->getX();
	int y = n->getY();

	return typeGrid[x][y].getTypeCost();
}


