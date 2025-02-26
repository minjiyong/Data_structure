//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//
//class ChampTree
//{
//public:
//	string pos{};
//	string name{};
//	int hp{};
//	int atk{};
//	int def{};
//
//	ChampTree* lchild{ nullptr };
//	ChampTree* rchild{ nullptr };
//
//	ChampTree() {};
//	ChampTree(string p, string n, int h, int a, int d)
//		:pos(p), name(n), hp(h), atk(a), def(d), lchild(nullptr), rchild(nullptr) {};
//	~ChampTree() {};
//
//	void print_champ() {
//		cout.width(10);
//		cout << pos;
//		cout.width(15);
//		cout << name;
//		cout.width(5);
//		cout << hp;
//		cout.width(5);
//		cout << atk;
//		cout.width(5);
//		cout << def << endl;
//	}
//};
//
//void InsertBT(ChampTree*& root, string pos, string name, int hp, int atk, int def) {
//	if (root == nullptr) {
//		root = new ChampTree(pos, name, hp, atk, def);
//		return;
//	}
//
//	if (name < root->name) {
//		InsertBT(root->lchild, pos, name, hp, atk, def);
//	}
//	else {
//		InsertBT(root->rchild, pos, name, hp, atk, def);
//	}
//}
//
//void MakeTree(ChampTree*& root) {
//	ifstream in{ "mini_LOLDic.txt" };
//
//	if (!in) {
//		cout << "파일을 열 수 없습니다." << endl;
//		return;
//	}
//
//	string pos, name;
//	int hp, atk, def;
//
//	while (in >> pos >> name >> hp >> atk >> def) {
//		InsertBT(root, pos, name, hp, atk, def);
//	}
//
//	in.close();
//}
//
//void PrintBT(ChampTree* root) {
//	if (root == nullptr) {
//		return;
//	}
//
//	PrintBT(root->lchild);
//	root->print_champ();
//	PrintBT(root->rchild);
//}
//
//void DeleteBT(ChampTree*& root, string name) {
//	ChampTree* cur{ root };
//	ChampTree* parent{ nullptr };
//	ChampTree* pre{ nullptr };
//	ChampTree* suc{ nullptr };
//	ChampTree* child{ nullptr };
//
//	while (cur != nullptr) {
//		if (name == cur->name) {
//			break;
//		}
//		parent = cur;
//		if (name < cur->name) {
//			cur = cur->lchild;
//		}
//		else {
//			cur = cur->rchild;
//		}
//	}
//
//	if (cur == nullptr) {
//		cout << "지울 노드를 찾을 수 없습니다." << endl;
//		return;
//	}
//
//	if (cur->lchild == nullptr && cur->rchild == nullptr) {
//		if (parent != nullptr) {
//			if (parent->lchild == cur) {
//				parent->lchild = nullptr;
//			}
//			else {
//				parent->rchild = nullptr;
//			}
//		}
//		else {
//			cur = nullptr;
//		}
//	}
//
//	else if (cur->lchild != nullptr && cur->rchild != nullptr) {
//		pre = cur;
//		suc = cur->lchild;
//		while (suc->rchild != nullptr) {
//			pre = suc;
//			suc = suc->rchild;
//		}
//
//		if (pre->lchild == suc) {
//			pre->lchild = suc->lchild;
//		}
//		else {
//			pre->rchild = suc->lchild;
//		}
//
//		cur->pos = suc->pos;
//		cur->name = suc->name;
//		cur->hp = suc->hp;
//		cur->atk = suc->atk;
//		cur->def = suc->def;
//		cur = suc;
//	}
//
//	else {
//		if (cur->lchild != nullptr) {
//			child = cur->lchild;
//		}
//		else if (cur->rchild != nullptr) {
//			child = cur->rchild;
//		}
//
//		if (parent != nullptr) {
//			if (parent->lchild == cur) {
//				parent->lchild = child;
//			}
//			else if (parent->rchild == cur) {
//				parent->rchild = child;
//			}
//		}
//		else {
//			root = child;
//		}
//	}
//
//	free(cur);
//	cout << "성공적으로 삭제되었습니다." << endl;
//}
//
//void SearchBT(ChampTree* root, string name) {
//	if (root == nullptr) {
//		return;
//	}
//	
//	if (name == root->name) {
//		root->print_champ();
//		return;
//	}
//	else {
//		SearchBT(root->lchild, name);
//		SearchBT(root->rchild, name);
//	}
//}
//
//
//
//int main()
//{
//	ChampTree* root{ nullptr };
//
//	MakeTree(root);
//
//	string input{};
//
//
//	while (input != "1") {
//		PrintBT(root);
//		cin >> input;
//		DeleteBT(root, input);
//	}
//
//	return 0;
//}



#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class ChampList
{
public:
	string pos{};
	string name{};
	int hp{};
	int atk{};
	int def{};

	ChampList* next{ nullptr };

	ChampList() {};
	ChampList(string p, string n, int h, int a, int d)
		:pos(p), name(n), hp(h), atk(a), def(d), next(nullptr) {};
	~ChampList() {};

	void print_champ() {
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
	}
};

void MakeList(ChampList*& head, ChampList*& tail) {
	ifstream in("mini_LOLDic.txt");

	if (!in) {
		cout << "파일을 열 수 없습니다." << endl;
		return;
	}

	string pos, name;
	int hp, atk, def;

	if (head == nullptr) {
		head = tail = new ChampList;
	}
	while (in >> pos >> name >> hp >> atk >> def) {
		ChampList* newchamp = new ChampList(pos, name, hp, atk, def);

		tail->next = newchamp;
		tail = newchamp;
	}

	tail->next = nullptr;

	in.close();
}

void PrintSL(ChampList*& head) {
	for (ChampList* c = head->next; c != nullptr; c = c->next) {
		c->print_champ();
	}
}


int main()
{
	ChampList* head{ nullptr };
	ChampList* tail{ nullptr };

	MakeList(head, tail);
	PrintSL(head);

	return 0;
}