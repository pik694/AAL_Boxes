//
// Created by Piotr Żelazko on 02.12.2017.
//

#include "MaxVolumeFirstAlgorithm.hpp"

using namespace boxes_aficionado::algorithms::max_volume_first_algorithm;

bool Compare::operator()(const Vertex *v1, const Vertex *v2) {
	return v1->getVolume() < v2->getVolume();
}


MaxVolumeFirstAlgorithm::MaxVolumeFirstAlgorithm() {
	Vertex::manager_ = this;
}


void MaxVolumeFirstAlgorithm::createConnections() {

	vertices_.reserve(boxes_.size());

	for (auto box : boxes_) {
		vertices_.emplace_back(box);
		auto currentVertex = --vertices_.end();

		for (auto vertexIt = vertices_.begin(); vertexIt != vertices_.end(); ++vertexIt) {
			if (vertexIt != currentVertex) {
				if (vertexIt->getBox().fits(currentVertex->getBox())) {
					vertexIt->addParent(&*currentVertex);
					currentVertex->addChild(&*vertexIt);
				} else if (currentVertex->getBox().fits(vertexIt->getBox())) {
					vertexIt->addChild(&*currentVertex);
					currentVertex->addParent(&*vertexIt);
				}
			}
		}
	}
}

void MaxVolumeFirstAlgorithm::registerAsPathHead(Vertex *vertex) {
	headsOfPaths_.push_back(vertex);
}

void MaxVolumeFirstAlgorithm::registerAsVertexWithoutPendingChildren(Vertex *vertex) {
	verticesWithoutPendingChildren_.push(vertex);
}

algorithms::Algorithm::result_t MaxVolumeFirstAlgorithm::compute(std::vector<boxes::Box> vector) {

	boxes_ = std::move(vector);
	createConnections();

	for (auto &vertex : vertices_)
		if (vertex.getInputsCount() == 0)
			verticesWithoutPendingChildren_.push(&vertex);

	while (!verticesWithoutPendingChildren_.empty()) {

		auto vertex = verticesWithoutPendingChildren_.top();
		verticesWithoutPendingChildren_.pop();
		vertex->findParent();

	}

	std::vector<boxes::Box> resultingSequence;


	for (auto head : headsOfPaths_) {
		head->appendOutputList(resultingSequence);
	}

	units::box_volume_t resultingVolume = getVolume(resultingSequence);

	return std::make_pair(std::move(resultingSequence), resultingVolume);


}

