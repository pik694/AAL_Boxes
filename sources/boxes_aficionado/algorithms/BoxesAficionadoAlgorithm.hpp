//
// Created by Piotr Żelazko on 02.12.2017.
//

#ifndef AAL_BOXES_BOXESAFICIONADOALGORITHM_HPP
#define AAL_BOXES_BOXESAFICIONADOALGORITHM_HPP

#include "Algorithm.hpp"

namespace boxes_aficionado::algorithms {
	class BoxesAficionadoAlgorithm : Algorithm {
	public:
		virtual result_t compute(std::vector<boxes::Box> vector) override;

	private:

	};

}


#endif //AAL_BOXES_BOXESAFICIONADOALGORITHM_HPP
