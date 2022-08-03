#include <iostream>

#include "src/bloom_filter.h"

int main() {
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
    bf.Insert(sarray[i]);
  }
  std::cout << bf.Lookup("Tennis") << std::endl;
  std::cout << bf.Lookup("/facebook") << std::endl;
  std::cout << bf.Lookup("facebook") << std::endl;

  return 0;
}
