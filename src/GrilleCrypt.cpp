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
#include <fstream>
#include <string>
#include <list>

#include "GrilleCrypt.h"
#include "GrilleKey.h"
#include "EncryptStream.h"
#include "DecryptStream.h"
#include "KeyGenerator.h"
#include "FileFormatter.h"
#include "FileValidator.h"
#include "XorCrypt.h"
#include "converter.h"



namespace grille{

	bool GrilleCrypt::Encrypt(std::string inputFileName, std::string outputFileName, std::string passCode){
		
		std::ifstream ifs {inputFileName, std::ios_base::binary};
		std::istream& is = static_cast<std::istream&>(ifs);
		std::ofstream ofs {outputFileName};
		std::ostream& os = static_cast<std::ostream&>(ofs);

		grille::KeyGenerator kg;

		grille::GrilleKey key = kg.getNewKey();

		grille::FileFormatter ff{};

		ff.setPasscode(passCode);
		ff.setKey(key);


		os<<std::noskipws<<ff;

		grille::EncryptStream es {key};
		while(is.good()){
			is >>std::noskipws >> es;
			os << std::noskipws<< es;
		}	
	
		ifs.close();
		ofs.close();


		return true;
	}

	bool GrilleCrypt::Decrypt(std::string inputFileName, std::string outputFileName, std::string passCode){
		std::ifstream ifs {inputFileName, std::ios_base::binary};
		std::istream& is = static_cast<std::istream&>(ifs);
		std::ofstream ofs {outputFileName, std::ios_base::binary};
		std::ostream& os = static_cast<std::ostream&>(ofs);

		grille::FileValidator fv{};
		fv.setPasscode(passCode);
		if(!fv.validateStream(is)){
			return false;
		}

		grille::GrilleKey key{fv.extractKey(is>>std::noskipws)};

		grille::DecryptStream ds{key};

		while(is){
			is >> std::noskipws >> ds;
			os << std::noskipws << ds;
		}
		ifs.close();
		ofs.close();
		return true;
	}

}
