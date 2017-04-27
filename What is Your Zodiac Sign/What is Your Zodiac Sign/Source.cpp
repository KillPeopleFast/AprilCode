#include<iostream>
using namespace std;
bool Horoscope (int num);
int main() {
	int input;
	cout << "What's your zodiac sign?" << endl;
	cout << "1) From January 20th - Feburary 18th " << endl;
	cout << "2) From Feburary 19th - March 20th " << endl;
	cout << "3) From March 20th - April 19th " << endl;
	cout << "4) From April 20th - May 20th " << endl;
	cout << "5) From May 21st - June 20th " << endl;
	cout << "6) From June 21th - July 22nd " << endl;
	cout << "7) From July 23rd - August 22nd " << endl;
	cout << "8) From August 23rd - September 22nd " << endl;
	cout << "9) From September 23rd - Obtober 22 " << endl;
	cout << "10) From October 23rd - November 21st " << endl;
	cout << "11) From November 22nd - December 21 " << endl;
	cout << "12) From December 22nd - Janurary 19th " << endl;
	cin >> input;
	if (Horoscope(input) == true)
		cout << "Happy Birthday Month!" << endl;
}
bool Horoscope(int num) {
	
	switch (num) {
	case 1:
		cout << "From January 20th - Feburary 18th is Aquarius" << endl;
		break;
	case 2:
		cout << "From Feburary 19th - March 20th is Pisces" << endl;
		return 0;
		break;
	case 3:
		cout << "From March 20th - April 19th is Aries" << endl;
		return 0;
		break;
	case 4:
		cout << "From April 20th - May 20th is Taurus" << endl;
		
		return 1;
		break;
	case 5:
		cout << "From May 21st - June 20th is Gemini" << endl;
		return 0;
		break;
	case 6:
		cout << "From June 21th - July 22nd is Cancer" << endl;
		return 0;
		break;
	case 7:
		cout << "From July 23rd - August 22nd is Leo" << endl;
		return 0;
		break;
	case 8:
		cout << "From August 23rd - September 22nd is Virgo" << endl;
		return 0;
		break;
	case 9:
		cout << "From September 23rd - Obtober 22 is Libra" << endl;
		return 0;
		break;
	case 10:
		cout << "From October 23rd - November 21st is Scorpio" << endl;
		return 0;
		break;
	case 11:

		cout << "From November 22nd - December 21 is Sagittarius" << endl;
		return 0;
		break;
	case 12:
		cout << "From December 22nd - Janurary 19th is Capricorn" << endl;
		return 0;
		break;

	}
	
}