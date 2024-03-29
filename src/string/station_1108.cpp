//
// Created by huan.yang on 2024-01-16.
//
/**
* IP 地址无效化
 * 给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。

所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。



示例 1：

输入：address = "1.1.1.1"
输出："1[.]1[.]1[.]1"
示例 2：

输入：address = "255.100.50.0"
输出："255[.]100[.]50[.]0"


提示：

给出的 address 是一个有效的 IPv4 地址
*/

class Solution {
public:
    string defangIPaddr(string address) {
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
};