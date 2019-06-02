#ifndef GAME_H // Purpose: See if header file (Item.h) has been included before by checking whether or the symbol "Item_H" has been defined
#define GAME_H // Purpose: Defines the "Item_H" symbol so the compiler can tell the this file has already been compiled

//General Includes
#include <iostream>
#include <string>

//Header File Includes
#include "World.h"
#include "Location.h"
#include "ItemManager.h"
#include "Item.h"

using namespace std;

class Game {
public:
	Game(const string& game_name);
	bool isOver() const;
	int getScore() const;
	void printDescription() const;
	void printInventory() const;
	void reset();
	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();
	void takeItem(char id);
	void leaveItem(char id);

private:
	bool invariant() const;
	World world;
	ItemManager item_manager;
	Location player;
};


#endif // Purpose: End of ifndef statement
