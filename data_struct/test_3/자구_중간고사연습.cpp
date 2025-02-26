//Ʈ�� ���� ����
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ChampTree
{
public:
	string pos{};
	string name{};
	int hp{};
	int atk{};
	int def{};

	ChampTree* lchild = nullptr;
	ChampTree* rchild = nullptr;

	ChampTree() {};
	ChampTree(string c_pos, string c_name, int c_hp, int c_atk, int c_def)
		:pos(c_pos), name(c_name), hp(c_hp), atk(c_atk), def(c_def), lchild(nullptr), rchild(nullptr) {};
	~ChampTree() {};

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

void InsertBT(ChampTree*& root, string pos, string name, int hp, int atk, int def) {
	if (root == nullptr) {
		root = new ChampTree(pos, name, hp, atk, def);
		return;
	}
	
	if (name < root->name) {
		InsertBT(root->lchild, pos, name, hp, atk, def);
	}
	else {	
		InsertBT(root->rchild, pos, name, hp, atk, def);
	}
}

void MakeTree(ChampTree*& root) {
	ifstream in{ "mini_LOLDic.txt" };
	if (!in) {
		cout << "������ ã�� �� �����ϴ�." << endl;
		return;
	}

	string pos, name;
	int hp, atk, def;

	while (in >> pos >> name >> hp >> atk  >> def) {
		InsertBT(root, pos, name, hp, atk, def);
	}

	in.close();
}

void PrintAllBT(ChampTree* root) {
	if (root == nullptr) {
		return;
	}

	PrintAllBT(root->lchild);
	root->print_champ();
	PrintAllBT(root->rchild);
}

void SortByNameBT(ChampTree* root) {
	if (root == nullptr) {
		return;
	}

	PrintAllBT(root->lchild);
	root->print_champ();
	PrintAllBT(root->rchild);
}

void RevSortByNameBT(ChampTree* root) {
	if (root == nullptr) {
		return;
	}

	RevSortByNameBT(root->rchild);
	root->print_champ();
	RevSortByNameBT(root->lchild);
	
}

void SearchBT(ChampTree* root, string name, bool& check) {
	if (root == nullptr) {
		return;
	}

	if (root->name == name) {
		root->print_champ();
		check = true;
		return;
	}
	else {
		SearchBT(root->lchild, name, check);
		SearchBT(root->rchild, name, check);
	}
}

void DeleteBT(ChampTree*& root, string name) {
	ChampTree* cur = root;
	ChampTree* parent{ nullptr };
	ChampTree* pre{ nullptr };
	ChampTree* suc{ nullptr };
	ChampTree* child{ nullptr };

	// ������ ��� Ž��. parent�� ������ ����� �θ��带 ����Ű�� ��.
	while (cur != nullptr) {
		if (name == cur->name) {
			break;
		}
		parent = cur;
		if (name < cur->name) {
			cur = cur->lchild;
		} 
		else {
			cur = cur->rchild;
		}
	}

	// ������ ��带 ã�� ���ߴٸ� �Լ�����
	if (cur == nullptr) {
		cout << "������ è�Ǿ��� �����ϴ�." << endl;
		return;
	}

	// ������ ��尡 ���� ����� ���
	if (cur->lchild == nullptr && cur->rchild == nullptr) {
		if (parent != nullptr) {
			if (parent->lchild == cur) {
				parent->lchild = nullptr;
			}
			else {
				parent->rchild = nullptr;
			}
		}

		// ������ ��尡 ��Ʈ ���� �׳� ����� ��
		else {
			cur == nullptr;
		}
	}

	// ������ ��尡 �� �ڽ��� ���� ���
	else if (cur->lchild != nullptr && cur->rchild != nullptr) {
		pre = cur;
		suc = cur->lchild;

		// ������ �ڽ��� ���� ������ �̵�, suc�� ������ ��尡 �ȴ�.
		while (suc->rchild != nullptr) {
			pre = suc;
			suc = suc->rchild;
		}

		// pre�� �����ʰ� ���� �� ��� suc������ ���� suc�� ���� �ڽ����� ����
		if (pre->lchild == suc) {
			pre->lchild = suc->lchild;
		}
		else {
			pre->rchild = suc->lchild;
		}

		// cur�� ���� ���� suc�� ������ �ٲ��ش�.
		cur->pos = suc->pos;
		cur->name = suc->name;
		cur->hp = suc->hp;
		cur->atk = suc->atk;
		cur->def = suc->def;
		cur = suc;
	}

	// ������ ��尡 �ϳ��� �ڽ��� ���� ���
	else {
		// �����ʰ� ���� �� ��� �ڽ� ���� �ִ��� ����
		if (cur->lchild != nullptr) {
			child = cur->lchild;
		}
		else if (cur->rchild != nullptr) {
			child = cur->rchild;
		}

		// �¿쿡 ���� parent�� ���� child�� ������ �ٷ� ����
		if (parent != nullptr) {
			if (parent->lchild == cur) {
				parent->lchild = child;
			}
			else if (parent->rchild == cur) {
				parent->rchild = child;
			}
		}

		// ���� root ���� �״�� �ڽ����� �����ϸ� ��.
		else {
			root = child;
		}

		// cur �޸� ����
		free(cur);
		cout << "���������� �����Ǿ����ϴ�." << endl;
	}
}


int main()
{
	ChampTree* root = nullptr;
	string input{};
	bool check{ false };

	MakeTree(root);
	PrintAllBT(root);

	cin >> input;

	/*check = false;
	SearchBT(root, input, check);
	if (!check) cout << "�׷� �̸��� è�Ǿ��� �����ϴ�." << endl;*/

	DeleteBT(root, input);

	PrintAllBT(root);

	return 0;
}