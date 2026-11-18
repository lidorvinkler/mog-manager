#include "Units.h"

Unit::Unit() : approveStatus(std::make_unique<Waiting>()), statusCreator(std::make_unique<StatusCreator>()){}
void Unit::setStatus(const std::string& name){
    this -> approveStatus = creates(name);
}

std::string Unit::getName() const{return UNIT_NAME;}
std::string Unit::getStatus() const{return (this -> approveStatus) -> getName();}
Status& Unit::getStatus() const {return *(this -> approveStatus)}

std::string Aman::getName() const{return UNIT_NAME;}

std::string Avir::getName() const{return UNIT_NAME;}

std::string Yam::getName() const{return UNIT_NAME;}

std::string Padam::getName() const{return UNIT_NAME;}

std::string Patzan::getName() const{return UNIT_NAME;}

std::string Pakmaz::getName() const{return UNIT_NAME;}

std::string Shabak::getName() const{return UNIT_NAME;}

std::string UnitComposite::getStatus() const{
    std::string res = "";
    for(const auto& elem : this -> units){
        res += elem->getName() + " : " + elem->getStatus() + "\n";
    }
    return res;
}

void UnitComposite::addUnit(const std::string& name){
    
}