#include "UpdateList.h"

/*
 * Created by Stuart Irwin on 4/15/2019.
 * Manages list of nodes through update cycle
 */

//Static variables
std::vector<Node *> UpdateList::screen;

//Check if node has moving collisionlayer
bool UpdateList::moving_layer(Node *n) {
	return n->get_layer() == PLAYER || n->get_layer() == ENEMY;
}

//Add node to update cycle
void UpdateList::add_node(Node *next) {
	screen.push_back(next);
}

//Remove marked nodes from update cycle
void UpdateList::remove_nodes() {
	std::vector<Node *>::iterator it = screen.begin();
	while(it != screen.end()) {
		//Check for delete mark
		if((*it)->get_delete()) {
			screen.erase(it);
			delete *it;
		}

		//Move to next
		if(it != screen.end()) it++; 
	}
}

//Update all nodes in list
void UpdateList::update(sf::RenderWindow &window, double time) {
	bool deleting = false;

	//Check collisions and updates
	for(Node *source : screen) {
		if(source->on_screen()) {
			//For moving object types
			if(moving_layer(source)) {
				for(Node *object : screen) {
					//Actually check collision box
					if(source->check_collision(object)) {
						source->collide(object);

						//Check for double detection
						if(!moving_layer(object))
							object->collide(source);
					}
				}
			}

			//Update each object
			source->update(time);
			if(!source->get_hidden())
				window.draw(*source);
		}

		//Check for deletion
		if(source->get_delete())
			deleting = true;
	}

	if(deleting)
		remove_nodes();
}
