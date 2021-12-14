#include"BitMap.h"
#include"ThreadPool.h"

void FileProcessIn(const char* str1) {
	int i, j;		//�ļ������
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	ThreadPool pool(sysInfo.dwNumberOfProcessors);		//��ȡϵͳ�������������ɶ�Ӧ�����̳߳�
	intptr_t Handle;		//���ڻ�ȡĿ¼���ļ���
	std::vector< std::future<int> > results;		//�������̵߳���
	char str0[10] = "*.";
	strcat_s(str0, sizeof(str0), str1);
	cout << str0 << endl;		//����û�ָ�����ļ�
	char filename[20];		//��Ϊ����ļ����ļ���
	struct _finddata_t FileInfo;		//���ڻ�ȡĿ¼���ļ���

	if ((Handle = (_findfirst(str0, &FileInfo))) == -1)
		cout << "File not found! Error!" << endl;
	else {
		char str[20] = ".\\BitMap\\%02d.";
		strcat_s(str, sizeof(str), str1);
		i = 1;
		sprintf_s((char*)filename, sizeof(filename), str, i);
		results.emplace_back(pool.enqueue(Encryption, FileInfo.name, filename));		//���ö��߳�
		cout << FileInfo.name << "\t";
		cout << filename << endl;
		j = 2;
		while (_findnext(Handle, &FileInfo) == 0)
		{
			sprintf_s((char*)filename, sizeof(filename), str, j);//ָ���ļ���Ϊ��2��ʼ��������ÿ�μ�1
			j = j + 1;
			results.emplace_back(pool.enqueue(Encryption, FileInfo.name, filename));
			cout << FileInfo.name << "\t";
			cout << filename << endl;
		}
		_findclose(Handle);
	}
}

void FileProcessOut(const char* str1) {
	int i, j;		//�ļ������
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	ThreadPool pool(sysInfo.dwNumberOfProcessors);		//��ȡϵͳ�������������ɶ�Ӧ�����̳߳�
	intptr_t Handle;		//���ڻ�ȡĿ¼���ļ���
	std::vector< std::future<int> > results;		//�������̵߳���
	char str0[10] = "*.";
	strcat_s(str0, sizeof(str0), str1);
	cout << str0 << endl;		//����û�ָ�����ļ�
	char filename[20];		//��Ϊ����ļ����ļ���
	struct _finddata_t FileInfo;		//���ڻ�ȡĿ¼���ļ���

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
			sprintf_s((char*)filename, sizeof(filename), str, j);//ָ���ļ���Ϊ��2��ʼ��������ÿ�μ�1
			j = j + 1;
			results.emplace_back(pool.enqueue(Decryption, FileInfo.name, filename));
			cout << FileInfo.name << "\t";
			cout << filename << endl;
		}
		_findclose(Handle);
	}
}