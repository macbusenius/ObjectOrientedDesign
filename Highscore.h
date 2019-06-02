#ifndef Highscores_H // Purpose: See if header file (Item.h) has been included before by checking whether or the symbol "Item_H" has been defined
#define Highscores_H // Purpose: Defines the "Item_H" symbol so the compiler can tell the this file has already been compiled

//General Includes
#include <iostream>
#include <string>

using namespace std;

struct Element {
	int score;
	string name;
	Element* p_next;

};

class HighScore {
public:
	HighScore();
	//  Purpose: To create an HighScores with no scores.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: A new HighScores is created containing no scores.

	HighScore(const string& game_name);
	//  Purpose: To create an HighScores with the scores in the data
	//           file for the game with the specified name.
	//  Parameter(s):
	//    <1> game_name: The game name
	//  Precondition(s):
	//    <1> game_name != ""
	//  Returns: N/A
	//  Side Effect: A new HighScores is created containing the scores loaded from the data file for the game with name game_name.

	HighScore(const HighScore& to_copy);
	//  Purpose: To create a HighScores with the same scores as
	//           another.
	//  Parameter(s):
	//    <1> to_copy: The ItemManager to copy
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: A new HighScores is created containing the same scores as to_copy.

	~HighScore();
	//  Purpose: To safely destroy a HighScores without memory
	//           leaks.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: All dynamically allocated memeory associated with this HighScores is freed.

	HighScore& operator= (const HighScore& to_copy);
	//  Purpose: To modify this HighScores to be a copy of another.
	//  Parameter(s):
	//    <1> to_copy: The HighScores to copy
	//  Precondition(s): N/A
	//  Returns: A reference to this HighScores.
	//  Side Effect: The scores in this HighScores are removed an replaced with copies of the scores in to_copy.

	void print() const;
	//  Purpose: To print the current scores.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The scores in this HighScores are printed to standard output (cout).

	void save(const string& game_name) const;
	//  Purpose: To save the current scores to the data file for the
	//           game with the specified name.
	//  Parameter(s):
	//    <1> game_name: The game name
	//  Precondition(s):
	//    <1> game_name != ""
	//  Returns: N/A
	//  Side Effect: The high scores data files for game game_name is overwritten with the scores in this HighScores.

	void insert(int score1, const string& player_name);
	//  Purpose: To insert a new high score with the specified
	//           player score and player name.
	//  Parameter(s):
	//    <1> score: The player score
	//    <2> player_name: The player name
	//  Precondition(s):
	//    <1> player_name != ""
	//  Returns: N/A
	//  Side Effect: A new entry with score player_score and name player_name is inserted into this HighScores.

private:
	Element* copyLinkedList(const Element* p_old_head) const;
	//  Purpose: To create a copy of the linked list with the
	//           specified head.
	//  Parameter(s):
	//    <1> p_old_head: A pointer to the head of the existing
	//                    linked list
	//  Precondition(s): N/A
	//  Returns: The pointer to the head of a dynamically allocated
	//           copy of the linked list starting with p_old_head.
	//           If p_old_head == nullptr, nullptr is returned.  It
	//           is the responsiblity of the client code to ensure
	//           that the linked list returned is eventually
	//           deallocated.
	//  Side Effect: N/A

	void destroyLinkedList(Element* p_head) const;
	//  Purpose: To free the dynamically allocated memory associated
	//           with the linked list with the specified head.
	//  Parameter(s):
	//    <1> p_head: A pointer to the head of the linked list
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The dynamically allocated memory associated with the linked list starting at p_head is freed. After this function ends, p_head will be a dangling pointer.

	void printToStream(ostream& out) const;
	//  Purpose: To print the current scores to the specified output
	//           stream.
	//  Parameter(s):
	//    <1> out: The output stream to print to
	//  Precondition(s): N/A
	//  Returns: N/A
	//  Side Effect: The scores in this HighScores are printed to stream out.

	string getFilename(const string& game_name) const;
	//  Purpose: To determine the filename for the high scores data
	//           file for the gamne with the specified name.
	//  Parameter(s):
	//    <1> game_name: The game name
	//  Precondition(s): N/A
	//  Returns: The high scores data file filename.
	//  Side Effect: N/A

	bool invariant() const;
	//  Purpose: To determine if the class invarint is true.
	//  Parameter(s): N/A
	//  Precondition(s): N/A
	//  Returns: Whether the class invariant is true.
	//  Side Effect: N/A

	Element* p_head;

};

#endif
