#include<stdio.h>

#include<stdlib.h>

#define MAXN 2001


struct quest
{
    int xp, target, deadline;
}quests[MAXN];// structure array

typedef struct quest quest;

int comparison(const void *a, const void *b)
{
    (void)a; (void)b;

    return rand() % 2 ? +1 : -1;
}

int n, v, c;
int main()
{
    int total = 0;
    int currentLevel = 0;
    int maxXp = 0;
    scanf("%d %d %d", &n, &v, &c);
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &quests[i].xp, &quests[i].target);
        quests[i].deadline = ((quests[i].xp * c) + (quests[i].target * v));
        total += quests[i].xp;
    }

    qsort(quests, n, sizeof(quest), comparison);// time complexity

    for(i = 0; i < n; i++)
    {
        if(currentLevel < quests[i].target)
        {
            maxXp += (quests[i].xp * c);
            currentLevel = (maxXp / v); 
        }
        else if(currentLevel >= quests[i].target)
        {
            maxXp += quests[i].xp;
            currentLevel = (maxXp / v); 
        }
    }
    printf("%d", maxXp);
}
