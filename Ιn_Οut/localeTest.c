/* Depicts wide character use. Adapted by P. Lampsas
* from an example found here: 
* https://en.cppreference.com/w/c/locale/setlocale 
*/

#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <wchar.h>
#include <string.h>
 
int main(void)
{   
    /* the C locale will be Greek
    * date and time formatting will be Francaise */
    printf("Locale is: %s\n", setlocale(LC_ALL, ""));
    setlocale(LC_TIME, "French_France");
    
    wchar_t str[100];
    time_t t = time(NULL);
    wcsftime(str, 100, L"%A %c", localtime(&t));
    wprintf(L"Number: %.2f\nDate: %ls\n", 3.14, str);
}
