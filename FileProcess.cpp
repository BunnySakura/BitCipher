#include"BitMap.h"
#include"ThreadPool.h"

void FileProcessIn(string file_suffix,string folder_path) {
	unsigned int cpu_threads = std::thread::hardware_concurrency();		//获取系统逻辑核心数量
	ThreadPool pool(cpu_threads);		//生成对应数量减二的线程池，保留线程用于确保程序正常运行
	intptr_t Handle;		//用于获取目录下文件名
	std::vector< std::future<int> > results;		//用作多线程调用
	string search_file;
	search_file = "*." + file_suffix;
	cout << search_file << endl << endl;		//输出用户指定的文件
	string filename;		//作为输出文件的文件名
	struct _finddata_t FileInfo;		//用于获取目录下文件名

	if ((Handle = (_findfirst(search_file.c_str(), &FileInfo))) == -1)
		cout << "File not found! Error!" << endl;
	else {
		filename = folder_path + (string)FileInfo.name;
		results.emplace_back(pool.enqueue(Encryption, FileInfo.name, filename.c_str()));		//调用多线程
		cout << FileInfo.name << "\t----->" << filename << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));		//阻塞当前主线程，避免竞争
		while (_findnext(Handle, &FileInfo) == 0)
		{
			filename = folder_path + (string)FileInfo.name;
			results.emplace_back(pool.enqueue(Encryption, FileInfo.name, filename.c_str()));
			cout << FileInfo.name << "\t----->" << filename << endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));		//阻塞当前主线程，避免竞争
		}
		_findclose(Handle);
	}
}

void FileProcessOut(string file_suffix,string folder_path) {
	unsigned int cpu_threads = std::thread::hardware_concurrency();		//获取系统逻辑核心数量
	ThreadPool pool(cpu_threads);		//生成对应数量减二的线程池，保留线程用于确保程序正常运行
	intptr_t Handle;		//用于获取目录下文件名
	std::vector< std::future<int> > results;		//用作多线程调用
	string search_file;
	search_file = "*." + file_suffix;
	cout << search_file << endl;		//输出用户指定的文件
	string filename;		//作为输出文件的文件名
	struct _finddata_t FileInfo;		//用于获取目录下文件名

	if ((Handle = (_findfirst(search_file.c_str(), &FileInfo))) == -1)
		cout << "File not found! Error!" << endl;
	else {
		filename = folder_path + (string)FileInfo.name;
		results.emplace_back(pool.enqueue(Decryption, FileInfo.name, filename.c_str()));		//调用多线程
		cout << FileInfo.name << "\t----->" << filename << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));		//阻塞当前主线程，避免竞争
		while (_findnext(Handle, &FileInfo) == 0)
		{
			filename = folder_path + (string)FileInfo.name;
			results.emplace_back(pool.enqueue(Decryption, FileInfo.name, filename.c_str()));
			cout << FileInfo.name << "\t----->" << filename << endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));		//阻塞当前主线程，避免竞争
		}
		_findclose(Handle);
	}
}