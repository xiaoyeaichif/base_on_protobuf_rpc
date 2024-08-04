#include <mprpcapplication.h>
#include <iostream>
#include <unistd.h>


MprpcConfig MprpcApplication::m_config;
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
        exit(EXIT_FAILURE);
    }

    int c = 0;
    // 配置文件
    std::string config_file;
    while((c = getopt(argc, argv, "i:")) != -1)
    {
        switch (c)
        {
        case 'i':
            config_file = optarg;
            break;
        //不希望出现的参数
        case '?':
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        //没有带正确的参数
        case ':':
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        default:
            break;
        }
    }

    // 开始加载配置文件了 rpcserver_ip=  rpcserver_port   zookeeper_ip=  zookepper_port=
    m_config.LoadConfigFile(config_file.c_str());

    // std::cout << "rpcserverip:" << m_config.Load("rpcserverip") << std::endl;
    // std::cout << "rpcserverport:" << m_config.Load("rpcserverport") << std::endl;
    // std::cout << "zookeeperip:" << m_config.Load("zookeeperip") << std::endl;
    // std::cout << "zookeeperport:" << m_config.Load("zookeeperport") << std::endl;
}
// 获取唯一的单例
MprpcApplication &MprpcApplication::GetInstance()
{
    static MprpcApplication temp;
    return temp;
}

MprpcConfig& MprpcApplication::GetConfig()
{
    return m_config;
}