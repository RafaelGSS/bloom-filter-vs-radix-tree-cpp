#include <iostream>

#include "src/bloom_filter.h"
#include "src/radix_tree.h"

int bloom_test() {
  BloomFilter bf;

  std::string sarray[33]
    = { "abound",   "abounds",       "abundance",
      "abundant", "accessible",    "bloom",
      "blossom",  "bolster",       "bonny",
      "bonus",    "bonuses",       "coherent",
      "cohesive", "colorful",      "comely",
      "comfort",  "gems",          "generosity",
      "generous", "generously",    "genial",
      "bluff",    "cheater",       "hate",
      "war",      "humanity",      "racism",
      "hurt",     "nuke",          "gloomy",
      "facebook", "geeksforgeeks", "twitter" };
  for (int i = 0; i < 33; i++) {
    bf.Insert("/home/repos/" + sarray[i]);
  }
  std::cout << bf.Lookup("/tmp/") << std::endl;
  std::cout << bf.Lookup("/usr/") << std::endl;
  std::cout << bf.Lookup("/home/repos/valid-path") << std::endl;

  return 0;
}

int radix_test() {
  RadixTree rt;
  rt.Insert("/home/rafaelgss/repos/gitignore");
  rt.Insert("/tmp/*");
  rt.Insert("/home/joao");
  rt.Insert("/home/rafaelgss/repos/readme");

  std::cout << rt.Lookup("/home/rafaelgss/") << std::endl;
  std::cout << rt.Lookup("/home/rafaelgss") << std::endl;
  std::cout << rt.Lookup("/home/readme") << std::endl;

  std::cout << rt.Lookup("/home/rafaelgss/repos/readme2") << std::endl;
  std::cout << rt.Lookup("/home/rafaelgss/reposreadme") << std::endl;
  std::cout << rt.Lookup("/home/rafaelgss/repos/readme") << std::endl;
  std::cout << rt.Lookup("/tmp/aout") << std::endl;
  std::cout << rt.Lookup("/tmp/") << std::endl;
  std::cout << rt.Lookup("/tmp/dsadsa/dsadsad/dsadadsa/dsadsadsa/dasdasdsa") << std::endl;
  return 0;
}

int main() {
  /* bloom_test(); */
  radix_test();
  return 0;
}
