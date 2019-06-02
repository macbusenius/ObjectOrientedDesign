#ifndef NODE_H // Purpose: See if header file (Item.h) has been included before by checking whether or the symbol "Item_H" has been defined
#define NODE_H // Purpose: Defines the "Item_H" symbol so the compiler can tell the this file has already been compile

//General Includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cassert>

//Header File Includes
#include "Location.h"

using namespace std;

class Node {
public:
	Node();
	Node(unsigned int description1, unsigned int north1, unsigned int south1, unsigned int east1, unsigned int west1, bool is_death1);
	Node(const Node& to_copy);
	virtual ~Node();
	Node& operator= (const Node& to_copy);
	virtual void debugPrint() const;
	virtual Node* getClone() const;
	void debugPrint() const;
	unsigned int getDescription() const;
	Location getNorth() const;
	Location getSouth() const;
	Location getEast() const;
	Location getWest() const;
	bool isDeath() const;
	virtual bool isObstructed() const;
	virtual char getRequiredItem() const;
	virtual char getRequiredItem() const;
	virtual unsigned int getDescriptionSuccess() const;


	// Member Variables
private:
	unsigned int description;
	unsigned int north;
	unsigned int south;
	unsigned int east;
	unsigned int west;
	bool is_death;
};

#endif // Purpose: End of ifndef statement

