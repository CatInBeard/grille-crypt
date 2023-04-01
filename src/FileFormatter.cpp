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

#include "FileFormatter.h"
#include "XorCrypt.h"
#include "converter.h"

namespace grille{
	
	void FileFormatter::setPasscode(const std::string& str){
		passcodeLst = stringToList(str);
	}
	void FileFormatter::setKey(const GrilleKey& key){
		keyLst = key.getKeyChars();
	}
	std::ostream& operator<<(std::ostream& os,FileFormatter& ff){
		XorCrypt xcrypt {ff.passcodeLst};

		std::list<char> output {xcrypt.encrypt(ff.keyLst)};
		
		os<<"GRL1S";

		char i = static_cast<char>(output.size());
		
		os<< static_cast<char>( i ^ static_cast<char>(ff.passcodeLst.front()));

		for(char c: output){
			os<<c;
		}

		return os;
	}
	
}

