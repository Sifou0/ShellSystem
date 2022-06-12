#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

void displayContent(string path)
{
    for (const auto & entry : fs::directory_iterator(path)) std::cout << entry.path() << std::endl;

}


int main()
{
    displayContent("/");
    return 0;
}