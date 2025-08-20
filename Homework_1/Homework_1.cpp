#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
*p_HPPotion = count;
*p_MPPotion = count;
}

int main()
{
	int Stat[4];
	/*
	Stat[0] = HP 체력
    Stat[1] = MP 마력
	Stat[2] = AP 공격력
	Stat[3] = DP 방어력
	*/

	printf("HP와 MP를 입력해주세요.\n");
	scanf_s("%d", &Stat[0]);
	scanf_s("%d", &Stat[1]);

	while(Stat[0] < 50 || Stat[1] < 50 )
	{
		printf("HP 나 MP의 값이 너무 작습니다. 다시 입력해 주세요.\n");
		scanf_s("%d", &Stat[0]);
		scanf_s("%d", &Stat[1]);
	}

	printf("\n공격력과 방어력을 입력해주세요.\n");
	scanf_s("%d", &Stat[2]);
	scanf_s("%d", &Stat[3]);

	while(Stat[2] <= 0 || Stat[3] <= 0)
	{
		printf("AP 나 DP의 값이 너무 작습니다. 다시 입력해 주세요.\n");
		scanf_s("%d", &Stat[2]);
		scanf_s("%d", &Stat[3]);
	}

	int Num = 0;
	int HPPotion = 0;
	int MPPotion = 0;

	setPotion(5, &HPPotion, &MPPotion);

	printf("\n* 포션이 지급되었습니다.(HP, MP 포션 각 5개)\n");
	printf("===============================================================================================================\n");
	printf("<스탯 관리 시스템>\n 1. HP 회복\n 2. MP 회복\n 3. HP 강화\n 4. MP 강화\n 5. 공격 스킬 사용\n 6. 필살기 사용\n 7. 나가기\n");

	while(1)
	{
		printf("번호를 선택해주세요.\n");
		scanf_s("%d", &Num);
		if (Num == 7) {
			printf("프로그램을 종료합니다.\n");
			break;	
		}

		switch (Num)
		{
		case 1:
			if (HPPotion <= 0)
			{
				printf("포션이 부족합니다.\n");
				continue;
			}

			Stat[0] += 20;
			HPPotion -= 1;
			printf("*HP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n");
			printf("현재 HP : %d\n남은 포션 수 : %d\n", Stat[0], HPPotion);
			break;

		case 2:
			if (MPPotion <= 0)
			{
				printf("포션이 부족합니다.\n");
				continue;
			}

			Stat[1] += 20;
			MPPotion -= 1;
			printf("*MP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n");
			printf("현재 MP : %d\n남은 포션수 : %d\n", Stat[1], MPPotion);
			break;

		case 3:
			Stat[0] *= 2;
			printf("*HP가 강화되었습니다.\n 현재 HP : %d\n", Stat[0]);
			break;

		case 4:
			Stat[1] *= 2;
			printf("*MP가 강화되었습니다.\n 현재 MP : %d\n", Stat[1]);
			break;

		case 5:
			if (Stat[1] < 50)
			{
				printf("MP가 부족합니다.\n 현재 MP : %d\n", Stat[1]);
				continue;
			}

			Stat[1] -= 50;
			printf("*스킬을 사용하여 MP가 50 소모되었습니다.\n 현재 MP : %d\n",Stat[1]);
			break;

		case 6:
			Stat[1] /= 2;
			printf("스킬을 사용하여 MP가 50%% 소모되었습니다.\n 현재 MP : %d\n",Stat[1]);
			break;
		}
	}
	
	return 0;
}
/*
개선 필요 사항?
1. HP, MP 강화가 무한대로 발생함
2. 필살기 사용시 MP가 50% 소모되나 최소 요구 MP가 없음 
3. 공격력과 방어력 데이터는 입력되었으나 사용하지 않음
4. 포션을 다 사용 후 추가하는 기능 없음
*/