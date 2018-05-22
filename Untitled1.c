#include<stdio.h>
#include<string.h>

int main()
{
    int z;
    node *t1,*t2;
    p1=(node*)malloc(sizeof(node));
    p2=(node*)malloc(sizeof(node));
    tail=(node*)malloc(sizeof(node));
    head=createNode(1);
    temp=head;
    for(i=2;i<=100;i++)
    {
        p1=temp;
        temp->next=createNode(i);
        temp=temp->next;
        p2=temp;
        p2->prev=p1;
        if(i==100)
            tail=p2;
    }
    temp=head;
    while(temp!=NULL)
    {
        switch(temp->info)
        {
            /*-----------------FOR LADDERS---------------*/
        case 8: temp->lad=lsearch(31,temp);
             break;
        case 15: temp->lad=lsearch(97,temp);
             break;
        case 27: temp->lad=lsearch(53,temp);
             break;
        case 42: temp->lad=lsearch(81,temp);
             break;
        case 66: temp->lad=lsearch(87,temp);
             break;
             /*-----------------FOR SNAKES---------------*/
        case 24: temp->snake=ssearch(2,temp);
             break;
        case 99: temp->snake=ssearch(6,temp);
             break;
        case 55: temp->snake=ssearch(13,temp);
             break;
        case 88: temp->snake=ssearch(67,temp);
             break;
        case 71: temp->snake=ssearch(29,temp);
             break;
        }
        temp=temp->next;
    }
    w:
    temp=head;
    t1=t2=temp;
    Board();
    int m,n,x,y,flag=0,flag1=0,flag2=0;
    //GAME STARTS HERE-------------------------------->
    while(t1->info!=100 || t2->info!=100 || t1!=NULL || t2!=NULL)
    {
        printf("**Player1** will throw a die:");
        m=ThrowADice();
        if(flag!=0)
            t1->play=' ';
        if(flag1==1)
            {
                t1->play='#';
                flag1=0;
            }
        if(flag==0)
            m--;
        while(m--)
            {
                t1=t1->next;
                if(t1==NULL)
                    break;
            }
        if(t1==NULL);//do nothing
        else if(t1->info==100)
        {
            t1->play='$';
            getch();
            Board();
            printf("**********CONGRATULATIONS! PLAYER 1 WINS THE GAME**********");
            getch();
            printf("\n\t\tPress any key to EXIT!");
            getch();
            return 0;
        }
        else if(t1->snake!=NULL)
        {
            t1->play='$';
            getch();
            Board();
            printf("OOPS! SNAAAAAAAKE...\n");
            getch();
            t1->play=' ';
            t1=t1->snake;
            if(t1->info==t2->info && t1->info!=1 && t2->info!=1)
            {
                t1->play='&';
                Board();
                flag2=1;
                getch();
            }
            else
            {
                t1->play='$';
                Board();
                getch();
            }
        }
        else if(t1->lad!=NULL)
        {
            t1->play='$';
            getch();
            Board();
            printf("WOW! You got a LADDER...\n");
            getch();
            t1->play=' ';
            t1=t1->lad;
            if(t1->info==t2->info && t1->info!=1 && t2->info!=1)
            {
                t1->play='&';
                flag2=1;
                Board();
                getch();
            }
            else
            {
                t1->play='$';
                Board();
                getch();
            }
        }
        else if(t2->info==t1->info && t1->info!=1 && t2->info!=1)
            {
                t2->play='&';
                flag2=1;
                getch();
                Board();
            }
        else
            {
                if(t2->info==t1->info && t1->info!=1 && t2->info!=1)
                {
                    t2->play='&';
                    flag2=1;
                    getch();
                    Board();
                }
                else
                {
                    t1->play='$';
                    getch();
                    Board();
                }
            }
        printf("**Player2** will throw a die:");
        n=ThrowADice();
        if(flag!=0)
            t2->play=' ';
        if(flag2==1)
            {
                t2->play='$';
                flag2=0;
            }
        if(flag==0)
            n--;
        while(n--)
            {
                t2=t2->next;
                if(t2==NULL)
                    break;
            }
        if(t2==NULL);//Do Nothing
        else if(t2->info==100)
        {
            t2->play='$';
            getch();
            Board();
            printf("**********CONGRATULATIONS! PLAYER 2 WINS THE GAME**********");
            getch();
            printf("\n\t\tPress any key to EXIT!");
            getch();
            return 0;
        }
        if(t2->snake!=NULL)
        {
            t2->play='#';
            getch();
            Board();
            printf("OOPS! SNAAAAAAAKE...");
            getch();
            t2->play=' ';
            t2=t2->snake;
            if(t2->info==t1->info && t1->info!=1 && t2->info!=1)
                {
                    t2->play='&';
                    flag1=1;
                    Board();
                }
            else
                {
                    t2->play='#';
                    Board();
                }
        }
        else if(t2->lad!=NULL)
        {
            t2->play='#';
            getch();
            Board();
            printf("WOW! You got a LADDER...");
            getch();
            t2->play=' ';
            t2=t2->lad;
            if(t2->info==t1->info && t1->info!=1 && t2->info!=1)
                {
                    t2->play='&';
                    flag1=1;
                    Board();
                }
            else
                {
                    t2->play='#';
                    Board();
                }
        }
        else
            {
                if(t2->info==t1->info && t1->info!=1 && t2->info!=1)
                {
                    t2->play='&';
                    flag1=1;
                    getch();
                    Board();
                    flag1=1;
                }
                else
                {
                    t2->play='#';
                    getch();
                    Board();
                }
            }
        flag=1;
    }
    return 0;
}
