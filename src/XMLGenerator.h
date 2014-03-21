#ifndef _XML_GEN_H
#define _XML_GEN_H

#include <list>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

class XMLGen
{


	//	Properties


	//	Public methods
	public:
		XMLGen();
		string XMLGen::generateWorldFile();
		list<string> generateWorld();
		list<string> generateModel();
		list<string> generateLink();
		list<string> XMLGen::generateSphericalCoordinates();
		list<string> XMLGen::generateGeometry();
		list<string> XMLGen::generateState();
		list<string> XMLGen::generateWorldPhysics();
		list<string> XMLGen::generateLight();
		list<string> XMLGen::generateGUI();
		list<string> XMLGen::generateScene();

		list<string> XMLGen::generateGrassPlane();
		list<string> XMLGen::generateStraightRoad();
		list<string> XMLGen::generateStraightRoad(double length, double width, double angle);

		void writeToFile(list<string> textToWrite, string filename);

	//	Private methods
	private:

};
#endif