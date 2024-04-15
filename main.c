/****************************************************
 *  Programm zum Senden von IDOK an alle Fenster,   *
 *  die einen angegebenen Text entalten             *
 +--------------------------------------------------+ 
 *  Syntax: AutoQuit Titelausschnitt [ID=123]       *
 ****************************************************
 ** Änderungen                                     **
 ****************************************************
 * 28.03.2024 *  aN * .05 * bei PostMessage Parameter WM_COMMAND ergänzt
 * 28.03.2024 *  aN * .06 * die Möglichkeit eine ID anzugeben
 ****************************************************/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

/*
  Suchen eines beliebigen Fensters
 */
int QuitWindowByText(char *suche, size_t id)
{
    HWND hwfd;
    char str[200];
    int found = 0;

    hwfd = FindWindow(NULL, NULL);

    while (TRUE)
    {
        hwfd = GetWindow(hwfd, GW_HWNDNEXT);
        if (hwfd)
        {
            GetWindowText(hwfd, str, 200);
            if (strstr(str, suche) != NULL)
            {
                printf("Found: %s\n",str);
                // SetForegroundWindow(hwfd);
                // PostMessage(hwfd, WM_SETFOCUS, id, 0);
                // keybd_event(VK_RETURN,0,0,0);
                // keybd_event(VK_RETURN,0,KEYEVENTF_KEYUP,0);
                
                PostMessage(hwfd, WM_COMMAND , id, 0);
                found++;
            }
        }
        else
        {
            break;
        }
    }
    return found;
}


int main(int argc, char *argv[])
{
    HWND hCon = GetConsoleWindow();
    size_t id = IDOK;
    char titel[350];
    
    if (2 > argc)
    {
        printf("Usage:\nAutoQuit Text [ID=<n>]\n");
        return 1;
    }

    // Gibts noch einen Parameter
    if(3 == argc)
    {
        // Beginnt er mit ID=
        if (0 == strnicmp(argv[2],"ID=",3))
        {
            // dann kommt mit dem 4. Zeichen die ID
            id = atoi(&argv[2][3]);
        }
    }
    
    GetWindowText(hCon, titel, sizeof(titel));
    SetWindowText(hCon,"~S~e~a~r~c~h~");
    printf("Sent IDOK to %d windows\n", QuitWindowByText(argv[1], id));
    SetWindowText(hCon, titel);
    return 0;
}
