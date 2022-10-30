#include <iostream>
#include <vector>
#include "UnionFind.h"

using namespace std;

int minSwapsCouples(vector<int>& row);

int main() {
    //testing leetcode 765
//    vector<int> row = {5, 4, 2, 6, 3, 1, 0, 7};
//    cout << minSwapsCouples(row);

    //testing UnionFind
    UnionFind ds(6);
    ds.print();
    ds.unify(1,2);
    cout << "connected 1 and 2: ";
    ds.connected(1, 2)? cout << "true " : cout << "false ";
    ds.print();

    UnionFind ds2(ds);
    cout << "original: ";
    ds.print();
    cout << "copied: ";
    ds2.print();

    UnionFind ds3(5);
    ds3 = ds2;
    cout << "equals on copy: ";
    ds3.print();

    ds2.unify(0, 3);
    cout << "changing copy: ";
    ds2.print();

    cout << "checking equals: ";
    ds3.print();

    ds.unify(1, 3);
    cout << "numComponents: " << ds.components() << " ";
    ds.print();
    ds.unify(5, 4);
    cout << "size: " << ds.size() << " ";
    ds.print();
    ds.unify(5, 0);
    cout << "size of component w/ 2: " << ds.componentSize(2) << " ";
    ds.print();
    ds.unify(3, 0);
    ds.print();
    return 0;
}

int minSwapsCouples(vector<int>& row) {     //leetcode 765
    int len = row.size()/2;
    UnionFind ds(len);
    for(int i = 0; i < row.size(); i += 2){
        ds.unify(row[i]/2, row[i+1]/2);
    }
    return len - ds.components();
}