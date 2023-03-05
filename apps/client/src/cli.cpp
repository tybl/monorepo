#include "socket.hpp"
#include "tictactoe.hpp"

#include <cstring>
#include <iostream>

#include <unistd.h>

auto main() -> int {
  client_socket cs("127.0.0.1", "9987");
  char sname[64];
  char cname[64];

  int count = 0;
  int inp = 0;
  int x = 0;
  int y = 0;
  int ni = 0;
  int inp_true = 0;
  int toss = 0;
  char serv_choice;
  char cli_choice;
  char nc;
  char choice_buffer[2];
  char co_ordinates_buffer[16];
  char toss_buffer;

  std::cout << "Enter your name : ";
  std::cin >> cname;
  ssize_t bytes_sent = 0;
  ssize_t bytes_recvd = 0;
  do {
    static int flag = 0;
    bytes_sent = cs.send(&cname, sizeof(cname));
    if (bytes_sent == -1 && flag == 0) {
      std::cout << "PLAYER DATA NOT SENT!" << std::endl << "Trying Again...";
      continue;
    }
    cli_choice = 'X';

    flag = 1;
    std::memset(&sname, 0, sizeof(sname));
    bytes_recvd = cs.recv(&sname, sizeof(sname));
    if (bytes_recvd == -1) {
      std::cout << "COULD NOT ACQUIRE PLAYER INFORMATION!" << std::endl << "Trying Again..." << std::endl;
    } else {
      std::cout << "You have joined " << sname << " for a game of Tic-Tac-Toe." << std::endl;
    }
  } while (bytes_sent == -1 || bytes_recvd == -1);

  std::cout << "Creating game. Please wait..." << std::endl;
  sleep(2);
  std::cout << std::endl << "Game created!" << std::endl << std::endl << "Doing a toss...";

  bytes_recvd = cs.recv(&toss_buffer, sizeof(toss_buffer));
  std::cerr << "Line " << __LINE__ << ": received " << bytes_recvd << " bytes for the toss_buffer\n";
  if (bytes_recvd == -1) {
    perror("TOSS BUFFER not received");
    return 1;
  }

  toss = toss_buffer - '0';
  if (toss == 0) {
    std::cout << std::endl << sname << " WON the toss." << std::endl;
    std::cout << sname << " is choosing. Please wait..." << std::endl << std::endl;
    std::memset(&choice_buffer, 0, sizeof(choice_buffer));
    bytes_recvd = cs.recv(&choice_buffer, sizeof(choice_buffer));
    if (bytes_recvd == -1) {
      perror("CHOICE BUFFER not received!");
      return 1;
    }
    serv_choice = choice_buffer[0];
    cli_choice = choice_buffer[1];
    std::cout << sname << " has chosen " << serv_choice << std::endl
              << std::endl
              << "You will play with " << cli_choice << std::endl;
    std::cout << std::endl << "Lets Play!" << std::endl << std::endl;
  } else {
    std::cout << std::endl << "You won the TOSS!" << std::endl;
    do {
      std::cout << cname << " Enter Your Choice (X or O): ";
      std::cin >> cli_choice;
      if (cli_choice == 'X' || cli_choice == 'x') {
        serv_choice = 'O';
        cli_choice = 'X';
        inp_true = 1;
        std::cout << std::endl
                  << sname << " gets O." << std::endl
                  << std::endl
                  << "Lets Play!" << std::endl
                  << std::endl;
      } else if (cli_choice == 'O' || cli_choice == 'o' || cli_choice == '0') {
        serv_choice = 'X';
        cli_choice = 'O';
        inp_true = 1;
        std::cout << std::endl
                  << sname << " gets X." << std::endl
                  << std::endl
                  << "Lets Play!" << std::endl
                  << std::endl;
      } else {
        std::cout << "\nInvalid Choice! Please Choose Again..." << std::endl;
      }
    } while (inp_true == 0);

    std::memset(&choice_buffer, 0, sizeof(choice_buffer));
    choice_buffer[0] = serv_choice;
    choice_buffer[1] = cli_choice;

    bytes_sent = cs.send(&choice_buffer, sizeof(choice_buffer));
    if (bytes_sent == -1) {
      perror("CHOICE BUFFER could not be sent.");
      return 1;
    }
  }

  if (serv_choice == 'X') {
    inp = 1;
    std::cout << sname << " will play first." << std::endl << std::endl;

  } else {
    inp = 2;
    std::cout << "You will play first." << std::endl << std::endl;
  }

  init();
  std::cout << std::endl << "Starting Game..." << std::endl;
  sleep(3);
  display();

  while (count < 9) {
    std::memset(&co_ordinates_buffer, 0, sizeof(co_ordinates_buffer));

    if (inp % 2 != 0) {
      std::cout << std::endl << sname << "'s turn. Please wait..." << std::endl;
      bytes_recvd = cs.recv(&co_ordinates_buffer, sizeof(co_ordinates_buffer));
      if (bytes_recvd == -1) {
        perror("CO-ORDINATES BUFFER not recieved!");
        return 1;
      }
      x = co_ordinates_buffer[0] - '0';
      y = co_ordinates_buffer[1] - '0';
      ni = input(serv_choice, x, y);
      if (ni == 0) {
        inp++;
        std::cout << std::endl << sname << " has played. Updating Matrix..." << std::endl;
      }
    } else {
      std::cout << std::endl << "Your turn. Enter co-ordinates separated by a space : ";
      std::cin >> x >> y;
      ni = input(cli_choice, x, y);
      if (ni == 0) {
        inp++;
        sprintf(&co_ordinates_buffer[0], "%d", x);
        sprintf(&co_ordinates_buffer[1], "%d", y);
        std::cout << std::endl << "Updating Matrix..." << std::endl;

        bytes_sent = cs.send(&co_ordinates_buffer, 2);
        if (bytes_sent == -1) {
          perror("CO-ORDINATES BUFFER could not be sent!");
          return 1;
        }
      }
    }

    count++;
    sleep(2);
    system("clear");
    display();

    if (count >= 5) {
      nc = check();
      if (nc == 'f') {
        continue;
      } 
      if (serv_choice == nc) {
        std::cout << std::endl << "You loose." << std::endl << sname << " has won." << std::endl;
        break;
      }
      if (cli_choice == nc) {
        std::cout << std::endl << "Congrats! You have won!!!" << std::endl << sname << " lost." << std::endl;
        break;
      }
    }
  }

  if (nc == 'f') {
    std::cout << std::endl << "Game ends in a draw." << std::endl;
  }

  std::cout << std::endl << "Thank You for playing Tic-tac-Toe" << std::endl;
  return 0;
}
