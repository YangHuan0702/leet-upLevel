//
// Created by huan.yang on 2024-01-10.
//
#include <iostream>
#include <stack>
#include <algorithm>

#include <map>
#include <hash_map>
#include <vector>

std::string defangIPaddr(std::string address) {
    std::string r;
    for (int index = 0; index < address.length(); index++) {
        if (address[index] == '.') {
            r.push_back('[');
            r.push_back('.');
            r.push_back(']');
        } else {
            r.push_back(address[index]);
        }
    }
    return r;
}


int main() {

}