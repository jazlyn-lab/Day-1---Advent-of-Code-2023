//DAY 1.2 2023 ADVENT CALENDAR!

#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
#include <cctype> // For isdigit()
#include <unordered_map>
using namespace std;

// Function to convert spelled-out digits to numeric form
int convertSpelledDigit(const string& word) 
{

    // Map spelled-out digits to their numeric values
    unordered_map<string, int> spelledDigits = 
    {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };

    // If the word is a spelled-out digit return its numeric value
    if (spelledDigits.find(word) != spelledDigits.end()) 
    {
        return spelledDigits[word];
    }
    return -1; // Indicating the word is not a spelled-out digit
}

// Function to find the first and last digit (numeric or spelled-out) and calculate the calibration value
int addCalibValues(const vector<string>& lines) 
{
    int sum = 0;

    for (const string& line : lines) {
        int digitFirst = -1;
        int digitLast = -1;

        // Find the first digit (numeric or spelled-out) in the line
        for (size_t j = 0; j < line.size(); ++j) 
        {
            if (isdigit(line[j])) 
            {
                digitFirst = line[j] - '0';
                break;
            } else if (isalpha(line[j])) 
            {
                string word = "";
                for (size_t k = j; k < line.size() && isalpha(line[k]); ++k) {
                    word += line[k];
                    if (convertSpelledDigit(word) != -1) 
                    {
                        digitFirst = convertSpelledDigit(word);
                        break;
                    }
                }
                if (digitFirst != -1) break;
            }
        }

        // Find the last digit (numeric or spelled-out) in the line
        for (int j = static_cast<int>(line.size()) - 1; j >= 0; --j) {
            if (isdigit(line[j])) 
            {
                digitLast = line[j] - '0';
                break;
            } else if (isalpha(line[j])) 
            {
                string word = "";
                for (int k = j; k >= 0 && isalpha(line[k]); --k) {
                    word = line[k] + word;
                    if (convertSpelledDigit(word) != -1) 
                    {
                        digitLast = convertSpelledDigit(word);
                        break;
                    }
                }
                if (digitLast != -1) break;
            }
        }

        // Combine the digits to form the calibration value
        if (digitFirst != -1 && digitLast != -1) 
        {
            int calibValue = digitFirst * 10 + digitLast;
            sum += calibValue;
            cout << "Calibration: " << calibValue << endl; 
        }
    }

    return sum;
}


int main() {
    ifstream inputFile("values.txt");
    if (!inputFile) 
    {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    vector<string> lines;
    string line;

    while (getline(inputFile, line)) 
    {
        lines.push_back(line);
    }

    inputFile.close();

    int result = addCalibValues(lines);

    cout << "Sum of all calibration values: " << result << endl;

    return 0; 
}
