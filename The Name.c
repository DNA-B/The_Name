#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>		// ǥ�������
#include <stdlib.h>		// rand()
#include <time.h>		// random �ʱ�ȭ
#include <string.h>		// strcmp(): ���ڿ� ��
#include <conio.h>		// (Console in out)		kbhit(): Ű���� �Է� ���� _ ��1, ����0
#include <windows.h>	// Sleep(delay) -> 1000ms (1��): �Ͻ�����, system("cls"): �ܼ�â �����

#define delay 750
#define hDelay 150
#define sDelay 1000

// ������Ÿ�� ����
void title();

void name(char* user_name);

void stage0(char* user_name);
void stage1();
void stage2(char* user_name);
void stage3(char* user_name);
void stage4();
void stage5(char* user_name);
void stage6(char* user_name);
void stage7(char* user_name);
void stage8(char* user_name);

void common_fail();
void stage8_fail();
int choose_quiz(int quiz);
int quiz1(int which_quiz);
int quiz2(int which_quiz);
int quiz3(int which_quiz);
int quiz4(int which_quiz);
int quiz5(int which_quiz);
int quiz6(int which_quiz);
int quiz7(int which_quiz);
int quiz8(char* user_name, int which_quiz);

// ���� ���� ����
  // ���������� �õ� Ƚ��
int try1 = 1, try2 = 1, try3 = 1, try4 = 1, try5 = 1, try6 = 1, try7 = 1, try8 = 1;
int game_try = 1;	// ��ü �õ� Ƚ��

// ���� �Լ�
int main() {
	char user_name[100] = { '\0' };
	int answer = 0;
	
	title();

	name(user_name);

	stage0(user_name);
	while (1) {
		// Quiz1, Stage1
		answer = quiz1(choose_quiz(1));
		if (answer) {
			for (int i = 0; i < 3; i++) {
				printf("\n.\n"); Sleep(hDelay);
			}
			stage1();
		}
		else {
			common_fail();
			continue;
		}
		// Quiz2, Stage2
		answer = quiz2(choose_quiz(2));
		if (answer == 2) {
			for (int i = 0; i < 3; i++) {
				printf("\n.\n"); Sleep(hDelay);
			}
			stage2(user_name);
		}
		else {
			common_fail();
			continue;
		}
		// Quiz3, Stage3
		answer = quiz3(choose_quiz(3));
		if (answer == 1) {
			for (int i = 0; i < 3; i++) {
				printf("\n.\n"); Sleep(hDelay);
			}
			stage3(user_name);
		}
		else {
			common_fail();
			continue;
		}
		// Quiz5, Stage5
		answer = quiz4(choose_quiz(4));
		if (answer == 1) {
			for (int i = 0; i < 3; i++) {
				printf("\n.\n"); Sleep(hDelay);
			}
			stage4(user_name);
		}
		else {
			common_fail();
			continue;
		}
		// Quiz5, Stage5
		answer = quiz5(choose_quiz(5));
		if (answer == 1) {
			for (int i = 0; i < 3; i++) {
				printf("\n.\n"); Sleep(hDelay);
			}
			stage5(user_name);
		}
		else {
			common_fail();
			continue;
		}
		// Quiz6, Stage6
		answer = quiz6(choose_quiz(6));
		if (answer == 1) {
			for (int i = 0; i < 3; i++) {
				printf("\n.\n"); Sleep(hDelay);
			}
			stage6(user_name);
		}
		else {
			common_fail();
			continue;
		}
		// Quiz7, Stage7
		answer = quiz7(choose_quiz(7));
		if (answer == 1) {
			for (int i = 0; i < 3; i++) {
				printf("\n.\n"); Sleep(hDelay);
			}
			stage7(user_name);
		}
		else {
			common_fail();
			continue;
		}
		// Quiz8, Stage8(Ending)
		answer = quiz8(user_name, choose_quiz(8));
		if (answer == 1) {
			for (int i = 0; i < 3; i++) {
				printf("\n.\n"); Sleep(hDelay);
			}
			stage8(user_name);
		}
		else {
			stage8_fail();
			continue;
		}

		break;
	}
	printf("  ��  ��\n");	// ���α׷� ���� �˸��� �ڵ�
	printf("~(������)~\n");
	printf("������: ������ - �ڿ�, ������, ������, ������, Ȳ����");	// ������
	return 0;
}

// title UI
void title() {
	char bf = '\0';
	printf("\n==================================================================================================================================\n");
	printf("\n\n");
	printf("                   .                                .\n");
	printf("   @@@@@@&@@&&@@@@@=  *@:       +&#    #@@@@@@@@@@@@*           .@@#       &@@.\n");
	printf("    .     @@          :@#       *@:     .@*                      +@@&      =@#    :*#&#*.#&   *&: *&&#+  =#&&*=     .+#&&&#+.\n");
	printf("         .@@          =@@.::....*@=+     @%:====+*=              +@:=@*    =@*   @@+.  :#@@.  +@@@=. =@@@+: .=@@   @@=    .*@%\n");
	printf("         .@@         &@@@**+++++&@&+     @@+++++++:              @@:  #@+  :@+  @@       #@   :@*     @@      *@. @@###&&&&&@@\n");
	printf("         :@@          &@*       +@=      @&                     *@@    .@@=.@*  @@       *@:  :@#     @@      *@. @@         \n");
	printf("         .@@#        @@@        #@&    =#@@#*****+++*&#        +@@=      +@@@@  .@@*:.:+@@@&  =@@     @@      &@+  &@#=::=+&@&\n");
	printf("          =*.        **         .*:   .#+:..::==++**+.         :*:         *=     .=+**=  =   .*:     ++      =*.    :+***+:\n");
	printf("\n\n");
	printf("\n==================================================================================================================================\n");
	printf("\n\n                                                        Press Enter...");
	while (1) {
		if (_kbhit()) {
			// �̸� �Է� �� ���ۿ� �����ִ� ���ڰ� ���� scanf�� �ذ�
			fflush(stdin);
			scanf("%c", &bf);
			system("cls");
			return;
		}
	}
}

// ����� �̸� �Է� �Լ�
void name(char* user_name) {
	printf("\n======================================================= What's your name? ========================================================\n");
	printf("\n����� �̸��� �����ΰ���?\n\n�̸�: ");
	scanf("%s", user_name);
	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	system("cls");
	return;
}

// ���������� ��ȭ ��� �Լ�
void stage0(char* user_name) {
	printf("\n============================================================ Stage 0 =============================================================\n");
	Sleep(delay);
	printf("\n%s: .....�� ���� �����?\n", user_name);
	Sleep(delay);
	printf("\n\n�̱� ����: ����̱���.\n");
	Sleep(delay);
	printf("\n\n%s: ��... ��������?\n", user_name);
	Sleep(delay);
	printf("\n\n�̱� ����: ���� �� ���� �����Դϴ�.\n");
	Sleep(delay);
	printf("\n	��ſ��� ��Ź�帮�� ���� �� �־ ���� ����� �ҷ����ϴ�.\n");
	Sleep(delay);
	printf("\n	�̰��� �޼��Դϴ�. �� ��Ź�� ������� ������ �̰����� ���� �� �����ϴ�.\n");
	Sleep(delay);
	printf("\n\n%s: ��? ���� �׵������� �Ҹ���? ���� �� ���⼭ �������� ������ ������ �Ű��ϰھ�!\n", user_name);
	Sleep(delay);
	printf("\n\n�̱� ����: ��������ϴ�. ������ �ҿ���� �״ϱ��.\n");
	Sleep(delay);
	printf("\n\n%s: �϶�� ���� �� �Ƴ� ����?\n", user_name);
	Sleep(delay);
	printf("\n	[�֍֍� ��] ��ȭ�� ��Ż �����Դϴ�? �̰� ���� �Ҹ���?\n");
	Sleep(delay);
	printf("\n	���� �ô뿡 ��ȭ�� �� �Ǵ� ���� ����ٰ�! �峭ġ�� ��!\n");
	Sleep(delay);
	printf("\n\n�̱� ����: ���� �� ���� ���ذ� �ǽʴϱ�? ���⼭ ���� ����� �� �ϳ�,\n");
	Sleep(delay);
	printf("\n	�̰��� ������ ��� Ǫ�ø� �˴ϴ�.\n");
	Sleep(delay);
	printf("\n\n%s: (�ڵ����� �� �ǰ� ������ ������ ��û�� ���ܵ� ���� �� ����.\n", user_name);
	Sleep(delay);
	printf("\n	�̽�½�� ������ �ϴ��� �� �༮�� ���� ������ ���ۿ� ���ڱ�...)\n");
	Sleep(delay);
	printf("\n	�ϴ� �̾߱⸦ ����. �� �ڼ��ϰ� �����غ�.\n");
	Sleep(delay);
	printf("\n\n�̱� ����: �켱 �̰��� ���� �����ص帮��.\n");
	Sleep(delay);
	printf("\n	�� ���� ���� ������ ������ ���۵˴ϴ�.\n");
	Sleep(delay);
	printf("\n	�� 8���� ���� ������ ������ �濡�� �� ������ Ǯ�� �� �̴ϴ�.\n");
	Sleep(delay);
	printf("\n	�� ������ ��� Ǯ�� �� �⳪�� �޿��� ��� �� �ֽ��ϴ�.\n");
	Sleep(delay);
	printf("\n	������ ������ �� �� �ְڳ׿�. ������ ���� ������ ���� �̴ϴ�.\n");
	Sleep(delay);
	printf("\n\n%s: (�������� �Ұ����� �������� ����� �̰͹ۿ� ����.)\n", user_name);
	Sleep(delay);
	printf("\n	����. �� ���⸦ �޾�����.\n");
	Sleep(delay);
	printf("\n\n�̱� ����: �� �����ϼ̽��ϴ�. �׷� ���� �������� �����帮�ڽ��ϴ�.\n");
	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}
void stage1() {
	printf("\n================================================= Stage 1 _ Story: �������� ��ȭ =================================================\n");
	Sleep(delay);
	printf("\n�̱� ����: �׸��� �θ� ��ȭ �����Ͻó���? �ű⿡�� ����������� �ι��� ��������.\n");
	Sleep(delay);
	printf("\n	�״� �ڸ��佺�� ���̾����ϴ�.\n");
	Sleep(delay);
	printf("\n	������ ��Ȱ�� ������ �״� �ŵ��� �ڽ��� ���̷� ���� �����\n");
	Sleep(delay);
	printf("\n	���ݽ��� ������ �������� ����ų�,\n");
	Sleep(delay);
	printf("\n	���� ���� ���� �ϵ��� �ٸ� ������� �������ϴ� ��\n");
	Sleep(delay);
	printf("\n	���� ���� ���̴� ���� �����߽��ϴ�.\n");
	Sleep(delay);
	printf("\n	�г��� ���콺�� ���������� ���� ������ ���� ��,\n");
	Sleep(delay);
	printf("\n	�Ʒ����� �� ������� Ŀ�ٶ� ������ ������ �ϴ� ������ �����ϴ�.\n");
	Sleep(delay);
	printf("\n	������ ����, ������� ������ ������ �ص� ������ ����ؼ� �������ٴ� �̴ϴ�. \n");
	Sleep(delay);
	printf("\n	�ᱹ �ý������� ����ؼ� ������ ���� ������ �߽��ϴ�. ��������.\n");
	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}
void stage2(char* user_name) {
	printf("\n================================================ Stage 2 _ Story: �ұ��� ��ȸ��� ================================================\n");
	Sleep(delay);
	printf("\n�̱� ����: �̹��� ������ �̾߱⸦ �غ����.\n");
	Sleep(delay);
	printf("\n	'��ȸ'�� �ұ��� �ٽ� ����Դϴ�.\n");
	Sleep(delay);
	printf("\n	��ȸ��, ���� ��� �ִ� �ΰ��� ���� �ܼ��� �ϳ��� '��'�� �Ұ��մϴ�.\n");
	Sleep(delay);
	printf("\n	������ �� �ٸ� �ΰ����� �¾ �������� �ٸ� ���� ��� ����.\n");
	Sleep(delay);
	printf("\n	�츮�� '������'�� ��� ��ȸ�� ������ ��� ������\n");
	Sleep(delay);
	printf("\n	���� ���� �ݺ��� ������ �ʴ´ٰ� �մϴ�.\n");
	Sleep(delay);
	printf("\n	���� ��ȸ�� �������� �������� ǥ���ϴµ�,\n");
	Sleep(delay);
	printf("\n	������ ����콺�� ���� �� �� �ְ���.\n");
	Sleep(delay);
	printf("\n\n%s: (ù ��°�� ��ȭ�� �� ��°�� ����?)\n", user_name);
	Sleep(delay);
	printf("\n	��� ����, �и� �̾߱⸶�� ����Ǵ� ���� ���� �ž�.\n");
	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}
void stage3(char* user_name) {
	printf("\n=================================================== Stage 3 _ Story: �������� ====================================================\n");
	Sleep(delay);
	printf("\n�̱� ����: ����� ���ļ��踦 �ϳ���?\n");
	Sleep(delay);
	printf("\n\n%s: �׷� ��ǳ�� ���� �ϰھ�.\n", user_name);
	Sleep(delay);
	printf("\n\n�̱� ����: ���� �ʴ±���. �׷��� ������ ���� ���̰���.\n");
	Sleep(delay);
	printf("\n	���������� �˸� ���� ����� ���� �� ���� ���� �� �ϳ��Դϴ�.\n");
	Sleep(delay);
	printf("\n	������ ������ ������ ����� �� ���ܳ� �������� ������ ���� ���� �Ҽ����� �Ǿ�, \n");
	Sleep(delay);
	printf("\n	���� Ÿ�� �� �ӿ� ������ ���� �־� ���� �¿��,\n");
	Sleep(delay);
	printf("\n	�������� ū ��â�� �ޱ��� ������ ���� ��ų�\n");
	Sleep(delay);
	printf("\n	��, ��, ��, ���� ��� ���߿� �����ٰ� �մϴ�.\n");
	Sleep(delay);
	printf("\n	�� ������ ������ �ݺ��ȴٰ� �մϴ�.\n");

	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}
void stage4() {
	printf("\n================================================ Stage 4 _ Story: movie _ Memento ================================================\n");
	Sleep(delay);
	printf("\n�̱� ���� : �� ���ڰ� �־����ϴ�. ���ڿ��� �˳��� ���� �� �η��� ���� ��,\n");
	Sleep(delay);
	printf("\n	��������� �Ƴ��� �־����ϴ�.\n");
	Sleep(delay);
	printf("\n	�׷��� ���ڰ� ������ ���� �Ӹ��� ū �λ��� �԰� �Ǿ����ϴ�.\n");
	Sleep(delay);
	printf("\n	�׳��� ����, ���ڴ� ��� ������ ��︸ ���� ä,\n");
	Sleep(delay);
	printf("\n	�� ������ ������ 10�� �ֱ�� ������� �������� �޽��ϴ�.\n");
	Sleep(delay);
	printf("\n	���ڴ� ��ô ���������, �Ƴ��� ����� ��ȣ�� ������� ȣ���Ǵ� �� �;���,\n");
	Sleep(delay);
	printf("\n	�״� ��⸦ ���� �ڽ��� �� ���¸� Ȯ���غ�����\n");
	Sleep(delay);
	printf("\n	�Ƴ��� �¿�� ���� �����غ��ڴٰ� ���߽��ϴ�.\n");
	Sleep(delay);
	printf("\n\n	������ �ٷ� �� ���̾����ϴ�.\n");
	Sleep(delay);
	printf("\n	���� ����� �幮 �뱳�� ������, ����ġ�� �ٶ��� ������ �־����ϴ�.\n");
	Sleep(delay);
	printf("\n	������ �ݴ����� �����ϴ� ���ֿ��� ������ ���� ���߱���.\n");
	Sleep(delay);
	printf("\n	�ᱹ �� ������ ũ�� �浹�ϰ�, ���� ������ ���Ҵϸ� �Ĺ����ϴ�.\n");
	Sleep(delay);
	printf("\n	�Ƴ��� �� �ڸ����� ����߽��ϴ�.\n");
	Sleep(delay);
	printf("\n	���ڵ� ���� �������� ����� ����� ������ �˴ϴ�.\n");
	Sleep(delay);
	printf("\n	���ڴ� �Ƴ��� ���� �����ڿ��� ������ �� �غ� �մϴ�.\n");
	Sleep(delay);
	printf("\n	������ ���ڴ� ��� ��� �Ƴ��� ���� �������� �λ��� ��Ʈ�� ������Ұ�,\n");
	Sleep(delay);
	printf("\n	�����ڸ� ã�� ���м����մϴ�.\n");
	Sleep(delay);
	printf("\n	������ �������� �ٵ� �𸣰�.\n");
	Sleep(delay);
	printf("\n\n	����� ������ �̷����ϴ�.\n");
	Sleep(delay);
	printf("\n	ó������ ���ֿ��� ������ �������ϴ�.\n");
	Sleep(delay);
	printf("\n	�ܼ��� ������ �����̼����� �Ͼ ������ϴ�.\n");
	Sleep(delay);
	printf("\n	��� ��, ������� ���� �ӿ��� �׾�� �Ƴ��� ����\n");
	Sleep(delay);
	printf("\n	���ڴ� ������ ���� �������ϴ�.\n");
	Sleep(delay);
	printf("\n	���� ������ �Ƴ��� �׿��ٴ� ��å���� ������ ��� ���� �ʾҽ��ϴ�.\n");
	Sleep(delay);
	printf("\n	�׷��� ���ڴ� ������ �����ڸ� �����, �װ� �Ƴ��� �׿��ٰ� ��Ʈ�� ����մϴ�.\n");
	Sleep(delay);
	printf("\n	10�� �ڿ� �״� �ڽ��� ������ �Ƴ��� �׿��ٴ� ����� �ؾ���Ȱ�,\n");
	Sleep(delay);
	printf("\n	���� ��Ʈ ���� �������� �����̶� �Ͻ��ϴ�.\n");
	Sleep(delay);
	printf("\n	���ݵ� �״� �Ƴ��� ���� �����ڸ� ����ؼ� ã�� �ֽ��ϴ�.\n");
	Sleep(delay);
	printf("\n	�ڽ��� ���� �̱� �ӿ�����.\n");
	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}
void stage5(char* user_name) {
	printf("\n============================================= Stage 5 _ Story: �ؿ� ���� �� ������? ==============================================\n");
	Sleep(delay);
	printf("\n�̱� ����: �����մϴ�. ������ ��������.\n");
	Sleep(delay);
	printf("\n	��� �� ���� �����ϼ̰����� �� ����л��� ���̾����ϴ�.\n");
	Sleep(delay);
	printf("\n	�� �л��� ��� '�ؿ� ���� �� ������'��� �̾߱⸦ �����߾��..\n");
	Sleep(delay);
	printf("\n	��. ����� �˰� �ִ� �ٷ� �� �̾߱��Դϴ�.\n");
	Sleep(delay);
	printf("\n	ȣ���̿��Լ� ����ġ�ٰ�,\n");
	Sleep(delay);
	printf("\n	�ϴÿ��� ������ �������� Ÿ�� �ؿ� ���� �� �� ������ �̾߱��.\n");
	Sleep(delay);
	printf("\n	�װ� �ƽʴϱ�?\n");
	Sleep(delay);
	printf("\n	�� �����̴� ���ݵ� �ؿ� ���� �״�� ���� �ֺ��� �ӹ��� �ִٰ� �ϴ±���.\n");
	Sleep(delay);
	printf("\n	���� ������ �л��� ����ı���?\n");
	Sleep(delay);
	printf("\n	��... �װ� �𸣰ڳ׿�. ��� �б��� ���� �ʾҰڽ��ϱ�. ������.\n");
	Sleep(delay);
	printf("\n==================================================================================================================================\n");
	Sleep(delay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}
void stage6(char* user_name) {
	printf("\n=============================================== Stage 6 _ Story: My favorite words ===============================================\n");
	Sleep(delay);
	printf("\n�̱� ����: ���� ������ ���� �ƴϳ׿�. ���� �� ���Դٰ� �� ������ �Ǵٴ�...\n");
	Sleep(delay);
	printf("\n	���� �̾������� �� ��������.\n");
	Sleep(delay);
	printf("\n	�׷��� �������� ����� �ʾ���?\n");
	Sleep(delay);
	printf("\n	��� ������ ���� ���� �����ϴ� �ܾ�� �� �ϳ��� �̿��� ��������.\n");
	Sleep(delay);
	printf("\n	����� ������ָ� ���ڳ׿�!\n");
	Sleep(delay);

	printf("\n\n%s: ���� ���� ����� ������ ����.\n", user_name);
	Sleep(delay);
	printf("\n	�� ���� ������ ���ؼ� ������ Ǯ ���̾�. �ʿ��� ���� ����.\n");
	Sleep(delay);

	printf("\n\n�̱� ����: ��? ��, �׷���. �׷��� ������ ģ���� �� �˾Ҵµ� �����ϳ׿�...\n");
	Sleep(delay);

	printf("\n==================================================================================================================================\n");
	Sleep(delay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}
void stage7(char* user_name) {
	printf("\n================================================ Stage 7 _ Story: I need a dollar ================================================\n");
	Sleep(delay);
	printf("\n�̱� ����: ��... �� ����...\n");
	Sleep(delay);
	printf("\n	���� ������ ������ ����, �԰� ���� ���ĵ�, ���� ���� ����\n");
	Sleep(delay);
	printf("\n	���ϴ� �� ��κ��� �� �� ���ݾƿ�.\n");
	Sleep(delay);
	printf("\n	�� ���� ������ ����. ���� ������ 1���̶� ������ ���� ��������\n");
	Sleep(delay);
	printf("\n	������ Ǯ�� �ʰ� ���� �� �ְ� ���ٰԿ�.\n");
	Sleep(delay);
	printf("\n	��, ���̶� �ƹ��͵� ����? �̰� �Ƿ��߱���. ��������.\n");
	Sleep(delay);
	printf("\n	�׳����� ��Ÿ����� �ƽʴϱ�? �׸��� �θ� ��ȭ�� ������ ���� �̸�����.\n");
	Sleep(delay);
	printf("\n	�� ���� ���ø� ������ ������ �Ҹ��� ���� �� �ִٰ� �ϳ׿�.\n");
	Sleep(delay);
	printf("\n	���� ������ �̰͵� �� �� �������?\n");
	Sleep(delay);

	printf("\n\n%s: ���� ���⿣ �־ ������ ������ '����'�� ������.\n", user_name);
	Sleep(delay);

	printf("\n\n�̱� ����: �̷�. �� �� �Ծ��׿�...\n");

	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}
void stage8(char* user_name) {
	printf("\n================================================ Stage 8 _ Story: What's my name? ================================================\n");
	printf("\n\"ö��\"\n");
	Sleep(delay);
	printf("\n������ ��ġ�� ��𼱰� ���� ������ �Ҹ��� ��ȴ�.\n");
	Sleep(delay);
	printf("\n���� ���� �̱� ������ �̼Ҹ� ���� �־���,\n");
	Sleep(delay);
	printf("\n���� �ʸӿ� �ִ� ���� ��¦ �����ִ�.\n");
	Sleep(delay);
	if (game_try == 1) {
		printf("\n\n%s: ���ϵ帳�ϴ�. �̸��� �˾Ƴ±���. ���� �� ������.\n", user_name);
		Sleep(delay);
		printf("\n	�̷��� ���� ���� ���̾�...\n");
		Sleep(delay);
		printf("\n	���� �˷��帱 ���� ���� ���� �����ߴµ� �����̱���.\n");
		Sleep(delay);
		printf("\n	����� �����ϱ� ���� �� ���׿�.\n");
		Sleep(delay);
	}
	else {
		printf("\n\n%s: ���ϵ帳�ϴ�. ���� �̸��� �˾Ƴ±���.\n", user_name);
		Sleep(delay);
		printf("\n	���� ���� ���� ����ߴµ� �׷��� �����̳׿�...\n");
		Sleep(delay);
		printf("\n	���� �˷��帱 ���� ���� ���� ������ �� �˾ҽ��ϴ�. \n");
		Sleep(delay);
		printf("\n	���� �����Դϴ�. �����ο�.\n");
		Sleep(delay);
	}
	printf("\n\nENDLESS: ��! �Կ� �ٸ� �Ҹ� ���� ��.\n");
	Sleep(delay);
	printf("\n	���� �� ���������� �̱��� �����±�.\n");
	Sleep(delay);
	printf("\n	�� �־��!!�ٽ� ������ ����!\n");
	Sleep(delay);
	printf("\n\n���� ���� �̱� ������ ������ �̼Ҹ� ����� ���� ���� �ش�.\n");
	Sleep(delay);
	printf("\n���� �޿��� ��� �� �־�!\n");
	Sleep(delay);
	printf("\n���� ������ �����Ͽ� �̱� ������ �ڿ� �ִ� ���� ���ߴ�.\n");
	Sleep(delay);
	printf("\n������ �Ѿ� ���� ���� �������� ����, ���� ������ �����.\n");
	Sleep(delay);
	printf("\n��°�� ������ �̱� ������ ���̴� ����?\n");
	Sleep(delay);
	printf("\n���̴� ������ 7�� �濡�� �� ������ �� �Ѿ���� ���� �����ϴ�.\n");
	Sleep(delay);
	printf("\n\nENDLESS: �� ����! ���� ����! ��ü �� ������ �װ� ���̴� ����?\n");
	Sleep(delay);
	printf("\n	��°�� �ٽ� ���ƿ� �ųİ�! ������ �������� �� �ž�?\n");
	Sleep(delay);
	printf("\n	������ �� Ǯ���ݾ�! � �� ���⼭ ��������!\n");
	Sleep(delay);
	printf("\n\n%s: ������������ ��ձ���.\n", user_name);
	Sleep(delay);
	printf("\n	�������̿�? ���ʿ� ���� ����� ���� �� �ִٰ� ���� ���� �����ϴ�.\n");
	Sleep(delay);
	printf("\n	�� ���� �ڴ�� ������ �� �������. ��... �󸶳� �������...\n");
	Sleep(delay);
	printf("\n	����� ���� �� �̸��� �θ� �������� ����� �� �̸��� ����߽��ϴ�.\n");
	Sleep(delay);
	printf("\n	�� �̱ÿ��� ���� ����ڰ� �� ������ ������ ��ٸ��� �־�� �Ѵٴ� ����.\n");
	Sleep(delay);
	printf("\n	����� ��Ҵ� ���� ���� �� ���Դϴ�.\n");
	Sleep(delay);
	printf("\n	����� �̸���, �׵��� ���� ��굵, �ΰ� ���赵 ���� ��� ���� ������.\n");
	Sleep(delay);
	printf("\n	�׷� �� ������ ã�� �������� �ϰڽ��ϴ�. ���ɷ� �ȳ��� ��ʽÿ�.\n");
	Sleep(delay);
	printf("\n\nENDLESS: ��������! �� !@#$^&�� �ƴϾ�! �� %s���!!!!!!!!!n\n", user_name);
	Sleep(delay);
	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}


// ���� Ʋ���� �� (Stage1~7)
void common_fail() {
	int fail = -1;
	system("cls");
	srand(time(NULL));
	fail = rand() % 3;		// 0, 1, 2
	if (game_try == 1)
		fail = 0;
	switch (fail) {
	case 0:
		for (int i = 0; i < 3; i++) {
			printf("\n.\n"); Sleep(hDelay);
		}
		printf("\n��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf(" "); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf(" "); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf(" "); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		for (int i = 0; i < 3; i++) {
			printf("."); Sleep(hDelay);
		}
		printf("\n");
		for (int i = 0; i < 3; i++) {
			printf("\n.\n"); Sleep(hDelay);
		}
		break;
	case 1:
		for (int i = 0; i < 3; i++) {
			printf("\n.\n"); Sleep(hDelay);
		}
		printf("\n��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf(" "); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf(" "); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf(" "); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("?\n"); Sleep(hDelay);
		for (int i = 0; i < 3; i++) {
			printf("\n.\n"); Sleep(hDelay);
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++) {
			printf("\n.\n");
			Sleep(hDelay);
		}
		printf("\n��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf(" "); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("��"); Sleep(hDelay);
		printf("!\n"); Sleep(hDelay);
		for (int i = 0; i < 3; i++) {
			printf("\n.\n"); Sleep(hDelay);
		}
		break;
	default:
		printf("\n??? error) common_fail ???\n");
	}
	printf("\n��ſ��� �ٽ� ��ȸ�� �帮��.\n"); Sleep(delay);
	game_try++;
	system("cls");
	return;
}
	// ���� Ʋ���� �� (stage8)
void stage8_fail() {
	int fail = -1;
	system("cls");
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}

	if (try8 == 2)
		fail = 0;
	else if (try8 == 3)
		fail = 1;
	else
		fail = 2;
	switch (fail) {
	case 0:
		printf("\n�̱� ����: ����� ���� �� �� �� �� ���� �Ŷ� �����ߴµ���...\n");
		Sleep(delay);
		printf("\n	�� ��밡 �ʹ� �Ǵ� �ǰ���?\n");
		Sleep(delay);
		printf("\n	��ȸ�� �� �� �� �帮��. �󸶳� �� ���� ��Ʈ�� ����� ����?\n");
		Sleep(delay);
		printf("\n	�̹��� ������ �����ϰ� Ǯ�� �ٶ��ϴ�.\n");
		Sleep(delay);
		break;
	case 1:
		printf("\n�̱� ����: ��ȸ�� �� ��µ��� �� ������ �̴ϱ�?\n");
		Sleep(delay);
		printf("\n	�׷��� ���� ��Ʈ�� ��ȴµ�����?\n");
		Sleep(delay);
		printf("\n	���� �� �����̶�� �� �غ�����.\n");
		Sleep(delay);
		printf("\n	���� ���������� �̷��� ģ���ϰ� ���� �ʽ��ϴ�.\n");
		Sleep(delay);
		break;
	case 2:
		printf("\n�̱� ����: ��ü �� ������ �Ǹ���Ű���� ����? ������ �� �ϴ� �ǰ�?\n");
		Sleep(delay);
		printf("\n	�Ӹ��ӿ� ��ü ���� ����淡 ������ �� ������ ����? �Ӹ��� ����ΰ�?\n");
		Sleep(delay);
		printf("\n	�����̶�� �� �� �϶� ���̾�, ������!!\n");
		Sleep(delay);
		break;
	default:
		printf("\n??? error) stage8_fail ???\n");
	}
	printf("\n��ſ��� �ٽ� ��ȸ�� �帮��.\n"); Sleep(delay);
	game_try++;
	system("cls");
	return;
}

// ���� ���� �Լ�
int choose_quiz(int quiz) {
	int which_quiz = -1;
	srand(time(NULL));
	which_quiz = rand() % 5;	// 0, 1, 2, 3, 4
	if (quiz == 1) {
		if (try1 == 1) {
			which_quiz = 0;
			try1++;
		}
	}
	else if (quiz == 2) {
		srand(time(NULL));
		which_quiz = rand() % 5;	// 0, 1, 2, 3, 4
		if (try2 == 1)
			which_quiz = 0;
		try2++;
	}
	else if (quiz == 3) {
		srand(time(NULL));
		which_quiz = rand() % 5;	// 0, 1, 2, 3, 4
		if (try3 == 1)
			which_quiz = 0;
		try3++;
	}
	else if (quiz == 4) {
		srand(time(NULL));
		which_quiz = rand() % 5;	// 0, 1, 2, 3, 4
		if (try4 == 1)
			which_quiz = 0;
		try4++;
	}
	else if (quiz == 5) {
		srand(time(NULL));
		which_quiz = rand() % 5;	// 0, 1, 2, 3, 4
		if (try5 == 1)
			which_quiz = 0;
		try5++;
	}
	else if (quiz == 6) {
		srand(time(NULL));
		which_quiz = rand() % 5;	// 0, 1, 2, 3, 4
		if (try6 == 1)
			which_quiz = 0;
		try6++;
	}
	else if (quiz == 7) {
		srand(time(NULL));
		which_quiz = rand() % 5;	// 0, 1, 2, 3, 4
		if (try7 == 1)
			which_quiz = 0;
		try7++;
	}
	else if (quiz == 8) {
		if (try8 == 1)
			which_quiz = 0;
		else if (try8 == 2)
			which_quiz = 1;
		else
			which_quiz = 2;
		try8++;
	}
	return which_quiz;
}

// ���������� ���� ��� �Լ�
int quiz1(int which_quiz) {
	int get1 = 0, answer = 0;
	printf("\n========================================================= Stage 1 _ Quiz =========================================================\n");
	printf("\n���� ���� �� ���� �ٴڿ� ���� ��ũ�� ������ �����־���.\n");
	Sleep(delay);
	printf("\n�ܾ� = ����? ������ �ǹ��ϴ� �ɱ�?\n");
	Sleep(delay);
	printf("\n�Ƹ� ����ǥ�� �� ���ڸ� �˾Ƴ��� �ϳ�����.\n");
	Sleep(delay);
	printf("\n�и� ������ ��Ģ�� �����ž�. �����غ���.\n");
	Sleep(delay);
	printf("\n������� ������ �̷� ������ Ǫ�� �ż����...\n");
	Sleep(delay);
	printf("\n���� �𸣰� ������� ���Դ�.\n");
	Sleep(delay);

	printf("\n\nQuiz) ?�� �� ����?\n");
	switch (which_quiz) {
	case 0:
		printf("\n���� = 0\n");
		printf("\n���� = 1\n");
		printf("\n���ѹα� = 4\n");
		printf("\n��ġ����� = 5\n");
		printf("\n����ǥ = ?\n");
		break;
	case 1:
		printf("\n�͸����Ǽ� = 0\n");
		printf("\n�޸��� = 1\n");
		printf("\n���ϸ��� = 0\n");
		printf("\n����ƮȨ = 2\n");
		printf("\n������ = ?\n");
		break;
	case 2:
		printf("\n������ġ = 4\n");
		printf("\n���������Ѷ� = 6\n");
		printf("\n���� = 1\n");
		printf("\n�ñر� = 3\n");
		printf("\nǥ������ = ?\n");
		break;
	case 3:
		printf("\n���̰��� = 2\n");
		printf("\n���ڵ� = 1\n");
		printf("\nƢ�� = 0\n");
		printf("\n�׹ʴ� = 1\n");
		printf("\nǥ������ = ?\n");
		break;
	case 4:
		printf("\nȫ���Ա��� = 1\n");
		printf("\n���� = 2\n");
		printf("\n���콺�е� = 2\n");
		printf("\n��ġ = 1\n");
		printf("\n�买 = ?\n");
		break;
	default:
		printf("\n??? error) quiz1 ???\n");
	}
	printf("\n\n���� (���ڸ� �Է�): ");
	scanf("%d", &get1);

	if ((which_quiz == 0 && get1 == 1) || (which_quiz == 1 && get1 == 2) || (which_quiz == 2 && get1 == 3) || (which_quiz == 3 && get1 == 1) || (which_quiz == 4 && get1 == 1)) {
		answer = 1;
	}

	printf("\n==================================================================================================================================\n");
	Sleep(delay);
	return answer;
}
int quiz2(int which_quiz) {
	char get2_1, get2_2, get2_3, answer = 0;
	char bro1[10] = { '\0' }, bro2[10] = { '\0' };
	printf("\n========================================================= Stage 2 _ Quiz =========================================================\n");
	printf("\n�� ���� �浵 ù ��° ��� �Ȱ��� �����̴�.\n");
	Sleep(delay);
	printf("\n�ٸ�... ���� ������ �ƴ϶� �� �����̴�.\n");
	Sleep(delay);
	printf("\n��, ������� �Ӹ��� ��������.\n");
	Sleep(delay);
	printf("\n������ �� ���⼭ ������ �Ѵ�.\n");
	Sleep(delay);
	printf("\n���� ���� �������� �˾ƺ���.\n");
	Sleep(delay);
	printf("\n������ �� �� ���� �� ����.\n");
	Sleep(delay);
	printf("\n\nQuiz)\n");
	switch (which_quiz) {
	case 0:
		printf("\nA: B �Ǵ� C�� ���������̾�.\n");
		printf("\nB: �� ���������̰� �ƴϾ�.\n");
		printf("\nC: A�� ���������̾�.\n");
		printf("\nD: A �Ǵ� B�� ���������̾�.\n");
		printf("\n\n�� �� ���������̴� 1���̴�. ���� �����ϱ�?\n");
		printf("\n����������: ");
		fflush(stdin);
		// ���� �Է� �� �ٳѱ��� %c�� ��� �Է¹޾����� scanf�� ���õƴ�.
		// %c �տ� ������ �־� �ذ��ߴ�.
		scanf(" %c", &get2_1);
		if (get2_1 == 'a' || get2_1 == 'A')
			answer = 2;
		break;
	case 1:
		printf("\nA: B, D �߿��� ���������̰� ����.\n");
		printf("\nB: ���� ���������̰� �ƴϾ�.\n");
		printf("\nC: D�� ���������̰� �ƴϾ�.\n");
		printf("\nD: B�� F �� �� ���� �� ���� ���������̾�.\n");
		printf("\nE: C�� D �߿��� ���������̰� �ּ� 1�� �־�.\n");
		printf("\nF: D�� ���������̾�.\n");
		printf("\n\n�� �� ���������̴� 2���̴�. ���� �����ϱ�?\n");
		printf("\n���������� 1: ");
		fflush(stdin);
		scanf(" %c", &get2_1);
		printf("���������� 2: ");
		fflush(stdin);
		scanf(" %c", &get2_2);
		if (((get2_1 == 'e' || get2_1 == 'E') && (get2_2 == 'f' || get2_2 == 'F')) || ((get2_1 == 'f' || get2_1 == 'F') && (get2_2 == 'e' || get2_2 == 'E')))
			answer = 2;
		break;
	case 2:
		printf("\n������ ���λ���� �Ͼ��.\n");
		printf("\n�����ڴ� �� 5������ A, B, C, D, E�� �ִ�.\n");
		printf("\n5�� �߿� 3���� ������ ���ϰ� 2���� ������ ���ϰ� �ִ�.\n");
		printf("\n������ ���ϴ� �� �� �� �� ���� �������� ������ �����������̰�,\n");
		printf("\n������ �� ���� �������̴�.\n");
		printf("\n�̵��� ������ ������ ����.\n");
		printf("\n\nA: D�� �����ھ�.\n");
		printf("\nB: �� ���˾�.\n");
		printf("\nC: E�� �����ڰ� �ƴϾ�.\n");
		printf("\nD: B�� �������ϴ� �ž�.\n");
		printf("\nE: B�� ���� ����̾�.\n");
		printf("\n���������̿� �����ڸ� ã�Ƽ� ���� ������ �Ѵ�.\n");
		printf("\n\n���������̿� �����ڴ� ���� �����ΰ�?\n");
		printf("\n����������: ");
		fflush(stdin);
		scanf(" %c", &get2_1);
		fflush(stdin);
		printf("������: ");
		scanf(" %c", &get2_2);
		if ((get2_1 == 'd' || get2_1 == 'D') && (get2_2 == 'a' || get2_2 == 'A'))
			answer = 2;
		break;
	case 3:
		printf("\n� �����ҿ��� �ݵ�� ������ ���ϴ� ����� ������ ���ϴ� ����� �ִ�.\n");
		printf("\n������ �����ڸ� ������ ���縦 �ֱ� ���� �˼��鿡��\n");
		printf("\n���� �����������̰� ���� ���������� ���϶�� �ߴ�.\n");
		printf("\n�׷����� � ������� 3���� �̿� ���� ���ߴ�.\n");
		printf("\nA: B�� �����������Դϴ�. ���� �������̱� ������ ���Ǹ��� ���մϴ�.\n");
		printf("\nB: C�� �����������Դϴ�. ���߸��� �������Դϴ�.\n");
		printf("\nC: A, B�߸��� �����������Դϴ�. ���� ���� �������Դϴ�.\n");
		printf("\n\n���� ���� ������ ���ϰ� �ִ� ���ϱ�?\n");
		printf("\n������: ");
		scanf(" %c", &get2_1);
		if (get2_1 == 'b' || get2_1 == 'B')
			answer = 2;
		break;
	case 4:
		printf("\n� ���� �� ���� �� ���� �־����ϴ�.\n");
		printf("\n�� 6���� ���� A,B,C,D,E,F �� �ϰڽ��ϴ�.\n");
		printf("\n(������ ���� ���������� �Ҹ�)\n");
		printf("\n�� 6�� �� 3���� �׻� ������ ���ϰ�, ������ 3���� �׻� �������� �մϴ�.\n");
		printf("\n�� ��� ������ �ּ� 1���� ���������̰� �ֽ��ϴ�.\n");
		printf("\n�Ʒ��� �������� ������ ���� �����̰�\n");
		printf("\n���������̿� ������ ����� ���� �������� ����������.\n");
		printf("\nA: �� ������ �� �� ���������̴�.\n");
		printf("\nB: �� ������ �� �� ������ ����̴�.\n");
		printf("\nC: A�� B�� ���� �� ���������̴�.\n");
		printf("\nD: ���� C�� ������.\n");
		printf("\nE: ���� B�� ������.\n");
		printf("\nF: E�� ������ ����̴�.\n");
		printf("\n\n������ �� �־� ���� ���� �빮�ڷ�, ���ĺ� ������ �Է����ּ���.\n");
		printf("\n���� 1: ");
		scanf("%s", bro1);
		printf("\n���� 2: ");
		scanf("%s", bro2);
		if (((!strcmp(bro1, "BDE")) && (!strcmp(bro2, "ACF"))) || ((!strcmp(bro1, "ACF")) && (!strcmp(bro2, "BDE"))))
			answer++;
		printf("\n\n���������̸� �� ����� ���ĺ� ������� �Է����ּ���.\n");
		printf("\n���������� 1: ");
		fflush(stdin);
		scanf(" %c", &get2_1);
		printf("\n���������� 2: ");
		fflush(stdin);
		scanf(" %c", &get2_2);
		printf("\n���������� 3: ");
		fflush(stdin);
		scanf(" %c", &get2_3);
		if ((get2_1 == 'a' || get2_1 == 'A') && (get2_2 == 'b' || get2_2 == 'B') && (get2_3 == 'd' || get2_3 == 'D'))
			answer++;
		break;
	default:
		printf("\n??? error) quiz2 ???\n");
	}
	printf("\n==================================================================================================================================\n");
	Sleep(delay);
	return answer;
}
int quiz3(int which_quiz) {
	int get3 = 0, answer = 0;
	printf("\n========================================================= Stage 3 _ Quiz =========================================================\n");
	printf("\n�̹� ���� �� Ư���ߴ�.\n");
	Sleep(delay);
	printf("\n���� �Ѱ���� å���� ������ �־���, �� ������ ..��?\n");
	Sleep(delay);
	printf("\n���� �־���!\n");
	Sleep(delay);
	printf("\n�ų��� ���� �ָӴϿ� ���ų��� ������ ������ �� ���� �ż��� �ĳ´�.\n");
	Sleep(delay);
	printf("\n�̱� ����: ���� ������ Ǯ�����ؼ� ���õ� �����Դϴ�.\n");
	Sleep(delay);
	printf("\n	������ ���� �̱� ���ε� �̷��� ���Ÿ� �Ͻó׿�. ����\n");
	Sleep(delay);
	printf("\n������ �Ҹ��� ���� ������. ����� ��⿴��. �������.\n");
	Sleep(delay);
	printf("\n¥���� �� ���� �տ� �� ���� ���� �־� �ٽ� å�� �������Ҵ�. ��Ҹ��� ����.\n");
	Sleep(delay);
	printf("\n���� �������� ���ο��� �����ϱ� �Ⱦ� ���Ҵ�.\n");
	Sleep(delay);
	printf("\n���� ��������, ���� ���� ������ ������ ���ܳ���.\n");
	Sleep(delay);
	printf("\n��� ������ ���� �ᱸ��. ���� �̿��� ������ Ǯ���.\n");
	srand(time(NULL));

	printf("\n\nQuiz)\n");
	switch (which_quiz) {
	case 0:
		printf("\n��� �������Կ� �մ��� 70����¥�� ���ָ� ���� 100�� ��¥�� ��ǥ�� ���о���.\n");
		printf("\n������ �ܵ��� ��� ������ ���� �������� �ٲ� �մԿ��� 30�� ���� ���־���.\n");
		printf("\n������ �������� �ε� ��ǥ��� ȯ���� �䱸�ϱ淡 100�� ���� �ٽ� �����־���.\n");
		printf("\n�������� ������ �� �� ���� ���غ�����?\n");

		printf("\n\n��(���� ���� ���ڸ� �Է��Ͻÿ�. ����: �� ��): ");

		scanf("%d", &get3);
		if (get3 == 100)
			answer++;
		break;
	case 1:
		printf("\n�� ģ���� �Ĵ翡 ���� ���� �� ���� ��� ���� �Ծ����ϴ�.\n");
		printf("\n3�� ���� ����Ϸ��µ� ���� �̺�Ʈ��� ������ ��õ ���� �������ϴ�.\n");
		printf("\n�׷��� õ ���� ���� �����ް�, ���� ��õ ���� ������ ��Ծ����ϴ�.\n");
		printf("\n������ ���� ���ڱ� �� ģ���� �̻��ϴٰ� ���߽��ϴ�.\n");
		printf("\n��? �� ����� õ ���� �����޾����ϱ� 9õ ���� 2�� 7õ �� ����, 2õ �� ���̽�ũ�� �Ծ����ϱ�\n");
		printf("\n2�� 9õ �����ݾ�? ������ õ ���� ���� ����?\n");

		printf("\n\n���� ���� �� ���� ���ÿ�.\n");
		printf("\n1. ���� 2. �Ǽ� 3. ��� 4. ������ ��Ģ\n");

		printf("\n��(���ڸ� �Է��Ͻÿ�): ");
		scanf("%d", &get3);

		if (get3 == 1)
			answer++;
		break;
	case 2:
		printf("\n��� ��������� � ����� 7�� ���� ��⸦ �԰� 10�� ��¥�� ��ǥ�� �´�.\n");
		printf("\n������ �ܵ��� ��� �������� �������� �ٲ� �� �մԿ��� 3�� ���� �Ž��� ���.\n");
		printf("\n������ �������� �ε���ǥ��� ȯ���� �䱸�ϱ淡 10�� ���� �ٽ� �����־���.\n");
		printf("\n����� ������ �� �� ���� ���غ�����?\n");
		printf("\n\n��(���� ���� ���ڸ� �Է��Ͻÿ�. ����: �� ��): ");

		scanf("%d", &get3);

		if (get3 == 10)
			answer++;
		break;
	case 3:
		printf("\nA�� B���� ���� 500���� ������ �� õ������ 970��¥�� ���ڸ� ���.\n");
		printf("\n�Ž����� 30������ A,B,�� ���� 10���� ���� ������.\n");
		printf("\n�׷��� A,B���� 490���� �����ǵ� 490+490 = 980������ ���� ���� �� 10���� �����ϸ� 990���̴�.\n");
		printf("\n������ 10���� ���� ������?\n");

		printf("\n\n���� ���� �� ���� ���ÿ�: ");
		printf("\n1. �Ǽ� 2. ��� 3. ���� 4. ������ ��Ģ\n");

		printf("\n��(���ڸ� �Է��Ͻÿ�): ");
		scanf("%d", &get3);

		if (get3 == 3)
			answer++;
		break;

	case 4:
		printf("\n��� ���������� �մ��� 50�� ����ġ ��⸦ ���� 100�� ��¥�� ��ǥ�� ���о���.\n");
		printf("\n������ �ܵ��� ��� ������ ���� �������� �ٲ� �մԿ��� 50�� ���� ���־���.\n");
		printf("\n������ �������� �ε� ��ǥ��� ȯ���� �䱸�ϱ淡 100�� ���� �ٽ� �����־���.\n");
		printf("\n�������� ������ �� �� ���� ���غ�����?\n");

		printf("\n\n��(���� ���� ���ڸ� �Է��Ͻÿ�. ����: �� ��): ");

		scanf("%d", &get3);


		if (get3 == 100)
			answer++;
		break;

	default:
		printf("\n??? error) quiz3 ???\n");
	}
	printf("\n==================================================================================================================================\n");

	Sleep(delay);
	return answer;
}
int quiz4(int which_quiz) {
	int get4 = 0, answer = 0;

	printf("\n========================================================= Stage 4 _ Quiz =========================================================\n");
	printf("\n�׹�° ���̴�.\n");
	Sleep(delay);
	printf("\nó�� ���� ���� ������ ����ϴ�.\n");
	Sleep(delay);
	printf("\n���� ù��° ��� ��Ģ�� �����Ÿ�...?\n");
	Sleep(delay);
	printf("\nù ��° ������ ��Ģ���� ������ Ǯ���...\n");
	Sleep(delay);
	printf("\n���� �湮�� ��½�� ���� ���� ä ���� �����ִ�...\n");
	Sleep(delay);
	printf("\n������... ���� ����ߴµ�...\n");
	Sleep(delay);
	printf("\n������ �Ҹ��� ���� ������. ����� ��⿴��. �������.\n");
	Sleep(delay);
	printf("\n����� ���ڱ� �������ٰ� �ݻ� ������� ���ƿԴ�.\n");
	Sleep(delay);
	printf("\n���� �������� ���ο��� �����ϱ� �Ⱦ� ���Ҵ�.\n");
	Sleep(delay);
	printf("\nó���� �������� ���ư� Ǫ�� �� �ۿ�...\n");
	Sleep(delay);

	printf("\n\nQuiz) ?�� �� ����?\n");
	switch (which_quiz) {
	case 0:
		printf("\n USE = 4\n");
		printf("\n SAY = 5\n");
		printf("\n LIV = 3\n");
		printf("\n UNI = 3\n");
		printf("\n DEV = ?\n");

		printf("\n\n��(���ڸ� �Է��Ͻÿ�): ");

		scanf("%d", &get4);
		if (get4 == 4) {
			answer++;
		}
		break;
	case 1:
		printf("\n CAT = 5\n");
		printf("\n SPA = 4\n");
		printf("\n VAT = 5\n");
		printf("\n DOG = 4\n");
		printf("\n DEER = ?\n");

		printf("\n\n��(���ڸ� �Է��Ͻÿ�): ");

		scanf("%d", &get4);
		if (get4 == 7) {
			answer++;
		}
		break;
	case 2:
		printf("\n SKY = 6\n");
		printf("\n MOU = 3\n");
		printf("\n KOR = 6\n");
		printf("\n ACE = 5\n");
		printf("\n DIA = ?\n");

		printf("\n\n��(���ڸ� �Է��Ͻÿ�): ");

		scanf("%d", &get4);
		if (get4 == 4) {
			answer++;
		}
		break;
	case 3:
		printf("\n DIS = 3\n");
		printf("\n ATM = 5\n");
		printf("\n JUST= 5\n");
		printf("\n ARM = 5\n");
		printf("\n CUP= ?\n");

		printf("\n\n��(���ڸ� �Է��Ͻÿ�): ");

		scanf("%d", &get4);
		if (get4 == 3) {
			answer++;
		}
		break;

	case 4:
		printf("\n RED = 5\n");
		printf("\n BLUE = 5\n");
		printf("\n LOW = 3\n");
		printf("\n LPG = 4\n");
		printf("\n PUB = ?\n");

		printf("\n\n��(���ڸ� �Է��Ͻÿ�): ");

		scanf("%d", &get4);
		if (get4 == 3) {
			answer++;
		}
		break;
	default:
		printf("\n??? error) quiz4 ???\n");
	}
	printf("\n==================================================================================================================================\n");

	Sleep(delay);
	return answer;
}
int quiz5(int which_quiz) {
	int answer = 0;
	char get5[100] = { '\0' };

	printf("\n========================================================= Stage 5 _ Quiz =========================================================\n");
	printf("\n�̹� ���� �л��� �� ���� ���δ�.\n");
	Sleep(delay);
	printf("\nå�� ������ ������ ���� �� ��, ���޾�ǰ, ���� ���߱��� �־���,\n");
	Sleep(delay);
	printf("\nå���̿��� ���� ���� ��� �������� ����θ� ä�� ���� ���� ���� å���� ���� �ִ�.\n");
	Sleep(delay);
	printf("\n�� �濡 ������ ����� ��â������ ��������.\n");
	Sleep(delay);
	printf("\n�ƹ��� ������ �����ص� �̱� �� ���� �༮�� �־���.\n");
	Sleep(delay);
	printf("\n�߾��� ȸ���ϸ� ���� �ѷ����ٰ�\n");
	Sleep(delay);
	printf("\n�ٴڿ� ������ �ִ� 6���� ���ܾ� ī�带 �߰��ߴ�.\n");
	Sleep(delay);
	printf("\n�ܾ� ī�带 �ֿ� ������� �����Ϸ��µ�,\n");
	Sleep(delay);
	printf("\n�� �� �� ���� �ٴڿ� �������� ���� ��ũ�� ����� �۾��� �� ������ �ʾҴ�.\n");
	Sleep(delay);
	printf("\n���� �������� ī�尡 �ణ ����ؼ� ���谨�� ��������.\n");
	Sleep(delay);
	printf("\n���� ������ ���ϴ� ������ ��� �Է��� �� �ִ� ������ ���õ� �ִ�.\n");
	Sleep(delay);
	printf("\n�ջ�� ī���� �ܾ ���� ������ ���ϴ� ������ �� ����.\n");
	Sleep(delay);

	printf("\n\nQuiz)\n");
	switch (which_quiz) {
	case 0:
		printf("\nbear\n");
		printf("\nsnow\n");
		printf("\nticket\n");
		printf("\nsong\n");
		printf("\ndoor\n");
		printf("\n??????\n");

		printf("\n\n�ջ�� ī���� �ܾ��? (�ҹ��ڷ� �Է�)\n");
		scanf("%s", &get5);
		if (!strcmp(get5, "ticket"))
			answer++;
		break;
	case 1:
		printf("\ball\n");
		printf("\npalace\n");
		printf("\nwhole\n");
		printf("\nLOL\n");
		printf("\nluck?\n");
		printf("\n????\n");

		printf("\n\n�ջ�� ī���� �ܾ��? (�ҹ��ڷ� �Է�)\n");
		scanf("%s", &get5);
		if (!strcmp(get5, "rule"))
			answer++;
		break;
	case 2:
		printf("\soup\n");
		printf("\nrice paddy\n");
		printf("\nroom\n");
		printf("\nmol\n");
		printf("\neye\n");
		printf("\n????\n");

		printf("\n\n�ջ�� ī���� �ܾ��? (�ҹ��ڷ� �Է�)\n");
		scanf("%s", &get5);
		if (!strcmp(get5, "song"))
			answer++;
		break;
	case 3:
		printf("\nbear\n");
		printf("\ndoor\n");
		printf("\nball\n");
		printf("\nsoup\n");
		printf("\nrice paddy\n");
		printf("\n????\n");
		printf("\n\n�ջ�� ī���� �ܾ��? (�ҹ��ڷ� �Է�)\n");
		scanf("%s", &get5);
		if (!strcmp(get5, "luck"))
			answer++;
		break;
	case 4:
		printf("\nsnow\n");
		printf("\nroom\n");
		printf("\nmol\n");
		printf("\nluck\n");
		printf("\nsong\n");
		printf("\n????\n");

		printf("\n\n�ջ�� ī���� �ܾ��? (�ҹ��ڷ� �Է�)\n");
		scanf("%s", &get5);
		if (!strcmp(get5, "ball"))
			answer++;
		break;
	default:
		printf("\n??? error) quiz5 ???\n");
	}

	printf("\n==================================================================================================================================\n");
	Sleep(delay);
	return answer;
}
int quiz6(int which_quiz) {
	int answer = 0;
	int get6 = 0;

	printf("\n========================================================= Stage 6 _ Quiz =========================================================\n");
	printf("\n���� ���� ���� ���� ���鿡�� ���ĺ��� ���ڰ� ¦������ �־���.\n");
	Sleep(delay);
	printf("\n�Ʊ� �浵 �׷��� �� �̷��� ��� ���� ��������...\n");
	Sleep(delay);
	printf("\n���� �������� �������� �����Ѵ�.\n");
	Sleep(delay);
	printf("\n���� �ﷷ�Ÿ��� �������� �� ����� ���� �ʴ�.\n");
	Sleep(delay);
	printf("\n���� ���� ������ �� ������� �� ������� ���ڴ�.\n");
	Sleep(delay);
	printf("\n���� ������ ���� ������ ���ĺ��� ����ǥ�� ¦������ �ִ�.\n");
	Sleep(delay);
	printf("\n�ƹ����� ����ǥ�� �� ���ڸ� �˾Ƴ��� �� �� ����.\n");

	printf("\n\nQuiz)\n");
	switch (which_quiz) {
	case 0:
		printf("\ns = 3\n");
		printf("\nm = 1\n");
		printf("\ne = 5\n");
		printf("\na = 2\n");
		printf("\nt = 4\n");
		printf("\nr = ?\n");

		printf("\n\n����ǥ�� �� ���ڴ�? ");

		scanf("%d", &get6);
		if (get6 == 6)
			answer++;
		break;
	case 1:
		printf("\nt = 35\n");
		printf("\na = 4\n");
		printf("\nn = 8\n");
		printf("\nr = 1\n");
		printf("\ni = 6\n");
		printf("\no = ?\n");

		printf("\n\n����ǥ�� �� ���ڴ�? ");

		scanf("%d", &get6);
		if (get6 == 27)
			answer++;
		break;
	case 2:
		printf("\nd = 4\n");
		printf("\na = 5\n");
		printf("\nr = 28\n");
		printf("\ne = 3\n");
		printf("\no = 7\n");
		printf("\nt = 6\n");
		printf("\np = ?\n");

		printf("\n\n����ǥ�� �� ���ڴ�? ");

		scanf("%d", &get6);
		if (get6 == 1)
			answer++;
		break;
	case 3:
		printf("\nd = 1\n");
		printf("\na = 4\n");
		printf("\nm = 5\n");
		printf("\ng = 8\n");
		printf("\nr = 2\n");
		printf("\nn = 7\n");
		printf("\ne = 3\n");
		printf("\ni = ?\n");

		printf("\n\n����ǥ�� �� ���ڴ�? ");

		scanf("%d", &get6);
		if (get6 == 6)
			answer++;
		break;
	case 4:
		printf("\no = 2\n");
		printf("\nf = 1\n");
		printf("\ne = 46\n");
		printf("\nv= 5 \n");
		printf("\nr = ??\n");

		printf("\n\n����ǥ�� �� ���ڴ�? ");

		scanf("%d", &get6);
		if (get6 == 37)
			answer++;
		break;
	default:
		printf("\n??? error) quiz6 ???\n");
	}

	printf("\n==================================================================================================================================\n");
	Sleep(delay);
	return answer;
}
int quiz7(int which_quiz) {
	int get7 = 0, answer = 0;

	printf("\n========================================================= Stage 7 _ Quiz =========================================================\n");
	printf("\n�̹� �濡���� ���� ������ ����´�. ��� ��� �� ������ ���ڱ� �� �����̶�?\n");
	Sleep(delay);
	printf("\n'I need~ a dollar, dollar, a dollar is what I need~ Hey Hey~'\n");
	Sleep(delay);
	printf("\n���� �޿� ������ �� �����ߴ� �뷡��.\n");
	Sleep(delay);
	printf("\n�и� �����ϰ� ���� �����ε� ���� �𸣰� �����ϰ� �������� ��\n");
	Sleep(delay);
	printf("\n�̱��� ������ ſ�̷���?\n");
	Sleep(delay);
	printf("\n�� �̰����� Ż���ؼ� ���ǿ��� �� �뷡�� ��� �ʹ�.\n");
	Sleep(delay);
	printf("\n�ƴ��� ħ�뿡 ���� �� �뷡�� ��� ������ �� �����ٵ�...\n");
	Sleep(delay);
	printf("\n������ ������ ���� ���� ���� ������ ã�´�.\n");
	Sleep(delay);
	printf("\n���� �������� ���ο��� �����ϱ� �Ⱦ� ���Ҵ�.\n");
	Sleep(delay);
	printf("\n�� ���� ������� �ʾ� ���̴� ���ĵ��� �ִ�.\n");
	Sleep(delay);
	printf("\n������ ������ ���� ���ϸ� �Ǵ� �Ű���?\n");
	Sleep(delay);

	printf("\n\nQuiz)\n");
	switch (which_quiz) {
	case 0:
		printf("\n500 - 50 = 5\n");
		printf("\n100 - 20 = 4\n");
		printf("\n500 - 20 = 8\n");
		printf("\n100 - 50 = 1\n");
		printf("\n500 - 80 = ?\n");

		printf("\n\n����ǥ�� �� ���ڴ�?: ");

		scanf("%d", &get7);
		if (get7 == 6)
			answer++;
		break;
	case 1:
		printf("\n500 + 50 = 2\n");
		printf("\n100 + 20 = 3\n");
		printf("\n500 + 20 = 3\n");
		printf("\n100 + 50 = 2\n");
		printf("\n500 + 80 = ?\n");

		printf("\n\n����ǥ�� �� ���ڴ�?: ");

		scanf("%d", &get7);
		if (get7 == 5)
			answer++;
		break;
	case 2:
		printf("\n12 X 5 = 2\n");
		printf("\n36 X 5 = 5\n");
		printf("\n10 X 10 = 1\n");
		printf("\n25 X 10 = 3\n");
		printf("\n35 X 12 = ?\n");

		printf("\n\n����ǥ�� �� ���ڴ�?: ");

		scanf("%d", &get7);
		if (get7 == 6)
			answer++;
		break;
	case 3:
		printf("\n4200 / 10 = 6\n");
		printf("\n4500 / 5 = 5\n");
		printf("\n3600 / 6 = 2\n");
		printf("\n4800 / 6 = 4\n");
		printf("\n5050 / 101 = ?\n");

		printf("\n\n����ǥ�� �� ���ڴ�?: ");

		scanf("%d", &get7);
		if (get7 == 1)
			answer++;
		break;

	case 4:
		printf("\n500 - 20 = 8\n");
		printf("\n100 + 20 = 3\n");
		printf("\n10 X 10 = 1\n");
		printf("\n4800 / 6 = 4\n");
		printf("\n100 + 400 = ?\n");

		printf("\n\n����ǥ�� �� ���ڴ�?: ");

		scanf("%d", &get7);
		if (get7 == 1)
			answer++;
		break;
	default:
		printf("\n??? error) quiz7 ???\n");
	}

	printf("\n==================================================================================================================================\n");
	Sleep(delay);
	return answer;
}
int quiz8(char* user_name, int which_quiz) {
	int answer = 0;
	char input[100] = { '\0' };
	printf("\n========================================================= Stage 8 _ Quiz =========================================================\n");
	switch (which_quiz) {
	case 0:
		printf("\n�̹� �濡�� �ȶ��غ��̴� ���İ� �־���,\n");
		Sleep(delay);
		printf("\n���� ���̺� ������ ������ ���� �غ�Ǿ� �־���.\n");
		Sleep(delay);
		printf("\n\n%s (���� ������ ���ΰ�... �ϴ� ����.)\n", user_name);;
		Sleep(delay);
		printf("\n\n7���� ���� �������� ��ĥ��� ��ģ ���� �������� �ð��.\n");
		Sleep(delay);
		printf("\n\n�̱� ����: �濡 � ��ġ�� ���������� �� �˰� �׷��� ������ �����ϱ�?\n");
		Sleep(delay);
		printf("\n\n�Ʊ� ������ �ص� �ƹ��� �ɾ����� �ʴ� ������ ���Ŀ�\n");
		Sleep(delay);
		printf("\n������ΰ� �̱� ������ �ͼ� �ɾ��ִ�.\n");
		Sleep(delay);
		printf("\n\n%s: ���� ���� ���� ������ �̷��� ����ϰ� �ִٰ� ������? ������ �� �ƴϸ� ���� ��.\n", user_name);;
		Sleep(delay);
		printf("\n\n�̱� ����: �׷��Կ�. �׷��� ������ �����̴ϸ�ŭ, ���� ���� �����ϱ�� �߽��ϴ�.\n");
		Sleep(delay);
		printf("\n\n%s: �׷�. � ������ ����.\n", user_name);
		Sleep(delay);
		printf("\n	������ ������ Ǯ�� �� ��̵� ���� ���������� ���� ���� ���߰ھ�.\n");
		Sleep(delay);
		printf("\n\n�̱� ����: ���� �׷��� ����� �־� ���� ����־����ϴٸ�...\n");
		Sleep(delay);
		printf("\n	��, �׷��� ���Ͻô� �ٷ� ���ص帮�ڽ��ϴ�.\n");
		Sleep(delay);
		printf("\n	������ ������ �ٷ� �� �̸��� ������ ���Դϴ�.\n");
		Sleep(delay);
		printf("\n	���ݱ��� Ǯ��� ������ ���� �ߴ� ������ �� ���þ�ʽÿ�. \n");
		Sleep(delay);
		printf("\n	���� �������� �� ���� �̴ϴ�.\n");
		Sleep(delay);
		printf("\n\n%s: ��? ���� �Ҹ���? ���� �� �̸��� ��� �˾�!!\n", user_name);
		Sleep(delay);
		printf("\n\n�̱� ����: �� �𸣽ðڴٸ� ������ ó������ �ٽ� Ǯ�� �Ǵ� ���Դϴ�.\n");
		Sleep(delay);
		printf("\n\n%s: ���� ���ݱ��� �󸶳� ����� Ǯ���µ� �װ� �ٽ� Ǯ���? ������ ��!\n", user_name);
		Sleep(delay);
		printf("\n\n�̱� ����: �׷��ϱ� �� �����غ��ʽÿ�. ���� �и� ����� ��Ʈ�� ��Ƚ��ϴ�.\n");
		Sleep(delay);
		printf("\n	��, ���������� ��Ʈ�� �ϳ� �� �帮��.\n");
		Sleep(delay);
		printf("\n	�� �̸��� �����Դϴ�. ��� ������ ���ڴ� �����. ����� ����.\n");
		break;
	case 1:
		printf("\n�ͼ��� ǳ���̴�. ���� 2���� ���� ���̺�, ������ ���� �غ�Ǿ� �ִ�.\n");
		Sleep(delay);
		printf("\n������ ���� ���� ���� ���� �ٽ� �غ��� ���� ���ϴ�.\n");
		Sleep(delay);
		printf("\n�� �̱ÿ��� �����ϰ� �޽��� ���� �� �־� ���̴� ��������,\n");
		printf("\n������ ���� ¥�����⸸ �Ѵ�.\n");
		Sleep(delay);
		printf("\n\n�̱� ����: �ð��� �Ʊ�����. ������ �Ʊ�� �����ϴ�. �� �̸��� ���ϸ� �ſ�.\n");
		Sleep(delay);
		printf("\n\n%s: �׷��ϱ�... ����θ� �̷���������?\n", user_name);
		Sleep(delay);
		printf("\n\n�̱� ����: ��... �׷����ϴ�. �� ������ Ǯ���ֽðھ��?\n");
		Sleep(delay);
		printf("\n\n%s: (������ �� ���п� ��վ��ٸ鼭 �� �¼���ȯ�� ����...)\n", user_name);
		Sleep(delay);
		printf("\n\n�̱� ����: ����� ���� �� �̸��� ���Ͻʽÿ�. ��.\n");
		Sleep(delay);
		printf("\n\n%s: �¾Ҵµ� Ʋ�ȴٰ� �ϸ� �� �ȴ�?!\n", user_name);
		Sleep(delay);
		printf("\n\n�̱� ����: �׷� ���� �����ϴ�!! ������ �����ϼ���!!!!!\n");
		Sleep(delay);
		break;
	case 2:
		printf("\n�Ʊ�� ������ ���� ǳ���̴�. �̰����� ���� �� ������...\n");
		Sleep(delay);
		printf("\n\n�̱� ����: ��... ����̶� �����...\n");
		printf("\n	����ü �󸶳� ���� ��ȸ�� �� ����� Ǯ �� �ִ� �̴ϱ�?\n");
		Sleep(delay);
		printf("\n	���� �ѽ��ϱ���... ����� �����ϴ� �� �ƴϾ���...\n");
		Sleep(delay);
		printf("\n\n%s: (����? ���ϰ� ���� ������ �����⸦ �ٶ�� �� ����. �ڽ��� �� �������鼭 ��ü ��?)\n", user_name);
		Sleep(delay);
		printf("\n\n�̱� ����: ������ �Ʊ�� �����ϴ�. �� ���� ���������ϱ���. ����� �� �� �̸��� ���ϼ���.\n");
		Sleep(delay);
		break;
	default:
		printf("\n??? error) quiz8 ???\n");
	}
	printf("\n\nQuiz) �̱� ������ �̸� (�빮�ڷ� �Է�): ");
	scanf("%s", input);
	if (!strcmp(input, "ENDLESS"))
		answer++;
	printf("\n==================================================================================================================================\n");
	Sleep(delay);
	return answer;
}
