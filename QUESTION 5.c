#include <stdio.h>
#include <ctype.h>

int wordCount(char s[])
{
    int count = 0, inside = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isspace((unsigned char)s[i]) && !inside)
        {
            count++;
            inside = 1;
        }
        else if (isspace((unsigned char)s[i]))
            inside = 0;
    }

    return count;
}

void uppercase(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = toupper((unsigned char)s[i]);
}

void reverseString(char s[])
{
    int len = 0;
    char temp;

    while (s[len] != '\0')
        len++;

    if (len > 0 && s[len - 1] == '\n')
        len--;

    for (int i = 0; i < len / 2; i++)
    {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

int palindrome(char s[])
{
    int left = 0, right = 0;

    while (s[right] != '\0')
        right++;

    right--;

    while (left < right)
    {
        while (left < right &&
               !isalnum((unsigned char)s[left]))
            left++;

        while (left < right &&
               !isalnum((unsigned char)s[right]))
            right--;

        if (tolower((unsigned char)s[left]) !=
            tolower((unsigned char)s[right]))
            return 0;

        left++;
        right--;
    }

    return 1;
}

int main(void)
{
    char message[200], copy[200];
    int i;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Word count: %d\n", wordCount(message));
    printf("Palindrome: %d\n", palindrome(message));

    for (i = 0; message[i] != '\0'; i++)
        copy[i] = message[i];
    copy[i] = '\0';

    uppercase(copy);
    printf("Uppercase: %s", copy);

    reverseString(copy);
    printf("Reversed: %s\n", copy);

    return 0;
}
