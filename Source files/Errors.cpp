#include "stdafx.h"
#include "Errors.hpp"


void getError(Errors code)
{
	switch (code) {
	case ZERO_ARR:
		cout << "Вы ввели массив, состоящий из одних нулей! "
			<< endl;
		break;

	case UNKNOWN_SYMBOL:
		cout << "Вы ввели массив, содержащий неизвестный элемент! "
			<< endl;
		break;

	case HOLE:
		cout << "Вы ввели элемент, содержащий отверстие! "
			<< endl;
		break;

	case NO_FILE:
		cout << "Файл не найден! "
			<< endl;
		break;

	case NOT_SINGLE:
		cout << "Элемент не единственный! "
			<< endl;
		break;

	case WRONG_SIDE_SIZE:
		cout << "Неверный размер массива! "
			<< endl;
		break;

	case NEED_HELP:
		cout << "Использование: ./a.out <Путь до входного файла> <Путь до выходного файла>"
			<< endl;
		break;

	case INVALID_AREA:
		cout << "Входные фигуры нельзя уместить в прямоугольник! "
			<< endl;
		break;

	case NO_ANSWER:
		cout << "Решение не найдено! "
			<< endl;
		break;

	case WIN:
		cout << "Решение найдено! "
			<< endl;
		break;

	default:
		break;
	}
}