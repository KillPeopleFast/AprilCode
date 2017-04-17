#include <iostream>
#include <stdlib.h> 
#include <math.h>
#include <ctime>
using namespace std;
int main() {
	int num;
	int num3;
	int num2;
	int num4;
	int s1;
	int s2;
	int s3;
	int pp;
	int aa;
	int s;
	srand(time(NULL));
	int randomNum = rand() % 20 + (-10);
	int randomNumm = rand() % 20 + (-10);
	cout << "your number is" << randomNum << "," << randomNumm << endl;
	cout << "Entr coordinateees 4 teh 2nd point" << endl;
	cin >> num >> num3;
	cout << "gimmie yo numaba 2" << endl;
	cin >> num2 >> num4;

	s1 = sqrt((randomNum - num)*(randomNum - num) + (randomNumm - num3)*(randomNumm - num3));
	s2 = sqrt((randomNum - num2)*(randomNum - num2) + (randomNumm - num4)*(randomNumm - num4));
	s3 = sqrt((num - num2)*(num - num2) + (num3 - num4)*(num3 - num4));

	pp = s1 + s2 + s3;

	s = s1 + s2 + s3 / 2;
	aa = sqrt(s*(s - s1)*(s - s2)*(s - s3));
	cout << "YOUR P.P. IS THIS LONG:" << pp << endl;
	cout << "The area is " << aa << endl;

}