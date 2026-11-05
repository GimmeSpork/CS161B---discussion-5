/******************************************************************************
# Author:           Lucy P
# Lab:              Assignment 8
# Date:             May 31, 2021
# Description:      calculates your numeric and letter grade from given 
#                   assignment scores, midterm exam score, and final exam score.
# Input:            numAssigns as int, numScore as double, 
# Output:           decimalGrade as double, letterGrade as char, prompt as string.
# Sources:          zybooks, assignment 7 and 8 resources.
#******************************************************************************/
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// display constant variables
const double ASSIGNMENT_WEIGHT = 0.6;
const double EXAM_WEIGHT = 0.2;

// display function prototypes
void welcome();
void readScore(string prompt, double &num);
void getInput(double &midtermScore, double &finalExamScore);
void calcLetterGrade(double finalScore, char &letter);

int readInt(string prompt);

double getScoreInRange(string prompt);
double assignAverage(int numAssigns);
double calcFinalScore(double assignAvg, double midterm, double final);

// start main function
int main() {
  welcome();

  double assignAvg = 0.0;
  double midtermExamScore = 0.0;
  double finalExamScore = 0.0;
  double finalScore;

  int numberOfAssignments = 0;
  bool next = true;
  while(next) {
    numberOfAssignments = readInt("Enter the number of assignments (0 to 10): ");
    if(0 <= numberOfAssignments 
       and 
       numberOfAssignments <= 10) {
      next = false;
    } else {
      cout << "Illegal Value! Please try again!!" << endl;
    }
  }

  assignAvg = assignAverage(numberOfAssignments);
  getInput(midtermExamScore, finalExamScore);

  cout << fixed << setprecision(1);
  double decimalGrade = calcFinalScore(assignAvg, midtermExamScore, finalExamScore);
  cout << "\nYour Final Numeric score is " << decimalGrade << endl;

  char letter = '\0';
  calcLetterGrade(decimalGrade, letter);
  cout << "Your Final Grade is " << letter << endl;

  cout << "\nThank you for using my Grade Calculator!" << endl;

  return 0;
}

// welcome function
void welcome() {
  cout << "Welcome to the Grade Calculation Program!" << endl;
  cout << "Please enter the following information and I will calculate your" << endl;
  cout << "Final Numerical Grade and Letter Grade for you!" << endl;
  cout << "The number of assignments must be between 0 and 10." << endl;
  cout << "All scores entered must be between 0 and 4." << endl;
  cout << endl;
}

// read number of assignments
int readInt(string prompt) {
   int numAssigns = 0;
   bool next = true;
    
   while (next) {
      cout << prompt;
      cin >> numAssigns;
      if (cin && numAssigns >= 0) {
            next = false;
      } else {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  return numAssigns;
}

// read assignment scores
void readScore(string prompt, double &num) {
  bool next = true;
    
  while (next) {
      cout << prompt;
      cin >> num;
      if (cin) {
          next = false;
      } else {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
  }
}

// check scores are in proper range
double getScoreInRange(string prompt) {
    double score = 0.0;
    bool next = true;
    double num;
    while(next) {
      readScore(prompt, num);
      score = num;
      if(0.0 <= score and score <= 4.0) {
        next = false;
      } else {
        cout << "Illegal Score! Please try again!" << endl;
      }
    }
    return score;
}

// assign averages
double assignAverage(int numAssigns) {
  double sum = 0.0;
  double avg = 0.0;

  for(int i = 1; i <= numAssigns; i++) {
    string promptScore = "Enter score " + to_string(i) + ": ";
    double score = getScoreInRange(promptScore);
    sum += score;
  }
  avg = sum / numAssigns;
  return avg;
}

void getInput(double &midtermExamScore, double &finalExamScore) {
  midtermExamScore = getScoreInRange("\nEnter your midterm exam score: ");
  finalExamScore = getScoreInRange("Enter your final exam score: ");
}

// calculate final score numeric
double calcFinalScore(double assignAvg, double midterm, double final){
  double finalScore = 0.0;
  finalScore += assignAvg * ASSIGNMENT_WEIGHT;
  finalScore += midterm * EXAM_WEIGHT;
  finalScore += final * EXAM_WEIGHT;
  return finalScore;
}

// calculate final letter grade
void calcLetterGrade(double finalScore, char &letter){
  if(finalScore >= 3.3) {
    letter = 'A';
  } else if(finalScore >= 2.8) {
    letter = 'B';
  } else if(finalScore >= 2.0) {
    letter = 'C';
  } else if(finalScore >= 1.2) {
    letter = 'D';
  } else {
    letter = 'F';
  }
}
