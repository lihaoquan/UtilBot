#include "Hiragana.h"

void Hiragana::Do(Application& app) {

	std::string answer;
	std::string row;

	gameOngoing = true;

	while (gameOngoing) {
		
		// TODO: display sound and let user guess character.
		// TODO: random row selection

		std::cout << "[Bot] Which row of Hiragana? " << std::endl;
		std::cout << "1) agyou" << std::endl;
		std::cout << "2) kagyou" << std::endl;
		std::cout << "3) sagyou" << std::endl;

		std::getline(std::cin, row);

		if (row == "exit") {
			gameOngoing = false;
			std::cout << "[Bot] Hiragana Test Stopped" << std::endl;
			return;
		}

		std::string hiragana;
		int random = rand() % 5;

		if (row == "1") {
			hiragana = GetRandomHiragana(row::agyou_row, random);
		}
		else if (row == "2") {
			hiragana = GetRandomHiragana(row::kagyou_row, random);
		} 
		else if (row == "3") {
			hiragana = GetRandomHiragana(row::sagyou_row, random);
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
			if (row == "1") sound = agyouSound[random];
			if (row == "2") sound = kagyouSound[random];
			if (row == "3") sound = sagyouSound[random];

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

	return character;
}