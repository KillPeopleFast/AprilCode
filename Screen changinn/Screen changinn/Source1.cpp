#include<iostream>
#include<Windows.h>
#include<MMSystem.h>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;

void colorchange();//declaration
				   //function declaration
int main() {
	srand(static_cast<unsigned int>(time(0)));//what does this do?

	int health = 100;
	bool gameover = false;
	string input;
	string items[5];//creates an array to hold your items
	int room = 11;
	//introduction
	cout << "Welcome to the creation that is, Game." << endl;
	cout << "Yes, I know what you're thinking...Game? Not a very creative name." << endl;
	cout << "That my freind is not.." << endl;
	cout << "A lie! This is truly trash" << endl;
	cout << "Enjoy :D" << endl;
	cout << "Rules: " << endl;
	cout << "everytime you give a response, it will always be in lower case unless posted otherwise" << endl;
	cout << "Have Fun" << endl;
	cout << "Or don't, there is no pressure..." << endl << endl << endl << endl << endl;
	while ((input != "quit") && (gameover == false)) {//game loop
													  //system("pause");//pauses game
													  //cout<<"type i to see your inventory"<<endl;
		switch (room) {
		case 1:
			cout << "You're in the Hallway." << endl;
			cout << "You can go through the east door." << endl << endl;
			PlaySound(TEXT("2crow.wav"), NULL, SND_FILENAME);
			getline(cin, input);
			if (input.compare("east") == 0)
				room = 2;
			else if (input.compare("Go Cubs!") == 0)
				room = 11;
			else if (input.compare("Cubs Suck!") == 0)
				room = 20;
			break;

		case 2:
			cout << "The room is white with padded walls." << endl;
			cout << "There is desk with one drawer that is colored black, while the others are white." << endl;
			cout << "Shall we open the drawer, go west, or south.?" << endl << endl;
			getline(cin, input);
			if (input.compare("drawer") == 0) {
				if (items[3].compare("key") != 0) {//check that they DONT have the key
					cout << "You found a key!!" << endl;
					cout << "type key to pick up the key" << endl;
				}
				else
					cout << "the drawer is empty. you can go west or south" << endl;
				getline(cin, input);
				if (input.compare("key") == 0)
					if (items[3].compare("key") == 0)//does have the key
						cout << "you have already gotten the key.." << endl;
					else if (items[3].compare("key") != 0) {
						items[3] = "key";//put a key in slot three of your items array
						cout << "you got the key" << endl;
						cout << "You can go west or south" << endl << endl;
					}

			}
			else if (items[3].compare("key") != 0)//don't have the key
				cout << "Foo' open the drawer" << endl;

			if (input.compare("west") == 0) {
				room = 1;
			}
			else if (input.compare("south") == 0)
				room = 3;
			break;
		case 3:
			cout << "" << endl;
			cout << "A mysterious box rests in the left corner of the room, open?" << endl;
			cout << "You can go north or east" << endl << endl;
			getline(cin, input);

			if (input.compare("open") == 0) {
				if (items[2].compare("Bouncy Ball") != 0) {//dont have ball??
					cout << "There is a bouncy ball!" << endl;
					cout << "Type ball to pick up the ball, go North or East." << endl;
				}
				else
					cout << "The box is empty..." << endl;


				cout << "You can go North or East." << endl << endl;
				getline(cin, input);


				if (input.compare("ball") == 0)
					if (items[2].compare("Bouncy Ball") == 0)//does have the ball
						cout << "You already have the Glorious Ball!!" << endl;
					else if (items[2].compare("Bouncy Ball") != 0) {
						items[2] = "Bouncy Ball";//put a ball in slot two of your items array
						cout << "You have the Ball!!" << endl;
						cout << "You can go North or East" << endl << endl;
					}
			}
			else if (items[2].compare("Bouncy Ball") != 0)//don't have the ball
				cout << "Foo' open the Box" << endl;

			if (input.compare("north") == 0) {
				room = 2;
			}
			else if (input.compare("east") == 0)
				room = 4;
			break;

		case 4:
			cout << "There is a locked door before you, unlock, or go back west." << endl << endl;
			getline(cin, input);
			if (input.compare("unlock") == 0) {
				if (items[3].compare("key") == 0) {
					cout << "You unlock the door" << endl;
					room = 5;
				}
			}
			else if (input.compare("west") == 0)
				room = 3;
			break;

		case 5:
			cout << "Appears to be an abandon childs playroom..." << endl;
			cout << "You can go North or South." << endl << endl;
			if (items[2].compare("Bouncy Ball") == 0) {
				cout << "Do you want to bounce the ball?" << endl;
			}
			getline(cin, input);
			if (input.compare("bounce") == 0)
				cout << "*Bounce*" << endl;
			else if (input.compare("south") == 0)
				room = 6;
			break;

		case 6:
			cout << "Before you is a singular chest surrounded by nothing back a dimly lit room." << endl;
			cout << "Would you like to open the chest? (open)" << endl;
			cout << "You can go North or West." << endl;
			getline(cin, input);
			if (input.compare("west") == 0)
				room = 7;
			else if (input.compare("north") == 0)
				room = 5;

			else if (input.compare("open") == 0) {
				if (items[1].compare("Buster Sword") != 0) {//dont have sword??
					items[1] = "Buster Sword";//put a sword in slot two of your items array

					cout << "Cloud's buster sword sits before you in the chest. It is now yours.." << endl;
					cout << "You can go North or West" << endl << endl;
					if (items[1].compare("Buster Sword") == 0) {
						cout << "The box is empty..." << endl;
					}
				}

			}


			break;

		case 7:

			cout << "A glass chandelier hangs above you that is noticably loose." << endl;
			cout << "The room appears fancy and well kept." << endl;
			cout << "Aside from the neat furniture and beautiful layout, there sits a Jack in the Box" << endl;
			cout << "You can go West, East, or play with the 'Jack in the Box'." << endl;
			getline(cin, input);
			if (input.compare("west") == 0) {
				room = 8;
			}
			if (input.compare("east") == 0) {
				room = 6;
			}

			if (input.compare("Jack in the Box") == 0) {
				cout << "slowly or fast..;)" << endl;
			}

			if ((input.compare("slowly") == 0)) {
				srand((NULL));

				PlaySound(TEXT("jack_in_the_box-Mike_Koenig-710345321.wav"), NULL, SND_FILENAME);
				int num = rand() % 100 + 1;
				if (num>50) {
					PlaySound(TEXT("explosion_x.wav"), NULL, SND_FILENAME);
					cout << "The chandelier falls on you and YOU DIED!!!!!!!!!" << endl;
					colorchange();//function call

					health = health - 100;

				}
			}



			else if (!input.compare("fast")) {
				srand((NULL));
				PlaySound(TEXT("jack_in_the_box_fast-Mike_Koenig-1288903495.wav"), NULL, SND_FILENAME);
				cout << "The chandelier falls on you and YOU DIED!!!!!!!!!" << endl;
				PlaySound(TEXT("explosion_x.wav"), NULL, SND_FILENAME);
				colorchange();//function call
				room = 20;



			}
			break;

		case 8:
			cout << "Garden Room" << endl;
			cout << "There seems to be an enless amount of gardening tools, plows, dirt, and the" << endl;
			cout << "necessary things for gardening and making pretty flowers" << endl;
			cout << "However, there are no grown flowers..." << endl;
			cout << "You can go North or East." << endl;
			getline(cin, input);
			if (input.compare("north") == 0) {
				room = 9;
			}
			else if (input.compare("east") == 0)
				room = 7;

			break;

		case 9:
			cout << "The room is pitch dark." << endl;
			cout << "You must feel around to find the next exit." << endl << "(feel around)" << endl;
			cout << "Or you can go back South." << endl;
			getline(cin, input);
			if (input.compare("feel around") == 0) {
				cout << "OUCH!" << endl;
				cout << "You fell into a pit!" << endl;
				room = 10;
			}
			else if (input.compare("south") == 0)
				room = 8;

			break;

		case 10:
			cout << "A tall vicious monster awaits you.!!" << endl;
			cout << "\"Are you ready to bow down to my wrath\"" << endl;
			cout << "\"Or would you rather scamper away, you pesky child.\"" << endl;
			cout << "You can run or fight." << endl;
			getline(cin, input);

			if (input.compare("south") == 0)
				room = 9;
			else if (input.compare("fight") == 0) {
				if (items[1].compare("Buster Sword") != 0) {
					cout << "\"You don't have anything to fight with!!\"" << endl;
					cout << "The tall monster kills you." << endl;
					room = 20;
				}
				if (items[1].compare("Buster Sword") == 0) {
					cout << "You defeat the monster with the Buster sword" << endl;
					cout << "btw cloud is awesome" << endl;
					room = 11;
				}
			}
			else if (input.compare("run") == 0)
				room = 9;
			break;
		case 11:
			colorchange();
			cout << "                           YOU WIN!!!                    " << endl;
			cout << "Thank you for playing!!!" << endl;
			cout << "I hope you enjoyed my first game" << endl;
			cout << "It was fun creating it and if you at least semi liked this" << endl;
			cout << "There will be more in the future" << endl;
			cout << "Would you like to play again?" << endl;
			getline(cin, input);
			if (input.compare("yes") == 0)
				room = 1;
			else if (input.compare("no") == 0)
				room = 20;
			break;

			//Death Room
		case 20:
			for (int i = 0; i < 20; i++) {
				cout << "******************************************************************" << endl;
				cout << "                            GAME OVER                             " << endl;
				cout << "******************************************************************" << endl;
				colorchange();
			}
			gameover = true;

		}//switch

	}///gameloop
}///main


 /////if (items[3].compare("key")


void colorchange() {//definition

	system("COLOR 4f");

	system("COLOR 1f");

	system("COLOR 2f");

	system("COLOR 6f");
}