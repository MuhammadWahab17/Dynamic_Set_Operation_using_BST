//
//  BST.hpp
//  jetmeer19
//
//  Created by Ch Muhammad Wahab on 25/09/2021.
//  Copyright © 2021 Ch Muhammad Wahab. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <iostream>
#include <stack>
using namespace std;
struct Bnode{
    string data;
    int n;
    Bnode *left,*right;
    Bnode(){}
    Bnode(Bnode*le,const string&v,int c,Bnode*ri){
        left=le;
        data=v;
        right=ri;
        n = c;
    }
};

class BST {
    Bnode*root;
    void printInorder(Bnode* ptr);
public:
    BST();
    ~BST();
    int insert(const string& val);
    int search(const string& val);
    int remove(const string& val);
    void min();
    void max();
    void list();
    void child(string val);
    void prev(string val);
    void next(string val);
    void parent(string val);
    void help();
};

#endif /* BST_hpp */
