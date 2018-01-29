//
// Created by pavel on 28.01.18.
//

#include "Shape.h"

Shape::Shape(int i, int j) :i(i), j(j) {}

int Shape::getI(){
    return this->i;
}

int Shape::getJ(){
    return this->j;
}

void Shape::setI(int i){
    this->i = i;
}

void Shape::setJ(int j) {
    this->j = j;
}

void Shape::setPosition(int i, int j){
    this->i = i;
    this->j = j;
}

char Shape::getIcon() {
    return this->icon;
}

void Shape::setIcon(char icon) {
    this->icon = icon;
}

Shape::~Shape() = default;

