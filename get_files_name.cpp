#include "BitMap.h"

/*
* 标准：C++17
* 功能：遍历指定路径的文件和文件夹
* 依赖：filesystem头文件，即C++17拥有的特性
*/

//测试用例：遍历路径下的文件及文件夹并输出
//void ProcessPath(const filesystem::path& path_to_show) {
//	if (!exists(path_to_show)) {  //目录不存在直接返回
//		return;
//	}
//	auto begin = filesystem::recursive_directory_iterator(path_to_show);  //获取文件系统迭代器
//	auto end = filesystem::recursive_directory_iterator();  //end迭代器 
//	for (auto& it = begin; it != end; it++) {
//		const string spacer(it.depth() * 2.0, ' ');  //这个是用来缩进排版的空格
//		auto& entry = *it;
//		if (filesystem::is_regular_file(entry)) {  //如果是文件
//			cout << spacer << "File:" << entry;
//			cout << "(" << filesystem::file_size(entry) << " bytes )" << endl;
//		}
//		else if (filesystem::is_directory(entry)) {  //如果是目录
//			cout << spacer << "Dir:" << entry << endl;
//		}
//		else {
//			cout << spacer << "???:" << entry << endl;
//		}
//	}
//}

std::queue<std::string> GetFilesName(const std::filesystem::path& path_to_show) {
	std::queue<std::string> filenames;  //包含文件名绝对路径的队列
	if (!std::filesystem::exists(path_to_show)) {  //目录不存在直接返回
		filenames.push(path_to_show.string() + "----->目录不存在！\n");
		return filenames;
	}

	auto begin = std::filesystem::recursive_directory_iterator(path_to_show);  //获取文件系统迭代器
	auto end = std::filesystem::recursive_directory_iterator();  //end迭代器 
	for (auto& it = begin; it != end; it++) {
		auto& entry = *it;
		if (std::filesystem::is_regular_file(entry)) {  //如果是文件
			filenames.push(entry.path().string());  //获取文件名绝对路径添加至队列
		}
	}

	//path_to_show = { argc >= 2 ? argv[1] : filesystem::current_path() };
	return filenames;
}

int UnitTest(char* path)
{
	std::filesystem::path path_name(path);
	std::queue<std::string> filenames = GetFilesName(path_name);
	while (!filenames.empty())
	{
		std::cout << path << filenames.front() << std::endl;
		filenames.pop();
	}

	return 0;
}