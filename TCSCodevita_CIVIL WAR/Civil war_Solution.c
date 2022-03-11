#include<stdio.h>
#include<stdlib.h>
//can be done using 2 stacks ...the only consequence will be the number of push and pop operations will be too much
struct node{
    int power; 
    struct node *next; 
};
struct node *sidechange(struct node *head1){
	struct node *head2=NULL;
	while(head1){
		if(head2==NULL){
		head2=(struct node*)malloc(sizeof(struct node));
		head2->power=head1->power;
		head2->next=NULL;}
		else{
			struct node *newnode=(struct node*)malloc(sizeof(struct node));
			newnode->power=head1->power;
			newnode->next=head2;
			head2=newnode;
		}
		head1=head1->next;
	}
	return head2;
	
}

int main(){
int N;
scanf("%d",&N);
int arr[N];
for(int i=0;i<N;i++){
	if(i==N-1)
	scanf("%d",&arr[i]);
	else
	scanf("%d ",&arr[i]);
}
struct node *head1=(struct node*)malloc(sizeof(struct node));
struct node *head2=(struct node*)malloc(sizeof(struct node));
head1->power=arr[N-1];
head1->next=NULL;
for(int i=N-2;i>-1;i--){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->power=arr[i];
	new->next=head1;
	head1=new;
}
struct node *Iron_pow=NULL,*Captain_pow=NULL;
struct node *consec_count=NULL,*temp;
int whose_turn=1;
while(head1 || head2){
	if(head1){
//			curr_pow=head1->power;
            if(consec_count==NULL){
			head2=sidechange(head1);
			if(head2->power>head1->power){	
					consec_count=head2;
					head2=head2->next;
					consec_count->next=NULL;
				    head1=NULL;
			}
			else{
				consec_count=head1;
				head1=head1->next;
				consec_count->next=NULL;
				head2=NULL;
			}
			
			}
			else{
				if(consec_count->power>0)
				{
					if(head1->power>0){
					temp=head1;
					head1=head1->next;
					temp->next=consec_count;
					consec_count=temp;
				}
				else{
					if(whose_turn==1){
						if(Iron_pow){
							temp=Iron_pow;
							while(temp->next){
								temp=temp->next;
							}
							temp->next=consec_count;
						}
						else{
						Iron_pow=consec_count;
						}
					    consec_count=NULL;
					    whose_turn=0;
					}
					else{
						if(Captain_pow){
							temp=Captain_pow;
							while(temp->next){
								temp=temp->next;
							}
							temp->next=consec_count;
						}
						else{
							Captain_pow=consec_count;
						}
					    consec_count=NULL;
					    whose_turn=1;
					}
					
				}
				}
				else{
					if(whose_turn==1){
						consec_count->next=Iron_pow;
						Iron_pow=consec_count;
					    consec_count=NULL;
					    whose_turn=0;
					}
					else{
						consec_count->next=Captain_pow;
						Captain_pow=consec_count;
						Captain_pow=consec_count;
					    consec_count=NULL;
					    whose_turn=1;
					}
					
				}
			}
				
	}
	else{
		 if(consec_count==NULL){
			head1=sidechange(head2);
			if(head2->power>head1->power){		
					consec_count=head2;
					head2=head2->next;
					consec_count->next=NULL;
				head1=NULL;
			}
			else{
				consec_count=head1;
				head1=head1->next;
				consec_count->next=NULL;
				head2=NULL;
			}
			
			}
			else{
				if(consec_count->power>0){
						if(head2->power>0){
					temp=head2;
					head2=head2->next;
					temp->next=consec_count;
					consec_count=temp;
				}
				else{
						if(whose_turn==1){
						if(Iron_pow){
							temp=Iron_pow;
							while(temp->next){
								temp=temp->next;
							}
							temp->next=consec_count;
						}
						else{
						Iron_pow=consec_count;
						}
					    consec_count=NULL;
					    whose_turn=0;
					}
					else{
						if(Captain_pow){
							temp=Captain_pow;
							while(temp->next){
								temp=temp->next;
							}
							temp->next=consec_count;
						}
						else{
							Captain_pow=consec_count;
						}
					    consec_count=NULL;
					    whose_turn=1;
					}
					
				}
				}
				else{
					if(whose_turn==1){
						consec_count->next=Iron_pow;
						Iron_pow=consec_count;
					    consec_count=NULL;
					    whose_turn=0;
					}
					else{
						consec_count->next=Captain_pow;
						Captain_pow=consec_count;
						Captain_pow=consec_count;
					    consec_count=NULL;
					    whose_turn=1;
					}
					
				}
			
			}
	}
	
}
if(whose_turn==1){
						if(Iron_pow){
							temp=Iron_pow;
							while(temp->next){
								temp=temp->next;
							}
							temp->next=consec_count;
						}
						else{
						Iron_pow=consec_count;
						}
					    consec_count=NULL;
					    whose_turn=0;
					}
					else{
						if(Captain_pow){
							temp=Captain_pow;
							while(temp->next){
								temp=temp->next;
							}
							temp->next=consec_count;
						}
						else{
							Captain_pow=consec_count;
						}
					    consec_count=NULL;
					    whose_turn=1;
					}
					
int ipow=0,cpow=0;
 while(Iron_pow){
 	ipow+=Iron_pow->power;
 	Iron_pow=Iron_pow->next;

 }

 while(Captain_pow){
 	cpow+=Captain_pow->power;
 	Captain_pow=Captain_pow->next;
// 
 }
 if(ipow>cpow)
 printf("%d",ipow-cpow);
 else
 printf("%d",cpow-ipow);
}
