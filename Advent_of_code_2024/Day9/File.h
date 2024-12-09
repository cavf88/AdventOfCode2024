#include <string>

class File
{
public:
    File(const int id, const int layOutSize, const int freeSpace);
    ~File() = default;


    const int getId() const;
    const int getFileLayoutSize() const;
    const int getFreeSpace() const;

    const std::string getFileLayout() const;



private:

    int m_id;
    int m_layoutSize;
    int m_freeSpace;

    std::string m_fileLayout;
};