#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE* fp = fopen("C:\\Users\\Admin\\Downloads\\lena512.bmp", "rb");
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
    imageData = (unsigned char*)malloc (imgDataSize * sizeof(unsigned char)); // allocate the block of memory as big as the image size
    newimageData = (unsigned char*)malloc (imgDataSize * sizeof(unsigned char));
    if(bitDepth <= 8)
    {
    fread(colorTable, sizeof(unsigned char), 1024, fp);
    }	
    fread( imageData, sizeof(unsigned char), imgDataSize, fp);
    printf("enter the treshold value that u want or inbuild value is ""150"" \n");
    printf("1.)inbuilt treshold value is ""150"" \n");
    printf("2.)write the treshold value that i want \n");
    int n,treshold;
    scanf("%d",&n);
    printf("u have entered (%d) option\n",n);
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
    printf("therfore the treshold value that u want is %d\n",treshold);
    printf("enter the type of operation that u want to do\n");
    printf("1.)to make the values greater than treshold brigther(brigther image)\n");
    printf("2.)to make the values lesser than treshold brigther(brigther image)\n");
    printf("3.)to make the values greater than treshold darker(darker image)\n");
    printf("4.)to make the values lesser than treshold darker(darker image)\n");
    printf("5.)to make the values greater than treshold value brigther and lesser darker(black&white image)\n");
    printf("6.)to make the values greater than treshold value darker and lesser brighter(black&white image)\n");
    printf("7.)to make rgb to greyscale\n");
    int new;
    scanf("%d",&new);
    printf("%d is the option that u have selected\n",new);
    while((new!=1)&&(new!=2)&&(new!=3)&&(new!=4)&&(new!=5)&&(new!=6)&&(new!=7))
    {
    printf("%d is not the correct option\n",new);
    printf("enter the correct option::");
    scanf("%d",&new);
    }
    printf("%d is the correct option that u have selected\n",new);
    switch(new)
    {
        case 1:
        for(i = 0; i<height; i++)
    {
	      for(j = 0; j<width; j++)
          {
            if(imageData[i*width + j]>treshold) 
            {                  
		     newimageData[i*width + j]= 255;
            }
            else
            newimageData[i*width + j] =imageData[i*width + j];  
 
		 }   
	}
    break;
        case 2:
       for(i = 0; i<height; i++)
    {
	      for(j = 0; j<width; j++)
          {
            if(imageData[i*width + j]<treshold) 
            {                  
		     newimageData[i*width + j]= imageData[i*width + j];
            }
            else
            newimageData[i*width + j] =255;  

		 }   
	}
    break;
        case 3:
        for(i = 0; i<height; i++)
       {
	      for(j = 0; j<width; j++)
          {
            if(imageData[i*width + j]>treshold) 
            {                  
		     newimageData[i*width + j]= 0;
            }
            else
            newimageData[i*width + j] =imageData[i*width + j];  

		 }   
	}
    break;
        case 4:
        
        for(i = 0; i<height; i++)
    {
	      for(j = 0; j<width; j++)
          {
            if(imageData[i*width + j]<treshold) 
            {                  
		     newimageData[i*width + j]= 0;
            }
            else
            newimageData[i*width + j] =imageData[i*width + j];  

		 }   
	}
break;
        case 5:
        for(i = 0; i<height; i++)
    {
	      for(j = 0; j<width; j++)
          {
            if(imageData[i*width + j]>treshold) 
            {                  
		     newimageData[i*width + j]= 255;
            }
            else
            newimageData[i*width + j] =0;  

		 }   
	}
    break;
        case 6:
        for(i = 0; i<height; i++)
    {
	      for(j = 0; j<width; j++)
          {
            if(imageData[i*width + j]>treshold) 
            {                  
		     newimageData[i*width + j]= 0;
            }
            else
            newimageData[i*width + j] =255;  

		 }   
	}
    break;
        case 7:
        printf("on progress\n");
        break;
        default:
        printf("not yet completed\n");
        }
        FILE *fo = fopen("C:\\Users\\Admin\\Downloads\\nila9799.bmp", "wb");

        fwrite(imageHeader, sizeof(unsigned char), 54, fo); 

	    if(bitDepth <= 8)	
        {
        	fwrite(colorTable, sizeof(unsigned char), 1024, fo);
        }
        fwrite( newimageData, sizeof(unsigned char), imgDataSize, fo); 
         
    fclose(fo);
	fclose(fp);
        




    return 0;
}

// git chcek