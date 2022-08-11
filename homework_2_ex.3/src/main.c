#include <stdio.h>
#define MAX 100
/*Представете си, че имате фирма за отдаване на каравани и
кемпери под наем, за която трябва да разработите софтуер. Вие сте малка
фирма и имате общо 3 каравани на цена 90 лв. на ден и 3 кемпера на цена
100 лв. на ден. Декларирайте променливи за броя на караваните, цената
на караваните, броя на кемперите и цената им. Направете меню, което
пита клиента каравана или кемпер ще иска. Направете променлива, в която
да се събират парите, които клиента дължи на компанията. Принтирайте
резултата*/

struct User
{
	char name[20];
	int discount;
	int countOfCaravans;
	int daysForCaravan;
	int countOfCempers;
	int daysForCemper;
	int position;
};
struct User arr_users[MAX];
int countOfUsers = 0;

int main()
{
	int countOfCaravans = 3;
	int countOfCempers = 3;
	int pricePerCaravan = 90;
	int pricePerCemper = 100;
	int choice;
	char answer;
	
account:
	printf("\nWelcome to Caravanlandiq\nDo you have an account?{Y/n}");
	scanf(" %c", &answer);
	if(answer == 'n')
	{
		int position = countOfUsers;
		countOfUsers++;
		printf("Lets make one!");
		printf("Enter your name: ");
		scanf("%s", arr_users[position].name);
		arr_users[position].position = position;
		arr_users[position].countOfCaravans = 0;
		arr_users[position].countOfCempers = 0;
		arr_users[position].discount = 0;

		printf("Welcome! Lets hire!\n");
		
		option:
			printf("Caravan - 90lv per day\nCemper - 100lv per day\n");
			do
			{
				printf("Chose: 1.Caravan or 2.Cemper: ");
				scanf("%d", &choice);
			} while (choice != 1 && choice != 2);
			
			if(choice == 1)
			{
				int count;
				int days;
				int bill;
				if(countOfCaravans == 0)
				{
					printf("There is no available caravan");
				}
				else
				{
					printf("%d caravans are available\n", countOfCaravans);
					do
					{
						printf("How  much caravans you want to hire? - ");
						scanf("%d", &count);
					} while (count > countOfCaravans);

					countOfCaravans-= count;
					if(count > 1)
					{
						printf("How many days you want hire the caravans for(in days): ");
						scanf("%d", &days);
					}
					else
					{
						printf("How many days you want hire the caravan for(in days): ");
						scanf("%d", &days);
					}
					bill = days * pricePerCaravan * count;
					arr_users[position].discount += bill;
					arr_users[position].countOfCaravans += count;
					arr_users[position].daysForCaravan += days;

					char choice2;
					printf("Do you want to hire something else[Y/n]: ");
					scanf(" %c", &choice2);

					if(choice2 == 'n')
					{
						printf("You have to pay %d lv", arr_users[position].discount);
						goto account;
					}
					else if(choice2 == 'Y')
					{
						goto option;
					}
				}
			}
			else
			{
				int count;
				int days;
				int bill;
				if(countOfCempers == 0)
				{
					printf("There is no available cemper");
				}
				else
				{
					printf("%d cempers are available\n", countOfCempers);
					do
					{
						printf("How  much cempers you want to hire? - ");
						scanf("%d", &count);
					} while (count > countOfCempers);

					countOfCempers-= count;
					if(count > 1)
					{
						printf("How many days you want hire the cempers for(in days): ");
						scanf("%d", &days);
					}
					else
					{
						printf("How many days you want hire the cemper for(in days): ");
						scanf("%d", &days);
					}
					bill = days * pricePerCemper * count;
					arr_users[position].discount += bill;
					arr_users[position].countOfCempers += count;
					arr_users[position].daysForCemper += days;

					char choice2;
					printf("Do you want to hire something else[Y/n]: ");
					scanf(" %c", &choice2);

					if(choice2 == 'n')
					{
						printf("You have to pay %d lv\n", arr_users[position].discount);
						goto account;
					}
					else if(choice2 == 'Y')
					{
						goto option;
					}
				}
			}
	}
	else if(answer == 'Y')
	{
		char name[20];
		printf("Enter your name: ");
		scanf("%s", name);

		for (int i = 0; i < countOfUsers; i++)
		{
			int compare = strcmp(name, arr_users[i].name);
			if(compare == 0)
			{
				printf("Info for your account:\n");
				
				printf("Name: %s\tDiscount: %d\tCaravans:%d\tDays for caravan:%d\tCempers: %d\t Days for cemper:%d\t Position: %d\n", arr_users[i].name, arr_users[i].discount
				, arr_users[i].countOfCaravans,arr_users[i].daysForCaravan, arr_users[i].countOfCempers,arr_users[i].daysForCemper, 
				arr_users[i].position);
				int choice4;
				printf("\nHallo %s\n", arr_users[i].name);
				printf("Choose option: \n1.Hire\n2.Bring back\n3.Log out\n");
				scanf("%d", &choice4);
				if(choice4 == 1)
				{
				 option2:
						printf("Caravan - 90lv per day\nCemper - 100lv per day\n");
						do
						{
							printf("Chose: 1.Caravan or 2.Cemper: ");
							scanf("%d", &choice);
						} while (choice != 1 && choice != 2);
						
						if(choice == 1)
						{
							int count;
							int days;
							int bill;
							if(countOfCaravans == 0)
							{
								printf("There is no available caravan");
							}
							else
							{
								printf("%d caravans are available\n", countOfCaravans);
								do
								{
									printf("How  much caravans you want to hire? - ");
									scanf("%d", &count);
								} while (count > countOfCaravans);

								countOfCaravans-= count;
								if(count > 1)
								{
									printf("How many days you want hire the caravans for(in days): ");
									scanf("%d", &days);
								}
								else
								{
									printf("How many days you want hire the caravan for(in days): ");
									scanf("%d", &days);
								}
								bill = days * pricePerCaravan * count;
								arr_users[i].discount += bill;
								arr_users[i].countOfCaravans += count;
								arr_users[i].daysForCaravan += days;

								char choice2;
								printf("Do you want to hire something else[Y/n]: ");
								scanf(" %c", &choice2);

								if(choice2 == 'n')
								{
									printf("You have to pay %d lv", arr_users[i].discount);
									goto account;
								}
								else if(choice2 == 'Y')
								{
									goto option2;
								}
							}
						}
						else
						{
							int count;
							int days;
							int bill;
							if(countOfCempers == 0)
							{
								printf("There is no available cemper");
							}
							else
							{
								printf("%d cempers are available\n", countOfCempers);
								do
								{
									printf("How  much cempers you want to hire? - ");
									scanf("%d", &count);
								} while (count > countOfCempers);

								countOfCempers-= count;
								if(count > 1)
								{
									printf("How many days you want hire the cempers for(in days): ");
									scanf("%d", &days);
								}
								else
								{
									printf("How many days you want hire the cemper for(in days): ");
									scanf("%d", &days);
								}
								bill = days * pricePerCemper * count;
								arr_users[i].discount += bill;
								arr_users[i].countOfCempers += count;
								arr_users[i].daysForCemper += days;

								char choice2;
								printf("Do you want to hire something else[Y/n]: ");
								scanf(" %c", &choice2);

								if(choice2 == 'n')
								{
									printf("You have to pay %d lv\n", arr_users[i].discount);
									goto account;
									
								}
								else if(choice2 == 'Y')
								{
									goto option2;
								}
							}
						}
				}
				else if(choice4 == 2)
				{
					int choice5;
					printf("Bring back:\n1.Caravan\n2.Cemper\n3.All\n");
					scanf(" %d", &choice5);
					if(choice5 == 1)
					{
						int temp = arr_users[i].countOfCaravans;
						int days = arr_users[i].daysForCaravan;
						countOfCaravans = arr_users[i].countOfCaravans;
						arr_users[i].countOfCaravans = 0;
						arr_users[i].daysForCaravan = 0;
						arr_users[i].discount -= temp * pricePerCaravan * days;

					}
					else if(choice5 == 2)
					{
						int temp = arr_users[i].countOfCempers;
						int days = arr_users[i].daysForCemper;
						countOfCempers = arr_users[i].countOfCempers;
						arr_users[i].countOfCempers = 0;
						arr_users[i].daysForCemper = 0;
						arr_users[i].discount -= temp * pricePerCemper * days;
					}
					else
					{
						countOfCaravans = arr_users[i].countOfCaravans;
						countOfCempers = arr_users[i].countOfCempers;
						arr_users[i].countOfCaravans = 0;
						arr_users[i].countOfCempers = 0;
						arr_users[i].discount = 0;
					}
					goto account;
				}
				else
				{
					goto account;
				}
			}
		}
	}
	/*for (int i = 0; i < countOfUsers; i++)
	{
		printf("Name: %s\tDiscount: %d\tCaravans: %d\tCempers: %d\tPosition: %d\n", arr_users[i].name, arr_users[i].discount
		, arr_users[i].countOfCaravans, arr_users[i].countOfCempers, 
		arr_users[i].position);
	}*/
	
	return (0);
}