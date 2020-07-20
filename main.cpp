#include <iostream>
#include "b_s_tree.h"

template<class T>
void printBST(const Tree<T>& tree){

    for(Tree<int>::Iterator iter = tree.begin(); iter != tree.end(); ++iter){
        std::cout<<*iter <<" ";
    }
    std::cout << std::endl;
}

int main(){
    Tree<int> myTree;
    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    for(int i = 0; i<7; i++){
        myTree.insert(arr[i]);
    }
    printBST(myTree);

    return 0;

}
