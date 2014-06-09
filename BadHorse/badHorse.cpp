#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;

enum Groups {Unreached ,Group1, Group2};

class TroublesomePairs{
private:
	map<string, vector<string> > pairsGraph;
	map<string, int> personStatus;
	struct Person{
		string name;
		int status;
		Person(string n) : name(n), status(Unreached){}
	};

public:
	TroublesomePairs(){

	}

	~TroublesomePairs(){

	}

public:
	void addRelation(string person1, string person2){
		personStatus[person1] = Unreached;
		personStatus[person2] = Unreached;

		if(pairsGraph.find(person1) != pairsGraph.end()){
			pairsGraph[person1].push_back(person2);
		}
		else{
			vector<string> relations;
			relations.push_back(person2);
			pairsGraph[person1] = relations;
		}
		if(pairsGraph.find(person2) != pairsGraph.end()){
			pairsGraph[person2].push_back(person1);
		}
		else{
			vector<string> relations;
			relations.push_back(person1);
			pairsGraph[person2] = relations;
		}
	}

	bool isBepartetable(){
		map<string, vector<string> >::iterator root = pairsGraph.begin();
		string curPerson;
		int curStatus = Group2;
		queue<string> q;
		q.push(root->first);
		q.push("flag");
		personStatus[root->first] = Group1;
		while(!q.empty()){
			curPerson = q.front();
			cout << curPerson << endl;
			q.pop();
			if(curPerson == "flag"){
				curStatus = curStatus == Group1 ? Group2 : Group1;
				if(q.empty()){
					return true;
				}
				q.push("flag");
			}
			for(int i = 0; i < pairsGraph[curPerson].size(); ++i){
				if(personStatus[pairsGraph[curPerson][i]] == Unreached){
					personStatus[pairsGraph[curPerson][i]] = curStatus;
					q.push(pairsGraph[curPerson][i]);
				}
				else if(personStatus[pairsGraph[curPerson][i]] != curStatus){
					return false;
				}
			}
		}
	}

	void clearData(){
		pairsGraph.clear();
		personStatus.clear();
	}
};

int main(){
	int caseCount;
	int caseNumber;
	int pairsCount;
	int pairNumber;
	string person1;
	string person2;
	TroublesomePairs tp;
	string result;

	ifstream dataFile("A-small-practice-2.in");
	ofstream resultFile("A-small-practice-2.out");
	dataFile >> caseCount;

	for(caseNumber = 1; caseNumber <= caseCount; ++caseNumber){
		dataFile >> pairsCount;
		for(pairNumber = 0; pairNumber < pairsCount; ++pairNumber){
			dataFile >> person1 >> person2;
			tp.addRelation(person1, person2);
		}
		result = tp.isBepartetable() ? "YES" : "NO";
		resultFile << "Case #" << caseNumber << ": " << result << endl;
		tp.clearData();
	}
}