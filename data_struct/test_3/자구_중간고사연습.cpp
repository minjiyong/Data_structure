//트리 구조 연습
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
		cout << "파일을 찾을 수 없습니다." << endl;
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

	// 삭제할 노드 탐색. parent를 삭제할 노드의 부모노드를 가리키게 함.
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

	// 삭제할 노드를 찾지 못했다면 함수종료
	if (cur == nullptr) {
		cout << "삭제할 챔피언이 없습니다." << endl;
		return;
	}

	// 삭제할 노드가 리프 노드일 경우
	if (cur->lchild == nullptr && cur->rchild == nullptr) {
		if (parent != nullptr) {
			if (parent->lchild == cur) {
				parent->lchild = nullptr;
			}
			else {
				parent->rchild = nullptr;
			}
		}

		// 삭제할 노드가 루트 노드면 그냥 지우면 끝
		else {
			cur == nullptr;
		}
	}

	// 삭제할 노드가 두 자식을 가진 경우
	else if (cur->lchild != nullptr && cur->rchild != nullptr) {
		pre = cur;
		suc = cur->lchild;

		// 오른쪽 자식이 없을 때까지 이동, suc은 전임자 노드가 된다.
		while (suc->rchild != nullptr) {
			pre = suc;
			suc = suc->rchild;
		}

		// pre의 오른쪽과 왼쪽 중 어디가 suc인지에 따라 suc의 왼쪽 자식으로 연결
		if (pre->lchild == suc) {
			pre->lchild = suc->lchild;
		}
		else {
			pre->rchild = suc->lchild;
		}

		// cur의 값을 전부 suc의 값으로 바꿔준다.
		cur->pos = suc->pos;
		cur->name = suc->name;
		cur->hp = suc->hp;
		cur->atk = suc->atk;
		cur->def = suc->def;
		cur = suc;
	}

	// 삭제할 노드가 하나의 자식을 가진 경우
	else {
		// 오른쪽과 왼쪽 중 어디에 자식 값이 있는지 저장
		if (cur->lchild != nullptr) {
			child = cur->lchild;
		}
		else if (cur->rchild != nullptr) {
			child = cur->rchild;
		}

		// 좌우에 따라 parent의 값을 child의 값으로 바로 연결
		if (parent != nullptr) {
			if (parent->lchild == cur) {
				parent->lchild = child;
			}
			else if (parent->rchild == cur) {
				parent->rchild = child;
			}
		}

		// 만약 root 노드면 그대로 자식으로 연결하면 됨.
		else {
			root = child;
		}

		// cur 메모리 해제
		free(cur);
		cout << "성공적으로 삭제되었습니다." << endl;
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
	if (!check) cout << "그런 이름의 챔피언은 없습니다." << endl;*/

	DeleteBT(root, input);

	PrintAllBT(root);

	return 0;
}