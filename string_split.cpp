#include "BitMap.h"

//用于字符串分割，返回vector
const std::vector<std::string> StringSplit(const std::string& str, const std::string& pattern) {
	std::vector<std::string> result;
	std::string::size_type begin, end;

	end = str.find(pattern);
	begin = 0;

	while (end != std::string::npos) {
		if (end - begin != 0) {
			result.push_back(str.substr(begin, end - begin));
		}
		begin = end + pattern.size();
		end = str.find(pattern, begin);
	}

	if (begin != str.length()) {
		result.push_back(str.substr(begin));
	}
	return result;
}