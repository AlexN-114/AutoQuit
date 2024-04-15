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
 * 15.04.2024 *  aN * .09 * regex ala ChkWnd()
 ****************************************************/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "..\\tiny-regex-c\\re.h"

//** Prototypen ***********************************/
int StrInStr(char *sub, char *str);
int RegEx(char *sub, char *str);
int CloseWindowByText(char *suche);

//** Variablen ************************************/
int (*compare)(char *sub,char *str);
char wie_t[] = "text";
char wie_r[] = "regex";
char *wie = wie_t;
char suchtit[] = "~S~e~a~r~c~h~";
HWND selbst = NULL;
int ignore_case = 0;
int dummy = 0;
char titel[500];

//*************************************************/

/*
 Suche String in String
*/
int StrInStr(char *sub, char *str)
{
    char *pos = strstr(sub,str);
    return (pos != NULL);
}

/*
 regular expression
*/
int RegEx(char *sub, char *str)
{
    int l;
    int res = re_match(str, sub, &l);
    return (res != -1);
}

/*
  Suchen eines beliebigen Fensters
 */
int QuitWindowByText(char *txt, size_t id)
{
    HWND hwnd;
    int treffer = 0;
    static char hStr[500];
    
    printf("Suche (%s): %s\n",wie,txt);

    hwnd = FindWindow(NULL, NULL);

    while(hwnd != NULL)
    {
        // - Fenster auswerten
        GetWindowText(hwnd, hStr, sizeof(hStr));
        
        if (selbst != hwnd)
        {
            if ((*compare)(hStr, txt) != 0)
            {
                printf("gefunden: %s\n", hStr);
                PostMessage(hwnd, WM_COMMAND , id, 0);
                treffer++;
            }
        }
        else
        {
            // printf("geigenes Fenster: %s\n", hStr);
        }
        hwnd = GetWindow(hwnd,GW_HWNDNEXT);
    }
    printf("Treffer: %d\n", treffer);
    return treffer;
}

int main(int argc, char *argv[])
{
    selbst = GetWindow(GetConsoleWindow(),GW_OWNER);
    size_t id = IDOK;
    char titel[350];
    char *srch = NULL;
    int treffer_ges = 0;
   
   compare = &StrInStr;   
    
    GetConsoleTitle(titel, sizeof(titel));

    SetConsoleTitle(suchtit);
    Sleep(100);
    
    for(int i=1;i<argc;i++)
    {
        if (strcmp(argv[i],"-r")==0)
        {
            compare = &RegEx;
            wie = wie_r;
        }
        else if (strcmp(argv[i],"-t")==0)
        {
            compare = &StrInStr;
            wie = wie_t;
        }
        else if (0 == strnicmp(argv[i],"ID=",3))
        {
            // dann kommt mit dem 4. Zeichen die ID
            id = atoi(&argv[i][3]);
        }
        else
        {
            srch = argv[i];
            treffer_ges += QuitWindowByText(srch, id);
        }
    }

    if (srch != NULL)
    {
        printf("gesamt %d Treffer gefunden\n", treffer_ges);
    }
    else
    {
        printf("Verwendung:\nAutoQuit [[-r][-t][ID=##] <SuchText>]...\n%%ERRORLEVEL%% ist Anzahl Treffer\n");
    }

    SetConsoleTitle(titel);

    return treffer_ges;
}
