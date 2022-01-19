#include "BitMap.h"
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )  //ȥ����̨����

int main(int argc, char** argv) {
	std::string temp_string;  //�����ַ���ת������ʱstring
	//�жϲ����Ƿ���ϱ�׼
	if (argc < 4) {
		std::cout << "�������㣬�����ԣ�" << std::endl;
		return -1;
	}
	else if (argc == 4) {
		if (argv[1] == std::string("��ѡ��������ļ�����·��")) {
			std::cout << "�������ļ�·����ֹĬ��ֵ��" << std::endl;
			return 1;
		}
		if (argv[2] == std::string("��ѡ������ļ�����·��")) {
			temp_string = std::filesystem::current_path().string();
			argv[2] = (char*)temp_string.c_str();  //��Ϊ��ǰ·��,current_path()�ɻ�ȡ��ǰĿ¼
			std::cout << "�ļ�����·�����޸�Ϊ��ǰ·����" << argv[2] << std::endl;
		}
		if (atoi(argv[3]) < 1 || atoi(argv[3]) > 256) {
			itoa(4, argv[3], 10);
			std::cout << "��ѡ��1-256���ڵ��߳���!\n�߳������޸�ΪĬ��ֵ��4" << std::endl;
		}
	}
	else {
		std::cout << "��ֵĲ���̫���ˣ��Ѿ��������ˣ�" << std::endl;
		return -2;
	}

	std::filesystem::path path_name(argv[1]);  //�������ļ�����·��
	std::queue<std::string> filenames = GetFilesName(path_name);  //�����ļ�������·���Ķ���

	const std::string directory_input(argv[1]);  //����1���������ļ�·��
	const std::string directory_output(argv[2]);  //����2��������ļ�·��
	const int threads_quantity = atoi(argv[3]);  //����3���߳���
	std::cout << "�������ļ�����·����" << argv[1] << std::endl << "������ļ�����·����" << argv[2] << std::endl << "ʹ���߳�����" << argv[3] << std::endl;

	ThreadPool pool(threads_quantity);  //���ɶ�Ӧ�����������̳߳أ������߳�����ȷ��������������
	std::vector< std::future<int> > results;  //�������̵߳���

	while (!filenames.empty())
	{
		std::string target_filename(StringSplit(filenames.front(), "\\").back());  //�ļ���
		std::string target_dictory(directory_output + (std::string(filenames.front()).erase(0, directory_input.length())));  //������ļ��ľ���·��
		target_dictory.erase(target_dictory.length() - target_filename.length(), target_filename.length());
		std::filesystem::create_directories(target_dictory);  //���������ļ������ļ������Ҹ��ļ��в����ڣ��򴴽�֮
		results.emplace_back(pool.enqueue(FileCryption, target_dictory + target_filename, filenames.front()));
		//std::this_thread::sleep_for(std::chrono::microseconds(100));  //������ǰ���߳�100ms�����⾺��
		filenames.pop();
	}

	return 0;
}