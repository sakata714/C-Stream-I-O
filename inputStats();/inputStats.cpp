#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

// Line 1 has 5 (longest =11)
// Line 2 has 8 (longest =6)
// Line 3 has 6 (longest =6)
// Line 4 has 3 (longest =14)
// Longest line: the jaws the bite, the claws that catch,

void tokenStats(ifstream& infile, ofstream& outfile)
{
    string line, token, longLine;
    int numTokens, longTokenLen, lineNum = 0;

    while(getline(infile, line))
    {
      lineNum++;
      numTokens = 0;
      longTokenLen = 0;

      stringstream s(line);

      if (line.length()>= longLine.length())
      {
        longLine = line;
      }

      while(s >> token)
      {
        numTokens++;
        if (token.length() > longTokenLen)
        {
          longTokenLen = token.length();
        }
      }
      outfile << "Line " << lineNum << " has " 
        << numTokens << " (longest = " << longTokenLen << ")" << endl;
    }
    outfile << "Longest line: " << longLine;
    infile.close();
    outfile.close();
}

int main()
{
  string inFilename = "input.txt", outFilename = "output.txt";
  ifstream infile(inFilename.c_str());
  ofstream outfile(outFilename.c_str());
  if(infile.fail())
  {
    cout << "ERROR: could not open input file " << inFilename << endl;
    return 1;
  }

tokenStats(infile, outfile);

return 0;
}
