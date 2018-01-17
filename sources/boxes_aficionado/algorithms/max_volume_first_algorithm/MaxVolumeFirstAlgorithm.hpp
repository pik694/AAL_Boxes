//
// Created by Piotr Żelazko on 02.12.2017.
//

#ifndef AAL_BOXES_BOXESAFICIONADOALGORITHM_HPP
#define AAL_BOXES_BOXESAFICIONADOALGORITHM_HPP

#include "algorithms/Algorithm.hpp"

namespace boxes_aficionado::algorithms::max_volume_first_algorithm {
	class MaxVolumeFirstAlgorithm;
}

#include "Vertex.h"

namespace boxes_aficionado::algorithms {
	namespace max_volume_first_algorithm {

		struct Compare{
			bool operator()(const Vertex* v1, const Vertex* v2);
		};

		class MaxVolumeFirstAlgorithm : public boxes_aficionado::algorithms::Algorithm {
		public:
			MaxVolumeFirstAlgorithm();

			result_t compute(std::vector<boxes::Box> vector) override;

			void registerAsPathHead(Vertex *);

			void registerAsVertexWithoutPendingChildren(Vertex *);

			~MaxVolumeFirstAlgorithm() override = default;

		private:
			void createConnections();

			std::vector<boxes::Box> boxes_;
			std::vector<Vertex> vertices_;


			using container_t = std::vector<Vertex *>;

			std::priority_queue<Vertex *, container_t, Compare> verticesWithoutPendingChildren_;
			std::list<Vertex *> headsOfPaths_;
		};
	}
}


#endif //AAL_BOXES_BOXESAFICIONADOALGORITHM_HPP
