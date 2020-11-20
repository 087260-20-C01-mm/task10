#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int checkElement(int o,int k,int b[k]){
int i;
for(i=0;i<=k-1;i++){
    if(b[i]==o){return 1;}
}
return 0;
}

int main()
{
    setlocale(LC_ALL,"Rus");
    int i,j,P,n,count=0;


    FILE *fp,*fp1;
    char s[2][80], linkIn[80],linkOut[80];

    printf("¬ведите путь к файлу, с которого будет считыватьс€ текст\n");
    gets(linkIn);
    fp=fopen(linkIn,"r");
    printf("¬ведите путь к файлу, в который будет зписан текст\n");
    gets(linkOut);
    fp1=fopen(linkOut,"w");
    fgets(&s[0][0],80,fp);
    n=strlen(&s[0][0]);


        j=0;
    for(i=0;i<=n-1;i++)
    {
        if(s[0][i]==' ')
        {
            if(i==n-1 || i+1==n-1 || s[0][i+1]==' ' || s[0][i+1]=='.' || j==0){continue;}
            else{s[1][j]=' ';j++;}
        }
        else{s[1][j]=s[0][i];j++;}
    }
    s[1][j]='\0';
    fprintf(fp1,"%s\n",&s[1][0]);



    char **Words;
    Words = (char**) malloc(20*sizeof(char*));

    char *word=strtok(s," ");
    for (i=0;word != NULL;i++)
  {
    Words[i] = (char*) malloc(sizeof(word));
    Words[i]=word;

    word = strtok(NULL, " .");
  }

  int blackList1[i],blackList2[i],k1=0,k2=0;
    for(j=0;j<=i-1;j++)
    {
        if(strcmp(Words[i-1],Words[j])==0){blackList1[k1]=j;k1++;}
        if(strchr(&Words[j][1],Words[j][0])!=0){blackList2[k2]=j;k2++;}
    }

    for(j=0;j<=i-1;j++)
    {
        if(checkElement(j,k1,blackList1)==1){continue;}
        if(count!=0){fprintf(fp1,"%c",' ');}
        fprintf(fp1,"%s",Words[j]);count++;
    }
    fprintf(fp1,"\n",NULL);count=0;
    for(j=0;j<=i-1;j++)
    {
        if(checkElement(j,k2,blackList2)==1 || checkElement(j,k1,blackList1)==1){continue;}
        if(count!=0){fprintf(fp1,"%c",' ');}
        fprintf(fp1,"%s",Words[j]);count++;
    }

    free(Words);


    fclose(fp);
    fclose(fp1);
    printf("¬роде готово, посмотрите в ");
    puts(linkOut);
    printf("\n\n\n");
    return main();
}
