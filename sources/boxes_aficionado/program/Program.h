//
// Created by Piotr Żelazko on 13.01.2018.
//

#ifndef AAL_BOXES_PROGRAM_H
#define AAL_BOXES_PROGRAM_H

#include "units.h"

namespace boxes_aficionado {
	namespace program {
		class Program {
		public:
			Program() = default;

			virtual void run() = 0;

			virtual ~Program() = default;
		};
	}
}


#endif //AAL_BOXES_PROGRAM_H
