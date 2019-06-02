#ifndef ITEMMANAGER_H // Purpose: See if header file (Item.h) has been included before by checking whether or the symbol "Item_H" has been defined
#define ITEMMANAGER_H // Purpose: Defines the "Item_H" symbol so the compiler can tell the this file has already been compiled

//General Includes
#include <string>

//Header File Includes

#include "Location.h"
#include "Item.h"

using namespace std;


class ItemManager {

public:
	ItemManager();
	//  Purpose: To create an ItemManager with no items.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: A new ItemManager is created containing no items.
	
	ItemManager(const string& game_name);
	//  Purpose: To create an ItemManager for a game with the
	//           specified name.
	//  Parameter(s):
	//    <1> game_name: The game name
	//  Precondition(s):
	//    <1> game_name != ""
	//  Returns: N/A
	//  Side Effect: A new ItemManager is created with the items for the game with name game_name.  All the items are placed at their respective starting locations.

	ItemManager(const ItemManager& to_copy);
	//  Purpose: To create an ItemManager as a copy of another
	//           ItemManager.
	//  Parameter(s):
	//    <1> to_copy: The ItemManager to copy
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: A new ItemManager is created with copies of the items in to_copy.

	~ItemManager();
	//  Purpose: To safely destroy an ItemManager without memory
	//           leaks.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: All dynamically allocated memeory associated with this ItemManager is freed.

	ItemManager& operator= (const ItemManager& to_copy);
	//  Purpose: To modify this ItemManager to be a copy of another
	//           ItemManager.
	//  Parameter(s):
	//    <1> to_copy: The ItemManager to copy
	//  Precondition(s): N/A
	//  Returns: A reference to this ItemManager.
	//  Side Effect: The items in this ItemManager are removed and replaced with copies of the items in to_copy.

	int getScore() const;
	//  Purpose: To determine if the player score.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: The current player score.
	//  Side Effect: N/A

	void printAtLocation(const Location& location) const;
	//  Purpose: To print all items in the player invenrtory.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Returns: The description for each item in the player inventory is printed.
	
	void printInventory()const;
	//  Purpose: To print all items at the specified node.
	//  Parameter(s):
	//    <1> location: The location
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Returns: The description for each item at node location is printed.

	bool isInInventory(char id) const;
	//  Purpose: To determine if the item with the specified id is
	//           in the player invenrtory.
	//  Parameter(s):
	//    <1> id: The item id
	//  Precondition(s): N/A
	//  Returns: Whether the item with id id is in the player inventory.  If there is no such item, false is returned.
	//  Side Effect: N/A

	void reset();
	//  Purpose: To reset all items.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: All items are moved to their respective starting locations.

	void take(char id, const Location& player_location);

	//           assuming that the player is at the specified
	//           location.
	//  Parameter(s):
	//    <1> id: The item id
	//    <2> player_location: The player location
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: If there is an item with id id location player_location, that item is moved to the player inventory.  Otherwise, a message is printed.

	void leave(char id, const Location& player_location);
	//  Purpose: To attempt to leave the item with the specified id,
	//           assuming that the player is at the specified
	//           location.
	//  Parameter(s):
	//    <1> id: The item id
	//    <2> player_location: The player location
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: If there is an item with id id in the player inventory, that item is moved to location player_location.  Otherwise, a message is printed.


private:
	void load(const string& fliename);
	//  Purpose: To load the items for this ItemManager from the
	//           specified file.
	//  Parameter(s):
	//    <1> filename: The file name
	//  Precondition(s):
	//    <1> filename != ""
	//    <2> items == nullptr
	//  Returns: N/A
	//  Side Effect: The items in file filename are loaded into this ItemManager.

	unsigned int find(char id) const;
	//  Purpose: To determine the index of the item with the specified id.
	//  Parameter(s):
	//    <1> id: The item id
	//  Precondition(s): N/A
	//  Returns: The index of the item with id id.  If there is no such item, NO_SUCH_ITEM (a hidden constant) is returned.  If there is more than one such item, the index of any one of them might be returned.
	//  Side Effect: N/A

	void sort();
	//  Purpose: To sort the items in this ItemManager specified id.
	//  Parameter(s): N/A
	//  Precondition(s):
	//    <1> items == nullptr
	//  Returns: N/A
	//  Side Effect: The items in this ItemManager are sorted.

	bool invariant() const;
	//  Purpose: To determine if the class invariant is true.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: Whether the class invariant is true.
	//  Side Effect: N/A




	// Array
	Item* itemsArrayD;

	// Constants
	unsigned int item_count;
};

#endif // Purpose: End of ifndef statement

