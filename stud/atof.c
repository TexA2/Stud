#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100


double atof(char[]);
/*Объявление функции можно делать как вне функций, так
и внутри других функций!*/

int main()
{
    //double atof(char[]);
    char line[MAXLINE] = {'-','1','2','3','4','5','4','.','2'};
    printf("%0.2f\n", atof(line)+0.3);
    

}


double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++);

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i]- '0');


    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return sign * val / power;

}
