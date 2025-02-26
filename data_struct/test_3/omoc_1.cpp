#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

char dot[19][19];
char black = 'O';
char white = 'X';
int count = 1;
int conti_nums[20];
char conti_nums_s[20];
//모든 가로줄 중 가장 많이 연속된 돌들을 찾기위한 변수
int all_conti_nums[100];
char all_conti_nums_s[100];
int all_max_conti_num = 1;
int all_conti_nums_num_x[100];
int all_conti_nums_num_y[100];


void board()
{
    int x, y;
    if (count % 2 == 1) {
        printf("흑돌의 좌표를 적으시오>>");
        scanf("%d %d", &x, &y);
        if (x > 18 || x < 0 || y > 18 || y < 0)
            return;
        if (dot[y][x] != '+') {
            printf("이미 돌이 놓여있습니다.\n");
            return;
        }
        dot[y][x] = black;
        count++;
    }
    else {
        printf("백돌의 좌표를 적으시오>>");
        scanf("%d %d", &x, &y);
        if (x > 18 || x < 0 || y > 18 || y < 0)
            return;
        if (dot[y][x] != '+') {
            printf("이미 돌이 놓여있습니다.\n");
            return;
        }
        dot[y][x] = white;
        count++;
    }
    system("cls");
    printf("[오목판] \n");
    printf("#1. 흑돌 O, 백돌 X\n#2. 흑돌(0-18), 백돌(0-18)\n#3. 가운데 가장 긴 대각선 기준 위쪽은 +n번째, 아래쪽은 -n번째 줄임\n");
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
    for (int i = 0; i < 19; i++) { //가로줄
        for (int j = 0; j < 19; j++) {
            if (dot[i][j] == 'O') {
                b_count++;
            }
            else if (dot[i][j] == 'X') {
                w_count++;
            }
        }
        if (b_count >= 1 || w_count >= 1)
            printf("가로 %2d번째 줄 - 흑돌 %d개, 백돌 %d개\n", i + 1, b_count, w_count);
        b_count = 0;
        w_count = 0;
    }

    for (int i = 0; i < 19; i++) { //세로줄
        for (int j = 0; j < 19; j++) {
            if (dot[j][i] == 'O') {
                b_count++;
            }
            else if (dot[j][i] == 'X') {
                w_count++;
            }
        }
        if (b_count >= 1 || w_count >= 1)
            printf("세로 %2d번째 줄 - 흑돌 %d개, 백돌 %d개\n", i + 1, b_count, w_count);
        b_count = 0;
        w_count = 0;
    }
    return;
}
void conti()
{
    int x = 0; //각각의 가로줄 배열 증가변수
    int y = 0; //모든 가로줄 배열 증가변수
    int conti_num = 1;
    int max_conti_num = 1;
    //모든 가로줄 체킹
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
        //넣은 배열에서 가장 큰수 찾기
        for (int i = 0; i < 20; i++) {
            if (conti_nums[i] == 0)
                break;
            if (conti_nums[i] > max_conti_num)
                max_conti_num = conti_nums[i];
        }

        for (int x = 0; x < 19; x++) {
            if (conti_nums[x] > 1) {
                if (conti_nums_s[x] != '+') {
                    printf("가로 %d번째 줄 - 가장 많이 연속된 돌의 개수 : %d", i + 1, max_conti_num);
                    for (int i = 0; i < 20; i++) {
                        if (conti_nums[i] == max_conti_num)
                            printf(", 가장 많이 연속된 돌의 종류 : % c ", conti_nums_s[i]);
                    }
                    printf("\n");
                    break;
                }
            }
        }

        //가로줄 한번 끝내고 다음 가로줄 체킹하기전 초기화
        for (int i = 0; i < 20; i++) {
            conti_nums[i] = 0;
            conti_nums_s[i] = 0;
        }
        x = 0;
        conti_num = 1;
        max_conti_num = 1;
    }




    //모든 세로줄 체킹
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
        //넣은 배열에서 가장 큰수 찾기
        for (int i = 0; i < 20; i++) {
            if (conti_nums[i] == 0)
                break;
            if (conti_nums[i] > max_conti_num)
                max_conti_num = conti_nums[i];
        }

        for (int x = 0; x < 19; x++) {
            if (conti_nums[x] > 1) {
                if (conti_nums_s[x] != '+') {
                    printf("세로 %d번째 줄 - 가장 많이 연속된 돌의 개수 : %d", i + 1, max_conti_num);
                    for (int i = 0; i < 20; i++) {
                        if (conti_nums[i] == max_conti_num)
                            printf(", 가장 많이 연속된 돌의 종류 : % c ", conti_nums_s[i]);
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

        max_conti_num = 1;  //세로줄 한번 끝내고 다음 세로줄 체킹하기전 초기화
        x = 0;
        conti_num = 1;
    }




    //모든 가로줄에서 가장 많이 연속으로 놓여진 돌들의 위치를 좌표를 표시

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
                        printf("같은 돌이 가장 많이 연속된 가로줄 : %d번째 줄, 돌의 종류 : % c, 돌의 개수 : %d, 시작 좌표(%d,%d), 마지막 좌표(%d,%d)\n"
                            , all_conti_nums_num_y[i] + 1, all_conti_nums_s[i], all_conti_nums[i], all_conti_nums_num_x[i] - all_conti_nums[i] + 1, all_conti_nums_num_y[i], all_conti_nums_num_x[i], all_conti_nums_num_y[i]);
                }
                break;
            }
        }
    }

    for (int i = 0; i < 100; i++) {  //모든 가로줄중 연속된 거 찾기 - 초기화
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
    //*****************우하향 대각선(가운데 기준 아래)********************
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
                    printf("우하향 대각선 -%d번째 줄 - 가장 많이 연속된 돌의 개수 : %d", i, max_conti_num);
                    for (int i = 0; i < 20; i++) {
                        if (conti_nums[i] == max_conti_num)
                            printf(", 가장 많이 연속된 돌의 종류 : % c ", conti_nums_s[i]);
                    }
                    printf("\n");
                    break;
                }
            }
        }

        //대각선 한번 끝내고 다음 가로줄 체킹하기전 초기화
        for (int i = 0; i < 20; i++) {
            conti_nums[i] = 0;
            conti_nums_s[i] = 0;
        }
        t = 0;
        conti_num = 1;
        max_conti_num = 1;
    }







    //*****************우하향 대각선(가운데 기준 위+가운데 줄)********************
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
                    printf("우하향 대각선 %d번째 줄 - 가장 많이 연속된 돌의 개수 : %d", j, max_conti_num);
                    for (int i = 0; i < 20; i++) {
                        if (conti_nums[i] == max_conti_num)
                            printf(", 가장 많이 연속된 돌의 종류 : % c ", conti_nums_s[i]);
                    }
                    printf("\n");
                    break;
                }
            }
        }

        //대각선 한번 끝내고 다음 가로줄 체킹하기전 초기화
        for (int i = 0; i < 20; i++) {
            conti_nums[i] = 0;
            conti_nums_s[i] = 0;
        }
        t = 0;
        conti_num = 1;
        max_conti_num = 1;
    }







    //*****************우상향 대각선(가운데 기준 아래)********************
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
                    printf("우상향 대각선 -%d번째 줄 - 가장 많이 연속된 돌의 개수 : %d", i, max_conti_num);
                    for (int i = 0; i < 20; i++) {
                        if (conti_nums[i] == max_conti_num)
                            printf(", 가장 많이 연속된 돌의 종류 : % c ", conti_nums_s[i]);
                    }
                    printf("\n");
                    break;
                }
            }
        }

        //대각선 한번 끝내고 다음 가로줄 체킹하기전 초기화
        for (int i = 0; i < 20; i++) {
            conti_nums[i] = 0;
            conti_nums_s[i] = 0;
        }
        t = 0;
        conti_num = 1;
        max_conti_num = 1;
    }







    //*****************우상향 대각선(가운데 기준 위+가운데 줄)********************
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
                    printf("우상향 대각선 %d번째 줄 - 가장 많이 연속된 돌의 개수 : %d", 18 - j, max_conti_num);
                    for (int i = 0; i < 20; i++) {
                        if (conti_nums[i] == max_conti_num)
                            printf(", 가장 많이 연속된 돌의 종류 : % c ", conti_nums_s[i]);
                    }
                    printf("\n");
                    break;
                }
            }
        }

        //대각선 한번 끝내고 다음 가로줄 체킹하기전 초기화
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
    printf("흑돌(0-18) 백돌(0-18)\n");
    while (1) {
        board();
        number(); //가로세로줄에서의 돌의 개수
        conti(); //가로세로줄에서 가장 많이 연속된 돌의 종류와 개수
        dagak(); //대각선에서 가장 많이 연속된 돌의 종류와 개수
        printf("-----------------------------------------------------------------------------------------------------------------\n");
    }
    return 0;
}