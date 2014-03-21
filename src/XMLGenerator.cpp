#include "XMLGenerator.h"

using namespace std;

XMLGen::XMLGen()
{

}

string XMLGen::generateWorldFile()
{
	list<string> worldContent = XMLGen::generateWorld();
	string filename = "TestWorld2.txt";
	XMLGen::writeToFile(worldContent, filename);
	return filename;
}

list<string> XMLGen::generateWorld()
{
	list<string> world;
	string prefixSpacing = "";

	world.push_back(prefixSpacing + "<sdf version='1.4'>");
	world.push_back(prefixSpacing + "   <world name='testWorld'>");

	//	Basic world requirements
	world.splice(world.end(), generateLight());
	world.splice(world.end(), generateWorldPhysics());
	world.splice(world.end(), generateScene());
	world.splice(world.end(), generateSphericalCoordinates());
	world.splice(world.end(), generateGUI());

	//	Add existing models


	//	Generate new models
	world.splice(world.end(), generateGrassPlane());
	world.splice(world.end(), generateStraightRoad(50.0, 7.0, 3.14159/4));

	world.push_back(prefixSpacing + "   </world>");
	world.push_back(prefixSpacing + "</sdf>");

	return world;
}

list<string> XMLGen::generateModel()
{
	list<string> model;
	return model;
}

list<string> XMLGen::generateLink()
{
	list<string> link;

	//	collision
	//	visual
	//	velocity decay
	//	self_collide
	//	kinematic
	//	gravity
	

	return link;
}

list<string> XMLGen::generateLight()
{
	list<string> light;
	string prefixSpacing = "      ";

	light.push_back(prefixSpacing + "<light name='sun' type='directional'>");

	//	cast_shadows
	light.push_back(prefixSpacing + "   <cast_shadows>1</cast_shadows>");

	//	pose
	light.push_back(prefixSpacing + "   <pose>0 0 10   0 0 0</pose>");
	
	//	diffuse
	light.push_back(prefixSpacing + "   <diffuse>0.8 0.8 0.8 1</diffuse>");

	//	specular
	light.push_back(prefixSpacing + "   <specular>0.2 0.2 0.2 1</specular>");

	//	attenuation
	light.push_back(prefixSpacing + "   <attenuation>");
	light.push_back(prefixSpacing + "      <range>1000</range>");
	light.push_back(prefixSpacing + "      <constant>0.9</constant>");
	light.push_back(prefixSpacing + "      <linear>0.01</linear>");
	light.push_back(prefixSpacing + "      <quadratic>0.001</quadratic>");
	light.push_back(prefixSpacing + "   </attenuation>");

	//	direction
	light.push_back(prefixSpacing + "   <direction>-0.5 0.1 -0.9</direction>");

	light.push_back(prefixSpacing + "</light>");

	return light;
}

list<string> XMLGen::generateWorldPhysics()
{
	list<string> physics;
	string prefixSpacing = "      ";

	//	type
	physics.push_back(prefixSpacing + "<physics type='ode'>");

	//	max step size
	physics.push_back(prefixSpacing + "   <max_step_size>0.001</max_step_size>");

	//	real time factor
	physics.push_back(prefixSpacing + "   <real_time_factor>1</real_time_factor>");
	
	//	real time update rate
	physics.push_back(prefixSpacing + "   <real_time_update_rate>1000</real_time_update_rate>");
	
	//	gravity
	physics.push_back(prefixSpacing + "   <gravity>0 0 -9.8</gravity>");


	physics.push_back(prefixSpacing + "</physics>");

	return physics;
}

list<string> XMLGen::generateScene()
{
	list<string> scene;
	string prefixSpacing = "      ";

	scene.push_back(prefixSpacing + "<scene>");

	//	ambient
	scene.push_back(prefixSpacing + "   <ambient>0.4 0.4 0.4 1</ambient>");

	//	background
	scene.push_back(prefixSpacing + "   <background>0.7 0.7 0.7 1</background>");

	//	sky
	scene.push_back(prefixSpacing + "   <sky>");
	scene.push_back(prefixSpacing + "      <time>12</time>");
	scene.push_back(prefixSpacing + "      <clouds>");
	scene.push_back(prefixSpacing + "      </clouds>");
	scene.push_back(prefixSpacing + "   </sky>");

	//	shadows
	scene.push_back(prefixSpacing + "   <shadows>1</shadows>");

	scene.push_back(prefixSpacing + "</scene>");

	return scene;
}

list<string> XMLGen::generateSphericalCoordinates()
{
	list<string> coordinates;
	string prefixSpacing = "      ";

	coordinates.push_back(prefixSpacing + "<spherical_coordinates>");

	//	surface model
	coordinates.push_back(prefixSpacing + "   <surface_model>EARTH_WGS84</surface_model>");

	//	latitutde deg
	coordinates.push_back(prefixSpacing + "   <latitude_deg>0</latitude_deg>");

	//	longitude deg
	coordinates.push_back(prefixSpacing + "   <longitude_deg>0</longitude_deg>");

	//	elevation
	coordinates.push_back(prefixSpacing + "   <elevation>0</elevation>");

	//	heading deg
	coordinates.push_back(prefixSpacing + "   <heading_deg>0</heading_deg>");

	coordinates.push_back(prefixSpacing + "</spherical_coordinates>");

	return coordinates;
}

list<string> XMLGen::generateState()
{
	list<string> state;

	//	sim time
	//	

	return state;
}

list<string> XMLGen::generateGUI()
{
	list<string> gui;
	string prefixSpacing = "      ";

	gui.push_back(prefixSpacing + "<gui fullscreen='0'>");
	
	//	camera
	gui.push_back(prefixSpacing + "   <camera name='user_camera'>");
	gui.push_back(prefixSpacing + "      <pose>0 0 5  0 0.25 0.25</pose>");
	gui.push_back(prefixSpacing + "      <view_controller>orbit</view_controller>");
	gui.push_back(prefixSpacing + "   </camera>");

	gui.push_back(prefixSpacing + "</gui>");

	return gui;
}

list<string> XMLGen::generateGeometry()
{
	list<string> geometry;
	return geometry;
}

list<string> XMLGen::generateGrassPlane()
{
	list<string> road;
	string prefixSpacing = "      ";

	road.push_back(prefixSpacing + "<model name='grassPlane'>");
	road.push_back(prefixSpacing + "   <static>1</static>");

	road.push_back(prefixSpacing + "   <link name='roadLink_1'>");

	//	Collision
	road.push_back(prefixSpacing + "      <collision name='collision'>");
	road.push_back(prefixSpacing + "         <geometry>");
	road.push_back(prefixSpacing + "            <plane>");
	road.push_back(prefixSpacing + "               <normal>0 0 1</normal>");
	road.push_back(prefixSpacing + "               <size>100 100</size>");
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
	road.push_back(prefixSpacing + "               <size>100 100</size>");
	road.push_back(prefixSpacing + "            </plane>");
	road.push_back(prefixSpacing + "         </geometry>");
	road.push_back(prefixSpacing + "         <material>");
	road.push_back(prefixSpacing + "            <script>");
	road.push_back(prefixSpacing + "               <uri>file://media/materials/scripts/gazebo.material</uri>");
	road.push_back(prefixSpacing + "               <name>Gazebo/Green</name>");
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

	road.push_back(prefixSpacing + "</model>");


	return road;
}

list<string> XMLGen::generateStraightRoad(double length, double width, double angle)
{
	list<string> road;
	string prefixSpacing = "      ";

	road.push_back(prefixSpacing + "<model name='straightRoad'>");
	road.push_back(prefixSpacing + "   <static>1</static>");

	road.push_back(prefixSpacing + "   <link name='roadLink_1'>");

	//	pose: start at origin
	road.push_back(prefixSpacing + "   <pose>" + to_string(width / 2) + " " + to_string(length / 2) + " 0.1  0 0 " + to_string(angle) + "</pose>");
	

	//	Collision
	road.push_back(prefixSpacing + "      <collision name='collision'>");
	road.push_back(prefixSpacing + "         <geometry>");
	road.push_back(prefixSpacing + "            <plane>");
	road.push_back(prefixSpacing + "               <normal>0 0 1</normal>");
	road.push_back(prefixSpacing + "               <size>" + to_string(width) + " " + to_string(length) + "</size>");
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
	road.push_back(prefixSpacing + "               <size>" + to_string(width) + " " + to_string(length) + "</size>");
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

	road.push_back(prefixSpacing + "</model>");


	return road;
}

list<string> XMLGen::generateStraightRoad()
{
	list<string> road;
	string prefixSpacing = "      ";

	road.push_back(prefixSpacing + "<model name='straightRoad'>");
	road.push_back(prefixSpacing + "   <static>1</static>");
	
	road.push_back(prefixSpacing + "   <link name='roadLink_1'>");
	road.push_back(prefixSpacing + "   <pose>0 0 0.1  0 0 0</pose>");

	//	Collision
	road.push_back(prefixSpacing + "      <collision name='collision'>");
	road.push_back(prefixSpacing + "         <geometry>");
	road.push_back(prefixSpacing + "            <plane>");
	road.push_back(prefixSpacing + "               <normal>0 0 1</normal>");
	road.push_back(prefixSpacing + "               <size>10 100</size>");
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
	road.push_back(prefixSpacing + "               <size>10 100</size>");
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

	road.push_back(prefixSpacing + "</model>");


	return road;
}



void XMLGen::writeToFile(list<string> textToWrite, string filename)
{
	ofstream outputFile(filename, ofstream::out);

	for (string line : textToWrite)
	{
		outputFile << line << endl;
	}

	outputFile.flush();
	outputFile.close();
}
