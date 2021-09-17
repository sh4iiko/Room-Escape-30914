#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
enum Item {
	remoteControl,
	innerRoomKey,
	bookHintPaper,
	USB,
	hardBread,
	softBread,
	dischargedPhone,
	phone,
	battery,

};

char itemName[30][30] = {
	"리모컨",
	"안방 키",
	"힌트 종이",
	"USB",
	"딱딱한 빵",
	"적신 빵",
	"방전된 스마트폰",
	"스마트폰",
	"보조 배터리",
};

void LivingRoom();
int LivingRoom_sopa, LivingRoom_TV, LivingRoom_refrigerator, LivingRoom_waterpurifier, LivingRoom_raptop;
 

void InnerRoom();
int InnerRoom_open, InnerRoom_book, InnerRoom_bedding, InnerRoom_mattress, InnerRoom_pillow, InnerRoom_jacket, InnerRoom_jeans;
int InnerRoom_doorLife=3;

int InputNum(int first, int last);

void LookInventory();

int inventory[30];
const int inventoryMax = 30;

char raptopPassword[5];
const int raptopPasswordCount = 4;

char doorRaptopPassword[5];
const int doorRaptopPasswordCount = 4;

char doorPhonePassword[5];
const int doorPhonePasswordCount=4;

char doorPassword[9];
const int doorPasswordCount=8;

int phoneLife=0;
int batteryLife=150;

int life=30;

int main()
{
	srand(time(NULL));
	int i;
	for (i = 0; i < raptopPasswordCount; i++) {
		raptopPassword[i] = '0' + rand() % 10;
	}
	raptopPassword[i] = '\0';
	for (i = 0; i < doorPasswordCount; i++) {
		doorPassword[i] = '0' + rand() % 10;
	}
	for(i = 0;i<doorRaptopPasswordCount;i++){
		doorRaptopPassword[i]= doorPassword[i];
	}
	doorRaptopPassword[i] = '\0';
	for(i = 0;i<doorPhonePasswordCount;i++){
		doorPhonePassword[i] = doorPassword[i+doorRaptopPasswordCount];
	}
	doorPhonePassword[i] = '\0';

	printf("밖에 나가려 했는데 문이 닫혀있다.\n");
	Sleep(1000);
	printf("왜 열리지 않는걸까 ? 이대로 갇혀있있순 없다.\n");
	Sleep(1000);
	printf("빨리 탈출하자.");
	Sleep(1000);
	system("cls");

	LivingRoom();
}

void LivingRoom()
{
	int num;
	while (1) {
		if(!life){
			system("cls");
			printf("체력 없어서 죽음");
			return; 
		} 
		printf("남은 체력 : %d \n1. 소파 2. TV 3. 냉장고 \n4. 정수기 5. 노트북 6.안방으로 이동 \n7. 인벤토리 8. 탈출구\n",life);
		
		num = InputNum(1, 8);
		system("cls");
		life--;
		
		switch (num)
		{
		case 1:
			if (!LivingRoom_sopa) {
				printf("1. 소파 위를 뒤진다.\n");
				printf("2. 가만히 둔다.\n");

				num = InputNum(1, 2);
				if (num == 1) {
					printf("리모컨 획득\n");
					inventory[remoteControl] = 1;
					LivingRoom_sopa = 1;
				}
				else {
					printf("아무일도 없다.\n");
				}
			}
			else {
				printf("더 이상 찾을게 없다\n");				
			}
			break;

		case 3:
			if(!LivingRoom_refrigerator)
			{
				printf("먹다 남은 음식이 있다. 챙길까\n");
				printf("1. 챙긴다 2. 그냥 두고 간다.\n");
				num = InputNum(1,2);
				if(num==1){
					printf("딱딱한 빵 획득\n");
					inventory[hardBread]=1;
					LivingRoom_refrigerator=1;
				}
				else{
					printf("건들지 말자\n");
				}
			}
			else{
				printf("더 이상 찾을게 없다\n");
			}
			break;
		
		case 4: 
			printf("정수기다.\n");
			printf("1. 물을 튼다. 2. 가만히 둔다.\n");
			num = InputNum(1,2);
			if(num==1){
				if(inventory[hardBread]){
					printf("1. 빵을 물에 적신다. 2.그냥 둔다\n");
					num = InputNum(1,2);
					if(num==1){
						printf("빵이 젖었다. 더 배부르게 먹을 수 있겠지\n");
						inventory[hardBread]=0;
						inventory[softBread]=1;
					}
				}
				else{
					printf("물이 나온다.\n");
				}
			}
			else{
				printf("건들지 말자\n");
			}
			break;
		case 5:
			printf("노트북이 있다.\n");
			printf("1. 노트북을 킨다. 2. 가만히 둔다.\n");
			num = InputNum(1, 2);
			if (num == 1) {
				char pw[100];
				system("cls");
				printf("키는 중\n");
				Sleep(1000);
				printf("켜짐\n");
				printf("비밀번호가 걸려있다. 비밀번호를 입력하자.\n");
				scanf("%s", pw);
				if (!strcmp(pw, raptopPassword)) {
					printf("비밀번호가 맞았다.\n");
					if (inventory[USB]) {
						printf("USB가 있었지, 꽂아볼까\n");
						printf("1. 꽂는다 2. 그냥 끈다.\n");
						num = InputNum(1, 2);
						if (num == 1) {
							printf("이상한 번호가 써있는 메모장을 찾았다.\n");
							printf("%s\n", doorRaptopPassword);
							Sleep(3000);
						}
					}
					else {
						printf("아무 자료가 없다.\n");
					}
				}

				else {
					printf("비밀번호가 틀렸다.\n");

				}
			}
			else {
				printf("그냥 가만히 두자\n");
			}
			break;

		case 6:
			if (!InnerRoom_open) {
				printf("문이 잠겨있는거 같다.\n");
				printf("1. 문 열기 2. 문 부수기 0. 가만히 둔다\n");
				num = InputNum(0, 2);
				if (!num) {
					break;
				}
				else if (num == 1) {
					if (!inventory[innerRoomKey]) {
						printf("열쇠가 없어 들어갈 수 없다. 열쇠를 찾아보자\n");
					}
					else {
						printf("문이 열렸다. 들어가보자\n");
						InnerRoom_open = 1;
						Sleep(500);
						system("cls");
						InnerRoom();
					}
				}
				else {
					printf("쾅...\n");
					Sleep(1000);
					printf("더 하면 부서질것 같은데..\n");
					printf("체력이 5 깎였다.\n");
					Sleep(1000);
					life-=5;
					InnerRoom_doorLife--;
					if(!InnerRoom_doorLife){
						printf("문이 부숴졌다. 들어가보자\n");
						InnerRoom_open=1;
						Sleep(1000);
						system("cls");
						InnerRoom();
					}
				}
			}
			else{
				InnerRoom();
			}
			break;
		case 7:
			LookInventory();
			break;
		
		case 8:
			char pw[100];
			printf("비밀번호 : \n");
			scanf("%s", pw);
			if (!strcmp(pw, doorRaptopPassword)) {
				system("cls");
				printf("탈출 성공\n");
				Sleep(1000);
				return;
			}
			else {
				printf("틀렸다 다시 찾아보자\n");
			}
			break;

		}
		Sleep(500);
		system("cls");
			
	}
		

}


void InnerRoom() {
	int num;
	while (1) {
		
		if(!life){
			system("cls");
			printf("체력 없어서 죽음");
			return; 
		} 
		printf("남은 체력 : %d\n1. 책 2. 침대 3. 옷장 \n4. 인벤토리 0. 나가기\n",life);

		num = InputNum(0, 4);
		life--;
		system("cls");
		switch (num)
		{
		case 0:
			printf("안방을 나왔다.\n");
			return;
		case 1:
			printf("책이 있다.\n1. 책을 연다. 2.가만히 둔다.\n");
			num = InputNum(1, 2);
			if (num == 1) {
				printf("책에서 숫자가 적혀있는 종이를 찾았다. 확인해보자\n");
				inventory[bookHintPaper] = 1;
			}
			else {
				printf("그냥 가만히 두자.\n");
			}
			break;
		case 2:
			printf("1. 이불 2. 매트리스 3. 베게 4. 가만히 둔다.\n");
			num = InputNum(1, 4);
			if (num == 1) {
				printf("1. 이불을 들춘다. 2. 가만히 둔다.\n");
				num = InputNum(1, 2);
				if (num == 1) {
					printf("솜털만 날린다.\n");
				}
				else {
					printf("그냥 가만히 두자\n");
				}
			}
			else if (num == 2) {
				printf("1. 매트리스를 들춘다. 2. 가만히 둔다.\n");
				num = InputNum(1, 2);
				if (num == 1) {
					printf("숨겨져 있던 USB를 찾았다.\n");
					inventory[USB] = 1;
				}
				else {
					printf("그냥 가만히 두자\n");
				}
			}
			else if (num == 3) {
				if(!InnerRoom_pillow){
				
					printf("1. 베게를 들춘다. 2. 가만히 둔다.\n");
					num = InputNum(1, 2);
					if (num == 1) {
						printf("스마트폰 획득.\n");
						printf("근데 배터리가 없다\n");
						inventory[dischargedPhone]=1; 
						InnerRoom_pillow=1;
					}
					else {
						printf("그냥 가만히 두자\n");
					}
				}
				else{
					printf("더 이상 찾을게 없다\n");
				}
			}
			break;
		
		case 3:
			printf("1. 자켓 2. 청바지 3. 가만히 두기\n");
			num = InputNum(1,3);
			if(num==1){
				if(!InnerRoom_jacket){
				
					printf("1. 주머니를 뒤진다. 2.가만히 둔다.\n");
					num = InputNum(1,2);
					if(num==1){
						printf("보조 배터리를 찾았다. 어따쓰지\n");
						inventory[battery] =1;
						InnerRoom_jacket=1;
					}
					else{
						printf("가만히 두자.\n");
					}
				}
				else{
				printf("더 할게 없다.\n");
				} 
				 
			}
			else if(num==2){
				printf("아무것도 없다.\n");
			}
			else{
				printf("가만히 두자");
			}
			
			break;
		case 4:
			LookInventory();
			break;


		}
		Sleep(500);
		system("cls");

	}
}

int InputNum(int first, int last) {
	char get;
	while (1) {
		get = NULL;
		scanf("%c", &get);
		if (get == NULL||get=='\n') {
			continue;
		}
		if ((get >= '0' + first && get <= '0' + last))
		{
			return get - '0';
		}
		else 
		{
			printf("다시 입력\n");
		}
		
	}
	return -1;
}

void LookInventory() {
	int i;
	int item[30];
	int count = 0;
	for (i = 0; i < inventoryMax; i++) {
		if (inventory[i]) {
			item[count++] = i;
		}
	}
	
	printf("남은 체력 : %d\n",life);
	
	for (i = 0; i < count; i++) {
		printf("%d. %s ", i + 1, itemName[item[i]]);
		if ((i+1) % 3 == 0) {
			printf("\n");
		}
	}
	printf("0. 나가기\n");

	i = InputNum(0, count);
	if (!i) {
		return;
	}
	switch(item[i-1]){
		
		case remoteControl:
			if(!inventory[innerRoomKey])
			printf("리모컨 안에 숨어있는 안방 열쇠를 찾았다.\n");
			inventory[innerRoomKey] = 1;
			break;
			
		case bookHintPaper:
			printf("어디에 쓰는지 모르는 숫자가 써있다.\n");
			printf("%s\n", raptopPassword);
			break;
		case hardBread:
			printf("딱딱한 빵이 있다 먹을까\n");
			printf("1. 먹는다 2. 납둔다\n");
			i = InputNum(1,2);
			if(i==1){
				printf("쩝쩌ㅃ쩌ㅃ쩌ㅃ쩌ㅃ\n");
				life +=5;
				printf("체력이 5 회복 됐다.\n");
				inventory[hardBread]=0;
			}
			else{
				printf("나중에 먹어야지\n");
			}
			break;
		case softBread:
			printf("적신 빵이 있다 먹을까\n");
			printf("1. 먹는다 2. 납둔다\n");
			i = InputNum(1,2);
			if(i==1){
				printf("쩝쩌ㅃ쩌ㅃ쩌ㅃ쩌ㅃ\n");
				life +=10;
				printf("체력이 10 회복 됐다.\n");
				inventory[softBread]=0;
			}
			else{
				printf("나중에 먹어야지\n");
			}
			break;
			
			
		case battery:
			printf("스마트폰을 충전할까?\n");
			printf("1. 한다 2. 안한다.\n");
			i = InputNum(1,2);
			if(i==1){
			
				if(batteryLife){
					if(inventory[phone]||inventory[dischargedPhone]){
						if(inventory[phone]){
							int temp;
							temp = battery;
							if(batteryLife<100-phoneLife){
								phoneLife += batteryLife;
								batteryLife=0;
							}
							else{
								batteryLife -= 100-phoneLife;
								phoneLife = 100;
							}
							
						}
					}
					printf("스마트폰 충전됨\n");
					printf("현재 배터리 : %d%%",phoneLife);
					printf("남은 보조 배터리 : %d%%",batteryLife);
				}
				else{
					printf("보조배터리를 다썼다.\n");
				}
			}
			break;
			
		case dischargedPhone:
			printf("배터리가 없다 충전을 하자.\n");
			break;
			
			
			
		case phone:
			printf("현재 남은 배터리 : %d%%\n",phoneLife);
			printf("1. 자료를 찾아본다. 2. 게임을 한다 3. 납둔다");
			i = InputNum(1,3);
			if(i==1&&phoneLife>=20){
				printf("이상한 숫자를 찾았다.\n");
				printf("%s",doorPhonePassword);
				phoneLife-=20;
				Sleep(3000);
			}
			else if(i==2&&phoneLife>=60){
				printf("게임을 하니 기분이 좋아졌다.\n");
				printf("체력이 5 회복됐다.\n");
				life+=5;
				phoneLife-=60;
			}
			else if(phoneLife>=1) {
				
				printf("그냥 가만히 두자\n");
				phoneLife--;
				
			}
			break;
		default :
			printf("조사해 봤지만 아무것도 없다.\n");
			
	}
	
	Sleep(1000);
	return;
}
