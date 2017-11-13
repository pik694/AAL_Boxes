//
// Created by Piotr Żelazko on 13.11.2017.
//

#ifndef AAL_BOXES_ALGORITHMSELECTOR_HPP
#define AAL_BOXES_ALGORITHMSELECTOR_HPP

#include <string>
#include "Algorithm.hpp"
#include "BrutForceAlgorithm.hpp"

namespace boxes_aficionado::algorithms{

	class AlgorithmSelector{
	public:

		inline static std::shared_ptr<Algorithm> getAlgorithm(std::string algorithm){
			if (algorithm == "-brut")
				return std::make_shared<BrutForceAlgorithm>();
			throw std::invalid_argument("Unexpected algorithm value : " + algorithm);
		}
	};
}


#endif //AAL_BOXES_ALGORITHMSELECTOR_HPP
