<?php
namespace App;
class Calculator{
    public static function numberOfDaysByYear($years = 0)   {
        if($years < 0) {
            return 'Invalid entry, please enter a positive integer';
        }
        $numberOfDaysByYear = 365;
        return $years * $numberOfDaysByYear;
    }
}