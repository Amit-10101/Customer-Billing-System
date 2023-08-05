#include <stdio.h>
int main()
{
	FILE *menu = fopen("menu.txt","r");
	FILE *selected = fopen("selected.txt","w+");
	char items[100];
	//displaying the menu to the customer
	
	printf("S.no Item        Cost   Discount\n");
	while(!feof(menu))
	{
	fgets(items,99,menu);
	printf("%s",items);
	}
	rewind(menu);
	
	//selection of items by the user and adding them to cart
	int select;
	printf("\nNow you can select the items by entering the index of the number : ");
	printf("\nEnter the S.no of the item : ");
	scanf("%d",&select);
	int s_no;
	fscanf(menu,"%d",&s_no);
	char item[200];
	int counter = 0;
	while(select!=0)
	{
		while(select!=s_no)
		{
			fgets(item,199,menu);
			fscanf(menu,"%d",&s_no);
			
			
		}
		fseek(menu,-1,1);
		fgets(item,199,menu);
		fputs(item,selected);
		printf("\nEnter the S.no of the item : ");
		scanf("%d",&select);
		rewind(menu);
		fscanf(menu,"%d",&s_no);
		counter++;	
	}
	
	//de-selection of the selected items: 
	rewind(selected);
	int counter1 = 0;
	int number;
	char dot;
	char thing[15];
	float cost;
	float discount;
	int confirm;
	float bill = 0;
	float final_cost;
	printf("\nNow you can de-select the items that you have selected: ");
	while(counter1!=counter)
	{
		fscanf(selected,"%d",&number);
		fscanf(selected,"%s",&dot);
		fscanf(selected,"%s",thing);
		fscanf(selected,"%f",&cost);
		fscanf(selected,"%f",&discount);
		printf("\nYou have selected %s enter 1 to confirm and 0 to delete : ",thing);
		scanf("%d",&confirm);
		if(confirm==1)
		{
			final_cost = cost-discount;
			bill+=(final_cost);
			printf("\nOrder confirmed");
		}
		else
		{
			printf("\nWe have cancelled the item");
		}
		
		counter1++;
	}
	printf("\n The final bill is %.2f",bill);
	
	
	//payment mode
	int payment;
	printf("\nSelect the payment mode: ");
	printf("\nEnter 1 for cash ,2 for credit card, 3 for UPI: ");
	scanf("%d",&payment);
	if(payment==1)
	{
		printf("\nThank you for visiting our hotel");
	}
	else if(payment==2)
	{
		int pin;
		printf("\nEnter the pin of your credit card: ");
		scanf("%d",&pin);
		printf("\nThank you for visiting our hotel");
	}
	else if(payment==3)
	{
		printf("\nPayment has been recieved ");
		printf("\nThank you for visiting our hotel");
	}
	
	
	
}
