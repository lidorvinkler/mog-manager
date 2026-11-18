#pragma once
#include <map>
#include <memory>
#include <stdexcept>
#include <string>


template <class T>
class Factory {
    private:
    std::map<std::string, std::unique_ptr<T>(*)()> factory;
    public:
    Factory() = default;
    ~Factory() = default;
    template <class T1>
    void addElem(const std::string& name) {
        factory[name] = []()-> std::unique_ptr<T> {return std::make_unique<T1>();};
    }
    std::unique_ptr<T> creates(const std::string& name) const{
        auto it = factory.find(name);
        if (it == factory.end()) {
            throw std::invalid_argument("Unknown " + name);
        }
        return it -> second();
    }
};
