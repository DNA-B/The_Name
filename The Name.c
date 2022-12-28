#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>		// 표준입출력
#include <stdlib.h>		// rand()
#include <time.h>		// random 초기화
#include <string.h>		// strcmp(): 문자열 비교
#include <conio.h>		// (Console in out)		kbhit(): 키보드 입력 감지 _ 참1, 거짓0
#include <windows.h>	// Sleep(delay) -> 1000ms (1초): 일시정지, system("cls"): 콘솔창 지우기

#define delay 750
#define hDelay 150
#define sDelay 1000

// 프로토타입 선언
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

// 전역 변수 선언
  // 스테이지별 시도 횟수
int try1 = 1, try2 = 1, try3 = 1, try4 = 1, try5 = 1, try6 = 1, try7 = 1, try8 = 1;
int game_try = 1;	// 전체 시도 횟수

// 메인 함수
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
	printf("  △  △\n");	// 프로그램 끝을 알리는 코드
	printf("~(ㅇㅅㅇ)~\n");
	printf("제작자: 씨리얼 - 박완, 변성훈, 전선현, 조정훈, 황윤신");	// 제작자
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
			// 이름 입력 시 버퍼에 남아있는 문자가 들어가서 scanf로 해결
			fflush(stdin);
			scanf("%c", &bf);
			system("cls");
			return;
		}
	}
}

// 사용자 이름 입력 함수
void name(char* user_name) {
	printf("\n======================================================= What's your name? ========================================================\n");
	printf("\n당신의 이름은 무엇인가요?\n\n이름: ");
	scanf("%s", user_name);
	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	system("cls");
	return;
}

// 스테이지별 대화 출력 함수
void stage0(char* user_name) {
	printf("\n============================================================ Stage 0 =============================================================\n");
	Sleep(delay);
	printf("\n%s: .....음 여긴 어디지?\n", user_name);
	Sleep(delay);
	printf("\n\n미궁 주인: 깨어나셨군요.\n");
	Sleep(delay);
	printf("\n\n%s: 윽... 누구세요?\n", user_name);
	Sleep(delay);
	printf("\n\n미궁 주인: 저는 이 방의 주인입니다.\n");
	Sleep(delay);
	printf("\n	당신에게 부탁드리고 싶은 게 있어서 제가 당신을 불렀습니다.\n");
	Sleep(delay);
	printf("\n	이곳은 꿈속입니다. 제 부탁을 들어주지 않으면 이곳에서 나갈 수 없습니다.\n");
	Sleep(delay);
	printf("\n\n%s: 뭐? 무슨 뚱딴지같은 소리야? 당장 날 여기서 내보내지 않으면 경찰에 신고하겠어!\n", user_name);
	Sleep(delay);
	printf("\n\n미궁 주인: 상관없습니다. 어차피 소용없을 테니까요.\n");
	Sleep(delay);
	printf("\n\n%s: 하라면 못할 줄 아나 보지?\n", user_name);
	Sleep(delay);
	printf("\n	[띡띡띡 띡] 통화권 이탈 지역입니다? 이게 무슨 소리야?\n");
	Sleep(delay);
	printf("\n	요즘 시대에 전화가 안 되는 곳이 어딨다고! 장난치지 마!\n");
	Sleep(delay);
	printf("\n\n미궁 주인: 이제 제 말이 이해가 되십니까? 여기서 나갈 방법은 단 하나,\n");
	Sleep(delay);
	printf("\n	이곳의 문제를 모두 푸시면 됩니다.\n");
	Sleep(delay);
	printf("\n\n%s: (핸드폰도 안 되고 마땅히 구조를 요청할 수단도 없는 거 같다.\n", user_name);
	Sleep(delay);
	printf("\n	미심쩍긴 하지만 일단은 저 녀석의 말을 따르는 수밖에 없겠군...)\n");
	Sleep(delay);
	printf("\n	일단 이야기를 들어보지. 더 자세하게 설명해봐.\n");
	Sleep(delay);
	printf("\n\n미궁 주인: 우선 이곳에 대해 설명해드리죠.\n");
	Sleep(delay);
	printf("\n	이 문을 열고 나가면 문제가 시작됩니다.\n");
	Sleep(delay);
	printf("\n	총 8개의 방이 나오고 각각의 방에서 한 문제씩 풀게 될 겁니다.\n");
	Sleep(delay);
	printf("\n	이 문제를 모두 풀면 이 기나긴 꿈에서 깨어날 수 있습니다.\n");
	Sleep(delay);
	printf("\n	간단한 내기라고 할 수 있겠네요. 하지만 결코 쉽지는 않을 겁니다.\n");
	Sleep(delay);
	printf("\n\n%s: (누가봐도 불공평한 내기지만 방법이 이것밖에 없다.)\n", user_name);
	Sleep(delay);
	printf("\n	좋아. 그 내기를 받아주지.\n");
	Sleep(delay);
	printf("\n\n미궁 주인: 잘 생각하셨습니다. 그럼 다음 공간으로 보내드리겠습니다.\n");
	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}
void stage1() {
	printf("\n================================================= Stage 1 _ Story: 시지포스 신화 =================================================\n");
	Sleep(delay);
	printf("\n미궁 주인: 그리스 로마 신화 좋아하시나요? 거기에는 시지포스라는 인물이 등장하죠.\n");
	Sleep(delay);
	printf("\n	그는 코린토스의 왕이었습니다.\n");
	Sleep(delay);
	printf("\n	굉장히 교활한 성격의 그는 신들이 자신을 죽이려 보낸 사신을\n");
	Sleep(delay);
	printf("\n	감금시켜 죽음의 위협에서 벗어나거나,\n");
	Sleep(delay);
	printf("\n	신이 몰래 벌인 일들을 다른 사람에게 고자질하는 등\n");
	Sleep(delay);
	printf("\n	신을 골탕 먹이는 것을 좋아했습니다.\n");
	Sleep(delay);
	printf("\n	분노한 제우스는 시지포스를 높은 산으로 끌고 와,\n");
	Sleep(delay);
	printf("\n	아래에서 산 정상까지 커다란 바위를 굴려야 하는 형벌을 내립니다.\n");
	Sleep(delay);
	printf("\n	무서운 점은, 정상까지 바위를 굴린다 해도 밑으로 계속해서 떨어진다는 겁니다. \n");
	Sleep(delay);
	printf("\n	결국 시시포스는 계속해서 바위를 위로 굴려야 했습니다. 영원히요.\n");
	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}
void stage2(char* user_name) {
	printf("\n================================================ Stage 2 _ Story: 불교의 윤회사상 ================================================\n");
	Sleep(delay);
	printf("\n미궁 주인: 이번엔 동양의 이야기를 해볼까요.\n");
	Sleep(delay);
	printf("\n	'윤회'는 불교의 핵심 사상입니다.\n");
	Sleep(delay);
	printf("\n	윤회란, 지금 살고 있는 인간의 삶은 단순히 하나의 '생'에 불과합니다.\n");
	Sleep(delay);
	printf("\n	죽으면 또 다른 인간으로 태어나 전생과는 다른 삶을 살게 되죠.\n");
	Sleep(delay);
	printf("\n	우리가 '깨달음'을 얻어 윤회의 굴레를 벗어날 때까지\n");
	Sleep(delay);
	printf("\n	생과 사의 반복은 끝나지 않는다고 합니다.\n");
	Sleep(delay);
	printf("\n	보통 윤회는 수레바퀴 문양으로 표현하는데,\n");
	Sleep(delay);
	printf("\n	일종의 뫼비우스의 띠라고 할 수 있겠죠.\n");
	Sleep(delay);
	printf("\n\n%s: (첫 번째는 신화고 두 번째는 종교?)\n", user_name);
	Sleep(delay);
	printf("\n	계속 들어보자, 분명 이야기마다 공통되는 점이 있을 거야.\n");
	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}
void stage3(char* user_name) {
	printf("\n=================================================== Stage 3 _ Story: 무간지옥 ====================================================\n");
	Sleep(delay);
	printf("\n미궁 주인: 당신은 사후세계를 믿나요?\n");
	Sleep(delay);
	printf("\n\n%s: 그런 허풍을 누가 믿겠어.\n", user_name);
	Sleep(delay);
	printf("\n\n미궁 주인: 믿지 않는군요. 그래도 지옥은 들어는 보셨겠죠.\n");
	Sleep(delay);
	printf("\n	무간지옥은 죄를 지은 사람이 죽은 뒤 가는 지옥 중 하나입니다.\n");
	Sleep(delay);
	printf("\n	옥졸이 죄인의 가죽을 벗기고 그 벗겨낸 가죽으로 죄인의 몸을 묶어 불수레에 실어, \n");
	Sleep(delay);
	printf("\n	훨훨 타는 불 속에 죄인을 집어 넣어 몸을 태우며,\n");
	Sleep(delay);
	printf("\n	야차들이 큰 쇠창을 달구어 죄인의 몸을 꿰거나\n");
	Sleep(delay);
	printf("\n	입, 코, 배, 등을 꿰어 공중에 던진다고 합니다.\n");
	Sleep(delay);
	printf("\n	이 고통은 무한히 반복된다고 합니다.\n");

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
	printf("\n미궁 주인 : 한 남자가 있었습니다. 남자에겐 넉넉한 재산과 남 부럽지 않은 집,\n");
	Sleep(delay);
	printf("\n	사랑스러운 아내가 있었습니다.\n");
	Sleep(delay);
	printf("\n	그러다 남자가 교통사고를 당해 머리에 큰 부상을 입게 되었습니다.\n");
	Sleep(delay);
	printf("\n	그날의 사고로, 남자는 사고 이전의 기억만 남긴 채,\n");
	Sleep(delay);
	printf("\n	그 이후의 기억들은 10분 주기로 사라지는 후유증을 겪습니다.\n");
	Sleep(delay);
	printf("\n	남자는 무척 고생하지만, 아내의 정성어린 간호에 어느정도 호전되는 듯 싶었고,\n");
	Sleep(delay);
	printf("\n	그는 용기를 내어 자신의 몸 상태를 확인해보고자\n");
	Sleep(delay);
	printf("\n	아내를 태우고 차를 운전해보겠다고 말했습니다.\n");
	Sleep(delay);
	printf("\n\n	오늘이 바로 그 날이었습니다.\n");
	Sleep(delay);
	printf("\n	둘은 사람이 드문 대교를 가르며, 몰아치는 바람을 맛보고 있었습니다.\n");
	Sleep(delay);
	printf("\n	하지만 반대편에서 돌진하는 음주운전 차량은 보지 못했군요.\n");
	Sleep(delay);
	printf("\n	결국 두 차량은 크게 충돌하고, 가해 차량은 뺑소니를 쳐버립니다.\n");
	Sleep(delay);
	printf("\n	아내는 그 자리에서 즉사했습니다.\n");
	Sleep(delay);
	printf("\n	남자도 죽을 뻔했으나 가까스로 목숨을 건지게 됩니다.\n");
	Sleep(delay);
	printf("\n	남자는 아내를 죽인 가해자에게 복수를 할 준비를 합니다.\n");
	Sleep(delay);
	printf("\n	다행히 남자는 사건 당시 아내를 죽인 가해자의 인상을 노트로 적어놓았고,\n");
	Sleep(delay);
	printf("\n	가해자를 찾아 동분서주합니다.\n");
	Sleep(delay);
	printf("\n	본인이 가해자인 줄도 모르고.\n");
	Sleep(delay);
	printf("\n\n	사건의 전말은 이렇습니다.\n");
	Sleep(delay);
	printf("\n	처음부터 음주운전 차량은 없었습니다.\n");
	Sleep(delay);
	printf("\n	단순히 남자의 운전미숙으로 일어난 사고였습니다.\n");
	Sleep(delay);
	printf("\n	사고 후, 흐려지는 정신 속에서 죽어가는 아내를 보며\n");
	Sleep(delay);
	printf("\n	남자는 공포에 몸을 떨었습니다.\n");
	Sleep(delay);
	printf("\n	죽을 때까지 아내를 죽였다는 죄책감을 가지고 살고 싶지 않았습니다.\n");
	Sleep(delay);
	printf("\n	그래서 남자는 상상속의 가해자를 만들고, 그가 아내를 죽였다고 노트에 기록합니다.\n");
	Sleep(delay);
	printf("\n	10분 뒤에 그는 자신의 손으로 아내를 죽였다는 사실을 잊어버렸고,\n");
	Sleep(delay);
	printf("\n	오직 노트 속의 거짓말이 진실이라 믿습니다.\n");
	Sleep(delay);
	printf("\n	지금도 그는 아내를 죽인 가해자를 계속해서 찾고 있습니다.\n");
	Sleep(delay);
	printf("\n	자신이 만든 미궁 속에서요.\n");
	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}
void stage5(char* user_name) {
	printf("\n============================================= Stage 5 _ Story: 해와 달이 된 오누이? ==============================================\n");
	Sleep(delay);
	printf("\n미궁 주인: 축하합니다. 문제를 맞혔군요.\n");
	Sleep(delay);
	printf("\n	방금 그 방은 짐작하셨겠지만 한 고등학생의 방이었습니다.\n");
	Sleep(delay);
	printf("\n	그 학생은 어릴적 '해와 달이 된 오누이'라는 이야기를 좋아했어요..\n");
	Sleep(delay);
	printf("\n	네. 당신이 알고 있는 바로 그 이야기입니다.\n");
	Sleep(delay);
	printf("\n	호랑이에게서 도망치다가,\n");
	Sleep(delay);
	printf("\n	하늘에서 내려온 동아줄을 타고 해와 달이 된 그 오누이 이야기요.\n");
	Sleep(delay);
	printf("\n	그거 아십니까?\n");
	Sleep(delay);
	printf("\n	그 오누이는 지금도 해와 달인 그대로 지구 주변에 머물고 있다고 하는군요.\n");
	Sleep(delay);
	printf("\n	방의 주인인 학생은 어딨냐구요?\n");
	Sleep(delay);
	printf("\n	음... 그건 모르겠네요. 어디 학교라도 가지 않았겠습니까. 하하하.\n");
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
	printf("\n미궁 주인: 하하 몰골이 말이 아니네요. 영어 좀 나왔다고 땀 범벅이 되다니...\n");
	Sleep(delay);
	printf("\n	조금 미안해지려 할 정도예요.\n");
	Sleep(delay);
	printf("\n	그래도 생각보다 어렵진 않았죠?\n");
	Sleep(delay);
	printf("\n	방금 문제는 제가 가장 좋아하는 단어들 중 하나를 이용한 문제에요.\n");
	Sleep(delay);
	printf("\n	당신이 기억해주면 좋겠네요!\n");
	Sleep(delay);

	printf("\n\n%s: 내가 굳이 기억할 이유는 없어.\n", user_name);
	Sleep(delay);
	printf("\n	난 그저 나가기 위해서 문제를 풀 뿐이야. 너에게 관심 없어.\n");
	Sleep(delay);

	printf("\n\n미궁 주인: 네? 아, 그렇죠. 그래도 조금은 친해진 줄 알았는데 매정하네요...\n");
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
	printf("\n미궁 주인: 돈... 돈 좋죠...\n");
	Sleep(delay);
	printf("\n	돈이 많으면 따뜻한 집도, 먹고 싶은 음식도, 가고 싶은 곳도\n");
	Sleep(delay);
	printf("\n	원하는 것 대부분을 할 수 있잖아요.\n");
	Sleep(delay);
	printf("\n	한 가지 제안을 하죠. 당장 저에게 1원이라도 좋으니 돈을 가져오면\n");
	Sleep(delay);
	printf("\n	문제를 풀지 않고도 나갈 수 있게 해줄게요.\n");
	Sleep(delay);
	printf("\n	아, 꿈이라 아무것도 없죠? 이거 실례했군요. 하하하하.\n");
	Sleep(delay);
	printf("\n	그나저나 넥타르라고 아십니까? 그리스 로마 신화에 나오는 술의 이름이죠.\n");
	Sleep(delay);
	printf("\n	이 술을 마시면 영원한 젊음과 불멸을 얻을 수 있다고 하네요.\n");
	Sleep(delay);
	printf("\n	돈이 많으면 이것도 살 수 있을까요?\n");
	Sleep(delay);

	printf("\n\n%s: 내가 보기엔 있어도 너한텐 영원한 '젊음'은 무리야.\n", user_name);
	Sleep(delay);

	printf("\n\n미궁 주인: 이런. 한 방 먹었네요...\n");

	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}
void stage8(char* user_name) {
	printf("\n================================================ Stage 8 _ Story: What's my name? ================================================\n");
	printf("\n\"철컥\"\n");
	Sleep(delay);
	printf("\n정답을 외치자 어디선가 문이 열리는 소리가 들렸다.\n");
	Sleep(delay);
	printf("\n앞을 보니 미궁 주인은 미소를 짓고 있었고,\n");
	Sleep(delay);
	printf("\n그의 너머에 있는 문이 살짝 열려있다.\n");
	Sleep(delay);
	if (game_try == 1) {
		printf("\n\n%s: 축하드립니다. 이름을 알아냈군요. 아주 잘 해줬어요.\n", user_name);
		Sleep(delay);
		printf("\n	이렇게 빨리 맞힐 줄이야...\n");
		Sleep(delay);
		printf("\n	제가 알려드릴 수도 없어 많이 걱정했는데 다행이군요.\n");
		Sleep(delay);
		printf("\n	당신을 선택하길 잘한 거 같네요.\n");
		Sleep(delay);
	}
	else {
		printf("\n\n%s: 축하드립니다. 드디어 이름을 알아냈군요.\n", user_name);
		Sleep(delay);
		printf("\n	보는 동안 많이 답답했는데 그래도 맞히셨네요...\n");
		Sleep(delay);
		printf("\n	제가 알려드릴 수도 없어 속이 터지는 줄 알았습니다. \n");
		Sleep(delay);
		printf("\n	정말 다행입니다. 정말로요.\n");
		Sleep(delay);
	}
	printf("\n\nENDLESS: 하! 입에 바른 소리 하지 마.\n");
	Sleep(delay);
	printf("\n	드디어 이 지긋지긋한 미궁을 나가는군.\n");
	Sleep(delay);
	printf("\n	잘 있어라!!다신 만나지 말자!\n");
	Sleep(delay);
	printf("\n\n나의 말에 미궁 주인은 말없이 미소를 짓고는 손을 흔들어 준다.\n");
	Sleep(delay);
	printf("\n드디어 꿈에서 깨어날 수 있어!\n");
	Sleep(delay);
	printf("\n나는 걸음을 재촉하여 미궁 주인의 뒤에 있는 문을 향했다.\n");
	Sleep(delay);
	printf("\n문턱을 넘어 문을 지나 걸으려던 순간, 나는 걸음을 멈췄다.\n");
	Sleep(delay);
	printf("\n어째서 아직도 미궁 주인이 보이는 거지?\n");
	Sleep(delay);
	printf("\n보이는 광경이 7번 방에서 이 방으로 막 넘어왔을 때와 유사하다.\n");
	Sleep(delay);
	printf("\n\nENDLESS: 너 뭐야! 여기 어디야! 대체 왜 아직도 네가 보이는 거지?\n");
	Sleep(delay);
	printf("\n	어째서 다시 돌아온 거냐고! 나한테 거짓말을 한 거야?\n");
	Sleep(delay);
	printf("\n	문제를 다 풀었잖아! 어서 날 여기서 내보내줘!\n");
	Sleep(delay);
	printf("\n\n%s: 하하하하하하 재밌군요.\n", user_name);
	Sleep(delay);
	printf("\n	거짓말이요? 애초에 저는 당신이 나갈 수 있다고 말한 적이 없습니다.\n");
	Sleep(delay);
	printf("\n	제 말을 멋대로 오해한 건 당신이죠. 하... 얼마나 우습던지...\n");
	Sleep(delay);
	printf("\n	당신이 저의 옛 이름을 부른 순간부터 당신은 그 이름을 계승했습니다.\n");
	Sleep(delay);
	printf("\n	이 미궁에서 다음 희생자가 올 때까지 얌전히 기다리고 있어야 한다는 거죠.\n");
	Sleep(delay);
	printf("\n	당신이 살았던 삶은 이제 제 것입니다.\n");
	Sleep(delay);
	printf("\n	당신의 이름도, 그동안 모은 재산도, 인관 관계도 이젠 모두 저의 것이죠.\n");
	Sleep(delay);
	printf("\n	그럼 전 자유를 찾아 떠나도록 하겠습니다. 모쪼록 안녕히 계십시오.\n");
	Sleep(delay);
	printf("\n\nENDLESS: 웃기지마! 난 !@#$^&가 아니야! 난 %s라고!!!!!!!!!n\n", user_name);
	Sleep(delay);
	printf("\n==================================================================================================================================\n");
	Sleep(sDelay);
	for (int i = 0; i < 3; i++) {
		printf("\n.\n"); Sleep(hDelay);
	}
	return;
}


// 문제 틀렸을 때 (Stage1~7)
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
		printf("\n조"); Sleep(hDelay);
		printf("금"); Sleep(hDelay);
		printf(" "); Sleep(hDelay);
		printf("더"); Sleep(hDelay);
		printf(" "); Sleep(hDelay);
		printf("힘"); Sleep(hDelay);
		printf("을"); Sleep(hDelay);
		printf(" "); Sleep(hDelay);
		printf("내"); Sleep(hDelay);
		printf("보"); Sleep(hDelay);
		printf("세"); Sleep(hDelay);
		printf("요"); Sleep(hDelay);
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
		printf("\n이"); Sleep(hDelay);
		printf("것"); Sleep(hDelay);
		printf("밖"); Sleep(hDelay);
		printf("에"); Sleep(hDelay);
		printf(" "); Sleep(hDelay);
		printf("안"); Sleep(hDelay);
		printf(" "); Sleep(hDelay);
		printf("되"); Sleep(hDelay);
		printf("는"); Sleep(hDelay);
		printf(" "); Sleep(hDelay);
		printf("건"); Sleep(hDelay);
		printf("가"); Sleep(hDelay);
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
		printf("\n정"); Sleep(hDelay);
		printf("말"); Sleep(hDelay);
		printf("이"); Sleep(hDelay);
		printf("지"); Sleep(hDelay);
		printf(" "); Sleep(hDelay);
		printf("한"); Sleep(hDelay);
		printf("심"); Sleep(hDelay);
		printf("하"); Sleep(hDelay);
		printf("군"); Sleep(hDelay);
		printf("!\n"); Sleep(hDelay);
		for (int i = 0; i < 3; i++) {
			printf("\n.\n"); Sleep(hDelay);
		}
		break;
	default:
		printf("\n??? error) common_fail ???\n");
	}
	printf("\n당신에게 다시 기회를 드리죠.\n"); Sleep(delay);
	game_try++;
	system("cls");
	return;
}
	// 문제 틀렸을 때 (stage8)
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
		printf("\n미궁 주인: 당신이 조금 더 잘 할 수 있을 거라 생각했는데요...\n");
		Sleep(delay);
		printf("\n	제 기대가 너무 컸던 건가요?\n");
		Sleep(delay);
		printf("\n	기회를 한 번 더 드리죠. 얼마나 더 많은 힌트를 드려야 하죠?\n");
		Sleep(delay);
		printf("\n	이번엔 문제를 신중하게 풀길 바랍니다.\n");
		Sleep(delay);
		break;
	case 1:
		printf("\n미궁 주인: 기회를 더 줬는데도 못 맞히는 겁니까?\n");
		Sleep(delay);
		printf("\n	그렇게 많은 힌트를 드렸는데도요?\n");
		Sleep(delay);
		printf("\n	조금 더 생각이라는 걸 해보세요.\n");
		Sleep(delay);
		printf("\n	제가 언제까지고 이렇게 친절하게 있진 않습니다.\n");
		Sleep(delay);
		break;
	case 2:
		printf("\n미궁 주인: 대체 날 어디까지 실망시키려는 거지? 생각을 안 하는 건가?\n");
		Sleep(delay);
		printf("\n	머릿속에 대체 뭐가 들었길래 아직도 못 맞히는 거지? 머리는 장식인가?\n");
		Sleep(delay);
		printf("\n	생각이라는 걸 좀 하란 말이야, 생각을!!\n");
		Sleep(delay);
		break;
	default:
		printf("\n??? error) stage8_fail ???\n");
	}
	printf("\n당신에게 다시 기회를 드리죠.\n"); Sleep(delay);
	game_try++;
	system("cls");
	return;
}

// 문제 고르는 함수
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

// 스테이지별 문제 출력 함수
int quiz1(int which_quiz) {
	int get1 = 0, answer = 0;
	printf("\n========================================================= Stage 1 _ Quiz =========================================================\n");
	printf("\n문을 열고 들어간 방의 바닥에 검은 잉크로 문제가 찍혀있었다.\n");
	Sleep(delay);
	printf("\n단어 = 숫자? 무엇을 의미하는 걸까?\n");
	Sleep(delay);
	printf("\n아마 물음표에 들어갈 숫자를 알아내야 하나보다.\n");
	Sleep(delay);
	printf("\n분명 일정한 규칙이 있을거야. 생각해보자.\n");
	Sleep(delay);
	printf("\n뜬끔없이 끌려와 이런 문제나 푸는 신세라니...\n");
	Sleep(delay);
	printf("\n나도 모르게 헛웃음이 나왔다.\n");
	Sleep(delay);

	printf("\n\nQuiz) ?에 들어갈 것은?\n");
	switch (which_quiz) {
	case 0:
		printf("\n슴우 = 0\n");
		printf("\n오리 = 1\n");
		printf("\n대한민국 = 4\n");
		printf("\n김치냉장고 = 5\n");
		printf("\n물음표 = ?\n");
		break;
	case 1:
		printf("\n와르르맨션 = 0\n");
		printf("\n메모장 = 1\n");
		printf("\n에일리언 = 0\n");
		printf("\n스위트홈 = 2\n");
		printf("\n봉구스 = ?\n");
		break;
	case 2:
		printf("\n오버워치 = 4\n");
		printf("\n지구를지켜라 = 6\n");
		printf("\n응답 = 1\n");
		printf("\n궁극기 = 3\n");
		printf("\n표음문자 = ?\n");
		break;
	case 3:
		printf("\n파이게임 = 2\n");
		printf("\n디스코드 = 1\n");
		printf("\n튀김 = 0\n");
		printf("\n그믐달 = 1\n");
		printf("\n표본조사 = ?\n");
		break;
	case 4:
		printf("\n홍대입구역 = 1\n");
		printf("\n우주 = 2\n");
		printf("\n마우스패드 = 2\n");
		printf("\n뭉치 = 1\n");
		printf("\n요물 = ?\n");
		break;
	default:
		printf("\n??? error) quiz1 ???\n");
	}
	printf("\n\n정답 (숫자만 입력): ");
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
	printf("\n두 번재 방도 첫 번째 방과 똑같은 형식이다.\n");
	Sleep(delay);
	printf("\n다만... 숫자 문제가 아니라 논리 문제이다.\n");
	Sleep(delay);
	printf("\n윽, 벌써부터 머리가 아파진다.\n");
	Sleep(delay);
	printf("\n하지만 난 여기서 나가야 한다.\n");
	Sleep(delay);
	printf("\n빨리 누가 누구인지 알아보자.\n");
	Sleep(delay);
	printf("\n정답은 한 명씩 적는 것 같다.\n");
	Sleep(delay);
	printf("\n\nQuiz)\n");
	switch (which_quiz) {
	case 0:
		printf("\nA: B 또는 C가 거짓말쟁이야.\n");
		printf("\nB: 난 거짓말쟁이가 아니야.\n");
		printf("\nC: A가 거짓말쟁이야.\n");
		printf("\nD: A 또는 B가 거짓말쟁이야.\n");
		printf("\n\n이 중 거짓말쟁이는 1명이다. 과연 누구일까?\n");
		printf("\n거짓말쟁이: ");
		fflush(stdin);
		// 정수 입력 후 줄넘김이 %c에 대신 입력받아져서 scanf가 무시됐다.
		// %c 앞에 공백을 넣어 해결했다.
		scanf(" %c", &get2_1);
		if (get2_1 == 'a' || get2_1 == 'A')
			answer = 2;
		break;
	case 1:
		printf("\nA: B, D 중에는 거짓말쟁이가 없어.\n");
		printf("\nB: 나는 거짓말쟁이가 아니야.\n");
		printf("\nC: D는 거짓말쟁이가 아니야.\n");
		printf("\nD: B와 F 둘 중 오직 한 명이 거짓말쟁이야.\n");
		printf("\nE: C와 D 중에는 거짓말쟁이가 최소 1명 있어.\n");
		printf("\nF: D가 거짓말쟁이야.\n");
		printf("\n\n이 중 거짓말쟁이는 2명이다. 과연 누구일까?\n");
		printf("\n거짓말쟁이 1: ");
		fflush(stdin);
		scanf(" %c", &get2_1);
		printf("거짓말쟁이 2: ");
		fflush(stdin);
		scanf(" %c", &get2_2);
		if (((get2_1 == 'e' || get2_1 == 'E') && (get2_2 == 'f' || get2_2 == 'F')) || ((get2_1 == 'f' || get2_1 == 'F') && (get2_2 == 'e' || get2_2 == 'E')))
			answer = 2;
		break;
	case 2:
		printf("\n마을에 살인사건이 일어났다.\n");
		printf("\n용의자는 총 5명으로 A, B, C, D, E가 있다.\n");
		printf("\n5명 중에 3명이 진실을 말하고 2명이 거짓을 말하고 있다.\n");
		printf("\n거짓을 말하는 두 명 중 한 명은 마을에서 유명한 거짓말쟁이이고,\n");
		printf("\n나머지 한 명은 살인자이다.\n");
		printf("\n이들의 진술은 다음과 같다.\n");
		printf("\n\nA: D가 살인자야.\n");
		printf("\nB: 난 무죄야.\n");
		printf("\nC: E는 살인자가 아니야.\n");
		printf("\nD: B가 거짓말하는 거야.\n");
		printf("\nE: B의 말이 사실이야.\n");
		printf("\n거짓말쟁이와 살인자를 찾아서 벌을 내려야 한다.\n");
		printf("\n\n거짓말쟁이와 살인자는 각각 누구인가?\n");
		printf("\n거짓말쟁이: ");
		fflush(stdin);
		scanf(" %c", &get2_1);
		fflush(stdin);
		printf("살인자: ");
		scanf(" %c", &get2_2);
		if ((get2_1 == 'd' || get2_1 == 'D') && (get2_2 == 'a' || get2_2 == 'A'))
			answer = 2;
		break;
	case 3:
		printf("\n어떤 형무소에는 반드시 진실을 말하는 사람과 거짓을 말하는 사람이 있다.\n");
		printf("\n간수는 정직자를 선별해 은사를 주기 위해 죄수들에게\n");
		printf("\n누가 거짓말쟁이이고 누가 정직자인지 말하라고 했다.\n");
		printf("\n그랬더니 어떤 수용방의 3명은 이와 같이 말했다.\n");
		printf("\nA: B는 거짓말쟁이입니다. 저는 정직자이기 때문에 진실만을 말합니다.\n");
		printf("\nB: C가 거짓말쟁이입니다. 저야말로 정직자입니다.\n");
		printf("\nC: A, B야말로 거짓말쟁이입니다. 저는 물론 정직자입니다.\n");
		printf("\n\n과연 누가 진실을 말하고 있는 것일까?\n");
		printf("\n정직자: ");
		scanf(" %c", &get2_1);
		if (get2_1 == 'b' || get2_1 == 'B')
			answer = 2;
		break;
	case 4:
		printf("\n어떤 곳에 삼 형제 두 쌍이 있었습니다.\n");
		printf("\n그 6명을 각각 A,B,C,D,E,F 로 하겠습니다.\n");
		printf("\n(누구와 누가 형제인지는 불명)\n");
		printf("\n이 6명 중 3명은 항상 진실을 말하고, 나머지 3명은 항상 거짓말을 합니다.\n");
		printf("\n또 어느 형제든 최소 1명은 거짓말쟁이가 있습니다.\n");
		printf("\n아래의 증언으로 누구와 누가 형제이고\n");
		printf("\n거짓말쟁이와 정직한 사람은 각각 누구인지 맞혀보세요.\n");
		printf("\nA: 내 형제는 둘 다 거짓말쟁이다.\n");
		printf("\nB: 내 형제는 둘 다 정직한 사람이다.\n");
		printf("\nC: A와 B는 양쪽 다 거짓말쟁이다.\n");
		printf("\nD: 나는 C와 형제다.\n");
		printf("\nE: 나와 B는 형제다.\n");
		printf("\nF: E는 정직한 사람이다.\n");
		printf("\n\n형제를 한 쌍씩 띄어쓰기 없이 대문자로, 알파벳 순서로 입력해주세요.\n");
		printf("\n형제 1: ");
		scanf("%s", bro1);
		printf("\n형제 2: ");
		scanf("%s", bro2);
		if (((!strcmp(bro1, "BDE")) && (!strcmp(bro2, "ACF"))) || ((!strcmp(bro1, "ACF")) && (!strcmp(bro2, "BDE"))))
			answer++;
		printf("\n\n거짓말쟁이를 한 사람씩 알파벳 순서대로 입력해주세요.\n");
		printf("\n거짓말쟁이 1: ");
		fflush(stdin);
		scanf(" %c", &get2_1);
		printf("\n거짓말쟁이 2: ");
		fflush(stdin);
		scanf(" %c", &get2_2);
		printf("\n거짓말쟁이 3: ");
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
	printf("\n이번 방은 좀 특이했다.\n");
	Sleep(delay);
	printf("\n방의 한가운데에 책상이 놓여져 있었고, 그 위에는 ..돈?\n");
	Sleep(delay);
	printf("\n돈이 있었다!\n");
	Sleep(delay);
	printf("\n신나서 돈을 주머니에 쑤셔넣을 찰나에 주인이 내 손을 거세게 쳐냈다.\n");
	Sleep(delay);
	printf("\n미궁 주인: 돈은 문제를 풀기위해서 마련된 도구입니다.\n");
	Sleep(delay);
	printf("\n	가져가 봤자 미궁 안인데 미련한 짓거릴 하시네요. 하하\n");
	Sleep(delay);
	printf("\n주인은 소리를 내어 웃었다. 어깨가 들썩였다. 재수없어.\n");
	Sleep(delay);
	printf("\n짜증이 난 나는 손에 쥔 돈을 힘을 주어 다시 책상에 내려놓았다. 쾅소리가 났다.\n");
	Sleep(delay);
	printf("\n손이 아팠지만 주인에게 내색하기 싫어 참았다.\n");
	Sleep(delay);
	printf("\n돈을 내려놓자, 방의 벽에 문제가 서서히 생겨났다.\n");
	Sleep(delay);
	printf("\n계산 문제라서 돈을 줬구나. 돈을 이용해 문제를 풀어보자.\n");
	srand(time(NULL));

	printf("\n\nQuiz)\n");
	switch (which_quiz) {
	case 0:
		printf("\n어느 보석가게에 손님이 70만원짜리 진주를 사고는 100만 원짜리 수표를 내밀었다.\n");
		printf("\n주인은 잔돈이 없어서 옆집에 가서 현금으로 바꿔 손님에게 30만 원을 내주었다.\n");
		printf("\n다음날 옆집에서 부도 수표라며 환불을 요구하길래 100만 원을 다시 돌려주었다.\n");
		printf("\n보석가게 주인은 몇 만 원을 손해봤을까?\n");

		printf("\n\n답(단위 없이 숫자만 입력하시오. 단위: 만 원): ");

		scanf("%d", &get3);
		if (get3 == 100)
			answer++;
		break;
	case 1:
		printf("\n세 친구가 식당에 가서 각자 만 원씩 모아 밥을 먹었습니다.\n");
		printf("\n3만 원을 계산하려는데 오늘 이벤트라며 주인이 오천 원을 깎아줬습니다.\n");
		printf("\n그래서 천 원씩 서로 돌려받고, 남은 이천 원은 간식을 사먹었습니다.\n");
		printf("\n한참을 가다 갑자기 한 친구가 이상하다고 말했습니다.\n");
		printf("\n어? 한 사람이 천 원씩 돌려받았으니까 9천 원씩 2만 7천 원 내고, 2천 원 아이스크림 먹었으니까\n");
		printf("\n2만 9천 원이잖아? 나마지 천 원은 어디로 갔지?\n");

		printf("\n\n다음 보기 중 답을 고르시오.\n");
		printf("\n1. 착각 2. 실수 3. 모순 4. 우주의 법칙\n");

		printf("\n답(숫자만 입력하시오): ");
		scanf("%d", &get3);

		if (get3 == 1)
			answer++;
		break;
	case 2:
		printf("\n어느 고기집에서 어떤 사람이 7만 원의 고기를 먹고 10만 원짜리 수표를 냈다.\n");
		printf("\n주인은 잔돈이 없어서 옆집에서 현금으로 바꾼 뒤 손님에게 3만 원을 거슬러 줬다.\n");
		printf("\n다음날 옆집에서 부도수표라며 환불을 요구하길래 10만 원을 다시 돌려주었다.\n");
		printf("\n고기집 주인은 몇 만 원을 손해봤을까?\n");
		printf("\n\n답(단위 없이 숫자만 입력하시오. 단위: 만 원): ");

		scanf("%d", &get3);

		if (get3 == 10)
			answer++;
		break;
	case 3:
		printf("\nA와 B한테 각각 500원을 빌리고 총 천원으로 970원짜리 과자를 샀다.\n");
		printf("\n거스름돈 30원으로 A,B,나 각각 10원씩 나눠 가졌다.\n");
		printf("\n그러면 A,B에게 490원씩 빚진건데 490+490 = 980원에서 내가 가진 돈 10원을 포함하면 990원이다.\n");
		printf("\n나머지 10원은 어디로 갔을까?\n");

		printf("\n\n다음 보기 중 답을 고르시오: ");
		printf("\n1. 실수 2. 모순 3. 착각 4. 우주의 법칙\n");

		printf("\n답(숫자만 입력하시오): ");
		scanf("%d", &get3);

		if (get3 == 3)
			answer++;
		break;

	case 4:
		printf("\n어느 정육점에서 손님이 50만 원어치 고기를 사고는 100만 원짜리 수표를 내밀었다.\n");
		printf("\n주인은 잔돈이 없어서 옆집에 가서 현금으로 바꿔 손님에게 50만 원을 내주었다.\n");
		printf("\n다음날 옆집에서 부도 수표라며 환불을 요구하길래 100만 원을 다시 돌려주었다.\n");
		printf("\n보석가게 주인은 몇 만 원을 손해봤을까?\n");

		printf("\n\n답(단위 없이 숫자만 입력하시오. 단위: 만 원): ");

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
	printf("\n네번째 방이다.\n");
	Sleep(delay);
	printf("\n처음 들어갔던 방의 문제랑 비슷하다.\n");
	Sleep(delay);
	printf("\n설마 첫번째 방과 규칙이 같은거면...?\n");
	Sleep(delay);
	printf("\n첫 번째 문제의 규칙으로 문제를 풀어보자...\n");
	Sleep(delay);
	printf("\n다음 방문은 꿈쩍도 하지 않은 채 굳게 닫혀있다...\n");
	Sleep(delay);
	printf("\n에라이... 내심 기대했는데...\n");
	Sleep(delay);
	printf("\n주인은 소리를 내어 웃었다. 어깨가 들썩였다. 재수없어.\n");
	Sleep(delay);
	printf("\n기분이 갑자기 좋아졌다가 금새 원래대로 돌아왔다.\n");
	Sleep(delay);
	printf("\n손이 아팠지만 주인에게 내색하기 싫어 참았다.\n");
	Sleep(delay);
	printf("\n처음의 마음으로 돌아가 푸는 수 밖에...\n");
	Sleep(delay);

	printf("\n\nQuiz) ?에 들어갈 것은?\n");
	switch (which_quiz) {
	case 0:
		printf("\n USE = 4\n");
		printf("\n SAY = 5\n");
		printf("\n LIV = 3\n");
		printf("\n UNI = 3\n");
		printf("\n DEV = ?\n");

		printf("\n\n답(숫자만 입력하시오): ");

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

		printf("\n\n답(숫자만 입력하시오): ");

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

		printf("\n\n답(숫자만 입력하시오): ");

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

		printf("\n\n답(숫자만 입력하시오): ");

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

		printf("\n\n답(숫자만 입력하시오): ");

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
	printf("\n이번 방은 학생의 방 같아 보인다.\n");
	Sleep(delay);
	printf("\n책상 위에는 구겨진 종이 몇 장, 구급약품, 펜이 나뒹굴고 있었고,\n");
	Sleep(delay);
	printf("\n책꽂이에는 각종 시험 대비 문제집과 생기부를 채울 때나 읽을 법한 책들이 꽂혀 있다.\n");
	Sleep(delay);
	printf("\n이 방에 있으니 당신의 학창시절이 떠오른다.\n");
	Sleep(delay);
	printf("\n아무리 열심히 공부해도 이길 수 없는 녀석이 있었지.\n");
	Sleep(delay);
	printf("\n추억을 회상하며 방을 둘러보다가\n");
	Sleep(delay);
	printf("\n바닥에 떨어져 있던 6장의 영단어 카드를 발견했다.\n");
	Sleep(delay);
	printf("\n단어 카드를 주워 원래대로 정리하려는데,\n");
	Sleep(delay);
	printf("\n그 중 한 장이 바닥에 엎질러진 빨간 잉크에 물들어 글씨가 잘 보이지 않았다.\n");
	Sleep(delay);
	printf("\n물감 때문인지 카드가 약간 찐득해서 불쾌감이 느껴진다.\n");
	Sleep(delay);
	printf("\n다음 방으로 향하는 문에는 영어를 입력할 수 있는 자판이 마련돼 있다.\n");
	Sleep(delay);
	printf("\n손상된 카드의 단어가 다음 방으로 향하는 열쇠인 것 같다.\n");
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

		printf("\n\n손상된 카드의 단어는? (소문자로 입력)\n");
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

		printf("\n\n손상된 카드의 단어는? (소문자로 입력)\n");
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

		printf("\n\n손상된 카드의 단어는? (소문자로 입력)\n");
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
		printf("\n\n손상된 카드의 단어는? (소문자로 입력)\n");
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

		printf("\n\n손상된 카드의 단어는? (소문자로 입력)\n");
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
	printf("\n문을 열고 들어온 방의 벽면에는 알파벳과 숫자가 짝지어져 있었다.\n");
	Sleep(delay);
	printf("\n아까 방도 그렇고 왜 이렇게 영어가 많이 나오는지...\n");
	Sleep(delay);
	printf("\n영어 공포증이 몰려오기 시작한다.\n");
	Sleep(delay);
	printf("\n속이 울렁거리고 식은땀이 나 기분이 좋지 않다.\n");
	Sleep(delay);
	printf("\n끝도 없이 나오는 이 영어들이 얼른 사라지면 좋겠다.\n");
	Sleep(delay);
	printf("\n다음 방으로 가는 문에는 알파벳과 물음표가 짝지어져 있다.\n");
	Sleep(delay);
	printf("\n아무래도 물음표에 들어갈 숫자를 알아내야 할 거 같다.\n");

	printf("\n\nQuiz)\n");
	switch (which_quiz) {
	case 0:
		printf("\ns = 3\n");
		printf("\nm = 1\n");
		printf("\ne = 5\n");
		printf("\na = 2\n");
		printf("\nt = 4\n");
		printf("\nr = ?\n");

		printf("\n\n물음표에 들어갈 숫자는? ");

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

		printf("\n\n물음표에 들어갈 숫자는? ");

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

		printf("\n\n물음표에 들어갈 숫자는? ");

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

		printf("\n\n물음표에 들어갈 숫자는? ");

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

		printf("\n\n물음표에 들어갈 숫자는? ");

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
	printf("\n이번 방에서는 뭔가 음악이 들려온다. 영어를 벗어난 건 좋지만 갑자기 웬 음악이람?\n");
	Sleep(delay);
	printf("\n'I need~ a dollar, dollar, a dollar is what I need~ Hey Hey~'\n");
	Sleep(delay);
	printf("\n내가 꿈에 갇히기 전 좋아했던 노래다.\n");
	Sleep(delay);
	printf("\n분명 경쾌하고 밝은 리듬인데 왠지 모르게 섬뜩하게 느껴지는 건\n");
	Sleep(delay);
	printf("\n미궁의 분위기 탓이려나?\n");
	Sleep(delay);
	printf("\n얼른 이곳에서 탈출해서 현실에서 이 노래를 듣고 싶다.\n");
	Sleep(delay);
	printf("\n아늑한 침대에 누워 이 노래를 듣고 있으면 참 좋을텐데...\n");
	Sleep(delay);
	printf("\n정신을 차리고 다음 방을 향한 문제를 찾는다.\n");
	Sleep(delay);
	printf("\n손이 아팠지만 주인에게 내색하기 싫어 참았다.\n");
	Sleep(delay);
	printf("\n딱 봐도 평범하지 않아 보이는 수식들이 있다.\n");
	Sleep(delay);
	printf("\n마지막 수식의 답을 구하면 되는 거겠지?\n");
	Sleep(delay);

	printf("\n\nQuiz)\n");
	switch (which_quiz) {
	case 0:
		printf("\n500 - 50 = 5\n");
		printf("\n100 - 20 = 4\n");
		printf("\n500 - 20 = 8\n");
		printf("\n100 - 50 = 1\n");
		printf("\n500 - 80 = ?\n");

		printf("\n\n물음표에 들어갈 숫자는?: ");

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

		printf("\n\n물음표에 들어갈 숫자는?: ");

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

		printf("\n\n물음표에 들어갈 숫자는?: ");

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

		printf("\n\n물음표에 들어갈 숫자는?: ");

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

		printf("\n\n물음표에 들어갈 숫자는?: ");

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
		printf("\n이번 방에는 안락해보이는 소파가 있었고,\n");
		Sleep(delay);
		printf("\n낮은 테이블 위에는 따뜻한 차가 준비되어 있었다.\n");
		Sleep(delay);
		printf("\n\n%s (이제 마지막 방인가... 일단 앉자.)\n", user_name);;
		Sleep(delay);
		printf("\n\n7개의 방을 지나오며 지칠대로 지친 몸을 소파위에 맡겼다.\n");
		Sleep(delay);
		printf("\n\n미궁 주인: 방에 어떤 장치가 숨겨져있을 줄 알고 그렇게 경계심이 없습니까?\n");
		Sleep(delay);
		printf("\n\n아까 까지만 해도 아무도 앉아있지 않던 맞은편 소파에\n");
		Sleep(delay);
		printf("\n어느새인가 미궁 주인이 와서 앉아있다.\n");
		Sleep(delay);
		printf("\n\n%s: 내가 지금 누구 때문에 이렇게 고생하고 있다고 생각해? 도와줄 거 아니면 참견 마.\n", user_name);;
		Sleep(delay);
		printf("\n\n미궁 주인: 그러게요. 그래도 마지막 문제이니만큼, 제가 직접 출제하기로 했습니다.\n");
		Sleep(delay);
		printf("\n\n%s: 그래. 어서 문제나 말해.\n", user_name);
		Sleep(delay);
		printf("\n	마지막 문제를 풀고 이 재미도 없고 지긋지긋한 꿈의 끝을 봐야겠어.\n");
		Sleep(delay);
		printf("\n\n미궁 주인: 저는 그래도 당신이 있어 나름 재미있었습니다만...\n");
		Sleep(delay);
		printf("\n	뭐, 그렇게 원하시니 바로 말해드리겠습니다.\n");
		Sleep(delay);
		printf("\n	마지막 문제는 바로 제 이름을 맞히는 것입니다.\n");
		Sleep(delay);
		printf("\n	지금까지 풀어온 문제와 제가 했던 말들을 잘 곱씹어보십시오. \n");
		Sleep(delay);
		printf("\n	뭔가 생각나는 게 있을 겁니다.\n");
		Sleep(delay);
		printf("\n\n%s: 뭐? 무슨 소리야? 내가 네 이름을 어떻게 알아!!\n", user_name);
		Sleep(delay);
		printf("\n\n미궁 주인: 정 모르시겠다면 문제를 처음부터 다시 풀면 되는 일입니다.\n");
		Sleep(delay);
		printf("\n\n%s: 내가 지금까지 얼마나 힘들게 풀었는데 그걸 다시 풀라고? 웃기지 마!\n", user_name);
		Sleep(delay);
		printf("\n\n미궁 주인: 그러니까 잘 생각해보십시오. 저는 분명 충분한 힌트를 드렸습니다.\n");
		Sleep(delay);
		printf("\n	아, 마지막으로 힌트를 하나 더 드리죠.\n");
		Sleep(delay);
		printf("\n	제 이름은 영어입니다. 영어를 제외한 문자는 없어요. 행운을 빌죠.\n");
		break;
	case 1:
		printf("\n익숙한 풍경이다. 소파 2개와 낮은 테이블, 따뜻한 차가 준비되어 있다.\n");
		Sleep(delay);
		printf("\n차에서 김이 나는 것을 보면 다시 준비한 방인 듯하다.\n");
		Sleep(delay);
		printf("\n이 미궁에서 유일하게 휴식을 취할 수 있어 보이는 곳이지만,\n");
		printf("\n지금은 그저 짜증나기만 한다.\n");
		Sleep(delay);
		printf("\n\n미궁 주인: 시간이 아깝군요. 문제는 아까와 같습니다. 제 이름을 말하면 돼요.\n");
		Sleep(delay);
		printf("\n\n%s: 그러니까... 영어로만 이루어졌댔던가?\n", user_name);
		Sleep(delay);
		printf("\n\n미궁 주인: 하... 그렇습니다. 얼른 문제나 풀어주시겠어요?\n");
		Sleep(delay);
		printf("\n\n%s: (언제는 나 덕분에 재밌었다면서 이 태세전환은 뭐지...)\n", user_name);
		Sleep(delay);
		printf("\n\n미궁 주인: 잡생각 말고 제 이름을 말하십시오. 얼른.\n");
		Sleep(delay);
		printf("\n\n%s: 맞았는데 틀렸다고 하면 안 된다?!\n", user_name);
		Sleep(delay);
		printf("\n\n미궁 주인: 그럴 생각 없습니다!! 문제에 집중하세요!!!!!\n");
		Sleep(delay);
		break;
	case 2:
		printf("\n아까와 완전히 같은 풍경이다. 이곳에서 나갈 수 있을까...\n");
		Sleep(delay);
		printf("\n\n미궁 주인: 하... 당신이란 사람은...\n");
		printf("\n	도대체 얼마나 많은 기회를 더 드려야 풀 수 있는 겁니까?\n");
		Sleep(delay);
		printf("\n	정말 한심하군요... 당신을 선택하는 게 아니었어...\n");
		Sleep(delay);
		printf("\n\n%s: (선택? 묘하게 내가 문제를 맞히기를 바라는 것 같다. 자신이 날 가뒀으면서 대체 왜?)\n", user_name);
		Sleep(delay);
		printf("\n\n미궁 주인: 문제는 아까와 같습니다. 이 말도 지긋지긋하군요. 영어로 된 제 이름을 말하세요.\n");
		Sleep(delay);
		break;
	default:
		printf("\n??? error) quiz8 ???\n");
	}
	printf("\n\nQuiz) 미궁 주인의 이름 (대문자로 입력): ");
	scanf("%s", input);
	if (!strcmp(input, "ENDLESS"))
		answer++;
	printf("\n==================================================================================================================================\n");
	Sleep(delay);
	return answer;
}
