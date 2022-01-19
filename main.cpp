#include "BitMap.h"
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )  //去控制台窗口

int main(int argc, char** argv) {
	std::string temp_string;  //用于字符串转换的临时string
	//判断参数是否符合标准
	if (argc < 4) {
		std::cout << "参数不足，请重试！" << std::endl;
		return -1;
	}
	else if (argc == 4) {
		if (argv[1] == std::string("请选择待处理文件所在路径")) {
			std::cout << "待处理文件路径禁止默认值！" << std::endl;
			return 1;
		}
		if (argv[2] == std::string("请选择处理后文件保存路径")) {
			temp_string = std::filesystem::current_path().string();
			argv[2] = (char*)temp_string.c_str();  //改为当前路径,current_path()可获取当前目录
			std::cout << "文件保存路径已修改为当前路径：" << argv[2] << std::endl;
		}
		if (atoi(argv[3]) < 1 || atoi(argv[3]) > 256) {
			itoa(4, argv[3], 10);
			std::cout << "请选择1-256以内的线程数!\n线程数已修改为默认值：4" << std::endl;
		}
	}
	else {
		std::cout << "奇怪的参数太多了，已经塞不下了！" << std::endl;
		return -2;
	}

	std::filesystem::path path_name(argv[1]);  //待处理文件所在路径
	std::queue<std::string> filenames = GetFilesName(path_name);  //包含文件名绝对路径的队列

	const std::string directory_input(argv[1]);  //参数1：待处理文件路径
	const std::string directory_output(argv[2]);  //参数2：处理后文件路径
	const int threads_quantity = atoi(argv[3]);  //参数3：线程数
	std::cout << "待处理文件所在路径：" << argv[1] << std::endl << "处理后文件保存路径：" << argv[2] << std::endl << "使用线程数：" << argv[3] << std::endl;

	ThreadPool pool(threads_quantity);  //生成对应数量减二的线程池，保留线程用于确保程序正常运行
	std::vector< std::future<int> > results;  //用作多线程调用

	while (!filenames.empty())
	{
		std::string target_filename(StringSplit(filenames.front(), "\\").back());  //文件名
		std::string target_dictory(directory_output + (std::string(filenames.front()).erase(0, directory_input.length())));  //处理后文件的绝对路径
		target_dictory.erase(target_dictory.length() - target_filename.length(), target_filename.length());
		std::filesystem::create_directories(target_dictory);  //如果处理后文件在子文件夹中且该文件夹不存在，则创建之
		results.emplace_back(pool.enqueue(FileCryption, target_dictory + target_filename, filenames.front()));
		//std::this_thread::sleep_for(std::chrono::microseconds(100));  //阻塞当前主线程100ms，避免竞争
		filenames.pop();
	}

	return 0;
}