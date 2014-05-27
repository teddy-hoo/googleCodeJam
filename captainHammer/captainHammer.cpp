#include<iostream>
#include<fstream>
#include<iomanip>
#include<math.h>
#include<stdio.h>

#define PI 3.14159265
#define G 9.8

using namespace std;

void main(){
	ifstream dataFile("B-small-practice.in");
	ofstream resultFile("B-small-practice.out");
	double velocity;
	double distance;
	double theta;
	int caseCount;
	dataFile >> caseCount;
	cout.precision(5);
	for(int caseNumber = 1; caseNumber <= caseCount; ++caseNumber){
		dataFile >> velocity >> distance;
		theta = asin(distance * G / (2 * velocity * velocity)) * 180.0 / PI;
		resultFile << "Case #" << caseNumber << ": " << ios::fixed << setprecision(6) << theta << endl;
	}
}