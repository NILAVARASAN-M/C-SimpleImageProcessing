#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void case1(unsigned char *imageData,unsigned char *newimageData,int imgDataSize);
void case2(unsigned char *imageData,unsigned char *newimageData,int imgDataSize);
void case3(unsigned char *imageData,unsigned char *newimageData,int imgDataSize);
void case4(unsigned char *imageData,unsigned char *newimageData,int imgDataSize);
void case5(unsigned char *imageData,unsigned char *newimageData,int imgDataSize);
void case6(unsigned char *imageData,unsigned char *newimageData,int imgDataSize);
int treshoold(int n);
void printtreshold();
void printoption();
int optioncheck(int new);
void mainswitch(int new,unsigned char *imageData,unsigned char *newimageData,int imgDataSize);
void extraswitch(int n,unsigned char *imageData,unsigned char *newimageData,int imgDataSize);
void check(char *name);
int main()
{
    char name[50];
    check(name);
    FILE* fp = fopen(name, "rb");
    if(fp==NULL)
    {
        printf("no such file exist,enter the valid file");
        return 0;
    }
    printf("1.)to continue the loop\n2.)to break\nclick any one option mentioned\n");
    unsigned char *imageData; 
	unsigned char *newimageData; 
    unsigned char imageHeader[54]; 
    unsigned char colorTable[1024];
    fread(imageHeader, sizeof(unsigned char), 54, fp);
    int i,j;
    int width = *(int*)&imageHeader[18];
    int height = *(int*)&imageHeader[22];
	int bitDepth = *(int*)&imageHeader[28];
    int imgDataSize = width * height;
    imageData = (unsigned char*)malloc (imgDataSize * sizeof(unsigned char)); 
    newimageData = (unsigned char*)malloc (imgDataSize * sizeof(unsigned char));
    if(bitDepth <= 8)
    {
    fread(colorTable, sizeof(unsigned char), 1024, fp);
    }	
    fread( imageData, sizeof(unsigned char), imgDataSize, fp);
    imgDataSize=width*height;
    int n;
    scanf("%d",&n);
    extraswitch(n,imageData,newimageData,imgDataSize);
    FILE *fo = fopen("nila(6).bmp", "wb");
    fwrite(imageHeader, sizeof(unsigned char), 54, fo); 
    if(bitDepth <= 8)	
    {
        fwrite(colorTable, sizeof(unsigned char), 1024, fo);
    }
        fwrite( newimageData, sizeof(unsigned char), imgDataSize, fo); 
         printf("the image is proccesed go look your directory\n");
    fclose(fo);
	fclose(fp);
    ;
    return 0;
}



void case1(unsigned char *imageData,unsigned char *newimageData,int imgDataSize)
{
    int i;
     for(i = 0; i <= imgDataSize; i++) {
    if(imageData[i]>150)   {
      newimageData[i] =255;
    } else {
      newimageData[i]=imageData[i];
    }
  }
}
void case2(unsigned char *imageData,unsigned char *newimageData,int imgDataSize)
{
    int i;
    for(i = 0; i <= imgDataSize; i++) 
    {
    if(imageData[i]>150)   {
      newimageData[i]=imageData[i];
    } else {
      newimageData[i]=255;
    }
  }
}
void case3(unsigned char *imageData,unsigned char *newimageData,int imgDataSize)
{
    int i;
    for(i = 0; i <= imgDataSize; i++) 
    {
    if(imageData[i]>150)   {
      newimageData[i]=0;
    } else {
      newimageData[i]=imageData[i];
    }
  }
}
void case4(unsigned char *imageData,unsigned char *newimageData,int imgDataSize)
{
    int i;
    for(i = 0; i <= imgDataSize; i++) 
    {
    if(imageData[i]>150)   {
      newimageData[i]=imageData[i];
    } else {
      newimageData[i]=0;
    }
  }
}
void case5(unsigned char *imageData,unsigned char *newimageData,int imgDataSize)
{
    int i;
    for(i = 0; i <= imgDataSize; i++) 
    {
    if(imageData[i]>150)   {
      newimageData[i]=255;
    } else {
      newimageData[i]=0;
    }
  }
}
void case6(unsigned char *imageData,unsigned char *newimageData,int imgDataSize)
{
    int i;
    for(i = 0; i <= imgDataSize; i++) 
    {
    if(imageData[i]>150)   {
      newimageData[i]=0;
    } else {
      newimageData[i]=255;
    }
  }
}
int treshoold(int n)
{
    int treshold;
while((n!=1)&&(n!=2))
    {
        printf("%d is not the correct option\n",n);
        printf("enter the correct option\n");
        scanf("%d",&n);
    }
    printf("u have entered (%d) option\n",n);
    switch(n)
    {
        case 1:
        treshold=150;
        break;
        case 2:
        printf("enter the treshold value:\n");
        scanf("%d",&treshold);
        break;
        default:
        printf("%d is not the correct constraint\n",treshold);
    }
    return treshold;
}
void printtreshold()
{
    printf("enter the treshold value that u want or inbuild value is ""150"" \n");
    printf("1.)inbuilt treshold value is ""150"" \n");
    printf("2.)write the treshold value that i want \n");
}
void printoption()
{
    printf("enter the type of operation that u want to do\n");
    printf("1.)to make the values greater than treshold brigther(brigther image)\n");
    printf("2.)to make the values lesser than treshold brigther(brigther image)\n");
    printf("3.)to make the values greater than treshold darker(darker image)\n");
    printf("4.)to make the values lesser than treshold darker(darker image)\n");
    printf("5.)to make the values greater than treshold value brigther and lesser darker(black&white image)\n");
    printf("6.)to make the values greater than treshold value darker and lesser brighter(black&white image)\n");
}
int optioncheck(int new)
{
    while((new!=1)&&(new!=2)&&(new!=3)&&(new!=4)&&(new!=5)&&(new!=6)&&(new!=7))
    {
    printf("%d is not the correct option\n",new);
    printf("enter the correct option::");
    scanf("%d",&new);
    }
}
void mainswitch(int new,unsigned char *imageData,unsigned char *newimageData,int imgDataSize)
{
    switch(new)
    {
        case 1:
        case1(imageData,newimageData,imgDataSize);
        break;
        case 2:
        case2(imageData,newimageData,imgDataSize);
        break;
        case 3:
        case3(imageData,newimageData,imgDataSize);
        printf("hi......");
        break;
        case 4:
        case4(imageData,newimageData,imgDataSize);
        break;
        case 5:
        case5(imageData,newimageData,imgDataSize);
        break;
        case 6:
        case6(imageData,newimageData,imgDataSize);
        break;
        default:
        printf("some problem.....\n");
        }
}
void extraswitch(int n,unsigned char *imageData,unsigned char *newimageData,int imgDataSize)
{
    
     switch(n)
    {
    case 1:
    printtreshold();
    int n,treshold;
    scanf("%d",&n);
    printf("u have entered (%d) option\n",n);
    treshold=treshoold(n);
    printoption();
    int new;
    scanf("%d",&new);
    int hi=optioncheck(new);
    printf("%d is the correct option that u have selected\n",hi);
    mainswitch(new,imageData,newimageData,imgDataSize);
    break;
    case 2:
    printf("hi......");
    break;
    }
}
void check(char *name)
{
    printf("enter the file name with .bmp\n");
    gets(name);
    printf("the name u entered is %s\n",name);
}