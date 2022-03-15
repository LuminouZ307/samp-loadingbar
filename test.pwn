#include <a_samp>
#include <loadingbar>

main() 
{

}

public OnPlayerCommandText(playerid, cmdtext[])
{
    if(!strcmp(cmdtext, "loadingbar", true))
    {
        if(IsValidLoadingBar(playerid)) // check if player still have active LoadingBar
            return SendClientMessage(playerid, -1, "You already have active LoadingBar!");
            
        StartPlayerLoadingBar(playerid, 10, "Loading..."); 
        SendClientMessage(playerid, -1, "LoadingBar started!");
        // will show player a LoadingBar with max value '10' (means 10 seconds) and text 'Loading...' .
    }
    return 0;
}

public OnLoadingBarProgress(playerid, value) // detect every LoadingBar value updated.
{
    if(value == 5)
    {
        SendClientMessage(playerid, -1, "The value of LoadingBar is now '5'");
    }
    return 1;
}
public OnLoadingBarFinished(playerid) // detect when current LoadingBar finished.
{
    SendClientMessage(playerid, -1, "LoadingBar finished!");
    return 1;
}