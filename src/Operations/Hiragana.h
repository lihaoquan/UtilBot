#pragma once

#include "../Operation.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

class Hiragana
	: public Operation
{
public:
	Hiragana(std::string name)
		: Operation(name) {
	}

	void Do(Application& app) override;

	enum class row { agyou_row, kagyou_row };

	std::string GetRandomHiragana(row row, int random);
private:
	bool gameOngoing = true;

	std::string agyou[5] = {"あ", "い", "う", "え", "お"};
	std::string agyouSound[5] = { "a", "i", "u", "e", "o" };

	std::string  kagyou[5] = { "か", "き", "く", "け", "こ" };
	std::string kagyouSound[5] = { "ka", "ki", "ku", "ke", "ko" };
};