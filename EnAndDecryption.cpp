#include"BitMap.h"

int Encryption(string file_in, string file_out)
{
	ifstream file_read;
	file_read.open(file_in, ios::binary);   //ios::binary�����Ƶײ�ϵͳ������ļ����ݽ��е��Զ�ת��;������������ϵͳ���Զ���'\n'תΪ'\r\n';
	if (!file_read)
	{
		cout << file_in << "�޷���ȡ�������ԣ�����������������" << endl;
		return 1;
	}
	//һ���Զ�ȡ�����ļ�
	stringstream buffer;
	buffer << file_read.rdbuf();
	string FileStr(buffer.str());
	for (int i = 0; i < FileStr.length(); i++) {
		FileStr[i] ^= char(0xFF);
		//file_write.put(FileStr[i] ^ char(0xFF));		//��λ������ַ��Ķ�������Ϊ01100000������11111111�������Ϊ10011111��
	}
	file_read.close();


	ofstream file_write;
	file_write.open(file_out, ios::binary);
	if (!file_write) {

		cout << file_out << "�޷�д�룬�����ԣ�����������������" << endl;
		return 1;     //��ͳ�����ϣ�return 1  ��ʾ�Ƿ�������return 0  ��ʾ����������
	}
	file_write << FileStr;
	file_write.close();

	cout << file_in << "������ɣ�" << endl;		//������

	return 0;
}

int Decryption(string file_in, string file_out)
{
	ifstream file_read;
	file_read.open(file_in, ios::binary);   //ios::binary�����Ƶײ�ϵͳ������ļ����ݽ��е��Զ�ת��;������������ϵͳ���Զ���'\n'תΪ'\r\n';
	if (!file_read)
	{
		cout << file_in << "�޷���ȡ�������ԣ�����������������" << endl;
		return 1;
	}
	//һ���Զ�ȡ�����ļ�
	stringstream buffer;
	buffer << file_read.rdbuf();
	string FileStr(buffer.str());
	for (int i = 0; i < FileStr.length(); i++) {
		FileStr[i] ^= char(0xFF);
		//file_write.put(FileStr[i] ^ char(0xFF));		//��λ������ַ��Ķ�������Ϊ01100000������11111111�������Ϊ10011111��
	}
	file_read.close();


	ofstream file_write;
	file_write.open(file_out, ios::binary);
	if (!file_write) {

		cout << file_out << "�޷�д�룬�����ԣ�����������������" << endl;
		return 1;     //��ͳ�����ϣ�return 1  ��ʾ�Ƿ�������return 0  ��ʾ����������
	}
	file_write << FileStr;
	file_write.close();

	cout << file_in << "������ɣ�" << endl;		//������

	return 0;
}