#include<iostream>
using namespace std;
#include<string>
int main() {
	string food[7];
	cout << "Favorite Food.?" << endl;
	for (int i = 0; i < 7; i++) {
		getline(cin, food[i]);
	}
	cout << "1: " << food[0] << endl;
	cout << "2: " << food[1] << endl;
	cout << "3: " << food[2] << endl;
	cout << "4: " << food[3] << endl;
	cout << "5: " << food[4] << endl;
	cout << "6: " << food[5] << endl;
	cout << "7: " << food[6] << endl;
}