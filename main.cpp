#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <sstream>
#include <locale.h>
#include <termios.h>
#include <stdio.h>
#include <sys/ioctl.h>

struct Russia
{
    virtual void notResponsible() = 0;
};

class MainOfficial : public Russia
{
public:
    void notResponsible()
    {
        std::cout << "\nВертикаль была создана и говорит:\n\e[96m\"Тяжкое наследие девяностых. Не отвечаю. Сплотимся.\"\e[0m" << std::endl;
    }
};

class PeskovsSenselessReply : public MainOfficial
{
public:
    void notResponsible()
    {
        std::cout << "\nЗам Вертикали был создан и говорит:\n\e[96m\"Это не к Администрации вопросы. Вам лучше уточнить у соответствующих органов.\"\e[0m \n";
    }
};

class AnyFromRussia : public MainOfficial
{
public:
    template < typename T>
    void notResponsible( T & object )
    {
        std::cout << "\n Я за \e[92m" << object << "\e[0m не отвечаю!";
    };
};

int _kbhit() {
    static bool inited = false;
    int left;

    if (!inited) {
        termios t;
        tcgetattr(0, &t);
        t.c_lflag &= ~ICANON;
        tcsetattr(0, TCSANOW, &t);
        setbuf(stdin, NULL);
        inited = true;
    }

    ioctl(0, FIONREAD, &left);

    return left;
}

int main()
{
  	std::cout << "Эта программа отражает одно из ключевых явлений России, а именно -- явление \033[0m\033[32m круговой безответственности\033[0m. \nПредлагаем вам внести свой посильный вклад в те зоны, за которые еще кто-то по неопытности российской жизни отвечает.\nПерестаньте, пожалуйста, и срочно сообщите за что вы не отвечаете.\nПримеры указанные ниже будут вам в помощь.\n";

	std::cout << "Нажмите\e[93m Ввод/Enter\e[0m для создания своей комфортной \e[91mзоны\e[0m, где вас не должны трогать";

	int point = 0;
	
	while (true) 
 	{ 
		if (_kbhit() != 0)
        {
			if(std::cin.get() == '\n')
				break;
        }
		std::cout << "." << std::flush; 
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
 	};
	 
    auto putin = new MainOfficial();
    putin->notResponsible();
    auto pesok = new PeskovsSenselessReply();
    pesok->notResponsible();
    auto russian = new AnyFromRussia();

	std::cout << "\nПримеры за что не отвечают россияне порожденные от Вертикали:";
    russian->notResponsible("терминал в автобусе");
    russian->notResponsible("уборку");
    russian->notResponsible("этот участок");
    russian->notResponsible("ваших соседей");
    russian->notResponsible("мобильную связь");
    russian->notResponsible("авиасообщение");
    russian->notResponsible("твое здоровье");
    russian->notResponsible("это программное обеспечение");
  
    std::string irresponsibility;
    std::cout << "\n\nВведите то, за что вы не отвечаете, например, \e[93m'цены'\e[0m или \e[93m 'российскую космонавтику'\e[0m : \n";

    std::getline(std::cin,  irresponsibility);

    std::cout << "\e[91m Поздравляем! \e[0m Теперь вы не отвечаете за: \e[32m" << irresponsibility << "\e[0m \n";
    std::cout << "Вот так это теперь выглядит: \n" ;

    russian->notResponsible(irresponsibility);

	std::cout << "\n\n\n";
    return 0;
}
