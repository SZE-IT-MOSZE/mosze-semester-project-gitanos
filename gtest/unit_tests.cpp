#pragma once

#include "pch.h"
#include "../game/classes.h"

using namespace std;

TEST(SplitTest, SplitStrs) {
	vector<wstring> onevtr = { L"title.game" };
	EXPECT_EQ(functions::split(L"title.game", L"#"), onevtr);

	vector<wstring> vtr1 = { L"title", L"game" };
	EXPECT_EQ(functions::split( L"title.game", L"."), vtr1);

	vector<wstring> vtr2 = { L"title", L"game", L"art" };
	EXPECT_EQ(functions::split(L"title.game.art", L"."), vtr2);
}

TEST(StoryClass_check_if_art, check_if_art) {
	Story story(L"../story/", L"_start", L"_start");
	EXPECT_FALSE(story.check_if_art(L"test"));
	EXPECT_TRUE(story.check_if_art(L"test.art"));
}

TEST(StoryClass_link_to_raw_text, link_to_raw_text) {
	Story story(L"../story/", L"_gtest", L"_gtest");
	wstring expected_text = L"story for\n"
		L"gtext\n"
		L"\n"
		L"|NOT ART>00_some_story\n"
		L"|Now this is art!>02_some.art";
	EXPECT_EQ(story.link_to_raw_text(L"_gtest"), expected_text);
}

TEST(StoryClass_split_to_body_and_links, split_to_body_and_links) {
	Story story(L"../story/", L"_gtest", L"_gtest");
	wstring body = L"story for\n"
		L"gtext\n"
		L"\n";
	wstring btn1 = L"NOT ART";
	wstring btn2 = L"Now this is art!";
	wstring link1 = L"00_some_story";
	wstring link2 = L"02_some.art";
	wstring raw_text = L"story for\n"
		L"gtext\n"
		L"\n"
		L"|NOT ART>00_some_story\n"
		L"|Now this is art!>02_some.art";
	story.split_to_body_and_links(raw_text);
	EXPECT_EQ(story.body, body);
	EXPECT_EQ(story.btn_texts[0], btn1);
	EXPECT_EQ(story.btn_texts[1], btn2);
	EXPECT_EQ(story.btn_links[0], link1);
	EXPECT_EQ(story.btn_links[1], link2);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}