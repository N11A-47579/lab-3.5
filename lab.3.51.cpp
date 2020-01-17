#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

class Array {
private:
	int sizeArray, menuCountItem, sizeCreatedArray;
	char save[1];
	std::ofstream arraySaveFile;
	std::ifstream arrayOpenFile;
	std::string valueArrayFromFile;
public:
	int menuChoice;
	std::vector < int > tablica;
	Array() {
		tablica.clear();
		return;
	}
	Array(int size) {
		sizeArray = size;
		srand(time(NULL));
		for (int i = 0; i < sizeArray; i++) {
			tablica.push_back(rand() % 100);
		}
		return;
	}
	void menu() {
		do {
			system("cls");
			std::cout << "==========[MENU]==========" << std::endl;
			std::cout << "[1]	Generate array." << std::endl;
			std::cout << "[2]	Show array." << std::endl;
			std::cout << "[3]	Load form file." << std::endl;
			std::cout << "[4]	Sort array." << std::endl;
			std::cout << "[5]	Minimal value." << std::endl;
			std::cout << "[6]	Maximal value." << std::endl;
			std::cout << "[0]	Exit." << std::endl;
			std::cout << "==========[MENU]==========" << std::endl;
			std::cin >> menuChoice;
			if (std::cin.fail()) {
				system("cls");
				std::cin.clear();
				std::cin.ignore();
				menu();
			}
		} while (std::cin.fail());
		return;
	}
	void generate() {
		srand(time(NULL));
		system("cls");
		do {
			std::cout << "==========[GENEREATE ARRAY]=========" << std::endl;
			std::cout << "Size: ";
			std::cin >> sizeCreatedArray;
			if (std::cin.fail()) {
				system("cls");
				std::cin.clear();
				std::cin.ignore();
				generate();
			}
		} while (std::cin.fail() && sizeCreatedArray < 0);
		for (int i = 0; i < sizeCreatedArray; i++) {
			tablica.push_back(rand() % 100);
			std::cout << tablica[i] << " ";
			if (i == sizeCreatedArray - 1) {
				std::cout << std::endl;
			}
		}
		do {
			std::cout << "Do You want to save this array? y/n: ";
			std::cin >> save[0];
		} while (save[0] != 'y' && save[0] != 'n');
		if (save[0] == 'y') {
			saveArray();
		}
		else if (save[0] == 'n') {
			menu();
		}
		std::cout << "Genereted array size is [" << sizeCreatedArray << "]: ";
		
		return;
	}
	void printArray() {
		system("cls");
		std::cout << "==========[PRINT ARRAY]==========" << std::endl;
		if (!tablica.empty()) {
			for (int i = 0; i < tablica.size(); i++) {
				if (i < tablica.size() - 1)
					std::cout << tablica[i] << ", ";
				else
					std::cout << tablica[i];
			}
			std::cout << std::endl;
		}
		else {
			std::cout << "No array!" << std::endl;
		}
		
		system("pause");
	}
	void sort() {
		int sizeTemp = tablica.size();
		do {
			for (int i = 0; i < sizeTemp - 1; i++) {
				if (tablica[i] > tablica[i + 1]) {
					std::swap(tablica[i], tablica[i + 1]);
				}
			}
			sizeTemp = sizeTemp - 1;
		} while (sizeTemp > 1);
		return;
	}
	void saveArray() {

		arraySaveFile.open("array.txt");

		for (int i = 0; i < tablica.size(); i++) {
			arraySaveFile << tablica[i];
			if (i < sizeArray - 1) {
				arraySaveFile << "\n";
			}
		}
		arraySaveFile.close();
		std::cout << "Array saved successfully!" << std::endl;
		system("pause");
		system("CLS");
		return;
	}
	void loadArray() {
		system("cls");
		std::cout << "==========[LOAD ARRAY FROM FILE]=========" << std::endl;
		arrayOpenFile.open("array.txt", std::fstream::in | std::fstream::out | std::fstream::app);
		if (arrayOpenFile) {
			tablica.clear();
			while (getline(arrayOpenFile, valueArrayFromFile)) {
				int value = std::stoi(valueArrayFromFile);
				tablica.push_back(value);
			}
			arrayOpenFile.close();
			std::cout << "Loaded array: ";
			printArray();
			std::cout << std::endl;
		}
		else {
			std::cout << "NO FILLE!" << std::endl;
		}
		system("pause");
		return;
	}
	void maximumValue() {
		system("cls");
		std::cout << "==========[MAXIMAL VALUE]==========" << std::endl;
		if (!tablica.empty()) {
			int max = tablica[0];
			for (int i = 0; i < tablica.size(); i++) {
				if (max < tablica[i])
					max = tablica[i];
			}
			std::cout << "Max: " << max << std::endl;
		}
		else {
			std::cout << "No array!" << std::endl;
		}
		system("pause");
	}
	void minimumValue() {
		system("cls");
		std::cout << "==========[MINIMAL VALUE]==========" << std::endl;
		if (!tablica.empty()) {
			int min = tablica[0];
			for (int i = 0; i < tablica.size(); i++) {
				if (min > tablica[i])
					min = tablica[i];
			}
			std::cout << "Min: " << min << std::endl;
		}
		else {
			std::cout << "No array!" << std::endl;
		}
		system("pause");
	}
};

int main()
{
	system("Color 3F");
	Array arrayClass;
	
	do {
		arrayClass.menu();
		switch (arrayClass.menuChoice) {
			case 1: {
				arrayClass.generate();
				break;
			}
			case 2: {
				arrayClass.printArray();
				break;
			}
			case 3: {
				arrayClass.loadArray();
				break;
			}
			case 4: {
				arrayClass.sort();
				break;
			}
			case 5: {
				arrayClass.minimumValue();
				break;
			}
			case 6: {
				arrayClass.maximumValue();
				break;
			}
			case 0: {
				break;
			}
			default: {
				arrayClass.menu();
				break;
			}
		}
	} while (arrayClass.menuChoice != 0);
}
