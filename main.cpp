#include <iostream>
#include <fstream>
#include "List.h"


void print_menu() {
    system("cls");  // очищаем экран
    printf("Меню:\n");
    printf("1. Прочитать содержимое файла res.txt\n");
    printf("2. Добавление новых данных\n");
    printf("3. Поиск данных по ключу\n");
    printf("4. Удаление данных по ключу;\n");
    printf("5. Вставка данных в упорядоченный по первому полю список, не нарушая\n порядка;\n");
    printf("6. Сортировка по одному полю;\n");
    printf("7. Сортировка списка по двум полям\n");
    printf("8. Вывод списка на экран\n");
    printf("9. Записать в файл res.txt;\n");
    printf("10.Выход\n");
    printf(">");
}

int get_variant(int count) {
    int variant;
    char s[100]; // строка для считывания введённых данных
    scanf("%s", s); // считываем строку

    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again: "); // выводим сообщение об ошибке
        scanf("%s", s); // считываем строку повторно
    }

    return variant;
}

int main() {
    LList a;
    int variant;
    std::string fio;
    std::ifstream f_in;
    std::ofstream f_out;
    Store store;
    do {
        print_menu(); // выводим меню на экран

        variant = get_variant(10); // получаем номер выбранного пункта меню

        switch (variant) {
            case 1:
                f_in.open("res.txt");
                f_in >> a;
                f_in.close();
                break;

            case 2:
                std::cout << "Введите данные в формате (name, cost, age_from, age_to)" << std::endl;
                std::cin >> store;
                a.add(store);
                break;

            case 3:
                std::cout << "Введите фио, что нужно найти"<< std::endl;
                std:: cin >> fio;
                store = *a.find(fio);
                std :: cout << "Результат поиска:" << store;
                break;

            case 4:
                std::cout << "Введите фио для удаления"<< std::endl;
                std::cin >> fio;
                a.remove(fio);
                break;
            case 5:
                std::cout << "Введите данные в формате (fio, number, title, date)" << std::endl;
                std::cin >> store;
                a.add_sorted(store);
                break;
            case 6:
                std::cout << "Готово(sort by one)"<< std::endl;
                a.sort();
                break;

            case 7:
                std::cout << "Готово(sort by two)"<< std::endl;
                a.sort_by_two();
                break;

            case 8:
                std::cout << "Вывод списка на экран"<< std::endl;
                std::cout << a;
                break;
            case 9:
                f_out.open("res.txt");
                f_out << a;
                f_out.close();
                break;

        }

        if (variant != 10)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 10);
    return 0;
}
