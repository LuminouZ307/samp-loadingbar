#include <a_samp>
#include <samp-loadingbar>

main() 
{

}

public OnPlayerCommandText(playerid, cmdtext[])
{
    if(!strcmp(cmdtext, "loadingbar", true))
    {
        if(IsValidLoadingBar(playerid)) // check if player still have active LoadingBar
            return SendClientMessage(playerid, -1, "You already have active LoadingBar!");
            
        StartPlayerLoadingBar(playerid, // The player to be shown LoadingBar
                            10, // The max value of the LoadingBar (default are 3)
                            "Loading...", // The text to display on LoadingBar 
                            300, // The update interval for the LoadingBar (default are 1000, means every 1 second)
                            "TestLoadingBar", // The callback that will called when the LoadingBar finished. (empty if you don't want to)
                            1687547311 // The color for LoadingBar, you kan use color format like 0x.... 
                        );
        SendClientMessage(playerid, -1, "LoadingBar started!");
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

forward TestLoadingBar(playerid); // The callback that called when starting the LoadingBar
public TestLoadingBar(playerid)
{
    SendClientMessage(playerid, -1, "This is test LoadingBar!");
    return 1;
}