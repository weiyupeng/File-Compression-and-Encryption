//
//  main.cpp
//  myZip
//
//  Created by 彭伟宇 on 16/11/13.
//  Copyright © 2016年 彭伟宇. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
//#include <bitset>
#include "MyZip.hpp"
/**
 1.Read files by ASCII, transfer it to integer,then count the frequency of each integer,encoding file with Huffman Tree
 2. save the encoding code as binary file,and save the whole huffman Tree too
 3. decoding using file with hash table create by hufman Tree key point : greedy algorithm
 **/



int main(int argc, const char * argv[]) {
    std::cout << "please input the compress file name !\n";
    // if the file name is not exist, system will break down
    std::string fileNmae;
    std::cin>>fileNmae;
    std::ifstream file(fileNmae);
    std::vector<int> content;
    int i;
    while ((i = file.get())!=-1) {
        content.push_back(i);
    }
    file.close();
    
    std::cout<<"original size:  "<<content.size()<<std::endl;
    
    std::cout << "please input the output file name !\n";
    std::string path;
    std::cin>>path;
    MyZip* myZip = new MyZip(content);
    myZip->encoding(path);
    
    
    std::cout << "please input the uncompre file name !\n";
    std::string f1;
    std::cin>>f1;
    std::ifstream file1(f1);
    std::string str;
    
    while ((i = file1.get())!=-1) {
        str.push_back(i);
    }
    file.close();
    path.clear();
    std::cout << "please input the output file name !\n";
    std::cin>>path;

    myZip->decoding(str,path);
//    std::cout<<str<<std::endl;
    
    
    return 0;
}

    
    
    
    
//    MyZip* myZip = new MyZip(content);
//    std::string str = myZip->encoding();
//    std::cout<<"the size after encoding:  "<<str.size()/8<<"    "<<content.size()<<std::endl;
//    
//    
//    char *tmp = new char[str.size()/8+1];
//    int loc = 0;
//    i = 0;
//    while(i<str.size()){
//        int mv =  7;
//        int num = 0;
//        while(mv >=0 && i<str.size()){
//            num |= (str[i++]-'0')<<mv--;
//        }
//        char c = num;
//        tmp[loc++] = c;
//    }
//    std::fstream binary_file("/Users/WeiyuPeng/Desktop/myZip/myZip/encode.txt",std::ios::out|std::ios::binary);
//    binary_file.write(reinterpret_cast<char *>(&tmp),sizeof(str.size()/8+1));
//    binary_file.close();
//    
//    std::vector<int> decode = myZip->decoding(str);
//    for (int i : decode)
//        std::cout<<i;
//    
//    std::cout<<std::endl;
//    
//    for (int i : content)
//        std::cout<<i;
//    don't support dynamic allocation memery'
//    std::bitset<str.size()> bs(str);
    

