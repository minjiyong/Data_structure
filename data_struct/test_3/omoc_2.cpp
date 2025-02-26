#include <iostream>
#include <fstream>

using namespace std;

#define x_max 20
#define y_max 20

class Omoc {
public:
	int x{};
	int y{};
	char shape{};
	Omoc* next = nullptr;

	Omoc() {
		shape = '+';
	};
	~Omoc() {};
};

Omoc* head = nullptr;
Omoc* return_head = nullptr;
char board[x_max][y_max]{};

int large(int& a, int& b) {
	if (a >= b) return a;
	else if (a < b) return b;
}

void insert_omoc(int x, int y, char shape) {
	Omoc* ptr = new Omoc;
	ptr->x = x;
	ptr->y = y;
	ptr->shape = shape;
	
	if (head == nullptr) {
		head = ptr;
	} 
	else {
		ptr->next = head;
		head = ptr;
	}
}

void return_omoc(int x, int y, char shape) {
	Omoc* ptr = new Omoc;
	ptr->x = x;
	ptr->y = y;
	ptr->shape = shape;

	if (return_head == nullptr) {
		return_head = ptr;
	}
	else {
		ptr->next = return_head;
		return_head = ptr;
	}
}

void Initialize() {
	for (int i = 0; i < y_max; ++i) {
		for (int j = 0; j < x_max; ++j) {
			board[i][j] = '+';
		}
	}
}

void print_board() {
	for (int i = 0; i < y_max; ++i) {
		for (int j = 0; j < x_max; ++j) {
			cout <<board[i][j] << " ";
		}
		cout << endl;
	}
}

void every_num() {
	int y_ocount[y_max] = {0};
	int x_ocount[x_max] = {0};
	int y_xcount[y_max] = {0};
	int x_xcount[x_max] = {0};

	for (int i = 0; i < y_max; ++i) {
		for (int j = 0; j < x_max; ++j) {
			if (board[i][j] == 'o') {
				y_ocount[i]++;
				x_ocount[j]++;
			}
			else if (board[i][j] == 'x') {
				y_xcount[i]++;
				x_xcount[j]++;
			}
		}
	}

	for (int i = 0; i < y_max; ++i) {
		cout << "가로" << i << "번째 줄 o " << y_ocount[i] << "개" << endl;
		cout << "가로" << i << "번째 줄 x " << y_xcount[i] << "개" << endl;
	}
	for (int i = 0; i < x_max; ++i) {
		cout << "세로" << i << "번째 줄 o " << x_ocount[i] << "개" << endl;
		cout << "세로" << i << "번째 줄 x " << x_xcount[i] << "개" << endl;
	}
}

void garos() {
	int omax = { 0 };					// 연속된 돌의 갯수가 가장 큰 값 'o'
	int xmax = { 0 };
	int os{ 0 };						// 연속된 돌의 갯수 'o'
	int xs{ 0 };

	int max_ox[x_max] = { NULL };		// 연속된 돌의 좌표값 'o'
	int max_oy[y_max] = { NULL };
	int ox_index{ 0 };
	int oy_index{ 0 };

	int max_xx[x_max] = { NULL };		// 연속된 돌의 좌표값 'x'
	int max_xy[y_max] = { NULL };
	int xx_index{ 0 };
	int xy_index{ 0 };

	for (int i = 0; i < y_max; ++i) {
		for (int j = 0; j < x_max; ++j) {
			if (board[i][j] == 'o' && board[i][j + 1] == 'o') {
				os++;
				max_ox[ox_index] = j;
				max_oy[oy_index] = i;
				ox_index++;
				oy_index++;
				if (board[i][j + 2] != 'o') {
					os++;
					max_ox[ox_index] = j + 1;
					max_oy[oy_index] = i;
					ox_index++;
					oy_index++;
					continue;
				}
			}
			else if (board[i][j] == 'x' && board[i][j + 1] == 'x') {
				xs++;
				max_xx[xx_index] = j;
				max_xy[xy_index] = i;
				xx_index++;
				xy_index++;
				if (board[i][j + 2] != 'x') {
					xs++;
					max_xx[xx_index] = j + 1;
					max_xy[xy_index] = i;
					xx_index++;
					xy_index++;
					continue;
				}
			}
		}
		if (omax < os) omax = os;
		else {
			ox_index = 0;
			oy_index = 0;
		}
		if (xmax < xs) xmax = xs;
		else {
			xx_index = 0;
			xy_index = 0;
		}

		if (omax == 0 && xmax == 0) continue;
		else if (omax == xmax) {
			cout << i << "번째 가로줄에서 가장 많이 연속으로 놓인 돌: o, " << omax << "개" << endl;
			for (int j = 0; j < x_max; ++j) {
				if (max_ox[j] != NULL) cout << "(" << max_ox[j] << ", " << max_oy[j] << ")";
			}
			cout << endl;
			cout << i << "번째 가로줄에서 가장 많이 연속으로 놓인 돌: x, " << xmax << "개" << endl;
			for (int j = 0; j < x_max; ++j) {
				if (max_xx[j] != NULL) cout << "(" << max_xx[j] << ", " << max_xy[j] << ")";
			}
			cout << endl;
		}
		else if (omax > xmax) {
			cout << i << "번째 가로줄에서 가장 많이 연속으로 놓인 돌: o, " << omax << "개" << endl;
			for (int j = 0; j < x_max; ++j) {
				if (max_ox[j] != NULL) cout << "(" << max_ox[j] << ", " << max_oy[j] << ")";
			}
			cout << endl;
		}
		else if (xmax > omax) {
			cout << i << "번째 가로줄에서 가장 많이 연속으로 놓인 돌: x, " << xmax << "개" << endl;
			for (int j = 0; j < x_max; ++j) {
				if (max_xx[j] != NULL) cout << "(" << max_xx[j] << ", " << max_xy[j] << ")";
			}
			cout << endl;
		}
		os = 0;
		xs = 0; 
		omax = 0;
		xmax = 0;
	}
}

void seros() {
	int omax = { 0 };
	int xmax = { 0 };
	int os{ 0 };
	int xs{ 0 };

	for (int i = 0; i < y_max; ++i) {
		for (int j = 0; j < x_max; ++j) {
			if (board[j][i] == 'o' && board[j + 1][i] == 'o') {
				os++;
				if (board[j + 2][i] != 'o') {
					os++;
					continue;
				}
			}
			else if (board[j][i] == 'x' && board[j + 1][i] == 'x') {
				xs++;
				if (board[j + 2][i] != 'x') {
					xs++;
					continue;
				}
			}
		}
		if (omax < os) omax = os;
		if (xmax < xs) xmax = xs;

		if (omax == 0 && xmax == 0) continue;
		else if (omax == xmax) {
			cout << i << "번째 세로줄에서 가장 많이 연속으로 놓인 돌: o, " << omax << "개" << endl;
			cout << i << "번째 세로줄에서 가장 많이 연속으로 놓인 돌: x, " << xmax << "개" << endl;
		}
		else if (omax > xmax) {
			cout << i << "번째 세로줄에서 가장 많이 연속으로 놓인 돌: o, " << omax << "개" << endl;
		}
		else if (xmax > omax) {
			cout << i << "번째 세로줄에서 가장 많이 연속으로 놓인 돌: x, " << xmax << "개" << endl;
		}
		os = 0;
		xs = 0;
		omax = 0;
		xmax = 0;
	}
}

void daegacs() {
	int omax = { 0 };
	int xmax = { 0 };
	int os{ 0 };
	int xs{ 0 };

	// x = 0 좌표로 시작하는 우하향 대각선
	for (int i = 0; i < x_max; ++i) {
		for (int j = 0; j < x_max - i; ++j) {
			if (board[i + j][j] == 'o' && board[i + j + 1][j + 1] == 'o') {
				os++;
				if (board[i + j + 2][j + 2] != 'o') {
					os++;
					continue;
				}
			}
			else if (board[i + j][j] == 'x' && board[i + j + 1][j + 1] == 'x') {
				xs++;
				if (board[i + j + 2][j + 2] != 'x') {
					xs++;
					continue;
				}
			}
		}
		if (omax < os) {
			omax = os;
		}
		if (xmax < xs) {
			xmax = xs;
		}

		if (omax == 0 && xmax == 0) continue;
		else if (omax == xmax) {
			cout << "(" << 0 << ", " << i << ") 에서 시작하는 우하향 대각선에서 가장 많이 연속으로 놓인 돌: o, " << omax << "개" << endl;
			cout << "(" << 0 << ", " << i << ") 에서 시작하는 우하향 대각선에서 가장 많이 연속으로 놓인 돌: x, " << xmax << "개" << endl;
		}
		else if (omax > xmax) {
			cout << "(" << 0 << ", " << i << ") 에서 시작하는 우하향 대각선에서 가장 많이 연속으로 놓인 돌: o, " << omax << "개" << endl;
		}
		else if (xmax > omax) {
			cout << "(" << 0 << ", " << i << ") 에서 시작하는 우하향 대각선에서 가장 많이 연속으로 놓인 돌: x, " << xmax << "개" << endl;
		}
		os = 0;
		xs = 0;
		omax = 0;
		xmax = 0;
	}

	// y = 0 좌표로 시작하는 우하향 대각선
	for (int i = 1; i < x_max; ++i) {
		for (int j = 0; j < x_max - i; ++j) {
			if (board[j][i + j] == 'o' && board[j + 1][i + j + 1] == 'o') {
				os++;
				if (board[j + 2][i + j + 2] != 'o') {
					os++;
					continue;
				}
			}
			else if (board[j][i + j] == 'x' && board[j + 1][i + j + 1] == 'x') {
				xs++;
				if (board[j + 2][i + j + 2] != 'x') {
					xs++;
					continue;
				}
			}
		}
		if (omax < os) {
			omax = os;
		}
		if (xmax < xs) {
			xmax = xs;
		}

		if (omax == 0 && xmax == 0) continue;
		else if (omax == xmax) {
			cout << "(" << i << ", " << 0 << ") 에서 시작하는 우하향 대각선에서 가장 많이 연속으로 놓인 돌: o, " << omax << "개" << endl;
			cout << "(" << i << ", " << 0 << ") 에서 시작하는 우하향 대각선에서 가장 많이 연속으로 놓인 돌: x, " << xmax << "개" << endl;
		}
		else if (omax > xmax) {
			cout << "(" << i << ", " << 0 << ") 에서 시작하는 우하향 대각선에서 가장 많이 연속으로 놓인 돌: o, " << omax << "개" << endl;
		}
		else if (xmax > omax) {
			cout << "(" << i << ", " << 0 << ") 에서 시작하는 우하향 대각선에서 가장 많이 연속으로 놓인 돌: x, " << xmax << "개" << endl;
		}
		os = 0;
		xs = 0;
		omax = 0;
		xmax = 0;
	}

	// y = 0 좌표로 시작하는 좌하향 대각선
	for (int i = 0; i < x_max; ++i) {
		for (int j = 0; j < x_max - i; ++j) {
			if (board[j][i + j] == 'o' && board[j - 1][i + j + 1] == 'o') {
				os++;
				if (board[j - 2][i + j + 2] != 'o') {
					os++;
					continue;
				}
			}
			else if (board[j][i + j] == 'x' && board[j - 1][i + j + 1] == 'x') {
				xs++;
				if (board[j - 2][i + j + 2] != 'x') {
					xs++;
					continue;
				}
			}
		}
		if (omax < os) {
			omax = os;
		}
		if (xmax < xs) {
			xmax = xs;
		}

		if (omax == 0 && xmax == 0) continue;
		else if (omax == xmax) {
			cout << "(" << i << ", " << 0 << ") 에서 시작하는 좌하향 대각선에서 가장 많이 연속으로 놓인 돌: o, " << omax << "개" << endl;
			cout << "(" << i << ", " << 0 << ") 에서 시작하는 좌하향 대각선에서 가장 많이 연속으로 놓인 돌: x, " << xmax << "개" << endl;
		}
		else if (omax > xmax) {
			cout << "(" << i << ", " << 0 << ") 에서 시작하는 좌하향 대각선에서 가장 많이 연속으로 놓인 돌: o, " << omax << "개" << endl;
		}
		else if (xmax > omax) {
			cout << "(" << i << ", " << 0 << ") 에서 시작하는 좌하향 대각선에서 가장 많이 연속으로 놓인 돌: x, " << xmax << "개" << endl;
		}
		os = 0;
		xs = 0;
		omax = 0;
		xmax = 0;
	}

	// x = 19 좌표로 시작하는 좌하향 대각선
	for (int i = 1; i < y_max; ++i) {
		for (int j = 19; j > 0 + i; --j) {
			if (board[i + j][j] == 'o' && board[i + j + 1][j - 1] == 'o') {
				os++;
				if (board[i + j + 2][j - 2] != 'o') {
					os++;
					continue;
				}
			}
			else if (board[i + j][j] == 'x' && board[i + j + 1][j - 1] == 'x') {
				xs++;
				if (board[i + j + 2][j - 2] != 'x') {
					xs++;
					continue;
				}
			}
		}
		if (omax < os) {
			omax = os;
		}
		if (xmax < xs) {
			xmax = xs;
		}

		if (omax == 0 && xmax == 0) continue;
		else if (omax == xmax) {
			cout << "(" << 19 << ", " << i << ") 에서 시작하는 좌하향 대각선에서 가장 많이 연속으로 놓인 돌: o, " << omax << "개" << endl;
			cout << "(" << 19 << ", " << i << ") 에서 시작하는 좌하향 대각선에서 가장 많이 연속으로 놓인 돌: x, " << xmax << "개" << endl;
		}
		else if (omax > xmax) {
			cout << "(" << 19 << ", " << i << ") 에서 시작하는 좌하향 대각선에서 가장 많이 연속으로 놓인 돌: o, " << omax << "개" << endl;
		}
		else if (xmax > omax) {
			cout << "(" << 19 << ", " << i << ") 에서 시작하는 좌하향 대각선에서 가장 많이 연속으로 놓인 돌: x, " << xmax << "개" << endl;
		}
		os = 0;
		xs = 0;
		omax = 0;
		xmax = 0;
	}
}

void OutFile() {
	ofstream File("Omoc.txt");
	if (File.is_open()) {
		for (int i = 0; i < y_max; ++i) {
			for (int j = 0; j < x_max; ++j) {
				File << board[i][j] << " ";
			}
			File << endl;
		}
	}
	File.close();
}

void InFile() {
	ifstream File("Omoc.txt");
	if (File.is_open()) {
		for (int i = 0; i < y_max; ++i) {
			for (int j = 0; j < x_max; ++j) {
				File >> board[i][j];
			}
		}
	}
	File.close();
}

int main()
{
	int turn{ 1 };
	Initialize();

	int input_x{};
	int input_y{};

	int input_menu{};

	while (true) {
		print_board();
		cout << "메뉴: 1.돌 놓기, 2.파일 불러오기, 3.파일 저장하기, 4.무르기, 5.무르기 취소: ";
		cin >> input_menu;
		if (cin.fail()) {
			cout << "올바른 입력이 아닙니다. 다시 입력해주세요" << endl;
			cin.clear();
			cin.ignore();
		}

		else if (input_menu == 1) {
			cout << "돌을 놓을 위치를 입력해주세요(가로 0~19, 세로 0~19): ";
			cin >> input_x >> input_y;
			system("cls");
			if (!cin.fail()) {
				if (input_x > 19 || input_x < 0 || input_y > 19 || input_y < 0) {
					cout << "올바른 입력이 아닙니다. 다시 입력해주세요" << endl;
					cin.clear();
					cin.ignore();
					continue;
				}
				if (board[input_y][input_x] == '+') {
					if (turn % 2 == 1) {
						insert_omoc(input_x, input_y, 'o');
						board[input_y][input_x] = 'o';
					}
					else if (turn % 2 == 0) {
						insert_omoc(input_x, input_y, 'x');
						board[input_y][input_x] = 'x';
					}
					++turn;

					
				}
				else {
					cout << "이미 돌이 놓여있습니다. 다시 입력해주세요" << endl;
					cin.clear();
					cin.ignore();
				}
			}
			else if (cin.fail()) {
				cout << "올바른 입력이 아닙니다. 다시 입력해주세요" << endl;
				cin.clear();
				cin.ignore();
			}

			every_num();
			garos();
			seros();
			daegacs();
		}

		else if (input_menu == 2) {
			InFile();
		}

		else if (input_menu == 3) {
			OutFile();
		}

		else if (input_menu == 4) {
			int current_x{};
			int current_y{};
			int current_shape{};
			if (head != nullptr) {
				current_x = head->x;
				current_y = head->y;
				current_shape = head->shape;
				board[current_y][current_x] = '+';

				return_omoc(current_x, current_y, current_shape);
				head = head->next;
			}
			else {
				cout << "무르기할 수가 없습니다." << endl;
			}
		}

		else if (input_menu == 5) {
			int current_x{};
			int current_y{};
			int current_shape{};
			if (return_head != nullptr) {
				current_x = return_head->x;
				current_y = return_head->y;
				current_shape = return_head->shape;
				board[current_y][current_x] = current_shape;

				insert_omoc(current_x, current_y, current_shape);
				return_head = return_head->next;
			}
			else {
				cout << "무르기 취소할 수가 없습니다." << endl;
			}
		}

		else {
			cout << "올바른 입력이 아닙니다. 다시 입력해주세요" << endl;
		}
	}
	return 0;
}