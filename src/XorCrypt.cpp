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


#include "XorCrypt.h"

namespace grille{
	std::list<char> XorCrypt::encrypt(const std::list<char>& lst) const{
		auto keyIter = key.begin();
		auto keyEnd = key.end();
		std::list<char> data{};

		for(auto c: lst){
			data.push_back(c^*keyIter);	
			keyIter++;
			if(keyIter == keyEnd){
				keyIter = key.begin();
			}
		}

		return data;
	}
}
