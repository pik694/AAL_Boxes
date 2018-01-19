//
// Created by Piotr Żelazko on 13.01.2018.
//

#ifndef AAL_BOXES_FILERESULTPRINTER_H
#define AAL_BOXES_FILERESULTPRINTER_H

#include <fstream>
#include "ResultPrinter.h"


namespace boxes_aficionado {
	namespace program {
		namespace result_printer {
			class FileResultPrinter : public ResultPrinter {
			public:
				FileResultPrinter(std::ofstream &outFile) : outputFile_(std::move(outFile)) {
					outStream_ = &outputFile_;
				}

				~FileResultPrinter() override {
					outputFile_.close();
				}

			private:
				std::ofstream outputFile_;
			};
		}
	}
}

#endif //AAL_BOXES_FILERESULTPRINTER_H
