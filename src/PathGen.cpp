#include "aeg/PathGen.h"
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <sstream>

list<string> PathGen::generatePath(double pathLength, bool continuous, list<string> terrainList, string modelName)
{
	list<string> pathList;
	double width = 10;
	//	TODO: add initial model description

	list<vector<double> > pathPoints = selectPoints(pathLength, continuous);

	int index = 0;
	list<vector<double> >::iterator nextIter = pathPoints.begin();
	nextIter++;
	for (list<vector<double> >::iterator iter = pathPoints.begin(); pathPoints.end() != nextIter; iter++, nextIter++, index++)
	{
		vector<double> start = *iter;
                vector<double> end = *nextIter;

		//	if circular course and last point reached, connect to start
		if ((continuous) && (pathPoints.end() == nextIter))
		{
			end = *pathPoints.begin();
		}

		//	generate path segment with start and end
		list<string> temp = generateRoadSegment(start, end, width, index);
		pathList.splice(pathList.end(), temp);
	}

	//	TODO: add supplemental model description

	return pathList;
}

list<string> PathGen::generateRoadSegment(vector<double> start, vector<double> end, double width, int segmentNum)
{
	list<string> segmentDescription;

	

	return segmentDescription;
}

list<string> PathGen::generateRoadSegment(vector<double> start, double length, double width, double angle, int segmentNum)
{
	list<string> road;

	string prefixSpacing = "      ";
	road.push_back(prefixSpacing + "   <link name='roadLink_1'>");

	//	pose: start at origin
	stringstream sstream;
	sstream << width / 2;
	string tempWidth = sstream.str();
        sstream.str(string());
	
        sstream << length / 2;
	string tempLength = sstream.str();
        sstream.str(string());
	
        sstream << angle;
	string tempAngle = sstream.str();
        sstream.str(string());

	road.push_back(prefixSpacing + "   <pose>" + tempWidth + " " + tempLength + " 0.1  0 0 " + tempAngle + "</pose>");
	

	//	Collision
	road.push_back(prefixSpacing + "      <collision name='collision'>");
	road.push_back(prefixSpacing + "         <geometry>");
	road.push_back(prefixSpacing + "            <plane>");
	road.push_back(prefixSpacing + "               <normal>0 0 1</normal>");

	sstream << width;
	tempWidth = sstream.str();
        sstream.str(string());

	sstream << length;
	tempLength = sstream.str();
        sstream.str(string());

	road.push_back(prefixSpacing + "               <size>" + tempWidth + " " + tempLength + "</size>");
	road.push_back(prefixSpacing + "            </plane>");
	road.push_back(prefixSpacing + "         </geometry>");
	road.push_back(prefixSpacing + "         <surface>");
	road.push_back(prefixSpacing + "            <bounce>");
	road.push_back(prefixSpacing + "            </bounce>");
	road.push_back(prefixSpacing + "            <friction>");
	road.push_back(prefixSpacing + "               <ode>");
	road.push_back(prefixSpacing + "                  <mu>100</mu>");
	road.push_back(prefixSpacing + "                  <mu2>50</mu2>");
	road.push_back(prefixSpacing + "               </ode>");
	road.push_back(prefixSpacing + "            </friction>");
	road.push_back(prefixSpacing + "            <contact>");
	road.push_back(prefixSpacing + "               <ode>");
	road.push_back(prefixSpacing + "               </ode>");
	road.push_back(prefixSpacing + "            </contact>");
	road.push_back(prefixSpacing + "         </surface>");
	road.push_back(prefixSpacing + "      </collision>");

	//	Visual
	road.push_back(prefixSpacing + "      <visual name='visual'>");
	road.push_back(prefixSpacing + "         <cast_shadows>0</cast_shadows>");
	road.push_back(prefixSpacing + "         <geometry>");
	road.push_back(prefixSpacing + "            <plane>");
	road.push_back(prefixSpacing + "               <normal>0 0 1</normal>");
	road.push_back(prefixSpacing + "               <size>" + tempWidth + " " + tempLength + "</size>");
	road.push_back(prefixSpacing + "            </plane>");
	road.push_back(prefixSpacing + "         </geometry>");
	road.push_back(prefixSpacing + "         <material>");
	road.push_back(prefixSpacing + "            <script>");
	road.push_back(prefixSpacing + "               <uri>file://media/materials/scripts/gazebo.material</uri>");
	road.push_back(prefixSpacing + "               <name>Gazebo/FlatBlack</name>");
	road.push_back(prefixSpacing + "            </script>");
	road.push_back(prefixSpacing + "         </material>");
	road.push_back(prefixSpacing + "      </visual>");

	road.push_back(prefixSpacing + "      <velocity_decay>");
	road.push_back(prefixSpacing + "         <linear>0</linear>");
	road.push_back(prefixSpacing + "         <angular>0</angular>");
	road.push_back(prefixSpacing + "      </velocity_decay>");

	road.push_back(prefixSpacing + "      <self_collide>0</self_collide>");
	road.push_back(prefixSpacing + "      <kinematic>0</kinematic>");
	road.push_back(prefixSpacing + "      <gravity>1</gravity>");

	road.push_back(prefixSpacing + "   </link>");

//	road.push_back(prefixSpacing + "</model>");


	return road;
}

list<vector<double> > PathGen::selectPoints(double pathLength, bool continuous)
{
	list<vector<double> > pathPoints;
	vector<double> start(3, 0.1);	// start at (0.1,0.1,0.1);
	pathPoints.push_back(start);

	vector<double> nextPoint;
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
			nextLength = rand() % int(remainingLength);
		}

		//	TODO: add angle variability
		nextAngle = 0;
		
		nextPoint = selectRestrictedPoint(lastPoint, nextLength, nextAngle, angleDevMR);
		pathPoints.push_back(nextPoint);
		lastPoint = nextPoint;
		remainingLength -= nextLength;
		lastAngle = nextAngle;
	}

	return pathPoints;
}

vector<double> PathGen::selectRestrictedPoint(vector<double> start, double length, double startingAngle, int angleDevMR)
{
	vector<double> point;

	srand(time(NULL));
	int randAngle = rand() % int (2 * angleDevMR);
	randAngle = (randAngle < angleDevMR) ? -1 * (randAngle % int(angleDevMR)) : randAngle % int(angleDevMR);
	double angle = startingAngle + (randAngle / 1000.0);  // TODO: check that randAngle is treated as double

	double xPos = start[0] + length * cos(angle);
	double yPos = start[1] + length * sin(angle);
	double zPos = start[2] + 0.1;

	point.push_back(xPos);
	point.push_back(yPos);
	point.push_back(zPos);

	return point;
}
