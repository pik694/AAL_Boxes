//
// Created by Piotr Żelazko on 13.11.2017.
//

#ifndef AAL_BOXES_BOX_HPP
#define AAL_BOXES_BOX_HPP

#include <iostream>
#include "units.h"

namespace boxes_aficionado::boxes {

	class Box{
	public:

		Box(units::box_size_t x, units::box_size_t y, units::box_size_t z);

		Box(const Box &) = default;

		units::box_volume_t getVolume() const;

		bool fits(const Box&) const;

		int getID() const;

		std::tuple<units::box_size_t, units::box_size_t, units::box_size_t> getMeasures() const {
			return std::make_tuple(x_, y_, z_);
		};

		bool operator<(const Box& rBox) const{
			return this->volume_ < rBox.volume_;
		}
		bool operator>(const Box& rBox) const{
			return this->volume_ > rBox.volume_;
		}
		bool operator<=(const Box& rBox) const{
			return !(this->operator>(rBox));
		}
		bool operator>=(const Box& rBox) const{
			return !(this->operator<(rBox));
		}

		friend std::ostream &operator<<(std::ostream &, const Box &);

	private:
		units::box_size_t x_;
		units::box_size_t y_;
		units::box_size_t z_;
		units::box_volume_t volume_;
		int id_;
		static int currID_;

	};
}

#endif //AAL_BOXES_BOX_HPP
