#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ifstream dataFile("B-small-practice.in");
	ofstream resultFile("B-small-practice.out");

	int caseCount;
	int caseNumber;
	int problemType;
	int n;
	int p, q;

	dataFile >> caseCount;
	for(caseNumber = 1; caseNumber <= caseCount; ++caseNumber){
		dataFile >> problemType;
		if(problemType == 1){
			
		}
	}
	return 0;
}