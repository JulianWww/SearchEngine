#include "item.hpp"
#include <unordered_map>
#include <memory>
#include <vector>

namespace jce {
    namespace searchEngine
    {
        template<typename T>
        class nameSearch {
            private: std::unordered_map<char, std::unique_ptr<nameSearch<T>>> children;
            private: std::vector<std::shared_ptr<Item<T>>> items;

            public:  bool addChild(std::shared_ptr<Item<T>> item);
            private: bool addChild(std::shared_ptr<Item<T>> item, size_t deapth, const size_t& idx);

            private: nameSearch<T>& addChild(char key);
        };
    }
}

template<typename T>
bool jce::searchEngine::nameSearch<T>::addChild(std::shared_ptr<Item<T>> item){
    size_t idx = 0;
    bool out = true;
    for (size_t idx=0; idx<item->getKeySize(); idx++)
        out = out && this->addChild(item, 0, idx);
    return out;
}
template<typename T>
bool jce::searchEngine::nameSearch<T>::addChild(std::shared_ptr<Item<T>> item, size_t deapth, const size_t& idx){
    if (deapth == item->getKey(idx).size()) {
        this->items.push_back(item);
        return true;
    }
    return this->addChild(item->getKey(idx)[deapth]).addChild(item, deapth+1, idx);
}

template<typename T>
inline jce::searchEngine::nameSearch<T>& jce::searchEngine::nameSearch<T>::addChild(char key) {
    if (!this->children.contains(key)){
        this->children.insert({key, std::make_unique<nameSearch<T>>()});
    }
    return *this->children.at(key).get();
}