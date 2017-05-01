#include<iostream>
using namespace std;
#include<ctime>
int main() {
	int skills[7];
	srand(static_cast<unsigned int>(time(0)));



		for (int i = 0; i < 7; i++){

			int num = rand() % 10 + 1;
			skills[i] = num;
			cout << skills[i] << endl;
		}
		
	
}