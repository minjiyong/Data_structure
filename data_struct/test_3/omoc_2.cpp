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
		cout << "����" << i << "��° �� o " << y_ocount[i] << "��" << endl;
		cout << "����" << i << "��° �� x " << y_xcount[i] << "��" << endl;
	}
	for (int i = 0; i < x_max; ++i) {
		cout << "����" << i << "��° �� o " << x_ocount[i] << "��" << endl;
		cout << "����" << i << "��° �� x " << x_xcount[i] << "��" << endl;
	}
}

void garos() {
	int omax = { 0 };					// ���ӵ� ���� ������ ���� ū �� 'o'
	int xmax = { 0 };
	int os{ 0 };						// ���ӵ� ���� ���� 'o'
	int xs{ 0 };

	int max_ox[x_max] = { NULL };		// ���ӵ� ���� ��ǥ�� 'o'
	int max_oy[y_max] = { NULL };
	int ox_index{ 0 };
	int oy_index{ 0 };

	int max_xx[x_max] = { NULL };		// ���ӵ� ���� ��ǥ�� 'x'
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
			cout << i << "��° �����ٿ��� ���� ���� �������� ���� ��: o, " << omax << "��" << endl;
			for (int j = 0; j < x_max; ++j) {
				if (max_ox[j] != NULL) cout << "(" << max_ox[j] << ", " << max_oy[j] << ")";
			}
			cout << endl;
			cout << i << "��° �����ٿ��� ���� ���� �������� ���� ��: x, " << xmax << "��" << endl;
			for (int j = 0; j < x_max; ++j) {
				if (max_xx[j] != NULL) cout << "(" << max_xx[j] << ", " << max_xy[j] << ")";
			}
			cout << endl;
		}
		else if (omax > xmax) {
			cout << i << "��° �����ٿ��� ���� ���� �������� ���� ��: o, " << omax << "��" << endl;
			for (int j = 0; j < x_max; ++j) {
				if (max_ox[j] != NULL) cout << "(" << max_ox[j] << ", " << max_oy[j] << ")";
			}
			cout << endl;
		}
		else if (xmax > omax) {
			cout << i << "��° �����ٿ��� ���� ���� �������� ���� ��: x, " << xmax << "��" << endl;
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
			cout << i << "��° �����ٿ��� ���� ���� �������� ���� ��: o, " << omax << "��" << endl;
			cout << i << "��° �����ٿ��� ���� ���� �������� ���� ��: x, " << xmax << "��" << endl;
		}
		else if (omax > xmax) {
			cout << i << "��° �����ٿ��� ���� ���� �������� ���� ��: o, " << omax << "��" << endl;
		}
		else if (xmax > omax) {
			cout << i << "��° �����ٿ��� ���� ���� �������� ���� ��: x, " << xmax << "��" << endl;
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

	// x = 0 ��ǥ�� �����ϴ� ������ �밢��
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
			cout << "(" << 0 << ", " << i << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: o, " << omax << "��" << endl;
			cout << "(" << 0 << ", " << i << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: x, " << xmax << "��" << endl;
		}
		else if (omax > xmax) {
			cout << "(" << 0 << ", " << i << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: o, " << omax << "��" << endl;
		}
		else if (xmax > omax) {
			cout << "(" << 0 << ", " << i << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: x, " << xmax << "��" << endl;
		}
		os = 0;
		xs = 0;
		omax = 0;
		xmax = 0;
	}

	// y = 0 ��ǥ�� �����ϴ� ������ �밢��
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
			cout << "(" << i << ", " << 0 << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: o, " << omax << "��" << endl;
			cout << "(" << i << ", " << 0 << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: x, " << xmax << "��" << endl;
		}
		else if (omax > xmax) {
			cout << "(" << i << ", " << 0 << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: o, " << omax << "��" << endl;
		}
		else if (xmax > omax) {
			cout << "(" << i << ", " << 0 << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: x, " << xmax << "��" << endl;
		}
		os = 0;
		xs = 0;
		omax = 0;
		xmax = 0;
	}

	// y = 0 ��ǥ�� �����ϴ� ������ �밢��
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
			cout << "(" << i << ", " << 0 << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: o, " << omax << "��" << endl;
			cout << "(" << i << ", " << 0 << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: x, " << xmax << "��" << endl;
		}
		else if (omax > xmax) {
			cout << "(" << i << ", " << 0 << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: o, " << omax << "��" << endl;
		}
		else if (xmax > omax) {
			cout << "(" << i << ", " << 0 << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: x, " << xmax << "��" << endl;
		}
		os = 0;
		xs = 0;
		omax = 0;
		xmax = 0;
	}

	// x = 19 ��ǥ�� �����ϴ� ������ �밢��
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
			cout << "(" << 19 << ", " << i << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: o, " << omax << "��" << endl;
			cout << "(" << 19 << ", " << i << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: x, " << xmax << "��" << endl;
		}
		else if (omax > xmax) {
			cout << "(" << 19 << ", " << i << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: o, " << omax << "��" << endl;
		}
		else if (xmax > omax) {
			cout << "(" << 19 << ", " << i << ") ���� �����ϴ� ������ �밢������ ���� ���� �������� ���� ��: x, " << xmax << "��" << endl;
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
		cout << "�޴�: 1.�� ����, 2.���� �ҷ�����, 3.���� �����ϱ�, 4.������, 5.������ ���: ";
		cin >> input_menu;
		if (cin.fail()) {
			cout << "�ùٸ� �Է��� �ƴմϴ�. �ٽ� �Է����ּ���" << endl;
			cin.clear();
			cin.ignore();
		}

		else if (input_menu == 1) {
			cout << "���� ���� ��ġ�� �Է����ּ���(���� 0~19, ���� 0~19): ";
			cin >> input_x >> input_y;
			system("cls");
			if (!cin.fail()) {
				if (input_x > 19 || input_x < 0 || input_y > 19 || input_y < 0) {
					cout << "�ùٸ� �Է��� �ƴմϴ�. �ٽ� �Է����ּ���" << endl;
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
					cout << "�̹� ���� �����ֽ��ϴ�. �ٽ� �Է����ּ���" << endl;
					cin.clear();
					cin.ignore();
				}
			}
			else if (cin.fail()) {
				cout << "�ùٸ� �Է��� �ƴմϴ�. �ٽ� �Է����ּ���" << endl;
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
				cout << "�������� ���� �����ϴ�." << endl;
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
				cout << "������ ����� ���� �����ϴ�." << endl;
			}
		}

		else {
			cout << "�ùٸ� �Է��� �ƴմϴ�. �ٽ� �Է����ּ���" << endl;
		}
	}
	return 0;
}