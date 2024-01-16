#include<iostream>
#include<conio.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include<vector>
#include<sstream>
#include<cstdio>
#include<random>
#include<fstream>
#include<algorithm>

using namespace std;




int random_id_card(){

    srand(time(NULL));
    int id1=rand() % 30 + 1985;

    return id1;
}

void gotoxy(int x,int y)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD a={x,y};
    SetConsoleCursorPosition(h,a);

}

void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width-1;
    WindowSize.Bottom = height-1;
 
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

class crypto {

    private:
        string name = "";
        double price = 0.00;
        double result = 0.00;
        double lot = 0.00; 

    public:
            void set_lot(double lot){
                this->lot = lot;
            }

            void set_name(string name){
                this->name = name;
            }

            void set_price(double price){
                this->price = price;
            }

            double calculated(){
                result = price; 
            }
};

struct product{
    string name = "";
};
    product* set_product(){
        string n ;
        cout<<"Name of product: ";cin>>n;
        product* prd = new product;
            prd->name = n;
        return prd;
    }

void file_in_product(vector<product> vtr_product){
    fstream file;
        file.open("product.txt",ios::out);
            for(int i = 0 ; i<vtr_product.size() ; i++){
                file<<vtr_product[i].name<<endl;
            }
        file.close();
}

void file_out_product(vector<product>& vtr_product){
    product* prd = new product;
    vtr_product.clear();
    fstream file;
        file.open("product.txt",ios::in);
        string line,s1;
        stringstream ss;
        int i = 0;
            while(getline(file,line)){
                ss<<line;
                ss>>s1;
                prd->name=s1;
                vtr_product.push_back(*prd);
                ss.clear();
                i++;
            }
        delete prd;
        file.close();
}

void show_product(vector<product> vtr_product){
    for(int i = 0 ; i<vtr_product.size() ; i++){
        cout<<i<<". "<<vtr_product[i].name<<endl;
    }
}

struct sessionline{
    string session ="" ;
    double time1=0.00; double time2=0.00;
};


    sessionline* set_session(){
        string session_;double time_1;double time_2;
        cout<<"Name of session: ";cin>>session_;
        cout<<endl;
        cout<<"0.1 hour = 6 munite , 0.2 = 12 , 0.3 = 18 , 0.4 = 24 , 0.5 = 30 , 0.6 = 36 , 0.7 = 42 , 0.8 = 48 , 0.9 = 54 , 1 = 60"<<endl;
        cout<<"Time start: ";cin>>time_1;
        cout<<"Time end: ";cin>>time_2;
        sessionline* ss = new sessionline;
        ss->session = session_;ss->time1 = time_1;ss->time2 = time_2;
        return ss;
    }




struct timeline{

    int day,month,year;
    int s,m,h;

};

    timeline* set_time(){

        timeline* tl = new timeline;
        time_t curr_time;
        curr_time = time(NULL);
        char *tm = ctime(&curr_time);
        
        stringstream ss;
        ss<<tm;
        string s1,s2,s3,s4,s5;
        ss>>s1>>s2>>s3>>s4>>s5;

        stringstream syear,smonth,sday;

        tl->year = stoi(s5);

             if(s1 == "Mon") tl->day = 2;
             if(s1 == "Sat") tl->day = 3;
             if(s1 == "Wed") tl->day = 4;
             if(s1 == "Thur") tl->day = 5;
             if(s1 == "Fri") tl->day = 6;
             if(s1 == "Sat") tl->day = 7;
             if(s1 == "Sun") tl->day =8;

            if(s2 == "Jan") tl->month = 1;
            if(s2 == "Feb") tl->month = 2;
            if(s2 == "Mar") tl->month = 3;
            if(s2 == "Apr") tl->month = 4;
            if(s2 == "May") tl->month = 5;
            if(s2 == "Jun") tl->month = 6;
            if(s2 == "Jul") tl->month = 7;
            
            if(s2 == "Aug") tl->month = 8;
            if(s2 == "Sep") tl->month = 9;
            if(s2 == "Oct") tl->month = 10;
            if(s2 == "Nov") tl->month = 11;
            if(s2 == "Dec") tl->month = 12;

        sday<<s3;
        sday>>tl->day;


        char a;

        ss.clear();
        ss<<s4;
        ss>>tl->h>>a>>tl->m>>a>>tl->s;
        return tl;
    }



void file_in_session(vector<sessionline>& vtr_session){
    fstream file;
        file.open("session.txt",ios::out);
            for(int i = 0 ; i<vtr_session.size() ; i++){
                file<<vtr_session[i].session<<" "<<vtr_session[i].time1<<" "<<vtr_session[i].time2<<endl;
            }
        file.close();
}



void file_out_session(vector<sessionline>& vtr_session){

    sessionline* ss_ = new sessionline;
    vtr_session.clear();
    fstream file;
        file.open("session.txt",ios::in);

            stringstream ss;
            string s,s1,s2,s3;

            double tm1,tm2;
        
            int i=0;

                while(getline(file,s)){
                    ss<<s;
                    ss>>s1>>s2>>s3;
                
                    ss_->session = s1;
                    ss.clear();
                    ss<<s2;
                    ss>>tm1;
                    ss_->time1 = tm1;
                    ss.clear();
                    ss<<s3;
                    ss>>tm2;
                    ss_->time2 = tm2;
                    vtr_session.push_back(*ss_);
                    i++;
                    ss.clear();
                }
        
        delete ss_;
        file.close();
}

void exchange_time(double time,double& hour,double& munite){
    stringstream ss;
    int a;
    ss<<time;ss>>a;
    hour = a; munite = ((time*10) - (a*10))*6;
    ss.clear();
}

void show_session(vector<sessionline> vtr_session){
    double hour1,munite1,hour2,munite2;
    for(int i = 0 ; i< vtr_session.size(); i++){
        exchange_time(vtr_session[i].time1,hour1,munite1);exchange_time(vtr_session[i].time2,hour2,munite2);
        if(munite1 == 0 && munite2!=0){
            cout<<i<<". "<<vtr_session[i].session<<"    "<<hour1<<":"<<munite1<<"0  -   "<<hour2<<":"<<munite2<<endl;
        }
        else if(munite1 != 0 && munite2==0){
            cout<<i<<". "<<vtr_session[i].session<<"    "<<hour1<<":"<<munite1<<"  -  "<<hour2<<":"<<munite2<<"0"<<endl;
        }
        else if(munite1 == 0 && munite2==0){
            cout<<i<<". "<<vtr_session[i].session<<"    "<<hour1<<":"<<munite1<<"0  -   "<<hour2<<":"<<munite2<<"0"<<endl;
        }
        else if(munite1 !=0 && munite2!=0) {
            cout<<i<<". "<<vtr_session[i].session<<"    "<<hour1<<":"<<munite1<<"  -  "<<hour2<<":"<<munite2<<endl;
        }
        }
    }


void change_time(vector<sessionline> vtr_session,int& hour1 , int& munite1,int& hour2,int& munite2){

    stringstream ss;
    int a ; ss<<vtr_session[0].time1;ss>>a; hour1 = a;  a = a * 10;
    int b ; b = vtr_session[0].time1 *10;

        munite1 = (b-a) *6;
    
    stringstream ss_; int c,d;
  
    ss_.clear(); ss_<<vtr_session[0].time2;ss_>>c; hour2 = c ; c = c*10;
    d=vtr_session[0].time2*10;

        munite2 = (d-c) *6;
    
    ss.clear();

}





void in_vtr_session(vector<sessionline>& vtr_session){

    string session = "" ; double time1 = 0.00; double time2 = 0.00;

    cout<<"Session: ";cin>>session;cout<<"Time start session "<<session<<" :";cin>>time1;cout<<"Time end session "<<session<<" :";cin>>time2;

    sessionline* ss = new sessionline;
    ss = set_session();cout<<endl; cout<<"Loading ";
/*
    for(int i = 0 ; i<4 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            Sleep(500);
            cout<<". ";
        }
    }
*/
    cout<<endl;

    if(vtr_session.size() == 1){
        vtr_session.pop_back();
    }

        vtr_session.push_back(*ss);

            int hour1,hour2,munite1,munite2;
            change_time(vtr_session,hour1,munite1,hour2,munite2);
    
    string ampm1 , ampm2;

    if(hour1 >= 0 && hour1 <= 12 ){
        ampm1 = "AM";
    } 
    else {
        ampm1 = "PM";
    }

    if(hour2>= 0 && hour2<=12){
        ampm2 = "AM";
    }
    else{
        ampm2 = "PM";
    }
     

    cout<<"--------------------------"<<endl;
    cout<<endl;
    if(munite1 == 0 && munite2 ==0){
    cout<<"Session: "<<session<<"    "<<hour1<<":"<<munite1<<"0 "<<ampm1<<"    "<<hour2<<":"<<munite2<<"0 "<<ampm2<<endl;
    }
    else if (munite1 ==0 && munite2 !=0 ){
    cout<<"Session: "<<session<<"    "<<hour1<<":"<<munite1<<"0 "<<ampm1<<"    "<<hour2<<":"<<munite2<<" "<<ampm2<<endl;
    }
    else if(munite1 =! 0 && munite2==0 ){
    cout<<"Session: "<<session<<"    "<<hour1<<":"<<munite1<<" "<<ampm1<<"    "<<hour2<<":"<<munite2<<"0 "<<ampm2<<endl;
    }
    else{
    cout<<"Session: "<<session<<"    "<<hour1<<":"<<munite1<<" "<<ampm1<<"    "<<hour2<<":"<<munite2<<" "<<ampm2<<endl;
    }

    cout<<endl;
    cout<<"--------------------------"<<endl;

    cout<<"Done!"<<endl;

}



void in_time(vector<timeline>& vtr_time){

    timeline* tm = new timeline;

    tm = set_time();
    if(vtr_time.size() == 1){
        vtr_time.pop_back();
    }
    vtr_time.push_back(*tm);
}


void clock(vector<timeline> vtr_time){

int n = 0 ; string ampm;
        in_time(vtr_time);
        if(vtr_time[0].h >=0 && vtr_time[0].h <=12 ){
            ampm = "AM";
        }
        else{
            ampm = "PM";
        }
        gotoxy(0,5);cout<<vtr_time[0].h<<":"<<vtr_time[0].m<<" "<<ampm<<endl;

}


//backtest

class backtest_data{
    public:

        double risk_rewark = 0.00;

        double time_start  = 0.00;

        double time_end    = 0.00;

        string session     = "";

        string e_product   = "";

        vector<backtest_data> vtr_backtest_data;

    backtest_data():risk_rewark(0.00) , time_start(0.00) , time_end(0.00) , session(""),e_product(""){};
    backtest_data(double rr, double tm_start , double tm_end,string ss,string e_pr) : risk_rewark(rr) , time_start(tm_start) ,time_end(tm_end) , session(ss) , e_product(e_pr){};

    void in_data(vector<sessionline> vtr_session,vector<product> product);
    void file_in_data();
    void file_out_data();
    void show();
    
};

class backtest_caculator : public backtest_data{


        double win_rate = 0.00;

        double rr_loss = 0.00;

        double rr_win  = 0.00;


    public:

        void calculating_rate(vector<sessionline> vtr_session,backtest_data bt,vector<product> vtr_product);
        

};


int main(){

ShowScrollbar(0);
    vector<sessionline> vtr_session;
    vector<timeline>    vtr_time;
    vector<product>     vtr_product;

    backtest_caculator bt_caculator;
    backtest_data       bt;

    product* prd = new product;
    timeline* tm = new timeline;
    sessionline* ss = new sessionline;

    tm = set_time();
    vtr_time.push_back(*tm);
    
    file_out_session(vtr_session);
    file_out_product(vtr_product);
    bt.file_out_data();


    //bt_caculator.calculating_rate(vtr_session,bt,vtr_product);

    int choice;int aaa = 1;int choice_1;

goback:
        system("cls");
        cout<<"1. Backtest"<<endl;
        cout<<"2. Menu"<<endl;
        cout<<"0. End"<<endl;
        
        cout<<"> ";clock(vtr_time);gotoxy(1,3);cin>>choice;

        switch(choice){
            case 1:
bt_1:
                system("cls");
                bt.in_data(vtr_session,vtr_product);
                bt.file_in_data();cout<<endl;
                
                cout<<"1. Continue"<<endl;
                cout<<"0. Done"<<endl;
                cout<<"> ";cin>>choice_1;
                
                    if(choice_1 == 1){
                        goto bt_1;
                    }
                    else{
                        goto goback;
                    }
            case 2:
menu_1:
                system("cls");
                    cout<<"1. Menu product"<<endl;
                    cout<<"2. Menu session"<<endl;
                    cout<<"3. Backtest history"<<endl;
                    cout<<"4. Backtest caculating result"<<endl;
                    cout<<"0. Back"<<endl;
                    int choice_2;
                    cout<<endl;
                    cout<<"> ";cin>>choice_2;
                        switch(choice_2){
                            case 1:
menu_2:
                                int choice_3;
                                system("cls");
                                cout<<"1. Add product"<<endl;
                                cout<<"2. Show all product"<<endl;
                                cout<<"0. Back"<<endl;
                                cout<<endl;
                                cout<<"> ";cin>>choice_3;
                                    switch(choice_3){
                                        case 1:
                                            prd = set_product();
                                            vtr_product.push_back(*prd);
                                            file_in_product(vtr_product);
                                            cout<<"Done!"<<endl;system("pause");goto menu_2;
                                        case 2:
                                            file_out_product(vtr_product);
                                            show_product(vtr_product);
                                            system("pause");
                                            goto menu_2;
                                        case 0:
                                            goto menu_1;
                                        default:

                                            cout<<"Wrong choice!";
                                            goto menu_2;                                        
                                    }
                            
                            case 2:
menu_3:
                                int choice_4;
                                system("cls");
                                cout<<"1. Add session"<<endl;
                                cout<<"2. Show all session"<<endl;
                                cout<<"0. Back"<<endl;
                                cout<<endl;
                                cout<<"> ";cin>>choice_4;
                                    switch(choice_4){
                                        case 1:
                                            ss = set_session();
                                            vtr_session.push_back(*ss);
                                            file_in_session(vtr_session);
                                            cout<<"Done!"<<endl;system("pause");goto menu_3;
                                        case 2:
                                            file_out_session(vtr_session);
                                            show_session(vtr_session);cout<<endl;
                                            system("pause");goto menu_3;
                                        case 0:
                                        goto goback;
                                        default:

                                            cout<<"Wrong choice!";
                                            goto menu_3;
                                    }
                            
                            case 3:
                                cout<<endl;
                                bt.show();
                                cout<<endl;
                                system("pause");
                                goto menu_1;

                            case 4:
                                system("cls");
                                cout<<endl;
                                bt_caculator.calculating_rate(vtr_session,bt,vtr_product);
                                cout<<endl;
                                system("pause");
                                goto menu_1;
                            case 0:

                                goto goback;

                             default:

                                cout<<"Wrong choice!";
                                goto menu_1;                            
                            
                        }
            case 0:

                return 0;

            default:

                cout<<"Wrong choice!";
                goto goback;
        }


}



void backtest_data::in_data(vector<sessionline> vtr_session,vector<product> vtr_product){

double rr,tm_start,tm_end; string e_pr;

    cout<<"Risk/Reward: ";cin>>rr;cout<<endl;cout<<"0.1 hour = 6 munite , 0.2 = 12 , 0.3 = 18 , 0.4 = 24 , 0.5 = 30 , 0.6 = 36 , 0.7 = 42 , 0.8 = 48 , 0.9 = 54 , 1 = 60"<<endl;
    cout<<endl;cout<<"Time start: ";cin>>tm_start;
    cout<<"Time end: ";cin>>tm_end;

    cout<<endl;
    int choice = 0 ;
    for(int i = 0 ; i< vtr_product.size(); i++){
        cout<<i+1<<". "<<vtr_product[i].name<<"    ";
    }
    cout<<endl;

    cout<<"> ";cin>>choice; e_pr = vtr_product[choice-1].name;

    string ss_;

    for(int i = 0 ; i<vtr_session.size() ; i++){
        if(tm_start >= vtr_session[i].time1 && tm_end <= vtr_session[i].time2){
            ss_ = vtr_session[i].session;
        }
    }
    cout<<endl;
    cout<<"Risk/Reward: "<<rr<<"    Time start: "<<tm_start<<"  Time end: "<<tm_end<<"  Session: "<<ss_<<"  Product: "<<e_pr<<endl;




        vtr_backtest_data.push_back(backtest_data(rr,tm_start,tm_end,ss_,e_pr));
    /*
    for(int i = 0 ; i<vtr_backtest_data.size() ; i++){
             cout<<vtr_backtest_data[i].risk_rewark<<" ";
             cout<<vtr_backtest_data[i].time_start<<" ";
             cout<<vtr_backtest_data[i].time_end<<" ";
             cout<<vtr_backtest_data[i].session<<" ";
            }
    */

    cout<<endl;
}

void backtest_data::file_in_data(){
    fstream file;
        file.open("backtest.txt",ios::out);
            for(int i = 0 ; i < vtr_backtest_data.size() ; i++){
                file<<vtr_backtest_data[i].risk_rewark<<" "<<vtr_backtest_data[i].time_start<<" "<<vtr_backtest_data[i].time_end<<" "<<vtr_backtest_data[i].session<<" "<<vtr_backtest_data[i].e_product<<endl;
            }
        file.close();
}

void backtest_data::file_out_data(){

    fstream file;
    file.open("backtest.txt",ios::in);

        string line = "";
        stringstream ss;
        string ss_,e_prd;
        double s1,s2,s3;
        double rr ; double tm_start = 0.00 ; double tm_end = 0.00;
        int i = 0;

            while(getline(file,line)){
                ss<<line;
                ss>>s1>>s2>>s3>>ss_>>e_prd;
                rr = s1 ; tm_start = s2 ; tm_end = s3;
                vtr_backtest_data.push_back(backtest_data(rr,tm_start,tm_end,ss_,e_prd));
                ss.clear();
                i++;
            }
            /*
            for(int i = 0 ; i<vtr_backtest_data.size() ; i++){
             cout<<vtr_backtest_data[i].risk_rewark<<" ";
             cout<<vtr_backtest_data[i].time_start<<" ";
             cout<<vtr_backtest_data[i].time_end<<" ";
             cout<<vtr_backtest_data[i].session<<" ";
             cout<<vtr_backtest_data[i].e_product<<endl;
            }
            */
    file.close();

}

void backtest_data::show(){
    double hour1 = 0.00 ; double munite1 = 0.00; double hour2 = 0.00 ; double munite2 = 0.00;
        for(int i = 0 ; i < vtr_backtest_data.size() ; i++){
            exchange_time(vtr_backtest_data[i].time_start,hour1,munite1);
            exchange_time(vtr_backtest_data[i].time_end,hour2,munite2);
            if(munite1 == 0&&munite2!=0){
            cout<<i+1<<". "<<"Risk/reward: "<<vtr_backtest_data[i].risk_rewark<<"      "<<hour1<<":"<<munite1<<"0 - "<<hour2<<":"<<munite2<<"       "<<vtr_backtest_data[i].session<<"      "<<vtr_backtest_data[i].e_product<<endl;
            }
            else if(munite2 == 0 && munite1!=0){
            cout<<i+1<<". "<<"Risk/reward: "<<vtr_backtest_data[i].risk_rewark<<"      "<<hour1<<":"<<munite1<<" - "<<hour2<<":"<<munite2<<"0       "<<vtr_backtest_data[i].session<<"      "<<vtr_backtest_data[i].e_product<<endl;
            }
            else if (munite1 == 0 && munite2 == 0){
            cout<<i+1<<". "<<"Risk/reward: "<<vtr_backtest_data[i].risk_rewark<<"      "<<hour1<<":"<<munite1<<"0 - "<<hour2<<":"<<munite2<<"0       "<<vtr_backtest_data[i].session<<"      "<<vtr_backtest_data[i].e_product<<endl;
            }
            else{
            cout<<i+1<<". "<<"Risk/reward: "<<vtr_backtest_data[i].risk_rewark<<"      "<<hour1<<":"<<munite1<<" - "<<hour2<<":"<<munite2<<"       "<<vtr_backtest_data[i].session<<"      "<<vtr_backtest_data[i].e_product<<endl;
            }
            }
            cout<<endl;
}



void backtest_caculator::calculating_rate(vector<sessionline> vtr_session,backtest_data bt,vector<product> vtr_product){



    double number_win = 0; int number_loss = 0;
    for(int i = 0 ; i < bt.vtr_backtest_data.size(); i++){
        if(bt.vtr_backtest_data[i].risk_rewark > 0){
            number_win ++;
            rr_win += bt.vtr_backtest_data[i].risk_rewark;
        }
        else{
            number_loss++;
            rr_loss += bt.vtr_backtest_data[i].risk_rewark;
        }
    }

    double siz=0.00;
    stringstream ss ; ss<<bt.vtr_backtest_data.size();
    ss>>siz;
    win_rate = (number_win / siz) *100;

    cout<<"Win rate:    "<<win_rate<<" %    ("<<number_win<<" win | "<<number_loss<<" loss)"<<endl;cout<<endl;
    cout<<"Session          " <<"Ammount            "<<"Risk/Reward"<<"         Win rate (%)"<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    int ammount = 0;
    double rr_ = 0.00;double win = 0 ; double loss = 0;double w_rate = 0.00;
    for(int i = 0 ; i < vtr_session.size();i++){
        for(int j = 0 ; j<bt.vtr_backtest_data.size() ; j++){
            if(bt.vtr_backtest_data[j].session == vtr_session[i].session){
                if(bt.vtr_backtest_data[j].risk_rewark>0){
                    win++;
                }
                else{
                    loss++;
                }
                ammount++;
                rr_ = bt.vtr_backtest_data[j].risk_rewark + rr_;
            }
        }

                    if(ammount!=0){
                    w_rate = (win/ammount)*100;}

                    cout<<vtr_session[i].session;
                    cout<<"                "<<ammount;
                    cout<<"                     "<<rr_;
                    cout<<"                  "<<w_rate<<endl;

                            /*
                            if(vtr_session[i].session.size() < 6){
                                for(int i = 0 ; i< (6-vtr_session[i].session.size()) ; i++){
                                    cout<<" ";
                                }
                            }
                            else{
                                cout<<"         "
                            }
                            */

         rr_ = 0.00;
         ammount = 0;
         w_rate = 0;
    }
    cout<<endl;cout<<endl;
    win = 0 ; loss = 0;
    ammount = 0;
    cout<<"Product          " <<"Ammount            "<<"Risk/Reward"<<"         Win rate (%)"<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    
    for(int i = 0 ; i < vtr_product.size();i++){
        for(int j = 0 ; j<bt.vtr_backtest_data.size() ; j++){
            if(bt.vtr_backtest_data[j].e_product == vtr_product[i].name){
                if(bt.vtr_backtest_data[j].risk_rewark>0){
                    win++;
                }
                else{
                    loss++;
                }
                ammount++;
                rr_ = bt.vtr_backtest_data[j].risk_rewark + rr_;
            }
        }
                    if(ammount!=0){
                        w_rate = (win/ammount)*100;}
                    cout<<vtr_product[i].name;
                    cout<<"                "<<ammount;
                    cout<<"                     "<<rr_;
                    cout<<"                  "<<w_rate<<endl;
         rr_ = 0.00;
         ammount = 0;
         w_rate = 0;
         win = 0;
         loss = 0;

    }
    cout<<endl;cout<<endl;
    cout<<"Risk/Reward Win: "<<rr_win<<endl;
    cout<<"Risk/Reward Loss: "<<rr_loss<<endl;
    cout<<endl;
    cout<<"Risk/Reward Profit: "<<rr_win+rr_loss<<endl;
    cout<<endl;
   

}


//You're the light...I was blind...



