<?php
require_once('App/Calculator.php');
if (isset($argc)) {
       $years = $argv[1] ?? 0;
       $numberOfDays = App\Calculator::numberOfDaysByYear($years);
       echo "Number of days: ".$numberOfDays.".\n";
}