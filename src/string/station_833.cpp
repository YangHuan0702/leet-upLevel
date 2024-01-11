//
// Created by huan.yang on 2024-01-10.
//
/**
* 833. 字符串中的查找与替换
 * 你会得到一个字符串 s (索引从 0 开始)，你必须对它执行 k 个替换操作。替换操作以三个长度均为 k 的并行数组给出：indices, sources,  targets。

要完成第 i 个替换操作:

检查 子字符串  sources[i] 是否出现在 原字符串 s 的索引 indices[i] 处。
如果没有出现， 什么也不做 。
如果出现，则用 targets[i] 替换 该子字符串。
例如，如果 s = "abcd" ， indices[i] = 0 , sources[i] = "ab"， targets[i] = "eee" ，那么替换的结果将是 "eeecd" 。

所有替换操作必须 同时 发生，这意味着替换操作不应该影响彼此的索引。测试用例保证元素间不会重叠 。

例如，一个 s = "abc" ，  indices = [0,1] ， sources = ["ab"，"bc"] 的测试用例将不会生成，因为 "ab" 和 "bc" 替换重叠。
在对 s 执行所有替换操作后返回 结果字符串 。

子字符串 是字符串中连续的字符序列。
 *
*/
class Solution {
public:
    int GetOriginIndex(int index,std::vector<int>& indices,std::vector<int> &realyUse) {
        int r = 0;
        for (const auto &item: indices) {
            if (item == index && std::find(realyUse.begin(), realyUse.end(),r) == realyUse.end()) {
                realyUse.push_back(r);
                break;
            }
            r ++;
        }
        return r;
    }

    std::string findReplaceString(std::string s, std::vector<int>& indices, std::vector<std::string>& sources, std::vector<std::string>& targets) {
        int k = sources.size();
        std::vector newIndices(indices);
        std::sort(indices.begin(),indices.end(),[](int a,int b) {
            return a < b;
        });

        std::vector<int> realyUse;

        int lastMoveSize = 0;
        for (int index = 0; index < k; index ++) {
            int orginIndex = GetOriginIndex(indices[index],newIndices,realyUse);
            std::string &source = sources[orginIndex];
            int startIndex = indices[index] + lastMoveSize;
            std::string replaces = targets[orginIndex];
            std::string target = s.substr(startIndex ,s.length() - startIndex < source.length() ? s.length() - startIndex : source.length());
            if (source == target) {
                s = s.replace(startIndex,source.length(),replaces);
                lastMoveSize += replaces.size() - source.size();
            }
        }
        return s;
    }
};