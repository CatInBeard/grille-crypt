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



#include "GrilleKey.h"
#include "AbstractSystemDependedFactory.h"
#include "AbstractRandomStream.h"

#include <memory>

#ifndef KEY_GENERATOR_H
#define KEY_GENERATOR_H

namespace grille{
	class KeyGenerator{
		public:
			KeyGenerator();
			GrilleKey getNewKey(long char_length=64);
			~KeyGenerator();
		private:
			std::unique_ptr<AbstractRandomStream> rs;
	};
}

#endif
