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

TEST(StoryClass_constructor, constructor) {
	Story story(L"../story/", L"0_egyetem", L"_start");
	EXPECT_EQ(story.path, L"../story/");
	EXPECT_EQ(story.link, L"0_egyetem");
	EXPECT_EQ(story.prev_link, L"_start");

	wstring body = L"Jó választás! A játékunk csak erre az ágra terjed ki. Meg itt lehet bulizni. Apropos, megnézed a campust, és meglátod középen a kocsmát. \n";
	EXPECT_EQ(story.body, body);
	vector<wstring> texts = { L"Odamegyek, és elmesélem mindenkinek, hogy ide fogok járni!", L"Tovább nézelődök, olyan nagy ez a hely!" };
	EXPECT_EQ(story.btn_texts, texts);
	vector<wstring> links = { L"01_lapos", L"01_egyetem.art" };
	EXPECT_EQ(story.btn_links, links);
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