#include <fstream>
using namespace std;

float roundUp(float n1){
	int n2 = n1/0.001;
	if(n2%10 > 4){
		n2++;
	}
	float num = n2*0.001;
	return num;
}

int main(){
	//Variables
	ifstream inFile;
	inFile.open("profit.txt");
	int N;
	inFile >> N;
	int X[N];
	for(int i = 0; i < N; i++){
		inFile >> X[i];
	}
	
	//Main Code
	float profit_counter = (float)X[0]/(float)X[0];
	for(int i = 0; i < N; i++){
		for(int j = i; j < N; j++){
			if((float)X[j]/(float)X[i] > profit_counter){
				profit_counter = (float)X[j]/(float)X[i];
			}
		}
	}
	float profit = roundUp(profit_counter);
	
	//Output
	ofstream outFile;
	outFile.open("profit_out.txt");
	outFile << profit;
	
	return 0;
}