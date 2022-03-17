#if defined _loadingbar_included
  #endinput
#endif
#define _loadingbar_included

#define			 MAX_CALLBACK_STR			34

static  PlayerText:LoadingBar[MAX_PLAYERS][3],
        LoadingTimer[MAX_PLAYERS],
        LoadingValue[MAX_PLAYERS],
        LoadingMaxValue[MAX_PLAYERS],
        bool:IsLoading[MAX_PLAYERS],
		LoadingCallback[MAX_PLAYERS][MAX_CALLBACK_STR];

forward OnLoadingBarFinished(playerid);
forward OnLoadingBarProgress(playerid, value);

static Loading_Remove(playerid)
{
	for(new i = 0; i < 3; i++)
	{
		PlayerTextDrawDestroy(playerid, LoadingBar[playerid][i]);
	}
	LoadingValue[playerid] = 0;
	LoadingMaxValue[playerid] = 0;
	IsLoading[playerid] = false;
	LoadingCallback[playerid][0] = EOS;
	return 1;
}

static Loading_BarUpdate(playerid)
{
	PlayerTextDrawTextSize(playerid, LoadingBar[playerid][1], LoadingValue[playerid] * 79 / LoadingMaxValue[playerid], 13.500000);
	PlayerTextDrawShow(playerid, LoadingBar[playerid][1]);
}

forward Loading_TimerUpdate(playerid);
public Loading_TimerUpdate(playerid)
{
	if(!IsValidLoadingBar(playerid))
		return 0;

	if(LoadingValue[playerid] < LoadingMaxValue[playerid])
	{
		LoadingValue[playerid]++;
		Loading_BarUpdate(playerid);
        CallLocalFunction(#OnLoadingBarProgress, "dd", playerid, LoadingValue[playerid]);
	}
	else
	{
        CallLocalFunction(#OnLoadingBarFinished, "d", playerid);
		CallLocalFunction(LoadingCallback[playerid], "d", playerid);
		StopPlayerLoadingBar(playerid);	
	}
	return 1;
}

/* Used Functions */

stock IsValidLoadingBar(playerid)
	return IsLoading[playerid];

stock StartPlayerLoadingBar(playerid, value = 3, const text[] = "_", interval = 1000, const callback[] = EOS, color = 1687547311)
{
	if(IsValidLoadingBar(playerid))
		StopPlayerLoadingBar(playerid);

	LoadingBar[playerid][0] = CreatePlayerTextDraw(playerid, 277.000000, 399.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, LoadingBar[playerid][0], 4);
	PlayerTextDrawLetterSize(playerid, LoadingBar[playerid][0], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, LoadingBar[playerid][0], 83.000000, 18.000000);
	PlayerTextDrawSetOutline(playerid, LoadingBar[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, LoadingBar[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, LoadingBar[playerid][0], 1);
	PlayerTextDrawColor(playerid, LoadingBar[playerid][0], 1296911791);
	PlayerTextDrawBackgroundColor(playerid, LoadingBar[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, LoadingBar[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, LoadingBar[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, LoadingBar[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, LoadingBar[playerid][0], 0);

	LoadingBar[playerid][1] = CreatePlayerTextDraw(playerid, 279.000000, 401.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, LoadingBar[playerid][1], 4);
	PlayerTextDrawLetterSize(playerid, LoadingBar[playerid][1], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, LoadingBar[playerid][1], 0.000000, 13.500000);
	PlayerTextDrawSetOutline(playerid, LoadingBar[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, LoadingBar[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, LoadingBar[playerid][1], 1);
	PlayerTextDrawColor(playerid, LoadingBar[playerid][1], 1687547311);
	PlayerTextDrawBackgroundColor(playerid, LoadingBar[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, LoadingBar[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, LoadingBar[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, LoadingBar[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, LoadingBar[playerid][1], 0);

	LoadingBar[playerid][2] = CreatePlayerTextDraw(playerid, 318.000000, 403.000000, "_");
	PlayerTextDrawFont(playerid, LoadingBar[playerid][2], 1);
	PlayerTextDrawLetterSize(playerid, LoadingBar[playerid][2], 0.175000, 0.950000);
	PlayerTextDrawTextSize(playerid, LoadingBar[playerid][2], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, LoadingBar[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, LoadingBar[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, LoadingBar[playerid][2], 2);
	PlayerTextDrawColor(playerid, LoadingBar[playerid][2], -1);
	PlayerTextDrawBackgroundColor(playerid, LoadingBar[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, LoadingBar[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, LoadingBar[playerid][2], 0);
	PlayerTextDrawSetProportional(playerid, LoadingBar[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, LoadingBar[playerid][2], 0);

	PlayerTextDrawSetString(playerid, LoadingBar[playerid][2], text);
	PlayerTextDrawColor(playerid, LoadingBar[playerid][1], color);

	for(new i = 0; i < 3; i++)
	{
		PlayerTextDrawShow(playerid, LoadingBar[playerid][i]);
	}
	if(callback[0] != EOS)
	{
		format(LoadingCallback[playerid], MAX_CALLBACK_STR, "%s", callback);
	}
	LoadingValue[playerid] = 0;
	IsLoading[playerid] = true;
	LoadingMaxValue[playerid] = value;
	LoadingTimer[playerid] = SetTimerEx(#Loading_TimerUpdate, interval, true, "d", playerid);
	return 1;
}

stock StopPlayerLoadingBar(playerid)
{
    KillTimer(LoadingTimer[playerid]);
    Loading_Remove(playerid);	
}