#include "BusTrackVector.hpp"

/*================================================================================*/
/*================================= Конструкторы =================================*/
/*================================================================================*/

BusTrackVector::BusTrackVector(std::vector<BusTrack>& inVector) : Vector(inVector){}
BusTrackVector::BusTrackVector(const BusTrackVector& obj)
{
    Vector = obj.Vector;
}


void BusTrackVector::SortByNumberBus()
{
    size_t Size = size(Vector)/sizeof(Vector[0]);
    for (size_t i = 0; i < Size; ++i)
    {
        for (size_t j = 0; j < Size; ++j)
        {
            if (Vector[i].getNumberBus() <= Vector[j].getNumberBus())
            {
                std::swap(Vector[i], Vector[j]);
            }
        }
    }
}

void BusTrackVector::SortByNumberTrack()
{
    size_t Size = size(Vector)/sizeof(Vector[0]);
    for (size_t i = 0; i < Size; ++i)
    {
        for (size_t j = 0; j < Size; ++j)
        {
            if (Vector[i].getNumberTrack() <= Vector[j].getNumberTrack())
            {
                std::swap(Vector[i], Vector[j]);
            }
        }
    }
}


std::map<uint16_t, BusTrack>& BusTrackVector::createMap(std::map<uint16_t, BusTrack>& inMap)
{
    for (auto obj : Vector)
    {
        inMap[obj.getNumberBus()] = obj;
    }
    return inMap;
}

/*================================================================================*/
/*==================================== Геттер ====================================*/
/*================================================================================*/

std::vector<BusTrack> BusTrackVector::getVector() const
{
    return Vector;
}

/*================================================================================*/
/*===================== Перегрузка операторов ввода и вывода =====================*/
/*================================================================================*/

std::ostream& operator<<(std::ostream& out, const BusTrackVector& obj)
{
    for (const auto busTrack : obj.getVector())
    {
        out << busTrack;
    }
    return out;
}

std::istream& operator>>(std::istream& in, BusTrackVector& obj)
{
    BusTrack temp;
    while (in >> temp)
    {
        obj.Vector.push_back(temp);
    }
    return in;
}