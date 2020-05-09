#include<stdio.h> 

void print_instructions();
void print_instructions(){
 printf("These are the program's instructions\n");
 printf("press [1] To enter sales data\n");
 printf("press [2] To add a new branch\n");
 printf("press [3] To delete a branch\n");
 printf("press [4] To calculate total sales of the company\n");
 printf("press [5] To Calculate the percentage share of each branch\n");
 printf("press [6] To print the month of the peak sales\n");
 printf("press [7] To view sales of a given month for all branches\n");
 printf("press [8] To view sales of a given branch for all months\n");
 printf("press [0] To quit\n");
}

void print_table(float company[30][12]);
void print_table(float company[30][12]){
 printf("\n________________________________________________________________________________________________\n");
 int i,j;
 for(i=0; i<30; i++) {
 	if(company[i][0]!=0)
		printf("\n\nbranch %d: \n",(i+1));
	for(j=0;j<12;j++){
       if(company[i][j]!=0){
       	printf("month %d: ",(j+1));
        printf("%.1f\t", company[i][j]);
         if(j==5){
           printf("\n");
         }
       }
   }
 }
 printf("\n________________________________________________________________________________________________\n");
}
void enter_data(float company[30][12]);
void enter_data(float company[30][12]){
int i,j,k,branch;
printf("Enter desired number of branches: ");
scanf("%d",&branch);

printf("Enter sales data for the following months..\n");	
	for(i=0;i<branch;i++){
		printf("branch %d... \n",(i+1));
		for(j=0;j<12;j++){
			printf("month %d: ",(j+1));
			scanf("%f",&company[i][j]);
		}
	}
	print_table(company);
}

void add_branch(float company[30][12]);
void add_branch(float company[30][12]){
	int i,j,empty_row;
		for(i=0;i<30;i++){
			if(company[i][0]==0){
				empty_row=i;
				break;
			}
		}
	printf("enter sales for new branch..\n");
	for(i=0;i<12;i++){
		printf("month %d: ",(i+1));
		scanf("%f",&company[empty_row][i]);
	}
print_table(company);
}

void delete_branch(float company[30][12]);
void delete_branch(float company[30][12]){
	int i,j,branch_num;
	printf("delete branch: ");
	scanf("%d",&branch_num);
	for(i=0;i<branch_num;i++){
		for(j=0;j<12;j++){
			company[i][j]=0;
		}
		
	}
	print_table(company);
}

float total_sales(float company[30][12]){
	int i,j;
	float sum=0;
	for(i=0;i<30;i++){
		for(j=0;j<12;j++){
			sum+=company[i][j];
		}
	}
	printf("Total sales = %.1f",sum);
	return sum;
}

void percentage_branch(float company[30][12]){
	int i,j;
	float percentage,branch_sum,total_sum;
	total_sum=0.0;
	for(i=0;i<30;i++){
		for(j=0;j<12;j++)
			total_sum+=company[i][j];
	}
	for(i=0;i<30;i++){
		branch_sum=0;
		for(j=0;j<12;j++){
			branch_sum+=company[i][j];
			percentage=((branch_sum/total_sum)*100);
		}
		if(company[i][0]!=0)
		printf("percentage of branch %d= %.2f %% \n",(i+1),percentage);	
	}
}

void peak_month(float company[30][12]);
void peak_month(float company[30][12]){
	int i,j,month;
	float mx[1][1],max= mx[1][1]; 
	for(i=0;i<30;i++){
		for(j=0;j<12;j++){
			if(company[i][j]>max)
				max=company[i][j];
				if(company[i][j]==max)
					month=(j+1);
		}
	}
	printf("\nMonth %d has the peak sales of %.2f.\n",month,max);
}

void bubble_sort(float company[30][12]);
void bubble_sort(float company[30][12]){
	int i,j,n,flag;
	float temp,tmp_array[100];
	printf("Enter number of month: ");
	scanf("%d",&n);
	
	for(i=0;i<30;i++){
		tmp_array[i]=company[i][n-1];
	}
	
	for(i=0;i<12-1;i++){
		flag=0;
		for(j=0;j<11-i;j++){
			if(tmp_array[j]<tmp_array[j+1]){
				temp=tmp_array[j];
				tmp_array[j]=tmp_array[j+1];
				tmp_array[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
		break;
	}

	for(i=0;i<30;i++){
		if(tmp_array[i]!=0){
       		printf("month %d: ",n);
        	printf("%.1f\n", tmp_array[i]);
		}
   }
   
}

void selection_sort(float company[30][12]);
void selection_sort(float company[30][12]){
	int i,j,min,branch_num;
	float temp,tmp_array[100];
	printf("enter number of branch: ");
	scanf("%d",&branch_num);
	
	for(i=0;i<12;i++){
		tmp_array[i]=company[branch_num-1][i];
	}
	   
	for(i=0;i<11;i++){
		min=i;
		for(j=i+1;j<12;j++){
			if(tmp_array[j]>tmp_array[min]){
				min=j;
			}
			if(min!=i){
				temp=tmp_array[i];
				tmp_array[i]=tmp_array[min];
				tmp_array[min]=temp;
			}
		}
	}   
	
 	printf("\n\nbranch %d: \n",branch_num);
	for(j=0;j<12;j++){
       	printf("month %d: ",(j+1));
        printf("%.1f\n", tmp_array[j]);
   }
}

int main(){	
	int input;
	float company[30][12]={0};
	print_instructions();
	while(input!=0){
		printf("\ninput: ");
		scanf("%d",&input);
		
		switch(input){
		case 1:
			enter_data(company);
			break;
		case 2:
			add_branch(company);
			printf("\nyou added a new branch..\n");
			break;
		case 3:
			delete_branch(company);
			printf("\nyou deleted an existing branch..\n");	
			break;	
		case 4:
			total_sales(company);	
			break;
		case 5:
			percentage_branch(company);
			break;
		case 6:
			peak_month(company);
			break;
		case 7:
			bubble_sort(company);
			printf("\nYour branches' sales are now sorted!");
			break;
		case 8:
			selection_sort(company);
			printf("\nYour months' sales are now sorted!");
			break;
		case 0:
			printf("\nYou Just Ended The Program..\n");
			return 0;
		break;
		}
	}
	return 0;
}
