#include<iostream>
#include<fstream>
#include<map>
#include<vector>

using namespace std;

int main(){
	ifstream dataFile("B-small-practice.in");
	ofstream resultFile("B-small-practice.out");

	int caseCount;
	int caseNumber;
	int problemType;
	int n;
	int p, q;
	vector<bool> findElement;
	map<int, vector<int> > findPos;

	dataFile >> caseCount;
	for(caseNumber = 1; caseNumber <= caseCount; ++caseNumber){
		dataFile >> problemType;
		if(problemType == 1){
			findElement.clear()
			dataFile >> n;
			while(n != 1){
				findElement.push_back(n % 2 ? true : false);
				n = n / 2;
			}
		}
	}
	return 0;
}