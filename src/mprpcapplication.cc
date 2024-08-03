#include <mprpcapplication.h>
#include <iostream>
#include <unistd.h>
// 静态函数类外初始化
void ShowArgsHelp()
{
    std::cout<<"format: comman -i <configfile>"<<std::endl;
}

void MprpcApplication::Init(int argc,char ** argv)
{
    if (argc < 2) 
    {
        ShowArgsHelp();
    }
}
// 获取唯一的单例
MprpcApplication &MprpcApplication::GetInstance()
{
    static MprpcApplication temp;
    return temp;
}