//
// Created by huan.yang on 2024-01-10.
//
#include <iostream>
#include <stack>
#include <algorithm>

#include <vector>


class Solution {
public:
    std::string findReplaceString(std::string s, std::vector<int>& indices, std::vector<std::string>& sources, std::vector<std::string>& targets) {
        size_t k = sources.size();
        std::sort(indices.begin(),indices.end(),[](int a,int b) {
            return b < a;
        });

        for (size_t index = k; index >= 0; index--) {
            std::string &source = sources[index];
            std::string target = s.substr(indices[index],source.length());
            if (source == target) {
                s = s.replace(indices[index],source.length(),targets[index]);
            }
        }
        return s;
    }
};

std::string findReplaceString(std::string s, std::vector<int>& indices, std::vector<std::string>& sources, std::vector<std::string>& targets) {
    int k = sources.size();
    std::sort(indices.begin(),indices.end(),[](int a,int b) {
        return a < b;
    });


//    for (int index = k - 1; index >= 0; index --) {
    for (int index = 0; index < k; index ++) {
        std::string &source = sources[index];
        std::string target = s.substr(indices[index],source.length());
        std::cout << "source : "<< source << " target: " << target << std::endl;
        if (source == target) {
            s = s.replace(indices[index],source.length(),targets[index]);
        }
    }
    return s;
}

int main() {
    std::cout << "====================================" << std::endl;
    std::cout << "Starting C++ Up Level Log" << std::endl;

    std::string s = "vmokgggqzp";
    std::vector<int> indices {3,5,1};
    std::vector<std::string> sources {"kg","ggq","mo"};
    std::vector<std::string> targets{"s","so","bfr"};
    auto r= findReplaceString(s,indices,sources,targets);
    // "vbfrssozp"
    std::cout << "result:" ;
    std::cout << r << std::endl;
}