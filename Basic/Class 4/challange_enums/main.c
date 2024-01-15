#include <stdio.h>
#include <stdbool.h>

int main() {

    enum Company {GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};

    enum Company google = GOOGLE;
    enum Company xerox = XEROX;
    enum Company ebay = EBAY;
    enum Company myCompany = GOOGLE;

    bool isMyCompany = (myCompany == google);

    printf("%d\n", xerox);
    printf("%d\n", google);
    printf("%d\n", ebay);
    printf("%d\n", isMyCompany);

    return 0;
}