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
#include <fstream>

#include "GrilleKey.h"
#include "EncryptStream.h"
#include "DecryptStream.h"
#include "KeyGenerator.h"

int main(){

	std::ifstream ifs {"test", std::ios_base::binary};
	std::istream& is = static_cast<std::istream&>(ifs);
	std::ofstream ofs {"test2"};
	std::ostream& os = static_cast<std::ostream&>(ofs);

	grille::KeyGenerator kg;

	grille::GrilleKey key = kg.getNewKey();
	grille::EncryptStream es {key};
	while(is.good()){
		is >>std::noskipws >> es;
		os << std::noskipws<< es;
	}	
	
	ifs.close();
	ofs.close();
	

	std::ifstream ifs2 {"test2", std::ios_base::binary};
	std::istream& is2 = static_cast<std::istream&>(ifs2);
	std::ofstream ofs2 {"test3", std::ios_base::binary};
	std::ostream& os2 = static_cast<std::ostream&>(ofs2);

	grille::DecryptStream ds{key};

	while(is2){
		is2 >> std::noskipws >> ds;
		os2 << std::noskipws << ds;
	}
	ifs2.close();
	ofs2.close();
	return 0;
}
