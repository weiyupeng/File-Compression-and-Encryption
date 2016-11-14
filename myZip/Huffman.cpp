//
//  Huffman.cpp
//  myZip
//
//  Created by 彭伟宇 on 16/11/13.
//  Copyright © 2016年 彭伟宇. All rights reserved.
//

#include "Huffman.hpp"


void Huffman::buildMap(Node *root,std::string tmp){
    if (root->left == NULL){
        encodingMap[root->val] = tmp;
        decodingMap[tmp] = root->val;
        return;
    }
    
    buildMap(root->left, tmp+"0");
    buildMap(root->right, tmp+"1");
}

bool cmp(Node *a,Node *b){
    return a->cnt > b->cnt;
}

Huffman::Huffman(std::vector<int> &ve){
    std::priority_queue<Node*,std::vector<Node*>,decltype(&cmp)> qu(&cmp);
    std::map<int,int> mp;
        for (auto e : ve){
            mp[e]++;
        }
        auto beg = mp.begin(),end= mp.end();
        while (beg != end) {
            Node* q = new Node(beg->first,beg->second);
            qu.push(q);
            beg ++;
        }
    
    while (qu.size()!=1) {
        Node* a = qu.top();
        qu.pop();
        Node* b = qu.top();
        qu.pop();
        Node* p = new Node(-1,a->cnt+b->cnt);
        qu.push(p);
        p->left = a;
        p->right = b;
        

    }
    root = qu.top();
    
    std::string tmp;
    buildMap(root,tmp);
}

std::string Huffman::encoding(std::vector<int> &ve){
    std::string re;
    for(auto i : ve){
        re += encodingMap[i];
    }
    return re;
}





std::vector<int> Huffman:: decoding(std::string s){
    std::vector<int> re;
    int i = 0,j=0;
    for(j=0; j<s.size();j++){
        if (decodingMap.find(s.substr(i,j-i+1)) == decodingMap.end()) {
            if (i==j || decodingMap.find(s.substr(i,j-i)) != decodingMap.end()){
                re.push_back(decodingMap[s.substr(i,j-i)]);
                i = j;
            }
        }
    }
    if (i!=j-1) re.push_back(decodingMap[s.substr(i,j-i)]);
    return re;
    
}


//std::vector<int> Huffman:: decoding(std::string s){
//    std::vector<int> re;
//    std::cout<<"dadwhoawldlahhkjhadihadkjhadhpahdowhdah";
//    for (auto i : s) std::cout<<i;
//    std::string tmp ;
//    bool find = 0;
//    auto beg = decodingMap.begin();
//    auto end= decodingMap.end();
//    while (beg != end) {
//        std::cout<<beg->first<<"------"<<beg->second<<std::endl;
//        beg++;
//    }
//    int i = 0;
//    for(int j=0; j<s.size();j++){
//        if (decodingMap.find(s.substr(i,j-i+1)) != decodingMap.end()) {
//            if (i==j || decodingMap.find(s.substr(i,j-i)) == decodingMap.end()){
//                re.push_back(decodingMap[s.substr(i,j-i)]);
//                i = j;
//            }
//        }
//    }
//    
//    return re;
//}
//
////    for (auto i : s) {
////        //decodingMap.count() will bring error ? why ??? haven't fing out yet
////        if (decodingMap.find(tmp+i) == decodingMap.end() && find == 1){
//////            std::cout<<decodingMap[tmp]<<std::endl;
////            int x = decodingMap[tmp];
////            if (x==0)std::cout<<"why"<<tmp<<std::endl;
////            re.push_back(x);
////            tmp = "" ;
////        }
////        else if (find == 0){
////            if (decodingMap.find(tmp+i) == decodingMap.end() ) {
////                find = 1;
////            }
////        }
////        tmp += i;
////    }
//    for (auto i : re){
//        std::cout<<i<<std::endl;
//    }
//    beg = decodingMap.begin();
//    end= decodingMap.end();
//    while (beg != end) {
//        std::cout<<beg->first<<"------"<<beg->second<<std::endl;
//        beg++;
//    }
//    return re;
//}
//
//
////    std::priority_queue<Node*,std::vector<Node*>,decltype(&cmp)> qu(&cmp);
////    ve = s;
////    std::map<int,int> mp;
////    for (auto e : s){
////        mp[e]++;
////    }
////    auto beg = mp.begin(),end= mp.end();
////    while (beg != end) {
////        Node* q = new Node(beg->first,beg->second);
////        qu.push(q);
////        beg ++;
//    }