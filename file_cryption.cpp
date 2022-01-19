#include "BitMap.h"
#include <fstream>
#include <sstream>
#define FILE_SIZE 10*1024*1024

/*
* ���ܣ�ִ���ļ����ܽ���
* ������fstreamͷ�ļ��ṩ�ļ���д֧��
*		sstreamͷ�ļ��ṩstringstream֧��,����ת��string������
*		����rdbuf()�������ڽ�һ��������������һ�������
*		���½��ļ���ת��Ϊstring��
*		std::ifstream file("test.txt", std::ios::binary));
*		std::stringstream ss << file.rdbuf();
*		std::string s(ss.str());
*/

int FileCryption(const std::string directory_output, const std::string filename)
{
	//std::ios::binary�����Ƶײ�ϵͳ������ļ����ݽ��е��Զ�ת��;������������ϵͳ���Զ���'\n'תΪ'\r\n';
	std::ifstream file_read(filename, std::ios::binary);  //�����ƶ�ȡ�ļ���
	std::ofstream file_write(directory_output, std::ios::binary);  //������д���ļ���
	if (!file_read) {
		std::cout << filename << "�޷���ȡ�������ԣ�" << std::endl;
		return 1;  //��ͳ�����ϣ�return 1  ��ʾ�Ƿ�������return 0  ��ʾ����������
	}
	if (!file_write) {

		std::cout << filename << "�޷�д�룬�����ԣ�" << std::endl;
		return 1;  //��ͳ�����ϣ�return 1  ��ʾ�Ƿ�������return 0  ��ʾ����������
	}

	char* memory_buffer = new char[FILE_SIZE];  //�ļ������ڴ滺��������СΪ10MB
	std::string file_str;  //�ַ���ʽ��ȡ���ļ�

	while (!file_read.eof()) {  //�ֿ��ȡ���ļ���ÿ�ζ�ȡ10MB���ڴ��У�������ɺ�д�����ļ���
		file_read.read(memory_buffer, FILE_SIZE);
		file_str.assign(memory_buffer, file_read.gcount());  //gcount��������ʵ�ʶ�ȡ���ݴ�С
		for (int i = 0; i < file_str.length(); i++) {
			file_str[i] ^= char(0xFF);
			//file_write.put(file_read.get(char c) ^ char(0xFF));  //��λ������ַ��Ķ�������Ϊ01100000������11111111�������Ϊ10011111��
		}
		file_write.write(file_str.c_str(), file_read.gcount());
	}

	/*
	#һ���Զ�ȡ�����ļ������������ڴ棬������֧��2GB�����ļ�
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

	std::cout << filename << "������ɣ�" << std::endl;

	return 0;
}