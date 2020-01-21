/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef ULTIMA_ULTIMA1_MAPS_MAP_BASE_H
#define ULTIMA_ULTIMA1_MAPS_MAP_BASE_H

#include "ultima/shared/maps/map_base.h"

namespace Ultima {
namespace Ultima1 {

class Ultima1Game;

namespace Maps {

class Ultima1Map;

/**
 * Intermediate base class for Ultima 1 maps
 */
class MapBase : public Shared::Maps::MapBase {
private:
	/**
	 * Default unknown/question mark display
	 */
	void unknownAction();
protected:
	Ultima1Game *_game;
public:
	/**
	 * Constructor
	 */
	MapBase(Ultima1Game *game, Ultima1Map *map);
		
	/**
	 * Destructor
	 */
	virtual ~MapBase() {}

	/**
	 * Gets a tile at a given position
	 */
	virtual void getTileAt(const Point &pt, Shared::Maps::MapTile *tile, bool includePlayer = true) override;

	/**
	 * Do an inform action
	 */
	virtual void inform() = 0;

	/**
	 * Do a climb action/
	 */
	virtual void climb() { unknownAction(); }

	/**
	 * Do a steal action
	 */
	virtual void steal() { unknownAction(); }

	/**
	 * Do a talk action
	 */
	void talk() { unknownAction(); }
};

} // End of namespace Maps
} // End of namespace Ultima1
} // End of namespace Ultima

#endif