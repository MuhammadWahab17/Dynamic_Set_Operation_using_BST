
#include "iostream"
#include "BST.hpp"
using namespace std;

int main(){
    BST btree;
    while (1) {
        string word;
        getline(cin, word);
        string command = word.substr(0,word.find(' '));
        for (int i=0; i<command.length(); i++) {
            command[i] = tolower(command[i]);
        }
        string String = word.substr(word.find(' ')+1);
        if(command.length() == 0 || word.length()==0){
            cout<<"Invalid command\nList of command is given below\n";
            btree.help();
            continue;
        }
        if(command == "insert")
            cout<<String<<" "<<btree.insert(String)<<endl;
        else if(command == "delete")
            cout<<String<<" "<<btree.remove(String)<<endl;
        else if(command == "search")
            cout<<String<<" "<<btree.search(String)<<endl;
        else if(command == "min")
            btree.min();
        else if(command == "max")
            btree.max();
        else if(command == "child")
            btree.child(String);
        else if(command == "prev")
            btree.prev(String);
        else if(command == "next")
            btree.next(String);
        else if(command == "parent")
            btree.parent(String);
        else if(command == "list")
            btree.list();
        else if(command == "quit")
            break;
        else
        {
            cout<<"Invalid command\nList of command is given below\n";
            btree.help();
        }
    }
}
