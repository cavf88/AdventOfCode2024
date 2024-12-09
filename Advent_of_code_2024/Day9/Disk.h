#include <vector>
#include "File.h"

class Disk
{
    public:
        Disk() = default;
        ~Disk() = default;

        void pushFile(const File& file);
        void outPutDisk(bool asString = false);
        void compactDisk(bool moveFile = false);

    private:
        std::vector<File> m_files;
        std::vector<int> m_filesCompacted;

        void compactDiskByBlocks();
        void compactDiskByFiles();
};