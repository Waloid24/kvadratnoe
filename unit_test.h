//--------------------------------------------------------------------------
//! @file unit_test.h
//--------------------------------------------------------------------------

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

enum output
	{
		FAILED = 1,
		SUCCESS = 0
	};
	
const int NUMBER_OF_TESTS = 2;

//---------------------------------------------------------------------------------------
//!
//! @breif Функция иницализирует прогон по тестам
//!
//! @see duplicate_coefficients () isFailed ()
//!
//! @return Печатает число неудачных тестов из их общего числа
//!
//---------------------------------------------------------------------------------------
void UnitTest ();

//---------------------------------------------------------------------------------------
//!
//! @breif Функция дублирует значения из одного массива в другой массив
//! 
//! @param Принимает два указателя на структуру: в 1-ую структуру копируются значения из
//! второй структуры
//! 
//! @see assert()
//!
//! @return Ничего не возвращает
//!
//!--------------------------------------------------------------------------------------
void duplicate_coefficients (struct coef_and_sol * , struct coef_and_sol * );

//---------------------------------------------------------------------------------------
//!
//! @breif Функция проверяет тест на успешность
//!
//! @note Выводит в случае ошибки комментарий к ней
//! 
//! @see assert()
//!
//! @return 0-если тест прошёл неуспешно, 1 - если успешно
//!
//!--------------------------------------------------------------------------------------
int isFailed (struct coef_and_sol *, struct coef_and_sol *, int );

#endif
