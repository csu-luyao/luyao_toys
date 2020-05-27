#include"auxiliary.h"
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<vector>
#include"HFMTree.h"

//�Ϸ������
const std::string ValidCmd = "iedptqIEDPTQ";

void ShowMenu() //��ʾ�˵�
{
	std::cout << "----------------------MENU-------------------------" << std::endl;
	std::cout << "| I: Initialize.                                  |" << std::endl;
	std::cout << "| E: coding.                                      |" << std::endl;
	std::cout << "| D: Decoding.                                    |" << std::endl;
	std::cout << "| P: Print code file                              |" << std::endl;
	std::cout << "| T: Print Huffman tree.                          |" << std::endl;
	std::cout << "| Q: Quit the program.                            |" << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
}

void ReadCommand(std::string& cmd)//��������
{
	std::cout << "Please enter the command(I/E/D/P/T/Q): ";
	std::cin >> cmd;
	while (!CheckCommand(cmd))
	{
		std::cout << "Please enter your cmd again: ";
		std::cin >> cmd;
	}
}

bool CheckCommand(const std::string& cmd)//�������Ϸ���
{
	if (cmd.size() > 1 || cmd.size() == 0)//��С���Ϸ�
	{
		std::cout << "You enter wrong size of cmd!Please enter a letter." << std::endl;
		return false;
	}
	else if (ValidCmd.find(cmd) == std::string::npos)//�������
	{
		std::cout << "You enter invalid cmd!Please enter valid cmd." << std::endl;
		return false;
	}

	return true;
}

void CMDQ_Quit()
{
	std::cout << "Bye!" << std::endl;
	exit(0);
}

//�ó�ʼ������ķ�ʽ������������
void CMDI_Initialization(std::map<char, size_t>& count_char)
{
	char c;
	std::cout << "Please enter amount of chars: ";
	while (std::cin >> c && !isdigit(c))
	{
		std::cout << "Please enter a number: ";
	}
	int n = c - '0';
	std::cout << "Please enter " << n << " char(s):" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		char ch;
		std::cin >> ch;
		count_char[ch] = 0;
	}
	std::map<char, size_t>::iterator itmp = count_char.begin();
	std::cout << "Please enter weight of char in order:" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		int w;
		std::cout << "Char " << itmp->first << " weight: ";
		std::cin >> w;
		count_char[itmp->first] = w;
		++itmp;
	}

	
	//��ӡ��ֵ��
	DisplayHfmKV(count_char);

	//������������Ϣ�ŵ��ļ�hfmTree.txt��
	std::ofstream ofs("hfmTree.txt");
	itmp = count_char.begin();
	while (itmp != count_char.end())
	{
		if (itmp->first == ' ')
		{
			ofs << "char: Space " << "weight: " << itmp->second << std::endl;
		}
		else if (itmp->first == '\n')
		{
			ofs << "char: " << "Enter " << "weight: " << itmp->second << std::endl;
		}
		else
		{
			ofs << "char: " << itmp->first << " " << "weight: " << itmp->second << std::endl;
		}
		++itmp;
	}
}

//��ȡ�ı��ķ�ʽ������������
void CMDE_Code(std::map<char, size_t>& count_char)//�����ı�
{
	//�����ı������ַ�����
	std::fstream source("ToBeTran.txt", std::fstream::in);
	if (source.fail())
	{
		std::cerr << "ToBeTran.txt can't open.I/O stream is in badbit/failbit." << std::endl;
		std::cout << "Process terminated.Please enter any key to quit." << std::endl;
		getchar();
		exit(0);
	}
	char ch;
	//��ʼ�����˾Ͳ����ٳ�ʼ����
	if (count_char.size() == 0) {
		while (source.peek() != EOF)
		{
			source.get(ch);
			++count_char[ch];
		}
	}
	//�ն��ϴ�ӡ��ֵ��
	DisplayHfmKV(count_char);

	//������������Ϣ�ŵ��ļ�hfmTree.txt��
	std::ofstream ofs("hfmTree.txt");
	std::map<char, size_t>::iterator itmp = count_char.begin();
	while (itmp != count_char.end())
	{
		if (itmp->first == ' ')
		{
			ofs << "char: Space " << "weight: " << itmp->second <<  " code: " << << std::endl;
		}
		else if (itmp->first == '\n')
		{
			ofs << "char: " << "Enter " << "weight: " << itmp->second << std::endl;
		}
		else
		{
			ofs << "char: " << itmp->first << " " << "weight: " << itmp->second << std::endl;
		}
		++itmp;
	}

	//���ܺ����CodeFile.txt��

}

//��ʾ�ַ������������-ֵ
void DisplayHfmKV(std::map<char, size_t>& count_char)
{
	std::cout << "The following is char-weight in HFMTree." << std::endl;
	std::map<char, size_t>::iterator itmp = count_char.begin();
	while (itmp != count_char.end())
	{
		if (itmp->first == ' ')
		{
			std::cout << "char: Space" << itmp->first << " weight: " << itmp->second << std::endl;
		}
		else if (itmp->first == '\n')
		{
			std::cout << "char: " << "Enter" << " weight: " << itmp->second << std::endl;
		}
		else
		{
			std::cout << "char: " << itmp->first << " weight: " << itmp->second << std::endl;
		}
		++itmp;
	}
}

//ִ������
void RunCMD(const std::string& cmd, std::map<char, size_t>& count_char, bool flag_init)
{
	if (cmd == "I" || cmd == "i")
	{
		//���������Ѿ���ʼ������
		flag_init = true;
		CMDI_Initialization(count_char);
	}
	else if (cmd == "E" || cmd == "e")
	{
		if (flag_init)
		{
			std::cout << "HFMTree has been initializated by CMD_I.Don't use ToBeTran.txt to initializate again!\n";
		}
		else
		{
			CMDE_Code(count_char);
		}
	}
	else if (cmd == "Q" || cmd == "q")
	{
		CMDQ_Quit();
	}
}