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
#include <string>

#include "Cli.h"

namespace grille{

	namespace cli{

	void hello(){
		std::cout<< "Grille Crypt"<<std::endl;
	}

	void help(){
		std::cout<< "Help"<<std::endl;		
	}

	void done(){
		std::cout<<"Done!"<<std::endl;
	}

	void incorrectInput(){
		std::cout<< "Invalid arguments. Try --help"<<std::endl;
	}

	void extractStrings(std::string& inputFile, std::string& outputFile, std::string& passCode){	

		std::cout << "Enter input file name:"<<std::endl;
		std::cin >> inputFile;


		std::cout << "Enter output file name:"<<std::endl;
		std::cin >> outputFile;

		std::cout << "Enter your key:"<<std::endl;
		std::cin >> passCode;
	}

	void extractStrings(std::string& inputFile, std::string& OutputFile, std::string& passCode, Action& action){
			
		std::string act;
		std::cout<<"Encrypt or Decrypt? E/D:"<<std::endl;
		std::cin >> act;
		if(act[0] == 'e' || act[0] == 'E'){
			action = encrypt;
		}
		else if(act[0] == 'd' || act[0] == 'D'){
			action = decrypt;
		}
		else{
			std::cout<< "Incorrect answer!" << std::endl;
			extractStrings(inputFile, OutputFile, passCode, action);
		}
		extractStrings(inputFile, OutputFile, passCode);
	}

	}
	
}
