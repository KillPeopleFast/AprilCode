#include<iostream>
using namespace std;
double damage(double level, double attack, double defense, double power, double modifier);
int main() {
	double level;
	double attack;
	double defense;
	double power;
	double modifier;
	cout << " Give me level, attack, defense, power, modifier." << endl;
	cin >> level;
	cin >> attack;
	cin >> defense;
	cin >> power;
	cin >> modifier;

	cout << " PIKA TOOK " << damage(level, attack, defense, power, modifier) << endl;
}
double damage(double level, double attack, double defense, double power, double modifier) {
	
	double damage = (((2 * level) / 5 + 2)* power * attack / defense / 50 + 2)* modifier;
	return damage;
}