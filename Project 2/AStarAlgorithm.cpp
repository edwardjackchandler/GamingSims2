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

				else if (end.getX() < start.getX())
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

				else if (end.getX() < start.getX())
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

			else if (end.getX() < start.getX())
			{
				xVal--;
				moves++;
			}
		}
	}

	else if (abs(start.getX() - end.getX()) < abs(start.getY() - end.getY()))
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

			else if (end.getY() < start.getY())
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
			else if (end.getY() < start.getY())
			{
				
				//if triangle points up (even/odd or odd / even)
				if ((xVal % 2 == 0 & yVal % 2 == 1) || (xVal % 2 == 1 & yVal % 2 == 0))
				{
					yVal--;
					moves += 3;
				}

				//if triangle points down (even/even or odd / odd)
				else if ((xVal % 2 == 0 & yVal % 2 == 0) || (xVal % 2 == 1 & yVal % 2 == 1))
				{
					yVal--;
					moves++;
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

void AStarAlgorithm::typeSetup(vector<vector<NodeType> > &typeGrid)
{
	//Row 1
	typeGrid[0][0] = NodeType("f");
	typeGrid[1][0] = NodeType("h");
	typeGrid[2][0] = NodeType("m");
	typeGrid[3][0] = NodeType("m");
	typeGrid[4][0] = NodeType("m");
	typeGrid[5][0] = NodeType("m");
	typeGrid[6][0] = NodeType("r");
	typeGrid[7][0] = NodeType("r");
	typeGrid[8][0] = NodeType("f");
	typeGrid[9][0] = NodeType("f");
	typeGrid[10][0] = NodeType("f");
	typeGrid[11][0] = NodeType("l");
	typeGrid[12][0] = NodeType("h");
	typeGrid[13][0] = NodeType("h");
	typeGrid[14][0] = NodeType("f");
	typeGrid[15][0] = NodeType("f");
	typeGrid[16][0] = NodeType("f");
	typeGrid[17][0] = NodeType("f");
	typeGrid[18][0] = NodeType("h");
	typeGrid[19][0] = NodeType("h");
	typeGrid[20][0] = NodeType("h");

	//Row 2
	typeGrid[0][1] = NodeType("h");
	typeGrid[1][1] = NodeType("h");
	typeGrid[2][1] = NodeType("h");
	typeGrid[3][1] = NodeType("h");
	typeGrid[4][1] = NodeType("l");
	typeGrid[5][1] = NodeType("h");
	typeGrid[6][1] = NodeType("h");
	typeGrid[7][1] = NodeType("r");
	typeGrid[8][1] = NodeType("r");
	typeGrid[9][1] = NodeType("r");
	typeGrid[10][1] = NodeType("r");
	typeGrid[11][1] = NodeType("r");
	typeGrid[12][1] = NodeType("r");
	typeGrid[13][1] = NodeType("r");
	typeGrid[14][1] = NodeType("r");
	typeGrid[15][1] = NodeType("f");
	typeGrid[16][1] = NodeType("f");
	typeGrid[17][1] = NodeType("l");
	typeGrid[18][1] = NodeType("l");
	typeGrid[19][1] = NodeType("h");
	typeGrid[20][1] = NodeType("h");

	//Row 3
	typeGrid[0][2] = NodeType("h");
	typeGrid[1][2] = NodeType("l");
	typeGrid[2][2] = NodeType("l");
	typeGrid[3][2] = NodeType("h");
	typeGrid[4][2] = NodeType("l");
	typeGrid[5][2] = NodeType("m");
	typeGrid[6][2] = NodeType("h");
	typeGrid[7][2] = NodeType("h");
	typeGrid[8][2] = NodeType("h");
	typeGrid[9][2] = NodeType("r");
	typeGrid[10][2] = NodeType("r");
	typeGrid[11][2] = NodeType("f");
	typeGrid[12][2] = NodeType("f");
	typeGrid[13][2] = NodeType("f");
	typeGrid[14][2] = NodeType("r");
	typeGrid[15][2] = NodeType("r");
	typeGrid[16][2] = NodeType("f");
	typeGrid[17][2] = NodeType("r");
	typeGrid[18][2] = NodeType("r");
	typeGrid[19][2] = NodeType("r");
	typeGrid[20][2] = NodeType("r");

	//Row 4
	typeGrid[0][3] = NodeType("h");
	typeGrid[1][3] = NodeType("l");
	typeGrid[2][3] = NodeType("l");
	typeGrid[3][3] = NodeType("h");
	typeGrid[4][3] = NodeType("m");
	typeGrid[5][3] = NodeType("m");
	typeGrid[6][3] = NodeType("m");
	typeGrid[7][3] = NodeType("h");
	typeGrid[8][3] = NodeType("r");
	typeGrid[9][3] = NodeType("r");
	typeGrid[10][3] = NodeType("h");
	typeGrid[11][3] = NodeType("f");
	typeGrid[12][3] = NodeType("f");
	typeGrid[13][3] = NodeType("l");
	typeGrid[14][3] = NodeType("l");
	typeGrid[15][3] = NodeType("l");
	typeGrid[16][3] = NodeType("f");
	typeGrid[17][3] = NodeType("h");
	typeGrid[18][3] = NodeType("h");
	typeGrid[19][3] = NodeType("h");
	typeGrid[20][3] = NodeType("m");

	//Row 5
	typeGrid[0][4] = NodeType("f");
	typeGrid[1][4] = NodeType("f");
	typeGrid[2][4] = NodeType("h");
	typeGrid[3][4] = NodeType("h");
	typeGrid[4][4] = NodeType("h");
	typeGrid[5][4] = NodeType("r");
	typeGrid[6][4] = NodeType("r");
	typeGrid[7][4] = NodeType("r");
	typeGrid[8][4] = NodeType("r");
	typeGrid[9][4] = NodeType("m");
	typeGrid[10][4] = NodeType("h");
	typeGrid[11][4] = NodeType("f");
	typeGrid[12][4] = NodeType("f");
	typeGrid[13][4] = NodeType("f");
	typeGrid[14][4] = NodeType("l");
	typeGrid[15][4] = NodeType("f");
	typeGrid[16][4] = NodeType("f");
	typeGrid[17][4] = NodeType("h");
	typeGrid[18][4] = NodeType("h");
	typeGrid[19][4] = NodeType("m");
	typeGrid[20][4] = NodeType("m");

	//Row 6
	typeGrid[0][5] = NodeType("l");
	typeGrid[1][5] = NodeType("l");
	typeGrid[2][5] = NodeType("l");
	typeGrid[3][5] = NodeType("h");
	typeGrid[4][5] = NodeType("r");
	typeGrid[5][5] = NodeType("r");
	typeGrid[6][5] = NodeType("h");
	typeGrid[7][5] = NodeType("h");
	typeGrid[8][5] = NodeType("m");
	typeGrid[9][5] = NodeType("m");
	typeGrid[10][5] = NodeType("m");
	typeGrid[11][5] = NodeType("h");
	typeGrid[12][5] = NodeType("h");
	typeGrid[13][5] = NodeType("h");
	typeGrid[14][5] = NodeType("m");
	typeGrid[15][5] = NodeType("h");
	typeGrid[16][5] = NodeType("h");
	typeGrid[17][5] = NodeType("h");
	typeGrid[18][5] = NodeType("m");
	typeGrid[19][5] = NodeType("m");
	typeGrid[20][5] = NodeType("m");

	//Row 7
	typeGrid[0][6] = NodeType("h");
	typeGrid[1][6] = NodeType("m");
	typeGrid[2][6] = NodeType("l");
	typeGrid[3][6] = NodeType("h");
	typeGrid[4][6] = NodeType("r");
	typeGrid[5][6] = NodeType("r");
	typeGrid[6][6] = NodeType("h");
	typeGrid[7][6] = NodeType("h");
	typeGrid[8][6] = NodeType("h");
	typeGrid[9][6] = NodeType("h");
	typeGrid[10][6] = NodeType("h");
	typeGrid[11][6] = NodeType("h");
	typeGrid[12][6] = NodeType("h");
	typeGrid[13][6] = NodeType("m");
	typeGrid[14][6] = NodeType("m");
	typeGrid[15][6] = NodeType("m");
	typeGrid[16][6] = NodeType("h");
	typeGrid[17][6] = NodeType("h");
	typeGrid[18][6] = NodeType("h");
	typeGrid[19][6] = NodeType("h");
	typeGrid[20][6] = NodeType("h");

	//Row 8
	typeGrid[0][7] = NodeType("m");
	typeGrid[1][7] = NodeType("m");
	typeGrid[2][7] = NodeType("m");
	typeGrid[3][7] = NodeType("h");
	typeGrid[4][7] = NodeType("r");
	typeGrid[5][7] = NodeType("r");
	typeGrid[6][7] = NodeType("f");
	typeGrid[7][7] = NodeType("f");
	typeGrid[8][7] = NodeType("f");
	typeGrid[9][7] = NodeType("l");
	typeGrid[10][7] = NodeType("f");
	typeGrid[11][7] = NodeType("l");
	typeGrid[12][7] = NodeType("f");
	typeGrid[13][7] = NodeType("h");
	typeGrid[14][7] = NodeType("h");
	typeGrid[15][7] = NodeType("h");
	typeGrid[16][7] = NodeType("l");
	typeGrid[17][7] = NodeType("l");
	typeGrid[18][7] = NodeType("l");
	typeGrid[19][7] = NodeType("f");
	typeGrid[20][7] = NodeType("f");
}

pair<int, int> AStarAlgorithm::stringToInts(string coords)
{

	char letterChar = coords[0];
	char numberChar = coords[1];

	int letterInt = toupper(letterChar) - 64;
	int numberInt = numberChar - '0';

	return make_pair(letterInt, numberInt);
}

bool AStarAlgorithm::mountainCheck(vector<vector<NodeType> > typeGrid, Node *end)
{
	int x = end->getX();
	int y = end->getY();

	if (typeGrid[x][y].getType() == "mountain")
	{
		return true;
	}

	else false;
}

void AStarAlgorithm::changeType(string change, vector<vector<NodeType> > &typeGrid)
{
	char letterChar = change[0];
	char numberChar = change[1];
	string type = change.substr(2);

	int letterInt = toupper(letterChar) - 64;
	int numberInt = numberChar - '0';

	typeGrid[letterInt - 1][numberInt - 1].changeType(type);

	cout << "Node " << letterChar << numberChar << "'s type changed to " << type << "\n";
}	