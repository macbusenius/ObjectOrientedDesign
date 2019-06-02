
#ifndef ITEM_H // Purpose: See if header file (Item.h) has been included before by checking whether or the symbol "Item_H" has been defined
#define ITEM_H // Purpose: Defines the "Item_H" symbol so the compiler can tell the this file has already been compiled

//General Includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cassert>

//Header File Includes
#include "Location.h"

using namespace std;

class Item {
public:
	Item();
	//  Default Constructor
	//  Purpose: To create an Item with default values.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: A new Item is created with an id of ID_NOT_INITIALIZED, with starting and current locations of (0, 0), with a points value of 0, and with error messages for descriptions.

	void debugPrint() const;
	//  debugPrint
	//  Purpose: To display the state of this Item.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The values for this Item are printed.


	bool isInitialized() const;
	//  isInitialized
	//  Purpose: To determine whether this Item has been initialized.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: Whether this Item has been initialized.
	//  Side Effect: N/A


	char getId() const;
	//  getId
	//  Purpose: To determine the id of this Item.
	//  Parameter(s): N/A
	//  Precondition(s):
	//    <1> isInitialized()
	//  Returns: The id of this Item.
	//  Side Effect: N/A


	bool isInInventory() const;
	//  isInInventory
	//  Purpose: To determine whether this Item is in the player inventory.
	//  Parameter(s): N/A
	//  Precondition(s):
	//    <1> isInitialized()
	//  Returns: Whether this Item is in the player inventory.
	//  Side Effect: N/A


	bool isAtLocation(const Location& location) const;
	//  isAtLocation
	//  Purpose: To determine whether this Item is at the specified
	//           location.
	//  Parameter(s):
	//    <1> location: The location to check
	//  Precondition(s):
	//    <1> isInitialized()
	//  Returns: Whether this Item is in at location location.
	//  Side Effect: N/A


	int getPlayerPoints() const;
	//  getPlayerPoints
	//  Purpose: To determine how many points this Item is currently worth to the player.
	//  Parameter(s): N/A
	//  Precondition(s):
	//    <1> isInitialized()
	//  Returns: How many points this Item is worth to the player at
	//           present.
	//  Side Effect: N/A


	void printDescription() const;
	//  printDescription
	//  Purpose: To print the current description for this Item.
	//  Parameter(s): N/A
	//  Precondition(s):
	//    <1> isInitialized()
	//  Returns: N/A
	//  Side Effect: The current description for this Item is printed.


	bool operator< (const Item& other) const;
	//  Less Than Operator
	//  Purpose: To determine whether this Item should be sorted
	//           before the specified Item.
	//  Parameter(s):
	//    <1> other: The Item to compare to
	//  Precondition(s):
	//    <1> isInitialized()
	//    <1> other.isInitialized()
	//  Returns: Whether this Item should be before Item item.
	//  Side Effect: N/A


	void init(char id1, const Location& location, int points1, const std::string& world_description1, const std::string& inventory_description1);

	//  itemInit
	//  Purpose: To initialize the specified Item with the specified values.
	//  Parameter(s):
	//    <1> id1: The id for the item
	//    <2> start1: The starting location
	//    <3> points1: How many points the item is worth
	//    <4> world_description1: The description of the item when it is at a location in the world
	//    <5> inventory_description1: The description of the item when it is in the player inventory
	//  Precondition(s):
	//    <1> id1 != ID_NOT_INITIALIZED
	//    <2> world_description1 != ""
	//    <3> inventory_description1 != ""
	//  Returns: N/A
	//  Side Effect: Item item is initialized.


	void reset();
	//  reset
	//  Purpose: To reset this Item.
	//  Parameter(s): N/A
	//  Precondition(s):
	//    <1> isInitialized()
	//  Returns: N/A
	//  Side Effect: This Item is moved to its starting location.


	void moveToInventory();
	//  moveToInventory
	//  Purpose: To move this Item to the player inventory.
	//  Parameter(s): N/A
	//  Precondition(s):
	//    <1> isInitialized()
	//  Returns: N/A
	//  Side Effect: This Item is moved to the player inventory.


	void moveToLocation(const Location& location);
	//  moveToLocation
	//  Purpose: To move this Item to the specified location.
	//  Parameter(s):
	//    <1> location: The new Location
	//  Precondition(s):
	//    <1> isInitialized()
	//  Returns: N/A
	//  Side Effect: This Item is moved to location location.




private:
	bool invariant() const;
	//  invariant
	//  Purpose: To determine if the class invariant is true.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: Whether the class invarint is true.
	//  Side Effect: N/A


	char id;
	Location start;
	Location current;
	bool is_in_inventory;
	int points;
	string world_description;
	string inventory_description;
};


#endif // Purpose: End of ifndef statement

