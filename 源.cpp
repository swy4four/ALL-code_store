//#include <stdlib.h>
//#include <conio.h>
//int W = 25, S, * m, z = 0, c = 1, r = 2, i, j;
//int sum(int v, int l) {
//    return (abs(v % W - (v + l) % W) - W + 1 && v + l >= 0 && v + l < S) &&
//        m[v] == m[v + l] ? 1 + sum(v + l, l) : 0;
//}
//int main() {
//    for (m = calloc(S = W * W, 4); r < 4 && c - 27; c = _getch() & 95) {
//        c - 68 || ++z, c - 65 || --z, c - 83 || (z += W), c - 87 || (z -= W);
//        if (z = (z + S) % S, system("cls"), i = 2, !c && !m[z])
//            for (m[z] = r ^= 3; j = i % 3 - 1 + i / 3 * W, i < 6; ++i)
//                sum(z, j) + sum(z, -j) > 3 && (r ^= 3, i = r += 4);
//        for (i = 0; i < S; ++i % W || _cprintf("%d\n", i / W))
//            _cprintf("%c%c", " >"[i == z], " 0@"[m[i]]);
//        for (i = 0; i < W; ++i)_cprintf(" %c", 97 + i);
//        _cprintf(r & 1 ? "\nWhite" : "\nBlack"), r < 4 || _cputs(" win!");
//    }
//}
//
///*
//adsw�ƶ����ո����ӣ�Esc�˳����ڷ����֣��ȴ�������Ļ�ʤ
//'@'�ǰ���,'O'�Ǻ���,'>'�ǹ��, ���Զ������̳ߴ�(W)
//��С�����Լ���(3�е�W)(�̶������1:1)
//*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int n = 1;//ȫ�ֺ���
int t = 1;
void ShowMap(int map[15][15], int* isblack, int win_or_not, int num) {//��ӡ����  ��ά����ĵ�һ���������ᣬ�ڶ������Ǻ���
    int i, j;
    int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    printf("   ");
    for (i = 0; i < 9; i++) { printf("%d  ", arr[i]); }
    for (i = 9; i < 15; i++) { printf("%d ", arr[i]); }
    printf("\n");
    for (i = 0; i < 9; i++) {
        printf("%d  ", arr[i]);
        for (j = 0; j < 15; j++)
        {
            if (map[i][j] == 0) {
                if (i == 0 && j == 0) { printf("��  "); }
                else if (i == 0 && j == 14) { printf("��"); }
                else if (i == 14 && j == 0) { printf("��  "); }
                else if (i == 14 && j == 14) { printf("��"); }
                else if (i == 0) { printf("��  "); }//i=0��0<j<14�����
                else if (i == 14) { printf("��  "); }//i=14,<0j<14�����
                else if (j == 0) { printf("��  "); }//0<i<14,j=0�����
                else if (j == 14) { printf("��"); }//0<i<14,j=14�����
                else { printf("��  "); }
            }
            else if (map[i][j] == 1) { printf("�� "); }//����
            else { printf("�� "); }//����
        }
        printf("\n");
    }
    for (i = 9; i < 15; i++) {
        printf("%d ", arr[i]);
        for (j = 0; j < 15; j++)
        {
            if (map[i][j] == 0) {
                if (i == 0 && j == 0) { printf("��  "); }
                else if (i == 0 && j == 14) { printf("��"); }
                else if (i == 14 && j == 0) { printf("��  "); }
                else if (i == 14 && j == 14) { printf("��"); }
                else if (i == 0) { printf("��  "); }//i=0��0<j<14�����
                else if (i == 14) { printf("��  "); }//i=14,<0j<14�����
                else if (j == 0) { printf("��  "); }//0<i<14,j=0�����
                else if (j == 14) { printf("��"); }//0<i<14,j=14�����
                else { printf("��  "); }
            }
            else if (map[i][j] == 1) { printf("�� "); }//����
            else { printf("�� "); }//����
        }
        printf("\n");
    }
    if (t == 1 || win_or_not == 1 || win_or_not == 2 || num == 225) { return; }//��һ������ʱ˵��˭���֣��Լ���ֹ��ӡʤ����ʱ�����'����������'
    else if (*isblack == 1) { printf("�������������:"); }
    else { printf("�������������:"); }
}
void Press_Error_Y_N_O(char* press) {//�ݹ麯���� �����ַ���ΪYNO�����
    if (n == 1) {
        printf("\n����������:");
        n++;
    }
    *press = _getch();
    if (*press == 'y' || *press == 'Y' || *press == 'n' || *press == 'N' || *press == 'o' || *press == 'O') {
        n = 1;
        return;
    }
    else { Press_Error_Y_N_O(press); }
}
void Press_Error_Y_N(char* press) {//�ݹ麯���� �����ַ���ΪYN�����
    if (n == 1) {
        printf("\n����������:");
        n++;
    }
    *press = _getch();
    if (*press == 'y' || *press == 'Y' || *press == 'n' || *press == 'N') {
        n = 1;
        return;
    }
    else { Press_Error_Y_N(press); }
}
int Win_or_not(int map[15][15], int x, int y) {//�ж�ʤ��
    int i, j;
    int temp = map[y][x];
    for (j = x - 4, i = y; j <= x; j++) {//i����,j����,x���� y����
        if (j >= 0 && j <= 10 && temp == map[i][j] && temp == map[i][j + 1] && temp == map[i][j + 2] && temp == map[i][j + 3] && temp == map[i][j + 4])
        {
            return map[y][x];
        }
    }//ˮƽ�������
    for (i = y - 4, j = x; i <= y; i++) {//i����,j����,x���� y����
        if (i >= 0 && i <= 10 && temp == map[i][j] && temp == map[i + 1][j] && temp == map[i + 2][j] && temp == map[i + 3][j] && temp == map[i + 4][j])
        {
            return map[y][x];
        }
    }//��ֱ�������
    for (j = x - 4, i = y - 4; j <= x, i <= y; j++, i++) {//i����,j����,x���� y����
        if (j >= 0 && j <= 10 && i >= 0 && i <= 10 && temp == map[i][j] && temp == map[i + 1][j + 1] && temp == map[i + 2][j + 2] && temp == map[i + 3][j + 3] && temp == map[i + 4][j + 4])
        {
            return map[y][x];
        }
    }//���������Ϸ������
    for (j = x - 4, i = y + 4; j <= x, i >= 1; j++, i--) {//i����,j����,x���� y����
        if (j >= 0 && j <= 10 && i >= 0 && i <= 10 && temp == map[i][j] && temp == map[i - 1][j + 1] && temp == map[i - 2][j + 2] && temp == map[i - 3][j + 3] && temp == map[i - 4][j + 4])
        {
            return map[y][x];
        }
    }//���������·������
    return 0;
}
void SetPoint(int map[15][15], int* isblack, int* win_or_not) {//ÿ��һ����setһ��
    int f, s;
    scanf_s("%d %d", &f, &s);
    int x = f - 1;//x���� y����
    int y = s - 1;
    if (x < 0 || y < 0 || x>14 || y>14) {
        printf("����ĵ�λ���������ڣ�����������:");
        SetPoint(map, isblack, win_or_not);
    }
    else if (map[y][x] != 0) {
        printf("��ǰλ���������ӣ�����������:");
        SetPoint(map, isblack, win_or_not);
    }
    else if (*isblack == 1) {
        *isblack = 2;
        map[y][x] = 1;//�������ӵ�λ�õĶ�ά����ֵΪ1
    }
    else {
        *isblack = 1;
        map[y][x] = 2;//�������ӵ�λ�õĶ�ά����ֵΪ1
    }
    *win_or_not = Win_or_not(map, x, y);
}
void PlayGame() {
    int map[15][15] = { 0 };//ȫ����ʼ��Ϊ0
    int a = 1;//��������
    int* isblack = &a;//ͨ��*isblack��ֵȷ��Ϊ�������
    int num = 0;//��¼�µ����Ӹ���
    ShowMap(map, isblack, 0, num);
    if (t == 1) {
        t++;
        printf("�������֣��������������:");
    };
    while (1)//ѭ������ֱ��һ��ʤ������ƽ��
    {
        int b = 0;
        int* win_or_not = &b;
        SetPoint(map, isblack, win_or_not);
        system("cls");
        num++;
        ShowMap(map, isblack, *win_or_not, num);
        if (*win_or_not == 1) {
            printf("����WIn!\n");
            break;
        }
        if (*win_or_not == 2) {
            printf("����WIN!\n");
            break;
        }
        if (num == 225) {
            printf("ƽ��");
            break;
        }
    }
    printf("�Ƿ��ٴν���һ����Ϸ?(x��y)��������o�����Բ鿴��Ϸ�����Լ���Ϸ����˵��\n");
    printf("������(y/n/o):");
    t = 1;
}
void Introduction() {
    printf("������ �����˶��ĵĲ�����������Ϸ��\n"
        "��������ȫ�������˶��Ὰ����Ŀ֮һ����һ�����˶��ĵĴ�������������Ϸ��\n"
        "������������Χ��ͨ�ã���һ�ִ�ͳ�����֣��������淨��\n"
        "һ����˫���ֱ�ʹ�úڰ���ɫ�����ӣ���������ֱ������ߵĽ�����ϣ����γ����������߻�ʤ��\n"
        "����һ�����Լ��γ��������߾��滻�Է�����һö���ӡ����滻�����ӿ��ԺͶԷ��������ӡ�������ȳ����������ӵ�һ��Ϊʤ��\n"
        "�������������֣����ٽ��ˣ�����Ȥζ������������ʤ������������ǿ˼ά������������������Ҹ��������������������ԡ�\n"
        "����Ϸ�ǰ��յ�һ���������˼·������\n");
    printf("�����������ʽ\n"
        "�������������һ��Ϊ�����꣬���Ϊ�����꣬��ͨ����������� �ո� ����������س�����ʽ������\n");
    printf("�Ƿ����һ����Ϸ��(y��n)������:");
    char* press;
    char temp = _getch();
    press = &temp;
    if (*press == 'n' || *press == 'N') { exit(0); }
    else if (*press == 'y' || *press == 'Y') {
        system("cls");
        PlayGame();
    }
    else {//������ֵ��ΪY��N��ʱ��
        Press_Error_Y_N(press);//ֱ������Y��N�Ž���
        if (*press == 'n' || *press == 'N') { exit(0); }
        if (*press == 'y' || *press == 'Y') {
            system("cls");
            PlayGame();
        }
    }
}
void RePlayGame() {//�ж��Ƿ��ٴν�����Ϸ

    while (1)
    {
        char* press;
        char temp = _getch();
        press = &temp;
        if (*press == 'n' || *press == 'N') { exit(0); }
        else if (*press == 'o' || *press == 'O') {
            system("cls");
            printf("������ �����˶��ĵĲ�����������Ϸ��\n"
                "��������ȫ�������˶��Ὰ����Ŀ֮һ����һ�����˶��ĵĴ�������������Ϸ��\n"
                "������������Χ��ͨ�ã���һ�ִ�ͳ�����֣��������淨��\n"
                "һ����˫���ֱ�ʹ�úڰ���ɫ�����ӣ���������ֱ������ߵĽ�����ϣ����γ����������߻�ʤ��\n"
                "����һ�����Լ��γ��������߾��滻�Է�����һö���ӡ����滻�����ӿ��ԺͶԷ��������ӡ�������ȳ����������ӵ�һ��Ϊʤ��\n"
                "�������������֣����ٽ��ˣ�����Ȥζ������������ʤ������������ǿ˼ά������������������Ҹ��������������������ԡ�\n");
            printf("�����������ʽ\n"
                "�������������һ��Ϊ�����꣬���Ϊ�����꣬��ͨ����������� �ո� �������س�����ʽ������\n"
                "����o�����Բ鿴��Ϸ�����Լ���Ϸ����˵����");
            printf("�Ƿ��ٴν���һ����Ϸ��\n");
            printf("������(y/n):");
        }
        else if (*press == 'y' || *press == 'Y') {
            system("cls");
            PlayGame();
        }
        else {
            Press_Error_Y_N_O(press);
            if (*press == 'n' || *press == 'N') { exit(0); }
            else if (*press == 'o' || *press == 'O') {
                system("cls");
                printf("������ �����˶��ĵĲ�����������Ϸ��\n"
                    "��������ȫ�������˶��Ὰ����Ŀ֮һ����һ�����˶��ĵĴ�������������Ϸ��\n"
                    "������������Χ��ͨ�ã���һ�ִ�ͳ�����֣��������淨��\n"
                    "һ����˫���ֱ�ʹ�úڰ���ɫ�����ӣ���������ֱ������ߵĽ�����ϣ����γ����������߻�ʤ��\n"
                    "����һ�����Լ��γ��������߾��滻�Է�����һö���ӡ����滻�����ӿ��ԺͶԷ��������ӡ�������ȳ����������ӵ�һ��Ϊʤ��\n"
                    "�������������֣����ٽ��ˣ�����Ȥζ������������ʤ������������ǿ˼ά������������������Ҹ��������������������ԡ�\n");
                printf("�����������ʽ\n"
                    "�������������һ��Ϊ�����꣬���Ϊ�����꣬��ͨ����������� �ո� �������س�����ʽ������\n"
                    "����o�����Բ鿴��Ϸ�����Լ���Ϸ����˵����");
                printf("�Ƿ��ٴν���һ����Ϸ��\n");
                printf("������(y/n):");
            }
            else if (*press == 'y' || *press == 'Y') { PlayGame(); }
        }
    }
}
int main()
{
    system("color 70");//(stdlib.h�µĺ���)�ı����̨��Ӱ��ǰ������ɫ
    Introduction();
    RePlayGame();
    return 0;
}