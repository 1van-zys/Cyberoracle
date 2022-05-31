#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
//#include <liuyao.h>

//????????????????????????????????????,????????????????????????????????????


/***************************************************************************************************************************************************
 ????????? ???????? ????????? ??????? ??????? ????|?? ?????? ???????
??????????????????????????????????????????????????????????????????????????????????????????




***************************************************************************************************************************************************/


#define SHAOYIN 8
#define SHAOYANG 7
#define LAOYIN 6
#define LAOYANG 9

#define YINYAO 0
#define YANGYAO 1

struct RESULT
{
    int zhuguahao;    //
    int zhuguaci;
    int fuguahao;
    int fuguaci;
};


int bengua;
int biangua;

int XIANTIANGUA[64];

//????????,???2??????????3?????
//????rand????????????????????????????????????ADC????????????

int tosscoin(void);
int duangua64(int liuyao[6]);
int change(int liuyao[6]);
struct RESULT suan(int benguahao,int bianguahao);

main(void)
{
    int bin[6];
    char bian[6];          //01

    int yao,bi;
    int coin[3];
    int liuyao[6];      //6789

    struct RESULT result;

    for(yao=0;yao<6;yao++)
    {
        for(bi=0;bi<3;bi++)
        {
             coin[bi] = tosscoin();
             printf("bi=%d,",coin[bi]);
             Sleep(200);
        }
        liuyao[yao] = coin[0]+coin[1]+coin[2];
        switch(liuyao[yao])
        {
            case 6:
            bian[yao] = 'O';
            break;

            case 9:
            bian[yao] = 'X';
            break;

            default:
            bian[yao] = '\t';
            break;
        }
        bin[yao] = liuyao[yao] % 2;
        printf("%dyao = %d",yao+1,liuyao[yao]);
        printf("%c\n",bian[yao]);
        
    }


    bengua = duangua64(bin);

    biangua = change(liuyao);

    printf("%d ? %d ??\n",bengua,biangua);

    result = suan(23,32);

    printf("?????%d\n",result.zhuguahao);
    printf("????%d\n",result.zhuguaci);
    printf("?????%d\n",result.fuguahao);
    printf("????%d\n",result.fuguaci);

    return 0;
}


int tosscoin(void)
{
    int i;
    srand((unsigned)time(NULL));
    i = (rand()) % 2; 
//    printf("%d",i);  
    return i + 2;//????????23
}


int duangua64(int liuyao[6])
{
    int num;
    num = liuyao[5]*32+liuyao[4]*16+liuyao[3]*8+liuyao[2]*4+liuyao[1]*2+liuyao[0];
    return num + 1;            //1??64??
}

int change(int liuyao[6])
{
    int i,num;
    int change = 0;
    int bianyao[6] = {0};
    for(i=0;i<6;i++)
    {
        switch (liuyao[i])
        {
            case LAOYIN://6
            bianyao[i] = YINYAO;
            break;

            case SHAOYANG://7
            bianyao[i] = YANGYAO;
            break;

            case SHAOYIN://8
            bianyao[i] = YINYAO;
            break;

            case LAOYANG://9
            bianyao[i] = YANGYAO;
            break;
        }
    }
    num = bianyao[5]*32+bianyao[4]*16+bianyao[3]*8+bianyao[2]*4+bianyao[1]*2+bianyao[0];
    return num;
}

struct RESULT suan(int benguahao,int bianguahao)
{
    int bengua[6] = {0,1,0,1,0,1};
    int biangua[6] = {1,0,1,0,1,0};
    int bianyao[6];
    int bianyaoshu,i=0,j=0;
    int output[4];

    struct RESULT result;
       
//   bengua[6] = XIANTIANGUA[benguahao];//???????0101????¡ì???bengua[];
//   biangua[6] = XIANTIANGUA[bianguahao];

    for(i=0;i<6;i++)
    {
        bianyao[i] = bengua[i] ^ biangua[i];
    }
    bianyaoshu = bianyao[0] + bianyao[1] + bianyao[2] + bianyao[3] + bianyao[4] + bianyao[5];
    printf("%d???\n",bianyaoshu);
    switch(bianyaoshu)
    {
        case 0:
        result.zhuguahao = benguahao;
        result.zhuguaci = 1;//????1????????????
        result.fuguahao = 0;
        result.fuguaci = 0;
        break;

        case 1:
        result.zhuguahao = benguahao;
        for(i=0;i<6;i++)
        {
            if(bianyao[i] == 1)
             result.zhuguaci = i + 1;

        }
        result.fuguahao = 0;
        result.fuguaci = 0;
        break;

        case 2:
        result.zhuguahao = benguahao;
        for(i=0;i<6;i++)
        {
            if(bianyao[i] == 1)
            {
                j++;
                switch(j)
                {
                    case 1:
                    result.zhuguaci = i + 1;
                    break;

                    case 2:
                    result.fuguaci = i + 1;
                    break;
                }
            }
            result.fuguahao = benguahao;
            
        }
        break;

        case 3:
        result.zhuguahao = benguahao;
        result.zhuguaci = 1;//????1????????????
        result.fuguahao = bianguahao;
        result.fuguaci = 1; 
        break;

        case 4:
        result.zhuguahao = bianguahao;
        result.fuguahao = bianguahao;
        for(i=0;i<6;i++)
        {
            if(bianyao[i] == 0)
            {
                j++;
                switch(j)
                {
                    case 1:
                    result.fuguaci = i + 1;
                    break;

                    case 2:
                    result.zhuguaci = i + 1;
                    break;
                }
            }
        }
        break;

        case 5:
        result.zhuguahao = bianguahao;
        for(i=0;i<6;i++)
        {
            if(bianyao[i] == 0)
                result.zhuguaci = i + 1;
        }
        result.fuguahao = 0;
        result.fuguaci = 0;
        break;

        case 6:
        {
            switch(benguahao)
            {
                case 1:
                result.zhuguahao = benguahao;
                result.zhuguaci = 65;//????0????
                break;

                case 64:
                result.zhuguahao = benguahao;
                result.zhuguaci =65;
                break;

                default :
                result.zhuguahao = bianguahao;
                result.zhuguaci = 1;
                break;
            }
            result.fuguahao = 0;
            result.fuguaci = 0;            
        }
        break;        
    }
    return result;
}