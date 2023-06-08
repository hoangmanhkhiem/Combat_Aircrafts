#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define Esc 27 //Exit
#define Up 72 //up down right left
#define Down 80
#define Left 75
#define Right 77
#define Kong 32 // Gun


int x=10; //Toa do may bay
int y=18;

//Toa do target
int d1=10;
int d2=10;
int d3=10;
int d=10;
int r=1;
int r1=1;
int r2 =1;
int r3=1;

int t=1; //Gameover
int f=0; // Score
int m=4; // May bay dich
int j=0; // Diem tieu diet
char p; // Nhan phim
int hp = 3; // Mau may bay


void Remote_NV(int bx,int by);//Ham khai bao
void setup_background();


void gotoxy(int x,int y) //Di chuyen toa do
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
void hidden_point()//an con tro
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible=0;// 1 hien thi, 0 an
    SetConsoleCursorInfo(hOut,&cci);
}
//**************************************************************************************


//??
void Show_title()
{
	gotoxy(30,0);
    printf("\tGame ban may bay - SKROMNYY");
    gotoxy(0,0);
}


//****************************************************************************************


//Danh gia end game hay chua
void GAMEEND()
{
	if((x==d&&y==r)||(x==d+1&&y==r+1)||(x==d-1&&y==r-1)){
		hp -= 1;
        gotoxy(26,3);
        printf("\tHP: %d \n",hp);
        printf("   ");
        if(r) r=0;
        x = 10;
        y = 18;
        gotoxy(10,18);
        printf("<^>");
	}
	else if((x==d1&&y==r1)||(x==d1+1&&y==r1+1)||(x==d1-1&&y==r1-1)){
		hp -= 1;
        gotoxy(26,3);
        printf("\tHP: %d \n",hp);
        printf("   ");
        if(r1) r1=0;
        x = 10;
        y = 18;
        gotoxy(10,18);
        printf("<^>");
	}
	else if((x==d2&&y==r2)||(x==d2+1&&y==r2+1)||(x==d2-1&&y==r2-1)){
		hp -= 1;
        gotoxy(26,3);
        printf("\tHP: %d \n",hp);
        printf("   ");
        if(r2) r2=0;
        x = 10;
        y = 18;
        gotoxy(10,18);
        printf("<^>");
	}
	else if((x==d3&&y==r3)||(x==d3+1&&y==r3+1)||(x==d3-1&&y==r3-1)){
		hp -= 1;
        gotoxy(26,3);
        printf("\tHP: %d \n",hp);
        printf("   ");
        if(r3) r3=0;
        x = 10;
        y = 18;
        gotoxy(10,18);
        printf("<^>");
	}
	else if(r==18){
		hp -= 1;
        gotoxy(26,3);
        printf("\tHP: %d \n",hp);
        if(r) r=0;
	}
	else if(r2==18){
		hp -= 1;
        gotoxy(26,3);
        printf("\tHP: %d \n",hp);
        if(r2) r2=0;
	}
	else if(r3==18){
		hp -= 1;
        gotoxy(26,3);
        printf("\tHP: %d \n",hp);
        if(r3) r3=0;
	}
	else if(r1==18){
		hp -= 1;
        gotoxy(26,3);
        printf("\tHP: %d \n",hp);
        if(r1) r1=0;
	}
    if(hp==0){
        gotoxy(26,4);
        printf(" \t\t\t!!! GAME OVER !!!\n"
                "\t\t\t\t\t*******************\n"
                " \t\t\t\t\tYour Score: %d\n\n"
                " \t\t\t\t\tNumber of enemies: %d\n"
                " \t\t\t\t\tNumber of enemies destroyed: %d\n"
                " \t\t\t\t\tHit rate: %.0f %%\n"
                "\t\t\t\t\t*******************\n",f,m,j,((float)j/(float)m)*100);
        while(!kbhit())
        {
            Sleep(500);
            gotoxy(1,12);
            printf("\t\t\t\t\tBam phim backspace de tiep tuc...\n\n\n");
            Sleep(900);
            gotoxy(1,12);
            printf("   ");
        }
        gotoxy(0,0);
        setup_background();
        hp=3;f=0; m=0; j=0;
        x = 10; y = 18;
        gotoxy(26,3);
        printf("\tHP: %d \n",hp);
        if(x>=18) x--;
        else x++;
        if(r) r=0;
        if(r1) r1=0;
        gotoxy(10,18);
        printf("<^>");
    }
}

// Cap nhat may bay dich bi tieu diet
void Tinhdiem()
{
    if(x==d&&y==r||x==d+1&&y==r+1||x==d-1&&y==r-1)
    {
        gotoxy(d,r); printf("Bum");
        Sleep(200);
        gotoxy(d,r); printf("   "); f+=1; r=0; j++;}
    if(x==d1&&y==r1||x==d1+1&&y==r1+1||x==d1-1&&y==r1-1)
    {
        gotoxy(d1,r1); printf("Bum");
        Sleep(200);
        gotoxy(d1,r1); printf("   "); f+=1; r1=0; j++;}
	if(x==d2&&y==r2||x==d2+1&&y==r2+1||x==d2-1&&y==r2-1)
    {
        gotoxy(d2,r2); printf("Bum");
        Sleep(200);
        gotoxy(d2,r2); printf("   "); f+=1; r2=0; j++;}
    if(x==d3&&y==r3||x==d3+1&&y==r3+1||x==d3-1&&y==r3-1)
    {
        gotoxy(d3,r3); printf("Bum");
        Sleep(200);
        gotoxy(d3,r3); printf("   "); f+=1; r3=0; j++;}
    gotoxy(26,2);
    printf("\tScore: %d \n",f);

}

//Ve khung game
void setup_background()
{
    int i,n;
    for(i=0;i<=24;i++)
    {
        for(n=0;n<=24;n++)
        {
            printf("|");
        }
        printf("\n");
    }
    for(i=1;i<=23;i++)
    {
        for(n=1;n<=23;n++)
        {
            gotoxy(i,n);
            printf(" ");
        }
    }
}


// tao may bay dich
void spwan_dich ()
{
    while(t)
    {
        if(!r) {
            d=rand()%7+3; m++;
        }
        if(!r1) {
            d1=rand()%14+8; m++;
        }
        if (!r2) d2=rand()%7+3; m++;
        if (!r3) d3=rand()%14+8; m++;
        while(t)
        {
            r++; r1++, r2++,r3++;
            gotoxy(d,r); printf("<v>");
            gotoxy(d1,r1); printf("<v>");
            gotoxy(d2,r2); printf("<v>");
            gotoxy(d3,r3); printf("<v>");
            Sleep(900);
            gotoxy(d2,r2); printf("   ");
            gotoxy(d3,r3); printf("   ");
            gotoxy(d,r); printf("   ");
            gotoxy(d1,r1); printf("   ");
            Remote_NV(0,0);
            GAMEEND();
            if(r==18) r=0;
            if(r1==18) r1=0;
            if(r2==18) r2=0;
            if(r3==18) r3=0;
            if(r==0||r1==0||r2==0||r3==0) break;
        }
    }
}


// dieu khien may bay
void Remote_NV(int bx,int by)
{
    int a;
    while (kbhit())
    {
        if ((p=getch())==-32) p=getch();
        a=p;
        gotoxy(22,5);

        switch(a)
        {// dieu khien
            case Up:if (y!=1)
                {
                    gotoxy(x,y); printf("   ");
                    y--;
                    gotoxy(x,y); printf("<^>");
                }break;
            case Down:if (y!=18)
                { 
                    gotoxy(x,y); printf("   ");
                    y++;
                    gotoxy(x,y); printf("<^>");
                }break;
            case Left:if (x!=1)
                { 
                    gotoxy(x,y); printf("   ");
                    x--;
                    gotoxy(x,y); printf("<^>");
                }break;
            case Right:if (x!=21)
                { 
                    gotoxy(x,y); printf("   ");
                    x++;
                    gotoxy(x,y); printf("<^>");
                }break;
            case Kong:{
                bx=y;
                for(by=y;by>1;) // Ban dan
                {
                    by--;
                    gotoxy(x,by);
                    printf(".'.");
                    Sleep(10);
                    gotoxy(x,by);
                    printf("   ");
                    y=by;
                    Tinhdiem();
                    if(r==0||r1==0||r2==0||r3==0) break;
                }
                y=bx;
            }break;

            case Esc:t=0; break; //exit

            default:break;
        }
    }
}

void run()
{
    srand(time(NULL));
    Show_title();
    hidden_point();
    setup_background();
    gotoxy(26,2);
    printf("\tScore: %d \n",f);
    gotoxy(26,3);
    printf("\tHP: %d \n",hp);
    gotoxy(x,y);
    printf("<^>");

    gotoxy(22,2);
    while (t)
    {
        Remote_NV(0,0);
        if(t) spwan_dich ();
    }

}

void main(){
	printf("Xin chao moi nguoi\n");
	printf("MENU\n");
	printf("1.Ban may bay\n");
	printf("2.Exit");
	printf("\nNhap lua chon cua ban: ");
	int luachon;
	scanf("%d",&luachon);
	if(luachon==1){
		printf("                               ");
		run();
	}
	else if(luachon==2){
		printf("\nCam on ban da su dung");
		return 0;
	}
	else{
		do{
			printf("\nNhap lua chon cua ban: ");
			int luachon;
			scanf("%d",&luachon);
			if(luachon==1){
				printf("                               ");
				run();
			}
			else if(luachon==2){
				printf("\nCam on ban da su dung");
				return 0;
			}
		}while(luachon!=1||luachon!=2);
	}
}
