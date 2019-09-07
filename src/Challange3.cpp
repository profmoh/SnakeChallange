//#include <iostream>
//#include <conio.h>
//#include <windows.h>
//#include <direct.h>
//#include <time.h>
//
//using namespace std;
//
//HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//COORD cursorPosition;
//
//void gotoxy(int x, int y) {
//	cursorPosition.X = x;
//	cursorPosition.Y = y;
//
//	SetConsoleCursorPosition(console, cursorPosition);
//}
//
//class Drawable {
//private:
//	int x;
//	int y;
//public:
//	Drawable(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
//
//	virtual ~Drawable() {
//	}
//
//	virtual void draw() = 0;
//
//	int getX() const {
//		return this->x;
//	}
//
//	void setX(int x) {
//		this->x = x;
//	}
//
//	int getY() const {
//		return this->y;
//	}
//
//	void setY(int y) {
//		this->y = y;
//	}
//
//	void moveUp() {
//		this->y--;
//	}
//
//	void moveDown() {
//		this->y++;
//	}
//
//	void moveLeft() {
//		this->x--;
//	}
//
//	void moveRight() {
//		this->x++;
//	}
//
//	void erase() {
//		gotoxy(x, y);
//		cout << " ";
//	}
//
//	void copyPos(Drawable &d) {
//		d.setX(this->getX());
//		d.setY(this->getY());
//	}
//};
//
//class Fruit: public Drawable {
//public:
//	Fruit() :
//			Drawable(0, 0) {
//	}
//
//	Fruit(int x, int y) :
//			Drawable(x, y) {
//	}
//
//	~Fruit() {
//	}
//
//	void draw() {
//		gotoxy(this->getX(), this->getY());
//		cout << "$";
//	}
//};
//
//class SnakePart: public Drawable {
//public:
//	SnakePart() :
//			Drawable(0, 0) {
//	}
//
//	SnakePart(int x, int y) :
//			Drawable(x, y) {
//	}
//
//	~SnakePart() {
//	}
//
//	void draw() final {
//		gotoxy(this->getX(), this->getY());
//		cout << "*";
//	}
//};
//
//class Snake {
//private:
//	const int MAX_SNAKE_SIZE = 25;
//
//	int initX = 5;
//	int initY = 10;
//
//	char dir = 'l';
//
//	int currentSnakeSize = 0;
//
//	SnakePart snakePartArr[25];
//
//	void initSnake() {
////		for (int i = 0; i < MAX_SNAKE_SIZE; i++) {
////			snakePartArr[i] ;
////		}
//		SnakePart head = SnakePart(initX, initY);
//
//		addPart(head);
//
//		SnakePart body1 = SnakePart(initX + 1, initY);
//		SnakePart body2 = SnakePart(initX + 2, initY);
//
//		addPart(body1);
//		addPart(body2);
//	}
//
//	void addPart(SnakePart part) {
//		snakePartArr[currentSnakeSize++] = part;
//	}
//
//public:
//	Snake() {
//		initSnake();
//	}
//
//	~Snake() {
//	}
//
//	void TurnUp() {
//		dir = 'u'; // w is control key for turning up
//	}
//
//	void TurnDown() {
//		dir = 'd'; // s is control key for turning down
//	}
//
//	void TurnLeft() {
//		dir = 'l'; // s is control key for turning left
//	}
//
//	void TurnRight() {
//		dir = 'r'; // d is control key for turning right
//	}
//
//	SnakePart getHead() {
//		return snakePartArr[0];
//	}
//
//	void addPart() {
//		SnakePart part = SnakePart(0, 0);
//		addPart(part);
//	}
//
//	void Move() {
//		// making snake body follow its head
//		for (int i = currentSnakeSize - 1; i > 0; i--) {
//			snakePartArr[i - 1].copyPos(snakePartArr[i]);
//		}
//
//		// turning snake's head
//		switch (dir) {
//		case 'u':
//			snakePartArr[0].moveUp();
//			break;
//		case 'd':
//			snakePartArr[0].moveDown();
//			break;
//		case 'l':
//			snakePartArr[0].moveLeft();
//			break;
//		case 'r':
//			snakePartArr[0].moveRight();
//			break;
//		}
//
//		draw();
//	}
//
//	void draw() {
//		for (int i = 0; i < currentSnakeSize; i++) {
//			snakePartArr[i].draw();
//		}
//	}
//};
//
//class SnakeGame {
//private:
//	Snake snake = Snake();
//	Fruit fruit = Fruit();
//
//	void resetFruit() {
//		fruit.setX(rand() % 50);
//		fruit.setY(rand() % 25);
//	}
//
//public:
//	SnakeGame() {
//		resetFruit();
//	}
//
//	void Start() {
//		char op = 'l';
//
//		do {
//			system("cls");
//
//			if (kbhit()) {
//				op = getch();
//			}
//
//			switch (op) {
//			case 'w':
//			case 'W':
//				snake.TurnUp();
//				break;
//			case 's':
//			case 'S':
//				snake.TurnDown();
//				break;
//			case 'a':
//			case 'A':
//				snake.TurnLeft();
//				break;
//			case 'd':
//			case 'D':
//				snake.TurnRight();
//				break;
//			}
//
//			snake.Move();
//
//			SnakePart head = snake.getHead();
//			gotoxy(0,0);
//			cout << head.getX();
//			gotoxy(0,10);
//cout << head.getY();
//			if (fruit.getX() == head.getX() && fruit.getY() == head.getY()) {
//				snake.addPart();
//
//				resetFruit();
//			}
//
//			fruit.draw();
//
//			Sleep(50);
//		} while (op != 'e');
//
//	}
//};
//
//int main() {
//	srand((unsigned) time(NULL));
//
//	SnakeGame game = SnakeGame();
//
//	game.Start();
//
//	return 0;
//}
