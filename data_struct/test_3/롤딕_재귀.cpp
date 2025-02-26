#include <iostream>
#include <string>
using namespace std;

#define arr_size 40
int index{ 0 };


class Champ
{
public:
	string name{};
	int hp{};
	int mp{};
	int speed{};
	int range{};
	string pos{};

	Champ() {
		name = "\0";
		hp = -1;
		mp = -1;
		speed = -1;
		range = -1;
		pos = "\0";
	};
	Champ(string c_name, int c_hp, int c_mp, int c_speed, int c_range, string c_pos)
		: name(c_name), hp(c_hp), mp(c_mp), speed(c_speed), range(c_range), pos(c_pos) {};
	~Champ() {};

	void print_champ() const {
		cout.width(15);
		cout << name;
		cout.width(5);
		cout << hp;
		cout.width(5);
		cout << mp;
		cout.width(5);
		cout << speed;
		cout.width(5);
		cout << range;
		cout.width(10);
		cout << pos << endl;
	};

	void delete_champ() {
		name = "\0";
		hp = -1;
		mp = -1;
		speed = -1;
		range = -1;
		pos = "\0";
	}
};

int Search(Champ c[], string c_name, int c_num) {
	if (c_num == 0) return -1;
	else if (c[index].name == c_name) return index;
	index++;
	return Search(c, c_name, --c_num);
}

void DeleteAll (Champ c[], string c_name, int c_num, bool& check_deleteall) {
	if (c_num == 0) return;
	else if (c[index].pos == c_name) {
		c[index].delete_champ();
		check_deleteall = true;
	}
	index++;
	return DeleteAll(c, c_name, --c_num, check_deleteall);
}

void Print(Champ c[], int c_num) {
	if (c_num == 0) return;
	if (c[index].name != "\0") c[index].print_champ();
	++index;
	return Print(c, --c_num);
}

void FindMaxHp(Champ c[], int& max, int c_num) {
	if (c_num == 0) return;
	if (c[index].hp > max) max = c[index].hp;
	++index;
	return FindMaxHp(c, max, --c_num);
}

void FindBetweenHp(Champ c[], int b_max, int& n_max, int c_num) {
	if (c_num == 0) return;
	if (b_max > c[index].hp && c[index].hp > n_max) n_max = c[index].hp;
	++index;
	return FindBetweenHp(c, b_max, n_max ,--c_num);
}

void PrintSameHp(Champ c[], int max, int c_num) {
	if (c_num == 0) return;
	if (c[index].hp == max) c[index].print_champ();
	++index;
	return PrintSameHp(c, max, --c_num);
}

void SortByHp(Champ c[], int &b_max, int c_num) {
	if (c_num == 0) return;
	int n_max{ 0 };
	index = 0;
	FindBetweenHp(c, b_max, n_max, arr_size);
	index = 0;
	PrintSameHp(c, n_max, arr_size);
	b_max = n_max;
	return SortByHp(c, b_max, --c_num);
}

bool check_eng(const string& str) {
	for (char c : str) {
		if (!isalpha(c) && c != 32) {
			return false;
		}
	}
	return true;
}



int main()
{
	Champ champ_arr[arr_size]{};
	Champ a("Jayce", 3466, 8307, 452, 73, "mid");
	Champ b("Vayne", 3318, 2790, 390, 60, "support");
	Champ c("Lee Sin", 9864, 6257, 747, 19, "support");
	Champ d("Teemo", 1915, 1313, 700, 68, "mid");
	Champ e("Nami", 2968, 2153, 803, 74, "support");
	Champ f("Jinx", 2583, 3042, 123, 53, "jungle");
	Champ g("Cassiopeia", 6067, 7330, 683, 24, "top");
	Champ h("Ahri", 4573, 7079, 177, 79, "top");
	Champ i("Fiora", 2591, 9329, 337, 81, "jungle");
	Champ j("Zac", 9864, 7272, 405, 49, "bottom");
	Champ k("Janna", 4922, 2275, 690, 66, "jungle");
	Champ l("Ashe", 7421, 5549, 428, 31, "top");
	Champ m("Twitch", 2980, 7703, 204, 91, "mid");
	Champ n("Ezreal", 3660, 9835, 274, 44, "mid");
	Champ o("Sona", 5655, 8442, 252, 26, "bottom");
	Champ p("Lulu", 3231, 2014, 503, 32, "support");
	Champ q("Amumu", 6763, 3994, 427, 19, "jungle");
	Champ r("Master Yi", 5737, 7168, 434, 61, "top");
	Champ s("Jarvan", 1895, 3070, 323, 80, "mid");
	Champ t("Shen", 4794, 9220, 783, 42, "mid");
	Champ u("Fizz", 9864, 1913, 433, 38, "bottom");
	Champ v("Taric", 6158, 7451, 160, 36, "bottom");

	champ_arr[0] = a;
	champ_arr[1] = b;
	champ_arr[2] = c;
	champ_arr[3] = d;
	champ_arr[4] = e;
	champ_arr[5] = f;
	champ_arr[6] = g;
	champ_arr[7] = h;
	champ_arr[8] = i;
	champ_arr[9] = j;
	champ_arr[10] = k;
	champ_arr[11] = l;
	champ_arr[12] = m;
	champ_arr[13] = n;
	champ_arr[14] = o;
	champ_arr[15] = p;
	champ_arr[16] = q;
	champ_arr[17] = r;
	champ_arr[18] = s;
	champ_arr[19] = t;
	champ_arr[20] = u;
	champ_arr[21] = v;

	int champ_size{ 0 };
	for (int i = 0; i < arr_size; ++i) {
		if (champ_arr[i].name == "\0") break;
		champ_size++;
	}

	bool check_deleteall{ false };
	string input{};
	string input_name{};
	int champ_index{ 0 };

	while (true) {
		cout << "Menu | Search, Insert, Delete, DeleteAll, PrintAll, FindMaxHp, SortByHp, Exit" << endl << "어떤 동작을 수행할까요? : ";
		cin >> input;
		if (input == "Search") {
			cout << "검색할 챔피언의 이름은 무엇인가요? : ";
			cin.ignore();
			getline(cin, input_name);
			index = 0;
			champ_index = Search(champ_arr, input_name, arr_size);
			if (champ_index == -1) {
				cout << "그런 챔피언은 없습니다." << endl;
			}
			else {
				champ_arr[champ_index].print_champ();
			}
		}

		else if (input == "Insert") {
			cout << "이름을 입력해주세요 : ";
			string temp_str{};
			cin.ignore();
			getline(cin, temp_str);
			index = 0;
			champ_index = Search(champ_arr, "\0", arr_size);
			if (check_eng(temp_str)) {
				champ_arr[champ_index].name = temp_str;
			}
			else if (!check_eng(temp_str)) {
				cout << "다시 입력해주세요." << endl;
				continue;
			}
			cout << "hp을 입력해주세요 : ";
			int temp_int{};
			cin >> temp_int;
			if (!cin.fail()) {
				champ_arr[champ_index].hp = temp_int;
			}
			else if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "다시 입력해주세요." << endl;
				continue;
			}
			cout << "mp을 입력해주세요 : ";
			cin.ignore();
			cin >> temp_int;
			if (!cin.fail()) {
				champ_arr[champ_index].mp = temp_int;
			}
			else if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "다시 입력해주세요." << endl;
				continue;
			}
			cout << "speed을 입력해주세요 : ";
			cin.ignore();
			cin >> temp_int;
			if (!cin.fail()) {
				champ_arr[champ_index].speed = temp_int;
			}
			else if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "다시 입력해주세요." << endl;
				continue;
			}
			cout << "range을 입력해주세요 : ";
			cin.ignore();
			cin >> temp_int;
			if (!cin.fail()) {
				champ_arr[champ_index].range = temp_int;
			}
			else if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "다시 입력해주세요." << endl;
				continue;
			}
			cout << "position을 입력해주세요 : ";
			cin.ignore();
			cin >> temp_str;
			if (check_eng(temp_str)) {
				champ_arr[champ_index].pos = temp_str;
			}
			else if (!check_eng(temp_str)) {
				cout << "다시 입력해주세요." << endl;
				continue;
			}
			cout << "성공적으로 저장되었습니다." << endl;
			champ_size++;
		}

		else if (input == "Delete") {
			cout << "삭제할 챔피언의 이름은 무엇인가요? : ";
			cin.ignore();
			getline(cin, input_name);
			index = 0;
			champ_index = Search(champ_arr, input_name, arr_size);
			if (champ_index == -1) {
				cout << "그런 챔피언은 없습니다." << endl;
			}
			else {
				champ_arr[champ_index].delete_champ();
				cout << "성공적으로 삭제되었습니다." << endl;
			}
		}

		else if (input == "DeleteAll") {
			cout << "삭제할 포지션은 무엇인가요? : ";
			cin >> input_name;
			index = 0;
			DeleteAll(champ_arr, input_name, arr_size, check_deleteall);

			if (check_deleteall == true) cout << "성공적으로 삭제되었습니다." << endl;
			else if (check_deleteall == false) cout << "그런 포지션은 없습니다." << endl;

			check_deleteall = false;
		}

		else if (input == "PrintAll") {
			index = 0;
			Print(champ_arr, arr_size);
		}

		else if (input == "FindMaxHp") {
			int max{ 0 };
			index = 0;
			FindMaxHp(champ_arr, max, arr_size);
			index = 0;
			PrintSameHp(champ_arr, max, arr_size);
		}

		else if (input == "SortByHp") {
			int max{ 0 };
			index = 0;
			FindMaxHp(champ_arr, max, arr_size);
			index = 0;
			PrintSameHp(champ_arr, max, arr_size);
			index = 0;
			SortByHp(champ_arr, max, arr_size);
			cout << "성공적으로 정렬되었습니다." << endl;
		}

		else if (input == "Exit") {
			exit(true);
			return 0;
		}

		else {
			cout << "그런 명령어는 없습니다." << endl;
		}

	}


	return 0;
}