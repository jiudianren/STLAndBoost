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


    filesystem::path dirpath = "I:\\Ѹ������";
    filesystem::directory_iterator end;// ֻ֧�ֱ���Ŀ¼����
    for (filesystem::directory_iterator iter(dirpath); iter != end; iter++)
    {
        filesystem::path p = *iter;
        //std::cout << p.leaf() << std::endl;// Ҷ�ӽ���ļ���
        //std::cout << p.stem() << std::endl;// Ҷ�ӽ���ļ������޺�׺��
        //std::cout << p.string() << std::endl;// �ļ������������ţ�
        std::cout << p.leaf().string() << std::endl;// Ҷ�ӽ���ļ���std::string��
    }

    return 1;
}
