/******************************************************************************
# Author: Andy Joy, Lucy Price          
# Assignment: Discussion 5             
# Date: 11/04/2026            
# Description: This program takes a text file of different majors, their
#              associated salaries, and the number of men and women that work in
#              each. It prints into a new file, the percentages of men and women
#              in each field and the one with the highest and lowest salary.     
# Input: no user input, just file input.         
# Output: no output, just writing into a new file.         
# Sources: zybooks, discussion 5 resources.      
#******************************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAXCHAR = 101;

// function prototypes
bool openFile(ifstream &inFile, string fileName);
void ratioCalc(ifstream& inFile, ofstream& outFile);
void minMaxSalaryCalc(ifstream& inFile, ofstream& outFile);

// main
int main() {
  ifstream inFile;
 
  if (!openFile(inFile, "stem.txt")) {
    cout << "File did not open. Program terminating!!!" << endl;
    return 1;
  }
  
  ofstream outFile;
  outFile.open("stemout.txt");
    
  if (!outFile.is_open()) {
    cout << "Could not open file stemout.txt." << endl;
    return 1;
  }
  ratioCalc(inFile, outFile);
  minMaxSalaryCalc(inFile, outFile);
 
  inFile.close();
  outFile.close();
  
  return 0;
}

// function to open file
// returns true if file opens
// returns false if file does not open for any reason
// parameters: file stream variable by reference and fileName
bool openFile(ifstream &inFile, string fileName) {
  inFile.open(fileName);
  if (!inFile) {
    return false;
  }
  return true;
}

// write the ratioCalc function below this
void ratioCalc(ifstream& inFile, ofstream& outFile){
  double totalCount = 0;
  double menCount = 0;
  double womenCount = 0;
    
  char majorName [MAXCHAR];
  char strDiscard[MAXCHAR];
  int intDiscard;
  double percentMen = 0.0;
  double percentWomen = 0.0;
  
  inFile.ignore(200, '\n');
  while (!inFile.eof()){
    inFile >> intDiscard >> majorName >> strDiscard >> totalCount >> menCount >> womenCount >> intDiscard;
        
    percentMen = (menCount / totalCount) * 100;
    percentWomen = (womenCount / totalCount) * 100;
        
    outFile << fixed << setprecision(2) << majorName << " " << percentMen << "% " << percentWomen << "%" << endl;
  }
  inFile.clear();
	inFile.seekg(0);
}

void minMaxSalaryCalc(ifstream& inFile, ofstream& outFile) {
  int salary = 0;
  int salaryMin = 0;
  int salaryMax = 0;

  char majorName [MAXCHAR];
  char minMajorName [MAXCHAR];
  char maxMajorName [MAXCHAR];

  char strDiscard[MAXCHAR];
  int intDiscard;

  inFile.ignore(200, '\n');
  inFile >> intDiscard >> majorName >> strDiscard >> intDiscard >> intDiscard >> intDiscard >> salary;
  salaryMin = salary;
  strcpy(minMajorName, majorName);
  salaryMax = salary;
  strcpy(maxMajorName, majorName);
  
  while (!inFile.eof()){
    inFile >> intDiscard >> majorName >> strDiscard >> intDiscard >> intDiscard >> intDiscard >> salary;

    if (salary < salaryMin) {
      salaryMin = salary;
      strcpy(minMajorName, majorName);
    }
    if (salary > salaryMax) {
      salaryMax = salary;
      strcpy(maxMajorName, majorName);
    }
  }
  outFile << "\nThe major with the highest salary is " << maxMajorName << " at " << salaryMax << "$ per year." << endl;
  outFile << "\nThe major with the lowest salary is " << minMajorName << " at " << salaryMin << "$ per year." << endl;

  inFile.clear();
	inFile.seekg(0);
}