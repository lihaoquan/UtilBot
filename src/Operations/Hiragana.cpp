#include "Hiragana.h"

void Hiragana::Do(Application& app) {

	std::string answer;
	std::string row;

	gameOngoing = true;

	while (gameOngoing) {
		
		// TODO: display sound and let user guess character.

		std::cout << "[Bot] Which row of Hiragana? " << std::endl;
		std::cout << "1) random" << std::endl;
		std::cout << "2) agyou" << std::endl;
		std::cout << "3) kagyou" << std::endl;
		std::cout << "4) sagyou" << std::endl;
		std::cout << "5) tagyou" << std::endl;
		std::cout << "6) nagyou" << std::endl;

		std::getline(std::cin, row);

		if (row == "exit") {
			gameOngoing = false;
			std::cout << "[Bot] Hiragana Test Stopped" << std::endl;
			return;
		}

		std::string hiragana;
		int random = rand() % 5;

		std::string* randomRow;

		if (row == "1")	{

			int selectedRow = rand() % 5;

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
			else if (selectedRow == 4) {
				randomRow = nagyouSound;
				hiragana = GetRandomHiragana(row::nagyou_row, random);
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
		else if (row == "6") {
			hiragana = GetRandomHiragana(row::nagyou_row, random);
		}
		else {
			continue;
		}

		std::cout << "[Bot] How to pronounce: " << hiragana << std::endl;

		std::getline(std::cin, answer);
		
		if (answer == "exit") {
			gameOngoing = false;
			std::cout << "[Bot] Hiragana Test Stopped" << std::endl;
			return;
		}
		else {
			std::string sound;
			if (row == "1") sound = randomRow[random];
			if (row == "2") sound = agyouSound[random];
			if (row == "3") sound = kagyouSound[random];
			if (row == "4") sound = sagyouSound[random];
			if (row == "5") sound = tagyouSound[random];
			if (row == "6") sound = nagyouSound[random];

			if (answer == sound) std::cout << "[Bot] Correct!" << std::endl;
			else std::cout << "[Bot] Wrong!" << std::endl;
		}
		

		Sleep(1);
	}
}

std::string Hiragana::GetRandomHiragana(row row, int random) {

	std::string character;

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
	else if (row == row::nagyou_row) {
		character = nagyou[random];
	}

	return character;
}