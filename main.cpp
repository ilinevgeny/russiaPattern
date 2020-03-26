#include <iostream>
#include <string>

struct Russia
{
    virtual void notResponsible() = 0;
};

class MainOfficial : public Russia
{
public:
    void notResponsible()
    {
        std::cout << "\nТяжкое наследие девяностых. Кхе-кхе. Сплотимся." << std::endl;
    }
};

class PeskovsSenselessReply : public MainOfficial
{
public:
    void notResponsible()
    {
        std::cout << "\nВам лучше уточнить у соответствующих органов. \n";
    }
};

class AnyFromRussia : public MainOfficial
{
public:
    template < typename T>
    void notResponsible( T & object )
    {
        std::cout << "\n Я за " << object << " не отвечаю! \n";
    };
};


int main()
{
   system("chcp 65001");

    auto * putin = new MainOfficial();
    putin->notResponsible();
    auto * pesok = new PeskovsSenselessReply();
    pesok->notResponsible();
    auto * russian = new AnyFromRussia();
    russian->notResponsible("терминал");
    russian->notResponsible("уборку");
    russian->notResponsible("этот участок");
    russian->notResponsible("ваших соседей");
    russian->notResponsible("мобильную связь");
    russian->notResponsible("авиасообщение");
    russian->notResponsible("твое здоровье");
    russian->notResponsible("это программное обеспечение");
    russian->notResponsible("депутата");
    russian->notResponsible("страну");
    russian->notResponsible("себя");

    std::string irresponsibility;
    std::cout << "Введите за что вы не отвечаете: \n";

    std::getline(std::cin,  irresponsibility);

    std::cout << "Поздравляем! Теперь вы не отвечаете за: " << irresponsibility << " \n";
    std::cout << "Вот так это теперь выглядит: " ;

    russian->notResponsible(irresponsibility);
    return 0;
}
