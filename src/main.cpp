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
#include "DecryptStream.h"

int main(){
	std::string plainData {"1234567890"};

	std::cout<<"original: " <<plainData << std::endl;

	std::istringstream iss {plainData};
	std::istream& is = static_cast<std::istream&>(iss);
	std::stringstream oss{};
	std::ostream& os = static_cast<std::ostream&>(oss);

	grille::GrilleKey key{"az"};
	grille::EncryptStream es {key};
	while(is){
		is >> es;
		os << es;
	}
	
	std::string encoded = oss.str();
	std::cout<<"encoded: " <<encoded << std::endl;
	
	std::istringstream iss2 {encoded};
	std::istream& is2 = static_cast<std::istream&>(iss2);

	grille::DecryptStream ds{key};
	std::cout<<"decoded: ";
	while(is2){
		is2 >> ds;
		std::cout << ds;
	}

	return 0;
}
