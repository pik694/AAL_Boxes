//
// Created by Piotr Żelazko on 13.01.2018.
//

#ifndef AAL_BOXES_RESULTPRINTER_H
#define AAL_BOXES_RESULTPRINTER_H

#include "algorithms/Algorithm.hpp"

namespace boxes_aficionado {
	namespace program {
		namespace result_printer {
			class ResultPrinter {
			public:
				ResultPrinter() : outStream_(&std::cout) {}

				virtual void printBoxes(const std::vector<boxes::Box> &boxes) {

					(*outStream_) << boxes.size() << "\n";

					for (auto &box : boxes) {
						auto measures = box.getMeasures();

						(*outStream_) << std::get<0>(measures) << " "
						              << std::get<1>(measures) << " "
						              << std::get<2>(measures) << "\n";
					}

					(*outStream_) << std::endl;

				}

				virtual void printResult(const algorithms::Algorithm::result_t &result) {
					auto boxes = result.first;
					auto volume = result.second;

					units::box_volume_t maxVolume = 0;

					for (auto &box : boxes) {
						(*outStream_) << box.getID() << " ";
						maxVolume += box.getVolume();
					}
					(*outStream_) << "\n" << maxVolume << "->" << volume << std::endl;

				}

				virtual ~ResultPrinter() = default;

			protected:
				std::ostream *outStream_;
			};

		}
	}
}


#endif //AAL_BOXES_RESULTPRINTER_H
