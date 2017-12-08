//
// Created by Piotr Żelazko on 13.11.2017.
//

#ifndef AAL_BOXES_BOX_HPP
#define AAL_BOXES_BOX_HPP

#include <cstdint>

namespace boxes_aficionado {

	class Box{
	public:

		Box(uint16_t x, uint16_t y, uint16_t z);

		uint64_t getVolume() const;

		bool fits(const Box&) const;

		int getID() const;

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

	private:
		uint16_t x_;
		uint16_t y_;
		uint16_t z_;
		uint64_t volume_;
		int id_;
		static int currID_;

	};
}

#endif //AAL_BOXES_BOX_HPP
