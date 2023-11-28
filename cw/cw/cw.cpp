#include "settings.h"
#include "fuctions.h"

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //уникальный номер окна консоли (дескриптор)
	system("title Maze"); // меняем название файла в консоли

	HideCursor(false, 100); // скрываем мигающий курсор в консоли

	srand(time(0));

	// оформление главного меню
	bool dyn_size = false;
	bool stat_size = false;
	main_menu(dyn_size, stat_size);

	if (stat_size) {
		StaticMaze();
	}
	
	else {
		DynamicMaze();
	}
}