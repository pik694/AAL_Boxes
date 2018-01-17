//
// Created by Piotr Żelazko on 13.11.2017.
//

#include "Box.hpp"

using namespace boxes_aficionado::boxes;

int Box::currID_ = 0;


Box::Box(uint16_t x, uint16_t y, uint16_t z) : x_(x), y_(y), z_(z), volume_(x * y * z), id_(currID_++) {}

int Box::getID() const {
	return id_;
}

uint64_t Box::getVolume() const {
	return volume_;
}

bool Box::fits(const Box& anotherBox) const{

	if (volume_ >= anotherBox.volume_) return false;

	return ((x_ < anotherBox.x_ && y_ < anotherBox.y_ && z_ < anotherBox.z_)
	        || (x_ < anotherBox.x_ && y_ < anotherBox.z_ && z_ < anotherBox.y_)
	        || (x_ < anotherBox.y_ && y_ < anotherBox.x_ && z_ < anotherBox.z_)
	        || (x_ < anotherBox.y_ && y_ < anotherBox.z_ && z_ < anotherBox.x_)
	        || (x_ < anotherBox.z_ && y_ < anotherBox.x_ && z_ < anotherBox.y_)
	        || (x_ < anotherBox.z_ && y_ < anotherBox.y_ && z_ < anotherBox.x_));
}


namespace boxes_aficionado::boxes {
	std::ostream &operator<<(std::ostream &out, const Box &box) {
		return out << box.x_ << " " << box.y_ << " " << box.z_;
	}
}


