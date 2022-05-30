#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

typedef struct sinhvien
{
    int msv;
    char ten[1000];
    double tong_diem;
    double diemA;
    double diemB;
    double diemC;
} sv;

void swapi(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapd(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}
void swapstr(char *a, char *b)
{
    char temp[1000];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}

void swap(sv *a, sv *b)
{
    swapstr(a->ten,b->ten);
    swapd(&a->tong_diem, &b->tong_diem);
    swapd(&a->diemA, &b->diemA);
    swapd(&a->diemB, &b->diemB);
    swapd(&a->diemC, &b->diemC);
    swapi(&a->msv, &b->msv);
}

void sort(sv *SV, int index)
{
    for ( int i = 0 ; i < index ; i++ )
    {
        for ( int j = i+1 ; j <= index ; j++ )
        {
            if ( SV[i].tong_diem > SV[j].tong_diem )
            {
                swap(&SV[i], &SV[j]);
            }
        }
    }
}

void them(int *stack,int *user_action, int *index, sv *SV)
{
    int n;
    scanf("%d",&n);
    scanf("\n");
    stack[*user_action] = n;
    for ( int i = *index ; i < *index + n ; i++ )
    {
        SV[i].msv = i;
        gets((SV[i]).ten);
        scanf("\n");
        scanf("%lf %lf %lf", &SV[i].diemA, &SV[i].diemB, &SV[i].diemC);
        SV[i].tong_diem = SV[i].diemA + SV[i].diemB + SV[i].diemC;
        scanf("\n");
    }
    *index += n;
}

void sua(int *stack, int *user_action, sv *SV)
{
    int n;
    scanf("%d",&n);
    stack[*user_action] = n;
    int lens = strlen(SV[n].ten);

    for ( int i = 0 ; i < lens ; i++ )
    {
        SV[n].ten[i] = '\0';
    }

    scanf("\n");
    gets(SV[n].ten);
    scanf("\n");
    scanf("%lf %lf %lf",&SV[n].diemA, &SV[n].diemB, &SV[n].diemC);
    SV[n].tong_diem = SV[n].diemA + SV[n].diemB + SV[n].diemC;
}

void in_man(int *stack, int user_action, int index, sv *SV)
{
    index--;
    sort(SV,index);
    for ( int i = 1 ; i <= user_action ; i++ )
    {
        printf("%d\n",stack[i]);
    }
    for ( int i = 1 ; i <= index ; i++ )
    {
        printf("%d %s %.1lf %.1lf %.1lf\n", SV[i].msv, SV[i].ten, SV[i].diemA, SV[i].diemB, SV[i].diemC);
    }
}

int main()
{
    int ok = 1;
    int stack[1000] = {0};
    int user_action = 0;
    int index = 1;
    sv SV[1000];
    while ( ok )
    {
        int sl;
        scanf("%d",&sl);

        if ( sl == 1 ) 
        {
            user_action++;
            them(stack,&user_action,&index,SV);
        }

        if ( sl == 2 ) 
        {
            user_action++;
            sua(stack,&user_action,SV);
        }

        if ( sl == 3 )
        {
            in_man(stack,user_action,index,SV);
            break;
        }

    }
}