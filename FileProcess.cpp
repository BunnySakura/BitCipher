#include"BitMap.h"
#include"ThreadPool.h"

void FileProcessIn(string file_suffix,string folder_path) {
	unsigned int cpu_threads = std::thread::hardware_concurrency();		//��ȡϵͳ�߼���������
	ThreadPool pool(cpu_threads);		//���ɶ�Ӧ�����������̳߳أ������߳�����ȷ��������������
	intptr_t Handle;		//���ڻ�ȡĿ¼���ļ���
	std::vector< std::future<int> > results;		//�������̵߳���
	string search_file;
	search_file = "*." + file_suffix;
	cout << search_file << endl << endl;		//����û�ָ�����ļ�
	string filename;		//��Ϊ����ļ����ļ���
	struct _finddata_t FileInfo;		//���ڻ�ȡĿ¼���ļ���

	if ((Handle = (_findfirst(search_file.c_str(), &FileInfo))) == -1)
		cout << "File not found! Error!" << endl;
	else {
		filename = folder_path + (string)FileInfo.name;
		results.emplace_back(pool.enqueue(Encryption, FileInfo.name, filename.c_str()));		//���ö��߳�
		cout << FileInfo.name << "\t----->" << filename << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));		//������ǰ���̣߳����⾺��
		while (_findnext(Handle, &FileInfo) == 0)
		{
			filename = folder_path + (string)FileInfo.name;
			results.emplace_back(pool.enqueue(Encryption, FileInfo.name, filename.c_str()));
			cout << FileInfo.name << "\t----->" << filename << endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));		//������ǰ���̣߳����⾺��
		}
		_findclose(Handle);
	}
}

void FileProcessOut(string file_suffix,string folder_path) {
	unsigned int cpu_threads = std::thread::hardware_concurrency();		//��ȡϵͳ�߼���������
	ThreadPool pool(cpu_threads);		//���ɶ�Ӧ�����������̳߳أ������߳�����ȷ��������������
	intptr_t Handle;		//���ڻ�ȡĿ¼���ļ���
	std::vector< std::future<int> > results;		//�������̵߳���
	string search_file;
	search_file = "*." + file_suffix;
	cout << search_file << endl;		//����û�ָ�����ļ�
	string filename;		//��Ϊ����ļ����ļ���
	struct _finddata_t FileInfo;		//���ڻ�ȡĿ¼���ļ���

	if ((Handle = (_findfirst(search_file.c_str(), &FileInfo))) == -1)
		cout << "File not found! Error!" << endl;
	else {
		filename = folder_path + (string)FileInfo.name;
		results.emplace_back(pool.enqueue(Decryption, FileInfo.name, filename.c_str()));		//���ö��߳�
		cout << FileInfo.name << "\t----->" << filename << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));		//������ǰ���̣߳����⾺��
		while (_findnext(Handle, &FileInfo) == 0)
		{
			filename = folder_path + (string)FileInfo.name;
			results.emplace_back(pool.enqueue(Decryption, FileInfo.name, filename.c_str()));
			cout << FileInfo.name << "\t----->" << filename << endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));		//������ǰ���̣߳����⾺��
		}
		_findclose(Handle);
	}
}