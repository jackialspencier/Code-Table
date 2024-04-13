#include <iostream>
#include "binaryTree.h"
using namespace std;
int main()

{     
    binaryTree<char> tree; 

    tree.createTree('@');

    tree.preOrder();

    tree.midOrder();

    tree.postOrder();

    tree.levelOrder();

    printTree(tree, '@');

    tree.delLeft('L');

    tree.delLeft('C');

    tree.delRight('C');

    tree.exchange();

    printTree(tree, '@');

    return 0;
}