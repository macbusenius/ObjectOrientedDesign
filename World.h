#ifndef WORLD_H // Purpose: See if header file (Item.h) has been included before by checking whether or the symbol "Item_H" has been defined
#define WORLD_H // Purpose: Defines the "Item_H" symbol so the compiler can tell the this file has already been compiled

//General Includes
#include <iostream>
#include <string>
#include <cassert>

//Header File Includes
#include "Node.h"
#include "Location.h"

using namespace std;

const unsigned int MAX_DESCRIPTION_COUNT = 1000;
static const int MAX_NODE_COUNT = 1000;

// World Class
class World {
public:
	World(const string& game_name);
	//  Constructor
	//  Purpose: To create an World for the game with the specified name.
	//  Parameter(s):
	//    <1> game_name: The game name
	//  Precondition(s):
	//    <1> game_name != ""
	//  Returns: N/A
	//  Side Effect: A new World is created.  The nodes and descriptions are read from the data files for name game_name.


	void debugPrint() const;
	//  debugPrint
	//  Purpose: To print the complete state of this World.  This
	//           function is intended for use when debugging.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The complete state of this World is printed to standard output (cout).  This includes the current value of all member variables.


	Location getStart() const;
	//  getStart
	//  Purpose: To determine the starting location for the player.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: The starting node for the player.
	//  Side Effect: N/A


	bool isValid(const Location& location) const;
	//  isValid
	//  Purpose: To determine if the specified Location represents a valid node.
	//  Parameter(s):
	//    <1> location: The location to test
	//  Precondition(s): N/A
	//  Returns: Whether Location location represents valid node in
	//           this World.
	//  Side Effect: N/A


	void printDescription(const Location& location) const;
	//  printDescription
	//  Purpose: To print the description for the specified node.
	//  Parameter(s):
	//    <1> location: The node to print
	//  Precondition(s):
	//    <1> isValid()
	//  Returns: N/A
	//  Side Effect: The description for node location is printed to standard output (cout).


	bool canGoNorth(const Location& location) const;
	//  canGoNorth
	//  Purpose: To determine if it is possible to go north from the specified node.
	//  Parameter(s):
	//    <1> location: The node to test
	//  Precondition(s):
	//    <1> isValid()
	//  Returns: Whether it is possible to go north from node location.
	//  Side Effect: N/A


	bool canGoSouth(const Location& location) const;
	//  canGoSouth
	//  Purpose: To determine if it is possible to go south from the specified node.
	//  Parameter(s):
	//    <1> location: The node to test
	//  Precondition(s):
	//    <1> isValid()
	//  Returns: Whether it is possible to go south from node location.
	//  Side Effect: N/A


	bool canGoEast(const Location& location) const;
	//  canGoEast
	//  Purpose: To determine if it is possible to go east from the specified node.
	//  Parameter(s):
	//    <1> location: The node to test
	//  Precondition(s):
	//    <1> isValid()
	//  Returns: Whether it is possible to go east from node location.
	//  Side Effect: N/A


	bool canGoWest(const Location& location) const;
	//  canGoWest
	//  Purpose: To determine if it is possible to go west from the specified node.
	//  Parameter(s):
	//    <1> location: The node to test
	//  Precondition(s):
	//    <1> isValid()
	//  Returns: Whether it is possible to go west from node location.
	//  Side Effect: N/A


	Location getNorth(const Location& location) const;
	//  getNorth
	//  Purpose: To determine the location to the north of the specified node.
	//  Parameter(s):
	//    <1> location: The node to query
	//  Precondition(s):
	//    <1> isValid()
	//    <2> canGoNorth(location)
	//  Returns: The location of the node to the north of location.
	//  Side Effect: N/A


	Location getSouth(const Location& location) const;
	//  getSouth
	//  Purpose: To determine the location to the south of the specified node.
	//  Parameter(s):
	//    <1> location: The node to query
	//  Precondition(s):
	//    <1> isValid()
	//    <2> canGoSouth(location)
	//  Returns: The location of the node to the south of location.
	//  Side Effect: N/A


	Location getEast(const Location& location) const;
	//  getEast
	//  Purpose: To determine the location to the east of the specified node.
	//  Parameter(s):
	//    <1> location: The node to query
	//  Precondition(s):
	//    <1> isValid()
	//    <2> canGoEast(location)
	//  Returns: The location of the node to the east of location.
	//  Side Effect: N/A


	Location getWest(const Location& location) const;
	//  getWest
	//  Purpose: To determine the location to the west of the specified node.
	//  Parameter(s):
	//    <1> location: The node to query
	//  Precondition(s):
	//    <1> isValid()
	//    <2> canGoWest(location)
	//  Returns: The location of the node to the west of location.
	//  Side Effect: N/A


	bool isDeath(const Location& location) const;
	//  isDeath
	//  Purpose: To determine if the node at the specified location is a death node.
	//  Parameter(s):
	//    <1> location: The node to query
	//  Precondition(s):
	//    <1> isValid()
	//  Returns: Whether the node at location location is a death node.
	//  Side Effect: N/A


	bool isVictory(const Location& location) const;
	//  isVictory
	//  Purpose: To determine if the node at the specified location is the victory node.
	//  Parameter(s):
	//    <1> location: The node to query
	//  Precondition(s):
	//    <1> isValid()
	//  Returns: Whether the node at location location is the victory node.
	//  Side Effect: N/A


private:

	void loadNodes(const string& filename);
	//  loadNodes
	//  Purpose: To load the nodes for the specified file.
	//  Parameter(s):
	//    <1> filename: The name of the file
	//  Precondition(s):
	//    <1> filename != ""
	//  Returns: N/A
	//  Side Effect: The nodes in file filename are loaded into this World.


	void loadDescriptions(const string& filename);
	//  loadDescriptions
	//  Purpose: To load the descriptions for the specified file.
	//  Parameter(s):
	//    <1> filename: The name of the file
	//  Precondition(s):
	//    <1> filename != ""
	//  Returns: N/A
	//  Side Effect: The descriptions in file filename are loaded into this World.


	bool invariant() const;
	//  invariant
	//  Purpose: To determine if the class invariant is true.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: Whether the class invariant is true.
	//  Side Effect: N/A

private:
	Node nodes[MAX_NODE_COUNT];
	unsigned int node_count;
	unsigned int start_node;
	unsigned int victory_node;
	string descriptions[MAX_DESCRIPTION_COUNT];
	unsigned int description_count;
};

#endif

