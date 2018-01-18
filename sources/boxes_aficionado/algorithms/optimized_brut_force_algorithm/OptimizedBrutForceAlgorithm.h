//
// Created by Piotr Żelazko on 17.01.2018.
//

#ifndef AAL_BOXES_OPTIMIZEDBRUTFORCEALGORITHM_H
#define AAL_BOXES_OPTIMIZEDBRUTFORCEALGORITHM_H

#include <algorithms/BrutForceAlgorithm.hpp>

namespace boxes_aficionado::algorithms::optimized_brut_force_algorithm{
	class OptimizedBrutForceAlgorithm : public BrutForceAlgorithm {
	public:
		OptimizedBrutForceAlgorithm() = default;

		result_t compute (std::vector<boxes::Box>) override;

		~OptimizedBrutForceAlgorithm() override = default;
	private:

	};
}



#endif //AAL_BOXES_OPTIMIZEDBRUTFORCEALGORITHM_H
