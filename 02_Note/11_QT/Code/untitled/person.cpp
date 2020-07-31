#include "person.h"

person::person(QObject *parent) : QObject(parent)
{

}

void person::shout(){
    std::cout<<"hahahahah"<<std::endl;
}
