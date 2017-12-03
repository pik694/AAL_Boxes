//
// Created by Piotr Żelazko on 02.12.2017.
//

#ifndef AAL_BOXES_BOXESAFICIONADOALGORITHM_HPP
#define AAL_BOXES_BOXESAFICIONADOALGORITHM_HPP

#include "Algorithm.hpp"

namespace boxes_aficionado::algorithms {
	class BoxesAficionadoAlgorithm : Algorithm {
	public:
		virtual std::pair<std::vector<Box>, uint64_t> compute(std::vector<Box> vector) override;

	private:

	};

}


#endif //AAL_BOXES_BOXESAFICIONADOALGORITHM_HPP
