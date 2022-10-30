//
// Created by yuanr on 10/29/2022.
//

#ifndef UNIONFIND_UNIONFIND_H
#define UNIONFIND_UNIONFIND_H


class UnionFind {
private:
    int num;
    int numComp;
    int* sz;
    int* root;

public:
    UnionFind(int n);
    UnionFind& operator=(const UnionFind& other);
    UnionFind(const UnionFind& other);
    ~UnionFind();
    int find(int x);
    bool connected(int p, int q);
    int componentSize(int p);
    int size() const;
    int components() const;
    bool unify(int p, int q);
    void print();
};


#endif //UNIONFIND_UNIONFIND_H
