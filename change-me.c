//gcc -fno-stack-protector -no-pie -z execstack change-me.c -o change-me
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define USERNAME_BUFF_LEN 50

//leftover debug code ;). Could be helpful...
void debug_console() {
  system("/bin/sh");
  exit(0);
}

//user authentication routine.
//I wonder if there are any bugs...
int auth_user() {
  //Yes yes, hard coded password. The goal is to make this readable, not
  //difficult. running 'strings' against the binary to find the password
  //is not the goal of this excercise.
  char password[] = "Sup3r$3cr37\n";
  char username[USERNAME_BUFF_LEN];
  char user_pass[12];

  //Print to the user, requesting their username
  printf("Enter your name: ");
  //Read username from stdin, entered by user
  scanf("%s", username);

  //Print more stuff to user, requesting their password
  printf("Hello ");
  printf(username);
  printf("\nPlease enter the password: ");
  scanf("%s",user_pass);

  //Check if users password is 'correct'
  if (strcmp(user_pass, password) == 0) {
    //Access granted :)
    puts("Welcome home Agent 47");
  } else {
    //Access Denied. Engage security systems :P .
    puts("Access Denied");
    return 1;
  }
  return 0;
}

int main ()
{
  int ret;

  //authenticate user
  ret = auth_user();
  return ret;
}
