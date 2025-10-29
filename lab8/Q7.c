#include <stdio.h>

int main() {
    int inv[2][3][4]={0};
    int sec, sh, it;
    int totalSec[2]={0};
    int shelfSum, maxShelf=0, maxVal=0, s1,s2;
    printf("Enter quantities (2 sections, 3 shelves, 4 items):\n");
    for(sec=0;sec<2;sec++){
        for(sh=0;sh<3;sh++){
            for(it=0;it<4;it++){
            	printf("Enter Section No. %d shelves %d Items %d :", sec+1, sh+1 , it+1);
                scanf("%d", &inv[sec][sh][it]);
            }
        }
    }
    for(sec=0;sec<2;sec++){
        for(sh=0;sh<3;sh++){
            shelfSum=0;
            for(it=0;it<4;it++){
                shelfSum += inv[sec][sh][it];
            }
            totalSec[sec] += shelfSum;
            if(shelfSum > maxVal){
                maxVal = shelfSum;
                s1 = sec+1;
                s2 = sh+1;
            }
        }
    }
    printf("\nTotal items in each section:\n");
    for(sec=0;sec<2;sec++){
        printf("Section %d: %d\n", sec+1, totalSec[sec]);
    }
    printf("Shelf with highest quantity: Section %d, Shelf %d (%d items)\n", s1, s2, maxVal);
    return 0;
}
