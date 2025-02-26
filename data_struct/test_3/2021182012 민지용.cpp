#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int cnt{ 0 };


class Champ
{
public:
	string pos{};
	string name{};
	int hp{};
	int atk{};
	int def{};

	Champ* next{};

	Champ() {
		pos = "\0";
		name = "\0";
		hp = -1;
		atk = -1;
		def = -1;

		next = nullptr;
	};
	Champ(string c_pos, string c_name, int c_hp, int c_atk, int c_def)
		: pos(c_pos), name(c_name), hp(c_hp), atk(c_atk), def(c_def), next(nullptr) {};
	~Champ() {};

	void print_champ() const {
		cout.width(10);
		cout << pos;
		cout.width(15);
		cout << name;
		cout.width(5);
		cout << hp;
		cout.width(5);
		cout << atk;
		cout.width(5);
		cout << def << endl;
	};
};


Champ* head = nullptr;
Champ* tail = nullptr;


class ChampTree
{
public:
	string pos{};
	string name{};
	int hp{};
	int atk{};
	int def{};

	ChampTree* lchild{};
	ChampTree* rchild{};

	ChampTree() {
		pos = "\0";
		name = "\0";
		hp = -1;
		atk = -1;
		def = -1;

		lchild = nullptr;
		rchild = nullptr;
	};
	ChampTree(string c_pos, string c_name, int c_hp, int c_atk, int c_def)
		: pos(c_pos), name(c_name), hp(c_hp), atk(c_atk), def(c_def), lchild(nullptr), rchild(nullptr) {};
	~ChampTree() {};

	void print_champ() const {
		cout.width(10);
		cout << pos;
		cout.width(15);
		cout << name;
		cout.width(5);
		cout << hp;
		cout.width(5);
		cout << atk;
		cout.width(5);
		cout << def << endl;
	};
};

ChampTree* root = nullptr;


void MakeLinkedList() {
	ifstream in{ "LOLDic.txt" };
	if (!in) {
		cout << "파일을 열 수 없습니다." << endl;
		return;
	}

	string pos;
	string name;
	int hp, atk, def;

	if (head == nullptr) {
		head = tail = new Champ; //첫 노드 할당
	}

	while (in >> pos >> name >> hp >> atk >> def) {
		Champ* newChamp = new Champ(pos, name, hp, atk, def);

		if (!tail->next) {
			tail->next = newChamp;
			tail = newChamp;
		}
	}
	tail->next = nullptr;

	in.close();
}

Champ* sortedInsert(Champ* sorted, Champ* newChamp) {
	if (!sorted || sorted->name >= newChamp->name) {
		newChamp->next = sorted;
		sorted = newChamp;
	}
	else {
		Champ* current = sorted;
		while (current->next && current->next->name < newChamp->name) {
			current = current->next;
		}
		newChamp->next = current->next;
		current->next = newChamp;
	}
	return sorted;
}


void SortByName_SL() {
	Champ* sorted = nullptr;
	Champ* current = head;

	while (current) {
		Champ* next = current->next;
		sorted = sortedInsert(sorted, current);
		current = next;
	}

	head = sorted;
}

void PrintAll_SL() {
	Champ* q{};
	for (q = head->next; q->next != nullptr; q = q->next) {
		q->print_champ();
	}
}

void Insert_BT(ChampTree*& root, const string& pos, const string& name, int hp, int atk, int def) {
	if (root == nullptr) {
		root = new ChampTree(pos, name, hp, atk, def);
		return;
	}

	if (name < root->name) {
		Insert_BT(root->lchild, pos, name, hp, atk, def);
	}
	else {
		Insert_BT(root->rchild, pos, name, hp, atk, def);
	}
}

void MakeTree() {
	ifstream in{ "LOLDic.txt" };
	if (!in) {
		cout << "파일을 열 수 없습니다." << endl;
		return;
	}

	string pos, name;
	int hp, atk, def;

	while (in >> pos >> name >> hp >> atk >> def) {
		Insert_BT(root, pos, name, hp, atk, def);
	}

	in.close();
}

void Search_BT(string c_name, ChampTree* root) {
	while (root != nullptr) {
		if (root->name == c_name) {
			root->print_champ();
			return;
		}
		else {
			Search_BT(c_name, root->rchild);
			Search_BT(c_name, root->lchild);
			break;
		}
	}
}


void Delete_BT(string c_name, ChampTree* root) {
	ChampTree* cur = root;
	ChampTree* parent = nullptr;
	ChampTree* child = nullptr;
	ChampTree* pre = nullptr;
	ChampTree* suc = nullptr;
	while (cur != nullptr) {
		if (cur->name == c_name) {
			break;
		}
		parent = cur;
		if (cur->name < c_name) {
			cur = cur->rchild;
		}
		else {
			cur = cur->lchild;
		}
	}
	if (cur == NULL) {
		cout << "그런 이름의 챔피언은 없습니다." << endl;
		return;
	}
	if (cur->lchild == NULL && cur->rchild == NULL) {
		if (parent != NULL) {
			if (parent->lchild == cur) {
				parent->lchild = NULL;
			}
			else {
				parent->rchild = NULL;
			}
		}
		else {
			cur = NULL;
		}
	}
	else if (cur->lchild != NULL && cur->rchild != NULL) {
		pre = cur;
		suc = cur->lchild;
		while (suc->rchild != NULL) {
			pre = suc;
			suc = suc->rchild;
		}
		if (pre->lchild == suc) {
			pre->lchild = suc->lchild;
		}
		else {
			pre->rchild = suc->lchild;
		}
		cur->pos = suc->pos;
		cur->name = suc->name;
		cur->hp = suc->hp;
		cur->atk = suc->atk;
		cur->def = suc->def;
		cur = suc;
	}
	else {
		if (cur->lchild != NULL) {
			child = cur->lchild;
		}
		else if (cur->rchild != NULL) {
			child = cur->rchild;
		}
		if (parent != NULL) {
			if (parent->lchild == cur) {
				parent->lchild = child;
			}
			else if (parent->rchild == cur) {
				parent->rchild = child;
			}
		}
		else {
			root = child;
		}
	}
	free(cur);
	cout << "성공적으로 삭제되었습니다." << endl;
}


void PrintAll_BT(ChampTree* root) {
	if (root != nullptr) {
		PrintAll_BT(root->lchild);
		root->print_champ();
		PrintAll_BT(root->rchild);
	}
}

void SortByName_BT(ChampTree* root) {
	if (root != nullptr) {
		SortByName_BT(root->lchild);
		root->print_champ();
		SortByName_BT(root->rchild);
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
	double start_time{};
	double end_time{};

	MakeLinkedList();

	start_time = (((double)clock()) / CLOCKS_PER_SEC);
	SortByName_SL();
	PrintAll_SL();
	end_time = (((double)clock()) / CLOCKS_PER_SEC);
	cout << "연결리스트 만들고 정렬하는 함수 실행시간: " << end_time - start_time << endl;

	MakeTree();
	cout << "트리 구조로 재정렬 완료." << endl;

	string input{};
	string input_name{};


	while (true) {
		cout << "Menu | Search, Insert, Delete, PrintAll, SortByName, Exit" << endl << "어떤 동작을 수행할까요? : ";
		cin >> input;
		if (input == "Search") {
			cout << "검색할 챔피언의 이름은 무엇인가요? : ";
			cin.ignore();
			getline(cin, input_name);

			start_time = (((double)clock()) / CLOCKS_PER_SEC);
			Search_BT(input_name, root);
			end_time = (((double)clock()) / CLOCKS_PER_SEC);
			cout << "함수 실행시간: " << end_time - start_time << endl;
		}

		else if (input == "Insert") {
			string temp_pos, temp_name;
			int temp_hp, temp_atk, temp_def;
			string temp_str{};

			cout << "position을 입력해주세요 : ";
			cin.ignore();
			cin >> temp_str;
			if (check_eng(temp_str)) {
				temp_pos = temp_str;
			}
			else if (!check_eng(temp_str)) {
				cout << "다시 입력해주세요." << endl;
				continue;
			}

			cout << "이름을 입력해주세요 : ";
			cin.ignore();
			getline(cin, temp_str);
			if (!cin.fail()) {
				temp_name = temp_str;
			}
			else if (cin.fail()) {
				cout << "다시 입력해주세요." << endl;
				continue;
			}

			cout << "hp을 입력해주세요 : ";
			int temp_int{};
			cin >> temp_int;
			if (!cin.fail()) {
				temp_hp = temp_int;
			}
			else if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "다시 입력해주세요." << endl;
				continue;
			}

			cout << "공격력을 입력해주세요 : ";
			cin >> temp_int;
			if (!cin.fail()) {
				temp_atk = temp_int;
			}
			else if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "다시 입력해주세요." << endl;
				continue;
			}

			cout << "방어력을 입력해주세요 : ";
			cin >> temp_int;
			if (!cin.fail()) {
				temp_def = temp_int;
			}
			else if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "다시 입력해주세요." << endl;
				continue;
			}

			start_time = (((double)clock()) / CLOCKS_PER_SEC);
			Insert_BT(root, temp_pos, temp_name, temp_hp, temp_atk, temp_def);
			end_time = (((double)clock()) / CLOCKS_PER_SEC);
			cout << "함수 실행시간: " << end_time - start_time << endl;

			cout << "성공적으로 저장되었습니다." << endl;
		}

		else if (input == "Delete") {
			cout << "삭제할 챔피언의 이름은 무엇인가요? : ";
			cin.ignore();
			getline(cin, input_name);

			start_time = (((double)clock()) / CLOCKS_PER_SEC);
			Delete_BT(input_name, root);
			end_time = (((double)clock()) / CLOCKS_PER_SEC);
			cout << "함수 실행시간: " << end_time - start_time << endl;
		}

		else if (input == "PrintAll") {
			start_time = (((double)clock()) / CLOCKS_PER_SEC);
			PrintAll_BT(root);
			end_time = (((double)clock()) / CLOCKS_PER_SEC);
			cout << "함수 실행시간: " << end_time - start_time << endl;
		}

		else if (input == "SortByName") {
			start_time = (((double)clock()) / CLOCKS_PER_SEC);
			SortByName_BT(root);
			cout << "성공적으로 정렬되었습니다." << endl;
			end_time = (((double)clock()) / CLOCKS_PER_SEC);
			cout << "함수 실행시간: " << end_time - start_time << endl;
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