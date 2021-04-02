struct File
{
    int descriptor;
    char buffer[MAX_BUFFER_SIZE];
};

File *openFile(const char *file_name)
{
    File *file = (File *)malloc(sizeof(File));
    file->descriptor = open(file_name, O_CREATE);
    return file;
}

void write(File *file, const char*text)
{
    //...
}

void closeFile(File *file)
{
    // Сбросить буффер, если что-то в нём есть.
    // ...
    close(file->descriptor);
    free(file);
}

class BufferFile
{
public:
    BufferFile()
    {
        i = new int();
        descriptor_ = open(file_name, O_CREATE);
    }

    ~BufferFile()
    {
        delete i;
        close(descriptor);
    }
    void open(const char* file_name)
    {
        descriptor_ = open(file_name, O_CREATE);
    }

    void write(const char* text)
    {
        // ...
    }

    void close()
    {
        close(descriptor);
    }
    int *i;
    //~/
private:
    int descriptor_;
    char buffer[MAX_BUFFER_SIZE];
};

// BufferFile bfile;
// bfile.open("text.txt");
// bfile.write("Some string");
// bfile.close();

// BufferFile bfile;
// bfile.a <-- ошибка
