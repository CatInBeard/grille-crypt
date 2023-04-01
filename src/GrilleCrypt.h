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

#ifndef GRILLE_CRYPT_H

#define GRILLE_CRYPT_H

#include <string>

namespace grille{

class GrilleCrypt{
	public:
		bool Encrypt(std::string inputFileName, std::string outputFileName, std::string passCode);	
		bool Decrypt(std::string inputFileName, std::string outputFileName, std::string passCode);

};

}
#endif
