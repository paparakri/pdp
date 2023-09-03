/* USER: u023
LANG: C++
TASK: astrolavos */
#include <fstream>
using namespace std;

float roundUp(float n1){
	int n2 = n1/0.001;
	float number = n2*0.001;
	return number;
}

float findTurns(int gear1, float gear1_turns, int currentGear){
	float multpl = gear1 * gear1_turns;
	float turns = multpl/currentGear;
	return turns;
}

int main(){
	//Variables
	ifstream infile;
	infile.open("/Users/alexandrospapakribopoulos/Desktop/PDP/A_Fasi/astrolavos.in");
	int l;
	infile >> l;
	float m[l];
	int kn[6];
	float results[5];
	for(int i = 0; i < l; i++){
		infile >> m[i];
	}
	for(int i = 0; i < 6; i++){
		infile >> kn[i];
	}

	//Main Code
	for(int i = 0; i < l; i++){
		for(int j = 1; j < 6; j++){
			if(i == kn[j]-1){
				results[j-1] = findTurns(m[0], kn[0], m[i]);
			}
		}
	}
	
	//Output
	float result;
	float scale = 0.001;
	ofstream outFile;
	outFile.open("/Users/alexandrospapakribopoulos/Desktop/PDP/A_Fasi/astrolavos.out");
	for(int i = 0; i < 5; i++){
		result = roundUp(results[i]);
		outFile << result << " ";
	}
	return 0;
}