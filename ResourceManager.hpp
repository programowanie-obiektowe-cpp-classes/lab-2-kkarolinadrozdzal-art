#pragma once

#include "Resource.hpp"

class ResourceManager
{
    Resource * bernard;
ResourceManager() {
    bernard = new Resource();
}
ResourceManager(const ResourceManager& other) {
    bernard = new Resource(*other.bernard);
}

ResourceManager(ResourceManager&& other) noexcept {

    bernard = other.bernard; 
}

ResourceManager& operator=(const ResourceManager& other)
{
    if (this != &other)
    {
        delete bernard;
        bernard = new Resource(*other.bernard);
    }
    return *this;
}
ResourceManager& operator=(ResourceManager& other) noexcept
{
    if (this != &other)
    {
        delete bernard;
        bernard = other.bernard;
    }
    return *this;
}

double get() {
    return bernard->get();
}

~ResourceManager() {
    delete bernard;
}
};
