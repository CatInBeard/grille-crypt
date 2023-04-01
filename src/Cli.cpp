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
	std::string helloText{"Grille crypt provide you to encrypt and decrypt files with Grille algorithm\nCopyright (C) 2023  Grigoriy Efimov\n\nThis program is free software: you can redistribute it and/or modify\nit under the terms of the GNU General Public License as published by\nthe Free Software Foundation, either version 3 of the License, or\n(at your option) any later version.\nThis program is distributed in the hope that it will be useful,\nbut WITHOUT ANY WARRANTY; without even the implied warranty of\nMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\nGNU General Public License for more details.\nYou should have received a copy of the GNU General Public License\nalong with this program.  If not, see <https://www.gnu.org/licenses/>.\n"};
	std::cout<<helloText<<std::endl;
	}

	void help(){
		std::cout<< "Help:"<<std::endl;
		std::cout<< "You can use interactive mode: without arguments or with -e (--encrypt) or -d (--decrypt)" <<std::endl;
		std::cout<< "For non-interactive usage type grille-crypt -e -i inputFile -o outputFile -p password "<<std::endl;
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

	bool extractStringsFromArgs(char* argv[],std::string& inputFile, std::string& outputFile, std::string& passCode, Action& action){
	
		bool setInputFile = false;
		bool setOutputFile = false;
		bool setPassCode = false;
		bool setAction = false;

		for(int i = 0; i!=8; ++i){
			std::string arg {argv[i]};
			if(arg == "-e" || arg == "--encrypt"){
				action = encrypt;
				setAction = true;
			}
			else if(arg == "-d" || arg == "--decrypt"){
				action = decrypt;
				setAction =true;
			}
			else if(arg == "-i" || arg == "--input"){
				if(i==7){
					return false;
				}
				std::string nextArg {argv[i+1]};
				if(nextArg[0] == '-'){
					return false;
				}
				setInputFile = true;
				inputFile = nextArg;
			}
			else if(arg == "-o" || arg == "--output"){
				if(i==7){
					return false;
				}
				std::string nextArg {argv[i+1]};
				if(nextArg[0] == '-'){
					return false;
				}
				setOutputFile = true;
				outputFile = nextArg;
			}
			else if(arg == "-p" || arg == "--passcode"){
				if(i==7){
					return false;
				}
				std::string nextArg {argv[i+1]};
				if(nextArg[0] == '-'){
					return false;
				}
				setPassCode = true;
				passCode = nextArg;
			}

		}

		return setInputFile && setOutputFile && setPassCode && setAction;
	}

	}
	
}
