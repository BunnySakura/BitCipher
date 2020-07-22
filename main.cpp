/*
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	char ch;

	ifstream in;
	in.open("C:\\Users\\ASUS\\Desktop\\pixiv\\qidian.png", ios::binary);   //ios::binary�����Ƶײ�ϵͳ������ļ����ݽ��е��Զ�ת��;������������ϵͳ���Զ���'\n'תΪ'\r\n';
	if (!in)
	{
		cout << "Cannot open file.";
		return 1;
	}
	ofstream out;
	out.open("C:\\Users\\ASUS\\Desktop\\tmp.jpg", ios::binary);
	if (!out) {

		cout << "Cannot open file.";
		return 1;     //��ͳ�����ϣ�return 1  ��ʾ�Ƿ�������return 0  ��ʾ����������
	}
	while (in)
	{
		in.get(ch);
		ch = ch ^ char(0xFF);    //�ַ��Ķ�������Ϊ01100000������11111111�������Ϊ10011111��
		if (in)   out.put(ch);
	}


	in.close();
	out.close();
	return 0;
}

//'\r' �س����ص���ǰ�е����ף������ỻ����һ�У������������Ļ���������ǰ�����ݻᱻ��һ���ǣ�

//'\n' ���У�������ǰλ�õ���һ�У�������ص����ף�

*/

/*
#include <fstream>
#include <iostream>

using namespace std;
int main()
{
	char ch;

	ifstream in;
	in.open("C:\\Users\\ASUS\\Desktop\\tmp.jpg", ios::binary);   //ios::binary�����Ƶײ�ϵͳ������ļ����ݽ��е��Զ�ת��;������������ϵͳ���Զ���'\n'תΪ'\r\n';
	if (!in)
	{
		cout << "Cannot open file.";
		return 1;
	}
	ofstream out;
	out.open("C:\\Users\\ASUS\\Desktop\\new.jpg", ios::binary);
	if (!out) {

		cout << "Cannot open file.";
		return 1;     //��ͳ�����ϣ�return 1  ��ʾ�Ƿ�������return 0  ��ʾ����������
	}
	while (in)
	{
		in.get(ch);
		ch = ch ^ char(0xFF);    //�ַ��Ķ�������Ϊ01100000������11111111�������Ϊ10011111��
		if (in)   out.put(ch);
	}


	in.close();
	out.close();
	return 0;
}
*/

/*
1.��ȡ����ǰ����Ŀ¼
2.������ǰĿ¼����Ŀ¼�����ļ�������ļ�����·��
3.ȷ����Ҫ���еĲ���:����/����
4.����"inout"���in�������м���,out��������
  ʹ��forѭ���������в���
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <io.h>
#include <direct.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <regex>

using namespace std;

class inout
{
public:
	bool in(const char *str1, const char* str2);
	bool out(const char* str1, const char* str2);

private:

};

bool inout::in(const char *str1, const char* str2)
{
	char ch;

	ifstream in;
	in.open(str1, ios::binary);   //ios::binary�����Ƶײ�ϵͳ������ļ����ݽ��е��Զ�ת��;������������ϵͳ���Զ���'\n'תΪ'\r\n';
	if (!in)
	{
		cout << "Cannot in file." << endl;
		return 1;
	}
	ofstream out;
	out.open(str2, ios::binary);
	if (!out) {

		cout << "Cannot out file." << endl;
		return 1;     //��ͳ�����ϣ�return 1  ��ʾ�Ƿ�������return 0  ��ʾ����������
	}
	while (in)
	{
		in.get(ch);
		ch = ch ^ char(0xFF);    //�ַ��Ķ�������Ϊ01100000������11111111�������Ϊ10011111��
		if (in)   out.put(ch);
	}


	in.close();
	out.close();
	return true;

//'\r' �س����ص���ǰ�е����ף������ỻ����һ�У������������Ļ���������ǰ�����ݻᱻ��һ���ǣ�

//'\n' ���У�������ǰλ�õ���һ�У�������ص����ף�

}

bool inout::out(const char* str1, const char* str2)
{
	char ch;

	ifstream in;
	in.open(str1, ios::binary);   //ios::binary�����Ƶײ�ϵͳ������ļ����ݽ��е��Զ�ת��;������������ϵͳ���Զ���'\n'תΪ'\r\n';
	if (!in)
	{
		cout << "Cannot in file." << endl;
		return 1;
	}
	ofstream out;
	out.open(str2, ios::binary);
	if (!out) {

		cout << "Cannot out file." << endl;
		return 1;     //��ͳ�����ϣ�return 1  ��ʾ�Ƿ�������return 0  ��ʾ����������
	}
	while (in)
	{
		in.get(ch);
		ch = ch ^ char(0xFF);    //�ַ��Ķ�������Ϊ01100000������11111111�������Ϊ10011111��
		if (in)   out.put(ch);
	}


	in.close();
	out.close();
	return 0;
}

/*
����Ŀ¼����Ŀ¼·���ĺ���,�����޷����ѭ�����ַ������·���ַ���������
���ñ�׼����,�����������ļ�,����list.txt�����������
�˷����Ǹ�����Ϊ��ѽ������,�Ա�׼����ʹ���ļ����м���ѭ,����ѭ�������������ܽ���
����������ʧ��,��ʱ�޷����,����,�����Ժ�����

�˷���Ϊ����.���ò���,���������������պ���
#define MAX_PATH 80
void getFiles(string path, string path2, vector<string>& files);
*/

void dir0(const char* str1);
void dir1(const char* str1);


int main()
{
	int i;
	char str[8];

	string folderPath = ".\\BitMap";

	if (0 != _access(folderPath.c_str(), 0))
	{
		// if this folder not exist, create a new one.
		_mkdir(folderPath.c_str());   // ���� 0 ��ʾ�����ɹ���-1 ��ʾʧ��
		//���� ::_mkdir  ::_access Ҳ�У���֪��ʲô��˼
	}

	cout << "��������: 0 ,��������: 1 !" << endl;
	cin >> i;
	while (i != 0 && i != 1)
	{
		cout << "����������!" << endl;
		cin >> i;
	}

	cout << "��Сд��ʽ�����ļ���ʽ" << endl << "��txt,jpg,png,zip��!" << endl;
	cin >> str;

	/* ����ƥ���ַ���ʧ��,�־���û�д���,���Է���
		std::regex reg("^[0-9a-zA-Z]+$");
	bool bValid = std::regex_match(str, reg);

	while (bValid != true)
	{
		cout << "����������!" << endl;
		cin >> str;
	}
	*/

	switch (i)
	{
	case 0:
		dir0((const char*)str);
		break;
	default :
		dir1((const char*)str);
	}

	/*
	vector<string> files;
	char buffer[MAX_PATH];
	_getcwd(buffer, MAX_PATH);
	string filePath;
	filePath.assign(buffer).append("\\");
		////��ȡ��·���µ������ļ�
		getFiles(filePath, "", files);
	char str[30];
	int size = files.size();
	for (int i = 0; i < size; i++)
	{
		cout << files[i].c_str() << endl;
	}
	*/
	
	return 0;
}
/*
void getFiles(string path, string path2, vector<string>& files)
{
	//�ļ����
	long hFile = 0;
	//�ļ���Ϣ
	struct _finddata_t fileinfo;
	string p, p2;
	if ((hFile = _findfirst(p.assign(path).append(path2).append("*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//�����Ŀ¼,����֮
			//�������,�����б�
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "��") != 0)
					getFiles(p.assign(path).append("\\"),p2.assign(fileinfo.name).append("\\"), files );
			}
			else
			{
				files.push_back(p.assign(path2).append(fileinfo.name)); //��һ�п��Ը������·��
				//files.push_back(p.assign(fileinfo.name) ); //��һ�п��Ը����ļ���
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}


*/

//����
void dir0(const char* str1) {
	int i,j;
	intptr_t Handle;
	inout pic;
	char str0[10]="*.";
	strcat_s(str0, sizeof(str0), str1);
	cout << str0 << endl;
	char filename[20];
	struct _finddata_t FileInfo;

	if ((Handle = (_findfirst(str0, &FileInfo))) == -1)
		cout << "File not found! Error!" << endl;
	else {
		//��ɾ���·��,ʹ��"��ȫ"��strcat_s,ʧ��!
		//strcat_s((char*)str2, sizeof(str2) + 1, FileInfo.name);
		//printf(str2);
		char str[20] = ".\\BitMap\\%d.";
		strcat_s(str, sizeof(str), str1);
		i = 1;
		sprintf_s((char*)filename, sizeof(filename), str, i);
		pic.in(FileInfo.name, filename);
		cout << FileInfo.name << "\t";
		cout << filename << endl;
		j = 2;
		while (_findnext(Handle, &FileInfo) == 0)
		{
			sprintf_s((char*)filename, sizeof(filename), str, j);//ָ���ļ���Ϊ��2��ʼ��������ÿ�μ�1
			j = j + 1;
			pic.in(FileInfo.name, filename);
			cout << FileInfo.name << "\t";
			cout << filename << endl;
		}
		_findclose(Handle);
	}
}

//����
void dir1(const char* str1) {
	int i,j;
	intptr_t Handle;
	inout pic;
	char str0[10] = "*.";
	strcat_s(str0, sizeof(str0), str1);
	cout << str0 << endl;
	char filename[20];
	struct _finddata_t FileInfo;

	if ((Handle = (_findfirst(str0, &FileInfo))) == -1)
		cout << "File not found! Error!" << endl;
	else {
		char str[20] = ".\\BitMap\\%d.";
		strcat_s(str, sizeof(str), str1);
		i = 0;
		sprintf_s((char*)filename, sizeof(filename), str, i);
		pic.out(FileInfo.name, filename);
		cout << FileInfo.name << "\t";
		cout << filename << endl;
		j = 1;
		while (_findnext(Handle, &FileInfo) == 0)
		{
			sprintf_s((char*)filename, sizeof(filename), str, j);//ָ���ļ���Ϊ��1��ʼ��������ÿ�μ�1
			j = j + 1;
			pic.out(FileInfo.name, filename);
			cout << FileInfo.name << "\t";
			cout << filename << endl;
		}
		_findclose(Handle);
	}
	//��������,tmd����,����ֻ�ܴ�0���ļ���ʼ,Ȼ����ڶ�һ��Ī��������ļ�
	//�����Ƴ�����ļ���,��������ļ���ʼ,���޷�����...gank
	sprintf_s((char*)filename, sizeof(filename), "%d.jpg", j+1);
	remove(filename);
}