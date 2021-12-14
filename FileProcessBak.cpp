#include"BitMap.h"
#include"ThreadPool.h"

void FileProcessIn(const char* str1) {
	int i, j;		//文件名编号
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	ThreadPool pool(sysInfo.dwNumberOfProcessors);		//获取系统核心数量并生成对应数量线程池
	intptr_t Handle;		//用于获取目录下文件名
	std::vector< std::future<int> > results;		//用作多线程调用
	char str0[10] = "*.";
	strcat_s(str0, sizeof(str0), str1);
	cout << str0 << endl;		//输出用户指定的文件
	char filename[20];		//作为输出文件的文件名
	struct _finddata_t FileInfo;		//用于获取目录下文件名

	if ((Handle = (_findfirst(str0, &FileInfo))) == -1)
		cout << "File not found! Error!" << endl;
	else {
		char str[20] = ".\\BitMap\\%02d.";
		strcat_s(str, sizeof(str), str1);
		i = 1;
		sprintf_s((char*)filename, sizeof(filename), str, i);
		results.emplace_back(pool.enqueue(Encryption, FileInfo.name, filename));		//调用多线程
		cout << FileInfo.name << "\t";
		cout << filename << endl;
		j = 2;
		while (_findnext(Handle, &FileInfo) == 0)
		{
			sprintf_s((char*)filename, sizeof(filename), str, j);//指定文件名为从2开始的整数，每次加1
			j = j + 1;
			results.emplace_back(pool.enqueue(Encryption, FileInfo.name, filename));
			cout << FileInfo.name << "\t";
			cout << filename << endl;
		}
		_findclose(Handle);
	}
}

void FileProcessOut(const char* str1) {
	int i, j;		//文件名编号
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	ThreadPool pool(sysInfo.dwNumberOfProcessors);		//获取系统核心数量并生成对应数量线程池
	intptr_t Handle;		//用于获取目录下文件名
	std::vector< std::future<int> > results;		//用作多线程调用
	char str0[10] = "*.";
	strcat_s(str0, sizeof(str0), str1);
	cout << str0 << endl;		//输出用户指定的文件
	char filename[20];		//作为输出文件的文件名
	struct _finddata_t FileInfo;		//用于获取目录下文件名

	if ((Handle = (_findfirst(str0, &FileInfo))) == -1)
		cout << "File not found! Error!" << endl;
	else {
		char str[20] = ".\\BitMap\\%02d.";
		strcat_s(str, sizeof(str), str1);
		i = 1;
		sprintf_s((char*)filename, sizeof(filename), str, i);
		results.emplace_back(pool.enqueue(Decryption, FileInfo.name, filename));
		cout << FileInfo.name << "\t";
		cout << filename << endl;
		j = 2;
		while (_findnext(Handle, &FileInfo) == 0)
		{
			sprintf_s((char*)filename, sizeof(filename), str, j);//指定文件名为从2开始的整数，每次加1
			j = j + 1;
			results.emplace_back(pool.enqueue(Decryption, FileInfo.name, filename));
			cout << FileInfo.name << "\t";
			cout << filename << endl;
		}
		_findclose(Handle);
	}
}