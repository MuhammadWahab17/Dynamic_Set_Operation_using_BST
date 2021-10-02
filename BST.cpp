//
//  BST.cpp
//  jetmeer19
//
//  Created by Ch Muhammad Wahab on 25/09/2021.
//  Copyright © 2021 Ch Muhammad Wahab. All rights reserved.
//


#include <iostream>
#include "BST.hpp"
#include <stack>
using namespace  std;


void BST::printInorder(Bnode* ptr)
    {
        if (ptr == NULL)
            return;
        
        printInorder(ptr->left);
        
        cout<<"("<<ptr->n<<") "<<ptr->data<<", ";
        
        printInorder(ptr->right);
    }


BST::BST(){
        root=NULL;
}

    BST::~BST(){
        stack<Bnode*> s;
        if(root!=NULL)
            s.push(root);
        while(!s.empty()){
            Bnode*temp=s.top();
            if(temp->left!=NULL)
                s.push(temp->left);
            if(temp->right!=NULL)
                s.push(temp->right);
            if(temp->right==NULL&&temp->left==NULL){
                remove(temp->data);
                s.pop();
            }
        }
    }

    int BST::insert(const string& val){
        if(root==NULL){
            root=new Bnode(NULL,val,1,NULL);
            return 1;
        }
        else{
            Bnode*temp=root;
            while(1){
                if(val<temp->data){
                    if(temp->left==NULL){
                        temp->left=new Bnode(NULL,val,1,NULL);
                        return 1;
                    }
                    temp=temp->left;
                }
                else if(val>temp->data){
                    if(temp->right==NULL){
                        temp->right=new Bnode(NULL,val,1,NULL);
                        return 1;
                    }
                    temp=temp->right;
                }
                else
                {
                    temp->n++;
                    return temp->n;
                }
            }
        }
    }

    int BST::search(const string& val){
        Bnode*finder=root;
        while(finder!=NULL){
            if(val==finder->data)
                return finder->n;
            else if(val<finder->data)
                finder=finder->left;
            else
                finder=finder->right;
        }
        return 0;
    }

    int BST::remove(const string& val){
        Bnode*to_del=root;
        Bnode*prev=root;
        while(to_del!=NULL){
            if(val==to_del->data){
                if(to_del->n>1){
                    to_del->n--;
                    return to_del->n;
                }
                if(to_del->left==NULL && to_del->right==NULL){
                    if(prev->left!=NULL && prev->left->data==val)
                        prev->left=NULL;
                    else if(prev->right!=NULL && prev->right->data==val)
                        prev->right=NULL;
                    else
                        root=NULL;
                    delete to_del;
                    return 0;
                }
                else if(to_del->left==NULL){
                    if(prev->left!=NULL && prev->left->data==val)
                        prev->left=to_del->right;
                    else if(prev->right!=NULL && prev->right->data==val)
                        prev->right=to_del->right;
                    else{
                        if(root->left!=NULL)
                            root=root->left;
                        else
                            root=root->right;
                    }
                    delete to_del;
                    return 0;
                }
                else if(to_del->right==NULL){
                    if(prev->left!=NULL && prev->left->data==val)
                        prev->left=to_del->left;
                    else if(prev->right!=NULL && prev->right->data==val)
                        prev->right=to_del->left;
                    else{
                        if(root->left!=NULL)
                            root=root->left;
                        else
                            root=root->right;
                    }
                    delete to_del;
                    return 0;
                }
                else{
                    Bnode*successor=to_del->right;
                    while (successor->left!=NULL) {
                        successor=successor->left;
                    }
                    string val=successor->data;
                    remove(val);
                    to_del->data=val;
                }
            }
            else if(val<to_del->data){
                prev=to_del;
                to_del=to_del->left;
            }
            else{
                prev=to_del;
                to_del=to_del->right;
            }
        }
        return -1;
    }

    void BST::min(){
        if(root==NULL)
            cout<<endl;
        Bnode *Min = root;
        while(Min->left!=NULL){
            Min=Min->left;
        }
        cout<<Min->data<<endl;
    }

    void BST::max(){
        if(root==NULL)
            cout<<endl;
        Bnode *Max = root;
        while(Max->right!=NULL){
            Max=Max->right;
        }
        cout<<Max->data<<endl;
    }

    void BST::list(){
        printInorder(root);
        cout<<endl;
    }

    void BST::child(string val){
        Bnode*finder=root;
        while(finder!=NULL){
            if(val==finder->data)
            {
                if(finder->left==NULL)
                    cout<<"NULL, ";
                else
                    cout<<finder->left->data<<", ";
                if(finder->right==NULL)
                    cout<<"NULL, ";
                else
                    cout<<finder->right->data;
                return;
            }
            else if(val<finder->data)
                finder=finder->left;
            else
                finder=finder->right;
        }
    }

    void BST::prev(string val){
        Bnode*finder=root;
        while(finder!=NULL){
            if(val==finder->data)
                break;
            else if(val<finder->data)
                finder=finder->left;
            else
                finder=finder->right;
        }
        if(finder == NULL || finder->left == NULL){
            cout<<endl;
            return;
        }
        Bnode*successor=root->left;
        while (successor->right!=NULL) {
            successor=successor->right;
        }
        cout<<successor->data<<endl;
    }

    void BST::next(string val){
        Bnode*finder=root;
        while(finder!=NULL){
            if(val==finder->data)
                break;
            else if(val<finder->data)
                finder=finder->left;
            else
                finder=finder->right;
        }
        if(finder == NULL || finder->right == NULL){
            cout<<endl;
            return;
        }
        Bnode*successor=root->right;
        while (successor->left!=NULL) {
            successor=successor->left;
        }
        cout<<successor->data<<endl;
    }

    void BST::parent(string val){
        if(root==NULL && root->data == val)
        {
            cout<<endl;
            return;
        }
        Bnode*finder=root;
        Bnode*previous=root;
        while(finder!=NULL){
            if(val==finder->data)
            {
                cout<<previous->data<<endl;
                return;
            }
            else if(val<finder->data)
            {
                previous = finder;
                finder=finder->left;
            }
            else
            {
                previous = finder;
                finder=finder->right;
            }
        }
        cout<<endl;
    }

    void BST::help(){
        cout<<"Commands\n"
        "Insert <string>\n"
        "delete <string>\n"
        "search <string>\n"
        "min \n"
        "max \n"
        "child <string>\n"
        "prev <string> \n"
        "parent <string> \n"
        "list \n"
        "quit \n_";
    }

