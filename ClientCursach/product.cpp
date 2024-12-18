#include "product.h"
#include "ui_product.h"
#include "basketss.h"
#include "catalog.h"
#include "maps.h"
#include "kol.h"
#include <fstream>
Product::Product(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Product)
{
    // Инициализация серверного соединения
    Connect = new Connection(SERVER_IP, NUMBER_PORT);
    ui->setupUi(this);

    QPixmap pix2(":/resur/mg/карта.png");
    int w2= ui->map->width();
    int h2= ui->map->height();
    ui->map->setPixmap(pix2.scaled(w2, h2, Qt::KeepAspectRatio));

    QPixmap pix(":/resur/mg/корзина.png");
    int w= ui->bask->width();
    int h= ui->bask->height();
    ui->bask->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    // Устанавливаем максимальный размер окна
    this->setMaximumSize(1200, 800);

    // Устанавливаем минимальный размер окна (опционально)
    this->setMinimumSize(600, 800);

}

Product::~Product()
{
    delete Connect;
    delete ui;
}

class List {
public:
    string idProd;
    string name;
    string type;
    double value;
    double kol;
    double general;

    List(string id_, string name_,string type_, double value_,double kol_, double general_) : idProd(id_), name(name_),type(type_), value(value_), kol(kol_), general(general_) {}
};

class basket{
    vector<List> besketList;
public:
    // Метод для добавления элемента в корзину
    void Add(string idProd, string name, string type, double value, double kol) {
        bool normKol=true;
        for (auto& list : besketList) {
            if (list.idProd == idProd && list.kol<10) {
                list.kol += kol;
                list.general = list.kol * list.value;
                return;
            }else if(list.idProd == idProd && list.kol>=10){
                normKol=false;
                break;
            }
        }
        // Если продукта с таким кодом нет, добавляем новый
        if(normKol){
              besketList.push_back(List(idProd, name, type, value, kol, kol * value));
        }
    }
    // Метод для удаления элемента из корзины по idProd
    bool Delete(string idProd) {
        for (auto i = besketList.begin(); i != besketList.end(); ++i) {
            if (i->idProd == idProd) {
                besketList.erase(i);
                return true;
            }
        }
        return false;
    }

    // Метод для изменения количества в строке по idProd
    void ChangeQuantity(string idProd, double newQuantity) {
        for (auto& list : besketList) {
            if (list.idProd == idProd) {
                list.kol = newQuantity;
                list.general = newQuantity * list.value;
                break;
            }
        }
    }
    //Метод поиска
    string FindCode(string idProd){
        for (auto& list : besketList) {
            if (list.idProd == idProd) {
                return list.type;
            }
        }
        return "Не найдено";
    }

    // Метод для вывода всех данных в строку
    string print() {
        double price=0.0;
        ostringstream oss;
        for (const auto& list : besketList) {
            oss << "Код: " << list.idProd << "\nНазвание: " << list.name << "\nВид: " << list.type<< "\nЦена: " << list.value << "\nКол: " << list.kol << "\nИтог: " << list.general << "\n";
            price+=list.general;
            oss << "-----------------------------------\n";
        }
        oss<<"К оплате: "<<price;
        return oss.str();
    }
    // Метод для создания текстового файла
    void createTextFile(const string& filename, bool discounts) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Ошибка открытия файла для записи: " << filename << endl;
            return;
        }

        double price = 0.0;
        for (const auto& list : besketList) {
            file << "Код: " << list.idProd << "\nНазвание: " << list.name << "\nВид: " << list.type << "\nЦена: " << list.value << "\nКол: " << list.kol << "\nИтог: " << list.general << "\n";
            price += list.general;
            file << "-----------------------------------\n";
        }
        file << "К оплате: " << price << "\n";
        if(discounts){
            double totalAm=price*0.9;
            //чтобы 2 знака после запятой
            QString str=QString::number(totalAm,'f', 2);
            file <<  "С учетом скидки: "<<str.toDouble()<<"\n";
        }
        file.close();
    }
    //Размер корзины
    int sizes(){
        int i=0;
        for (auto& list : besketList) {
            i++;
        }
        return i;
    }

};

basket baskets;

void ErrorOrNo(int meaning){
    if(meaning<0){
        cout<<"Error\n";
        exit(0);
    }
}

QString TotalAmount(bool discounts){
    string mes=baskets.print();
    istringstream iss(mes);
    string line;
    string totalAm;
    while (getline(iss, line)) {
        if (line.find("К оплате:") != string::npos) {
            totalAm = line.substr(line.find(":") + 2);
        }
    }
    double number;
    stringstream str;
    str<<totalAm;
    str>>number;
    if(discounts){
        number=number*0.9;
    }
    return QString::number(number,'f', 2);
}

void makingFile(const string& filename, bool discounts){
    baskets.createTextFile(filename, discounts);
}

bool DelBas(string number){
    bool check =baskets.Delete(number);
    return check;
}

void ReKol(string number, double kol){
    baskets.ChangeQuantity(number, kol);
}

string finds(string number){
    string result = baskets.FindCode(number);
    return result;
}

bool emptyBasketss(){
    if(baskets.sizes()==0){
        return false;
    }
    return true;
}

void parseAndAdd(string mes) {
    istringstream iss(mes);
    string line;
    string idProd;
    string name;
    string type;
    string value_str;
    double value = 0.0; // Инициализируем значение по умолчанию
    double kol = 1.0; // По умолчанию количество 1
    bool hasIdProd = false;
    bool hasName = false;
    bool hasType = false;
    bool hasValue = false;

    while (getline(iss, line)) {
        if (line.find("Код:") != string::npos) {
            idProd = line.substr(line.find(":") + 2);
            hasIdProd = !idProd.empty(); // Проверяем, не пустая ли строка
        } else if (line.find("Название:") != string::npos) {
            name = line.substr(line.find(":") + 2);
            hasName = !name.empty(); // Проверяем, не пустая ли строка
        } else if (line.find("Цена:") != string::npos) {
            value_str = line.substr(line.find(":") + 2);
            // Удаление лишних символов из строки
            value_str.erase(remove_if(value_str.begin(), value_str.end(), ::isspace), value_str.end());
            // Преобразование строки в число с плавающей точкой с использованием std::istringstream
            std::istringstream iss2(value_str);
            if (iss2 >> value) {
                hasValue = true; // Устанавливаем флаг, если значение успешно преобразовано
            }
        } else if (line.find("Описание:") != string::npos) {
            type = line.substr(line.find(":") + 2);
            hasType = !type.empty(); // Проверяем, не пустая ли строка
        }
    }

    // Проверяем, что все необходимые поля заполнены
    if (hasIdProd && hasName && hasType && hasValue) {
        baskets.Add(idProd, name, type, value, kol);
    } else {
        // Обработка случая, когда данные неполные
        cerr << "Неполные данные. Продукт не добавлен в корзину." << endl;
    }
}


//Проверка верного ввода
bool CheckNumber(string check){
    for (size_t i=0; i<check.length();i++){
        if(check[i]<'0'||check[i]>'9'){
            return false;
        }
    }
    return true;
}

//Для кода
void Product::on_pushButton_clicked()
{
    int number = 1;
    QString text = ui->lineEdit->text();
    string check = text.toStdString();
    bool onlyNum= CheckNumber(check);
    if(onlyNum && check.length()>0){
        string meseg = Connect->sendMessage(number, text);
        if(meseg != "Ничего не найдено\n"){
            parseAndAdd(meseg);
        }
        ui->textBrowser->setText(QString::fromStdString(meseg));
    }else{
        ui->textBrowser->setText(QString::fromStdString("Ничего не найдено"));
    }
}

//для штрихкода
void Product::on_pushButton_4_clicked()
{
    int number = 2;
    QString text = ui->lineEdit->text();
    string check = text.toStdString();
    bool onlyNum= CheckNumber(check);
    if(onlyNum && check.length()>0){
        string meseg = Connect->sendMessage(number, text);
        if(meseg != "Ничего не найдено\n"){
            parseAndAdd(meseg);
        }
        ui->textBrowser->setText(QString::fromStdString(meseg));
    }else{
        ui->textBrowser->setText(QString::fromStdString("Ничего не найдено"));
    }
}
bool checkingInjections(const string& str) {
    //преобразования между UTF-8 и широкими символами
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    wstring wideStr = converter.from_bytes(str);

    for (wchar_t ch : wideStr) {
        if (!((ch >= L'0' && ch <= L'9') || // Числа
              (ch >= L'а' && ch <= L'я') || (ch >= L'А' && ch <= L'Я') || // Русские буквы
              ch == L' ')) { // Допустимые символы
            return false;
        }
    }
    return true;
}

//каталог
void Product::on_pushButton_2_clicked()
{
    catalog window(Connect);
    window.setModal(true);
    window.exec();
}


//название
void Product::on_pushButton_3_clicked()
{
    int number = 4;
    QString text = ui->lineEdit->text();

    if(text.length()<50&& text.length()>0 && checkingInjections(text.toStdString())){
    string meseg = Connect->sendMessage(number, text);
    ui->textBrowser->setText(QString::fromStdString(meseg));
    }else{
        ui->textBrowser->setText(QString::fromStdString("Ничего не найдено"));
    }
}


void Product::on_pushButton_5_clicked()
{
    string mes=baskets.print();
    ui->textBrowser->setText(QString::fromStdString(mes));
}


void Product::on_pushButton_7_clicked()
{
    Basketss windows;
    windows.setModal(true);
    windows.exec();
    this->on_pushButton_5_clicked();
}


void Product::on_pushButton_6_clicked()
{
    bool check = emptyBasketss();
    if(check){
        close();
        Maps windows(Connect);
        windows.setModal(true);
        windows.exec();
    }else{
        QMessageBox::warning(this, "Корзина","Корзина пуста");
    }

}


void Product::on_pushButton_8_clicked()
{
    kol windows;
    windows.setModal(true);
    windows.exec();
    this->on_pushButton_5_clicked();
}

