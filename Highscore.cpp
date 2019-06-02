//General Includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cassert>

//Header File Includes
#include "Highscore.h"

using namespace std;

HighScore::HighScore() {
	p_head = nullptr;

	assert(invariant());
}

HighScore::HighScore(const string& game_name) {
	p_head = nullptr;

	string filename = getFilename(game_name);
	assert(filename != "");
	ifstream fin(filename);

	// special case: no high scores file
	if (!fin) {
		assert(invariant());

		return;
	}

	// general case: high scores already exist
	assert(fin.good());

	Element* p_tail = nullptr;

	// loop exits on EOF below
	while (true) {
		// read score
		int score;
		fin >> score;

		if (!fin)
			break;  // loop drops out here

		assert(fin.good());

		// read player name
		string player_name;
		getline(fin, player_name);

		assert(fin.good());
		assert(player_name.size() > 1);

		// remove tab from player name
		assert(player_name != "");

		player_name = player_name.substr(1);

		assert(player_name != "");

		// insert new score into list
		//insert(score, player_name);  // if file is  unsorted

		// more efficient version for when file is already sorted
		Element* p_new_element = new Element;
		p_new_element->score = score;
		p_new_element->name = player_name;
		p_new_element->p_next = nullptr;

		if (p_tail == nullptr)
			p_head = p_new_element;
		else
			p_tail->p_next = p_new_element;
		p_tail = p_new_element;
	} 

	assert(invariant());
}

HighScore::HighScore(const HighScore& to_copy) {
	p_head = copyLinkedList(to_copy.p_head);

	assert(to_copy.invariant());
	assert(invariant());
}

HighScore::~HighScore() {
	assert(invariant());

	destroyLinkedList(p_head);
}

HighScore& HighScore::operator= (const HighScore& to_copy) {
	assert(invariant());
	assert(to_copy.invariant());

	if (&to_copy != this) {
		destroyLinkedList(p_head);
		p_head = copyLinkedList(to_copy.p_head);
	}

	assert(invariant());
	assert(to_copy.invariant());

	return *this;
}

void HighScore::print() const {
	assert(invariant());
	
	cout << "High Scores: " << endl;
	printToStream(cout);
}

void HighScore::save(const string& game_name) const {
	assert(invariant());

	ofstream fout(getFilename(game_name), ios::trunc);
	printToStream(fout);
}

void HighScore::insert(int score1, const string& player_name) {
	assert(invariant());

	// create new element
	Element* p_new_element = new Element;
	p_new_element->score = score1;
	p_new_element->name = player_name;
	p_new_element->p_next = nullptr;

	// special case: linked list was empty
	if (p_head == nullptr) {
		p_head = p_new_element;

		assert(invariant());

		return;
	}

	// special case: insert at front of linked list
	assert(p_head != nullptr);

	if (p_head->score <= score1) {
		p_new_element->p_next = p_head;
		p_head = p_new_element;

		assert(invariant());

		return;
	}

	// general case: insert part way through the linked list
	Element* p_previous = p_head;

	assert(p_previous != nullptr);

	while (p_previous->p_next != nullptr && p_previous->p_next->score > score1) {
		p_previous = p_previous->p_next;

		assert(p_previous != nullptr);
	}

	assert(p_previous != nullptr);
	assert(p_previous->score > score1);
	assert(p_previous->p_next == nullptr || p_previous->p_next->score <= score1);

	p_new_element->p_next = p_previous->p_next;
	p_previous->p_next = p_new_element;

	assert(invariant());
}

Element* HighScore::copyLinkedList(const Element* p_old_head) const {
	if (p_old_head == nullptr)
		return nullptr;

	// copy head
	Element* p_new_head = new Element;
	p_new_head->score = p_old_head->score;
	p_new_head->name = p_old_head->name;
	p_new_head->p_next = nullptr;

	// copy linked list after head
	const Element* p_old_current = p_old_head;
	Element*       p_new_current = p_new_head;
	while (p_old_current->p_next != nullptr)
	{
		p_old_current = p_old_current->p_next;

		p_new_current->p_next = new Element;
		p_new_current = p_new_current->p_next;

		p_new_current->score = p_old_current->score;
		p_new_current->name = p_old_current->name;
		p_new_current->p_next = nullptr;
	}

	// return head of new linked list
	return p_new_head;
}

void HighScore::destroyLinkedList(Element* p_head) const {
	while (p_head != nullptr)
	{
		Element* p_current = p_head;
		p_head = p_head->p_next;
		delete p_current;
	}

	assert(p_head == nullptr);	
}

void HighScore::printToStream(ostream& out) const {
	for (Element* p_current = p_head;
		p_current != nullptr;
		p_current = p_current->p_next)
	{
		out << p_current->score << "\t"
			<< p_current->name << endl;
	}
}

string HighScore::getFilename(const string& game_name) const {
	return game_name + "_highscores.txt";
}


bool HighScore::invariant() const {
	for (Element* p_current = p_head;
		p_current != nullptr;
		p_current = p_current->p_next)
	{
		if (p_current->p_next != nullptr &&
			p_current->score < p_current->p_next->score)
		{
			return false;
		}
	}
	return true;
}

