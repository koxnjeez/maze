// enumeration - перечисление
enum Derections { LEFT = 75, RIGHT = 77, DOWN = 80, UP = 72 };
enum colors { BLACK = 0, GRAY = 8, YELLOW = 14, RED = 12, PINK = 13, GREEN = 2, PURPLE = 5 };
enum elems { HALL = 0, WALL = 1, COIN = 2, ENEMY = 3, MEDICINE_KIT = 4 };

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //уникальный номер окна консоли (дескриптор)

void SetCursor(int x, int y, int color, string text)
{
    COORD position;
    position.X = x; // настройка координат
    position.Y = y;
    SetConsoleCursorPosition(h, position); // установка курсора в координату
	SetConsoleTextAttribute(h, color); // установка цвета
	cout << text; // вывод строки текста
}

void SetCursorChar(int x, int y, int color, char text)
{
    COORD position;
    position.X = x; // настройка координат
    position.Y = y;
    SetConsoleCursorPosition(h, position); // установка курсора в координату
	SetConsoleTextAttribute(h, color); // установка цвета
	cout << text; // вывод строки текста
}

void HideCursor(bool vision, int size) {
	// скрываем мигающий курсор в консоли
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 100;
	SetConsoleCursorInfo(h, &info);
}

void PEndProgram() {
	system("cls");
	SetCursorChar(1, 0, GRAY, (char)201);
	for (int i = 2; i < 118; i++) {
		SetCursorChar(i, 0, GRAY, (char)205);
	}
	SetCursorChar(118, 0, GRAY, (char)187);
	for (int i = 1; i < 29; i++) {
		SetCursorChar(118, i, GRAY, (char)186);
	}
	SetCursorChar(118, 29, GRAY, (char)188);
	for (int i = 2; i < 118; i++) {
		SetCursorChar(i, 29, GRAY, (char)205);
	}
	SetCursorChar(1, 29, GRAY, (char)200);
	for (int i = 1; i < 29; i++) {
		SetCursorChar(1, i, GRAY, (char)186);
	}
	SetCursor(55, 14, RED, "The end...");
	Sleep(INFINITE); // пауза до того момента пока пользователь не закроет программу
}

void PStartProgram() {
	system("cls");
	SetCursorChar(1, 0, GRAY, (char)201);
	for (int i = 2; i < 118; i++) {
		SetCursorChar(i, 0, GRAY, (char)205);
	}
	SetCursorChar(118, 0, GRAY, (char)187);
	for (int i = 1; i < 29; i++) {
		SetCursorChar(118, i, GRAY, (char)186);
	}
	SetCursorChar(118, 29, GRAY, (char)188);
	for (int i = 2; i < 118; i++) {
		SetCursorChar(i, 29, GRAY, (char)205);
	}
	SetCursorChar(1, 29, GRAY, (char)200);
	for (int i = 1; i < 29; i++) {
		SetCursorChar(1, i, GRAY, (char)186);
	}
	SetCursor(55, 14, GREEN, "You win!!!");
	Sleep(INFINITE); // пауза до того момента пока пользователь не закроет программу
}

void EndProgram(bool fail) {
	system("cls"); // очистка экрана
	if (fail == false) {

		PStartProgram(); // main() - перезапуск приложения
	}
	else {
		PEndProgram();
	}
	Sleep(INFINITE); // пауза до того момента пока пользователь не закроет программу
}

void dyn_walls(int x, int y, int width, int height, int** arr, int elem) {
	if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
		arr[y][x] = elem;
	}
}

void walls(int x, int y, int width, int height, int arr[][60], int elem) {
	if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
		arr[y][x] = elem;
	}
}

void dyn_entry_exit(int x, int y, int width, int height, int** arr, int elem) {
	if (x == 0 && y == 2 || x == 1 && y == 2 || x == 2 && y == 2 || x == width - 1 && y == height - 3 || x == width - 2 && y == height - 3 || x == width - 3 && y == height - 3) {
		arr[y][x] = elem;
	}
}

void entry_exit(int x, int y, int width, int height, int arr[][60], int elem) {
	if (x == 0 && y == 2 || x == 1 && y == 2 || x == 2 && y == 2 || x == width - 1 && y == height - 3 || x == width - 2 && y == height - 3 || x == width - 3 && y == height - 3) {
		arr[y][x] = elem;
	}
}

void dyn_check(int x, int y, int** arr, int item, int elem, int probability) {
	if (arr[y][x] == item) {
		int r;
		r = rand() % probability;
		if (r != 0)
		{
			arr[y][x] = elem;
		}
	}
}

void check(int x, int y, int arr[][60], int item, int elem, int probability) {
	if (arr[y][x] == item) {
		int r;
		r = rand() % probability;
		if (r != 0)
		{
			arr[y][x] = elem;
		}
	}
}

void main_menu(bool& dyn, bool& stat) {
	SetCursor(52, 12, 2, "Classic size");
	SetCursor(52, 14, 13, "Custom size");
	SetCursor(49, 12, 8, "->");
	SetCursor(65, 12, 8, "<-");
	int pos = 0;
	SetCursorChar(1, 0, GRAY, (char)201);
	for (int i = 2; i < 118; i++) {
		SetCursorChar(i, 0, GRAY, (char)205);
	}
	SetCursorChar(118, 0, GRAY, (char)187);
	for (int i = 1; i < 29; i++) {
		SetCursorChar(118, i, GRAY, (char)186);
	}
	SetCursorChar(118, 29, GRAY, (char)188);
	for (int i = 2; i < 118; i++) {
		SetCursorChar(i, 29, GRAY, (char)205);
	}
	SetCursorChar(1, 29, GRAY, (char)200);
	for (int i = 1; i < 29; i++) {
		SetCursorChar(1, i, GRAY, (char)186);
	}
	while (true) {
		int change = _getch();
		if (change == 224) {
			change = _getch();
		}
		if (change == 80 && pos == 0) {
			SetCursor(49, 12, 8, "  ");
			SetCursor(65, 12, 8, "  ");
			SetCursor(49, 14, 8, "->");
			SetCursor(64, 14, 8, "<-");
			pos = 1;
		}
		else if (change == 72 && pos == 1) {
			SetCursor(49, 14, 8, "  ");
			SetCursor(64, 14, 8, "  ");
			SetCursor(49, 12, 8, "->");
			SetCursor(65, 12, 8, "<-");
			pos = 0;
		}
		else if (change == 13) {
			if (pos) {
				dyn = true;
			}
			else {
				stat = true;
			}
			system("cls");
			break;
		}
	}
}

#pragma comment(lib, "winmm.lib")
DWORD WINAPI HitSound(void* param)
{
	PlaySoundA("C:\\Users\\User\\Desktop\\Code\\cw\\sounds\\minecraft_hit_sound.wav", NULL, SND_NODEFAULT | SND_LOOP); // в "" путь к музыке
	return 0;
}

DWORD WINAPI DeathSound(void* param)
{
	PlaySoundA("C:\\Users\\User\\Desktop\\Code\\cw\\sounds\\minecraft_death.wav", NULL, SND_NODEFAULT | SND_LOOP); // в "" путь к музыке
	return 0;
}

DWORD WINAPI PickCoinSound(void* param)
{
	PlaySoundA("C:\\Users\\User\\Desktop\\Code\\cw\\sounds\\minecraft_pick_u.wav", NULL, SND_NODEFAULT | SND_LOOP); // в "" путь к музыке
	return 0;
}

DWORD WINAPI UseKitSound(void* param)
{
	PlaySoundA("C:\\Users\\User\\Desktop\\Code\\cw\\sounds\\medshot4.wav", NULL, SND_NODEFAULT | SND_LOOP); // в "" путь к музыке
	return 0;
}

void StaticMaze() {
	system("title Maze"); // меняем название файла в консоли
	HideCursor(false, 100); // скрываем мигающий курсор в консоли
	srand(time(0));

	const int width = 60, height = 20;
	int maze[height][width] = {};

	// коридоры - 0     стены - 1     монетки - 2     враги - 3     аптечки - 4

	///////////////////////////////////////////////////////////////////////
	// установка лабиринта

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			maze[y][x] = rand() % 5;

			walls(x, y, width, height, maze, WALL); // установка стен

			entry_exit(x, y, width, height, maze, HALL); // определение точки входа и выхода

			check(x, y, maze, ENEMY, HALL, 10); // уменьшение вероятности появления врага (10%)

			check(x, y, maze, MEDICINE_KIT, HALL, 20); // уменьшение вероятности появления автечки (5%)

			if (maze[y][x] == HALL) {
				SetCursor(x, y, BLACK, " ");
			}
			else if (maze[y][x] == WALL) {
				SetCursorChar(x, y, GRAY, (char)177);
			}
			else if (maze[y][x] == COIN) {
				SetCursor(x, y, YELLOW, "*");
			}
			else if (maze[y][x] == ENEMY) {
				SetCursorChar(x, y, RED, (char)1);
			}
			else if (maze[y][x] == MEDICINE_KIT) {
				SetCursor(x, y, GREEN, "+");
			}
			else {
				cout << maze[y][x];
			}
		}
		cout << endl;
	}

	///////////////////////////////////////////////////////////////////////
	// управление персонажем

	// установка курсора в любую координату консоли
	COORD position;
	position.X = 0;
	position.Y = 2;
	SetCursorChar(0, 2, PINK, (char)1);

	int coins = 0; // количество подобраных монет
	int health = 100; // здоровье
	bool lose = false; // индикатор проигрыша
	bool write = false; // показатель прошлого шага (нужно ли вернуть аптечку или нет)

	while (true) {
		if (_kbhit()) {
			///////////////////////////////////////////////////////////////////////
			// условие перезапуска

			COORD reset_info;
			reset_info.X = width + 1;
			reset_info.Y = 7;
			SetCursor(reset_info.X, reset_info.Y, YELLOW, "RESET GAME - \"R\"");

			///////////////////////////////////////////////////////////////////////
			// условие выхода 

			COORD exit_info;
			exit_info.X = width + 1;
			exit_info.Y = 5;
			SetCursor(exit_info.X, exit_info.Y, YELLOW, "STOP GAME - \"P\"");

			///////////////////////////////////////////////////////////////////////
			// показатель здоровья

			COORD health_info;
			health_info.X = width + 1;
			health_info.Y = 3;
			SetCursor(health_info.X, health_info.Y, YELLOW, "HEALTH - ");
			cout << health << "%";

			///////////////////////////////////////////////////////////////////////
			// передвижение

			int code = _getch(); // get character - получение кода нажатой клавиши
			if (code == 224) // если была нажата стрелочка
			{
				code = _getch();
			}
			else if (code == 112) // если пользователь захотел завершить программу
			{
				PEndProgram();
			}
			else if (code == 114) // если пользователь захотел перезапустить программу
			{
				system("cls");
				StaticMaze();
			}

			SetCursor(position.X, position.Y, BLACK, " ");

			COORD kit_pos; // создание пустых координат аптечки
			kit_pos.X = 0;
			kit_pos.Y = 0;
			if (write) // 2 этап процесса возврата аптечки
			{
				kit_pos.X = position.X; // записывание координат аптечки (до шага)
				kit_pos.Y = position.Y;
				write = false; // обнуление переменной после записи координат
			}

			if (code == RIGHT && maze[position.Y][position.X + 1] != WALL) {
				position.X++; // смещение вправо
			}
			else if (code == LEFT && maze[position.Y][position.X - 1] != WALL) {
				position.X--; // смещение влево
			}
			else if (code == UP && maze[position.Y - 1][position.X] != WALL) {
				position.Y--; // смещение вверх
			}
			else if (code == DOWN && maze[position.Y + 1][position.X] != WALL) {
				position.Y++; // смещение вниз
			}

			if (kit_pos.X > 0) // если доступны координаты аптечки, возвращаем ее на место (3 этап процесса возврата аптечки)
			{
				SetCursor(kit_pos.X, kit_pos.Y, GREEN, "+");
			}

			if (maze[position.Y][position.X] == ENEMY) // проверка наличия врага
			{
				health -= 25;
				if (health != 0) {
					CreateThread(0, 0, HitSound, 0, 0, 0);
				}
				maze[position.Y][position.X] = HALL;
				health_info.X += 12;
				SetCursor(health_info.X, health_info.Y, YELLOW, " ");
				if (health == 0) {
					CreateThread(0, 0, DeathSound, 0, 0, 0);
					lose = true;
					MessageBoxA(0, "Закончилось здоровье!", "Поражение :(", MB_OK);
					PEndProgram();
				}
			}

			if (maze[position.Y][position.X] == MEDICINE_KIT && health != 100) // использование аптечки
			{
				health += 25;
				CreateThread(0, 0, UseKitSound, 0, 0, 0);
				maze[position.Y][position.X] = HALL;
			}
			else if (maze[position.Y][position.X] == MEDICINE_KIT && health == 100) // 1 этап процесса возврата аптечки
			{
				write = true;
			}

			SetCursorChar(position.X, position.Y, PINK, (char)1);

			///////////////////////////////////////////////////////////////////////
			// проверка на выход из лабиринта

			if (position.X == width - 1 && position.Y == height - 3) {
				MessageBoxA(0, "Найден выход из лабиринта!", "ПОБЕДА!", MB_OK);
				break;
			}

			///////////////////////////////////////////////////////////////////////
			// проверка на подбор монетки

			if (maze[position.Y][position.X] == COIN) {
				coins++;
				CreateThread(0, 0, PickCoinSound, 0, 0, 0);
				maze[position.Y][position.X] = HALL;
				SetCursor(width + 1, 1, YELLOW, "COINS - ");
				SetCursor(width + 9, 1, YELLOW, to_string(coins));
			}
		}
		else {
			Sleep(20);
			COORD enemy_pos[100];
			int enemy_count = 0;

			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{

					if (maze[y][x] == ENEMY)
					{
						enemy_pos[enemy_count].X = x;
						enemy_pos[enemy_count].Y = y;
						enemy_count++;
					}
				}
			}
			//ПЕРЕДВИЖЕНИЕ ВРАГОВ
			for (int i = 0; i < enemy_count; i++)
			{
				int r = rand() % 100;
				if (r == LEFT &&
					maze[enemy_pos[i].Y][enemy_pos[i].X - 1] != WALL &&
					maze[enemy_pos[i].Y][enemy_pos[i].X - 1] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;


					temp.X = enemy_pos[i].X - 1;
					temp.Y = enemy_pos[i].Y;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y][enemy_pos[i].X - 1] = ENEMY;
				}
				else if (r == RIGHT &&
					maze[enemy_pos[i].Y][enemy_pos[i].X + 1] != WALL &&
					maze[enemy_pos[i].Y][enemy_pos[i].X + 1] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;


					temp.X = enemy_pos[i].X + 1;
					temp.Y = enemy_pos[i].Y;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y][enemy_pos[i].X + 1] = ENEMY;
				}
				else if (r == UP &&
					maze[enemy_pos[i].Y - 1][enemy_pos[i].X] != WALL &&
					maze[enemy_pos[i].Y - 1][enemy_pos[i].X] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;


					temp.X = enemy_pos[i].X;
					temp.Y = enemy_pos[i].Y - 1;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y - 1][enemy_pos[i].X] = ENEMY;
				}
				else if (r == DOWN &&
					maze[enemy_pos[i].Y + 1][enemy_pos[i].X] != WALL &&
					maze[enemy_pos[i].Y + 1][enemy_pos[i].X] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;

					temp.X = enemy_pos[i].X;
					temp.Y = enemy_pos[i].Y + 1;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y + 1][enemy_pos[i].X] = ENEMY;
				}
			}
		}
	}

	for (int y = 0; y < height; y++) {
		delete[] maze[y];
	}
	delete[] maze;
	
	EndProgram(lose);
}

void DynamicMaze() {
	system("title Maze"); // меняем название файла в консоли
	HideCursor(false, 100); // скрываем мигающий курсор в консоли
	srand(time(0));

	unsigned int width;
	unsigned int height;
	SetCursor(2, 1, YELLOW, "Please, enter amount of columns: ");
	cin >> width;
	SetCursor(2, 3, YELLOW, "Please, enter amount of rows: ");
	cin >> height;

	int** maze = new int* [width];
	for (int y = 0; y < width; y++) {
		maze[y] = new int[height];
	}

	system("cls");

	// коридоры - 0     стены - 1     монетки - 2     враги - 3     аптечки - 4

	///////////////////////////////////////////////////////////////////////
	// установка лабиринта

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			maze[y][x] = rand() % 5;

			dyn_walls(x, y, width, height, maze, WALL); // установка стен

			dyn_entry_exit(x, y, width, height, maze, HALL); // определение точки входа и выхода

			dyn_check(x, y, maze, ENEMY, HALL, 10); // уменьшение вероятности появления врага (10%)

			dyn_check(x, y, maze, MEDICINE_KIT, HALL, 20); // уменьшение вероятности появления автечки (5%)

			if (maze[y][x] == HALL) {
				SetCursor(x, y, BLACK, " ");
			}
			else if (maze[y][x] == WALL) {
				SetCursorChar(x, y, GRAY, (char)177);
			}
			else if (maze[y][x] == COIN) {
				SetCursor(x, y, YELLOW, "*");
			}
			else if (maze[y][x] == ENEMY) {
				SetCursorChar(x, y, RED, (char)1);
			}
			else if (maze[y][x] == MEDICINE_KIT) {
				SetCursor(x, y, GREEN, "+");
			}
			else {
				cout << maze[y][x];
			}
		}
		cout << endl;
	}

	///////////////////////////////////////////////////////////////////////
	// управление персонажем

	// установка курсора в любую координату консоли
	COORD position;
	position.X = 0;
	position.Y = 2;
	SetCursorChar(0, 2, PINK, (char)1);

	int coins = 0; // количество подобраных монет
	int health = 100; // здоровье
	bool lose = false; // индикатор проигрыша
	bool write = false; // показатель прошлого шага (нужно ли вернуть аптечку или нет)

	while (true) {
		if (_kbhit()) {
			///////////////////////////////////////////////////////////////////////
			// условие перезапуска

			COORD reset_info;
			reset_info.X = width + 1;
			reset_info.Y = 7;
			SetCursor(reset_info.X, reset_info.Y, YELLOW, "RESET GAME - \"R\"");

			///////////////////////////////////////////////////////////////////////
			// условие выхода 

			COORD exit_info;
			exit_info.X = width + 1;
			exit_info.Y = 5;
			SetCursor(exit_info.X, exit_info.Y, YELLOW, "STOP GAME - \"P\"");

			///////////////////////////////////////////////////////////////////////
			// показатель здоровья

			COORD health_info;
			health_info.X = width + 1;
			health_info.Y = 3;
			SetCursor(health_info.X, health_info.Y, YELLOW, "HEALTH - ");
			cout << health << "%";

			///////////////////////////////////////////////////////////////////////
			// передвижение

			int code = _getch(); // get character - получение кода нажатой клавиши
			if (code == 224) // если была нажата стрелочка
			{
				code = _getch();
			}
			else if (code == 112) // если пользователь захотел завершить программу
			{
				PEndProgram();
			}
			else if (code == 114) // если пользователь захотел перезапустить программу
			{
				system("cls");
				DynamicMaze();
			}

			SetCursor(position.X, position.Y, BLACK, " ");

			COORD kit_pos; // создание пустых координат аптечки
			kit_pos.X = 0;
			kit_pos.Y = 0;
			if (write) // 2 этап процесса возврата аптечки
			{
				kit_pos.X = position.X; // записывание координат аптечки (до шага)
				kit_pos.Y = position.Y;
				write = false; // обнуление переменной после записи координат
			}

			if (code == RIGHT && maze[position.Y][position.X + 1] != WALL) {
				position.X++; // смещение вправо
			}
			else if (code == LEFT && maze[position.Y][position.X - 1] != WALL) {
				position.X--; // смещение влево
			}
			else if (code == UP && maze[position.Y - 1][position.X] != WALL) {
				position.Y--; // смещение вверх
			}
			else if (code == DOWN && maze[position.Y + 1][position.X] != WALL) {
				position.Y++; // смещение вниз
			}

			if (kit_pos.X > 0) // если доступны координаты аптечки, возвращаем ее на место (3 этап процесса возврата аптечки)
			{
				SetCursor(kit_pos.X, kit_pos.Y, GREEN, "+");
			}

			if (maze[position.Y][position.X] == ENEMY) // проверка наличия врага
			{
				health -= 25;
				if (health != 0) {
					CreateThread(0, 0, HitSound, 0, 0, 0);
				}
				maze[position.Y][position.X] = HALL;
				health_info.X += 12;
				SetCursor(health_info.X, health_info.Y, YELLOW, " ");
				if (health == 0) {
					CreateThread(0, 0, DeathSound, 0, 0, 0);
					lose = true;
					MessageBoxA(0, "Закончилось здоровье!", "Поражение :(", MB_OK);
					PEndProgram();
				}
			}

			if (maze[position.Y][position.X] == MEDICINE_KIT && health != 100) // использование аптечки
			{
				health += 25;
				CreateThread(0, 0, UseKitSound, 0, 0, 0);
				maze[position.Y][position.X] = HALL;
			}
			else if (maze[position.Y][position.X] == MEDICINE_KIT && health == 100) // 1 этап процесса возврата аптечки
			{
				write = true;
			}

			SetCursorChar(position.X, position.Y, PINK, (char)1);

			///////////////////////////////////////////////////////////////////////
			// проверка на выход из лабиринта

			if (position.X == width - 1 && position.Y == height - 3) {
				MessageBoxA(0, "Найден выход из лабиринта!", "ПОБЕДА!", MB_OK);
				break;
			}

			///////////////////////////////////////////////////////////////////////
			// проверка на подбор монетки

			if (maze[position.Y][position.X] == COIN) {
				coins++;
				CreateThread(0, 0, PickCoinSound, 0, 0, 0);
				maze[position.Y][position.X] = HALL;
				SetCursor(width + 1, 1, YELLOW, "COINS - ");
				SetCursor(width + 9, 1, YELLOW, to_string(coins));
			}
		}
		else {
			Sleep(20);
			COORD enemy_pos[100];
			int enemy_count = 0;

			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{

					if (maze[y][x] == ENEMY)
					{
						enemy_pos[enemy_count].X = x;
						enemy_pos[enemy_count].Y = y;
						enemy_count++;
					}
				}
			}
			//ПЕРЕДВИЖЕНИЕ ВРАГОВ
			for (int i = 0; i < enemy_count; i++)
			{
				int r = rand() % 100;
				if (r == LEFT &&
					maze[enemy_pos[i].Y][enemy_pos[i].X - 1] != WALL &&
					maze[enemy_pos[i].Y][enemy_pos[i].X - 1] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;


					temp.X = enemy_pos[i].X - 1;
					temp.Y = enemy_pos[i].Y;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y][enemy_pos[i].X - 1] = ENEMY;
				}
				else if (r == RIGHT &&
					maze[enemy_pos[i].Y][enemy_pos[i].X + 1] != WALL &&
					maze[enemy_pos[i].Y][enemy_pos[i].X + 1] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;


					temp.X = enemy_pos[i].X + 1;
					temp.Y = enemy_pos[i].Y;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y][enemy_pos[i].X + 1] = ENEMY;
				}
				else if (r == UP &&
					maze[enemy_pos[i].Y - 1][enemy_pos[i].X] != WALL &&
					maze[enemy_pos[i].Y - 1][enemy_pos[i].X] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;


					temp.X = enemy_pos[i].X;
					temp.Y = enemy_pos[i].Y - 1;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y - 1][enemy_pos[i].X] = ENEMY;
				}
				else if (r == DOWN &&
					maze[enemy_pos[i].Y + 1][enemy_pos[i].X] != WALL &&
					maze[enemy_pos[i].Y + 1][enemy_pos[i].X] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;

					temp.X = enemy_pos[i].X;
					temp.Y = enemy_pos[i].Y + 1;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y + 1][enemy_pos[i].X] = ENEMY;
				}
			}
		}
	}

	for (int y = 0; y < height; y++) {
		delete[] maze[y];
	}
	delete[] maze;

	EndProgram(lose);
}