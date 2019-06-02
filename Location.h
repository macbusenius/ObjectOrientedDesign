#pragma once
#ifndef LOCATION_H
#define LOCATION_H

//General Includes
#include <iostream>
#include <string>

using namespace std;

class Location {

public:
	Location();
	Location(unsigned int node1);
	bool operator== (const Location& other) const;
	bool isInaccessible() const;
	unsigned int node;
};

std::ostream& operator<< (std::ostream& out,
	const Location& location);

#endif

