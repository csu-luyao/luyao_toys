#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<vector>
#include"HFMTree.h"
#include"pro_function.h"

//合法的命令集
const std::string ValidCmd = "iedptqIEDPTQ";
//表示是否建树，即内存中有无哈夫曼树
bool havetree = false;

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

void CMDQ_Quit()
{
	std::cout << "Bye!" << std::endl;
	exit(0);
}

//用初始化命令的方式建立哈夫曼树
void CMDI_Initialization(std::map<char, size_t>& count_char, 
	std::map<size_t, std::string> char_code, Node* root)
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

	//建立哈夫曼树
	HuffmanTree* ptr_hfm = new HuffmanTree(count_char);
	root = ptr_hfm->create();
	ptr_hfm->encode(root, "", char_code);
	havetree = true;

	//打印键值对
	DisplayHfmKV(count_char,char_code);

	//将哈夫曼树信息放到文件hfmTree.txt里
	std::ofstream ofs("hfmTree.txt");
	itmp = count_char.begin();
	while (itmp != count_char.end())
	{
		ofs << itmp->first << " " << itmp->second << " " << char_code[itmp->second] << std::endl;
		++itmp;
	}
}

//string转为int
int stoint(std::string s)
{
	int temp = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		temp = temp * 10 + s[i] - '0';
	}
	return temp;
}

//读取文本的方式建立哈夫曼树
void CMDE_Code(std::map<char, size_t>& count_char, std::map<size_t, std::string> char_code,Node* root)//处理文本
{
	//内存里没有哈夫曼树，从hfmTree里读入
	if (!havetree)
	{
		std::ifstream ifhfm("hfmTree.txt");
		while (ifhfm.peek() != EOF)
		{
			char s1;
			std::string s2;
			ifhfm >> s1 >> s2;
			count_char[s1] = stoint(s2);
			ifhfm >> s2;
		}

		//建立哈夫曼树
		HuffmanTree* ptr_hfm = new HuffmanTree(count_char);
		root = ptr_hfm->create();
		ptr_hfm->encode(root, "", char_code);
		havetree = true;
	}

	//终端上打印键值对
	DisplayHfmKV(count_char, char_code);

	//将编码结果丢到CodeFile.txt
	std::ofstream ofcode("CodeFile.txt");
	std::ifstream iftran("ToBeTran.txt");
	while (iftran.peek() != EOF)
	{
		char ch;
		iftran >> ch;
		ofcode << char_code[count_char[ch]];
	}
}

//显示字符哈夫曼编码键-值
void DisplayHfmKV(std::map<char, size_t>& count_char,std::map<size_t, std::string>& code_char)
{
	std::cout << "The following is char-weight-code in HFMTree." << std::endl;
	std::map<char, size_t>::const_iterator itmp = count_char.cbegin();
	while (itmp != count_char.cend())
	{
		if (itmp->first == ' ')
		{
			std::cout << "char: Space" << itmp->first << " weight: " << itmp->second << 
				" code: "<< code_char[itmp->second] <<std::endl;
		}
		else if (itmp->first == '\n')
		{
			std::cout << "char: " << "Enter" << " weight: " << itmp->second <<
				" code: " << code_char[itmp->second] << std::endl;
		}
		else
		{
			std::cout << "char: " << itmp->first << " weight: " << itmp->second <<
				" code: " << code_char[itmp->second] << std::endl;
		}
		++itmp;
	}
}

//执行命令
void RunCMD(const std::string& cmd, std::map<char, size_t>& count_char, 
	bool& flag_init, std::map<size_t,std::string>& code_char,Node* root)
{
	if (cmd == "I" || cmd == "i")
	{
		//哈夫曼树已经初始化过了
		if (flag_init)
		{
			std::cout << "HFMTree has been initializated by CMD_E.Don't use ToBeTran.txt to initializate again!\n";
		}
		else 
		{
			CMDI_Initialization(count_char, code_char, root);
			flag_init = true;
		}
	}
	else if (cmd == "E" || cmd == "e")
	{
		if (flag_init)
		{
			std::cout << "HFMTree has been initializated by CMD_I.Don't initializate again!\n";
		}
		else
		{
			CMDE_Code(count_char,code_char,root);
			flag_init = true;
		}
	}
	else if (cmd == "Q" || cmd == "q")
	{
		CMDQ_Quit();
	}
}