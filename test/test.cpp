#include <iostream>
#include <jceSearchEngine/nameSearch.hpp>

int main(int argc, char **argv) {
  jce::searchEngine::nameSearch<size_t> search;
  std::vector<std::string> key = {"denanu", "eris"};
  std::shared_ptr<jce::searchEngine::Item<size_t>> item(new jce::searchEngine::Item<size_t>(key, 1));
  search.addChild(item);
  return 1;
}