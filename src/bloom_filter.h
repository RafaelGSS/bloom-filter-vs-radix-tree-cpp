#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <string>
#include <vector>

class BloomFilter {
public:
  BloomFilter();
  ~BloomFilter();

  void Insert(std::string s);
  bool Lookup(std::string s);
private:
  std::vector<bool> bitarray_;
  int arrSize_;
};

#endif
