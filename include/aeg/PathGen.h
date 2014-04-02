#ifndef _PATH_GEN_H_
#define _PATH_GEN_H_

#include <list>
#include <vector>
#include <string>

using namespace std;

class PathGen
{
public:
	list<string> generatePath(double pathLength, bool continuous, list<string> terrainList, string modelName);

private:
	list<vector<double> > selectPoints(double pathLength, bool continuous);
	vector<double> selectRestrictedPoint(vector<double> start, double length, double startingAngle, int angleDev);
	list<string> generateRoadSegment(vector<double> start, vector<double> end, double width, int segmentNum);
	list<string> generateRoadSegment(vector<double> start, double length, double width, double angle, int segmentNum);


};

#endif
