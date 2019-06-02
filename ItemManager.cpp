//General Includes
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>

//Header File Includes
#include "Location.h"
#include "ItemManager.h"
#include "Item.h"

using namespace std;

// Constant
static const unsigned int NO_SUCH_ITEM = 999999999;

ItemManager::ItemManager() {
	itemsArrayD = new Item[0];
	item_count = 0;

	assert(invariant());
}

ItemManager::ItemManager(const string& game_name) {
	itemsArrayD = nullptr;
	item_count = 0;
	load(game_name + "_items.txt");
	sort();

	assert(invariant());
}

ItemManager::ItemManager(const ItemManager& to_copy){
	itemsArrayD = new Item[to_copy.item_count];
	item_count = to_copy.item_count;
	
	assert(to_copy.invariant());
	assert(invariant());
}

ItemManager::~ItemManager() {
	assert(invariant());
	delete[] itemsArrayD;
}

ItemManager& ItemManager::operator= (const ItemManager& to_copy) {
	assert(to_copy.invariant());
	assert(invariant());

	if (&to_copy != this) {
		// from destructor
		delete[] itemsArrayD;

		// from copy constructor
		itemsArrayD = new Item[to_copy.item_count];
		item_count = to_copy.item_count;
	}

	assert(to_copy.invariant());
	assert(invariant());
	return *this;
}

void ItemManager::load(const string& filename)
{
	assert(filename != "");
	assert(itemsArrayD == nullptr);

	ifstream fin(filename.c_str());
	if (!fin){
		cerr << "Error: Could not open file \"" << filename << "\"" << endl;
		return;
	}

	assert(fin.good());

	fin >> item_count;
	assert(fin.good());
	itemsArrayD = new Item[item_count];

	string line;
	getline(fin, line);
	assert(fin.good());
	assert(line == "");

	for (unsigned int i = 0; i < item_count; i++)
	{
		// read and discard a blank line
		getline(fin, line);
		assert(fin.good());
		assert(line == "");

		// read the values on the first line
		char id;
		fin >> id;
		assert(fin.good());

		unsigned int start;
		fin >> start;
		assert(fin.good());

		int points;
		fin >> points;
		assert(fin.good());

		// discard anything else on the line
		getline(fin, line);
		assert(fin.good());

		// read the descriptions
		string world_description;
		getline(fin, world_description);
		assert(fin.good());
		assert(world_description != "");

		string inventory_description;
		getline(fin, inventory_description);
		assert(fin.good());
		assert(inventory_description != "");

		// initialize the item
		itemsArrayD[i].init(id, Location(start), points, world_description, inventory_description);
	}
}

int ItemManager::getScore() const {
	assert(invariant());

	int pointsTotal = 0;
	for (int i = 0; i < item_count; i++) {
		pointsTotal += itemsArrayD[i].getPlayerPoints();
	}
	return pointsTotal;
}

void ItemManager::sort() {
	//Selection Sort
	for (unsigned int i = 0; i < item_count; i++)
	{
		// find best remaining item
		unsigned int spot = i;
		for (unsigned int j = i + 1; j < item_count; j++)
			if (itemsArrayD[j] < itemsArrayD[spot])
				spot = j;

		// swap best item in
		Item temp_item = itemsArrayD[i];
		itemsArrayD[i] = itemsArrayD[spot];
		itemsArrayD[spot] = temp_item;
	}
}


void ItemManager::printAtLocation(const Location& location) const {
	assert(invariant());

	for (int i = 0; i < item_count; i++)
		if (itemsArrayD[i].isAtLocation(location)) {
			itemsArrayD[i].printDescription();
		}
}


void ItemManager::printInventory() const {
	assert(invariant());

	for (unsigned int i = 0; i < item_count; i++) {
		if (itemsArrayD[i].isInInventory()) {
			itemsArrayD[i].printDescription();
		}
	}
}

void ItemManager::reset() {
	assert(invariant());

	for (unsigned int i = 0; i < item_count; i++){
		itemsArrayD[i].reset();
	}

	assert(invariant());
}

bool ItemManager::isInInventory(char id) const {
	assert(invariant());

	unsigned int item_index = find(id);
	if (item_index == NO_SUCH_ITEM) {
		return false;
	}
	else
		return itemsArrayD[item_index].isInInventory();
}

void ItemManager::take(char id, const Location& player_location) {
	assert(invariant());

	unsigned int item_index = find(id);

	if (item_index != NO_SUCH_ITEM && itemsArrayD[item_index].isAtLocation(player_location)){
		itemsArrayD[item_index].moveToInventory();
	}
	else
		cout << "Invalid item." << endl;

	assert(invariant());
}

void ItemManager::leave(char id, const Location& player_location) {
	assert(invariant());

	unsigned int item_index = find(id);

	if (item_index != NO_SUCH_ITEM && itemsArrayD[item_index].isInInventory()){
		itemsArrayD[item_index].moveToLocation(player_location);
	}
	else
		cout << "Invalid item." << endl;

	assert(invariant());
}

// Private Member Functions

unsigned int ItemManager::find(char id) const {
	// Binary Search
	unsigned int low = 0;
	unsigned int high = item_count;

	while (low <= high) {
		assert(low != high);
		unsigned int mid = (low + high) / 2;
		assert(mid < item_count);

		char middle_id = itemsArrayD[mid].getId();
		if (id == middle_id)
			return mid;  // found it!

		else if (id < middle_id)
			high = mid;  // search low half

		else {
			assert(id > middle_id);
			low = mid + 1;  // search high half
		}
	}
	return NO_SUCH_ITEM;
}

bool ItemManager::invariant() const {
	if (itemsArrayD == nullptr)
		return false;
	for (unsigned int i = 0; i < item_count; i++)
		if (!itemsArrayD[i].isInitialized())
			return false;
	for (unsigned int i = 1; i < item_count; i++)
		if (itemsArrayD[i - 1].getId() > itemsArrayD[i].getId())
			return false;
	return true;
}