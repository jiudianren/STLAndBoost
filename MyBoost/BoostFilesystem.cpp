/*
 *
 * boost::filesystem
 *
 *  https://www.boost.org/doc/libs/1_31_0/libs/filesystem/doc/index.htm
 *
 *
 * */


#include "filesystem.hpp"


int main()
{


    filesystem::path dirpath = "I:\\迅雷下载";
    filesystem::directory_iterator end;// 只支持本层目录遍历
    for (filesystem::directory_iterator iter(dirpath); iter != end; iter++)
    {
        filesystem::path p = *iter;
        //std::cout << p.leaf() << std::endl;// 叶子结点文件名
        //std::cout << p.stem() << std::endl;// 叶子结点文件名（无后缀）
        //std::cout << p.string() << std::endl;// 文件名（不带引号）
        std::cout << p.leaf().string() << std::endl;// 叶子结点文件名std::string型
    }

    return 1;
}
