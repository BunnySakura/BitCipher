#ifndef _BitMap_h_
#define _BitMap_h_

#include <string>
#include <iostream>
#include <queue>
#include <filesystem>
#include "ThreadPool.h"


//�ļ����������������������Ŀ¼��Դ�ļ�·��
int FileCryption(const std::string directory_output, const std::string filename);
//�����ļ�·��
std::queue<std::string> GetFilesName(const std::filesystem::path& path_to_show);
//������
int UnitTest(char* path);
//�����ַ����ָ�������������ַ������ָ��ַ�������vector
const std::vector<std::string> StringSplit(const std::string& str, const std::string& pattern);


#endif // !_BitMap_h_