

#include <stdio.h>
#define N 4

//所持している枚数が代入される
struct in_hand{
    int cent25;
    int cent10;
    int cent5;
    int cent1;
};

struct  used{
    int cent25;
    int cent10;
    int cent5;
    int cent1;
};

struct count{
    int cent25;
    int cent10;
    int cent5;
    int cent1;
    int sum;
};


struct in_hand coins;
struct used used_coins;
struct count cnt;

void greedy(int fee){

    int sum=0;

    while(1){
        //coinsで各コインの枚数分だけ、足せるだけ足していく
        //25 cent
        for(int i=0;i<coins.cent25;i++){
            sum+=25;
            if(sum>fee){
                sum-=25;
                break;
            }
            cnt.cent25++;
        }
        //10cent
        for(int i=0;i<coins.cent10;i++){
            sum+=10;
            if(sum>fee){
                sum-=10;
                break;
            }
            cnt.cent10++;
        }
        for(int i=0;i<coins.cent5;i++){
            sum+=5;
            if(sum>fee){
                sum-=5;
                break;
            }
            cnt.cent5++;
        }
        for(int i=0;i<coins.cent1;i++){
            sum+=1;
            if(sum>fee){
                sum-=1;
                break;
            }
            cnt.cent1++;
        }
        //判定
        if(sum!=fee){
            printf("Error: you cannot pay for this value.\n");

            break;
        }else{
            printf("[25 cent] %d used.\n", cnt.cent25);
            printf("[10 cent] %d used.\n", cnt.cent10);
            printf("[5 cent] %d used.\n", cnt.cent5);
            printf("[1 cent] %d used.\n", cnt.cent1);

            cnt.sum=cnt.cent25+cnt.cent10+cnt.cent5+cnt.cent1;
            printf("Totally, you used %d coins for %d\n", cnt.sum, fee);

            break;
        }
    }
}

int main(){

    int fee;

    printf("Input numbers of each cent(coin).\n->");
    scanf("%d %d %d %d", &coins.cent25, &coins.cent10, &coins.cent5, &coins.cent1);

    printf("Input how many cents should you pay?\n->");
    scanf("%d", &fee);

    greedy(fee);

    return 0;
}
