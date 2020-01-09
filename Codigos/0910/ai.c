////////////////////////////////////////
//
//	File : ai.c
//	CoSpace Robot
//	Version 1.0.0
//	Jan 1 2016
//	Copyright (C) 2016 CoSpace Robot. All Rights Reserved
//
//////////////////////////////////////
//
// ONLY C Code can be compiled.
//
/////////////////////////////////////

#define CsBot_AI_H//DO NOT delete this line
#ifndef CSBOT_REAL
#include <windows.h>
#include <stdio.h>
#include <math.h>
#define DLL_EXPORT extern __declspec(dllexport)
#define false 0
#define true 1
#endif//The robot ID : It must be two char, such as '00','kl' or 'Cr'.
char AI_MyID[2] = {'0','2'};

int Duration = 0;
int SuperDuration = 0;
int bGameEnd = false;
int CurAction = -1;
int CurGame = 0;
int SuperObj_Num = 0;
int SuperObj_X = 0;
int SuperObj_Y = 0;
int Teleport = 0;
int LoadedObjects = 0;
int US_Front = 0;
int US_Left = 0;
int US_Right = 0;
int CSLeft_R = 0;
int CSLeft_G = 0;
int CSLeft_B = 0;
int CSRight_R = 0;
int CSRight_G = 0;
int CSRight_B = 0;
int PositionX = 0;
int PositionY = 0;
int TM_State = 0;
int Compass = 0;
int Time = 0;
int WheelLeft = 0;
int WheelRight = 0;
int LED_1 = 0;
int MyState = 0;
int AI_SensorNum = 13;

#define CsBot_AI_C//DO NOT delete this line

DLL_EXPORT void SetGameID(int GameID)
{
    CurGame = GameID;
    bGameEnd = 0;
}

DLL_EXPORT int GetGameID()
{
    return CurGame;
}

//Only Used by CsBot Dance Platform
DLL_EXPORT int IsGameEnd()
{
    return bGameEnd;
}

#ifndef CSBOT_REAL

DLL_EXPORT char* GetDebugInfo()
{
    char info[1024];
    sprintf(info, "Duration=%d;SuperDuration=%d;bGameEnd=%d;CurAction=%d;CurGame=%d;SuperObj_Num=%d;SuperObj_X=%d;SuperObj_Y=%d;Teleport=%d;LoadedObjects=%d;US_Front=%d;US_Left=%d;US_Right=%d;CSLeft_R=%d;CSLeft_G=%d;CSLeft_B=%d;CSRight_R=%d;CSRight_G=%d;CSRight_B=%d;PositionX=%d;PositionY=%d;TM_State=%d;Compass=%d;Time=%d;WheelLeft=%d;WheelRight=%d;LED_1=%d;MyState=%d;",Duration,SuperDuration,bGameEnd,CurAction,CurGame,SuperObj_Num,SuperObj_X,SuperObj_Y,Teleport,LoadedObjects,US_Front,US_Left,US_Right,CSLeft_R,CSLeft_G,CSLeft_B,CSRight_R,CSRight_G,CSRight_B,PositionX,PositionY,TM_State,Compass,Time,WheelLeft,WheelRight,LED_1,MyState);
    return info;
}
 
DLL_EXPORT char* GetTeamName()
{
     return "CoSpace Team";
}

DLL_EXPORT int GetCurAction()
{
    return CurAction;
}

//Only Used by CsBot Rescue Platform
DLL_EXPORT int GetTeleport()
{
    return Teleport;
}

//Only Used by CsBot Rescue Platform
DLL_EXPORT void SetSuperObj(int X, int Y, int num)
{
    SuperObj_X = X;
    SuperObj_Y = Y;
    SuperObj_Num = num;
}
//Only Used by CsBot Rescue Platform
DLL_EXPORT void GetSuperObj(int *X, int *Y, int *num)
{
    *X = SuperObj_X;
    *Y = SuperObj_Y;
    *num = SuperObj_Num;
}

#endif ////CSBOT_REAL

DLL_EXPORT void SetDataAI(volatile int* packet, volatile int *AI_IN)
{

    int sum = 0;

    US_Front = AI_IN[0]; packet[0] = US_Front; sum += US_Front;
    US_Left = AI_IN[1]; packet[1] = US_Left; sum += US_Left;
    US_Right = AI_IN[2]; packet[2] = US_Right; sum += US_Right;
    CSLeft_R = AI_IN[3]; packet[3] = CSLeft_R; sum += CSLeft_R;
    CSLeft_G = AI_IN[4]; packet[4] = CSLeft_G; sum += CSLeft_G;
    CSLeft_B = AI_IN[5]; packet[5] = CSLeft_B; sum += CSLeft_B;
    CSRight_R = AI_IN[6]; packet[6] = CSRight_R; sum += CSRight_R;
    CSRight_G = AI_IN[7]; packet[7] = CSRight_G; sum += CSRight_G;
    CSRight_B = AI_IN[8]; packet[8] = CSRight_B; sum += CSRight_B;
    PositionX = AI_IN[9]; packet[9] = PositionX; sum += PositionX;
    PositionY = AI_IN[10]; packet[10] = PositionY; sum += PositionY;
    TM_State = AI_IN[11]; packet[11] = TM_State; sum += TM_State;
    Compass = AI_IN[12]; packet[12] = Compass; sum += Compass;
    Time = AI_IN[13]; packet[13] = Time; sum += Time;
    packet[14] = sum;

}
DLL_EXPORT void GetCommand(int *AI_OUT)
{
    AI_OUT[0] = WheelLeft;
    AI_OUT[1] = WheelRight;
    AI_OUT[2] = LED_1;
    AI_OUT[3] = MyState;
}
void Game0()
{

    if(SuperDuration>0)
    {
        SuperDuration--;
    }
    else if(Duration>0)
    {
        Duration--;
    }
    else if(CSLeft_R>=204 && CSLeft_R<=235 && CSLeft_G>=163 && CSLeft_G<=186 && CSLeft_B>=0 && CSLeft_B<=20 && CSRight_R>=204 && CSRight_R<=235 && CSRight_G>=163 && CSRight_G<=186 && CSRight_B>=0 && CSRight_B<=20)
    {
        Duration = 49;
        CurAction =1;
    }
    else if(CSLeft_R>=204 && CSLeft_R<=235 && CSLeft_G>=217 && CSLeft_G<=248 && CSLeft_B>=0 && CSLeft_B<=20 && CSRight_R>=204 && CSRight_R<=235 && CSRight_G>=217 && CSRight_G<=248 && CSRight_B>=0 && CSRight_B<=20)
    {
        Duration = 0;
        CurAction =2;
    }
    else if(CSLeft_R>=204 && CSLeft_R<=235 && CSLeft_G>=217 && CSLeft_G<=248 && CSLeft_B>=0 && CSLeft_B<=20 && CSRight_R>=0 && CSRight_R<=0 && CSRight_G>=0 && CSRight_G<=0 && CSRight_B>=0 && CSRight_B<=0)
    {
        Duration = 0;
        CurAction =3;
    }
    else if(CSRight_R>=204 && CSRight_R<=235 && CSRight_G>=217 && CSRight_G<=248 && CSRight_B>=0 && CSRight_B<=20)
    {
        Duration = 0;
        CurAction =4;
    }
    else if(US_Front>=0 && US_Front<=15)
    {
        Duration = 0;
        CurAction =5;
    }
    else if(US_Left>=0 && US_Left<=10)
    {
        Duration = 0;
        CurAction =6;
    }
    else if(US_Right>=0 && US_Right<=10)
    {
        Duration = 0;
        CurAction =7;
    }
    else if(CSLeft_R>=0 && CSLeft_R<=0 && CSLeft_G>=0 && CSLeft_G<=0 && CSLeft_B>=0 && CSLeft_B<=0)
    {
        Duration = 49;
        CurAction =8;
    }
    else if(CSRight_R>=0 && CSRight_R<=0 && CSRight_G>=0 && CSRight_G<=0 && CSRight_B>=0 && CSRight_B<=0)
    {
        Duration = 49;
        CurAction =9;
    }
    else if(CSLeft_R>=0 && CSLeft_R<=0 && CSLeft_G>=221 && CSLeft_G<=255 && CSLeft_B>=255 && CSLeft_B<=255)
    {
        Duration = 49;
        CurAction =10;
    }
    else if(CSRight_R>=0 && CSRight_R<=0 && CSRight_G>=221 && CSRight_G<=255 && CSRight_B>=255 && CSRight_B<=255)
    {
        Duration = 49;
        CurAction =11;
    }
    else if(CSLeft_R>=204 && CSLeft_R<=245 && CSLeft_G>=0 && CSLeft_G<=0 && CSLeft_B>=0 && CSLeft_B<=0)
    {
        Duration = 49;
        CurAction =12;
    }
    else if(CSRight_R>=204 && CSRight_R<=245 && CSRight_G>=0 && CSRight_G<=0 && CSRight_B>=0 && CSRight_B<=0)
    {
        Duration = 49;
        CurAction =13;
    }
    else if(true)
    {
        Duration = 0;
        CurAction =14;
    }
    switch(CurAction)
    {
        case 1:
            WheelLeft=0;
            WheelRight=0;
            LED_1=2;
            MyState=0;
            if(Duration == 1) {LoadedObjects = 0; } 
            break;
        case 2:
            WheelLeft=-4;
            WheelRight=-2;
            LED_1=0;
            MyState=0;
            break;
        case 3:
            WheelLeft=-2;
            WheelRight=-4;
            LED_1=0;
            MyState=0;
            break;
        case 4:
            WheelLeft=-4;
            WheelRight=-2;
            LED_1=0;
            MyState=0;
            break;
        case 5:
            WheelLeft=-2;
            WheelRight=1;
            LED_1=0;
            MyState=0;
            break;
        case 6:
            WheelLeft=3;
            WheelRight=-3;
            LED_1=0;
            MyState=0;
            break;
        case 7:
            WheelLeft=-3;
            WheelRight=3;
            LED_1=0;
            MyState=0;
            break;
        case 8:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            if(Duration == 1) LoadedObjects++;
            if(Duration < 6)
            {
                WheelLeft = 2;
                WheelRight = 2;
            }
            break;
        case 9:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            break;
        case 10:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            break;
        case 11:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            break;
        case 12:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            break;
        case 13:
            WheelLeft=0;
            WheelRight=0;
            LED_1=1;
            MyState=0;
            break;
        case 14:
            WheelLeft=3;
            WheelRight=3;
            LED_1=0;
            MyState=0;
            break;
        default:
            break;
    }

}


DLL_EXPORT void OnTimer()
{
    switch (CurGame)
    {
        case 9:
            break;
        case 10:
            WheelLeft=0;
            WheelRight=0;
            LED_1=0;
            MyState=0;
            break;
        case 0:
            Game0();
            break;
        default:
            break;
    }
}

