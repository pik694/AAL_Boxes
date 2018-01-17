//
// Created by Piotr Żelazko on 17.01.2018.
//

#ifndef AAL_BOXES_VERTEX_H
#define AAL_BOXES_VERTEX_H

#include <boxes/Box.hpp>
#include <list>
#include <queue>

namespace boxes_aficionado::algorithms::max_volume_first_algorithm {
	class Vertex;
}

#include "MaxVolumeFirstAlgorithm.hpp"

namespace boxes_aficionado::algorithms::max_volume_first_algorithm {
	class Vertex {
	public:
		static MaxVolumeFirstAlgorithm *manager_;

		explicit Vertex(const boxes_aficionado::boxes::Box &);

		void findParent();

		void addChild(Vertex *);

		void addParent(Vertex *);

		void appendOutputList(std::vector<boxes::Box> &);

		size_t getInputsCount();

		units::box_volume_t getVolume() const;

		const boxes::Box &getBox();

	private:

		void registerAsVertexWithoutPendingChildren();

		void registerAsPathHead();

		units::box_volume_t getMaxChildVolumeBeside(Vertex *) const;


		void removeParent(Vertex *);

		void removeChild(Vertex *);

		void assignChild(Vertex *);

		const boxes_aficionado::boxes::Box box_;


		std::list<Vertex *> children_;
		std::list<Vertex *> parents_;

		Vertex *child_;

	};
}

#endif //AAL_BOXES_VERTEX_H
