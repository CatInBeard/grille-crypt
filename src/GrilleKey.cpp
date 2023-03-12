/*
 * Copyright 2023 Grigoriy Efimov
 *
 * Author: Grigoriy Efimov <efimov-gm@newpage.xyz>
 *
 * This file is part of grille-crypt.
 * 
 * Grille-crypt is free software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * Grille-crypt is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with grille-crypt.
 * If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include <string>
#include <list>

#include "GrilleKey.h"

namespace grille{

GrilleKey::GrilleKey(std::list<char> password){
	listSize = 0;
	for(unsigned char c: password){
		while(c>0){
			bool isHole = c%2;
			c/=2;
			listSize++;
			keyDataList.push_back(isHole);
		}
	}
}

unsigned int GrilleKey::size() const{
	return listSize;
}

key_iterator GrilleKey::begin(){
	return keyDataList.begin();
}

key_iterator GrilleKey::end(){
	return keyDataList.end();
}

}
