#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node *link;
};

void Input(struct node *Head[],struct node *Temp[],int u,int v)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->val=v;
    temp->link=NULL;

    if(Head[u]==NULL)
    {
        Head[u]=temp;
        Temp[u]=temp;
    }
    else
    {
        Temp[u]->link=temp;
        Temp[u]=temp;
    }
}

int Deq(int *front,int Store_QU[])
{
    int D;
    D = Store_QU[*front];
    (*front)= (*front)+1;
    return D;
}

void Enq(int Store_QU[],int x,int *front ,int *rear)
{
    if(*front == -1 && *rear == -1) {
        *front=0;
        *rear=0;
        Store_QU[*rear]=x;
    }

    else {
        (*rear) = (*rear) + 1;
        Store_QU[*rear]=x;
    }
}

void BFS(struct node *Head[], struct node *Temp[], struct node *He2[], struct node *Root2[], int Store_QU[], int V)
{
    int front=-1, rear=-1;
    int FLAG[V];

    for(int a=1;a<V;++a)
        FLAG[a]=0;

    FLAG[0]=1;
    int u=0;
    while(1)
        {
            if(front>rear) break;

            Temp[u]=Head[u];
            while(Temp[u]!=NULL)
            {
                if(FLAG[Temp[u]->val] == 0)
                {
                    Enq(Store_QU,Temp[u] -> val,&front,&rear);
                    FLAG [Temp[u] -> val] = 1;
                    Root2[u]=He2[u];
                    while(Root2[u] != NULL)
                    {
                        Input(He2, Root2, Temp[u] -> val, Root2[u] -> val);
                        Root2[u] = Root2[u] -> link;
                    }
                Input(He2,Root2,Temp[u]->val,Temp[u]->val);
                }
				Temp[u] = Temp[u] -> link;
            }
			u = Deq(&front, Store_QU);
        }
}


void Print(struct node *He2[], struct node *Root2[], int V)
{
	for(int i=0; i< V; ++i)
	{
		Root2[i]=He2[i];
		while(Root2[i] != NULL)
			{
                printf("%d ", Root2[i] -> val);
				Root2[i] = Root2[i] -> link;
			}
        if(He2[i]==NULL)
            printf("NIL");
        printf("\n");
	}
}

int main()
{
    int test,V,E,u,v,Store_QU[500];
    scanf("%d",&test);

    for(int k=0; k<test; ++k)
    {
        scanf("%d%d",&V,&E);
        struct node *Temp[V], *Head[V];
		struct node *Root2[V], *He2[V];

        for(int i=0; i<V; ++i)
        {
            Head[i]=NULL;
            Temp[i]=NULL;
			He2[i]=NULL;
			Root2[i]==NULL;
        }

        for(int b=0;b<E;++b)
        {
            scanf("%d%d",&u,&v);
            Input(Head,Temp,u,v);
        }
		Input(He2, Root2, 0,0);
        BFS(Head, Temp, He2, Root2, Store_QU, V);
		Print(He2, Root2, V);
    }
}
