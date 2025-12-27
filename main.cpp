#include <filesystem>
#include <fstream>
#include <vector>

namespace fs = std::filesystem;
constexpr size_t HEADER_LEN = 256;

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <key> <file>\n", argv[0]);
        return 1;
    }

    std::string key = argv[1];
    fs::path file = argv[2];

    std::fstream f(file, std::ios::in | std::ios::out | std::ios::binary);
    if (!f)
    {
        printf("Unable to open file: %s\n", argv[2]);
        return 1;
    }

    std::vector<char> buf(HEADER_LEN);
    f.seekg(0);
    f.read(buf.data(), buf.size());
    std::streamsize n = f.gcount();
    if (n <= 0)
    {
        printf("The file is too small.\n");
        return 1;
    }

    size_t key_pos = 0;
    for (std::streamsize i = 0; i < n; ++i)
    {
        buf[i] ^= key[key_pos];
        key_pos = (key_pos + 1) % key.size();
    }

    f.seekp(0);
    f.write(buf.data(), n);
    f.flush();
    return 0;
}
