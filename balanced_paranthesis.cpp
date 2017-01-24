#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
struct St
{
    char data;
    struct St *next;
}*root=NULL;

struct St* create( char e)
{
    struct St *s=(struct St*)malloc(sizeof(struct St));
    s->data=e;
    s->next=NULL;
    return s;
}

void push(char e)
{
    struct St *st=create(e);
    st->next=root;
    root=st;
}
char pop()
{
    char popped=root->data;
    struct St *pop=root;
    root=root->next;
    pop->next=NULL;
    free(pop);
    return popped;

}
int check(char a, char b)
{
    if((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']')) return 1;
    else return 0;
       /* if (character1 == '(' && character2 == ')')
     return 1;
   else if (character1 == '{' && character2 == '}')
     return 1;
   else if (character1 == '[' && character2 == ']')
     return 1;
   else
     return 0;*/
}

int isBalanced(char exp[])
{
    int i=0;
    while(exp[i])
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);
        else if( exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            char a=pop();
            if(!check(a,exp[i])) return 0;
        }

        i++;
    }
    if(root!=NULL) return 0;
    else return 1;
}

int main()
{   char exp[]="[{abc}]";
    if(isBalanced(exp)) cout<<"balanced"<<endl;
    else cout<<"Not Balanced"<<endl;
    return 0;
}
