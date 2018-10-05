#include "gtest/gtest.h"
#include "Trie.h"

TEST(TrieTests, GetPrefixWithWildcardNos) {
    std::vector<std::string> v;
    EXPECT_EQ (v, v);
}

// TEST (SquareRootTest, ZeroAndNegativeNos) {
//     ASSERT_EQ (0.0, (0.0));
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
