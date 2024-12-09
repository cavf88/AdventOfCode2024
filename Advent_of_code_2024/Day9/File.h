#include <string>

class File
{
public:
    File(const int id, const int layOutSize, const int freeSpace);
    ~File() = default;


    const int getId() const;
    const int getFileLayoutSize() const;
    const int getFreeSpace() const;
    const int getUsedSpace() const;

    void useSpace(const int size);
    
    bool isFull() const;
    bool isModified() const;

    const std::string getFileLayout() const;

private:

    int m_id;
    int m_layoutSize;
    int m_freeSpace;
    int m_usedSpace;

    std::string m_fileLayout;
};