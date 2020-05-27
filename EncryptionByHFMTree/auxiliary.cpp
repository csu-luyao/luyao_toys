#include"auxiliary.h"
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<vector>

//合法的命令集
const std::string ValidCmd = "iedptqIEDPTQ";

void ShowMenu() //显示菜单
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

void ReadCommand(std::string& cmd)//读入命令
{
	std::cout << "Please enter the command(I/E/D/P/T/Q): ";
	std::cin >> cmd;
	while (!CheckCommand(cmd))
	{
		std::cout << "Please enter your cmd again: ";
		std::cin >> cmd;
	}
}

bool CheckCommand(const std::string& cmd)//检查命令合法性
{
	if (cmd.size() > 1 || cmd.size() == 0)//大小不合法
	{
		std::cout << "You enter wrong size of cmd!Please enter a letter." << std::endl;
		return false;
	}
	else if (ValidCmd.find(cmd) == std::string::npos)//命令不存在
	{
		std::cout << "You enter invalid cmd!Please enter valid cmd." << std::endl;
		return false;
	}

	return true;
}

void ProcessText(std::map<char, size_t>& count_char)//处理文本
{
	//已经通过命令I初始化过了，无需再读取文件初始化
	if (count_char.size() != 0)
		return;

	//处理文本并给字符计数
	std::fstream source("ToBeTran.txt", std::fstream::in);
	if (source.fail())
	{
		std::cerr << "ToBeTran.txt can't open.I/O stream is in badbit/failbit." << std::endl;
		std::cout << "Process terminated.Please enter any key to quit." << std::endl;
		getchar();
		exit(0);
	}
	char ch;
	while (source.peek() != EOF)
	{
		source.get(ch);
		++count_char[ch];
	}

	//将哈夫曼树信息放到文件hfmTree.txt里
	std::ofstream ofs("hfmTree.txt");
	std::map<char, size_t>::iterator itmp = count_char.begin();
	while (itmp != count_char.end())
	{
		if (itmp->first == ' ')
		{
			ofs << "char: Space, " <<  "num: " << itmp->second << std::endl;
		}
		else if (itmp->first == '\n')
		{
			ofs << "char: " << "Enter, "<< "num: " << itmp->second << std::endl;
		}
		else
		{
			ofs << "char: " << itmp->first << "， " << "num: " << itmp->second << std::endl;
		}
		++itmp;
	}
}