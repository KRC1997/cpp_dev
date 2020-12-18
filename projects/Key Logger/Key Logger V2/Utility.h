#pragma once

#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <sstream>

namespace Utility{

	template <typename T>
	std::string ToString(const T& object) {
		std::ostringstream output_string_stream;
		output_string_stream << object;
		return output_string_stream.str();
	}

}

#endif // _UTILITY_H_