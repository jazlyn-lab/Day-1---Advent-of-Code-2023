#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
#include <cctype> // For isdigit()
using namespace std;


// Add the caliberation values from each line in the input
int addCalibValues(const vector<string>&lines)
{
  int sum = 0;

  // Loop through each line in the input
  for(int i = 0; i < lines.size(); i++)
    {
      string line = lines[i];
      char digitFirst = '\0';
      char digitLast = '\0';

      // Find the first digit in the line
      for( int j = 0; j < line.size(); j++)
        {
          if(isdigit(line[j]))
          {
            digitFirst = line[j];
            break; // Stop loop when first digit is found
          }
        }

      // Find the last digit in the line
      for (int j = line.size() - 1; j >= 0; j--)
        {
          if (isdigit(line[j]))
          {
            digitLast = line[j];
            break; // Stop loop when last digit is found
          }
        }
      
      // Convert the digits to integers and add them to the sum

      if (digitFirst != '\0' && digitLast != '\0')
      {
        int calibValue = (digitFirst - '0') * 10 + (digitLast - '0');
        sum += calibValue;
        
      }
      
    }

  return sum;
  
}

int main()
{
  // Open the input file
  ifstream inputFile("values.txt");
  if(!inputFile)
  {
    cerr << "Error opening input file." << endl;
    return 1;
  }

  // Read the lines from the input file and store into a vector
  vector<string> lines;
  string line; 

  while(getline(inputFile, line))
    {
      lines.push_back(line);
    }

  inputFile.close();

  // Calculate the sum of calibration values
  int result = addCalibValues(lines);

  cout << "Summ of al calibration values: " << result << endl;

  return 0; 
}