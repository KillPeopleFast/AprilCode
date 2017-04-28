#include<iostream>
using namespace std;
double nuke(double attack, double orb);
int main() {
	double attack;
	double orb;
	cout << "how much damage are you using" << endl;
	cin >> attack;
	cout << "orb amount?" << endl;
	cin >> orb;
	cout << nuke(attack, orb);
}
double nuke(double attack, double orb) {
	double nuke = (attack * (1 + (0.3 * orb))) + 3000;
	return nuke;
}