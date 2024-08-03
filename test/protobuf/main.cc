
#include <iostream>
#include "test_.pb.h" 
#include <string>
using namespace fixbug;


int main()
{
    LoginRequest req;
    // 设置登录的账号密码
    req.set_name("yejie");
    req.set_pwd(" 520");

    // 检查是否序列化成功
    std::string send_str;
    if(req.SerializeToString(&send_str))
    {
        std::cout<<send_str<<std::endl;
    } 
    // 反序列化的过程
    LoginRequest reqR;
    if(reqR.ParseFromString(send_str))
    {
        std::cout<<reqR.name()<<std::endl;
        std::cout<<reqR.pwd()<<std::endl;
    }
    return 0;
}