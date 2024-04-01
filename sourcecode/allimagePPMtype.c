#include<stdio.h>
#include<stdlib.h>
int main()
{
    int width, height, color;
    unsigned char *image;
    char str[100];
    printf("Enter the name of the file (with .ppm) :");
    gets(str);
    FILE *in_file = fopen(str, "rb");
    fscanf(in_file, "P6\n%d %d\n%d\n", &width, &height, &color);
    image = (unsigned char *) malloc(width * height * 3);
    fread(image, 1, width * height * 3, in_file);
    fclose(in_file);
    for (int i = 0; i < width * height * 3; i += 3) {
        int avg = (0.299*image[i] + 0.587*image[i + 1] + 0.114*image[i + 2]);
        
        image[i] = avg;
        image[i + 1] = avg;
        image[i + 2] = avg;
    }
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
        for (int i = 0; i < width * height*3; i++) {
      if (image[i] < treshold)
       {
        image[i] = 255;
      } 
      else 
      image[i] = image[i];
      
    }
    break;
        case 2:
       for (int i = 0; i < width * height*3; i++) {
      if (image[i] < treshold) {
        image[i] = image[i];
      } 
      else 
      image[i] = 255;
      
    }
    break;
            for (int i = 0; i < width * height*3; i++) {
      if (image[i] < treshold) {
        image[i] = image[i];
      } 
      else 
      image[i] =0;
      
    }
    break;
        case 4:
        
       for (int i = 0; i < width * height*3; i++) {
      if (image[i] < treshold) {
        image[i] = 0;
      } 
      else 
      image[i] = image[i];
      
    }
break;
        case 5:
      for (int i = 0; i < width * height*3; i++) {
      if (image[i] < treshold) {
        image[i] = 0;
      } 
      else 
      image[i] = 255;
      
    }
    break;
        case 6:
       for (int i = 0; i < width * height*3; i++) {
      if (image[i] < treshold) {
        image[i] = 255;
      } 
      else 
      image[i] = 0;
      
    }
    break;
        default:
        printf("choose the right option completed\n");
        }
        printf("%d",width*height);
    FILE *out_file = fopen("outwithhhB1111.ppm", "wb");
    fprintf(out_file, "P6\n%d %d\n%d\n", width, height, color);
    fwrite(image, 1, width * height * 3, out_file);
    fclose(out_file);
    free(image);
    return 0;
}
