<?php
namespace Tests;

use App\Calculator;
use PHPUnit\Framework\TestCase;

class CalculatorTest extends TestCase
{
    public function test_calculate_days_given_one_year()
    {
        $year = 1;
        self::assertEquals(365, Calculator::numberOfDaysByYear($year));
    }

    public function test_calculate_days_given_hundred_years()
    {
        $year = 100;
        self::assertEquals(36500, Calculator::numberOfDaysByYear($year));
    }

    public function test_calculate_days_given_negative_integer()
    {
        $year = -1;
        self::assertEquals('Invalid entry, please enter a positive integer', Calculator::numberOfDaysByYear($year));
    }
}