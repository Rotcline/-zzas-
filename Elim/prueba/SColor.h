#ifndef SColor
#define SColor

typedef struct SColor{
    int SCL_R;
	int SCL_G;
	int SCL_B;
	int SCR_R;
	int SCR_G;
	int SCR_B;  
}*SColor; 

int detectColor(SColor *scolor,int SCL_R,int SCL_G,int SCL_B,int SCR_R,int SCR_G,int SCR_B); 



#endif