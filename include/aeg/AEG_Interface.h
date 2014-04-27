/*************************

   AEG_Interface.h

**************************/

#ifndef _AEG_INTERFACE_H_
#define _AEG_INTERFACE_H_

#include <string>
#include <list>

using namespace std;

class AEG_Interface
{
   public:
      int main(int argc, char** argv);

   private:
      /*--------------------------------
       *   Properties
       *--------------------------------*/

      /*--------------------------------
       *   Properties
       *--------------------------------*/

      // Print the command line description
      void printOptions();

      // Concatenate user input into a single string
      string getConcatLowerInput(int argc, char** argv);

      // retrieve terrain list from user input
      list<string> getTerrain(string userInput);

      // check if user specified path continuity
      bool isContinuous(string userInput);

      // check if help command specified
      bool getHelpState(string userInput);

      // retrieve road length if specified
      double getRoadLength(string userInput);
};

#endif
