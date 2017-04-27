#include<iostream>
#include<ctime>
using namespace std;
void colorchange();//declaration
int main() {
	srand(static_cast<unsigned int>(time(0)));
	while (1) {


		colorchange();
	}
}

void colorchange() {//definition
	int num = rand() % 100 + 1;
	if (num <= 25){
		system("COLOR 10");
		//system("pause");
		cout << num;
}
	else if (num >= 26 && num <= 50) {
		system("COLOR 20");
		//system("pause");
		cout << num;
	}
	else if (num >= 50 && num <= 100) {

		system("COLOR 40");
		cout << num;
		
		//system("pause");
	}
}
/*
0 = Black
1 = Blue
2 = Green
3 = Aqua
4 = Red
5 = Purple
6 = Yellow
7 = White
8 = Gray
9 = Light Blue
A = Light Green
B = Light Aqua
C = Light Red
D = Light Purple
E = Light Yellow
F = Bright White
*/

