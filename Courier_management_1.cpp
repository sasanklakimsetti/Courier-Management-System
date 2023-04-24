//COURIER MANAGEMENT SYSTEM
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct courier //structure
{
	int id;
	char sname[100];
	char saddress[100];
	char rname[100];
	char raddress[100];	
}c; //definition of structure

void insert() //Adds data into the file
{
	courier *c; //structure pointer
	FILE *fp; //file pointer
	int n,i;
	printf("\nEnter No.of Data Entries: ");
	scanf("%d",&n);
	printf("\nNOTE: Please don't give spaces between the entries.Use underscores instead\n");
	c = (courier*)calloc(n,sizeof(courier));
	fp = fopen("Courier Data.txt","a"); //opens the file in append mode
	for(i=0;i<n;i++)
	{
		printf("\nEnter Courier ID: ");
		scanf("%d",&c[i].id);
		fflush(stdin);
		printf("\nEnter Sender Name: ");
		scanf("%s",c[i].sname);
		fflush(stdin);
		printf("\nEnter Sender Adddress: ");
		scanf("%s",c[i].saddress);
		fflush(stdin);
		printf("\nEnter Receiver Name: ");
		scanf("%s",c[i].rname);
		fflush(stdin);
		printf("\nEnter Receiver Address: ");
		scanf("%s",c[i].raddress);
		fflush(stdin);
		fwrite(&c[i],sizeof(courier),1,fp);
		printf("\nSuccessfully Inserted");
	}
	fclose(fp); //closes the file
}
void display() //displays the data entries of file on screen
{
	courier c1;
	FILE *fp;
	fp = fopen("Courier Data.txt","r"); //opens the file in read mode
	if (fp==NULL)
	{
		printf("\nError opening in file");
	}
	printf("\nCOURIER ID\tSENDER NAME\tSENDER ADDRESS\tRECEIVER NAME\tRECEIVER ADDRESS\n--------------------------------------------------------------------------------------");
	while(fread(&c1,sizeof(courier),1,fp)) //reads the file 
	{
	printf("\n%-10d\t%-10s\t%-10s\t%-10s\t%-10s\n", c1.id, c1.sname, c1.saddress, c1.rname, c1.raddress);
	}
	fclose(fp);
}
void search() //searches the required data entry from file and display on screen
{
	courier c1;
	FILE *fp;
	fp = fopen("Courier Data.txt","r");
	int se,id;
	char sname[100],saddress[100],rname[100],raddress[100];
	int found=0;
	if (fp==NULL)
	{
		printf("\nError opening in file");
	}
	do
	{
		do
		{
    		printf("\nSearch by:\n7-Courier ID\n8-Sender Name\n9-Sender Address\n10-Receiever Name\n11-Receiver Address\n12.Home\n");
    		printf("Enter the Search Filter: \n");
    		scanf("%d",&se);
    		switch(se)
    		{
    			case 7:
    				printf("\nEnter the Courier ID to search: ");
    				scanf("%d",&id);
    				fflush(stdin);
    				while(fread(&c1,sizeof(courier),1,fp)) //reads the file
					{
						if(c1.id==id)
						{
							found = 1;
							printf("\nCOURIER ID\tSENDER NAME\tSENDER ADDRESS\tRECEIVER NAME\tRECEIVER ADDRESS\n--------------------------------------------------------------------------------------");
							printf("\n%-10d\t%-10s\t%-10s\t%-10s\t%-10s\n", c1.id, c1.sname, c1.saddress, c1.rname, c1.raddress);
							break;
						}
					}
					if(!found)
					{
						printf("\nCourier with the ID not found");
					}
					fclose(fp); //closes the file
					break;
				case 8:
					printf("\nEnter the Sender Name to search: ");
					scanf("%s",sname);
					fflush(stdin); //to flush the previous input
					while(fread(&c1,sizeof(courier),1,fp))
					{
						if(strcmp(c1.sname,sname)==0) //string comparision
						{
							found = 1;
							printf("\nCOURIER ID\tSENDER NAME\tSENDER ADDRESS\tRECEIVER NAME\tRECEIVER ADDRESS\n--------------------------------------------------------------------------------------");
							printf("\n%-10d\t%-10s\t%-10s\t%-10s\t%-10s\n", c1.id, c1.sname, c1.saddress, c1.rname, c1.raddress);
							break;
						}
					}
					if(!found)
					{
						printf("\nCourier with the Sender Name  not found");
					}
					fclose(fp);
					break;
				case 9:
					printf("\nEnter the Sender Address to search: ");
					scanf("%s",saddress);
					fflush(stdin);
					while(fread(&c1,sizeof(courier),1,fp))
					{
						if(strcmp(c1.saddress,saddress)==0)
						{
							found = 1;
							printf("\nCOURIER ID\tSENDER NAME\tSENDER ADDRESS\tRECEIVER NAME\tRECEIVER ADDRESS\n--------------------------------------------------------------------------------------");
							printf("\n%-10d\t%-10s\t%-10s\t%-10s\t%-10s\n", c1.id, c1.sname, c1.saddress, c1.rname, c1.raddress);
							break;
						}
					}
					if(!found)
					{
						printf("\nCourier with the Sender Address  not found");
					}
					fclose(fp);
					break;
				case 10:
					printf("\nEnter the Receiver Name to search: ");
					scanf("%s",rname);
					fflush(stdin);
					while(fread(&c1,sizeof(courier),1,fp))
					{
						if(strcmp(c1.rname,rname)==0)
						{
							found = 1;
							printf("\nCOURIER ID\tSENDER NAME\tSENDER ADDRESS\tRECEIVER NAME\tRECEIVER ADDRESS\n--------------------------------------------------------------------------------------");
							printf("\n%-10d\t%-10s\t%-10s\t%-10s\t%-10s\n", c1.id, c1.sname, c1.saddress, c1.rname, c1.raddress);
							break;
						}
					}
					if(!found)
					{
						printf("\nCourier with the Receiver Name  not found");
					}
					fclose(fp);
					break;
				case 11:
					printf("\nEnter the Receiver Address to search: ");
					scanf("%s",raddress);
					fflush(stdin);
					while(fread(&c1,sizeof(courier),1,fp))
					{
						if(strcmp(c1.raddress,raddress)==0)
						{
							found = 1;
							printf("\nCOURIER ID\tSENDER NAME\tSENDER ADDRESS\tRECEIVER NAME\tRECEIVER ADDRESS\n--------------------------------------------------------------------------------------");
							printf("\n%-10d\t%-10s\t%-10s\t%-10s\t%-10s\n", c1.id, c1.sname, c1.saddress, c1.rname, c1.raddress);
							break;
						}
					}
					if(!found)
					{
						printf("\nCourier with the Receiver Address  not found");
					}
					fclose(fp);
					break;
				case 12:
					break;
				default:
					break;				
			}
		}while(!se>12); //runs whenver the search filter is less than 12
	}while(!se>6); //runs whenever the option is less than 6
	fclose(fp);
}
void update() //updates the required data entry
{
	courier c1;
	FILE *fp,*fp1;
	int uid,found=0,up;
	fp = fopen("Courier Data.txt","r"); //opens the file Courier Data in read mode
	fp1 = fopen("temp.txt","w"); //opens the file temp in write mode
	if(fp==NULL)
	{
		printf("\nError in opening the file");
	}
	if(fp1==NULL)
	{
		printf("\nError in creating the file");
	}
	printf("\nEnter the Courier ID to update: ");
	scanf("%d",&uid);
	fflush(stdin);
	while(fread(&c1,sizeof(courier),1,fp))
	{
		if(c1.id==uid)
		{
			found = 1;
			printf("\nTo update\n13-Sender Name\n14-Sender Address\n15-Receiver Name\n16-Receiver Address\n17-Home");
			printf("\nEnter the Update Filter: "); //update filter
			scanf("%d",&up);
			switch(up)
			{
				case 13:
					printf("\nEnter the new Sender Name: ");
					scanf("%s",c1.sname);
					fflush(stdin);
					printf("\nSender Name successfully Updated");
					break;
				case 14:
					printf("\nEnter the new Sender Address: ");
					scanf("%s",c1.saddress);
					fflush(stdin);
					printf("\nSender Address successfully updated");
					break;
				case 15:
					printf("\nEnter the new Receiver Name: ");
					scanf("%s",c1.rname);
					fflush(stdin);
					printf("\nReceiver Name successfully updated");
					break;
				case 16:
					printf("Enter the new Receiver Address: ");
					scanf("%s",c1.raddress);
					fflush(stdin);
					printf("\nReceiver Address successfully updated");
					break;
				case 17:
					break;
				default:
					break;
			}
		}
		fwrite(&c1,sizeof(courier),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found)
	{
	fp1 = fopen("temp.txt","r");
	fp = fopen("Courier Data.txt","w");
	while(fread(&c1,sizeof(courier),1,fp1))
	{
		fwrite(&c1,sizeof(courier),1,fp); //saves the updated data into file
	}
	fclose(fp);
	fclose(fp1);
	}
	else
	{
		printf("\nData not found");
	}
	exit;
}
void del() //deletes the required data entry
{
	courier c1;
	FILE *fp,*fp1;
	int did,found=0;
	fp = fopen("Courier Data.txt","r");
	fp1 = fopen("temp.txt","w");
	if(fp==NULL)
	{
		printf("\nError in opening the file");
	}
	if(fp1==NULL)
	{
		printf("\nError in creating the file");
	}
	printf("\nEnter the id to delete: ");
	scanf("%d",&did);
	fflush(stdin);
	while(fread(&c1,sizeof(courier),1,fp))
	{
		if(c1.id==did)	
		{
			found = 1;
		}
		else
		{
			fwrite(&c1,sizeof(courier),1,fp1); //opens the file temp in write mode
		}
	}
	fclose(fp);
	fclose(fp1);
	if(found)
	{
		fp1 = fopen("temp.txt","r");
		fp = fopen("Courier Data.txt","w");
		while(fread(&c1,sizeof(courier),1,fp1))
		{
			fwrite(&c1,sizeof(courier),1,fp);
		}
		fclose(fp);
		fclose(fp1);
		printf("\nData successfully removed");
	}
	if(!found)
	{
		printf("\nData not found");
	}
}
void sort() //sorts the data entries in ascending order according to Courier ID
{
	courier *c,c1;
	FILE *fp;
	fp = fopen("Courier Data.txt","r");
	fseek(fp,0,SEEK_END); //seeks the file
	int n = ftell(fp)/sizeof(courier); 
	c = (courier*)calloc(n,sizeof(courier)); //memory allocation
	
	rewind(fp);
	for(int i=0;i<n;i++)
	{
		fread(&c[i],sizeof(courier),1,fp);
	}
	fclose(fp);
	//bubble sort
	for(int i=0;i<n-1;i++)
	{
		int flag = 0;
		for(int j=0;j<n-1-i;j++)
		{
			if(c[j].id>c[j+1].id)
			{
				c1 = c[j];
				c[j] = c[j+1];
				c[j+1] = c1;
				flag = 1;
			}
		}
	}
	fp = fopen("Courier Data.txt","w");
	printf("\nCOURIER ID\tSENDER NAME\tSENDER ADDRESS\tRECEIVER NAME\tRECEIVER ADDRESS\n--------------------------------------------------------------------------------------");
	for(int i=0;i<n;i++)
	{
		printf("\n%-10d\t%-10s\t%-10s\t%-10s\t%-10s\n", c[i].id, c[i].sname, c[i].saddress, c[i].rname, c[i].raddress);
		fwrite(&c[i],sizeof(courier),1,fp);
	}
	fclose(fp);
}
main()
{
	printf("\n\n\t\t*******************************      LOGIN ACCOUNT      *******************************\t\t\n\n");
	printf("\n\t\t\tDISCLAIMER\n\n\t\tConsole will automatically prompt you to enter User ID or Password if they are wrong\t\t\n\n");
	int usr,pass;
	//User ID = 1254
	//Password = 4521
	do
	{
		printf("\nEnter your User ID: ");
		scanf("%d",&usr);
	}while(usr!=1254);
	do
	{
		printf("\nEnter your Password: ");
		scanf("%d",&pass);
	}while(pass!=4521);
	int ch;
	do
	{
		printf("\n1.Insert");
		printf("\n2.Display");
		printf("\n3.Search");
		printf("\n4.Update");
		printf("\n5.Delete");
		printf("\n6.Sort");
		printf("\n0.Exit");
		
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				search();
				break;
			case 4:
				update();
				break;
			case 5:
				del();
				break;
			case 6:
				sort();
				break;
			case 0:
				break;
			default:
				break;
		}
	}while(ch!=0); //runs when the choice is not equal to 0
	return 0;
}
