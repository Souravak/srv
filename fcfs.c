#include <stdio.h>
struct Node
{
    int id;
    int at;
    int bt;
    int wt;
    int tat;
    int ct;
    int rt;
    int prio;
};
typedef struct Node node;
node pro[20];
int set(int n)
{
    for (int i = 0; i < n; i++)
    {
        pro[i].rt = pro[i].bt;
        pro[i].wt = pro[i].ct = pro[i].tat = 0;
    }
}
int fcfs(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pro[i].at > pro[j].at)
            {
                node temp = pro[i];
                pro[i] = pro[j];
                pro[j] = temp;
            }
        }
    }
    int count = 0;
    int ready[100], front = 0, back = -1;
    for (int time = 0; count < n; time++)
    {
        for (int i = 0; i < n; i++)
        {
            if (pro[i].at == time)
            {
                back++;
                ready[back] = i;
            }
        }
        if (pro[ready[front]].rt > 0) pro[ready[front]].rt--;
        if (pro[ready[front]].rt == 0)
        {
            
            pro[ready[front]].ct = time+1;
            pro[ready[front]].tat = pro[ready[front]].ct - pro[ready[front]].at;
            pro[ready[front]].wt = pro[ready[front]].tat - pro[ready[front]].bt;
            front++;
            count++;
        }
    }
    printf("FCFS");
    float totalwt=0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("\n%i\t%i\t%i\t%i\t%i\t%i\n",pro[i].id, pro[i].at, pro[i].bt, pro[i].ct, pro[i].tat,pro[i].wt);
        totalwt+=pro[i].wt;
    }
    printf("\nAvg WT = %0.2f",totalwt/n);
}

int sjf(int n)
{
    set(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pro[i].at > pro[j].at)
            {
                node temp = pro[i];
                pro[i] = pro[j];
                pro[j] = temp;
            }
        }
    }
    int count = 0;
    int ready[100], front = 0, back = -1;
    for (int time = 0; count < n; time++)
    {
        for (int i = 0; i < n; i++)
        {
            if (pro[i].at == time)
            {
                back++;
                ready[back] = i;
            }
        }
        if (pro[ready[front]].rt > 0) pro[ready[front]].rt--;
        if (pro[ready[front]].rt == 0)
        {
            pro[ready[front]].ct = time+1;
            pro[ready[front]].tat = pro[ready[front]].ct - pro[ready[front]].at;
            pro[ready[front]].wt = pro[ready[front]].tat - pro[ready[front]].bt;
            front++;
            count++;
            if(front>back) continue;
            for(int i=front;i<=back;i++)
            {
                for(int j=i+1;j<=back;j++)
                {
                    if(pro[ready[i]].bt>pro[ready[j]].bt)
                    {
                        int t1=ready[i];
                        ready[i]=ready[j];
                        ready[j]=t1;
                    }
                }
                
            }
        }
    }
    printf("\nSJF");
    float totalwt=0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("\n%i\t%i\t%i\t%i\t%i\t%i\n",pro[i].id, pro[i].at, pro[i].bt, pro[i].ct, pro[i].tat,pro[i].wt);
        totalwt+=pro[i].wt;
    }
    printf("\nAvg WT = %0.2f\n",totalwt/n);
}

int prior(int n)
{
    set(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pro[i].at > pro[j].at)
            {
                node temp = pro[i];
                pro[i] = pro[j];
                pro[j] = temp;
            }
        }
    }
    int tq=2;
    int count = 0;
    int ready[100], front = 0, back = -1;
    for (int time = 0; count < n; time++)
    {
        for (int i = 0; i < n; i++)
        {
            if (pro[i].at == time)
            {
                back++;
                ready[back] = i;
            }
        }
        if (pro[ready[front]].rt > 0) pro[ready[front]].rt--;
        if (pro[ready[front]].rt == 0)
        {
            pro[ready[front]].ct = time+1;
            pro[ready[front]].tat = pro[ready[front]].ct - pro[ready[front]].at;
            pro[ready[front]].wt = pro[ready[front]].tat - pro[ready[front]].bt;
            front++;
            count++;
            if(front>back) continue;
            for(int i=front;i<=back;i++)
            {
                for(int j=i+1;j<=back;j++)
                {
                    if(pro[ready[i]].prio>pro[ready[j]].prio)
                    {
                        int t1=ready[i];
                        ready[i]=ready[j];
                        ready[j]=t1;
                    }
                }
                
            }
        }
    }
    printf("\nPRIORITY");
    float totalwt=0;
    printf("\nPID\tAT\tBT\tPRIO\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("\n%i\t%i\t%i\t%i\t%i\t%i\t%i\n",pro[i].id, pro[i].at, pro[i].bt, pro[i].prio, pro[i].ct, pro[i].tat,pro[i].wt);
        totalwt+=pro[i].wt;
    }
    printf("\nAvg WT = %0.2f\n",totalwt/n);
}

int rr(int n)
{
    set(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pro[i].at > pro[j].at)
            {
                node temp = pro[i];
                pro[i] = pro[j];
                pro[j] = temp;
            }
        }
    }
    int tq=2;
    int count = 0;
    int ready[100], front = 0, back = -1;
    for (int time = 0; count < n; time++)
    {
        for (int i = 0; i < n; i++)
        {
            if (pro[i].at == time)
            {
                back++;
                ready[back] = i;
            }
        }
        if(pro[ready[front]].rt>tq)
        {
            pro[ready[front]].rt-=tq;
            for(int i=time+1;i<time+tq;i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (pro[j].at == i)
                    {
                        back++;
                        ready[back] = j;
                    }
                }
            }
            ready[++back]=ready[front];
            front++;
        }
        else
        {
            for(int i=time+1;i<pro[ready[front]].rt;i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (pro[j].at == i)
                    {
                        back++;
                        ready[back] = j;
                    }
                }
            }
            ready[++back]=ready[front];
            pro[ready[front]].rt = 0;
            front++;
        }
        if (pro[ready[front]].rt == 0)
        {
            pro[ready[front]].ct = time+1;
            pro[ready[front]].tat = pro[ready[front]].ct - pro[ready[front]].at;
            pro[ready[front]].wt = pro[ready[front]].tat - pro[ready[front]].bt;
            front++;
            count++;
            if(front>back) continue;
            for(int i=front;i<=back;i++)
            {
                for(int j=i+1;j<=back;j++)
                {
                    if(pro[ready[i]].prio>pro[ready[j]].prio)
                    {
                        int t1=ready[i];
                        ready[i]=ready[j];
                        ready[j]=t1;
                    }
                }
                
            }
        }
    }
    printf("\nROUND ROBIN");
    float totalwt=0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("\n%i\t%i\t%i\t%i\t%i\t%i\n",pro[i].id, pro[i].at, pro[i].bt, pro[i].ct, pro[i].tat,pro[i].wt);
        totalwt+=pro[i].wt;
    }
    printf("\nAvg WT = %0.2f\n",totalwt/n);
}

int main()
{
    int n = 5;
    pro[0].at = 2, pro[0].bt = 6, pro[0].prio=5;
    pro[1].at = 5, pro[1].bt = 2, pro[1].prio=3;
    pro[2].at = 1, pro[2].bt = 8, pro[2].prio=4;
    pro[3].at = 0, pro[3].bt = 3, pro[3].prio=1;
    pro[4].at = 4, pro[4].bt = 4, pro[4].prio=2;
    for (int i = 0; i < n; i++)
    {
        pro[i].id = i+1;
        pro[i].rt = pro[i].bt;
    }
    fcfs(n);
    sjf(n);
    prior(n);
    rr(n);

}