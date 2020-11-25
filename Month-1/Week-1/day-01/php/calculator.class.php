<?php
    class Calculator{
        static function numberOfDaysByYear($years = 0)   {
            $numberOfDaysByYear = 365;
            return $years * $numberOfDaysByYear;
        } 
    }
?>