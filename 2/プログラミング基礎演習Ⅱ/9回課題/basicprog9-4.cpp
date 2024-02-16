#include<iostream>
#include<fstream>
using namespace std;
int main(){
    FILE *fp;
    fp = fopen("dice.csv","r");
    int n = 0;
    int rub[100];
    while(n!=100){
        
        fscanf(fp, "%d,%d,%d,%d,%d.\n",&rub[0],&rub[1],&rub[2],&rub[3],&rub[4] );
        printf("%d,%d,%d,%d,%d\n", rub[0],rub[1],rub[2],rub[3],rub[4]);
        n++;}
    fclose( fp );
    return 0;
}
