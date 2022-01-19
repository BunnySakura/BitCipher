#include "BitMap.h"

/*
* ��׼��C++17
* ���ܣ�����ָ��·�����ļ����ļ���
* ������filesystemͷ�ļ�����C++17ӵ�е�����
*/

//��������������·���µ��ļ����ļ��в����
//void ProcessPath(const filesystem::path& path_to_show) {
//	if (!exists(path_to_show)) {  //Ŀ¼������ֱ�ӷ���
//		return;
//	}
//	auto begin = filesystem::recursive_directory_iterator(path_to_show);  //��ȡ�ļ�ϵͳ������
//	auto end = filesystem::recursive_directory_iterator();  //end������ 
//	for (auto& it = begin; it != end; it++) {
//		const string spacer(it.depth() * 2.0, ' ');  //��������������Ű�Ŀո�
//		auto& entry = *it;
//		if (filesystem::is_regular_file(entry)) {  //������ļ�
//			cout << spacer << "File:" << entry;
//			cout << "(" << filesystem::file_size(entry) << " bytes )" << endl;
//		}
//		else if (filesystem::is_directory(entry)) {  //�����Ŀ¼
//			cout << spacer << "Dir:" << entry << endl;
//		}
//		else {
//			cout << spacer << "???:" << entry << endl;
//		}
//	}
//}

std::queue<std::string> GetFilesName(const std::filesystem::path& path_to_show) {
	std::queue<std::string> filenames;  //�����ļ�������·���Ķ���
	if (!std::filesystem::exists(path_to_show)) {  //Ŀ¼������ֱ�ӷ���
		filenames.push(path_to_show.string() + "----->Ŀ¼�����ڣ�\n");
		return filenames;
	}

	auto begin = std::filesystem::recursive_directory_iterator(path_to_show);  //��ȡ�ļ�ϵͳ������
	auto end = std::filesystem::recursive_directory_iterator();  //end������ 
	for (auto& it = begin; it != end; it++) {
		auto& entry = *it;
		if (std::filesystem::is_regular_file(entry)) {  //������ļ�
			filenames.push(entry.path().string());  //��ȡ�ļ�������·�����������
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