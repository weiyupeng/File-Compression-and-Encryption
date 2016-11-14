//
//  MyZip.cpp
//  myZip
//
//  Created by 彭伟宇 on 16/11/13.
//  Copyright © 2016年 彭伟宇. All rights reserved.
//

#include "MyZip.hpp"

//bool cmp(Node *a,Node *b){
//    return a->cnt < b->cnt;
//}

MyZip::MyZip(std::vector<int>& s){
    ve = s;
    huffman = new Huffman(s);
};




//std::string MyZip::encoding(){
//    return huffman->encoding(ve);
//    
//};
void MyZip::encoding(std::string &path){
    std::string str = huffman->encoding(ve);
    std::cout<<"the size after encoding:  "<<str.size()/8<<std::endl;
//    char *tmp = new char[str.size()/8+1];
//    int loc = 0;
    std::string tmp;
    int i = 0;
    std::fstream binary_file(path,std::ios::out|std::ios::binary);
    while(i<str.size()){
        int mv =  7;
        int num = 0;
        while(mv >=0 && i<str.size()){
            num |= (str[i++]-'0')<<(mv--);
        }
        char c = num;
        tmp += c;
    }
    binary_file.write(tmp.c_str(),sizeof(char)*tmp.size());
    binary_file.close();
//    std::cout<<tmp<<std::endl;

};



void MyZip:: decoding(std::string &s,std::string &path){
//    std::cout<<s<<std::endl;
    std::string str;
    for(auto i : s){
        int mv = 7;
        while(mv>=0){
            char c = (i & (1<<(mv--))) == 0 ? '0' : '1';
            str += c;
        }
    }
    std::vector<int> re = huffman->decoding(str);
    std::string tmp;
    for(auto i= 1;i<re.size(); i++){
        char c = re[i];
//        char c = i;
        tmp += c;
    }
    std::fstream binary_file(path,std::ios::out|std::ios::binary);
    binary_file.write(tmp.c_str(),sizeof(char)*tmp.size());
    binary_file.close();
//    std::cout<<tmp<<std::endl;
}

//std::vector<int> MyZip:: decoding(std::string &s){
//    return huffman->decoding(s);
//}







//bool cmp(Node *a,Node *b){
//    return a->cnt < b->cnt;
//}
//MyZip::MyZip(std::vector<int>& s){
    //    std::cout<<"myZip start to innitiate"<<std::endl;
    //    std::priority_queue<Node*,std::vector<Node*>,decltype(&cmp)> qu(&cmp);
//    ve = s;
    //    std::map<int,int> mp;
    //    for (auto e : s){
    //        mp[e]++;
    //    }
    //    auto beg = mp.begin(),end= mp.end();
    //    while (beg != end) {
    //        Node* q = new Node(beg->first,beg->second);
    //        qu.push(q);
    //        beg ++;
    //    }
    //    std::cout<<"myZip end to innitiate"<<std::endl;
    
//    huffman = new Huffman(s);

    //    createTree();
//};


//void MyZip::createTree(){
//    huffman = new Huffman(qu);
//};