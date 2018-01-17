//
// Created by Piotr Żelazko on 17.01.2018.
//

#include "Vertex.h"

using namespace boxes_aficionado::algorithms::max_volume_first_algorithm;

MaxVolumeFirstAlgorithm *Vertex::manager_ = nullptr;

Vertex::Vertex(const boxes_aficionado::boxes::Box &box) :
		box_(box),
//	maxVolumeChildren_(comparator), //TODO
		child_(nullptr) {}

void Vertex::addChild(Vertex *childVertex) {
	children_.push_back(childVertex);
//	maxVolumeChildren_.push(childVertex); // TODO
}

void Vertex::addParent(Vertex *parent) {
	parents_.push_back(parent);
}

size_t Vertex::getInputsCount() {
	return children_.size();
}

boxes_aficionado::units::box_volume_t Vertex::getMaxChildVolumeBeside(Vertex *vertex) const {

	boxes_aficionado::units::box_volume_t maxChild = 0;

	for (auto child : children_)
		if (child != vertex && child->getVolume() > maxChild)
			maxChild = child->getVolume();

	return maxChild;
}

boxes_aficionado::units::box_volume_t Vertex::getVolume() const {
	return box_.getVolume();
}

void Vertex::removeChild(Vertex *vertex) {

	children_.remove(vertex);

	if (children_.size() == 0)
		registerAsVertexWithoutPendingChildren();

}

void Vertex::removeParent(Vertex *vertex) {
	parents_.remove(vertex);
}

void Vertex::assignChild(Vertex *vertex) {

	child_ = vertex;

	for (auto child : children_) {
		child->removeParent(this);
	}
}

void Vertex::appendOutputList(std::vector<boxes_aficionado::boxes::Box> &output) {

	if (child_) child_->appendOutputList(output);

	output.push_back(box_);

}

void Vertex::findParent() {

	Vertex *bestParent = nullptr;
	units::box_volume_t bestParentVolume = std::numeric_limits<units::box_volume_t>::max();

	for (auto parent : parents_) {
		auto volume = parent->getMaxChildVolumeBeside(this);
		if (volume == 0) {
			bestParent = parent;
			break;
		}
		if (volume <= getVolume() && volume < bestParentVolume) {
			bestParent = parent;
			bestParentVolume = volume;
		}
	}

	if (bestParent == nullptr) {
		registerAsPathHead();
	} else {
		bestParent->assignChild(this);
	}

	for (auto parent : parents_)
		parent->removeChild(this);

}

void Vertex::registerAsPathHead() {
	manager_->registerAsPathHead(this);
}

void Vertex::registerAsVertexWithoutPendingChildren() {
	manager_->registerAsVertexWithoutPendingChildren(this);
}

const boxes::Box &Vertex::getBox() {
	return box_;
}










