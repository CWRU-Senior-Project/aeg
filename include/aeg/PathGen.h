#include <list>
#include <vector>

class PathGen
{
public:
	list<string> generatePath(double pathLength, bool continuous, list<string> terrainList, string modelName);

private:
	list<vector<double> > selectPoints(double pathLength, bool continuous);
	vector<double> selectRestrictedPoint(vector<double> start, double length, double startingAngle, int angleDev);
	list<string> generateRoadSegment(vector<double> start, vector<double> end, double width, int segmentNum);
};