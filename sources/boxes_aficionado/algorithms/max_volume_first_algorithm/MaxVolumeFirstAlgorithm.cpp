//
// Created by Piotr Żelazko on 02.12.2017.
//

#include "MaxVolumeFirstAlgorithm.hpp"

using namespace boxes_aficionado::algorithms::max_volume_first_algorithm;

const auto comparator = [](const Vertex *v1, const Vertex *v2) {
	return v1->getVolume() > v2->getVolume();
};

MaxVolumeFirstAlgorithm::MaxVolumeFirstAlgorithm() :
		verticesWithoutPendingChildren_(comparator) {
	Vertex::manager_ = this;
}


void MaxVolumeFirstAlgorithm::createConnections() {

	for (auto box : boxes_) {
		vertices_.emplace_back(std::move(box));
		auto &currentVertex = vertices_.back();

		for (auto &vertex : vertices_) {
			if (&vertex != &currentVertex) {
				if (vertex.getBox().fits(currentVertex.getBox())) {
					vertex.addParent(&currentVertex);
					currentVertex.addChild(&vertex);
				} else if (currentVertex.getBox().fits(vertex.getBox())) {
					vertex.addChild(&currentVertex);
					currentVertex.addParent(&vertex);
				}
			}
		}
	}

}

void MaxVolumeFirstAlgorithm::registerAsPathHead(Vertex *vertex) {
	headsOfPaths_.push_back(vertex);
}

void MaxVolumeFirstAlgorithm::registerAsVertexWithoutPendingChildren(Vertex *vertex) {
//	verticesWithoutPendingChildren_.push(vertex);
}

algorithms::Algorithm::result_t MaxVolumeFirstAlgorithm::compute(std::vector<boxes::Box> vector) {

	boxes_ = std::move(vector);
	createConnections();

	for (auto &vertex : vertices_)
		if (vertex.getInputsCount() == 0)
//			verticesWithoutPendingChildren_.push(&vertex);

			while (!verticesWithoutPendingChildren_.empty()) {

//		auto vertex = verticesWithoutPendingChildren_.top();
//		verticesWithoutPendingChildren_.pop();
//		vertex->findParent();

			}

	std::vector<boxes::Box> resultingSequence;


	for (auto head : headsOfPaths_) {
		head->appendOutputList(resultingSequence);
	}

	units::box_volume_t resultingVolume = getVolume(resultingSequence);

	return std::make_pair(std::move(resultingSequence), resultingVolume);


}

