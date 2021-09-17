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
	"������",
	"�ȹ� Ű",
	"��Ʈ ����",
	"USB",
	"������ ��",
	"���� ��",
	"������ ����Ʈ��",
	"����Ʈ��",
	"���� ���͸�",
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

	printf("�ۿ� ������ �ߴµ� ���� �����ִ�.\n");
	Sleep(1000);
	printf("�� ������ �ʴ°ɱ� ? �̴�� �������ּ� ����.\n");
	Sleep(1000);
	printf("���� Ż������.");
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
			printf("ü�� ��� ����");
			return; 
		} 
		printf("���� ü�� : %d \n1. ���� 2. TV 3. ����� \n4. ������ 5. ��Ʈ�� 6.�ȹ����� �̵� \n7. �κ��丮 8. Ż�ⱸ\n",life);
		
		num = InputNum(1, 8);
		system("cls");
		life--;
		
		switch (num)
		{
		case 1:
			if (!LivingRoom_sopa) {
				printf("1. ���� ���� ������.\n");
				printf("2. ������ �д�.\n");

				num = InputNum(1, 2);
				if (num == 1) {
					printf("������ ȹ��\n");
					inventory[remoteControl] = 1;
					LivingRoom_sopa = 1;
				}
				else {
					printf("�ƹ��ϵ� ����.\n");
				}
			}
			else {
				printf("�� �̻� ã���� ����\n");				
			}
			break;

		case 3:
			if(!LivingRoom_refrigerator)
			{
				printf("�Դ� ���� ������ �ִ�. ì���\n");
				printf("1. ì��� 2. �׳� �ΰ� ����.\n");
				num = InputNum(1,2);
				if(num==1){
					printf("������ �� ȹ��\n");
					inventory[hardBread]=1;
					LivingRoom_refrigerator=1;
				}
				else{
					printf("�ǵ��� ����\n");
				}
			}
			else{
				printf("�� �̻� ã���� ����\n");
			}
			break;
		
		case 4: 
			printf("�������.\n");
			printf("1. ���� ư��. 2. ������ �д�.\n");
			num = InputNum(1,2);
			if(num==1){
				if(inventory[hardBread]){
					printf("1. ���� ���� ���Ŵ�. 2.�׳� �д�\n");
					num = InputNum(1,2);
					if(num==1){
						printf("���� ������. �� ��θ��� ���� �� �ְ���\n");
						inventory[hardBread]=0;
						inventory[softBread]=1;
					}
				}
				else{
					printf("���� ���´�.\n");
				}
			}
			else{
				printf("�ǵ��� ����\n");
			}
			break;
		case 5:
			printf("��Ʈ���� �ִ�.\n");
			printf("1. ��Ʈ���� Ų��. 2. ������ �д�.\n");
			num = InputNum(1, 2);
			if (num == 1) {
				char pw[100];
				system("cls");
				printf("Ű�� ��\n");
				Sleep(1000);
				printf("����\n");
				printf("��й�ȣ�� �ɷ��ִ�. ��й�ȣ�� �Է�����.\n");
				scanf("%s", pw);
				if (!strcmp(pw, raptopPassword)) {
					printf("��й�ȣ�� �¾Ҵ�.\n");
					if (inventory[USB]) {
						printf("USB�� �־���, �Ⱦƺ���\n");
						printf("1. �ȴ´� 2. �׳� ����.\n");
						num = InputNum(1, 2);
						if (num == 1) {
							printf("�̻��� ��ȣ�� ���ִ� �޸����� ã�Ҵ�.\n");
							printf("%s\n", doorRaptopPassword);
							Sleep(3000);
						}
					}
					else {
						printf("�ƹ� �ڷᰡ ����.\n");
					}
				}

				else {
					printf("��й�ȣ�� Ʋ�ȴ�.\n");

				}
			}
			else {
				printf("�׳� ������ ����\n");
			}
			break;

		case 6:
			if (!InnerRoom_open) {
				printf("���� ����ִ°� ����.\n");
				printf("1. �� ���� 2. �� �μ��� 0. ������ �д�\n");
				num = InputNum(0, 2);
				if (!num) {
					break;
				}
				else if (num == 1) {
					if (!inventory[innerRoomKey]) {
						printf("���谡 ���� �� �� ����. ���踦 ã�ƺ���\n");
					}
					else {
						printf("���� ���ȴ�. ������\n");
						InnerRoom_open = 1;
						Sleep(500);
						system("cls");
						InnerRoom();
					}
				}
				else {
					printf("��...\n");
					Sleep(1000);
					printf("�� �ϸ� �μ����� ������..\n");
					printf("ü���� 5 �𿴴�.\n");
					Sleep(1000);
					life-=5;
					InnerRoom_doorLife--;
					if(!InnerRoom_doorLife){
						printf("���� �ν�����. ������\n");
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
			printf("��й�ȣ : \n");
			scanf("%s", pw);
			if (!strcmp(pw, doorRaptopPassword)) {
				system("cls");
				printf("Ż�� ����\n");
				Sleep(1000);
				return;
			}
			else {
				printf("Ʋ�ȴ� �ٽ� ã�ƺ���\n");
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
			printf("ü�� ��� ����");
			return; 
		} 
		printf("���� ü�� : %d\n1. å 2. ħ�� 3. ���� \n4. �κ��丮 0. ������\n",life);

		num = InputNum(0, 4);
		life--;
		system("cls");
		switch (num)
		{
		case 0:
			printf("�ȹ��� ���Դ�.\n");
			return;
		case 1:
			printf("å�� �ִ�.\n1. å�� ����. 2.������ �д�.\n");
			num = InputNum(1, 2);
			if (num == 1) {
				printf("å���� ���ڰ� �����ִ� ���̸� ã�Ҵ�. Ȯ���غ���\n");
				inventory[bookHintPaper] = 1;
			}
			else {
				printf("�׳� ������ ����.\n");
			}
			break;
		case 2:
			printf("1. �̺� 2. ��Ʈ���� 3. ���� 4. ������ �д�.\n");
			num = InputNum(1, 4);
			if (num == 1) {
				printf("1. �̺��� �����. 2. ������ �д�.\n");
				num = InputNum(1, 2);
				if (num == 1) {
					printf("���и� ������.\n");
				}
				else {
					printf("�׳� ������ ����\n");
				}
			}
			else if (num == 2) {
				printf("1. ��Ʈ������ �����. 2. ������ �д�.\n");
				num = InputNum(1, 2);
				if (num == 1) {
					printf("������ �ִ� USB�� ã�Ҵ�.\n");
					inventory[USB] = 1;
				}
				else {
					printf("�׳� ������ ����\n");
				}
			}
			else if (num == 3) {
				if(!InnerRoom_pillow){
				
					printf("1. ���Ը� �����. 2. ������ �д�.\n");
					num = InputNum(1, 2);
					if (num == 1) {
						printf("����Ʈ�� ȹ��.\n");
						printf("�ٵ� ���͸��� ����\n");
						inventory[dischargedPhone]=1; 
						InnerRoom_pillow=1;
					}
					else {
						printf("�׳� ������ ����\n");
					}
				}
				else{
					printf("�� �̻� ã���� ����\n");
				}
			}
			break;
		
		case 3:
			printf("1. ���� 2. û���� 3. ������ �α�\n");
			num = InputNum(1,3);
			if(num==1){
				if(!InnerRoom_jacket){
				
					printf("1. �ָӴϸ� ������. 2.������ �д�.\n");
					num = InputNum(1,2);
					if(num==1){
						printf("���� ���͸��� ã�Ҵ�. �������\n");
						inventory[battery] =1;
						InnerRoom_jacket=1;
					}
					else{
						printf("������ ����.\n");
					}
				}
				else{
				printf("�� �Ұ� ����.\n");
				} 
				 
			}
			else if(num==2){
				printf("�ƹ��͵� ����.\n");
			}
			else{
				printf("������ ����");
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
			printf("�ٽ� �Է�\n");
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
	
	printf("���� ü�� : %d\n",life);
	
	for (i = 0; i < count; i++) {
		printf("%d. %s ", i + 1, itemName[item[i]]);
		if ((i+1) % 3 == 0) {
			printf("\n");
		}
	}
	printf("0. ������\n");

	i = InputNum(0, count);
	if (!i) {
		return;
	}
	switch(item[i-1]){
		
		case remoteControl:
			if(!inventory[innerRoomKey])
			printf("������ �ȿ� �����ִ� �ȹ� ���踦 ã�Ҵ�.\n");
			inventory[innerRoomKey] = 1;
			break;
			
		case bookHintPaper:
			printf("��� ������ �𸣴� ���ڰ� ���ִ�.\n");
			printf("%s\n", raptopPassword);
			break;
		case hardBread:
			printf("������ ���� �ִ� ������\n");
			printf("1. �Դ´� 2. ���д�\n");
			i = InputNum(1,2);
			if(i==1){
				printf("��¼��¼��¼��¼��\n");
				life +=5;
				printf("ü���� 5 ȸ�� �ƴ�.\n");
				inventory[hardBread]=0;
			}
			else{
				printf("���߿� �Ծ����\n");
			}
			break;
		case softBread:
			printf("���� ���� �ִ� ������\n");
			printf("1. �Դ´� 2. ���д�\n");
			i = InputNum(1,2);
			if(i==1){
				printf("��¼��¼��¼��¼��\n");
				life +=10;
				printf("ü���� 10 ȸ�� �ƴ�.\n");
				inventory[softBread]=0;
			}
			else{
				printf("���߿� �Ծ����\n");
			}
			break;
			
			
		case battery:
			printf("����Ʈ���� �����ұ�?\n");
			printf("1. �Ѵ� 2. ���Ѵ�.\n");
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
					printf("����Ʈ�� ������\n");
					printf("���� ���͸� : %d%%",phoneLife);
					printf("���� ���� ���͸� : %d%%",batteryLife);
				}
				else{
					printf("�������͸��� �ٽ��.\n");
				}
			}
			break;
			
		case dischargedPhone:
			printf("���͸��� ���� ������ ����.\n");
			break;
			
			
			
		case phone:
			printf("���� ���� ���͸� : %d%%\n",phoneLife);
			printf("1. �ڷḦ ã�ƺ���. 2. ������ �Ѵ� 3. ���д�");
			i = InputNum(1,3);
			if(i==1&&phoneLife>=20){
				printf("�̻��� ���ڸ� ã�Ҵ�.\n");
				printf("%s",doorPhonePassword);
				phoneLife-=20;
				Sleep(3000);
			}
			else if(i==2&&phoneLife>=60){
				printf("������ �ϴ� ����� ��������.\n");
				printf("ü���� 5 ȸ���ƴ�.\n");
				life+=5;
				phoneLife-=60;
			}
			else if(phoneLife>=1) {
				
				printf("�׳� ������ ����\n");
				phoneLife--;
				
			}
			break;
		default :
			printf("������ ������ �ƹ��͵� ����.\n");
			
	}
	
	Sleep(1000);
	return;
}
