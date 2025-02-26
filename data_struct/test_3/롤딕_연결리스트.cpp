#include <iostream>
#include <string>
using namespace std;

#define arr_size 40


class Champ
{
public:
	string name{};
	int hp{};
	int mp{};
	int speed{};
	int range{};
	string pos{};

	Champ* next{};

	Champ() {
		name = "\0";
		hp = -1;
		mp = -1;
		speed = -1;
		range = -1;
		pos = "\0";

		next = nullptr;
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


int index{ 0 };
Champ champ_arr[arr_size]{};
Champ* tail = nullptr;


void Array2LinkedList() {
	Champ* current = nullptr;

	Champ* new_c = new Champ;
	new_c->name = champ_arr[0].name;
	new_c->hp = champ_arr[0].hp;
	new_c->mp = champ_arr[0].mp;
	new_c->speed = champ_arr[0].speed;
	new_c->range = champ_arr[0].range;
	new_c->pos = champ_arr[0].pos;

	tail = new_c;
	new_c->next = current;
	current = new_c;

	for (int i = 1; i < arr_size; ++i) {
		if (champ_arr[i].name == "\0") continue;
		Champ* new_c = new Champ;
		new_c->name = champ_arr[i].name;
		new_c->hp = champ_arr[i].hp;
		new_c->mp = champ_arr[i].mp;
		new_c->speed = champ_arr[i].speed;
		new_c->range = champ_arr[i].range;
		new_c->pos = champ_arr[i].pos;

		new_c->next = current;
		current = new_c;
	}

	tail->next = current;
}

void Search(string c_name) {
	Champ* p{};
	for (p = tail; p->next != tail; p = p->next) {
		if (p->name == c_name) {
			p->print_champ();
			return;
		}
	}
	cout << "그런 챔피언은 없습니다." << endl;
}

void Delete(string c_name) {
	Champ* p{};
	for (p = tail; p->next != tail; p = p->next) {
		if (p->next->next == tail) {
			if (tail->name == c_name) {
				p->next->next = p->next->next->next;
				cout << "성공적으로 삭제되었습니다." << endl;
				tail = p->next->next;
				return;
			}
		}
		if (p->next->name == c_name) {
			p->next = p->next->next;
			cout << "성공적으로 삭제되었습니다." << endl;
			return;
		}
	}
	cout << "그런 챔피언은 없습니다." << endl;
}

void DeleteAll(string c_name) {
	Champ* p{};
	bool check{ false };
	for (p = tail; p->next != tail; p = p->next) {
		if (p->next->next == tail) {
			if (tail->pos == c_name) {
				p->next->next = p->next->next->next;
				check = true;
				tail = p->next->next;
			}
		}
		if (p->next->pos == c_name) {
			p->next = p->next->next;
			check = true;
			p = tail;
		}
	}
	if(check) cout << "성공적으로 삭제되었습니다." << endl;
	else cout << "그런 포지션은 없습니다." << endl;
}

void PrintAll() {
	Champ* p{};
	for (p = tail; p->next != tail; p = p->next) {
		if (p->name == "\0") continue;
		p->print_champ();
	}
}

void FindMaxHp(int& max) {
	Champ* p{};
	for (p = tail; p->next != tail; p = p->next) {
		if (p->hp > max) {
			max = p->hp;
		}
	}
}

void FindBetweenHp(Champ c[], int b_max, int& n_max, int c_num) {
	if (c_num == 0) return;
	if (b_max > c[index].hp && c[index].hp > n_max) n_max = c[index].hp;
	++index;
	return FindBetweenHp(c, b_max, n_max, --c_num);
}

void PrintSameHp(int max) {
	Champ* p{};
	for (p = tail; p->next != tail; p = p->next) {
		if (p->hp == max) {
			max = p->hp;
			p->print_champ();
		}
	}
}

void SortByHp() {
	Champ* q{};
	for (q = tail; q->next != tail; q = q->next) {
		if (q->hp < q->next->hp) {
			int temp{ q->next->hp };
			q->next->hp = q->hp;
			q->hp = temp;
			q = tail;
		}
	}
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

	Array2LinkedList();

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
			Search(input_name);
		}

		else if (input == "Insert") {
			Champ* new_c = new Champ;
			cout << "이름을 입력해주세요 : ";
			string temp_str{};
			cin.ignore();
			getline(cin, temp_str);
			if (check_eng(temp_str)) {
				new_c->name = temp_str;
			}
			else if (!check_eng(temp_str)) {
				cout << "다시 입력해주세요." << endl;
				continue;
			}
			cout << "hp을 입력해주세요 : ";
			int temp_int{};
			cin >> temp_int;
			if (!cin.fail()) {
				new_c->hp = temp_int;
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
				new_c->mp = temp_int;
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
				new_c->speed = temp_int;
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
				new_c->range = temp_int;
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
				new_c->pos = temp_str;
			}
			else if (!check_eng(temp_str)) {
				cout << "다시 입력해주세요." << endl;
				continue;
			}

			new_c->next = tail->next;
			tail->next = new_c;

			cout << "성공적으로 저장되었습니다." << endl;
		}

		else if (input == "Delete") {
			cout << "삭제할 챔피언의 이름은 무엇인가요? : ";
			cin.ignore();
			getline(cin, input_name);
			Delete(input_name);
		}

		else if (input == "DeleteAll") {
			cout << "삭제할 포지션은 무엇인가요? : ";
			cin >> input_name;
			DeleteAll(input_name);
		}

		else if (input == "PrintAll") {
			PrintAll();
		}

		else if (input == "FindMaxHp") {
			int max{ 0 };
			FindMaxHp(max);
			PrintSameHp(max);
		}

		else if (input == "SortByHp") {
			SortByHp();
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