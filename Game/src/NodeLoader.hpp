#include "UpdateList.h"

/*
 * Created by Stuart Irwin on 4/17/2019.
 * Inserts nodes into UpdateList
 */

class NodeLoader : public LogicReceiver {
private:
	std::vector<Node *> contents;

public:
	//Prepare node for adding
	void add_node(Node *next, Vector2i position) {
		contents.push_back(next);
		next->setPosition(position);
	}

	//Add content nodes
	void activate() {
		for(Node *next : contents)
			UpdateList::add_node(next);
	}

	//One use only
	bool is_singleton() {
		return true;
	}
	~LogicReciever() {
		delete contents;
	}
}