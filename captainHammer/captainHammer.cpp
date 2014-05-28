#include<iostream>
#include<fstream>
#include<iomanip>
#include<math.h>
#include<stdio.h>

#define G 9.8
const double PI = acos(-1.0);

using namespace std;

void main(){
	ifstream dataFile("B-small-practice.in");
	ofstream resultFile("B-small-practice.out");
	double velocity;
	double distance;
	double theta;
	double ans;
	int caseCount;
	dataFile >> caseCount;
	cout.precision(5);
	for(int caseNumber = 1; caseNumber <= caseCount; ++caseNumber){
		dataFile >> velocity >> distance;
		ans = asin(distance * G / velocity / velocity) / 2;
		theta = ans / PI * 180;
		resultFile << "Case #" << caseNumber << ": " << fixed << setprecision(8) << theta << endl;
	}
}