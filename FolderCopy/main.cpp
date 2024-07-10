#include <iostream>
#include <string>
#include <filesystem>
#include <map>

int main()
{
    std::string path = "/home/darius/Books/";
    std::string finalPath = "/mnt/usb/Books/";
    std::map<std::string, bool> existingElements;
    for(const auto& entry : std::filesystem::directory_iterator(finalPath))
    {
        std::string currentFile = entry.path().string();
        currentFile = currentFile.substr(currentFile.find_last_of("/") + 1);
        existingElements[currentFile] = 1;
        /* std::cout << existingElements.back() << "\n"; */
    }
    
    for(const auto& entry : std::filesystem::directory_iterator(path))
    {
        std::string currentFile = entry.path().string();
        currentFile = currentFile.substr(currentFile.find_last_of("/") + 1);
        /* std::cout << currentFile << '\n'; */
        if(!existingElements[currentFile])
        {
            std::cout << "Copy " << path + currentFile + "/" << " to " << finalPath << '\n';
            if(currentFile.find(".") != std::string::npos) std::filesystem::copy(path+currentFile, finalPath, std::filesystem::copy_options::overwrite_existing);
            else 
            {
                std::filesystem::create_directory(finalPath + currentFile + "/");
                for(const auto& entry : std::filesystem::directory_iterator(path + currentFile + "/"))
                {
                    std::filesystem::copy(entry.path().string(), finalPath + currentFile + "/", std::filesystem::copy_options::overwrite_existing);
                }
            }
        }
    }
}
