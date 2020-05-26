#include"auxiliary.h"
#include<iostream>

void ShowMenu()
{
	std::cout << "----------------------------------------------------MENU------------------------------------------------------------" << std::endl;
	std::cout << "I: Initialize.\n" <<
		"  Read the character set size n from the terminal, as well as n characters and n weights, build a Huffman tree, and store it in the file hfmTree." << std::endl;
	std::cout << "\nE: coding.\n" <<
		"  Use the built Huffman tree (if not in memory, read from the file htmTree), encode the text in the file ToBeTran, and then save the result in the file CodeFile." << std::endl;
	std::cout << "\nD: Decoding.\n" <<
		"  Use the established Huffman tree to decode the code in the file CodeFile, and store the result in the file TextFile." << std::endl;
	std::cout << "\nP:Print code file.\n" <<
		"The file CodeFile is displayed on the terminal in a compact format with 50 codes per line. At the same time, the encoding in the form of characters is written into the file CodePrint." << std::endl;
	std::cout << "\nT: Print Huffman tree.\n" << 
		"The Huffman tree already in memory is displayed on the terminal in an intuitive manner (in the form of a tree or a concave table), and at the same time, the Huffman tree in the form of this character is written to the file TreePrint."<< std::endl;
	std::cout << "\n\nPlease enter the command: " << std::endl;
}