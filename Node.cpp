//General Includes
#include <iostream>
#include <string>
#include <cassert>

//Header File Includes

#include "Node.h"
#include "Location.h"

using namespace std;

Node::Node()
	: description(0), north(0), south(0), east(0), is_death(0)
{
}

Node::Node(unsigned int description1, unsigned int north1, unsigned int south1, unsigned int east1, unsigned int west1, bool is_death1)
	: description(description1), north(north1), south(south1), east(east1), west(west1), is_death(is_death1)
{
}

void Node::debugPrint() const {
	if (is_death)
		cout << "D";
	else
		cout << "N";

	cout << "Description: " << description << " ";
	cout << "North: " << north << " ";
	cout << "South: " << south << " ";
	cout << "East: " << east << " ";
	cout << "West: " << west << " ";
	cout << "Death: " << is_death << endl;
}

unsigned int Node::getDescription() const {
	return description;
}

Location Node::getNorth() const {
	return Location(north);
}

Location Node::getSouth() const {
	return Location(south);
}

Location Node::getEast() const {
	return Location(east);
}

Location Node::getWest() const {
	return Location(west);
}

bool Node::isDeath() const {
	return is_death;
}

Node::Node(const Node& to_copy) {

}

virtual Node::~Node() {

}

Node::Node& operator= (const Node& to_copy) {

}

virtual void Node::debugPrint() const{

}

virtual Node* Node::getClone() const {
	
}

virtual bool isObstructed() const {

}

virtual char getRequiredItem() const {

}

virtual char getRequiredItem() const {

}

virtual unsigned int getDescriptionSuccess() const {

}



