#include "File.h"

File::File(const int id, const int layOutSize, const int freeSpace)
: m_id(id)
,m_layoutSize(layOutSize)
, m_freeSpace(freeSpace)

{
    for(int i = 0; i < layOutSize; ++i)
    {
        m_fileLayout += std::to_string(m_id);
    }
}

const int File::getId() const
{
    return m_id;
}

const int File::getFileLayoutSize() const
{
    return m_layoutSize;
}

const int File::getFreeSpace() const
{
    return m_freeSpace;
}

const std::string File::getFileLayout() const
{
    return m_fileLayout;
}