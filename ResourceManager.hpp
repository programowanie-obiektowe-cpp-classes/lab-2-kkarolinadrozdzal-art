#pragma once

#include "Resource.hpp"

class ResourceManager
{ 
    Resource * bernard;
public:
    ResourceManager() {
        bernard = new Resource();
    }
    ResourceManager(const ResourceManager& other) 
    {
        if (other.bernard != nullptr) {
            bernard = new Resource(*other.bernard);
        }
        bernard = nullptr;
    }
    
    ResourceManager(ResourceManager&& other) noexcept {

        bernard = other.bernard; 
        other.bernard = nullptr;
    }

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other)
        {
            if (bernard != nullptr)
            {
                delete bernard;
            }
                bernard = new Resource(*other.bernard);
            
        }
        return *this;
    }
    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other)
        {
            delete bernard;
            bernard = other.bernard;
            other.bernard = nullptr;
        }
        return *this;
    }

    double get() {
        if (bernard == nullptr){
            return nullptr;
        }
        return bernard->get();
            
    }

    ~ResourceManager() {
        delete bernard;
    }
};
