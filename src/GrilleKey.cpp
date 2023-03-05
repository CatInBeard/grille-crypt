/*                                                                                                        * Copyright 2023 Grigoriy Efimov                                                                         *                                                                                                        * Author: Grigoriy Efimov <efimov-gm@newpage.xyz>                                                        *                                                                                                        * This file is part of grille-crypt.                                                                     *
 * Grille-crypt is free software: you can redistribute it and/or modify it under the terms of the         * GNU General Public License as published by the Free Software Foundation, either version 3 of           * the License, or (at your option) any later version.
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



GrilleKey::GrilleKey(std::string str){
	size = static_cast<unsigned int>(str.length());
	for(auto c: str){
		bool isHole;

		if(c<'h'){
			isHole = false;
		}
		else{
			isHole = true;
		}

		keyDataList.push_back(isHole);
	}
}

unsigned int GrilleKey::getSize(){
	return size;
}

key_iterator GrilleKey::begin(){
	return keyDataList.begin();
}

key_iterator GrilleKey::end(){
	return keyDataList.end();
}
