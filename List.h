

#ifndef INC_2819_LINKED_LIST_LIST_H
#define INC_2819_LINKED_LIST_LIST_H

#include <string>

class Store {
    private:
        std::string name;
        unsigned int cost;
        unsigned int age_from;
        unsigned int age_to;
    public:
        Store * next, *prev;
        Store(std::string name_, unsigned int number_, unsigned int age_from_, unsigned int age_to_):
            name(name_), cost(number_), age_from(age_from_), age_to(age_to_){};
        Store(){};
        friend std::ostream& operator<<(std::ostream&os, Store& reader)
        {
            os << reader.name << std::endl << reader.cost << std::endl << reader.age_from << std::endl << reader.age_to << std::endl;
            return os;
        }
        friend std::istream& operator>>(std::istream&is, Store& reader)
        {
            is >> reader.name >> reader.cost >> reader.age_from >> reader.age_to;
            return is;
        }
        std::string get_name(){
            return name;
        }
        int get_cost(){
            return cost;
        }
};

class LList
    //  список (он же List)
{
private:
    Store *HEAD, *TAIL; // указатель на начало списка
    int size; // размер массива
public:
    LList():HEAD(nullptr){
        this->HEAD = nullptr;
        this->TAIL = nullptr;
        this->size = 0;
    };
    ~LList();
    bool is_empty();
    void add(Store reader); // функция добавления элемента
    void add_sorted(Store reader); // функция добавления элемента

    void sort();
    void sort_by_two();
    void print(); // функция распечатки списка
    void print_names();
    Store* find(std::string name);
    void insert_after(Store* prev_node, Store *mass);
    void remove(std::string _val);
    friend std::ostream& operator<<(std::ostream&os, LList& list)
    {
        Store *temp = list.HEAD;
        while (temp != nullptr) // Пока по адресу хоть что-то есть
        {
            os << *temp;
            temp = temp->next; // Запишем указатель на адрес следующего элемента структуры
        }
        return os;
    }
    friend std::istream& operator>>(std::istream&is, LList& list)
    {
        while (is){
            Store r;
            is>>r;
            list.add(r);
        }
        return is;
    }
};


#endif //INC_2819_LINKED_LIST_LIST_H
