#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<string>
#include<vector>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <QPixmap>
#include <cstdlib>
#include <locale>
#include <codecvt>
//exit
#include<unistd.h>
//содержит функции для работы с сетевыми адресами, такие как htons.
#include<arpa/inet.h>
//определяет символы, начинающиеся с " AF_ " для различных видов сетей и для работы сокетов
#include<sys/socket.h>
//функции для работы с сетевыми именами и адресами.
#include<netdb.h>
//содержащую определения для работы с интернет-адресами и портами.
#include<netinet/in.h>
#include <QMessageBox>

#define SERVER_IP "10.241.107.115"
#define NUMBER_PORT 7432
#define MAX_SIZE_BUF 10000
using namespace std;
void parseAndAdd(string mes);
bool DelBas(string number);
void ReKol(string number, double kol);
string finds(string number);
bool CheckNumber(string check);
QString TotalAmount(bool discounts);
void makingFile(const string& filename, bool discounts);
bool emptyBasketss();
string Pay();
bool YesOrNo();
void DeletOld();
bool checkingInjections(const string& str);
void restartApplication(QApplication *app);
#endif // HEADER_H
