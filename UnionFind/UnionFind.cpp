//
// Created by yuanr on 10/29/2022.
//

#include <cassert>
#include <vector>
#include <iostream>
#include "UnionFind.h"

UnionFind::UnionFind(int n) {
    assert(n > 0);
    num = numComp = n;
    sz = new int[n];
    root = new int[n];
    for (int i = 0; i < n; i++) {
        sz[i] = 1;
        root[i] = i;
    }
}

UnionFind::UnionFind(const UnionFind& other){
    num = other.num;
    numComp = other.numComp;
    sz = new int[num];
    root = new int[num];
    for(int i = 0; i < num; i++){
        sz[i] = other.sz[i];
        root[i] = other.root[i];
    }
}

UnionFind& UnionFind::operator=(const UnionFind& other){
    if(this == &other){
        return *this;
    }
    num = other.num;
    numComp = other.numComp;
    delete [] sz;
    delete [] root;
    sz = new int[num];
    root = new int[num];
    for(int i = 0; i < num; i++){
        sz[i] = other.sz[i];
        root[i] = other.root[i];
    }
    return *this;
}

UnionFind::~UnionFind() {
    delete [] sz;
    delete [] root;
}

int UnionFind::find(int x) {
    assert(x >= 0 && x < num);
    int head = x;
    while (head != root[head]) {
        head = root[head];
    }
    while (x != head) {
        root[x] = head;
        x = root[x];
    }
    return head;
}

bool UnionFind::connected(int p, int q){
    return find(p) == find(q);
}

int UnionFind::componentSize(int p){
    assert(p >= 0 && p < num);
    return sz[find(p)];
}

int UnionFind::size() const{
    return num;
}

int UnionFind::components() const{
    return numComp;
}

bool UnionFind::unify(int p, int q){
    assert(p >= 0 && p < num && q >= 0 && q < num);
    int root1 = find(p);
    int root2 = find(q);
    if(root1 == root2){
        return false;
    }
    if(sz[root1] < sz[root2]){
        root[root1] = root2;
        sz[root2] += sz[root1];
    }
    else{
        root[root2] = root1;
        sz[root1] += sz[root2];
    }
    numComp--;
    return true;
}

void UnionFind::print(){
    std::vector<std::vector<int>> ans(num);
    for(int i = 0; i < num; i++){
        ans[find(i)].push_back(i);
    }
    for(int i = 0; i < ans.size(); i++){
        if(ans[i].empty()){
            if(i == ans.size()-1){
                std::cout << std::endl;
            }
            continue;
        }
        std::cout << "[";
        for(int j = 0; j < ans[i].size(); j++){
            if(j != ans[i].size()-1){
                std::cout << ans[i][j] << ", ";
            }
            else{
                std::cout << ans[i][j];
            }
        }
        if(i != ans.size()-1){
            std::cout << "], ";
        }
        else{
            std::cout << "]" << std::endl;
        }
    }
}