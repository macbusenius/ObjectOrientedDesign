//General Includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cassert>

//Header File Includes
#include "World.h"
#include "Node.h"
#include "Location.h"
#include "ItemManager.h"
#include "Item.h"
#include "Game.h"

using namespace std;

World::World(const string& game_name) {
	loadNodes(game_name + "_nodes.txt");
	loadDescriptions(game_name + "_text.txt");

	assert(invariant());
}

void World::debugPrint() const {
	cout << "Nodes:" << endl;
	cout << "------" << endl;
	cout << node_count << endl;
	cout << start_node << "\t" << victory_node << endl;
	for (unsigned int n = 0; n < node_count; n++)
		nodes[n].debugPrint();
	cout << endl;

	cout << "Descriptions:" << endl;
	cout << "-------------" << endl;
	for (unsigned int d = 0; d < description_count; d++)
		cout << descriptions[d] << endl;
}


Location World::getStart() const {
	assert(invariant());

	return start_node;
}


bool World::isValid(const Location& location) const {
	assert(invariant());

	return location.node < node_count;
}


void World::printDescription(const Location& location) const {
	assert(invariant());
	assert(isValid(location));

	unsigned int index = nodes[location.node].getDescription();
	assert(index < MAX_DESCRIPTION_COUNT);
	assert(index < description_count);
	cout << descriptions[index];
}


bool World::canGoNorth(const Location& location) const {
	assert(invariant());
	assert(isValid(location));

	return !nodes[location.node].getNorth().isInaccessible();
}


bool World::canGoSouth(const Location& location) const {
	assert(invariant());
	assert(isValid(location));

	return !nodes[location.node].getSouth().isInaccessible();
}


bool World::canGoEast(const Location& location) const {
	assert(invariant());
	assert(isValid(location));

	return !nodes[location.node].getEast().isInaccessible();
}


bool World::canGoWest(const Location& location) const {
	assert(invariant());
	assert(isValid(location));

	return !nodes[location.node].getWest().isInaccessible();
}


Location World::getNorth(const Location& location) const {
	assert(invariant());
	assert(isValid(location));
	assert(canGoNorth(location));

	return nodes[location.node].getNorth();
}


Location World::getSouth(const Location& location) const {
	assert(invariant());
	assert(isValid(location));
	assert(canGoSouth(location));

	return nodes[location.node].getSouth();
}


Location World::getEast(const Location& location) const {
	assert(invariant());
	assert(isValid(location));
	assert(canGoEast(location));

	return nodes[location.node].getEast();
}


Location World::getWest(const Location& location) const {
	assert(invariant());
	assert(isValid(location));
	assert(canGoWest(location));

	return nodes[location.node].getWest();
}


bool World::isDeath(const Location& location) const
{
	assert(invariant());
	assert(isValid(location));

	return nodes[location.node].isDeath();
}


bool World::isVictory(const Location& location) const
{
	assert(invariant());
	assert(isValid(location));

	return location.node == victory_node;
}

void World::loadNodes(const string& filename)
{
	assert(filename != "");

	ifstream fin(filename.c_str());
	if (!fin)
	{
		cerr << "Error: Could not open file \"" << filename << "\"" << endl;
		return;
	}
	assert(fin.good());

	fin >> node_count;
	if (!fin)
	{
		cerr << "Error: Could not read node count in file \"" << filename << "\"" << endl;
		return;
	}
	assert(fin.good());
	if (node_count > MAX_NODE_COUNT)
	{
		cerr << "Error: Too many nodes in file \"" << filename << "\", increase MAX_NODE_COUNT" << endl;
		return;
	}
	assert(node_count <= MAX_NODE_COUNT);

	fin >> start_node;
	if (!fin)
	{
		cerr << "Error: Could not read start node in file \"" << filename << "\"" << endl;
		return;
	}
	assert(fin.good());
	if (start_node >= node_count)
	{
		cerr << "Error: Invalid start node " << start_node << " / "
			<< node_count << " in file \"" << filename << "\"" << endl;
		return;
	}
	assert(start_node < node_count);

	fin >> victory_node;
	if (!fin)
	{
		cerr << "Error: Could not read victory node in file \"" << filename << "\"" << endl;
		return;
	}
	assert(fin.good());
	if (victory_node >= node_count)
	{
		cerr << "Error: Invalid victory node " << victory_node << " / "
			<< node_count << " in file \"" << filename << "\"" << endl;
		return;
	}
	assert(victory_node < node_count);

	// discard anything else on start/victory line
	string line;
	getline(fin, line);
	if (!fin)
	{
		cerr << "Error: Could not discard blank line file \"" << filename << "\"" << endl;
		return;
	}
	assert(fin.good());
	if (!fin)
	{
		cerr << "Error: Extra values on info line in file \"" << filename << "\"" << endl;
		return;
	}
	assert(line == "");

	for (unsigned int n = 0; n < node_count; n++)
	{
		char node_type;
		fin >> node_type;
		if (!fin.good())
		{
			cerr << "Error: Could not read node type for node " << n << " in file \"" << filename << "\"" << endl;
			return;
		}
		assert(fin.good());

		unsigned int description;
		fin >> description;
		if (!fin.good())
		{
			cerr << "Error: Could not read description for node " << n << " in file \"" << filename << "\"" << endl;
			return;
		}
		assert(fin.good());

		unsigned int north;
		unsigned int south;
		unsigned int east;
		unsigned int west;
		fin >> north;
		fin >> south;
		fin >> east;
		fin >> west;
		if (!fin.good())
		{
			cerr << "Error: Could not read directions for node " << n << " in file \"" << filename << "\"" << endl;
			return;
		}
		assert(fin.good());

		if (node_type == 'N')
			nodes[n] = Node(description, north, south, east, west, false);
		else if (node_type == 'D')
			nodes[n] = Node(description, north, south, east, west, true);
		else if (node_type == 'O')
		{
			// these will be ObstructedNodes in Assignment 6
			nodes[n] = Node(description, north, south, east, west, false);
		}
		else
		{
			cerr << "Error: Invalid node type \'" << node_type << "\' for node " << n << " in file \"" << filename << "\"" << endl;
			return;
		}

		// discard anything else on the line
		string line;
		getline(fin, line);
		if (!fin.good())
		{
			cerr << "Error: Could not discard endline for node " << n << " in file \"" << filename << "\"" << endl;
			return;
		}
		assert(fin.good());
	}
}

void World::loadDescriptions(const string& filename)
{
	assert(filename != "");

	ifstream fin(filename.c_str());
	if (!fin)
	{
		cerr << "Error: Could not open file \"" << filename << "\"" << endl;
		return;
	}
	assert(fin.good());

	// this error checking really shouldn't be done with asserts...

	fin >> description_count;
	if (!fin)
	{
		cerr << "Error: Could not read description count in file \"" << filename << "\"" << endl;
		return;
	}
	assert(fin.good());
	if (description_count > MAX_DESCRIPTION_COUNT)
	{
		cerr << "Error: Too many descriptions in file \"" << filename << "\", increase MAX_DESCRIPTION_COUNT" << endl;
		return;
	}
	assert(description_count <= MAX_DESCRIPTION_COUNT);

	// discard anything else on count line
	string line;
	getline(fin, line);
	if (!fin.good())
	{
		cerr << "Error: Could not discard endline after description count in file \"" << filename << "\"" << endl;
		return;
	}
	assert(fin.good());
	if (line != "")
	{
		cerr << "Error: Extra values after description count in file \"" << filename << "\"" << endl;
		return;
	}
	assert(line == "");

	// read blank line
	getline(fin, line);
	if (!fin.good())
	{
		cerr << "Error: Could not discard first blank line in file \"" << filename << "\"" << endl;
		return;
	}
	assert(fin.good());
	if (line != "")
	{
		cerr << "Error: First blank line in file \"" << filename << "\" was not blank" << endl;
		return;
	}
	assert(line == "");

	// read descriptions
	for (unsigned int d = 0; d < description_count; d++)
	{
		descriptions[d] = "";

		getline(fin, line);
		if (!fin)
		{
			cerr << "Error: Could not read first line of description " << d << " in file \"" << filename << "\"" << endl;
			return;
		}
		assert(fin.good());
		while (line != "")
		{
			descriptions[d] += line + "\n";
			getline(fin, line);
			if (!fin)
			{
				cerr << "Error: Could not read line of description " << d << " in file \"" << filename << "\"" << endl;
				return;
			}
			assert(fin.good());
		}
	}
}

bool World::invariant() const
{
	if (node_count > MAX_NODE_COUNT) return false;
	if (start_node >= node_count) return false;
	if (victory_node >= node_count) return false;
	if (description_count > MAX_DESCRIPTION_COUNT) return false;

	for (unsigned int n = 0; n < node_count; n++)
		if (nodes[n].getDescription() >= description_count)
			return false;

	for (unsigned int d = 0; d < description_count; d++)
		if (descriptions[d] == "")
			return false;

	return true;
}
