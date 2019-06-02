//General Includes
#include <iostream>
#include <string>
#include <cassert>

//Header File Includes
#include "World.h"
#include "Location.h"
#include "ItemManager.h"
#include "Item.h"
#include "Game.h"

using namespace std;

Game::Game(const string& game_name)
	: world(game_name), item_manager(game_name), player(world.getStart())

{
	assert(invariant());
}

bool Game::isOver() const {
	assert(invariant());

	return (world.isDeath(player) || world.isVictory(player));
}

int Game::getScore() const {
	assert(invariant());

	return item_manager.getScore();
}

void Game::printDescription() const {
	assert(invariant());

	world.printDescription(player);
	item_manager.printAtLocation(player);
}

void Game::printInventory() const {
	assert(invariant());

	item_manager.printInventory();
}

void Game::reset() {
	assert(invariant());

	item_manager.reset();
	player = world.getStart();

	assert(invariant());
}

void Game::moveNorth() {
	assert(invariant());

	if (world.canGoNorth(player))
	{
		player = world.getNorth(player);
		printDescription();
	}
	else
		cout << "There is no way to go in that direction." << endl;

	assert(invariant());
}

void Game::moveSouth() {
	assert(invariant());

	if (world.canGoSouth(player))
	{
		player = world.getSouth(player);
		printDescription();
	}
	else
		cout << "There is no way to go in that direction." << endl;

	assert(invariant());
}

void Game::moveEast() {
	assert(invariant());

	if (world.canGoEast(player))
	{
		player = world.getEast(player);
		printDescription();
	}
	else
		cout << "There is no way to go in that direction." << endl;

	assert(invariant());
}

void Game::moveWest() {
	assert(invariant());

	if (world.canGoWest(player))
	{
		player = world.getWest(player);
		printDescription();
	}
	else
		cout << "There is no way to go in that direction." << endl;

	assert(invariant());
}

void Game::takeItem(char id) {
	assert(invariant());

	item_manager.take(id, player);

	assert(invariant());
}

void Game::leaveItem(char id) {
	assert(invariant());

	item_manager.leave(id, player);

	assert(invariant());
}

bool Game::invariant() const {
	if (!world.isValid(player)) return false;
	return true;
}
