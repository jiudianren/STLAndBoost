/*
 *
 * boost::filesystem
 *
 *  https://www.boost.org/doc/libs/1_31_0/libs/filesystem/doc/index.htm
 *
 *
 * */



#include <boost/filesystem.hpp>
#include "BoostFilesystem.h"
#include <iostream>


int mainBFileSys()
{


    boost::filesystem::path dirpath = "I:\\Ѹ������";
    boost::filesystem::directory_iterator end;// ֻ֧�ֱ���Ŀ¼����
    for (boost::filesystem::directory_iterator iter(dirpath); iter != end; iter++)
    {
    	boost::filesystem::path p = *iter;
        //std::cout << p.leaf() << std::endl;// Ҷ�ӽ���ļ���
        //std::cout << p.stem() << std::endl;// Ҷ�ӽ���ļ������޺�׺��
        //std::cout << p.string() << std::endl;// �ļ������������ţ�
        std::cout << p.leaf().string() << std::endl;// Ҷ�ӽ���ļ���std::string��
    }

    return 1;
}
