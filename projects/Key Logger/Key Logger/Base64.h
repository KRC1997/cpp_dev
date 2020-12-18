#pragma once

/*
	This header contains functions for encryption of the Keys being logged

	It uses base 64 algorithm for encryption
*/
#ifndef _BASE64_H_
#define _BASE64_H_

#include <vector>
#include <string>

namespace BASE64 {

	// these 3 are custom. you can use your own
	const std::string& SALT1 = "LM::TB::BB";
	const std::string& SALT2 = "_:/_77";
	const std::string& SALT3 = "line=wowC++";

	const std::string& BASE64_CODES = 
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	auto base64_encode(const std::string& s)->std::string {
		std::string ret;
		int val = 0;
		int bits = -6;
		const unsigned int b63 = 0x3F;

		for (const auto& c : s) {
			val = (val << 8) + c;
			bits += 8;
			while (bits >= 0) {
				ret.push_back(BASE64_CODES[(val >> bits)& b63]);
				bits -= 6;
			}
		}

		if (bits > -6) {
			ret.push_back(BASE64_CODES[((val << 8) >> (bits + 8))& b63]);
		}

		while (ret.size() % 4)
			ret.push_back('-');

		return ret;
	}

	auto EncryptB64(std::string s)->std::string {
		// play around with s in any way you want to
		s = SALT1 + s + SALT2 + SALT3;
		s = base64_encode(s);
		s.insert(7, SALT3); // you can write any SALT here
		s += SALT1;
		return s;
	}
}

#endif // _BASE64_H_