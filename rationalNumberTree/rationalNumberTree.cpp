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
		cout << problemType << endl;
		if(problemType == 1){
			findElement.clear();
			p = 1;
			q = 1;
			dataFile >> n;
			cout << n << endl;
			while(n != 1){
				findElement.push_back(n % 2 ? true : false);
				n = n / 2;
			}
			for(int i = 0; i < findElement.size(); ++i){
				p = findElement[i] ? p + q : p;
				q = findElement[i] ? p - q : p + q;
			}
			resultFile << "Case #" << caseNumber << ": " << p << " " << q << endl;
		}
		else{
			n = 1;
			dataFile >> p >> q;
			cout << p << " " << q << endl;
			while(p > 1 || q > 1){
				cout << p << " " << q << endl;
				n = p > q ? n * 2 + 1 : n * 2;
				p = p > q ? p - q : p;
				q = p > q ? q : q - p;
			}
			resultFile << "Case #" << caseNumber << ": " << n << endl;
		}
	}
	return 0;
}