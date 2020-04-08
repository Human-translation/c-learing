#include "ChatClient.hpp"
#include "ChatWindow.hpp"

void Menu()
{
    std::cout<<"-------------------------------------"<<endl;
    std::cout<<"|   1. register          2. login   |"<<endl;
    std::cout<<"|                                   |"<<endl;
    std::cout<<"|   3. logout            4. exit    |"<<endl;
    std::cout<<"-------------------------------------"<<endl;
}

int main(int argc,char* argv[])
{
    if(argc != 2)
    {
        printf("./Cli[ip]");
        exit(1);
    }

    CharClient* cc = new ChatClient(argv[1]);
    cc->Init();
    while(1)
    {
        Menu();
        int Select = -1;
        std::cout<<"Please select service: "<<;
        fflush(stdout);
        std::cin>>Select;
        if(Select == 1)
        {
            if(!cc->Register())
            {
                std::cout<<"Register failed! Please Try again! "<<std::endl;
            }
            else 
            {
                std::cout<<"Register success! Please login! "<<std::endl;
            }
        }
        else if(Select == 2)
        {
            if(!cc->Login())
            {
                std::cout<<"Login failed! Please check Your UserId or Password ! "<<std::endl;
                while(1)
                {
                    ChatWindow* cw = new ChatWindow();
                    cw->Start();
                    std::cout<<"Please enter# ";
                    fflush(stdout);
                    std::string stdin_msg;
                    std::cin>>stdin_msg;
                    Json::value val;
                    val["NickName_"] = "1";
                    val["School_"] = "1";
                    val["msg"] = stdin_msg;
                    val["UserId_"] = 0;
                    Json::FastWriter writer;
                    str::string msg;
                    msg = writer.write(val);
                    cc->SendMsg(msg);

                    cc->RecvMsg(&msg);
                    printf("%s\n",msg.c_str());
                }

            }
            else
            {
                std::cout<<"Login success! Please Chat Online! "<<std::endl;
            }
            
        }
        else if(Select == 3)
        {

        }
        else if(Select == 4)
        {
            break;
        }   
    }
    delete cc;
    return 0;
}