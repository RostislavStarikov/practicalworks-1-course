#ifndef BUSTRACKVECTOR_HPP
#define BUSTRACKVECTOR_HPP

#include <vector>   // Для работы с вектором
#include <map>      // Для создания map

#include "../BusTrack/BusTrack.hpp"

class BusTrackVector
{
private:
std::vector<BusTrack> Vector;

public:
BusTrackVector() = default;             // Конструктор по умолчанию
BusTrackVector(std::vector<BusTrack>&); // Конструктор с параметром
BusTrackVector(const BusTrackVector&);  // Конструктор копирования

void SortByNumberBus();  // Сортировка по номеру автобуса
void SortByNumberTrack();// Сортировка по номеру маршрута

std::map<uint16_t, BusTrack>& createMap(std::map<uint16_t, BusTrack>&);   // Создание контейнера map

std::vector<BusTrack> getVector() const;     // Геттер вектора

friend std::ostream& operator<<(std::ostream&, const BusTrackVector&);  // Перегрузка оператора вывода
friend std::istream& operator>>(std::istream&, BusTrackVector&);        // Перегрузка оператора ввода

};

#endif
