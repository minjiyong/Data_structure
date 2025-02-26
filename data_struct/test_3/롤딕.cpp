#include <iostream>
#include <string>
using namespace std;


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


bool check_eng(const string& str) {
	for (char c : str) {
		if (!isalpha(c) && c != 32) {
			return false;
		}
	}
	return true;
}


const int arr_size{ 40 };

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

	bool check_search{ false };
	bool check_delete{ false };
	bool check_deleteall{ false };
	string input{};
	string input_name{};

	while (true) {
		cout << "Menu | Search, Insert, Delete, DeleteAll, PrintAll, FindMaxHp, SortByHp, Exit" << endl << "어떤 동작을 수행할까요? : ";
		cin >> input;
		if (input == "Search") {
			cout << "검색할 챔피언의 이름은 무엇인가요? : ";
			cin.ignore();
			getline(cin, input_name);
			for (int i = 0; i < champ_size; ++i) {
				if (champ_arr[i].name == input_name) {
					champ_arr[i].print_champ();
					check_search = true;
					break;
				}
			}
			if (check_search == false) cout << "그런 챔피언은 없습니다." << endl;

			check_search = false;
		}

		else if (input == "Insert") {
			cout << "이름을 입력해주세요 : ";
			string temp_str{};
			cin.ignore();
			getline(cin, temp_str);
			if (check_eng(temp_str)) {
				champ_arr[champ_size].name = temp_str;
			}
			else if (!check_eng(temp_str)) {
				cout << "다시 입력해주세요." << endl;
				continue;
			}
			cout << "hp을 입력해주세요 : ";
			int temp_int{};
			cin >> temp_int;
			if (!cin.fail()) {
				champ_arr[champ_size].hp = temp_int;
			}
			else if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "다시 입력해주세요." << endl;
				continue;
			}
			cout << "mp을 입력해주세요 : ";
			cin >> temp_int;
			if (!cin.fail()) {
				champ_arr[champ_size].mp = temp_int;
			}
			else if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "다시 입력해주세요." << endl;
				continue;
			}
			cout << "speed을 입력해주세요 : ";
			cin >> temp_int;
			if (!cin.fail()) {
				champ_arr[champ_size].speed = temp_int;
			}
			else if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "다시 입력해주세요." << endl;
				continue;
			}
			cout << "range을 입력해주세요 : ";
			cin >> temp_int;
			if (!cin.fail()) {
				champ_arr[champ_size].range = temp_int;
			}
			else if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "다시 입력해주세요." << endl;
				continue;
			}
			cout << "position을 입력해주세요 : ";
			cin >> temp_str;
			if (check_eng(temp_str)) {
				champ_arr[champ_size].pos = temp_str;
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
			for (int i = 0; i < champ_size; ++i) {
				if (champ_arr[i].name == input_name) {
					champ_arr[i].delete_champ();
					for (int j = i; j < champ_size; ++j) {
						champ_arr[j] = champ_arr[j + 1];
					}
					champ_size--;
					cout << "성공적으로 삭제되었습니다." << endl;
					check_delete = true;
					break;
				}
			}
			if (check_delete == false) cout << "그런 챔피언은 없습니다." << endl;

			check_delete = false;
		}

		else if (input == "DeleteAll") {
			cout << "삭제할 포지션은 무엇인가요? : ";
			cin >> input_name;
			for (int i = 0; i < champ_size; ++i) {
				if (champ_arr[i].pos == input_name) {
					champ_arr[i].delete_champ();
					for (int j = i; j < champ_size; ++j) {
						champ_arr[j] = champ_arr[j + 1];
					}
					champ_size--;
					i--;
					check_deleteall = true;
				}
			}
			if (check_deleteall == true) cout << "성공적으로 삭제되었습니다." << endl;
			else if (check_deleteall == false) cout << "그런 포지션은 없습니다." << endl;

			check_deleteall = false;
		}

		else if (input == "PrintAll") {
			for (int i = 0; i < champ_size; ++i) {
				champ_arr[i].print_champ();
			}
		}

		else if (input == "FindMaxHp") {
			int max[arr_size]{};
			int cnt{ 0 };
			for (int i = 0; i < champ_size; ++i) {
				if (champ_arr[i].hp > champ_arr[max[0]].hp) max[0] = i;
			}
			cnt++;
			for (int i = 0; i < champ_size; ++i) {
				if (champ_arr[i].hp == champ_arr[max[0]].hp) {
					if (champ_arr[i].name == champ_arr[max[0]].name) cnt--;
					max[cnt++] = i;
				}
			}
			for (int i = 0; i < cnt; ++i) {
				champ_arr[max[i]].print_champ();
			}
		}

		else if (input == "SortByHp") {
			Champ temp{};
			for (int i = 0; i < champ_size; ++i) {
				for (int j = 0; j < champ_size - i - 1; ++j) {
					if (champ_arr[j].hp < champ_arr[j + 1].hp) {
						temp = champ_arr[j];
						champ_arr[j] = champ_arr[j + 1];
						champ_arr[j + 1] = temp;
					}
				}
			}
			cout << "성공적으로 체력이 큰 순으로 정렬되었습니다." << endl;
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