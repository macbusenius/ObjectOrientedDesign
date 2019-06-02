// Mckenzie Busenius
// SID - 200378076
// Course Section - 002
// Lab Section - 096

//General Includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cassert>

//Header File Includes
#include "Location.h"
#include "World.h"
#include "Item.h"
#include "ItemManager.h"
#include "Game.h"
#include "Highscore.h"

using namespace std;

void doEndScore(const Game& game, const string& player_name);

// Games

/*Static const string GAME_NAME = "blizzard";
string gameName1 = Blizzard;
*/
/*
static const string GAME_NAME = "ghostwood";
string gameName2 = "Ghostwood";
*/

static const string GAME_NAME = "jungle";
string gameName3 = "Jungle";


// Start of main function
int main()
{
	Game game(GAME_NAME);
	// Game Introductions

	/*
	// Blizzard Valey

	cout << "Welcome to Blizzard Valley!" << endl;
	cout << "You and six children were hiking in the mountians when an" << endl;
	cout << "unexpected blizzard blew up.  Find the six children and get them" << endl;
	cout << "all back to the hiking lodge on the other side of the river." << endl;

	// GhostWood

	cout << "Welcome to Ghostwood Manor!" << endl;
	cout << "There are rumors of treasure in the old haunted house but many who venture in never come out again." << endl << endl;
*/

	// Jungle
	cout << "Welcome to Jungle Quest!";
	cout << "You recently obtained an old treasure map in mysterious" << endl;
	cout << "circumstances.It showed the location of the Lost Jewel of" << endl;
	cout << "Leopold II, evil king of the Congo Free State.And since you" << endl;
	cout << "have always wanted to be more like Indiana Jones, you have" << endl;
	cout << "mounted an expedition to find it." << endl << endl;


	// Pre Game Instructions
	cout << "The Basic Commands are:" << endl;
	cout << "N, S, E, W or n, s, e, w - To move in that direction." << endl;
	cout << "T or t - Take the item that is at your possition. " << endl;
	cout << "L or l - Leave an item at current position." << endl;
	cout << "I or i - Print what is currently in your inventory." << endl;
	cout << "Q or q - Quit the game at any time." << endl << endl;

	// User Information
	cout << "Please Enter your Name" << endl;
	string userName;
	getline(cin, userName);

	cout << endl;
	cout << "Hello, " << userName << endl << "Welcome to the game " << gameName3 << endl << endl;

	game.printDescription();
	cout << endl;

	// Main Loop
	string userInput;
	char userLetter = ' ';
	bool is_quit = false;

	//Start of Main Loop
	while (!is_quit && !game.isOver()) {
		cout << "Next? ";

		// must get some input!
		do {
			getline(cin, userInput);
		}
		
		while (userInput == "");

		char command = userInput[0];

		if (userInput == "") {
			userLetter = ' ';
		}

		else
			userLetter = userInput[0];

		if (userLetter == ' ') {
			cout << "Invalled Expresstion" << endl;
		}

		else if ((userLetter == 'q') || (userLetter == 'Q')) {
			cout << "Are you sure you want to quit? " << endl;
			getline(cin, userInput);

			if ((userInput != "") && ((userInput[0] == 'y') || (userInput[0] == 'Y'))) {
				break;
			}

			doEndScore(game, userName);
			cout << endl;
		}

		else if ((userLetter == 't') || (userLetter == 'T')) {
			cout << "Take what? ";
			getline(cin, userInput);

			if (userInput != "")
				game.takeItem(userInput[0]);
			else
				cout << "Invalid Item." << endl;
		}

		else if ((userLetter == 'l') || (userLetter == 'L')) {
			cout << "Leave What? ";
			getline(cin, userInput);

			if (userInput != "")
				game.leaveItem(userInput[0]);
			else
				cout << "Invalid Item." << endl;
		}

		else if ((userLetter == 'i') || (userLetter == 'I')) {
			game.printInventory();
		}

		else if ((userLetter == 'r') || (userLetter == 'R')) {
			cout << "Are you sure you want to restart? ";
			getline(cin, userInput);

			if (userInput != "" && userInput[0] == 'y')
			{
				doEndScore(game, userName);
				cout << endl;
				game.reset();
				game.printDescription();
			}
		}

		// Directional Player Moves
		else if ((userLetter == 'N') || (userLetter == 'n')) {
			game.moveNorth();
		}

		else if ((userLetter == 'E') || (userLetter == 'e')) {
			game.moveEast();
		}

		else if ((userLetter == 'S') || (userLetter == 's')) {
			game.moveSouth();
		}

		else if ((userLetter == 'W') || (userLetter == 'w')) {
			game.moveWest();
		}

		else
			cout << "Invaled Entry!" << endl << endl;
		cout << endl;


	}// End of While loop

	doEndScore(game, userName);
	cout << endl;


	// Ending Message
	//cout << "Thank you for playing" << gameName1 << endl << endl;
	//cout << "Thank you for playing" << gameName2 << endl << endl;
	cout << "Thank you for playing" << " " << gameName3 << endl << endl;

} // End of main Function


void doEndScore(const Game& game, const string& player_name) {
	cout << endl;
	cout << "In this game you scored " << game.getScore() << " points." << endl;

	HighScore high_scores(GAME_NAME);
	high_scores.insert(game.getScore(), player_name);
	high_scores.save(GAME_NAME);
	high_scores.print();
	cout << endl;
}