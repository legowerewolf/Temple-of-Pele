#pragma once

#include "NodeLoader.hpp"
#include "Door.hpp"
#include "AreaSwitch.h"
#include "Key.hpp"
#include "Bridge.hpp"
#include "EndScreen.hpp"
#include "Enemy.h"

/*
 * Created by Stuart Irwin on 4/22/2019.
 * Node spawners for each map
 */

class NodeSpawner {
public:
	virtual void spawn() = 0;
};