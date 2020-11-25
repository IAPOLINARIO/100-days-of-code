<?php
    include('calculator.class.php');
    if (isset($argc)) {
       $years = $argv[1] ?? 0;
       $numberOfDays = Calculator::numberOfDaysByYear($years);
       echo "Number of days: ".$numberOfDays.".\n";
    }
?>