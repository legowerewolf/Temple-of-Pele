#include "engine/Node.h"
#include "engine/GridMaker.h"
#include "enums.h"
#include "textures.h"

/*
 * Created by Stuart Irwin on 4/20/2019.
 * Activatable bridge to go over lava
 */

class Bridge : public Node, public LogicDevice {
private:
	//Bridge current state
	int vertical_shown = 0;
	double nextTime = 0;
	bool closing = false;

public:
	//Build bridge
	Bridge(Textures &textures, OrthagonalDirection direction) : Node(FEATURE, sf::Vector2i(16, 16)) {
		//Configure bridge properties
		setTexture(textures.bridge);

		//Rotate door properly
		switch(direction) {
			case East:
				setRotation(90);
				break;
			case South:
				setRotation(180);
				break;
			case West:
				setRotation(-90);
				break;
			default:
				break;
		}
	}

	RecivingAction getRecivingAction() { return UNLINK; };

	//Start closing animation
	void activate() {
		closing = true;
	}

	//Continue bridge animation
	void update(double time) {
		if(closing && vertical_shown < 16) {
			//Closing animation
			if(time >= nextTime) {
				nextTime = time += 0.08;
				vertical_shown++;
			}

			//Set solid ground
			if(vertical_shown == 16) {
				GridMaker::set_tile(getPosition(), '.');
				send();
			}
		}

		//Set shown amount of texture
		setTextureRect(sf::IntRect(0, vertical_shown, 16, vertical_shown + 16));
	}
};