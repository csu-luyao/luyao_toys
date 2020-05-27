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

class Compare    //比较类
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
    std::priority_queue<Node*, std::vector<Node*>, Compare> nodes;    //优先队列（小根堆）
    Node* root;
public:
    HuffmanTree();
    HuffmanTree(std::map<char, size_t> char_count);
    ~HuffmanTree();
    //建立哈夫曼树
    Node* create();
    //进行哈夫曼编码
    void encode(Node* node, std::string code, std::map<size_t, std::string>& char_code);
    //遍历
    void preOrder(Node* root);
    void inOrder(Node* root);
    void postOrder(Node* root);
    //销毁
    void destroyTree(Node* root);
};

#endif