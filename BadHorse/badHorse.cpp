#include<iostream>
#include<map>
#include<string>
#include<fstream>

using namespace std;

int main(){
	int caseCount;
	int caseNumber;
	int pairsCount;
	int pairNumber;
	string person1;
	string person2;
	map<string, bool> group1;
	map<string, bool> group2;
	ifstream dataFile("A-small-practice-1.in");
	ofstream resultFile("A-small-practice-1.out");
	dataFile >> caseCount;
	for(caseNumber = 1; caseNumber <= caseCount; ++caseNumber){
		dataFile >> pairsCount;
		for(pairNumber = 0; pairNumber < pairsCount; ++pairNumber){
			dataFile >> person1 >> person2;
			cout << person1 << " and " << person2 << endl;
			if(group1.find(person2) == group1.end() && group2.find(person1) == group2.end()){
				group1[person1] = true;
				group2[person2] = true;
				continue;
			}
			if(group1.find(person1) == group2.end() && group2.find(person2) == group1.end()){
				group1[person2] = true;
				group2[person1] = true;
				continue;
			}
			resultFile << "Case #" << caseNumber << ": NO" << endl;
			break;
		}
		if(pairNumber == pairsCount){
			resultFile << "Case #" << caseNumber << ": YES" << endl;
		}
		while(++pairNumber < pairsCount){
			dataFile >> person1 >> person2;
		}
		group1.clear();
		group2.clear();
	}
}