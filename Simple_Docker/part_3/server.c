#include <stdlib.h>
#include <fcgi_stdio.h>

int main(){
    while (FCGI_Accept() >= 0){
        printf("Content-type: text/html\r\n\r\n");
        printf("<html>");
        printf("<body><h1>Hello world!</h1><body>\n");
        printf("</html>");
    }
    return 0;
}