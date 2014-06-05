#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void getPatterns(vector<int> &patterns, const string pattern){
	patterns.clear();
	int number = 0;
	for(int i = 0; i < pattern.length(); ++i){
		if(pattern[i] == '-'){
			patterns.push_back(number);
			number = 0;
		}
		else{
			number = number * 10 + (pattern[i] - '0');
		}
	}
	patterns.push_back(number);
}

void generateResult(string &readResult, int charCount, char number){
	int count = 1;
	switch(charCount){
	case 2:
		readResult.append(" double");
		break;
	case 3:
		readResult.append(" triple");
		break;
	case 4:
		readResult.append(" quadruple");
		break;
	case 5:
		readResult.append(" quintuple");
		break;
	case 6:
		readResult.append(" sextuple");
		break;
	case 7:
		readResult.append(" septuple");
		break;
	case 8:
		readResult.append(" octuple");
		break;
	case 9:
		readResult.append(" nonuple");
		break;
	case 10:
		readResult.append(" decuple");
		break;
	default:
		count = charCount;
		break;
	}
	// cout << charCount << endl;
	for(int i = 0; i < count; ++i){
		switch(number - '0'){
		case 0:
			readResult.append(" zero");
			break;
		case 1:
			readResult.append(" one");
			break;
		case 2:
			readResult.append(" two");
			break;
		case 3:
			readResult.append(" three");
			break;
		case 4:
			readResult.append(" four");
			break;
		case 5:
			readResult.append(" five");
			break;
		case 6:
			readResult.append(" six");
			break;
		case 7:
			readResult.append(" seven");
			break;
		case 8:
			readResult.append(" eight");
			break;
		case 9:
			readResult.append(" nine");
			break;
		}
	}	
}

int main(){
	ifstream dataFile("A-large-practice.in");
	ofstream resultFile("A-large-practice.out");

	int caseCount;
	vector<int> patterns;
	int patternsIndex;
	int numberLength;
	char preChar;
	int charCount;
	string phoneNumber;
	string pattern;
	string readResult;

	dataFile >> caseCount;
	for(int caseNumber = 1; caseNumber <= caseCount; ++caseNumber){
		readResult.erase();
		dataFile >> phoneNumber >> pattern;
		patternsIndex = 0;
		numberLength = phoneNumber.length();
		getPatterns(patterns, pattern);
		preChar = phoneNumber[0];
		charCount = 1;
		for(int j = 1; j <= numberLength; ++j){
			--patterns[patternsIndex];
			if(patterns[patternsIndex] == 0){
				generateResult(readResult, charCount, preChar);
				++patternsIndex;
				preChar = phoneNumber[j];
				charCount = 1;
				continue;
			}
			if(phoneNumber[j] != preChar){
				generateResult(readResult, charCount, preChar);
				preChar = phoneNumber[j];
				charCount = 1;
				continue;
			}
			++charCount;
		}
		resultFile << "Case #" << caseNumber << ":" << readResult << endl;
	}
	return 0;
}