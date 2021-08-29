#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
//#include <string>
//#include <ctime>
//#include <conio.h>
//#include <cstdio>

using namespace std;
struct{ //���� � ���-�� ������
    int goods_amount, //���-�� �������
    staff_amount, //���-�� �����������
    orders_amount, //���-�� �������
    orders_ready_amount; //���-�� ���������� �������
} Amount;
struct Goods{ //��������� � ��������
    string goods_code; //��� ������
    string goods_name; //�������� ������
    string goods_firm; //�������� �����-�������������
    string goods_model; //�������� ������
    string goods_guarantee; //������� ��������
}goods[50];
struct Staff{ //��������� � ������������
    string staff_surname; //������� ����������
    string staff_name; //��� ����������
    string staff_position; //��������� ����������
}staff[50];
struct Orders{ //��������� � ��������
    string order_code; //��� ������
    string goods_code; //��� ������
    string client_name; //��� ������
    string goods_guarantee; //������� �������� � �������
    string order_date; //���� ������
    string client_tel; //������� �������

}orders[50];
struct OrdersReady{ //��������� � ����������� �������
    string order_code; //��� ������
    string repair_cost; //�������� �������
    string repair_date; //���� �������
    string staff_surname; //������� �����������(����������)
    string staff_name; //��� �����������(����������)
    string staff_position; //��������� �����������(����������)
}ordersready[50];
struct Goods goods2[50];
struct Staff staff2[50];
struct Orders orders2[50];
struct OrdersReady ordersready2[50];
int state_menu;
int state_menu_search;
int state_menu_input;
int state_menu_output;

void InputFiles(){ //���� ������ �� ������
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

void Menu(){ //�������� ����
    cout<<"�������� ��������: "<<endl
        <<"(0) �����"<<endl
        <<"(1) ������ � ��������"<<endl
        <<"(2) ����� ������"<<endl
        <<"(3) �����"<<endl
        <<"(4) ����������"<<endl
        <<"\n��� �����: ";
    cin>>state_menu;
    cout<<"\n";
}
void MenuOutput(){ //���� ��� ������ ������
    cout<<endl;
    cout<<"�������� ��������: "<<endl
        <<"(0) �����"<<endl
        <<"(1) ����� �������"<<endl
        <<"(2) ����� �����������"<<endl
        <<"(3) ����� �������"<<endl
        <<"(4) ����� ���������� �������"<<endl
        <<"\n��� �����: ";
    cin>>state_menu_output;
    cout<<"\n";
}
void MenuInput(){ //���� ��� ����� ������
    cout<<endl;
    cout<<"�������� ��������: "<<endl
        <<"(0) �����"<<endl
        <<"(1) ���� �������"<<endl
        <<"(2) ���� ���������� �������"<<endl
        <<"\n��� �����: ";
    cin>>state_menu_input;
    cout<<"\n";
}
void MenuSearch(){ //���� ��� ������ ����
    cout<<endl;
    cout<<"�������� ��������: "<<endl
        <<"(0) �����"<<endl
        <<"(1) ����� �� �������"<<endl
        <<"(2) ����� �� �����������"<<endl
        <<"(3) ����� �� �������"<<endl
        <<"(4) ����� �� ����������� �������"<<endl
        <<"\n��� �����: ";
    cin>>state_menu_search;
    cout<<"\n";
}

void OutputGoods(){ //����� �������

    cout<<setw(16)<<left<<"��� ������"<<setw(24)<<left<<"��������"<<setw(20)<<left<<"�����"<<setw(20)<<left<<"������"<<setw(20)<<left<<"��������"<<endl;
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
void OutputSortedGoods(){ //����� ��������������� �������
    cout<<setw(16)<<left<<"��� ������"<<setw(24)<<left<<"��������"<<setw(20)<<left<<"�����"<<setw(20)<<left<<"������"<<setw(20)<<left<<"��������"<<endl;
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
void SortGoods(){ //���������� �������
    int state_menu_sort;
    do{
        cout<<"(0) �����"<<endl
        <<"(1) ���������� �� ���� ������"<<endl
        <<"(2) ���������� �� �������� ������"<<endl
        <<"(3) ���������� �� �����-������������� ������"<<endl;
        cout<<"��� �����: ";
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

void OutputStaff(){ //����� �����������
    cout<<"�\t"<<setw(25)<<left<<"���"<<"���������"<<endl;
    cout<<"-------------------------------------------"<<endl;
    for (int i=0; i<Amount.staff_amount; i++){
            cout<<i+1<<"\t"
            <<staff[i].staff_surname<<" "<<setw(10)<<left
            <<staff[i].staff_name<<"\t"
            <<staff[i].staff_position<<endl;
    }
    cout<<"\n";
}
void OutputSortedStaff(){ //����� ��������������� �����������
    cout<<setw(25)<<left<<"���"<<"���������"<<endl;
    cout<<"-------------------------------------------"<<endl;
    for (int i=0; i<Amount.staff_amount; i++){
            cout<<staff2[i].staff_surname<<" "<<setw(10)<<left
            <<staff2[i].staff_name<<"\t"
            <<staff2[i].staff_position<<endl;
    }
    cout<<"\n";
}
void SortStaff(){ //���������� �����������
    int state_menu_sort;
    do
    {
        cout << "(0) �����" << endl
             << "(1) ���������� �� �������" << endl
             << "(2) ���������� �� ���������" << endl;
        cout << "��� �����: ";
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

void OutputOrders(){ //����� �������
    cout<<setw(16)<<left<<"��� ������"<<setw(20)<<left<<"��� �������"<<setw(15)<<left<<"��� ������"<<setw(15)<<left<<"��������"<<setw(30)<<left<<"���� ����������� ������"<<"������� �������"<<endl;
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
void OutputSortedOrders(){ //����� ��������������� �������
    cout<<setw(16)<<left<<"��� ������"<<setw(20)<<left<<"��� �������"<<setw(15)<<left<<"��� ������"<<setw(15)<<left<<"��������"<<setw(30)<<left<<"���� ����������� ������"<<"������� �������"<<endl;
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
void SortOrders(){ //���������� �������
    int state_menu_sort;
    do{
        cout<<"(0) �����"<<endl
        <<"(1) ���������� �� ���� ������"<<endl
        <<"(2) ���������� �� ������� �������"<<endl
        <<"(3) ���������� �� ����"<<endl;
        cout<<"��� �����: ";
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

void OutputOrdersReady(){ //����� ���������� �������
    cout<<"�"<<"\t"<<setw(16)<<left<<"��� ������"<<setw(20)<<left<<"�����������"<<setw(30)<<left<<"��������� �����������"<<setw(25)<<left<<"��������� �������"<<setw(25)<<left<<"���� ���������� ������"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------------"<<endl;

    for(int i=0;i<Amount.orders_ready_amount;i++){
        cout<<i+1<<"\t"
        <<ordersready[i].order_code<<"\t\t"<<setw(7)<<left
        <<ordersready[i].staff_surname<<" "<<setw(12)<<left
        <<ordersready[i].staff_name<<setw(30)<<left
        <<ordersready[i].staff_position<<setw(5)<<left
        <<ordersready[i].repair_cost<<setw(20)<<left<<"���."
        <<currentDateTime(ordersready[i].repair_date)<<endl;
    }
    cout<<"\n";

}
void OutputSortedOrdersReady(){ //����� ���������������
    cout<<"�"<<"\t"<<setw(16)<<left<<"��� ������"<<setw(20)<<left<<"�����������"<<setw(30)<<left<<"��������� �����������"<<setw(25)<<left<<"��������� �������"<<setw(25)<<left<<"���� ���������� ������"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------"<<endl;

    for(int i=0;i<Amount.orders_ready_amount;i++){
        cout<<i+1<<"\t"
        <<ordersready2[i].order_code<<"\t\t"<<setw(7)<<left
        <<ordersready2[i].staff_surname<<" "<<setw(12)<<left
        <<ordersready2[i].staff_name<<setw(30)<<left
        <<ordersready2[i].staff_position<<setw(5)<<left
        <<ordersready2[i].repair_cost<<setw(20)<<left<<"���."
        <<currentDateTime(ordersready2[i].repair_date)<<endl;
    }
    cout<<"\n";
}
void SortOrdersReady(){ //���������� ���������� �������
    int state_menu_sort;
    do{
        cout<<"(0) �����"<<endl
        <<"(1) ���������� �� ���� ������"<<endl
        <<"(2) ���������� �� ������� �����������"<<endl
        <<"(3) ���������� �� ����"<<endl
        <<"(4) ���������� �� ����"<<endl;
        cout<<"��� �����: ";
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

void DeleteOrders(){ //�������� ������

    OutputOrders();
    bool del_success = false;
    int del;
    string ORDER_CODE;
    while(del_success == false){
        cout << "������� ��� ������, ������� ������ �������: ";
        cin>>ORDER_CODE;
        for(int i=0;i<Amount.orders_amount;i++){
            if(orders[i].order_code==ORDER_CODE){
                del=i;
                del_success=true;
            }
        }
        if(del_success==false)
            cout<<"������ � ����� ����� ������ �� ������. ��������� ������� ��� ���."<<endl;
    }

    ifstream infile("orders.txt");
    ofstream outfile("orders_copy.txt");//������ �����-����
    char buffer[1000];
    int t = -1;
    int trash;
    infile>>trash;
    trash--;
    outfile<<trash;
    Amount.orders_amount--;
    while(!infile.eof()) // ��������� ��� ������
    {
        if (t == del){
            infile.getline(buffer,sizeof(buffer));//���������� ������� ������
            t++;

        }else {

            infile.getline(buffer,sizeof(buffer));
            outfile<<buffer<<endl;//���������� � �����-����
            t++;}
    }


    infile.close();
    outfile.close();
    remove("orders.txt");//������� ������ ����
    rename("orders_copy.txt", "orders.txt");//��������������� �����-����
    InputFiles();
}
void DeleteOrdersReady(){ //�������� ���������� ������

    OutputOrdersReady();
    cout << "������� ����� ������, ������� ������ �������: ";
    int del;
    cin >> del;

    ifstream infile("ready_orders.txt");
    ofstream outfile("ready_orders_copy.txt");//������ �����-����
    char buffer[1000];
    int t = -1;
    int trash;
    infile>>trash;
    trash--;
    outfile<<trash;
    Amount.orders_ready_amount--;
    while(!infile.eof()) // ��������� ��� ������
    {
        if (t+1 == del){
            infile.getline(buffer,sizeof(buffer));//���������� ������� ������
            t++;

        }else {

            infile.getline(buffer,sizeof(buffer));
            outfile<<buffer<<endl;//���������� � �����-����
            t++;}
    }
    infile.close();
    outfile.close();
    remove("ready_orders.txt");//������� ������ ����
    rename("ready_orders_copy.txt", "ready_orders.txt");//��������������� �����-����
    InputFiles();
}
void DeleteStaff(){ //�������� ����������
    OutputStaff();
    cout << "������� ����� ������, ������� ������ �������: ";
    int del;
    cin >> del;
    ifstream infile("staff.txt");
    ofstream outfile("staff_copy.txt");//������ �����-����
    char buffer[1000];
    int t = -1;
    int trash;
    infile>>trash;
    trash--;
    outfile<<trash;
    Amount.staff_amount--;
    while(!infile.eof()){ // ��������� ��� ������
        if (t+1 == del){
            infile.getline(buffer,sizeof(buffer));//���������� ������� ������
            t++;
        }else {
            infile.getline(buffer,sizeof(buffer));
            outfile<<buffer<<endl;//���������� � �����-����
            t++;}
    }
    infile.close();
    outfile.close();
    remove("staff.txt");//������� ������ ����
    rename("staff_copy.txt", "staff.txt");//��������������� �����-����
    InputFiles();
}

void IncrementStr(string &str){ //���������� ������ �� �������
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
const string currentDateTime(string time) { //��������������� ���� � �������� ���
        time_t now = (time_t)atoi(time.c_str());
        struct tm  tstruct;
        char       buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%d-%m-%Y %X", &tstruct);
        return buf;
}
void Search(){ //����� ���������� �� ����
    MenuSearch();
    while(state_menu_search!=0){
        switch(state_menu_search){
        case 1:{
            int code;
            bool success = false;
            cout<<"����� �� ���� ������ (";
            cout<<goods[0].goods_code<<" - "<<goods[Amount.goods_amount-1].goods_code<<")"<<endl;
            cout<<"������� ��� ������: "; cin>>code;
            cout<<endl;
            cout<<setw(16)<<left<<"��� ������"<<setw(24)<<left<<"��������"<<setw(20)<<left<<"�����"<<setw(20)<<left<<"������"<<setw(20)<<left<<"��������"<<endl;
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
                cout<<"����� �� ������"<<endl;
            cout<<endl;
            MenuSearch();
            break;
        }
        case 2:{
            string surname;
            bool success2 = false;
            cout<<"����� ���������� �� �������"<<endl;

            cout<<"������� ������� ����������: "; cin>>surname;
            cout<<endl;
            cout<<setw(24)<<left<<"���"<<"���������"<<endl;
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
                cout<<"��������� �� ������"<<endl;
            cout<<endl;
            MenuSearch();
            break;
        }
        case 3:{
            string order_code;
            bool success3 = false;
            cout<<"����� �� ���� ������ � �������(";
            cout<<orders[0].order_code<<" - "<<orders[Amount.orders_amount-1].order_code<<")"<<endl;
            cout<<"������� ��� ������: "; cin>>order_code;
            cout<<endl;
            cout<<setw(16)<<left<<"��� ������"<<setw(20)<<left<<"��� �������"<<setw(15)<<left<<"��� ������"<<setw(15)<<left<<"��������"<<setw(30)<<left<<"���� ����������� ������"<<"������� �������"<<endl;
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
                cout<<"����� �� ������"<<endl;
            cout<<endl;
            MenuSearch();
            break;
        }
        case 4:{
            string order_ready_code;
            bool success4 = false;
            cout<<"����� �� ���� ������ � ����������� ������� (��������: A101, A102, ...)"<<endl;
            cout<<"������� ��� ������: "; cin>>order_ready_code;
            cout<<endl;
            cout<<setw(16)<<left<<"��� ������"<<setw(20)<<left<<"�����������"<<setw(30)<<left<<"��������� �����������"<<setw(25)<<left<<"��������� �������"<<setw(25)<<left<<"���� ���������� ������"<<endl;
            cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;

            for(int i = 0;i<Amount.orders_ready_amount;i++){
                if(ordersready[i].order_code==order_ready_code){
                    cout<<ordersready[i].order_code<<"\t\t"<<setw(7)<<left
                    <<ordersready[i].staff_surname<<" "<<setw(12)<<left
                    <<ordersready[i].staff_name<<setw(30)<<left
                    <<ordersready[i].staff_position<<setw(5)<<left
                    <<ordersready[i].repair_cost<<setw(20)<<left<<"���."
                    <<currentDateTime(ordersready[i].repair_date)<<endl;
                    success4 = true;
                }
            }
            if (success4==false)
                cout<<"����� �� ������"<<endl;
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

void AddOrderReady(){ //���������� ���������� �������

    string STAFF_SURNAME,STAFF_NAME, REPAIR_COST, ORDER_CODE, GOODS_CODE, GOODS_GUARANTEE;
    cin.ignore();
    cout<<"����� ������ "<<endl;
    OutputOrders();
    cout<<"������� ����� ������: ";
    getline(cin, ORDER_CODE);
    cout<<"���� ����������� "<<endl;
    OutputStaff();
    cout<<"������� ������� � �������� (������� �.�.): ";
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
            if(orders[j].goods_guarantee=="���"){
                cout<<"����: "; getline(cin, REPAIR_COST);
                ordersready[Amount.orders_ready_amount].repair_cost = REPAIR_COST;
            }else if(orders[j].goods_guarantee=="��" && GOODS_GUARANTEE=="��"){
                ordersready[Amount.orders_ready_amount].repair_cost = "0";
            }
            else if(orders[j].goods_guarantee=="��" && GOODS_GUARANTEE=="���"){
                cout<<"����: "; getline(cin, REPAIR_COST);
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
void AddGoods(){ //���������� ������
    string GOODS_NAME, GOODS_FIRM, GOODS_MODEL, GOODS_GUARANTEE;
    goods[Amount.goods_amount].goods_code = to_string(stoi(goods[Amount.goods_amount-1].goods_code)+1);
    cin.ignore();
    cout<<"������� �������� ������: "; getline(cin, GOODS_NAME);
    cout<<"������� �����-������������� ������: "; getline(cin, GOODS_FIRM);
    cout<<"������� ������ ������: "; getline(cin, GOODS_MODEL);
    cout<<"������� ������� �������� � ������(��/���): "; getline(cin, GOODS_GUARANTEE);
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
void AddOrder(){ //���������� ������

    string CLIENT_NAME, GOODS_GUARANTEE, CLIENT_TEL, AVAILABILITY_GOODS, GOOOS_CODE;
    string str1;
    cin.ignore();
    cout<<"��� �������(������� �.�.): "; getline(cin, CLIENT_NAME);
    str1 = orders[Amount.orders_amount-1].order_code;
    IncrementStr(str1);
    orders[Amount.orders_amount].order_code = str1;
    orders[Amount.orders_amount].client_name = CLIENT_NAME;
    OutputGoods();
    cout<<"����� ���� � ����?(��/���): "; cin>>AVAILABILITY_GOODS;
    if(AVAILABILITY_GOODS=="��"){
        cout<<"������� ��� ������: "; cin>>GOOOS_CODE;
        orders[Amount.orders_amount].goods_code = GOOOS_CODE;
    }
    if(AVAILABILITY_GOODS=="���"){
        AddGoods();
        orders[Amount.orders_amount].goods_code = goods[Amount.goods_amount-1].goods_code;
    }

    cout<<"������� �������� � ������(��/���): "; cin>>GOODS_GUARANTEE;
    cout<<"������� �������: "; cin>>CLIENT_TEL;
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
void AddStaff(){ //���������� ����������
    cout<<"���������� ����������"<<endl;
    cout<<"��� ����������(������� �.�.): ";
    cin>>staff[Amount.staff_amount].staff_surname>>staff[Amount.staff_amount].staff_name;
    cin.ignore();
    cout<<"��������� ����������: "; getline(cin, staff[Amount.staff_amount].staff_position);
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

int main(){ //�������� �������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu();
    while(state_menu != 0){
        switch(state_menu){
        case 1:
            InputFiles();
            int state_menu_orders;
            do{
                cout<<"(0) �����"<<endl
                <<"(1) ����������"<<endl
                <<"(2) ��������"<<endl;
                cout<<"��� �����: ";
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
                        cout<<"(0) �����"<<endl
                        <<"(1) �������� �������"<<endl
                        <<"(2) �������� ���������� �������"<<endl;
                        cout<<"��� �����: ";
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
                cout<<"(0) �����"<<endl
                <<"(1) ���������� �����������"<<endl
                <<"(2) �������� �����������"<<endl;
                cout<<"��� �����: ";
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
