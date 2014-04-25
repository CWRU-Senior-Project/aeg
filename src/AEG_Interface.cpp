#include "aeg/Run.h"
//#include "aeg/Test.h"
//#include "aeg/XMLGenerator.h"
#include <vector>
#include <algorithm>


// TODO: revise main program
int AEG_Interface::main(int argc, char** argv)
{
   printOptions();
  
   string inputLine = getConcatLowerInput(argc, argv);
   printf("Input line:\t%s\n\n", inputLine.c_str());

   double length = getRoadLength(inputLine);
   bool continuous = isContinuous(inputLine);
   list<string> terrainList = getTerrain(inputLine);

   printf("Length:\t%f\n", length);
   printf("Contin:\t%s\n", (continuous)?"true":"false");
   printf("List:\t%d\n", terrainList.size());

//   XMLGen testGen;
//   testGen.generateWorldFile();

//   AEGTester tester;
//   tester.testGenerateWorldFile();
   return 0;
}

string AEG_Interface::getConcatLowerInput(int argc, char** argv)
{
   stringstream ss;

   for (int i = 0; argc > i; i++)
   {
      ss << argv[i] << " ";
   }
   string inputLine = ss.str();
   transform(inputLine.begin(), inputLine.end(), inputLine.begin(), ::tolower);
  return inputLine;   
}

void AEG_Interface::printOptions()
{
   stringstream ss;

   ss << "\nAutomatic Environment Generator (AEG) for the DRC Sim\n";
   ss << "usage: AEG [-l=value|--length=value] [-t=<list>|--terrain=<list>] [-c|--continuous] [-h|--help]\n";
   ss << "\nDetails:\n";

   ss << "  length\tSpecify road length in meters\n";
   ss << "  terrain\tSpecify terrain elements by name in comma-separated list format. Unrecognized names will be ignored\n";
   ss << "  continuous\tSpecify that road should be a loop. Default is off\n";
   ss << "  help\t\tDisplays this message\n\n";

   printf(ss.str().c_str());
}

list<string> AEG_Interface::getTerrain(string userInput)
{
   list<string> terrainList;

   string labelStrings[] = { "--terrain=", "-t=" };
   vector<string> labels (labelStrings, labelStrings + sizeof(labelStrings) / sizeof(string));

   for (int i = 0; labels.size() > i; i++)
   {
      size_t found = userInput.find(labels[i]);

      if (string::npos != found)
      {
         // get value
         string delim = ",";
         size_t stringBreak = userInput.find(" ", found);
         string value = userInput.substr(found + labels[i].size(), stringBreak);

         // split by ',' and add to list
         size_t pos = 0;
         do
         {
            pos = value.find(delim);
            terrainList.push_back(value.substr(0, pos));
            value.erase(0, pos + delim.length());
         }
         while (string::npos != pos);
         
         break;
      }
   }

   return terrainList;
}

bool AEG_Interface::isContinuous(string userInput)
{
   bool continuous = false;

   string labelStrings[] = { "--continuous", "-c" };
   vector<string> labels (labelStrings, labelStrings + sizeof(labelStrings) / sizeof(string));

   for (int i = 0; labels.size() > i; i++)
   {
      size_t found = userInput.find(labels[i]);

      if (string::npos != found)
      {
         continuous = true;
         break;
      }
   }

   return continuous;
}

double AEG_Interface::getRoadLength(string userInput)
{
   double length = 50;

   string labelStrings[] = { "--length=", "-l=" };
   vector<string> labels (labelStrings, labelStrings + sizeof(labelStrings) / sizeof(string));

   for (int i = 0; labels.size() > i; i++)
   {
      size_t found = userInput.find(labels[i]);

      if (string::npos != found)
      {
         // get value
         size_t stringBreak = userInput.find(" ", found);
         string value = userInput.substr(found + labels[i].size(), stringBreak);

         // convert to double
         stringstream converter(value);
         converter >> length;
         break;
      }
   }

   return length;
}


