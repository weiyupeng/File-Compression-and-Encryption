//
//  Huffman.hpp
//  myZip
//
//  Created by 彭伟宇 on 16/11/13.
//  Copyright © 2016年 彭伟宇. All rights reserved.
//

#ifndef Huffman_hpp
#define Huffman_hpp

#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <iostream>

#endif /* Huffman_hpp */

class Node{
public:
    Node(){};
    Node(int val,int cnt):val(val),cnt(cnt){};
    
    int cnt;
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    
};

class Huffman{
public:
    Huffman(std::vector<int> &ve);
    std::string encoding(std::vector<int> &ve);
    void buildMap(Node *root,std::string tmp);
    std::vector<int> decoding(std::string s);
private:
    Node* root;
    std::map<int,std::string> encodingMap;
    std::map<std::string,int> decodingMap;

};



//struct Node{
//    char val = 0;
//    Node* left = nullptr;
//    Node* right = nullptr;
//};