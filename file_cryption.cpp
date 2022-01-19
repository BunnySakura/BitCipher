#include "BitMap.h"
#include <fstream>
#include <sstream>
#define FILE_SIZE 10*1024*1024

/*
* 功能：执行文件加密解密
* 依赖：fstream头文件提供文件读写支持
*		sstream头文件提供stringstream支持,用于转换string的类型
*		流的rdbuf()方法用于将一个流的内容用另一个流输出
*		如下将文件流转换为string：
*		std::ifstream file("test.txt", std::ios::binary));
*		std::stringstream ss << file.rdbuf();
*		std::string s(ss.str());
*/

int FileCryption(const std::string directory_output, const std::string filename)
{
	//std::ios::binary是抑制底层系统服务对文件内容进行的自动转换;如果不加这个，系统会自动把'\n'转为'\r\n';
	std::ifstream file_read(filename, std::ios::binary);  //二进制读取文件流
	std::ofstream file_write(directory_output, std::ios::binary);  //二进制写入文件流
	if (!file_read) {
		std::cout << filename << "无法读取，请重试！" << std::endl;
		return 1;  //传统意义上，return 1  表示非法结束；return 0  表示正常结束；
	}
	if (!file_write) {

		std::cout << filename << "无法写入，请重试！" << std::endl;
		return 1;  //传统意义上，return 1  表示非法结束；return 0  表示正常结束；
	}

	char* memory_buffer = new char[FILE_SIZE];  //文件流的内存缓冲区，大小为10MB
	std::string file_str;  //字符格式读取的文件

	while (!file_read.eof()) {  //分块读取大文件，每次读取10MB至内存中，处理完成后写入至文件内
		file_read.read(memory_buffer, FILE_SIZE);
		file_str.assign(memory_buffer, file_read.gcount());  //gcount方法返回实际读取数据大小
		for (int i = 0; i < file_str.length(); i++) {
			file_str[i] ^= char(0xFF);
			//file_write.put(file_read.get(char c) ^ char(0xFF));  //逐位输出，字符的二进制码为01100000，它与11111111作异或后变为10011111；
		}
		file_write.write(file_str.c_str(), file_read.gcount());
	}

	/*
	#一次性读取整个文件，极其消耗内存，且最大仅支持2GB左右文件
		sstring_buffer << file_read.rdbuf();
		file_str = sstring_buffer.str();
		for (int i = 0; i < file_str.length(); i++) {
			file_str[i] ^= char(0xFF);
		}
		file_write << file_str;
	*/


	delete[] memory_buffer;
	file_read.close();
	file_write.close();

	std::cout << filename << "处理完成！" << std::endl;

	return 0;
}