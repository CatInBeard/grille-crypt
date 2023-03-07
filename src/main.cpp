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


#include <iostream>
#include <sstream>

#include "GrilleKey.h"
#include "EncryptStream.h"

int main(){
	std::istringstream iss {"1234567890"};
	std::istream& is = static_cast<std::istream&>(iss);

	GrilleKey key{"az"};
	EncryptStream es {key};
	while(is){
		is >> es;
		std::cout << es;
	}
	return 0;
}
