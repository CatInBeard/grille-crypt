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


#include "GrilleCrypt.h"
#include <string>
#include <iostream>


#include "Cli.h"

using grille::cli::encrypt;
using grille::cli::decrypt;

int main(int argc, char* argv[]){


	grille::cli::Action action {encrypt};
	std::string inputFile;
	std::string outputFile;
	std::string passCode;

	if(argc == 1){	
		grille::cli::hello();
		grille::cli::extractStrings(inputFile, outputFile, passCode, action);		
	}
	else if(argc == 2){
		std::string arg1 {argv[1]};
		if(arg1 == "-h" || arg1 == "--help"){
			grille::cli::hello();
			grille::cli::help();
			return 0;
		}
		else if(arg1 == "-e" || arg1 == "--encrypt"){
			action = encrypt;
			grille::cli::hello();
			grille::cli::extractStrings(inputFile, outputFile, passCode);				
		}
		else if(arg1 == "-d" || arg1 == "--decrypt"){
			action = decrypt;
			grille::cli::hello();
			grille::cli::extractStrings(inputFile, outputFile, passCode);	
		}
		else{
			grille::cli::incorrectInput();

			return 1;
		}
	}
	else{
		if(!grille::cli::extractStringsFromArgs(argc ,argv ,inputFile, outputFile, passCode, action)){		
			grille::cli::incorrectInput();
			return 1;
		}
	}	


	grille::GrilleCrypt gc{};
	
	if(action == encrypt){
		gc.Encrypt(inputFile, outputFile, passCode);
	}
	else{
		gc.Decrypt(inputFile, outputFile, passCode);
	}

	grille::cli::done();

	return 0;
}
