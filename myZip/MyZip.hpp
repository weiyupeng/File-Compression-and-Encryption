//
//  MyZip.hpp
//  myZip
//
//  Created by 彭伟宇 on 16/11/13.
//  Copyright © 2016年 彭伟宇. All rights reserved.
//

#ifndef MyZip_hpp
#define MyZip_hpp

#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <queue>
#include <fstream>
#include "Huffman.hpp"

#endif /* MyZip_hpp */


class MyZip{
public:
    MyZip(std::vector<int>& s);
//    void createTree( std::priority_queue<Node> &qu);
//    std::string encoding();
    void encoding(std::string &path);
//    std::vector<int> decoding(std::string &s);
    void decoding(std::string &s,std::string &path);
    
    
private:
//    std::priority_queue<Node> qu;
    std::vector<int> ve;
    Huffman* huffman;
};
