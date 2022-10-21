#include <vector>

namespace jce{
    namespace searchEngine{
        template<typename T>
        class Item {
        private: T item;
        private: std::vector<std::string> key;

        public: Item(std::vector<std::string>& key, T item);
        
        public: const std::string& getKey(const size_t& idx) const;
        public: const size_t getKeySize() const;
        };
    }
}

template<typename T>
inline jce::searchEngine::Item<T>::Item(std::vector<std::string>& _key, T _item) {
    item = _item;
    key = _key;
}

template<typename T>
inline const std::string& jce::searchEngine::Item<T>::getKey(const size_t& idx) const {
    return this->key[idx];
}
template<typename T>
inline const size_t jce::searchEngine::Item<T>::getKeySize() const {
    auto key = this->key.size();
    return key;
}