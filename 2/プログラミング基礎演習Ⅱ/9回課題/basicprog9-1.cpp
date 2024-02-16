#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int i;
    char sex;
    double height,weight;

    FILE *fp = fopen("data.txt", "w");
    if(fp==NULL){
        cout << "Eroor : Failed to open file" << endl;
        return 0;
    }

    for(i=0; i<3; i++){
        cin >> sex >> height >> weight;
        fprintf(fp, "%c, %lf, %lf\n", sex, height, weight);
    }
    fclose(fp);
    return 0;

}