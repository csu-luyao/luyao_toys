#include"auxiliary.h"
#include<iostream>
#include<string>

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