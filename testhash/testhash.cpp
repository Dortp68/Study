#include <string>
#include <iostream>

using namespace std;
template <typename U>
int HashFunc(U key)
{
    return key%10;
}

template <typename T, typename U>
class HashTable
{
public:
    int i = 0;
    HashTable()
    {
        for (int j = 0; j < 10; j++)
        {
            arr[j] = nullptr;
        }
    }
    ~HashTable()
    {
        cout << "Таблица удалена, завершение работы";
    }
    template <typename T, typename U>
    class Node
    {
    public:
        T data;
        U key;
        Node* pNext;
        Node(T data = T(), U key = U(), Node* pNext = nullptr)
        {
            this->data = data;
            this->key = key;
            this->pNext = pNext;
        }
        void GetInf()
        {
            cout << "[Значение: " << data << " Ключ:" << key << "]" << endl << "          ";
        }
    };
    Node<T, U>* arr[10];

    void add(T data, U key)
    {
        i = HashFunc(key);
        arr[i] = new Node<T, U>(data, key, arr[i]);
        cout << "Элемент добавлен";
    }
    void del(U key)
    {
        i = HashFunc(key);
        if (arr[i] == nullptr)
        {
            cout << "С данным ключом элемента не существует" << endl;
        }
        else
        {
            Node<T, U>* current = this->arr[i];
            Node<T, U>* tmp = this->arr[i];
            while ((current->pNext != nullptr) && (current->key != key))
            {
                tmp = current;
                current = current->pNext;
            }
            if (current == arr[i])
            {
                arr[i] = arr[i]->pNext;
            }
            else
            {
                tmp->pNext = current->pNext;
            }
            cout << "Удаление элемента" << endl;
            delete current;
        }
    }
    void clear()
    {
        for (int j = 0; j < 10; j++)
        {
            delete arr[j];
        }
    }
    void find(U key)
    {
        i = HashFunc(key);
        if (arr[i] == nullptr)
        {
            cout << "С данным ключом элемента не существует" << endl;
        }
        else
        {
            Node<T, U>* current = this->arr[i];
            while (current != nullptr)
            {
                if (current->key == key)
                {
                    cout << "Найден элемент по ключу " << key << ":" << endl;
                    current->GetInf();
                }
                current = current->pNext;
            }
        }
    }
    void GetAll()
    {
        cout << "Вывод хеш-таблицы";
        for (int j = 0; j < 10; j++)
        {
            cout << "Ячейка " << j << ": ";
            if (arr[j] == nullptr)
            {
                cout << "Пусто" << endl;
            }
            else
            {
                Node<T, U>* current = this->arr[j];
                while (current != nullptr)
                {
                    current->GetInf();
                    current = current->pNext;
                }
                cout << endl;
            }
        }
        cout << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    HashTable<int, int> table1;
    while (1)
    {
        int a, b;
        char t;
        cin >> t;
        if (t == 'a')
        {
            cout << "Добавление элемента" << endl;
            cout << "Введите значение " << endl;
            cin >> a;
            cout << "Введите ключ " << endl;
            cin >> b;
            table1.add(a, b);
        }
        else if (t == 'f')
        {
            cout << "Поиск элемента" << endl;
            cout << "Введите ключ " << endl;
            cin >> b;
            table1.find(b);
        }
        else if (t == 'd')
        {
            cout << "Удаление элемента" << endl;
            cout << "Введите ключ " << endl;
            cin >> b;
            table1.del(b);
        }
        else if (t == 'g')
        {
            cout << "Вывод всей таблицы" << endl;
            table1.GetAll();
        }
        else if (t == 'c')
        {
            table1.clear();
            break;
        }
        else
        {
            cout << "Команда не найдена" << endl;
        }
    }
}
