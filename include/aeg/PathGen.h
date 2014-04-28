#ifndef _PATH_GEN_H_
#define _PATH_GEN_H_

#include <list>
#include <vector>
#include <string>

using namespace std;

class PathGen
{
   public:

      // Generates complete SDF path model given input parameters
      list<string> generatePath(double pathLength, bool continuous, list<string> terrainList, string modelName);

   private:
      /*--------------------------------
       *   Properties
       *--------------------------------*/

      /*--------------------------------
       *   Functions
       *--------------------------------*/

      // Randomly select planar locations for path segments
      list<vector<double> > selectPoints(double pathLength, bool continuous);

      // Randomly select a point (x,y,z) satisfying input criteria
      vector<double> selectRestrictedPoint(vector<double> start, double length, double startingAngle, int angleDev);

      // Generate SDF strings defining a road segment with given parameters
      list<string> generateRoadSegment(vector<double> start, vector<double> end, double width, int segmentNum);

      // Generate SDF strings defining a road segment with given parameters
      list<string> generateRoadSegment(vector<double> start, double length, double width, double angle, int segmentNum);
};

#endif
