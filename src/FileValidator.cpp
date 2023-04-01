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

#include "FileValidator.h"
#include "converter.h"
#include "XorCrypt.h"

namespace grille{

	void FileValidator::setPasscode(const std::string& str){
		passcodeLst = stringToList(str);
	}
	bool FileValidator::validateStream(std::istream& is) const{
		char chars[6];
		for(auto i=0;i!=5 ;i++){
			is >> chars[i];
		}
		return std::string{chars} == "GRL1S";

	}
	GrilleKey FileValidator::extractKey(std::istream& is) const{
		std::list<char> keyChars;
		char size;
		is >> size;
		size = size ^ passcodeLst.front();
		for(; size!=0; size--){
			char buffer;
			is >> buffer;
			keyChars.push_back(buffer);
		}
		XorCrypt xcrypt{passcodeLst};
		
		std::list<char> decryptedLst {xcrypt.encrypt(keyChars)};
		
		return GrilleKey{decryptedLst};
	}

}
