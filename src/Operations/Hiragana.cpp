#include "Hiragana.h"

void Hiragana::Do(Application& app) {

	std::string answer;
	std::string row;

	gameOngoing = true;

	while (gameOngoing) {
		
		// TODO: display sound and let user guess character.

		std::wcout << "[Bot] Which row of Hiragana? " << std::endl;
		std::wcout << "1) random" << std::endl;
		std::wcout << "2) agyou" << std::endl;
		std::wcout << "3) kagyou" << std::endl;
		std::wcout << "4) sagyou" << std::endl;
		std::wcout << "5) tagyou" << std::endl;

		std::getline(std::cin, row);

		if (row == "exit") {
			gameOngoing = false;
			std::wcout << "[Bot] Hiragana Test Stopped" << std::endl;
			return;
		}

		wchar_t* hiragana;
		int random = rand() % 5;

		std::string* randomRow = agyouSound;

		if (row == "1")	{

			int selectedRow = rand() % 4;

			if (selectedRow == 0) {
				randomRow = agyouSound;
				hiragana = GetRandomHiragana(row::agyou_row, random);
			}
			else if (selectedRow == 1) {
				randomRow = kagyouSound;
				hiragana = GetRandomHiragana(row::kagyou_row, random);
			}
			else if (selectedRow == 2) {
				randomRow = sagyouSound;
				hiragana = GetRandomHiragana(row::sagyou_row, random);
			}
			else if (selectedRow == 3) {
				randomRow = tagyouSound;
				hiragana = GetRandomHiragana(row::tagyou_row, random);
			}
			else {
				continue;
			}
		}
		else if (row == "2") {
			hiragana = GetRandomHiragana(row::agyou_row, random);
		}
		else if (row == "3") {
			hiragana = GetRandomHiragana(row::kagyou_row, random);
		} 
		else if (row == "4") {
			hiragana = GetRandomHiragana(row::sagyou_row, random);
		}
		else if (row == "5") {
			hiragana = GetRandomHiragana(row::tagyou_row, random);
		}
		else {
			continue;
		}

		std::wcout << "[Bot] How to pronounce: ";
		wprintf(L"%s", hiragana);
		std::wcout << std::endl;

		std::getline(std::cin, answer);
		
		if (answer == "exit") {
			gameOngoing = false;
			std::wcout << "[Bot] Hiragana Test Stopped" << std::endl;
			return;
		}
		else {
			std::string sound;

			if (row == "1") sound = randomRow[random];
			if (row == "2") sound = agyouSound[random];
			if (row == "3") sound = kagyouSound[random];
			if (row == "4") sound = sagyouSound[random];
			if (row == "5") sound = tagyouSound[random];

			if (answer == sound) std::wcout << "[Bot] Correct!" << std::endl;
			else std::wcout << "[Bot] Wrong!" << std::endl;
		}
		
		Sleep(1);
	}
}

wchar_t* Hiragana::GetRandomHiragana(row row, int random) {

	wchar_t* character = agyou[random];

	if (row == row::agyou_row) {
		character = agyou[random];
	}
	else if (row == row::kagyou_row) {
		character = kagyou[random];
	}
	else if (row == row::sagyou_row) {
		character = sagyou[random];
	}
	else if (row == row::tagyou_row) {
		character = tagyou[random];
	}

	return character;
}