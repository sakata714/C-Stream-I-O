#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;

void coinFlip(ifstream& infile, ofstream& outfile)
{
  string line, token;
  int countT = 0;
  double percent;

  while(getline(infile, line))
  {
    percent = 0.0;
    
    int linelen = line.length();
    int sumH = 0;
    int sumT = 0;
    double totalH;
    double totalT;
    
    if (line.find('H') || line.find('h'))
    {
      for (int i = 0; i < linelen; i++)
      {
        char a = line.at(i);
        if (a == 'H' || a == 'h')
        {
          sumH++;
        }
        else if (a == 'T' || a == 't')
        {
          sumT++;
        }
      }
      totalH = sumH;
      totalT = sumT;
     percent = ((totalH) / (totalT + totalH)) * 100; 
    }

    if (percent >= 100.0)
    {
      outfile << sumH << " heads (" << fixed << setprecision(1) 
        << percent << "%)" << "\n" << "You win!";
    }
    else if (percent > 50.0)
    {
      outfile << sumH << " heads (" << fixed << setprecision(1) 
        << percent << "%)" << "\n" << "You win!" << "\n" << "\n";
    }
    else
    {
      outfile << sumH << " heads (" << fixed << setprecision(1) 
        << percent << "%)" << "\n" << endl;
    }
  }
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

coinFlip(infile, outfile);

return 0;
}
