#ifndef _XML_GEN_H
#define _XML_GEN_H

#include <list>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class XMLGen
{
   //	Properties

   //	Public methods
public:
   string generateWorldFile();
   string generateWorldFile(double length, bool continuous, list<string> terrainList);
   list<string> generateWorld();
   list<string> generateModel();
   list<string> generateLink();
   list<string> generateSphericalCoordinates();
   list<string> generateGeometry();
   list<string> generateState();
   list<string> generateWorldPhysics();
   list<string> generateLight();
   list<string> generateGUI();
   list<string> generateScene();

   list<string> generateGrassPlane();
   list<string> generateStraightRoad();
   list<string> generateStraightRoad(double length, double width, double angle);
   list<string> generateStraightRoad(vector<double> start, double length, double width, double angle);
   list<string> generateStraightRoad(vector<double> start, vector<double> end, double width);
   list<string> generatePathFromStraightRoads(list<vector<double> > inputList);

   void writeToFile(list<string> textToWrite, string filename);
   list<string> getVehicle();
   list<string> getVRCPlugin();

   //	Private methods
private:

};
#endif
