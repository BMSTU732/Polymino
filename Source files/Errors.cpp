#include "stdafx.h"
#include "Errors.hpp"


void getError(Errors code)
{
	switch (code) {
	case ZERO_ARR:
		cout << "�� ����� ������, ��������� �� ����� �����! "
			<< endl;
		break;

	case UNKNOWN_SYMBOL:
		cout << "�� ����� ������, ���������� ����������� �������! "
			<< endl;
		break;

	case HOLE:
		cout << "�� ����� �������, ���������� ���������! "
			<< endl;
		break;

	case NO_FILE:
		cout << "���� �� ������! "
			<< endl;
		break;

	case NOT_SINGLE:
		cout << "������� �� ������������! "
			<< endl;
		break;

	case WRONG_SIDE_SIZE:
		cout << "�������� ������ �������! "
			<< endl;
		break;

	case NEED_HELP:
		cout << "�������������: ./a.out <���� �� �������� �����> <���� �� ��������� �����>"
			<< endl;
		break;

	case INVALID_AREA:
		cout << "������� ������ ������ �������� � �������������! "
			<< endl;
		break;

	case NO_ANSWER:
		cout << "������� �� �������! "
			<< endl;
		break;

	case WIN:
		cout << "������� �������! "
			<< endl;
		break;

	default:
		break;
	}
}