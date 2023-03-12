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

#include "DecryptStream.h"
#include "GrilleKey.h"

namespace grille{

DecryptStream::DecryptStream(const GrilleKey& key):
	dataFrame{new char[key.size()]}{
	unsigned long i = 0;
	for(auto isHole: key){
		char* c = &dataFrame[i++];
		if(isHole){
			realDataPtrList.push_back(c);
		}
		else{
			noiseDataPtrList.push_back(c);
		}
	}
	dataFrameSize = i;
}

DecryptStream::~DecryptStream(){
	
}	

void DecryptStream::put(std::istream& is){
	stopElement = &dataFrame[0];
	for(unsigned long i =0; i != dataFrameSize; i++){	
		stopElement = &dataFrame[i];
		if(is.peek() == EOF)return;
		is >> dataFrame[i];
		if(dataFrame[i] == 10 && is.peek() == EOF){
			stopElement++; 
			return;
		}
	}
	stopElement++;
}
void DecryptStream::get(std::ostream& os){
	for(char* c: realDataPtrList){
		if(c >= stopElement) return;
        	os << *c;
         }
	stopElement = realDataPtrList.front();
}

}
