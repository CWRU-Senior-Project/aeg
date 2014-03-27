#ifndef _XML_GEN_H
#define _XML_GEN_H

#include <list>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class XMLGen
{
   //	Properties

   //	Public methods
public:
   string generateWorldFile();
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

   void writeToFile(list<string> textToWrite, string filename);

   //	Private methods
private:

};
#endif
