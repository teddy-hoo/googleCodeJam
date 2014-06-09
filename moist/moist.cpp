#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool needMove(string name1, string name2){
	int index1;
	int index2;
	for(index1 = 0, index2 = 0; index1 < name1.length() && index2 < name2.length(); ++index1, ++index2){
		if(name1[index1] > name2[index2]){
			return true;
		}
		if(name1[index1] < name2[index2]){
			return false;
		}
	}
	if(index2 == name2.length()){
		return true;
	}
	return false;
}

void main(){
	int caseCount;
	int nameCount;
	int caseNumber;
	int nameNumber;
	int cost;
	string name;
	string lastName;

	ifstream dataFile("C-small-practice-2.in");
	ofstream resultFile("C-small-practice-2.out");

	dataFile >> caseCount;
	for(caseNumber = 1; caseNumber <= caseCount; ++caseNumber){
		cost = 0;
		dataFile >> nameCount;
		getline(dataFile, lastName);
		getline(dataFile, lastName);
		for(nameNumber = 1; nameNumber < nameCount; ++nameNumber){
			getline(dataFile, name);
			cout << lastName << endl;
			cout << name << endl;
			if(needMove(lastName, name)){
				++cost;
			}
			else{
				lastName = name;
			}
			cout << cost << endl;
		}
		resultFile << "Case #" << caseNumber << ": " << cost << endl;
	}
}