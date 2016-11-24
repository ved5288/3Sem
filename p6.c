#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student {
char*name;
int rollno;
char*dept;
struct student *next;
};

struct student *Slist;

void print()   //I used this function for printing linked list.
{
  struct student *temp;
  temp=Slist;
  while(temp!=NULL)
  {
    printf("%s %d %s\n",temp->name,temp->rollno,temp->dept);
    temp=temp->next;
  }
 // printf("%s %d %s\n",temp->name,temp->rollno,temp->dept);
}


void addAtBack(char*name, int rollno, char*dept) {
	struct student *temp=(struct student*)malloc(sizeof(struct student));
	temp->name= malloc(sizeof(char)*strlen(name));
	strcpy(temp->name,name);
	temp->rollno = rollno;	
	temp->dept = malloc(sizeof(char)*strlen(dept));
	strcpy(temp->dept,dept);
	temp->next = NULL;
	
	struct student *temp1;
	if(temp1==NULL)
	{
		temp1=temp;
	}
	else
	{
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
	}
}

void addAtIndex(char*name, int rollno, char*dept, int k) {
	struct student *temp=(struct student*)malloc(sizeof(struct student));
	temp->name= malloc(sizeof(char)*strlen(name));
	strcpy(temp->name,name);
	temp->rollno = rollno;
	temp->dept = malloc(sizeof(char)*strlen(dept));
	strcpy(temp->name,name);
	temp->next = NULL;



struct student *temp1 = Slist;
int CL=1;
while(temp1->next!=NULL&&CL<k-1)
{
	temp1=temp1->next;
	CL++;
}
temp1->next=temp;

}

int delete(int rollno){
struct student  *temp1=Slist;
int k=-1, CL=1;
while(temp1->next!=NULL)
{
	if(temp1->rollno == k)
	{
		k=1;
		break;
	}
	temp1=temp1->next;
	CL++;
}
if(k==1)
{
	struct student *temp2 = Slist;
	if(CL==1)
	{
		Slist=temp2->next;
		free(temp2);
		return k;
	}
	int i;
	for(i=0;i<CL-2;i++)
	temp2=temp2->next;
	struct student *temp3 = temp2->next;;
	temp2->next=temp3->next;
	free(temp3);
}
return k;
}

int getRollno(int k){
	struct student *temp ;
	temp=(struct student*)malloc(sizeof(struct student));
	temp=Slist;
	int i;
	if(temp!=NULL)
	{
		for(i=0;i<k-1;i++)
		temp=temp->next;
	}
	return temp->rollno;
}

int getDept(char*dept) {
	int count=0;
	struct student *temp;
	temp=(struct student*)malloc(sizeof(struct student));
	temp=Slist;
	if(temp!=NULL)
	{
		while(temp->next!=NULL)
		{
			if(strcmp(temp->dept,dept)==0)
				 count++;
			temp=temp->next;
		}
	}
	return count;
}

int main()
{
Slist = NULL;
struct student *temp=(struct student*)malloc(sizeof(struct student));
temp->name= malloc(sizeof(char)*strlen("v"));
strcpy(temp->name,"v");
temp->rollno = 43;
temp->dept = malloc(sizeof(char)*strlen("CSE"));
strcpy(temp->dept,"CSE");
temp->next = NULL;
Slist  = temp;
addAtBack("Vedant",1,"CSE");
addAtBack("Somani",2,"CSE");
addAtIndex("Som",4,"Chem",4);
addAtIndex("Ani",5,"Chem",9);
addAtIndex("Ved",3,"CSE",3);
printf("count  of persons in CSE is /are:%d\n",getDept("CSE"));
printf("count  of persons in Chem is /are:%d\n",getDept("Chem"));
printf("The roll number at index 3 is: %d\n",getRollno(3));
delete(1);
printf("count  of persons in CSE is /are:%d\n",getDept("CSE"));
}
