#include "pch.h"
#include "../game/classes.h"

TEST(TestFunction, PassingTest) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
  EXPECT_FALSE(false);
}

TEST(SplitTest, SplitStrs) {
	vector<string> onevtr = { "title.game" };
	EXPECT_EQ(functions::split("title.game", "#"), onevtr);

	vector<string> vtr1 = { "title", "game" };
	EXPECT_EQ(functions::split("title.game", "."), vtr1);

	vector<string> vtr2 = { "title", "game", "art" };
	EXPECT_EQ(functions::split("title.game.art", "."), vtr2);
}

TEST(StoryClass, check_if_art) {
	Story story("_gtest");
	EXPECT_FALSE(story.check_if_art("test"));
	EXPECT_TRUE(story.check_if_art("test.art"));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}