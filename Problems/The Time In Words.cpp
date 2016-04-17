#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int hourWrapAround(int hour){ //only pass in the hours that need to be wrapped around
	return (hour+1) % 12;
}

int minuteWrapAround(int minute){	//only pass in the minutes that need to be wrapped around
	return (60 - minute);
}

string hour(int hh){
	switch(hh){
		case 1:
			return "one";
		case 2:
			return "two";
		case 3:
			return "three";
		case 4:
			return "four";
		case 5:
			return "five";
		case 6:
			return "six";
		case 7:
			return "seven";
		case 8:
			return "eight";
		case 9:
			return "nine";
		case 10:
			return "ten";
		case 11:
			return "eleven";
		case 12:
			return "twelve";
		default:
			return NULL;
	}
}

string minute(int mm){
	switch(mm){
		case 1:
			return "one";
		case 2:
			return "two";
		case 3:
			return "three";
		case 4:
			return "four";
		case 5:
			return "five";
		case 6:
			return "six";
		case 7:
			return "seven";
		case 8:
			return "eight";
		case 9:
			return "nine";
		case 10:
			return "ten";
		case 11:
			return "eleven";
		case 12:
			return "twelve";
		case 13:
			return "thirteen";
		case 14:
			return "fourteen";
		case 15:	//Quarter
			return "quarter";
		case 16:
			return "sixteen";
		case 17:
			return "seventeen";
		case 18:
			return "eighteen";
		case 19:
			return "nineteen";
		case 20:
			return "twenty";
		case 21:
			return "twenty one";
		case 22:
			return "twenty two";
		case 23:
			return "twenty three";
		case 24:
			return "twenty four";
		case 25:
			return "twenty five";
		case 26:
			return "twenty six";
		case 27:
			return "twenty seven";
		case 28:
			return "twenty eight";
		case 29:
			return "twenty nine";
		default:
			return NULL;
	}
}

int main(){
    int h;
    int m;
    cin >> h;
    cin >> m;

	string hh;
	string mm;
	if(m == 0){	//00 will be concatenated as 0 on int
		hh = hour(h);
		cout << hh << " o' clock" << endl;
	}
	else{
		if(m == 30){	//Half
			hh = hour(h);
			cout << "half past " << hh << endl;
		}
		else if(m < 30){	// mm past hh
			hh = hour(h);
			mm = minute(m);
			if(m == 1){	//"minute"
				cout << mm << " minute past " << hh;
			}
			else if(m == 15 || m == 45){	//"quarter"
				cout << mm << " past " << hh;
			}
			else{	//"minutes"
				cout << mm << " minutes past " << hh;	
			}
		}
		else{	// 60-mm to hh+1
			h = hourWrapAround(h);
			hh = hour(h);
			m = minuteWrapAround(m);
			mm = minute(m);
			if(m == 1){	//"minute"
				cout << mm << " minute to " << hh;
			}
			else if(m == 15 || m == 45){	//"quarter"
				cout << mm << " to " << hh;
			}
			else{	//"minutes"
				cout << mm << " minutes to " << hh;	
			}
		}
	}
    return 0;
}
