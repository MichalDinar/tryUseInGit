// unival_tree_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct tree
{
    int value;
    tree* left;
    tree* right;
};
int calculateNumberOfUnivalTrees(tree* t);

int main()
{
    std::cout << "Hello World!\n";
    tree t1, t11, t12, t111, t112, t1121, t1122;
    t1.left = &t11;
    t1.right = &t12;
    t11.left = &t111;
    t11.right = &t112;
    t12.right = nullptr;
    t12.left = nullptr;
    t111.right = nullptr;
    t111.left = nullptr;
    t112.left = &t1121;
    t112.right = &t1122;
    t1121.right = nullptr;
    t1121.left = nullptr;
    t1122.right = nullptr;
    t1122.left = nullptr;

    t1.value = 0;
    t11.value = 0;
    t12.value = 1;
    t111.value = 0;
    t112.value = 1;
    t1121.value = 1;
    t1122.value = 1;
    
    cout << calculateNumberOfUnivalTrees(&t1);
}

int calculateNumberOfUnivalTrees(tree* t)
{
    if (t == nullptr)
        return 0;
    if (t->left == nullptr && t->right==nullptr)
        return 1;
    if (t->left == nullptr)
    {
        if (t->right->value == t->value)
            return 1 + calculateNumberOfUnivalTrees(t->right);
        return calculateNumberOfUnivalTrees(t->right);
    }
    if (t->right == nullptr)
    {
        if (t->left->value == t->value)
            return 1 + calculateNumberOfUnivalTrees(t->left);
        return calculateNumberOfUnivalTrees(t->left);
    }
    if (t->value == t->left->value && t->value == t->right->value)
       return 1 + calculateNumberOfUnivalTrees(t->left) + calculateNumberOfUnivalTrees(t->right);
    return calculateNumberOfUnivalTrees(t->left) + calculateNumberOfUnivalTrees(t->right);
}