#include<iostream>
#include<fstream>
#include<map>
#include<vector>

using namespace std;
enum Position{LEFT, RIGHT};

int main(){
	ifstream dataFile("B-large-practice.in");
	ofstream resultFile("B-large-practice.out");

	int caseCount;
	int caseNumber;
	int problemType;
	int64_t n;
	int64_t p, q;
	vector<bool> findElement;
	vector<bool> findPos;

	dataFile >> caseCount;
	for(caseNumber = 1; caseNumber <= caseCount; ++caseNumber){
		dataFile >> problemType;
		if(problemType == 1){			
			p = 1;
			q = 1;
			findElement.clear();
			dataFile >> n;
			while(n != 1){
				findElement.push_back(n % 2 == 0 ? LEFT : RIGHT);
				n = (n >> 1);
				cout << n << endl;
			}
			for(int i = findElement.size() - 1; i >= 0; --i){
				if(findElement[i] == LEFT){
					q = p + q;
				}
				else{
					p = p + q;
				}
			}
			resultFile << "Case #" << caseNumber << ": " << p << " " << q << endl;
		}
		else{
			n = 1;
			findPos.clear();
			dataFile >> p >> q;
			while(p != 1 || q != 1){
				findPos.push_back(p > q ? RIGHT : LEFT);
				if(p > q){
					p = p - q;
				}
				else{
					q = q - p;
				}
			}
			for(int i = findPos.size() - 1; i >= 0; --i){
				cout << n << endl;
				if(findPos[i] == LEFT){
					n = (n << 1);
				}
				else{
					n = (n << 1) + 1;
				}
				cout << n << endl;
			}
			resultFile << "Case #" << caseNumber << ": " << n << endl;
		}
	}
	return 0;
}