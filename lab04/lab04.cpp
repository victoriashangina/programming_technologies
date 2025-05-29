#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Restaurant {
 public:
  string name;
  string cuisine;
  double rating;
  double avg_bill;
};

void save_file(const vector<Restaurant>& restaurants, const string& filename) {
  ofstream file(filename);
  for (const Restaurant& r : restaurants) {
    file << r.name << " " << r.cuisine << " " << r.rating << " " << r.avg_bill << "\n";
  }
}

vector<Restaurant> load_file(const string& filename) {
  vector<Restaurant> restaurants;
  ifstream file(filename);
  Restaurant r;
  while (file >> r.name >> r.cuisine >> r.rating >> r.avg_bill) {
    restaurants.push_back(r);
  }
  return restaurants;
}

void Add(vector<Restaurant>& restaurants) {
  Restaurant r;
  cout << "Название: ";
  cin >> r.name;
  cout << "Тип кухни: ";
  cin >> r.cuisine;
  cout << "Рейтинг (0-5): ";
  cin >> r.rating;
  cout << "Средний чек (руб.): ";
  cin >> r.avg_bill;
  restaurants.push_back(r);
  cout << "Ресторан добавлен!\n";
}

void Delete(vector<Restaurant>& restaurants) {
  if (restaurants.empty()) {
    cout << "Список пуст.\n";
    return;
  }
  cout << "Введите номер для удаления (1 - " << restaurants.size() << "): ";
  int idx;
  cin >> idx;
  if (idx >= 1 && idx <= restaurants.size()) {
    restaurants.erase(restaurants.begin() + idx - 1);
    cout << "Удалено.\n";
  } else {
    cout << "Нет такого номера.\n";
  }
}

void Update(vector<Restaurant>& restaurants) {
  if (restaurants.empty()) {
    cout << "Список пуст.\n";
    return;
  }
  cout << "Введите номер для изменения (1 - " << restaurants.size() << "): ";
  int idx;
  cin >> idx;
  if (idx >= 1 && idx <= restaurants.size()) {
    Restaurant& r = restaurants[idx - 1];
    cout << "Новое название: ";
    cin >> r.name;
    cout << "Новый тип кухни: ";
    cin >> r.cuisine;
    cout << "Новый рейтинг (0-5): ";
    cin >> r.rating;
    cout << "Новый средний чек (руб.): ";
    cin >> r.avg_bill;
    cout << "Изменено.\n";
  } else {
    cout << "Нет такого номера.\n";
  }
}

void Print(const vector<Restaurant>& restaurants) {
  if (restaurants.empty()) {
    cout << "Список пуст.\n";
    return;
  }
  cout << "Рестораны:\n";
  for (int i = 0; i < restaurants.size(); ++i) {
    const Restaurant& r = restaurants[i];
    cout << i + 1 << ") " << r.name << " | Кухня: " << r.cuisine
         << " | Рейтинг: " << r.rating << " | Средний чек: " << r.avg_bill << " руб.\n";
  }
}

int main() {
  vector<Restaurant> restaurants;
  const string filename = "restaurants.txt";

  restaurants = load_file(filename);

  while (true) {
    cout << "\nВыберите действие:\n";
    cout << "1. Показать рестораны\n";
    cout << "2. Добавить ресторан\n";
    cout << "3. Удалить ресторан\n";
    cout << "4. Изменить ресторан\n";
    cout << "5. Сохранить и выйти\n";
    cout << "Ваш выбор: ";

    int choice;
    cin >> choice;

    switch (choice) {
      case 1: Print(restaurants); break;
        case 2: Add(restaurants); break;
      case 3: Delete(restaurants); break;
      case 4: Update(restaurants); break;
      case 5:
        save_file(restaurants, filename);
        cout << "Сохранено.\n";
        return 0;
      default:
        cout << "Неверный ввод.\n";
    }
  }
}

