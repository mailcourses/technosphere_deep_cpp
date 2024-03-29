# Популярные вопросы и ответы на них

#### Где посмотреть условия домашнего задания?
Условия домашнего задания мы публикуем в этом репозитории. Вы можете его найти в директории lesson-x/homework.md, где x - номер лекции.

#### Как оформлять домашние задание?
1. В вашем GitHub должен быть репозиторий msu\_cpp\_spring\_2021;
2. Внутри репозитория должны быть директории из двух цифр, вида: 01, 02 и т.д. - это номера домашних заданий;
3. Внутри каждой директории могут быть любые файлы реализующие задачу. Обязательным является только файл Makefile;
4. В Makefile обязательно должна быть цель test, которая запускает тесты вашего решения;
5. Собираться ваш код должен компилятором поддерживающим стандарт С++20;
6. Внешних зависимостей быть не должно;
7. Код решения должен быть отформатирован, так проще его читать. Не забывайте про отступы.
8. Максимальное количество попыток сдачи одного задания - 3.

#### Куда и кому высылать мое домашнее задание?
О том, что вы выполнили работу надо сообщать Кандаурову Геннадию. На странице курса на сайте потрала техносферы вы сможете найти кнопку "Отправить решение". К комментарию необходимо добавить вашу ссылку на GitHub. Как только Геннадий проверит вашу работу она отправит Вам ответ в этом же окне.

#### Как будет оцениваться мое домашние задание?
Максимальное количество баллов за одно домашнее задание:
+ 1 балл, если ДЗ выполнено, покрыто тестами и делает то, что оговорено,
+ 1 балл, если ДЗ *зачтено* до дедлайна,
+ 2 балла Геннадий может добавить на свое усмотрение.

*Если будет вычислено, что работа списана, то обеим сторонам выставляется 0 баллов без возможности исправления.*

#### Что значит "ДЗ выполнено, покрыто тестами"?
- Написанный вами код выполняет ту задачу, которая была поставлена в условии
- Код не порождает ошибки/корки/утечки памяти/undefined behaviour
- Код покрыт юнит-тестами, тесты покрывают все возможные кейсы (в рамках разумного)
- Ваш Makefile написан корректно: у него есть цель *all*, которая собирает проект, и цель *test*, которая запускает тесты

#### За что я могу получить магические дополнительные 2 балла?
Если вы красиво оформили ваше решение (имена переменных отображают их суть, код отформатирован, все отступы - это либо (2/4/8 пробела или табы). Ваш код логически разделен hpp(h)/cpp файлы, функции, классы. Нет большого числа вложенности. Использован современный с++. И прочие мелочи. Геннадий будет вам подсказывать, что нужно исправить для их получения.

#### Что будет, если я не успел выслать задание до дедлайна?
Вы теряете 1 балл, т.е. ваш максимальный балл становится 3, а не 4.

#### Что такое юнит-тесты и как их писать?
Юнит-тесты - это набор функций, который позволяет вам проверить, что результаты работы вашей программы совпадает с ожидаемым. Главная идея юнит-тестов - это возможность быстро запустить и понять точно ли моя программа работает верно. Если это не так, то пользователю должно выводиться сообщение о том, что его тест упал.

Пример написание простых юнит тестов для класса-сумматора:
```c++
class Summator
{
public:
    int64_t Sum(int lhs, int rhs)
    {
        return static_cast<int64_t>(lhs) + rhs;
    }

};

void DefaultWorkTest()
{
    Summator summator;
    int64_t result = summator.Sum(1, 5);
    assert(result == 6);
}

void IntLimitTest()
{
    Summator summator;
    int max_int = std::numeric_limits<int>::max();
    int64_t result = summator.Sum(max_int, max_int);
    assert(result == 4'294'967'294);
}

void NegativeTest()
{
    Summator summator;
    int64_t result = summator.Sum(-1, 10);
    assert(result == 9);
}

int main()
{
    DefaultWorkTest();
    IntLimitTest();
    NegativeTest();

    std::cout << "Success!\n";

    return 0;
}
```

!!!ВАЖНО: Юнит-тесты должны явно говорить об успехе или провале программы. Ошибки от тестов должны приходить только в том случае, если ваша программа перестала работать корректно.

P.S. Чтобы ассерты работали надо собирать без NDEBUG. Можно использовать просто if'ы.

#### Что, если я хочу закрыть свой репозиторий от чужих глаз?
Вы можете закрыть его от всех и разрешить доступ отдельно Геннадию: https://github.com/fantom-voronezh

#### Что если я не сдам за три попытки?
Вы получите 0 баллов, если после трех попыток ваша задача так и не заработала. Не переживайте, вам будут подсказывать что необходимо исправить для достижения цели.

#### Что нужно для допуска к экзамену?
ВСЕ сданные домашние задания. Если вы получили 0 баллов за списывание или вам не хватило трех попыток, то вы все равно будете допущены на экзамен.

#### Что если я хочу использовать другой code style нежели в примерах/условиях задачи?
Главное что бы он был.

#### А что программа должна делать в случае...
Если жестко не оговорена обработка ошибок, то тут вы сами можете решить как поступить. Главное, чтобы это не приводило к ошибкам.

#### Я прочитал все пункты выше и условие задачи, у меня все равно остались вопросы :(
Пишите в телеграм Геннадию(@gkandaurov) или в [общий чат](https://t.me/joinchat/HOUFmzzExEBiZDBi) мы поможем вам разобраться :)
