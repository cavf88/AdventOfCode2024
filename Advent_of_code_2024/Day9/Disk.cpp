#include "Disk.h"
#include <iostream>
#include <string>
#include <vector>

const static int FREE_SPACE_VALUE = -1;

void Disk::pushFile(const File& file)
{
    m_files.push_back(file);
}

void Disk::compactDisk(bool moveFile)
{
    //std::vector<int> diskVec;

    for(const auto& f: m_files)
    {
        const int layOutSize = f.getFileLayoutSize();
        const int id = f.getId();
        for(int i = 0; i < layOutSize; i++)
        {
            m_filesCompacted.push_back(id);
        }
        const int freeSpace = f.getFreeSpace();
        for(int i = 0; i < freeSpace; i++)
        {
            m_filesCompacted.push_back(FREE_SPACE_VALUE);
        }
    }


    if(moveFile)
        compactDiskByFiles();
    else
        compactDiskByBlocks();
}

void Disk::compactDiskByBlocks()
{
    int i = 0;
    int k = m_filesCompacted.size() - 1;
    do
    {
        if(m_filesCompacted[i] == -1)
        {
            if(m_filesCompacted[k] == -1)
            {
                do{
                    k--;
                }while(m_filesCompacted[k] == -1);
            }
            const int temp = m_filesCompacted[i];
            m_filesCompacted[i] = m_filesCompacted[k];
            m_filesCompacted[k] = temp;
            k--;
        }
        i++;
    }while(i != k);
}

void Disk::compactDiskByFiles()
{
    
}

void Disk::outPutDisk()
{
    uint64_t sum = 0;
    for(int i = 0; i < m_filesCompacted.size(); ++i)
    {
        if(m_filesCompacted[i] != -1)
            sum += i * m_filesCompacted[i];
    }
    std::cout << sum;

    //std::string str;
    //    for(const auto& i: diskVec)
    //    {
    //        str += (i != FREE_SPACE_VALUE)? std::to_string(i) : ".";
    //    }
    //std::cout << str;

}