#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int value;
    node* next_key;
    node(int input)
    {
        value=input;
        next_key=NULL;
        return;
    }
};
void insert_values_at_last(node* &start,int input)
{
    node* new_node=new node(input);
    if (start==NULL)
    {
        start=new_node;
        return;
    }
    node* temp=start;
    while (temp->next_key!=NULL)
    {
       temp=temp->next_key;
    }
    temp->next_key=new_node;
}
void display_the_linked_list(node* start)
{
    node* temp=start;
    while (temp!=NULL)
    {
        cout<<temp->value<<"->";
        temp= temp->next_key;
    }
    cout<<"NULL";
}
void merge_two_sorted_linked_list(node* start1,node* start2)
{
    node* new_start=new node(0);
    node* temp_new=new_start;
    while (true)
    {
        if (start1==NULL)
        {
            temp_new->next_key=start2;
            break;
        }
        if (start2==NULL)
        {
            temp_new->next_key=start1;
            break;
        }
        if (start1->value<=start2->value)
        {
            temp_new->next_key=new node(start1->value);
            start1=start1->next_key;
        }
        else
        {
            temp_new->next_key=new node(start2->value);
            start2=start2->next_key;
        }
        temp_new=temp_new->next_key;
    }  
    display_the_linked_list(new_start->next_key); 
}
int main()
{
    int test;
    cin>>test;
    node* start=NULL;
    for (int i = 0; i < test; i++)
    {
        int x;
        cin>>x;
        insert_values_at_last(start,x);
    }
    display_the_linked_list(start);
    cout<<endl;
    /*sort_a_linked_list(start);*/
    int test2;
    cin>>test2;
    node* start2=NULL;
    for (int i = 0; i < test2; i++)
    {
        int y;
        cin>>y;
        insert_values_at_last(start2,y);
    }
    display_the_linked_list(start2);
    cout<<endl;
    merge_two_sorted_linked_list(start,start2);
}