#include <stdio.h>
using namespace std;

//Sunday=0
//Monday=1
//Tuesday=2
//Wednesday=3
//Thursday=4
//Friday=5
//Saturday=6

struct date{
	int	day;
	int month;
	int year;
};

int day = 2; // 1st January 1901 => Thursday

int main(){
	int cnt=0;
	
	date test = {0,0,1901};
	
	while(test.day != 30 || test.month != 11 || test.year != 2000){
		if(day == 0 && test.day == 0) cnt++; 
		printf("%d %d %d\n", test.day, test.month, test.year);
		if(test.month == 8 || test.month == 3 || test.month == 5 || test.month == 10){
			test.year += test.month/12;
			test.month = (test.month+test.day / 30) % 12;
			test.day = (test.day+1) % 30;
			
			
		}
		
		if(test.month == 0 || test.month == 2 || test.month == 4 || test.month == 6 || test.month == 7 || test.month == 9 || test.month == 11){
			test.year += test.month/12;
			test.month = (test.month+test.day / 31) % 12;
			test.day = (test.day+1) % 31;
		}
		if(test.month == 1){
			if(test.year%4){
				test.year += test.month/12;
				test.month = (test.month+test.day / 29) % 12;
				test.day = (test.day+1) % 29;
			}
			else {
				test.year += test.month/12;
				test.month = (test.month+test.day / 28) % 12;
				test.day = (test.day+1) % 28;
			}
		}
		
		day=(day+1)%7;
	}
	
	printf("%d", cnt);
	
	return 0;
}
