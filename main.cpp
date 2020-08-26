#include "menu.h"

const string FILE_NAME = "flights.txt";

int main() {
	Menu menu;
    menu.load_data(FILE_NAME);

	return 0;
}
