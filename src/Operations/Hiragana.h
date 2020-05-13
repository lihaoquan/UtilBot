#pragma once

#include "../Operation.h"
#include <iostream>
#include <string>
#include <stdlib.h>

class Hiragana
	: public Operation
{
public:
	Hiragana(std::string name)
		: Operation(name) {
	}

	void Do(Application& app) override;

	enum class row { agyou_row, kagyou_row, sagyou_row, tagyou_row };

	wchar_t* GetRandomHiragana(row row, int random);
private:
	bool gameOngoing = true;

	wchar_t* agyou[5] = {L"あ", L"い", L"う", L"え", L"お"};
	std::string agyouSound[5] = { "a", "i", "u", "e", "o" };

	wchar_t* kagyou[5] = { L"か", L"き", L"く", L"け", L"こ" };
	std::string kagyouSound[5] = { "ka", "ki", "ku", "ke", "ko" };

	wchar_t* sagyou[5] = { L"さ", L"し", L"す", L"せ", L"そ"};
	std::string sagyouSound[5] = { "sa", "shi", "su", "se", "so" };

	wchar_t* tagyou[5] = { L"た", L"ち", L"つ", L"て", L"と" };
	std::string tagyouSound[5] = { "ta", "chi", "tsu", "te", "to" };
};