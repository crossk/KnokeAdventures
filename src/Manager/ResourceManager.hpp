#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include "SFML/Graphics.hpp"

#include <unordered_map>
#include <fstream>
#include <string>
#include <iostream>

template <typename Derived, class T>
class ResourceManager
{
public:
    ResourceManager(const std::string & file)
    {
        populateStorage(file);
    }

    ~ResourceManager()
    {
        killResources();
    }

    bool addResource(const std::string & resourceName)
    {
        auto res = find(resourceName);

        if(res)
        {
            ++res->second;
            return true;
        }

        auto filePath = fileMap.find(resourceName);

        if(filePath == fileMap.end())
        {
            return false;
        }

        T* resource = load(filePath->second);

        if(!resource)
        {
            return false;
        }

        resourceMap.emplace(resourceName, std::make_pair<resource, 1>);
        return true;
    }

    T* getResource(const std::string & resourceName)
    {
        auto res = find(resourceName);

        if(res)
        {
            return res->first;
        }
        return nullptr;
    }

    bool releaseResource(const std::string & resourceName)
    {
        auto res = find(resourceName);

        if(!res)
        {
            return false;
        }

        if(!res->second)
        {
            unload(resourceName);
        }
        return true;
    }

    void killResources()
    {
        while(resourceMap.begin() != resourceMap.end())
        {
            delete resourceMap.begin()->second.first;
            resourceMap.erase(resourceMap.begin());
        }
    }

    T* load(const std::string & path)
    {
        return static_cast<Derived*>(this)->load(path);
    }
private:
    std::unordered_map<std::string, std::pair<T*, int>> resourceMap;
    std::unordered_map<std::string, std::string> fileMap;

    std::pair<T*, int>* find(const std::string resourceName)
    {
        auto itr = resourceMap.find(resourceName);

        if(itr != resourceMap.end())
        {
            return &itr->second;
        }
        else
        {
            return nullptr;
        }
    }

    void unload(const std::string & resourceName)
    {
        auto itr = resourceMap.find(resourceName);

        if(itr != resourceMap.end())
        {
            std::cerr << "Failed to unload " << resourceName << std::endl;
            return;
        }

        delete itr->second.first;
        resourceMap.erase(itr);
    }

    void populateStorage(const std::string & fileName)
    {
        std::ifstream filestream(fileName);

        if(filestream.is_open())
        {
            std::string pathName;
            std::string path;

            while(!filestream.eof())
            {
                filestream >> pathName >> path;
                fileMap.emplace(pathName, path);
            }

            filestream.close();
            return;
        }

        std::cerr << "Failed to populate storage from file " << fileName << std::endl;
    }
};

#endif // RESOURCEMANAGER_HPP
