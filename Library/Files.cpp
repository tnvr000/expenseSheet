class Files
{
private:
    fstream userFile, itemFile;
    Files()
    {
        userFile.open("AccountFile.txt", ios::in | ios::out | ios::binary | ios::app);
    }
public:
    static Files* instance;
};

Files* Files::instance = NULL;