#include <iostream>
#include "mystruct.h"

void print_result(bool condition, const std::string& test_name) {
    if (condition) {
        std::cout << "[OK] " << test_name << std::endl;
    } else {
        std::cout << "[FAILED] " << test_name << std::endl;
    }
}

void print(const MyStruct& ms) {
    auto it = ms.begin();
    while (it != ms.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}
// void print_full(MyStruct& ms) {
//     std::cout << "Iterator-based print:\n";
//     auto it = ms.begin();
//     while (it != ms.end()) {
//         std::cout << *it << " ";
//         ++it;
//     }
//     std::cout << "\n";

//     std::cout << "Back(): " << ms.back() << "\n";
//     std::cout << "Size: " << ms.size() << "\n";
// }

int main() {
    MyStruct ms;
for (int i = 0; i < 10; ++i) ms.push_back(i);

auto it = ms.begin();
++it; ++it; // на позицію з елементом 2

it = ms.erase(it); // erase(2) → it повинен вказувати на 3
std::cout << *it << std::endl; // очікується: 3



    {
        std::cout << "\n== push_back, push_front, size, back, front ==" << std::endl;
        MyStruct ms;
        ms.push_back(1);
        ms.push_back(2);
        ms.push_back(3);
        ms.push_front(0);
        print_result(ms.size() == 4, "size == 4");
        print_result(ms.front() == 0, "front == 0");
        print_result(ms.back() == 3, "back == 3");

    }

    {
        std::cout << "\n== pop_back, pop_front ==" << std::endl;
        MyStruct ms{1, 2, 3, 4, 5};
        ms.pop_back();
        ms.pop_front();
        print_result(ms.size() == 3, "size == 3");
        print_result(ms.front() == 2, "front == 2");
        print_result(ms.back() == 4, "back == 4");
    }

    
    
    {
    std::cout << "\n== insert та erase ==" << std::endl;
    MyStruct ms{1, 2, 4, 5};
    print(ms);
    auto it = ms.begin(); ++it; ++it;
    ms.insert(it, 3);  // 1 2 3 4 5
    print(ms);
    it = ms.begin(); ++it; ++it;
    ms.erase(it);  // 1 2 4 5
    print(ms); // наш новий дебаг
    print_result(ms.size() == 4, "size == 4 після insert/erase");
}


    {
        std::cout << "\n== clear та empty ==" << std::endl;
        MyStruct ms{1, 2, 3};
        ms.clear();
        print_result(ms.empty(), "empty == true");
        print_result(ms.size() == 0, "size == 0");
    }

    {
        std::cout << "\n== copy constructor ==" << std::endl;
        MyStruct ms1{10, 20, 30};
        MyStruct ms2 = ms1;
        print_result(ms2.size() == 3, "копія: size == 3");
        print_result(ms2.front() == 10 && ms2.back() == 30, "копія: правильні значення");
        ms1.pop_back();
        print_result(ms2.size() == 3, "копія не змінилась після зміни оригіналу");
    }

    {
        std::cout << "\n== move constructor ==" << std::endl;
        MyStruct ms1{1, 2, 3};
        MyStruct ms2 = std::move(ms1);
        print_result(ms2.size() == 3, "переміщено: size == 3");
        print_result(ms1.size() == 0 || ms1.empty(), "переміщено: ms1 порожній");
    }

    {
        std::cout << "\n== ітератори begin(), end(), ++, * ==" << std::endl;
        MyStruct ms{5, 10, 15};
        int expected[] = {5, 10, 15};
        int idx = 0, ok = 1;
        for (auto it = ms.begin(); it != ms.end(); ++it, ++idx) {
            if (*it != expected[idx]) {
                ok = 0;
                break;
            }
        }
        print_result(ok == 1, "ітератори працюють правильно");
    }

    {
        std::cout << "\n== shrink_to_fit ==" << std::endl;
        MyStruct ms;
        for (int i = 0; i < 20; ++i) ms.push_back(i);
        ms.erase(ms.begin());          // erase 0
        ms.erase(++ms.begin());        // erase 2-й після 1
        int before = ms.size();
        ms.shrink_to_fit();
        print_result(ms.size() == before, "shrink_to_fit зберігає розмір");
    }

    {
        std::cout << "\n== перевірка ущільнення через erase+shrink_to_fit ==\n";
        MyStruct ms;
        for (int i = 0; i < 20; ++i) ms.push_back(i);
        for (int val : ms) std::cout << val << " ";

        for (auto it = ms.begin(); it != ms.end(); ) {
            if (*it % 3 == 0) it = ms.erase(it);
            else ++it;
        }
        std::cout << "\nПісля erase:\n";
        for (int val : ms) std::cout << val << " ";
        std::cout << "\nsize: " << ms.size() << "\n";

        // Збереження початкової місткості
        int initial_capacity = ms.capacity();
        int before = ms.size();
        ms.shrink_to_fit();
        std::cout << "Після shrink_to_fit:\n";
        for (int val : ms) std::cout << val << " ";
        std::cout << "\nsize: " << ms.size() << "\n";

        // Перевірка, чи змінилась місткість
        if (ms.capacity() < initial_capacity) {
            std::cout << "Місткість зменшена після shrink_to_fit.\n";
        } else {
            std::cout << "Місткість НЕ зменшена після shrink_to_fit.\n";
        }

        int ok = 1;
        int count = 0;
        for (int val : ms) {
            if (val % 3 == 0) ok = 0;
            ++count;
        }
        print_result(ok == 1 && count == before, "shrink_to_fit: елементи ущільнено, все на місці");
    }

    {
        std::cout << "\n== >32 елементи (кілька вузлів) ==" << std::endl;
        MyStruct ms;
        for (int i = 0; i < 50; ++i) ms.push_back(i);
        print_result(ms.size() == 50, "50 елементів");
        print_result(ms.front() == 0, "перший елемент 0");
        print_result(ms.back() == 49, "останній елемент 49");
    }

    {
        std::cout << "\n== поєднання push/pop та ущільнення ==" << std::endl;
        MyStruct ms;

        // Додаємо елементи
        for (int i = 0; i < 20; ++i) ms.push_back(i);
        std::cout << "Після push_back (0..19): ";
        for (auto val : ms) std::cout << val << " ";
        std::cout << std::endl;

        // Видаляємо 5 з початку
        for (int i = 0; i < 5; ++i) ms.pop_front();
        std::cout << "Після 5 pop_front: ";
        for (auto val : ms) std::cout << val << " ";
        std::cout << std::endl;

        // Видаляємо 3 з кінця
        for (int i = 0; i < 3; ++i) ms.pop_back();
        std::cout << "Після 3 pop_back: ";
        for (auto val : ms) std::cout << val << " ";
        std::cout << std::endl;

        int before = ms.size();
        ms.shrink_to_fit();  // для тестування compact_node ефекту

        std::cout << "Після shrink_to_fit: ";
        for (auto val : ms) std::cout << val << " ";
        std::cout << std::endl;

        print_result(ms.size() == before, "розмір не змінився після ущільнення");
        print_result(ms.front() == 5, "після pop_front front == 5");
        print_result(ms.back() == 16, "після pop_back back == 16");
    }


    std::cout << "\nУсі тести завершено ✅" << std::endl;
    return 0;
}
