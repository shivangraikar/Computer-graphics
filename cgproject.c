#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<process.h>
#include<conio.h>
#define KeyLeft 75
#define KeyUp 72
#define KeyDown 80
#define KeyRight 77
#define KeyEsc 27
int utx1=190,uty1=400,utx2=170,uty2=435,utx3=210,uty3=435;   //user triangle
int ucx=390,ucy=410,ucr=24;          //user circle
int p,q,z,count=0;
int rx1=350,ry1=20,rx2=350,ry2=70,rx3=420,ry3=20,rx4=420,ry4=70;
int tx1=290,ty1=20,tx2=260,ty2=70,tx3=320,ty3=70;
int cx=190,cy=50,cr=30;    //opp circle
int gd,gm;
int x=282,y=25,r=25; //circle
char ex,ch;
int x1=0,y1=0,x2=620,y2=440;  //boundary
int xlt=292,ylt=400,xrt=327,yrt=400,xlb=292,ylb=435,xrb=327,yrb=435;  //user object
int r1=155,r2=0,r3=155,r4=440,r5=465,r6=0,r7=465,r8=440; //road
void drawcircle(){
circle(ucx,ucy,ucr);
}
void usertri(){
line(utx1,uty1,utx2,uty2);
line(utx2,uty2,utx3,uty3);
line(utx1,uty1,utx3,uty3);
}
void drawrect(){
line(rx1,ry1,rx2,ry2);
line(rx1,ry1,rx3,ry3);
line(rx2,ry2,rx4,ry4);
line(rx3,ry3,rx4,ry4);
}
void instructions(){
outtextxy(r5,240,"y,g,h,j for moving");
outtextxy(r5,250,"triangle");
outtextxy(r5,200,"Arrow keys for");
outtextxy(r5,210,"moving circle");
outtextxy(r5,170,"w,a,s,d for movement");
outtextxy(r5,180,"of square");
outtextxy(r5,280,"Press C to exit");
outtextxy(r5,310,"Press F to score");
outtextxy(r5,320,"with square");
outtextxy(r5,340,"Press T to score");
outtextxy(r5,350,"with triangle");
outtextxy(r5,370,"Press I to score");
outtextxy(r5,380,"with circle");
}
void triangle(){
line(tx1,ty1,tx2,ty2);
line(tx1,ty1,tx3,ty3);
line(tx2,ty2,tx3,ty3);
}
void shapes(){
drawcircle();
usertri();
triangle();
drawrect();
circle(cx,cy,cr);
}
void normaldraw(){
line(r1,r2,r3,r4); //drawing road
line(r5,r6,r7,r8); //drawing road
line(xlt,ylt,xrt,yrt); //drawing the user object
line(xlt,ylt,xlb,ylb); //drawing the user object
line(xlb,ylb,xrb,yrb); //drawing the user object
line(xrt,yrt,xrb,yrb); //drawing the user object
rectangle(x1,y1,x2,y2);//drawing boundary
}
void main(){
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"C://turboc3//bgi");
while(1){
y:
instructions();
normaldraw();
shapes();
if(kbhit()){
ch=getch();
switch(ch){
case 'a':
if(xlt>=r1){
cleardevice();
instructions();
normaldraw();
shapes();
delay(15);
line(xlt--,ylt,xrt--,yrt);
line(xlt--,ylt,xlb--,ylb);
line(xlb--,ylb,xrb--,yrb);
line(xrt--,yrt,xrb--,yrb);
}
break;
case 'y':
if(uty1>=0){
cleardevice();
instructions();
normaldraw();
shapes();
delay(15);
line(utx1,uty1--,utx2,uty2--);
line(utx2,uty2--,utx3,uty3--);
line(utx1,uty1--,utx3,uty3--);
}
break;

case 80:
if(ucy<=r4-24){
cleardevice();
instructions();
normaldraw();
shapes();
delay(5);
circle(ucx,ucy++,ucr);
}
break;
case 72:
if(ucy>=r2+24){
cleardevice();
instructions();
normaldraw();
shapes();
delay(5);
circle(ucx,ucy--,ucr);
}
break;
case 75:
if(ucx>=r1+24){
cleardevice();
instructions();
normaldraw();
shapes();
delay(15);
circle(ucx--,ucy,ucr);
}
break;
case 77:
if(ucx<=r5-24){
cleardevice();
instructions();
normaldraw();
shapes();
delay(15);
circle(ucx++,ucy,ucr);
}
break;
case 'g':
if(utx2>=r1){
cleardevice();
instructions();
normaldraw();
shapes();
delay(15);
line(utx1--,uty1,utx2--,uty2);
line(utx2--,uty2,utx3--,uty3);
line(utx1--,uty1,utx3--,uty3);
}
break;
case 'h':
if(uty2<=r4){
cleardevice();
instructions();
normaldraw();
shapes();
delay(15);
line(utx1,uty1++,utx2,uty2++);
line(utx2,uty2++,utx3,uty3++);
line(utx1,uty1++,utx3,uty3++);
}
break;
case 'j':
if(utx3<=r5){
cleardevice();
instructions();
normaldraw();
shapes();
delay(15);
line(utx1++,uty1,utx2++,uty2);
line(utx2++,uty2,utx3++,uty3);
line(utx1++,uty1,utx3++,uty3);
}
break;
case 't':
instructions();
shapes();
if(utx1>=tx2&&utx1<=tx3&&uty1>=ty1&&utx2>=tx2+3&&uty2<=ty2&&utx3<=tx3-3&&uty3<=ty3){
count++;
goto x;
}
break;
case 'w':
if(ylt>=0){
cleardevice();
instructions();
normaldraw();
shapes();
delay(15);
line(xlt,ylt--,xrt,yrt--);
line(xlt,ylt--,xlb,ylb--);
line(xlb,ylb--,xrb,yrb--);
line(xrt,yrt--,xrb,yrb--);
}
break;
case 's':
if(ylb<=435){
cleardevice();
instructions();
normaldraw();
shapes();
delay(15);
line(xlt,ylt++,xrt,yrt++);
line(xlt,ylt++,xlb,ylb++);
line(xlb,ylb++,xrb,yrb++);
line(xrt,yrt++,xrb,yrb++);
}
break;
case 'd':
if(xrt<=r7){
cleardevice();
instructions();
normaldraw();
shapes();
delay(15);
line(xlt++,ylt,xrt++,yrt);
line(xlt++,ylt,xlb++,ylb);
line(xlb++,ylb,xrb++,yrb);
line(xrt++,yrt,xrb++,yrb);
}
break;
case 'f':
instructions();
shapes();
if(xlt>=rx1&&ylt>=ry1&&ylb<=ry2&&xrt<=rx3&&yrt>=ry3&&yrb<=ry4){
count++;
goto x;
}
break;
case 'i':
if(ucx<=196&&ucx>=184&&ucy<=56&&ucy>=44){
count++;
goto x;
}
break;
case 'c':
getch();
closegraph();
break;
}//switch ends
}//kbhit ends
}//while1 ends
x:
cleardevice();
printf("\nScore=%d",count);
outtextxy(r5,r6,"+1 point");
goto y;
}//main ends
