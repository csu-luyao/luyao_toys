#include <iostream>
#include <queue>
#include <string>
#include <iomanip>
#include<map>
#include"HFMTree.h"

HuffmanTree::HuffmanTree()
{
    root = NULL;
    std::cerr << "HFMTree is empty!" << std::endl;
}

HuffmanTree::HuffmanTree(std::map<char,size_t> char_count)
{
    while (!nodes.empty())
    {
        nodes.pop();
    }
    std::map<char, size_t>::iterator itmp = char_count.begin();
    for (int i = 0; i < char_count.size(); ++i)
    {
        nodes.push(new Node(itmp->second));
        ++itmp;
    }
    root = NULL;
}

//HFM的折构函数
HuffmanTree::~HuffmanTree()
{
    destroyTree(root);
}

//建立哈夫曼树
Node* HuffmanTree::create()
{
    while (nodes.size() > 1)
    {
        Node* node1 = nodes.top();
        nodes.pop();
        Node* node2 = nodes.top();
        nodes.pop();

        Node* root = new Node(node1->val + node2->val);
        root->left = node1;
        root->right = node2;
        node1->parent = root;
        node2->parent = root;
        nodes.push(root);
    }

    root = nodes.top();        //队列中最后一个结点即为哈夫曼树的根结点
    nodes.pop();

    return root;
}

//哈夫曼编码
void HuffmanTree::encode(Node* root, std::string code,std::map<size_t, std::string>& char_code)
{
    if (root->left == NULL && root->right == NULL)
    {
        char_code[root->val] = code;
    }

    if (root->left != NULL)
    {
        code += "0";              
        encode(root->left, code,char_code);
        code.erase(code.end() - 1);
    }
    if (root->right != NULL)
    {
        code += "1";
        encode(root->right, code,char_code);
        code.erase(code.end() - 1);
    }
}
