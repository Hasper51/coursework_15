#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
//#include <string>
//#include <ctime>
//#include <conio.h>
//#include <cstdio>

using namespace std;
struct{ //инфо о кол-во данных
    int goods_amount, //кол-во товаров
    staff_amount, //кол-во сотрудников
    orders_amount, //кол-во заказов
    orders_ready_amount; //кол-во исполнения заказов
} Amount;
struct Goods{ //структура с товарами
    string goods_code; //код товара
    string goods_name; //название товара
    string goods_firm; //название фирмы-производителя
    string goods_model; //название модели
    string goods_guarantee; //наличие гарантии
}goods[50];
struct Staff{ //структура с сотрудниками
    string staff_surname; //фамилия сотрудника
    string staff_name; //имя сотрудника
    string staff_position; //должность сотрудника
}staff[50];
struct Orders{ //структура с заказами
    string order_code; //код заказа
    string goods_code; //код товара
    string client_name; //ФИО клиета
    string goods_guarantee; //налиние гарантии у клиента
    string order_date; //дата заказа
    string client_tel; //телефон клиента

}orders[50];
struct OrdersReady{ //структура с исполнением заказов
    string order_code; //код заказа
    string repair_cost; //стоимось ремонта
    string repair_date; //дата ремонта
    string staff_surname; //фамилия исполнителя(сотрудника)
    string staff_name; //имя исполнителя(сотрудника)
    string staff_position; //должность исполнителя(сотрудника)
}ordersready[50];
struct Goods goods2[50];
struct Staff staff2[50];
struct Orders orders2[50];
struct OrdersReady ordersready2[50];
int state_menu;
int state_menu_search;
int state_menu_input;
int state_menu_output;

void InputFiles(){ //Ввод данных из файлов
    ifstream reading_goods("goods.txt");
    ifstream reading_staff("staff.txt");
    ifstream reading_orders("orders.txt");
    ifstream reading_orders_ready("ready_orders.txt");
    if(reading_staff){
        reading_staff>>Amount.staff_amount;
        int i = 0;
        while (!reading_staff.eof()){
            reading_staff>>staff[i].staff_surname
            >>staff[i].staff_name;
            string ss;
            getline(reading_staff,ss,';');
            ss.erase(0,1);
            staff[i].staff_position=ss;
            i++;
        }
    }
    if(reading_goods){
        reading_goods>>Amount.goods_amount;
        int i = 0;
        while (!reading_goods.eof())
        {
            reading_goods>>goods[i].goods_code;
            string ss;
            getline(reading_goods,ss,';');
            ss.erase(0,1);
            goods[i].goods_name=ss;
            getline(reading_goods,goods[i].goods_firm,';');
            getline(reading_goods,goods[i].goods_model,';');
            reading_goods>>goods[i].goods_guarantee;
            i++;
        }
    }

    if(reading_orders){
        reading_orders>>Amount.orders_amount;
        int i = 0;
        while (!reading_orders.eof())
        {
            reading_orders>>orders[i].order_code;
            string ss;
            getline(reading_orders,ss,';');
            ss.erase(0,1);
            orders[i].client_name=ss;
            getline(reading_orders,orders[i].goods_code,';');
            getline(reading_orders,orders[i].goods_guarantee,';');
            getline(reading_orders,orders[i].order_date,';');
            getline(reading_orders,orders[i].client_tel,';');
            i++;
        }
    }

    if(reading_orders_ready){
        reading_orders_ready>>Amount.orders_ready_amount;
        int i = 0;
        while (!reading_orders_ready.eof())
        {
            reading_orders_ready>>ordersready[i].order_code;
            string ss;
            getline(reading_orders_ready,ss,';');
            ss.erase(0,1);
            ordersready[i].staff_surname=ss;
            getline(reading_orders_ready,ordersready[i].staff_name,';');
            getline(reading_orders_ready,ordersready[i].staff_position,';');
            getline(reading_orders_ready,ordersready[i].repair_cost,';');
            getline(reading_orders_ready,ordersready[i].repair_date,';');

            i++;
        }
    }
}

void Menu(){ //основное меню
    cout<<"Выберите действие: "<<endl
        <<"(0) Выход"<<endl
        <<"(1) Работа с заказами"<<endl
        <<"(2) Вывод данных"<<endl
        <<"(3) Поиск"<<endl
        <<"(4) Сотрудники"<<endl
        <<"\nВаш выбор: ";
    cin>>state_menu;
    cout<<"\n";
}
void MenuOutput(){ //меню для вывода данных
    cout<<endl;
    cout<<"Выберите действие: "<<endl
        <<"(0) Назад"<<endl
        <<"(1) Вывод товаров"<<endl
        <<"(2) Вывод сотрудников"<<endl
        <<"(3) Вывод заказов"<<endl
        <<"(4) Вывод исполнения заказов"<<endl
        <<"\nВаш выбор: ";
    cin>>state_menu_output;
    cout<<"\n";
}
void MenuInput(){ //меню для ввода данных
    cout<<endl;
    cout<<"Выберите действие: "<<endl
        <<"(0) Назад"<<endl
        <<"(1) Ввод заказов"<<endl
        <<"(2) Ввод исполнения заказов"<<endl
        <<"\nВаш выбор: ";
    cin>>state_menu_input;
    cout<<"\n";
}
void MenuSearch(){ //меню для поиска инфо
    cout<<endl;
    cout<<"Выберите действие: "<<endl
        <<"(0) Назад"<<endl
        <<"(1) Поиск по товарам"<<endl
        <<"(2) Поиск по сотрудникам"<<endl
        <<"(3) Поиск по заказам"<<endl
        <<"(4) Поиск по исполнением заказов"<<endl
        <<"\nВаш выбор: ";
    cin>>state_menu_search;
    cout<<"\n";
}

void OutputGoods(){ //вывод товаров

    cout<<setw(16)<<left<<"Код товара"<<setw(24)<<left<<"Название"<<setw(20)<<left<<"Фирма"<<setw(20)<<left<<"Модель"<<setw(20)<<left<<"Гарантия"<<endl;
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<Amount.goods_amount;i++){
        cout<<setw(15)<<left<<goods[i].goods_code<<setw(25)<<left
        <<goods[i].goods_name<<setw(20)<<left
        <<goods[i].goods_firm<<setw(20)<<left
        <<goods[i].goods_model<<setw(20)<<left
        <<goods[i].goods_guarantee<<endl;
    }
    cout<<"\n";
}
void OutputSortedGoods(){ //вывод отсортированных товаров
    cout<<setw(16)<<left<<"Код товара"<<setw(24)<<left<<"Название"<<setw(20)<<left<<"Фирма"<<setw(20)<<left<<"Модель"<<setw(20)<<left<<"Гарантия"<<endl;
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<Amount.goods_amount;i++){
        cout<<setw(15)<<left<<goods2[i].goods_code<<setw(25)<<left
        <<goods2[i].goods_name<<setw(20)<<left
        <<goods2[i].goods_firm<<setw(20)<<left
        <<goods2[i].goods_model<<setw(20)<<left
        <<goods2[i].goods_guarantee<<endl;
    }
    cout<<"\n";
}
void SortGoods(){ //сортировка товаров
    int state_menu_sort;
    do{
        cout<<"(0) Назад"<<endl
        <<"(1) Сортировка по коду товара"<<endl
        <<"(2) Сортировка по названию товара"<<endl
        <<"(3) Сортировка по фирме-производителя товара"<<endl;
        cout<<"Ваш выбор: ";
        cin>>state_menu_sort;
        cout<<endl;
        for(int i = 0;i<Amount.goods_amount;i++)
            goods2[i]=goods[i];
        switch(state_menu_sort){
        case 1:

            for(int i = 0; i < Amount.goods_amount - 1; ++i)
            {
                for(int j = 0; j < Amount.goods_amount - 1; ++j)
                {
                    if (goods2[j + 1].goods_code < goods2[j].goods_code)
                    {
                        swap(goods2[j+1],goods2[j]);
                    }
                }
            }
            OutputSortedGoods();
            break;
        case 2:

            for(int i = 0; i < Amount.goods_amount - 1; ++i)
            {
                for(int j = 0; j < Amount.goods_amount - 1; ++j)
                {
                    if (goods2[j + 1].goods_name < goods2[j].goods_name)
                    {
                        swap(goods2[j+1],goods2[j]);
                    }
                }
            }
            OutputSortedGoods();
            break;
        case 3:

            for(int i = 0; i < Amount.goods_amount - 1; ++i)
            {
                for(int j = 0; j < Amount.goods_amount - 1; ++j)
                {
                    if (goods2[j + 1].goods_firm < goods2[j].goods_firm)
                    {
                        swap(goods2[j+1],goods2[j]);
                    }
                }
            }
            OutputSortedGoods();
            break;
        }
    }while(state_menu_sort!=0);
}

void OutputStaff(){ //вывод сотрудников
    cout<<"№\t"<<setw(25)<<left<<"ФИО"<<"Должность"<<endl;
    cout<<"-------------------------------------------"<<endl;
    for (int i=0; i<Amount.staff_amount; i++){
            cout<<i+1<<"\t"
            <<staff[i].staff_surname<<" "<<setw(10)<<left
            <<staff[i].staff_name<<"\t"
            <<staff[i].staff_position<<endl;
    }
    cout<<"\n";
}
void OutputSortedStaff(){ //вывод отсортированных сотрудников
    cout<<setw(25)<<left<<"ФИО"<<"Должность"<<endl;
    cout<<"-------------------------------------------"<<endl;
    for (int i=0; i<Amount.staff_amount; i++){
            cout<<staff2[i].staff_surname<<" "<<setw(10)<<left
            <<staff2[i].staff_name<<"\t"
            <<staff2[i].staff_position<<endl;
    }
    cout<<"\n";
}
void SortStaff(){ //сортировка сотрудников
    int state_menu_sort;
    do
    {
        cout << "(0) Назад" << endl
             << "(1) Сортировка по фамилии" << endl
             << "(2) Сортировка по должности" << endl;
        cout << "Ваш выбор: ";
        cin >> state_menu_sort;
        cout << endl;
        for (int i = 0; i < Amount.staff_amount; i++)
            staff2[i] = staff[i];
        switch (state_menu_sort)
        {
        case 1:
            for (int i = 0; i < Amount.staff_amount - 1; ++i)
            {
                for (int j = 0; j < Amount.staff_amount - 1; ++j)
                {
                    if (staff2[j + 1].staff_surname < staff2[j].staff_surname)
                        swap(staff2[j + 1], staff2[j]);
                }
            }
            OutputSortedStaff();
            break;
        case 2:
            for (int i = 0; i < Amount.staff_amount - 1; ++i)
            {
                for (int j = 0; j < Amount.staff_amount - 1; ++j)
                {
                    if (staff2[j + 1].staff_position < staff2[j].staff_position)
                        swap(staff2[j + 1], staff2[j]);
                }
            }
            OutputSortedStaff();
            break;
        }
    } while (state_menu_sort != 0);
}

void OutputOrders(){ //вывод заказов
    cout<<setw(16)<<left<<"Код заказа"<<setw(20)<<left<<"ФИО Клиента"<<setw(15)<<left<<"Код товара"<<setw(15)<<left<<"Гарантия"<<setw(30)<<left<<"Дата поступления заказа"<<"Телефон клиента"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;

    for(int i=0;i<Amount.orders_amount;i++){
        cout<<orders[i].order_code<<"\t\t"<<setw(20)<<left
        <<orders[i].client_name<<setw(15)<<left
        <<orders[i].goods_code<<setw(15)<<left
        <<orders[i].goods_guarantee<<setw(30)<<left
        <<currentDateTime(orders[i].order_date)
        <<orders[i].client_tel<<endl;
    }
    cout<<"\n";

}
void OutputSortedOrders(){ //вывод отсортированных заказов
    cout<<setw(16)<<left<<"Код заказа"<<setw(20)<<left<<"ФИО Клиента"<<setw(15)<<left<<"Код товара"<<setw(15)<<left<<"Гарантия"<<setw(30)<<left<<"Дата поступления заказа"<<"Телефон клиента"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;

    for(int i=0;i<Amount.orders_amount;i++){
        cout<<orders2[i].order_code<<"\t\t"<<setw(20)<<left
        <<orders2[i].client_name<<setw(15)<<left
        <<orders2[i].goods_code<<setw(15)<<left
        <<orders2[i].goods_guarantee<<setw(30)<<left
        <<currentDateTime(orders2[i].order_date)
        <<orders2[i].client_tel<<endl;
    }
    cout<<"\n";
}
void SortOrders(){ //сортировка заказов
    int state_menu_sort;
    do{
        cout<<"(0) Назад"<<endl
        <<"(1) Сортировка по коду заказа"<<endl
        <<"(2) Сортировка по фамилии клиента"<<endl
        <<"(3) Сортировка по дате"<<endl;
        cout<<"Ваш выбор: ";
        cin>>state_menu_sort;
        cout<<endl;
        for(int i = 0;i<Amount.orders_amount;i++)
            orders2[i]=orders[i];
        switch(state_menu_sort){
        case 1:

            for(int i = 0; i < Amount.orders_amount - 1; ++i)
            {
                for(int j = 0; j < Amount.orders_amount - 1; ++j)
                {
                    if (orders2[j + 1].order_code < orders2[j].order_code)
                    {
                        swap(orders2[j+1],orders2[j]);
                    }
                }
            }
            OutputSortedOrders();
            break;
        case 2:

            for(int i = 0; i < Amount.orders_amount - 1; ++i)
            {
                for(int j = 0; j < Amount.orders_amount - 1; ++j)
                {
                    if (orders2[j + 1].client_name < orders2[j].client_name)
                    {
                        swap(orders2[j+1],orders2[j]);
                    }
                }
            }
            OutputSortedOrders();
            break;
        case 3:

            for(int i = 0; i < Amount.orders_amount - 1; ++i)
            {
                for(int j = 0; j < Amount.orders_amount - 1; ++j)
                {
                    if (orders2[j + 1].order_date > orders2[j].order_date)
                    {
                        swap(orders2[j+1],orders2[j]);
                    }
                }
            }
            OutputSortedOrders();
            break;
        }
    }while(state_menu_sort!=0);
}

void OutputOrdersReady(){ //вывод исполнения заказов
    cout<<"№"<<"\t"<<setw(16)<<left<<"Код заказа"<<setw(20)<<left<<"Исполнитель"<<setw(30)<<left<<"Должность исполнителя"<<setw(25)<<left<<"Стоимость ремонта"<<setw(25)<<left<<"Дата исполнения заказа"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------------"<<endl;

    for(int i=0;i<Amount.orders_ready_amount;i++){
        cout<<i+1<<"\t"
        <<ordersready[i].order_code<<"\t\t"<<setw(7)<<left
        <<ordersready[i].staff_surname<<" "<<setw(12)<<left
        <<ordersready[i].staff_name<<setw(30)<<left
        <<ordersready[i].staff_position<<setw(5)<<left
        <<ordersready[i].repair_cost<<setw(20)<<left<<"руб."
        <<currentDateTime(ordersready[i].repair_date)<<endl;
    }
    cout<<"\n";

}
void OutputSortedOrdersReady(){ //вывод отсортированных
    cout<<"№"<<"\t"<<setw(16)<<left<<"Код заказа"<<setw(20)<<left<<"Исполнитель"<<setw(30)<<left<<"Должность исполнителя"<<setw(25)<<left<<"Стоимость ремонта"<<setw(25)<<left<<"Дата исполнения заказа"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------"<<endl;

    for(int i=0;i<Amount.orders_ready_amount;i++){
        cout<<i+1<<"\t"
        <<ordersready2[i].order_code<<"\t\t"<<setw(7)<<left
        <<ordersready2[i].staff_surname<<" "<<setw(12)<<left
        <<ordersready2[i].staff_name<<setw(30)<<left
        <<ordersready2[i].staff_position<<setw(5)<<left
        <<ordersready2[i].repair_cost<<setw(20)<<left<<"руб."
        <<currentDateTime(ordersready2[i].repair_date)<<endl;
    }
    cout<<"\n";
}
void SortOrdersReady(){ //сортировка исполнения заказов
    int state_menu_sort;
    do{
        cout<<"(0) Назад"<<endl
        <<"(1) Сортировка по коду заказа"<<endl
        <<"(2) Сортировка по фамилии исполнителя"<<endl
        <<"(3) Сортировка по дате"<<endl
        <<"(4) Сортировка по цене"<<endl;
        cout<<"Ваш выбор: ";
        cin>>state_menu_sort;
        cout<<endl;
        for(int i = 0;i<Amount.orders_ready_amount;i++)
            ordersready2[i]=ordersready[i];
        switch(state_menu_sort){
        case 1:

            for(int i = 0; i < Amount.orders_ready_amount - 1; ++i)
            {
                for(int j = 0; j < Amount.orders_ready_amount - 1; ++j)
                {
                    if (ordersready2[j + 1].order_code < ordersready2[j].order_code)
                    {
                        swap(ordersready2[j+1],ordersready2[j]);
                    }
                }
            }
            OutputSortedOrdersReady();
            break;
        case 2:

            for(int i = 0; i < Amount.orders_ready_amount - 1; ++i)
            {
                for(int j = 0; j < Amount.orders_ready_amount - 1; ++j)
                {
                    if (ordersready2[j + 1].staff_surname < ordersready2[j].staff_surname)
                    {
                        swap(ordersready2[j+1],ordersready2[j]);
                    }
                }
            }
            OutputSortedOrdersReady();
            break;
        case 3:

            for(int i = 0; i < Amount.orders_ready_amount - 1; ++i)
            {
                for(int j = 0; j < Amount.orders_ready_amount - 1; ++j)
                {
                    if (ordersready2[j + 1].repair_date > ordersready2[j].repair_date)
                    {
                        swap(ordersready2[j+1],ordersready2[j]);
                    }
                }
            }
            OutputSortedOrdersReady();
            break;
        case 4:

            for(int i = 0; i < Amount.orders_ready_amount - 1; ++i)
            {
                for(int j = 0; j < Amount.orders_ready_amount - 1; ++j)
                {
                    if (ordersready2[j + 1].repair_cost < ordersready2[j].repair_cost)
                    {
                        swap(ordersready2[j+1],ordersready2[j]);
                    }
                }
            }
            OutputSortedOrdersReady();
            break;
        }
    }while(state_menu_sort!=0);
}

void DeleteOrders(){ //удаление заказа

    OutputOrders();
    bool del_success = false;
    int del;
    string ORDER_CODE;
    while(del_success == false){
        cout << "Введите код заказа, которую хотите удалить: ";
        cin>>ORDER_CODE;
        for(int i=0;i<Amount.orders_amount;i++){
            if(orders[i].order_code==ORDER_CODE){
                del=i;
                del_success=true;
            }
        }
        if(del_success==false)
            cout<<"Заказа с таким кодом заказа не найден. Повторите попытку еще раз."<<endl;
    }

    ifstream infile("orders.txt");
    ofstream outfile("orders_copy.txt");//создаёт буфер-файл
    char buffer[1000];
    int t = -1;
    int trash;
    infile>>trash;
    trash--;
    outfile<<trash;
    Amount.orders_amount--;
    while(!infile.eof()) // считывает все строки
    {
        if (t == del){
            infile.getline(buffer,sizeof(buffer));//пропускает нужнную строку
            t++;

        }else {

            infile.getline(buffer,sizeof(buffer));
            outfile<<buffer<<endl;//записывает в буфер-файл
            t++;}
    }


    infile.close();
    outfile.close();
    remove("orders.txt");//удаляет старый файл
    rename("orders_copy.txt", "orders.txt");//переименовывает буфер-файл
    InputFiles();
}
void DeleteOrdersReady(){ //удаление исполнения заказа

    OutputOrdersReady();
    cout << "Введите номер строки, которую хотите удалить: ";
    int del;
    cin >> del;

    ifstream infile("ready_orders.txt");
    ofstream outfile("ready_orders_copy.txt");//создаёт буфер-файл
    char buffer[1000];
    int t = -1;
    int trash;
    infile>>trash;
    trash--;
    outfile<<trash;
    Amount.orders_ready_amount--;
    while(!infile.eof()) // считывает все строки
    {
        if (t+1 == del){
            infile.getline(buffer,sizeof(buffer));//пропускает нужнную строку
            t++;

        }else {

            infile.getline(buffer,sizeof(buffer));
            outfile<<buffer<<endl;//записывает в буфер-файл
            t++;}
    }
    infile.close();
    outfile.close();
    remove("ready_orders.txt");//удаляет старый файл
    rename("ready_orders_copy.txt", "ready_orders.txt");//переименовывает буфер-файл
    InputFiles();
}
void DeleteStaff(){ //удаление сотрудника
    OutputStaff();
    cout << "Введите номер строки, которую хотите удалить: ";
    int del;
    cin >> del;
    ifstream infile("staff.txt");
    ofstream outfile("staff_copy.txt");//создаёт буфер-файл
    char buffer[1000];
    int t = -1;
    int trash;
    infile>>trash;
    trash--;
    outfile<<trash;
    Amount.staff_amount--;
    while(!infile.eof()){ // считывает все строки
        if (t+1 == del){
            infile.getline(buffer,sizeof(buffer));//пропускает нужнную строку
            t++;
        }else {
            infile.getline(buffer,sizeof(buffer));
            outfile<<buffer<<endl;//записывает в буфер-файл
            t++;}
    }
    infile.close();
    outfile.close();
    remove("staff.txt");//удаляет старый файл
    rename("staff_copy.txt", "staff.txt");//переименовывает буфер-файл
    InputFiles();
}

void IncrementStr(string &str){ //увеличение строки на единицу
    for(int i=str.length()-1; i>=0; i--){
        int n=(str[i]==' ')?0:str[i]-48;
        n++;
        if(n<10){
            str[i]=n+48;
            break;
        }
        else str[i]=n%10+48;
    }
}
const string currentDateTime(string time) { //конвертирование даты в читаемый вид
        time_t now = (time_t)atoi(time.c_str());
        struct tm  tstruct;
        char       buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%d-%m-%Y %X", &tstruct);
        return buf;
}
void Search(){ //поиск информации по базе
    MenuSearch();
    while(state_menu_search!=0){
        switch(state_menu_search){
        case 1:{
            int code;
            bool success = false;
            cout<<"Поиск по коду товара (";
            cout<<goods[0].goods_code<<" - "<<goods[Amount.goods_amount-1].goods_code<<")"<<endl;
            cout<<"Введите код товара: "; cin>>code;
            cout<<endl;
            cout<<setw(16)<<left<<"Код товара"<<setw(24)<<left<<"Название"<<setw(20)<<left<<"Фирма"<<setw(20)<<left<<"Модель"<<setw(20)<<left<<"Гарантия"<<endl;
            cout<<"----------------------------------------------------------------------------------------------"<<endl;
            for(int i = 0;i<Amount.goods_amount;i++){
                if(stoi(goods[i].goods_code)==code){
                    cout<<setw(15)<<left<<goods[i].goods_code<<setw(25)<<left
                    <<goods[i].goods_name<<setw(20)<<left
                    <<goods[i].goods_firm<<setw(20)<<left
                    <<goods[i].goods_model<<setw(20)<<left
                    <<goods[i].goods_guarantee<<endl;
                    success = true;
                }
            }
            if (success==false)
                cout<<"Товар не найден"<<endl;
            cout<<endl;
            MenuSearch();
            break;
        }
        case 2:{
            string surname;
            bool success2 = false;
            cout<<"Поиск сотрудника по фамилии"<<endl;

            cout<<"Введите фамилию сотрудника: "; cin>>surname;
            cout<<endl;
            cout<<setw(24)<<left<<"ФИО"<<"Должность"<<endl;
            cout<<"-------------------------------------------"<<endl;
            for(int i = 0;i<Amount.staff_amount;i++){
                if(staff[i].staff_surname==surname){
                    cout
                    <<staff[i].staff_surname<<" "<<setw(10)<<left
                    <<staff[i].staff_name<<"\t"
                    <<staff[i].staff_position<<endl;
                    success2 = true;
                }
            }
            if (success2==false)
                cout<<"Сотрудник не найден"<<endl;
            cout<<endl;
            MenuSearch();
            break;
        }
        case 3:{
            string order_code;
            bool success3 = false;
            cout<<"Поиск по коду заказа в заказах(";
            cout<<orders[0].order_code<<" - "<<orders[Amount.orders_amount-1].order_code<<")"<<endl;
            cout<<"Введите код заказа: "; cin>>order_code;
            cout<<endl;
            cout<<setw(16)<<left<<"Код заказа"<<setw(20)<<left<<"ФИО Клиента"<<setw(15)<<left<<"Код товара"<<setw(15)<<left<<"Гарантия"<<setw(30)<<left<<"Дата поступления заказа"<<"Телефон клиента"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;

            for(int i = 0;i<Amount.orders_amount;i++){
                if(orders[i].order_code==order_code){
                    cout<<orders[i].order_code<<"\t\t"<<setw(20)<<left
                    <<orders[i].client_name<<setw(15)<<left
                    <<orders[i].goods_code<<setw(15)<<left
                    <<orders[i].goods_guarantee<<setw(30)<<left
                    <<currentDateTime(orders[i].order_date)
                    <<orders[i].client_tel<<endl;
                    success3 = true;
                }
            }
            if (success3==false)
                cout<<"Заказ не найден"<<endl;
            cout<<endl;
            MenuSearch();
            break;
        }
        case 4:{
            string order_ready_code;
            bool success4 = false;
            cout<<"Поиск по коду заказа в исполнениях заказов (Например: A101, A102, ...)"<<endl;
            cout<<"Введите код заказа: "; cin>>order_ready_code;
            cout<<endl;
            cout<<setw(16)<<left<<"Код заказа"<<setw(20)<<left<<"Исполнитель"<<setw(30)<<left<<"Должность исполнителя"<<setw(25)<<left<<"Стоимость ремонта"<<setw(25)<<left<<"Дата исполнения заказа"<<endl;
            cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;

            for(int i = 0;i<Amount.orders_ready_amount;i++){
                if(ordersready[i].order_code==order_ready_code){
                    cout<<ordersready[i].order_code<<"\t\t"<<setw(7)<<left
                    <<ordersready[i].staff_surname<<" "<<setw(12)<<left
                    <<ordersready[i].staff_name<<setw(30)<<left
                    <<ordersready[i].staff_position<<setw(5)<<left
                    <<ordersready[i].repair_cost<<setw(20)<<left<<"руб."
                    <<currentDateTime(ordersready[i].repair_date)<<endl;
                    success4 = true;
                }
            }
            if (success4==false)
                cout<<"Заказ не найден"<<endl;
            cout<<endl;
            MenuSearch();
            break;
        }
        default:
            MenuSearch();
            break;


        }
    }

}

void AddOrderReady(){ //добавление исполнения заказов

    string STAFF_SURNAME,STAFF_NAME, REPAIR_COST, ORDER_CODE, GOODS_CODE, GOODS_GUARANTEE;
    cin.ignore();
    cout<<"Номер заказа "<<endl;
    OutputOrders();
    cout<<"Введите номер заказа: ";
    getline(cin, ORDER_CODE);
    cout<<"Ввод исполнителя "<<endl;
    OutputStaff();
    cout<<"Введите фамилию и инициалы (Фамилия И.О.): ";
    cin>>STAFF_SURNAME>>STAFF_NAME;
    ordersready[Amount.orders_ready_amount].staff_surname = STAFF_SURNAME;
    ordersready[Amount.orders_ready_amount].staff_name = STAFF_NAME;
    for(int j = 0;j<Amount.staff_amount;j++){
        if(staff[j].staff_surname==STAFF_SURNAME && staff[j].staff_name==STAFF_NAME){
            ordersready[Amount.orders_ready_amount].staff_position = staff[j].staff_position;
        }
    }

    for(int j=0;j<Amount.orders_amount;j++){
        if(orders[j].order_code==ORDER_CODE){
            GOODS_CODE=orders[j].goods_code;
            for(int h=0;h<Amount.goods_amount;h++){
                if(goods[h].goods_code==GOODS_CODE){
                    GOODS_GUARANTEE=goods[h].goods_guarantee;
                }
            }
            if(orders[j].goods_guarantee=="нет"){
                cout<<"Цена: "; getline(cin, REPAIR_COST);
                ordersready[Amount.orders_ready_amount].repair_cost = REPAIR_COST;
            }else if(orders[j].goods_guarantee=="да" && GOODS_GUARANTEE=="да"){
                ordersready[Amount.orders_ready_amount].repair_cost = "0";
            }
            else if(orders[j].goods_guarantee=="да" && GOODS_GUARANTEE=="нет"){
                cout<<"Цена: "; getline(cin, REPAIR_COST);
                ordersready[Amount.orders_ready_amount].repair_cost = REPAIR_COST;
            }
        }
    }
    ordersready[Amount.orders_ready_amount].order_code = ORDER_CODE;
    time_t now = time(0);
    string now2 = to_string(now);
    ordersready[Amount.orders_ready_amount].repair_date = now2;
    Amount.orders_ready_amount++;
    ofstream writting_ordersready("ready_orders.txt");
    writting_ordersready<<Amount.orders_ready_amount<<"\n";
    for(int i=0;i<Amount.orders_ready_amount;i++){
        writting_ordersready<<ordersready[i].order_code<<" "
        <<ordersready[i].staff_surname<<";"
        <<ordersready[i].staff_name<<";"
        <<ordersready[i].staff_position<<";"
        <<ordersready[i].repair_cost<<";"
        <<ordersready[i].repair_date<<";"
        <<"\n";

    }
    InputFiles();
};
void AddGoods(){ //добавление товара
    string GOODS_NAME, GOODS_FIRM, GOODS_MODEL, GOODS_GUARANTEE;
    goods[Amount.goods_amount].goods_code = to_string(stoi(goods[Amount.goods_amount-1].goods_code)+1);
    cin.ignore();
    cout<<"Введите название товара: "; getline(cin, GOODS_NAME);
    cout<<"Введите фирму-производителя товара: "; getline(cin, GOODS_FIRM);
    cout<<"Введите модель товара: "; getline(cin, GOODS_MODEL);
    cout<<"Введите наличие гарантии у товара(да/нет): "; getline(cin, GOODS_GUARANTEE);
    goods[Amount.goods_amount].goods_firm = GOODS_FIRM;
    goods[Amount.goods_amount].goods_name = GOODS_NAME;
    goods[Amount.goods_amount].goods_model = GOODS_MODEL;
    goods[Amount.goods_amount].goods_guarantee = GOODS_GUARANTEE;
    Amount.goods_amount++;
    ofstream writting_goods("goods.txt");
    writting_goods<<Amount.goods_amount<<"\n";
    for(int i=0;i<Amount.goods_amount;i++){
        writting_goods<<goods[i].goods_code<<" "
        <<goods[i].goods_name<<";"
        <<goods[i].goods_firm<<";"
        <<goods[i].goods_model<<";"
        <<goods[i].goods_guarantee
        <<"\n";
    }
}
void AddOrder(){ //добавление заказа

    string CLIENT_NAME, GOODS_GUARANTEE, CLIENT_TEL, AVAILABILITY_GOODS, GOOOS_CODE;
    string str1;
    cin.ignore();
    cout<<"ФИО клиента(Фамилия И.О.): "; getline(cin, CLIENT_NAME);
    str1 = orders[Amount.orders_amount-1].order_code;
    IncrementStr(str1);
    orders[Amount.orders_amount].order_code = str1;
    orders[Amount.orders_amount].client_name = CLIENT_NAME;
    OutputGoods();
    cout<<"Товар есть в базе?(да/нет): "; cin>>AVAILABILITY_GOODS;
    if(AVAILABILITY_GOODS=="да"){
        cout<<"Введите код товара: "; cin>>GOOOS_CODE;
        orders[Amount.orders_amount].goods_code = GOOOS_CODE;
    }
    if(AVAILABILITY_GOODS=="нет"){
        AddGoods();
        orders[Amount.orders_amount].goods_code = goods[Amount.goods_amount-1].goods_code;
    }

    cout<<"Наличие гарантии у клиета(да/нет): "; cin>>GOODS_GUARANTEE;
    cout<<"Телефон клиента: "; cin>>CLIENT_TEL;
    orders[Amount.orders_amount].goods_guarantee = GOODS_GUARANTEE;

    time_t now = time(0);
    string now2 = to_string(now);
    orders[Amount.orders_amount].order_date = now2;
    orders[Amount.orders_amount].client_tel = CLIENT_TEL;
    Amount.orders_amount++;
    ofstream writting_orders("orders.txt");
    writting_orders<<Amount.orders_amount<<"\n";
    for(int i=0;i<Amount.orders_amount;i++){
        writting_orders<<orders[i].order_code<<" "
        <<orders[i].client_name<<";"
        <<orders[i].goods_code<<";"
        <<orders[i].goods_guarantee<<";"
        <<orders[i].order_date<<";"
        <<orders[i].client_tel<<";"
        <<"\n";
    }
    writting_orders.close();
    InputFiles();
};
void AddStaff(){ //добавление сотрудника
    cout<<"Добавление сотрудника"<<endl;
    cout<<"ФИО сотрудника(Фамилия И.О.): ";
    cin>>staff[Amount.staff_amount].staff_surname>>staff[Amount.staff_amount].staff_name;
    cin.ignore();
    cout<<"Должность сотрудника: "; getline(cin, staff[Amount.staff_amount].staff_position);
    Amount.staff_amount++;
    ofstream writting_staff("staff.txt");
    writting_staff<<Amount.staff_amount<<"\n";
    for(int i=0;i<Amount.staff_amount;i++){
        writting_staff<<staff[i].staff_surname<<" "
        <<staff[i].staff_name<<" "
        <<staff[i].staff_position<<";"
        <<"\n";
    }
    writting_staff.close();
    InputFiles();

}

int main(){ //основная функция
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu();
    while(state_menu != 0){
        switch(state_menu){
        case 1:
            InputFiles();
            int state_menu_orders;
            do{
                cout<<"(0) Назад"<<endl
                <<"(1) Добавление"<<endl
                <<"(2) Удаление"<<endl;
                cout<<"Ваш выбор: ";
                cin>>state_menu_orders;
                cout<<endl;
                switch(state_menu_orders){
                case 1:
                    MenuInput();
                    while(state_menu_input !=0){
                        switch(state_menu_input){
                        case 1:
                            AddOrder();
                            MenuInput();
                            break;
                        case 2:
                            AddOrderReady();
                            MenuInput();
                            break;
                        }
                    }

                    break;

                case 2:
                    int state_menu_orders_delete;
                    do{
                        cout<<"(0) Назад"<<endl
                        <<"(1) Удаление заказов"<<endl
                        <<"(2) Удаление исполнения заказов"<<endl;
                        cout<<"Ваш выбор: ";
                        cin>>state_menu_orders_delete;
                        cout<<endl;
                        switch(state_menu_orders_delete){
                        case 1:
                            DeleteOrders();
                            break;
                        case 2:
                            DeleteOrdersReady();
                            break;
                        }
                    }while(state_menu_orders_delete!=0);

                }

            } while(state_menu_orders!=0);

            Menu();
            break;


        case 2:
            InputFiles();
            MenuOutput();
            while(state_menu_output != 0){
                switch(state_menu_output){
                case 1:
                    SortGoods();
                    MenuOutput();
                    break;
                case 2:
                    SortStaff();
                    MenuOutput();
                    break;
                case 3:
                    SortOrders();
                    MenuOutput();
                    break;
                case 4:
                    SortOrdersReady();
                    MenuOutput();
                    break;
                default:
                    MenuOutput();
                    break;
                }
            }

            Menu();
            break;

        case 3:
            InputFiles();
            Search();

            Menu();
            break;
        case 4:
            InputFiles();
            int state_menu_staff;
            do{
                cout<<"(0) Назад"<<endl
                <<"(1) Добавление сотрудников"<<endl
                <<"(2) Удаление сотрудников"<<endl;
                cout<<"Ваш выбор: ";
                cin>>state_menu_staff;
                cout<<endl;
                switch(state_menu_staff){
                case 1:
                    AddStaff();
                    break;
                case 2:
                    DeleteStaff();
                    break;
                }
            }while(state_menu_staff!=0);
            Menu();
            break;
        default:
            Menu();
            break;
        }
    }
}
