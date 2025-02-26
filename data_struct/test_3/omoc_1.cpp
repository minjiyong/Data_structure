#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

char dot[19][19];
char black = 'O';
char white = 'X';
int count = 1;
int conti_nums[20];
char conti_nums_s[20];
//��� ������ �� ���� ���� ���ӵ� ������ ã������ ����
int all_conti_nums[100];
char all_conti_nums_s[100];
int all_max_conti_num = 1;
int all_conti_nums_num_x[100];
int all_conti_nums_num_y[100];


void board()
{
    int x, y;
    if (count % 2 == 1) {
        printf("�浹�� ��ǥ�� �����ÿ�>>");
        scanf("%d %d", &x, &y);
        if (x > 18 || x < 0 || y > 18 || y < 0)
            return;
        if (dot[y][x] != '+') {
            printf("�̹� ���� �����ֽ��ϴ�.\n");
            return;
        }
        dot[y][x] = black;
        count++;
    }
    else {
        printf("�鵹�� ��ǥ�� �����ÿ�>>");
        scanf("%d %d", &x, &y);
        if (x > 18 || x < 0 || y > 18 || y < 0)
            return;
        if (dot[y][x] != '+') {
            printf("�̹� ���� �����ֽ��ϴ�.\n");
            return;
        }
        dot[y][x] = white;
        count++;
    }
    system("cls");
    printf("[������] \n");
    printf("#1. �浹 O, �鵹 X\n#2. �浹(0-18), �鵹(0-18)\n#3. ��� ���� �� �밢�� ���� ������ +n��°, �Ʒ����� -n��° ����\n");
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            printf("%c ", dot[i][j]);
        }
        printf("\n");
    }
    return;
}
void number()
{
    int b_count = 0;
    int w_count = 0;
    for (int i = 0; i < 19; i++) { //������
        for (int j = 0; j < 19; j++) {
            if (dot[i][j] == 'O') {
                b_count++;
            }
            else if (dot[i][j] == 'X') {
                w_count++;
            }
        }
        if (b_count >= 1 || w_count >= 1)
            printf("���� %2d��° �� - �浹 %d��, �鵹 %d��\n", i + 1, b_count, w_count);
        b_count = 0;
        w_count = 0;
    }

    for (int i = 0; i < 19; i++) { //������
        for (int j = 0; j < 19; j++) {
            if (dot[j][i] == 'O') {
                b_count++;
            }
            else if (dot[j][i] == 'X') {
                w_count++;
            }
        }
        if (b_count >= 1 || w_count >= 1)
            printf("���� %2d��° �� - �浹 %d��, �鵹 %d��\n", i + 1, b_count, w_count);
        b_count = 0;
        w_count = 0;
    }
    return;
}
void conti()
{
    int x = 0; //������ ������ �迭 ��������
    int y = 0; //��� ������ �迭 ��������
    int conti_num = 1;
    int max_conti_num = 1;
    //��� ������ üŷ
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dot[i][j] == dot[i][j + 1] && dot[i][j] != '+') {
                conti_num++;
            }
            else if (dot[i][j] != dot[i][j + 1] && dot[i][j] != '+') {
                conti_nums[x] = conti_num;
                conti_nums_s[x] = dot[i][j];
                x++;
                all_conti_nums[y] = conti_num;
                all_conti_nums_s[y] = dot[i][j];
                all_conti_nums_num_y[y] = i;
                all_conti_nums_num_x[y] = j;
                y++;
                conti_num = 1;
            }
        }
        //���� �迭���� ���� ū�� ã��
        for (int i = 0; i < 20; i++) {
            if (conti_nums[i] == 0)
                break;
            if (conti_nums[i] > max_conti_num)
                max_conti_num = conti_nums[i];
        }

        for (int x = 0; x < 19; x++) {
            if (conti_nums[x] > 1) {
                if (conti_nums_s[x] != '+') {
                    printf("���� %d��° �� - ���� ���� ���ӵ� ���� ���� : %d", i + 1, max_conti_num);
                    for (int i = 0; i < 20; i++) {
                        if (conti_nums[i] == max_conti_num)
                            printf(", ���� ���� ���ӵ� ���� ���� : % c ", conti_nums_s[i]);
                    }
                    printf("\n");
                    break;
                }
            }
        }

        //������ �ѹ� ������ ���� ������ üŷ�ϱ��� �ʱ�ȭ
        for (int i = 0; i < 20; i++) {
            conti_nums[i] = 0;
            conti_nums_s[i] = 0;
        }
        x = 0;
        conti_num = 1;
        max_conti_num = 1;
    }




    //��� ������ üŷ
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (dot[j][i] == dot[j + 1][i] && dot[j][i] != '+') {
                conti_num++;
            }
            else if (dot[j][i] != dot[j + 1][i] && dot[j][i] != '+') {
                conti_nums[x] = conti_num;
                conti_nums_s[x] = dot[j][i];
                x++;
                conti_num = 1;
            }
        }
        //���� �迭���� ���� ū�� ã��
        for (int i = 0; i < 20; i++) {
            if (conti_nums[i] == 0)
                break;
            if (conti_nums[i] > max_conti_num)
                max_conti_num = conti_nums[i];
        }

        for (int x = 0; x < 19; x++) {
            if (conti_nums[x] > 1) {
                if (conti_nums_s[x] != '+') {
                    printf("���� %d��° �� - ���� ���� ���ӵ� ���� ���� : %d", i + 1, max_conti_num);
                    for (int i = 0; i < 20; i++) {
                        if (conti_nums[i] == max_conti_num)
                            printf(", ���� ���� ���ӵ� ���� ���� : % c ", conti_nums_s[i]);
                    }
                    printf("\n");
                    break;
                }
            }
        }

        for (int i = 0; i < 20; i++) {
            conti_nums[i] = 0;
            conti_nums_s[i] = 0;
        }

        max_conti_num = 1;  //������ �ѹ� ������ ���� ������ üŷ�ϱ��� �ʱ�ȭ
        x = 0;
        conti_num = 1;
    }




    //��� �����ٿ��� ���� ���� �������� ������ ������ ��ġ�� ��ǥ�� ǥ��

    for (int i = 0; i < 100; i++) {
        if (all_conti_nums[i] == 0)
            break;
        if (all_conti_nums[i] > all_max_conti_num)
            all_max_conti_num = all_conti_nums[i];
    }

    for (int y = 0; y < 100; y++) {
        if (all_conti_nums[y] == 0) {
            break;
        }
        if (all_conti_nums[y] > 1) {
            if (all_conti_nums_s[y] != '+') {
                for (int i = 0; i < 100; i++) {
                    if (all_conti_nums[i] == all_max_conti_num)
                        printf("���� ���� ���� ���� ���ӵ� ������ : %d��° ��, ���� ���� : % c, ���� ���� : %d, ���� ��ǥ(%d,%d), ������ ��ǥ(%d,%d)\n"
                            , all_conti_nums_num_y[i] + 1, all_conti_nums_s[i], all_conti_nums[i], all_conti_nums_num_x[i] - all_conti_nums[i] + 1, all_conti_nums_num_y[i], all_conti_nums_num_x[i], all_conti_nums_num_y[i]);
                }
                break;
            }
        }
    }

    for (int i = 0; i < 100; i++) {  //��� �������� ���ӵ� �� ã�� - �ʱ�ȭ
        all_conti_nums[i] = 0;
        all_conti_nums_s[i] = 0;
    }
    y = 0;
    all_max_conti_num = 1;

    return;
}
void dagak()
{
    int t = 0;
    int conti_num = 1;
    int max_conti_num = 1;
    //*****************������ �밢��(��� ���� �Ʒ�)********************
    for (int i = 17; i > 0; i--) {
        int i2 = i;
        for (int j = 0; j < 19; j++) {
            if (i2 == 19)
                break;
            if (dot[i2][j] == dot[i2 + 1][j + 1] && dot[i2][j] != '+') {
                conti_num++;
            }
            else if (dot[i2][j] != dot[i2 + 1][j + 1] && dot[i2][j] != '+') {
                conti_nums[t] = conti_num;
                conti_nums_s[t] = dot[i2][j];
                t++;
                conti_num = 1;
            }
            i2++;
        }
        for (int i = 0; i < 20; i++) {
            if (conti_nums[i] == 0)
                break;
            if (conti_nums[i] > max_conti_num)
                max_conti_num = conti_nums[i];
        }
        for (int x = 0; x < 19; x++) {
            if (conti_nums[x] > 1) {
                if (conti_nums_s[x] != '+') {
                    printf("������ �밢�� -%d��° �� - ���� ���� ���ӵ� ���� ���� : %d", i, max_conti_num);
                    for (int i = 0; i < 20; i++) {
                        if (conti_nums[i] == max_conti_num)
                            printf(", ���� ���� ���ӵ� ���� ���� : % c ", conti_nums_s[i]);
                    }
                    printf("\n");
                    break;
                }
            }
        }

        //�밢�� �ѹ� ������ ���� ������ üŷ�ϱ��� �ʱ�ȭ
        for (int i = 0; i < 20; i++) {
            conti_nums[i] = 0;
            conti_nums_s[i] = 0;
        }
        t = 0;
        conti_num = 1;
        max_conti_num = 1;
    }







    //*****************������ �밢��(��� ���� ��+��� ��)********************
    for (int j = 0; j < 18; j++) {
        int j2 = j;
        for (int i = 0; i < 19; i++) {
            if (j2 == 19)
                break;
            if (dot[i][j2] == dot[i + 1][j2 + 1] && dot[i][j2] != '+') {
                conti_num++;
            }
            else if (dot[i][j2] != dot[i + 1][j2 + 1] && dot[i][j2] != '+') {
                conti_nums[t] = conti_num;
                conti_nums_s[t] = dot[i][j2];
                t++;
                conti_num = 1;
            }
            j2++;
        }
        for (int i = 0; i < 20; i++) {
            if (conti_nums[i] == 0)
                break;
            if (conti_nums[i] > max_conti_num)
                max_conti_num = conti_nums[i];
        }
        for (int x = 0; x < 19; x++) {
            if (conti_nums[x] > 1) {
                if (conti_nums_s[x] != '+') {
                    printf("������ �밢�� %d��° �� - ���� ���� ���ӵ� ���� ���� : %d", j, max_conti_num);
                    for (int i = 0; i < 20; i++) {
                        if (conti_nums[i] == max_conti_num)
                            printf(", ���� ���� ���ӵ� ���� ���� : % c ", conti_nums_s[i]);
                    }
                    printf("\n");
                    break;
                }
            }
        }

        //�밢�� �ѹ� ������ ���� ������ üŷ�ϱ��� �ʱ�ȭ
        for (int i = 0; i < 20; i++) {
            conti_nums[i] = 0;
            conti_nums_s[i] = 0;
        }
        t = 0;
        conti_num = 1;
        max_conti_num = 1;
    }







    //*****************����� �밢��(��� ���� �Ʒ�)********************
    for (int i = 17; i > 0; i--) {
        int i2 = i;
        for (int j = 18; j > 0; j--) {
            if (i2 == 19)
                break;
            if (dot[i2][j] == dot[i2 + 1][j - 1] && dot[i2][j] != '+') {
                conti_num++;
            }
            else if (dot[i2][j] != dot[i2 + 1][j - 1] && dot[i2][j] != '+') {
                conti_nums[t] = conti_num;
                conti_nums_s[t] = dot[i2][j];
                t++;
                conti_num = 1;
            }
            i2++;
        }
        for (int i = 0; i < 20; i++) {
            if (conti_nums[i] == 0)
                break;
            if (conti_nums[i] > max_conti_num)
                max_conti_num = conti_nums[i];
        }
        for (int x = 0; x < 19; x++) {
            if (conti_nums[x] > 1) {
                if (conti_nums_s[x] != '+') {
                    printf("����� �밢�� -%d��° �� - ���� ���� ���ӵ� ���� ���� : %d", i, max_conti_num);
                    for (int i = 0; i < 20; i++) {
                        if (conti_nums[i] == max_conti_num)
                            printf(", ���� ���� ���ӵ� ���� ���� : % c ", conti_nums_s[i]);
                    }
                    printf("\n");
                    break;
                }
            }
        }

        //�밢�� �ѹ� ������ ���� ������ üŷ�ϱ��� �ʱ�ȭ
        for (int i = 0; i < 20; i++) {
            conti_nums[i] = 0;
            conti_nums_s[i] = 0;
        }
        t = 0;
        conti_num = 1;
        max_conti_num = 1;
    }







    //*****************����� �밢��(��� ���� ��+��� ��)********************
    for (int j = 18; j > 0; j--) {
        int j2 = j;
        for (int i = 0; i < 19; i++) {
            if (j2 < 0)
                break;
            if (dot[i][j2] == dot[i + 1][j2 - 1] && dot[i][j2] != '+') {
                conti_num++;
            }
            else if (dot[i][j2] != dot[i + 1][j2 - 1] && dot[i][j2] != '+') {
                conti_nums[t] = conti_num;
                conti_nums_s[t] = dot[i][j2];
                t++;
                conti_num = 1;
            }
            j2--;
        }
        for (int i = 0; i < 20; i++) {
            if (conti_nums[i] == 0)
                break;
            if (conti_nums[i] > max_conti_num)
                max_conti_num = conti_nums[i];
        }
        for (int x = 0; x < 19; x++) {
            if (conti_nums[x] > 1) {
                if (conti_nums_s[x] != '+') {
                    printf("����� �밢�� %d��° �� - ���� ���� ���ӵ� ���� ���� : %d", 18 - j, max_conti_num);
                    for (int i = 0; i < 20; i++) {
                        if (conti_nums[i] == max_conti_num)
                            printf(", ���� ���� ���ӵ� ���� ���� : % c ", conti_nums_s[i]);
                    }
                    printf("\n");
                    break;
                }
            }
        }

        //�밢�� �ѹ� ������ ���� ������ üŷ�ϱ��� �ʱ�ȭ
        for (int i = 0; i < 20; i++) {
            conti_nums[i] = 0;
            conti_nums_s[i] = 0;
        }
        t = 0;
        conti_num = 1;
        max_conti_num = 1;
    }

    return;
}

int main(void) {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            dot[i][j] = '+';
        }
    }
    printf("�浹(0-18) �鵹(0-18)\n");
    while (1) {
        board();
        number(); //���μ����ٿ����� ���� ����
        conti(); //���μ����ٿ��� ���� ���� ���ӵ� ���� ������ ����
        dagak(); //�밢������ ���� ���� ���ӵ� ���� ������ ����
        printf("-----------------------------------------------------------------------------------------------------------------\n");
    }
    return 0;
}