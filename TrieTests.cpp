#include "gtest/gtest.h"
#include <string>
#include "Trie.h"

TEST(TrieTests, GetPrefixWithWildcardNos) {
    std::vector<std::string> v;
    EXPECT_EQ (v, v);
}

TEST(TrieTests, AddStringToTrieTest){
  std::string test_string = "thisisatest";
  Trie test_trie;
  test_trie.addAWord(test_string);
  ASSERT_EQ(true, test_trie.isAWord(test_string));
}

// TEST (SquareRootTest, ZeroAndNegativeNos) {
//     ASSERT_EQ (0.0, (0.0));
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
