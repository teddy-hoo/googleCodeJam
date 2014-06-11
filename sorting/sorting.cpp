#include<iostream>
#include<fstream>
#include<map>
#include<vector>

using namespace std;
enum order{increasing, decreasing};

bool compare(int valuePre, int valueAft, bool order){
	if(order){
		return valuePre > valueAft;
	}
	else{
		return valuePre < valueAft;
	}
}

void swap(int &valuePre, int &valueAft){
	int tmp;
	tmp = valuePre;
	valuePre = valueAft;
	valueAft = tmp;
}

void quickSort(vector<int> &values, vector<int> &positions, int left, int right, bool order){
	int begin = left;
	int end = right;
    int pivot = values[positions[(begin + end) / 2]];

    while(begin <= end) {
        while(compare(values[positions[begin]], pivot, order)){
        	++begin;       	
        }            
        while(compare(pivot, values[positions[end]], order)){
        	--end;
        }
        if(begin <= end) {
        	swap(values[positions[begin]], values[positions[end]]);
            begin++;
            end--;
        }
    }
    if(left < end){
        quickSort(values, positions, left, end, order);
    }
    if(begin < right){
    	quickSort(values, positions, begin, right, order);
    }
}

int main(){
	ifstream dataFile("C-large-practice.in");
	ofstream resultFile("C-large-practice.out");

	int caseNumber;
	int caseCount;
	int bookCount;
	int price;
	int index;
	vector<int> books;
	vector<int> bookOfBob;
	vector<int> bookOfAlex;

	dataFile >> caseCount;
	for(caseNumber = 1; caseNumber <= caseCount; ++caseNumber){
		cout << caseNumber << endl;
		dataFile >> bookCount;
		books.clear();
		bookOfBob.clear();
		bookOfAlex.clear();
		for(index = 0; index < bookCount; ++index){
			dataFile >> price;
			books.push_back(price);
			if(price % 2 == 1 || price % 2 == -1){
				bookOfAlex.push_back(index);
			}
			else{
				bookOfBob.push_back(index);
			}
		}
		if(bookOfBob.size()){
			quickSort(books, bookOfBob, 0, bookOfBob.size() - 1, decreasing);
		}
		if(bookOfAlex.size()){
			quickSort(books, bookOfAlex, 0, bookOfAlex.size() - 1, increasing);
		}		
		resultFile << "Case #" << caseNumber << ":";
		for(index = 0; index < bookCount; ++index){
			resultFile << " " << books[index];
		}
		resultFile << endl;
	}
	return 0;
}