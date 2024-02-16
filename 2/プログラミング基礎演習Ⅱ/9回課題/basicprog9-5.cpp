#include<iostream>
#include<fstream>
using namespace std;
int main(){
    FILE *fp;
    fp = fopen("dice.csv","r");
    int n = 0;
    double sum0=0;
    double sum1=0;
    double sum2=0;
    double sum3=0;
    double sum4=0;
    double rub[100];
    while(n!=100){
        
        fscanf(fp, "%lf,%lf,%lf,%lf,%lf.\n",&rub[0],&rub[1],&rub[2],&rub[3],&rub[4] );
        /*printf("%lf,%lf,%lf,%lf,%lf\n", rub[0],rub[1],rub[2],rub[3],rub[4]);*/
        sum0+=rub[0];
        sum1+=rub[1];
        sum2+=rub[2];
        sum3+=rub[3];
        sum4+=rub[4];
        n++;}
    double ave0 = sum0/100;
    double ave1 = sum1/100;
    double ave2 = sum2/100;
    double ave3 = sum3/100;
    double ave4 = sum4/100;
    FILE *ff = fopen("dice_exp.csv", "w");
    fprintf(ff, "%d, %lf\n", 1, ave0);
    fprintf(ff, "%d, %lf\n", 2, ave1);
    fprintf(ff, "%d, %lf\n", 3, ave2);
    fprintf(ff, "%d, %lf\n", 4, ave3);
    fprintf(ff, "%d, %lf\n", 5, ave4);
    fclose( fp );
    return 0;
}