#ifndef _BitMap_h_
#define _BitMap_h_

#include <string>
#include <iostream>
#include <queue>
#include <filesystem>
#include "ThreadPool.h"


//文件处理主函数，参数：输出目录、源文件路径
int FileCryption(const std::string directory_output, const std::string filename);
//遍历文件路径
std::queue<std::string> GetFilesName(const std::filesystem::path& path_to_show);
//测试用
int UnitTest(char* path);
//用于字符串分割，参数：待处理字符串、分割字符，返回vector
const std::vector<std::string> StringSplit(const std::string& str, const std::string& pattern);


#endif // !_BitMap_h_