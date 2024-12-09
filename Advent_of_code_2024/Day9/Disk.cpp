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

    int filek = m_files.size() - 1;
    int posB = m_filesCompacted.size() - 1;
    do
    {
        File& fileB = m_files[filek];
        int posA = 0;
        bool swapped = false;
        for(int i = 0; i < filek; ++i)
        {
            File& fileA = m_files[i];
            posA += fileA.getFileLayoutSize() + fileA.getUsedSpace();
            if(fileA.getFreeSpace() >= fileB.getFileLayoutSize())
            {
                if(fileB.isModified())
                    posB -= fileB.getFreeSpace() + fileB.getUsedSpace();
                else
                    posB -= fileB.getFreeSpace();
                int s = 0;
                for(; s < fileB.getFileLayoutSize(); s++)
                {
                    const int temp = m_filesCompacted[posA + s];
                    m_filesCompacted[posA + s] = m_filesCompacted[posB - s];
                    m_filesCompacted[posB - s] = temp;
                }
                posB -= s;
                fileA.useSpace(s);
                swapped = true;
                break;
            }
            posA += fileA.getFreeSpace();
        }
        if(!swapped)
            posB -= (fileB.getFileLayoutSize()  + fileB.getFreeSpace());
        filek--;
    } while (filek > 0);
}

void Disk::outPutDisk(bool asString)
{

    if(asString)
    {
        std::string str;
            for(const auto& i: m_filesCompacted)
            {
                str += (i != FREE_SPACE_VALUE)? std::to_string(i) : ".";
            }
        std::cout << str;
        }
    else
    {
        uint64_t sum = 0;
        for(int i = 0; i < m_filesCompacted.size(); ++i)
        {
            if(m_filesCompacted[i] != -1)
                sum += i * m_filesCompacted[i];
        }
        std::cout << sum;
    }
    

}