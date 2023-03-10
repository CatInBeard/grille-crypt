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

#ifndef ABSTRACT_SYSTEM_DEPENDED_FACTORY_H
#define ABSTRACT_SYSTEM_DEPENDED_FACTORY_H

#include "AbstractRandomStream.h"

namespace grille{

	namespace abstractFactory{

		class AbstractSystemDependedFactory{
			public:
				static AbstractSystemDependedFactory* getInstance();
				virtual AbstractRandomStream* getRandomStream()=0;
				virtual ~AbstractSystemDependedFactory();
			protected:
				AbstractSystemDependedFactory(){};
			private:
				static AbstractSystemDependedFactory* instance;
		};
	
		using AF = AbstractSystemDependedFactory;

	};

}

#endif
