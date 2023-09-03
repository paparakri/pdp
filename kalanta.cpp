/* USER: u023
LANG: C++
TASK: kalanta */ 
#include <fstream>
#include <algorithm>
using namespace std;


int main(){
	ifstream fin;
	fin.open("kalanta.in");
	ofstream fout;
	fout.open("kalanta.out");

	long int totalSum = 0;
	long int houses;
	fin >> houses;
	int moneyPerHouse[houses];
	for(long int i=0; bi<houses; i++){
		fin >> moneyPerHouse[i];
		totalSum += moneyPerHouse[i];
	}
	
	long int kid2 = moneyPerHouse[houses-1];
	long int kid1 = totalSum - kid2;
	long int difference = max(kid1,kid2) - min(kid2,kid1);
	long int minDifference = difference;
	long int i = 1;
	long int j = 0;
	
	while(i < houses && j < houses){
		if (kid2 > kid1){
			kid1 = kid1 + moneyPerHouse[houses-1-j];
			kid2 = totalSum - kid1;
			j++;
		}
		else{
			kid2 = kid2 + moneyPerHouse[houses-1-i];
			kid1 = totalSum - kid2;
			i++;
		}
		difference = max(kid1,kid2) - min(kid2,kid1);
		if(difference < minDifference){
			minDifference = difference;
		}
	}
	fout << minDifference;
}
