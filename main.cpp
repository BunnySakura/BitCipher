/*
1.��ȡ����ǰ����Ŀ¼
2.������ǰĿ¼����Ŀ¼�����ļ�������ļ�����·��
3.ȷ����Ҫ���еĲ���:����/����
4.����"EnAndDecryption"���Encryption�������м���,Decryption��������
  ʹ��forѭ���������в���
*/
#include"Bitmap.h"

int main()
{
	cout << "ʹ�÷�����������ŵ���Ҫ��/���ܵ��ļ���ͬĿ¼��" << endl <<
		"�����ļ����֧��2GB!" << endl <<
		"��ѡ�񱣴�Ŀ¼Ĭ�ϱ��浽���ͬĿ¼�µ�BitMap�ļ���!" << endl << endl;

	int i;
	string file_suffix;
	string folder_path;
	TCHAR szBuffer[255] = { 0 };
	folder_path = SelectWindow(szBuffer) + '\\';

	if (0 != _access(folder_path.c_str(), 0))
	{
		// if this folder not exist, create a new one.
		if (_mkdir(folder_path.c_str()) != 0)return -1;		// ���� 0 ��ʾ�����ɹ���-1 ��ʾʧ��
		//���� ::_mkdir  ::_access Ҳ�У���֪��ʲô��˼
	}

	cout << "��������: 0 ,��������: 1 !" << endl;
	cin >> i;
	while (i != 0 && i != 1)
	{
		cout << "���������룡����" << endl;
		cin >> i;
	}

	cout << endl <<
		"��Сд��ʽ�����ļ���׺" << endl <<
		"��txt,jpg,png,zip,ƥ����ָ�ʽ��ͨ�����*����" << endl <<
		"��ɺ���ȷ���ļ�����������������ԣ���ô�����ԣ�����" << endl;
	cin >> file_suffix;

	switch (i)
	{
	case 0:
		FileProcessIn(file_suffix, folder_path);
		break;
	default:
		FileProcessOut(file_suffix, folder_path);
	}

	system("PAUSE");
	return 0;
}