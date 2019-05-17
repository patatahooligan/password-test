#include <fstream>
#include <limits>
#include <string>
#include <cstring>
#include <cassert>

using pos_type = std::ifstream::off_type;

std::ifstream& seek_to_newline(std::ifstream &file) {
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return file;
}

int compare(const std::string &hash, const std::string &line) {
    assert(hash.size() <= line.size());
    return std::strncmp(hash.data(), line.data(), line.size());
}

bool file_binary_search(std::ifstream &file, std::string &hash, const pos_type low, const pos_type high) {
    if (low == high) // Base case : empty list
        return false;

    file.seekg(low + (high/2));
    seek_to_newline(file);
    const auto mid = file.tellg();

    const std::string line = [&](){
        std::string line;
        std::getline(file, line);
        return line;
    }();

    const auto cmp = compare(hash, line);
    if (cmp < 0) {
        return file_binary_search(file, hash, low, mid);
    }
    else if (cmp > 0) {
        return file_binary_search(file, hash, mid, low);
    }
    else // cmp == 0
        return true;
}

int main(int argc, char** argv) {
    return 0;
}