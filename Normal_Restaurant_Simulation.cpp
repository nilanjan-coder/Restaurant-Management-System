/* AUTHOR: NILANJAN DAS

************* NORMAL - RESTAURANT ***************

*/

#include <stdio.h>
#include <string.h>
void main()
{
	int i,user=-1,id_check=0;
	char name_check[20];
	char yes_or_no;
	struct pds
	{
		char name[11];
		int item[5];
	}order[50];
	float itemrevenue[5];
	float x;
	char choice;
	for(;;)
	{
		printf("\n Welcome to PDS-Restaurant!");
		printf("\n Enter a to create new order");
		printf("\n Enter b to delete existing order");
		printf("\n Enter c to serve an order");
		printf("\n Enter d to display item statistics");
		printf("\n Enter e to terminate.");
		printf("\n Enter choice:");
		scanf(" %c",&choice);
		switch(choice)
		{
			case 'a':
			++user;
			printf("\n Create-new-order:");
			printf("\n Enter name:");
			scanf("%s",order[user].name);
			printf("\n Enter the quantity of each item:");
			for(i=0;i<5;i++) scanf("%d",&order[user].item[i]);
			printf("\n The pending orders are:");
			for(int j=0;j<=user;j++)
			{
				printf("\n Customer Name: %s",order[j].name);
				printf("\n Customer Id: %d",j);
				printf("\n The items ordered are:");
				for(int k=0;k<5;k++) printf("\n Item %d - Quantity: %d",k+1,order[j].item[k]);
			}
			break;
			
			case 'b':
			printf("\n Delete-existing-order:");
			printf("\n Enter Id:");
			scanf("%d",&id_check);
			if(id_check<0)
			{
				int j=0;
				printf("\n Enter name:");
				scanf("%s",name_check);
				for(j=0;j<=user;j++)
				{
					if(strcmp(name_check,order[j].name))
					{
						printf("\n Name: %s,Id: %d. Are you sure you want to delete this order?",name_check,j);
						break;
					}
				}
				scanf(" %c",&yes_or_no);
				if(yes_or_no=='Y')
				{
					printf("\n order deleted successfully");
					for(int k=j+1;k<=user;k++)
					{
						order[k-1]=order[k];
					}
					user--;
				}
				else if(yes_or_no=='N')
				{
					printf("\n Deletion of order cancelled");
				}
			}
			else
			{
				int j=0;
				for(j=0;j<=user;j++)
				{
					if(j==id_check)
					{
						printf("\n Name: %s,Id: %d. Are you sure you want to delete this order?",order[j].name,j);
						break;
					}
				}
				scanf(" %c",&yes_or_no);
				if(yes_or_no=='Y')
				{
					printf("\n order deleted successfully");
					for(int k=j+1;k<=user;k++)
					{
						order[k-1]=order[k];
					}
					user--;
				}
				else if(yes_or_no=='N')
				{
					printf("\n Deletion of order cancelled");
				}
			}
			break;
			
			case 'c':
			printf("\n Serve-order");
			printf("\n Order served is:");
			printf("\n Customer Name: %s",order[0].name);
			printf("\n Customer Id: %d",0);
			printf("\n The items ordered are:");
			for(int k1=0;k1<5;k1++) printf("\n Item %d - Quantity: %d",k1+1,order[0].item[k1]);
			for(int k2=1;k2<=user;k2++)
			{
				order[k2-1]=order[k2];
			}
			user--;
			printf("\n The pending orders are:");
			for(int j1=0;j1<=user;j1++)
			{
				printf("\n Customer Name: %s",order[j1].name);
				printf("\n Customer Id: %d",j1);
				printf("\n The items ordered are:");
				for(int k3=0;k3<5;k3++) printf("\n Item %d - Quantity: %d",k3+1,order[j1].item[k3]);
			}
			break;

			case 'd':
			printf("\n Display-item-statistics");
			int qty[10000];
			for(int k6=0;k6<5;k6++) qty[k6]=0;
			for(int k4=0;k4<5;k4++)
			{
				for(int j2=0;j2<=user;j2++)
				{
					qty[k4]=qty[k4]+order[j2].item[k4];
				}
			}
			for(int k5=0;k5<5;k5++)
			printf("\n Item %d is required in Quantity: %d",k5+1,qty[k5]);
			break;
			case 'e':
			return;
		}
	}
}
