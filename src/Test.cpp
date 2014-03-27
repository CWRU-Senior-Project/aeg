#include "aeg/Test.h"

void AEGTester::testWriteToFile()
{
	cout << "Starting testWriteToFile now." << endl;

	list<string> lineList;
	lineList.push_back("first line");
	lineList.push_back("second line");
	lineList.push_back("third line");

	string filename = "TestWrite_01.txt";

	xmlGen.writeToFile(lineList, filename);

	cout << "Completed testWriteToFile." << endl;
}
void AEGTester::testGenerateWorldFile()
{
   cout << "Starting testWriteToFile now." << endl;
   xmlGen.generateWorldFile();
   cout << "Completed testWriteToFile." << endl;
}
