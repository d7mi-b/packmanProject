#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int del = 1;
//variabels for PackMan
int midx=90, midy=180, angleB=45, angleE=360,radius=30;
int x2_line1=120,y2_line1=180;
int x2_line2=112,y2_line2=160;

//variabels for boo
int midx_head=240, midy_head=200, stangle_head=0;
int endangle_head=180, xradius_head=30, yradius_head=50;
//int stangle_bot=180,endangle_bot=360;
int y_end=220, linex1=270, linex2=255,linex3=210, linex4=225,linex5=240;

//variables for colors
int color=14;
int colorCircles=15;
int color_boo=4;



void boo(){

    setcolor(color_boo);
    setfillstyle(SOLID_FILL,color_boo);
    ellipse(midx_head,midy_head,stangle_head,endangle_head,xradius_head,yradius_head);
    line(linex1,midy_head,linex1,y_end);
    line(linex2,midy_head,linex1,y_end);
    line(linex3,midy_head,linex3,y_end);
    line(linex4,midy_head,linex3,y_end);
    line(linex4,midy_head,linex5,y_end);
    line(linex2,midy_head,linex5,y_end);
    floodfill(midx_head,midy_head,color_boo);
}

void linesx(int x1,int y1,int x2,int y2){
    line(x1,y1,x2,y2);
    line(x1+1,y1,x2+1,y2);
    line(x1+2,y1,x2+2,y2);
    line(x1+3,y1,x2+3,y2);
}
void linesy(int x1,int y1,int x2,int y2){
    line(x1,y1,x2,y2);
    line(x1,y1+1,x2,y2+1);
    line(x1,y2+2,x2,y2+2);
    line(x1,y2+3,x2,y2+3);
}

void packMan(){

    setcolor(color);
    setfillstyle(SOLID_FILL,color);
    arc(midx,midy,angleB,angleE,radius);
    line(midx,midy,x2_line1,y2_line1);
    line(midx,midy,x2_line2,y2_line2);
    floodfill(midx-1,midy-1,color);

}
void Up(int counter){
    for(int i=0;i<counter;i++){
	color=0;
	packMan();
	midy-=1;
	y2_line1-=1;
	y2_line2-=1;
	color=14;
	packMan();
    delay(del);
    }
}
void Right(int counter){
    for(int i=0;i<counter;i++){
    color=0;
    packMan();
    midx+=1;
    x2_line1+=1;
    x2_line2+=1;
    color=14;
    packMan();

    delay(del);
    }
}
void Down(int counter){
    for(int i=0;i<counter;i++){
    color=0;
    packMan();
    midy+=1;
    y2_line1+=1;
    y2_line2+=1;
    color=14;
    packMan();

    delay(del);
    }
}
void Left(int counter){
    for(int i=0;i<counter;i++){
    color=0;
    packMan();
    midx-=1;
    x2_line1-=1;
    x2_line2-=1;
    color=14;
    packMan();
    delay(del);
    }
}
void DownBoo(int counter){
    for(int i=0;i<counter;i++){
    color_boo=0;
    boo();
    midy_head+=1;
    y_end+=1;
    color_boo=4;
    boo();

    delay(del);
    }
}
void UpBoo(int counter){
    for(int i=0;i<counter;i++){
	color_boo=0;
	boo();
	midy_head-=1;
	y_end-=1;
	color_boo=4;
	boo();
    delay(del);
    }
}
void RightBoo(int counter){
    for(int i=0;i<counter;i++){
    color_boo=0;
    boo();
    midx_head+=1;
    linex1+=1;
    linex2+=1;
    linex3+=1;
    linex4+=1;
    linex5+=1;
    color_boo=4;
    boo();

    delay(del);
    }
}
void LeftBoo(int counter){
    for(int i=0;i<counter;i++){
    color_boo=0;
    boo();
    midx_head-=1;
    linex1-=1;
    linex2-=1;
    linex3-=1;
    linex4-=1;
    linex5-=1;
    color_boo=4;
    boo();
    delay(del);
    }
}
void move(){

    Up(115);
    Right(315);
    Down(230);
    Left(330);

    for(int i=1;i<15;i++){
     Down(i);
     DownBoo(i);
    }
    Down(5);
    for(int j=1;j<12;j++){
	LeftBoo(i);
	Right(i);
    }
    for(int k=1;k<16;k++){
	DownBoo(k);
	Right(k);
    }
    for(int l=1;l<21;l++){
	Right(l);
	RightBoo(l);
    }
    for(int m=1;m<23;m++){
	Up(m);
	RightBoo(m+1);
    }
    RightBoo(10);
    for(int n=1;n<13;n++){
	Up(n-5);
	UpBoo(n);
    }
    UpBoo(270);
}

void circles_y(int circlex,int circley,int length){
    for(int i=0;i<length;i++){
	setcolor(colorCircles);
	setfillstyle(SOLID_FILL,colorCircles);
	circle(circlex,circley,5);
	floodfill(circlex-1,circley-1,colorCircles);
	circley-=30;
    }
}
void circles_x(int circlex,int circley,int length){
    for(int i=0;i<length;i++){
	setcolor(colorCircles);
	setfillstyle(SOLID_FILL,colorCircles);
	circle(circlex,circley,5);
	floodfill(circlex-1,circley-1,colorCircles);
	circlex +=40;
    }
}
void main()
{
    int gdriver=DETECT, gmode,errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");


    //draw outlines
    setcolor(1);


    linesx(10,10,10,469); //line 1
    linesy(10,10,628,10); //line 2
    linesx(628,10,628,469); //line 3
    linesy(10,469,628,469); //line 4
    linesy(10,240,160,240); //line 5
    linesx(160,120,160,240); //line 6
    linesy(160,120,320,120); //line 7
    linesx(320,120,320,245); //line 8
    linesy(160,350,480,350); //line 9
    linesx(480,200,480,350); //line 10
    linesx(480,10,480,100); //line 11

    packMan();
    boo();
    circles_y(90,100,2);
    circles_x(130,70,8);
    circles_y(410,310,8);
    circles_x(90,310,8);
    circles_y(90,410,3);
    circles_x(130,410,12);
    circles_y(570,380,10);

    move();
    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    circle(560,50,5);
    floodfill(561,51,0);
    circle(580,50,5);
    floodfill(581,51,0);

    getch();
}