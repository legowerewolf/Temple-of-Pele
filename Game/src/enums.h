#pragma once

/*
 * Created by Stuart Irwin on 4/13/2019.
 * enums for tiles and collision
 */

enum CollisionLayer {
	SOLID,
	PLAYER,
	SWORD,
	ENEMY,
	FIREBALL,
	SWITCH
};

enum TileType {
	WALL,
	GROUND,
	EMPTY
};

enum OrthagonalDirection {
	North,
	Northeast,
	East,
	Southeast,
	South,
	Southwest,
	West,
	Northwest
};