#include<stdio.h>
#include<stdlib.h>
void main()
{
  FILE *fp;
  char f[100],F[100];
  char s[5]="%f";
  printf("Enter f(x,y):");
  scanf("%s",f);
  for(int i=0;i<100;i++)
  {
   F[i]=f[i];
   if(F[i]=='x')
      F[i]='X';
   if(F[i]=='y')
      F[i]='Y';
  }
  fp=fopen("modEuler.c","w");
  fprintf(fp,"#include<stdio.h>\n#include<math.h>\nvoid main()\n{float a,y,X,Y,h,end; \n printf(\"\\nEnter Xo:\");\n scanf(\"%s\",&a);\n printf(\"\\nEnter Yo:\");\n scanf(\"%s\",&y);\n printf(\"\\nEnter h:\");\n scanf(\"%s\",&h);\n printf(\"\\nEvaluate upto X=\");\n scanf(\"%s\",&end);\n for(float x=a;x<end;x+=h)\n {\n     Y=y+h*( %s );\n    X=x+h;\n     y=y+0.5*h*(( %s )+( %s ));\n }\n printf(\"Hence, Yn= %s\\n\",y);\n}",s,s,s,s,f,f,F,s);
  fclose(fp);
  system("gcc modEuler.c -lm");
  system("./a.out");
}
