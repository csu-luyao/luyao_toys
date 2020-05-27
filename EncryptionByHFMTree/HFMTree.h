#ifndef HFMTREE_H_
#define HFMTREE_H_

#include <iostream>
#include <queue>
#include <string>
#include<deque>
#include<map>

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) :val(val), left(NULL), right(NULL), parent(NULL) {}
    Node(int val, Node* left, Node* right, Node* parent) :val(val), left(left), right(right), parent(parent) {}
};

class Compare    //�Ƚ���
{
public:
    bool operator() (Node* a, Node* b)
    {
        return a->val > b->val;   
    }
};

class HuffmanTree
{
private:
    std::priority_queue<Node*, std::vector<Node*>, Compare> nodes;    //���ȶ��У�С���ѣ�
    Node* root;
public:
    HuffmanTree();
    HuffmanTree(std::map<char, size_t> char_count);
    ~HuffmanTree();
    //������������
    Node* create();
    //���й���������
    void encode(Node* node, std::string code, std::map<size_t, std::string>& char_code);
    //����
    void preOrder(Node* root);
    void inOrder(Node* root);
    void postOrder(Node* root);
    //����
    void destroyTree(Node* root);
};

#endif