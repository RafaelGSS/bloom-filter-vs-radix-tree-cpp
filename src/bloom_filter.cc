#include "./bloom_filter.h"
#include <iostream>
#include <cmath>

// hash 1
int h1(std::string s, unsigned int arrSize)
{
    long long unsigned int hash = 0;
    for (int i = 0; i < s.size(); i++) 
    {
        hash = (hash + ((int)s[i]));
        hash = hash % arrSize;
    }
    return hash;
}

// hash 2
int h2(std::string s, unsigned int arrSize)
{
    long long unsigned int hash = 1;
    for (int i = 0; i < s.size(); i++) 
    {
        hash = hash + std::pow(19, i) * s[i];
        hash = hash % arrSize;
    }
    return hash % arrSize;
}

// hash 3
int h3(std::string s, int arrSize)
{
    long long unsigned int hash = 7;
    for (int i = 0; i < s.size(); i++) 
    {
        hash = (hash * 31 + s[i]) % arrSize;
    }
    return hash % arrSize;
}

// hash 4
int h4(std::string s, int arrSize)
{
    long long unsigned int hash = 3;
    int p = 7;
    for (int i = 0; i < s.size(); i++) {
        hash += hash * 7 + s[0] * std::pow(p, i);
        hash = hash % arrSize;
    }
    return hash;
}

BloomFilter::BloomFilter(): bitarray_({ false }), arrSize_(100) {
}

BloomFilter::~BloomFilter() {}

// lookup operation
bool BloomFilter::Lookup(std::string s) {
    int a = h1(s, arrSize_);
    int b = h2(s, arrSize_);
    int c = h3(s, arrSize_);
    int d = h4(s, arrSize_);

    return bitarray_[a] && bitarray_[b] && bitarray_[c] && bitarray_[d];
}

void BloomFilter::Insert(std::string s) {
    if (!Lookup(s)) {
        int a = h1(s, arrSize_);
        int b = h2(s, arrSize_);
        int c = h3(s, arrSize_);
        int d = h4(s, arrSize_);

        bitarray_[a] = true;
        bitarray_[b] = true;
        bitarray_[c] = true;
        bitarray_[d] = true;
    }
}
