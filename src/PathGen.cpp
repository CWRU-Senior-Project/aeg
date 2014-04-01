#include "aeg/PathGen.h"
#include <cstdlib>
#include <algorithm>

list<string> PathGen::generatePath(double pathLength, bool continuous, list<string> terrainList, string modelName)
{
	list<string> pathList;
	//	TODO: add initial model description

	list<vector<double> > pathPoints = selectPoints(pathLength, continuous);

	for (list<vector<double> >::iterator iter = pathPoints.begin(), int index = 0; pathPoints.end() != iter; iter++, index++)
	{
		vector<double> start = *iter;

		//	if circular course and last point reached, connect to start
		if ((continuous) && (pathPoints.end() == (iter + 1))
		{
			vector<double> end = *pathPoints.begin();
		}
		else
		{
			vector<double> end = *(iter + 1);
		}

		//	generate path segment with start and end
		pathList.splice(pathList.end(), generateRoadSegment(start, end, width, index));		
	}

	//	TODO: add supplemental model description

	return pathList;
}

list<string> generateRoadSegment(vector<double> start, vector<double> end, double width, int segmentId)
{
	list<string> segmentDescription;



	return segmentDescription;
}

list<vector<double> > PathGen::selectPoints(double pathLength, bool continuous)
{
	list<vector<double> > pathPoints;
	vector<double> start(3, 0.1);	// start at (0.1,0.1,0.1);
	pathPoints.push_back(start);

	vector<double> currentPoint;
	vector<double> lastPoint = start;

	double remainingLength = pathLength;
	double startDistance = 0;
	
	double nextLength = 0;
	
	double lastAngle = 0;
	double nextAngle = 0;
	int angleDevMR = 400;
	int minPoints = 3;

	while (0 < remainingLength)
	{
		/*
		//	TODO: add continuous functionality
		if (continuous)
		{
		(minPoints < pathPoints.size())
			nextLength = rand() % min(remainingLength, startDistance);

		}
		else
		{
			
		}
		*/
		//	if remaining length < 10% of path length, set last point distance to remainingDistance
		if ((pathLength / 10) > remainingLength)
		{
			nextLength = remainingLength;
		}
		else
		{
			nextLength = rand() % remainingLength;
		}

		//	TODO: add angle variability
		nextAngle = 0;
		
		nextPoint = selectRestrictedPoint(lastPoint, nextLength, nextAngle, angleDev);
		pathPoints.push_back(nextPoint);
		lastPoint = nextPoint;
		remainingLength -= nextLength;
		lastAngle = nextAngle;
	}

	return pathPoints;
}

vector<double> selectRestrictedPoint(vector<double> start, double length, double startingAngle, int angleDevMR)
{
	vector<double> point;

	srand(time(NULL));
	int randAngle = rand() % (2 * angleDev);
	randAngle = (randAngle < angleDev) ? -1 * (randAngle % angleDev) : randAngle % angleDev;
	double angle = startingAngle + (randAngle / 1000.0);  // TODO: check that randAngle is treated as double

	double xPos = start[0] + length * cos(angle);
	double yPos = start[1] + length * sin(angle);
	double zPos = start[2] + 0.1;

	point.push_back(xPos);
	point.push_back(yPos);
	point.push_back(zPos);

	return point;
}